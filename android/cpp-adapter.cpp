#include <jni.h>
#include "react-native-turbofs.h"
#include <android/log.h>
#include <vector>
#include <string>

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

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_turbofs_TurbofsModule_nativeReadDir(JNIEnv *env, jclass type, jstring dirPath) {
    const char *path = env->GetStringUTFChars(dirPath, nullptr);

    try {
        std::vector<std::string> files = turbofs::readDir(path);
        env->ReleaseStringUTFChars(dirPath, path);

        // Create a new Java String array
        jclass stringClass = env->FindClass("java/lang/String");
        jobjectArray result = env->NewObjectArray(files.size(), stringClass, nullptr);

        // Fill the array with file paths
        for (size_t i = 0; i < files.size(); ++i) {
            env->SetObjectArrayElement(result, i, env->NewStringUTF(files[i].c_str()));
        }

        return result;
    } catch (const std::exception &e) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Error reading directory: %s", e.what());
        env->ReleaseStringUTFChars(dirPath, path);
        jclass exceptionClass = env->FindClass("java/lang/Exception");
        env->ThrowNew(exceptionClass, e.what());
        return nullptr;
    }
}
