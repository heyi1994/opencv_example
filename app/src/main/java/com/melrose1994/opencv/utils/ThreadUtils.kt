@file:JvmName("ThreadUtils")
package com.melrose1994.opencv.utils

import android.os.Handler
import android.os.Looper
import splitties.mainthread.isMainThread
import java.util.concurrent.Executors


private val IO_EXECUTOR = Executors.newSingleThreadExecutor()
private val mMainHandler = Handler(Looper.getMainLooper())

/**
 * Utility method to run blocks on a dedicated background thread, used for io/database work.
 */
fun runOnIoThread(body : () -> Unit) {
    IO_EXECUTOR.execute(body)
}


/**
 * run on ui thread .
 */
fun runOnUiThread( block:()->Unit){
    if (isMainThread){
        block.invoke()
    }else{
        mMainHandler.post(block)
    }
}

/**
 * run on UI Thread delayed ;
 */
fun runOnUiThreadDelayed(delayMillis:Long,block:()->Unit){
    mMainHandler.postDelayed(block,delayMillis)
}