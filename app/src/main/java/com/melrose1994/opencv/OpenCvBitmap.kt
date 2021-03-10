package com.melrose1994.opencv

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
     * @param src 需要进行灰度处理的bitmap ;
     * @param newBitmap 显示的bitmap ;
     */
    @JvmStatic external fun gray(src:Bitmap,newBitmap:Bitmap):Boolean


    /**
     * 将两张图片进行混合 ;
     * @param bitmap 图片1 ;
     * @param bitmap2 图片2 ;
     * @param dest 显示的bitmap ;
     */
    @JvmStatic external fun composite(bitmap: Bitmap,bitmap2: Bitmap,dest:Bitmap):Boolean




    @JvmStatic external fun debug(src:Bitmap,newBitmap:Bitmap):Boolean






}