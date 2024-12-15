#include <jni.h>
#include "react-native-turbofs.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_turbofs_TurbofsModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return turbofs::multiply(a, b);
}
