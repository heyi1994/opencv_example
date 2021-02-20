package com.melrose1994.opencv.ui.swell

import android.graphics.Bitmap
import com.melrose1994.opencv.BaseActivity
import com.melrose1994.opencv.R
import com.melrose1994.opencv.createArgbBitmap
import com.melrose1994.opencv.utils.runOnIoThread

class SwellActivity:BaseActivity<SwellUi>() {

    companion object{
        init {
            System.loadLibrary("opencv")
        }
    }


    override fun init() {
        val source = createArgbBitmap(R.drawable.ic_pic)
        getUi().image.setImageBitmap(source)

        runOnIoThread {
            val dilate = dilate(source)
            val erode = erode(source)
            runOnUiThread {
                getUi().dest1.setImageBitmap(dilate)
                getUi().dest2.setImageBitmap(erode)
            }
        }
    }


    /**
     * 图片膨胀 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external fun dilate(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap



    /**
     * 图片腐蚀 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external fun erode(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap





}