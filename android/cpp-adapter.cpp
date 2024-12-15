#include <jni.h>
#include "react-native-turbofs.h"
#include <android/log.h>

#define LOG_TAG "TurboFS"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_turbofs_TurbofsModule_nativeReadFile(JNIEnv *env, jclass type, jstring filePath) {
    const char *path = env->GetStringUTFChars(filePath, nullptr);

    try {
        std::string content = turbofs::readFile(path);
        env->ReleaseStringUTFChars(filePath, path);
        return env->NewStringUTF(content.c_str());
    } catch (const std::exception &e) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Error reading file: %s", e.what());
        env->ReleaseStringUTFChars(filePath, path);
        jclass exceptionClass = env->FindClass("java/lang/Exception");
        env->ThrowNew(exceptionClass, e.what());
        return nullptr;
    }
}
