package com.turbofs

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
        val content = turbofs.readFile(filePath) // Call the C++ implementation
        promise.resolve(content)
    } catch (e: Exception) {
        promise.reject("READ_FILE_ERROR", e.message)
    }
}

  companion object {
    const val NAME = "Turbofs"
  }
}
