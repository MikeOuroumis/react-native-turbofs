package com.turbofs

import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.module.annotations.ReactModule

@ReactModule(name = TurbofsModule.NAME)
class TurbofsModule(reactContext: ReactApplicationContext) :
    NativeTurbofsSpec(reactContext) {

    override fun getName(): String {
        return NAME
    }

    override fun readFile(filePath: String, promise: Promise) {
        try {
            val content = nativeReadFile(filePath)
            promise.resolve(content)
        } catch (e: Exception) {
            promise.reject("READ_FILE_ERROR", "Failed to read file at $filePath", e)
        }
    }

    private external fun nativeReadFile(filePath: String): String

    companion object {
        const val NAME = "Turbofs"

        init {
            try {
                System.loadLibrary("react-native-turbofs")
            } catch (e: UnsatisfiedLinkError) {
                e.printStackTrace() // Log if the library fails to load
            }
        }
    }
}
