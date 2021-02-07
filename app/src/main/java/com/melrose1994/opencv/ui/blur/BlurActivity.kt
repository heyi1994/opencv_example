package com.melrose1994.opencv.ui.blur

import android.graphics.Bitmap
import com.melrose1994.opencv.BaseActivity
import com.melrose1994.opencv.R
import com.melrose1994.opencv.clone
import com.melrose1994.opencv.createArgbBitmap
import com.melrose1994.opencv.utils.runOnIoThread

class BlurActivity:BaseActivity<BlurUi>() {

    companion object{
        init {
            System.loadLibrary("opencv")
        }
    }


    override fun init() {
        runOnIoThread {
            val source = createArgbBitmap(R.drawable.ic_pic)
            val blur = blur(source)
            val gaussianBlur =gaussianBlur(source)
            val medianBlur =medianBlur(source)
            val bilateralFilter =bilateralFilter(source)

            runOnUiThread {
                getUi().image.setImageBitmap(source)
                getUi().dest1.setImageBitmap(blur)
                getUi().dest2.setImageBitmap(gaussianBlur)
                getUi().dest3.setImageBitmap(medianBlur)
                getUi().dest4.setImageBitmap(bilateralFilter)
            }
        }



    }


    /**
     * 均值模糊 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external fun blur(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap

    /**
     * 高斯模糊 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external fun gaussianBlur(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap

    /**
     * 中值模糊 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external fun medianBlur(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap


    /**
     * 双边模糊 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external fun bilateralFilter(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap



}