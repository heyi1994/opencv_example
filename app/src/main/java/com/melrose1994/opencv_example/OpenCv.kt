package com.melrose1994.opencv_example

/**
 * @author Melrose
 * @since 1.0.0
 */
object OpenCv {
    init {
        System.loadLibrary("opencv")
    }


    /**
     * 灰度处理 ;
     */
    @JvmStatic
    external fun gray(buf:IntArray,width:Int,height:Int):IntArray



}