package com.melrose1994.opencv_example

import android.graphics.Bitmap

/**
 * @author Melrose
 * @since 1.0.0
 */
object OpenCvBitmap {
    init {
        System.loadLibrary("opencv")
    }


    /**
     * 灰度处理 ;
     */
    @JvmStatic
    external fun gray(src:Bitmap,newBitmap:Bitmap):Boolean




    @JvmStatic
    external fun debug(src:Bitmap,newBitmap:Bitmap):Boolean

}