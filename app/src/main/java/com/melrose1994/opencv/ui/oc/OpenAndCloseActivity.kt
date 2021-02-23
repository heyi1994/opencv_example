package com.melrose1994.opencv.ui.oc

import android.graphics.Bitmap
import com.melrose1994.opencv.BaseActivity
import com.melrose1994.opencv.R
import com.melrose1994.opencv.clone
import com.melrose1994.opencv.createArgbBitmap
import com.melrose1994.opencv.utils.runOnIoThread

class OpenAndCloseActivity:BaseActivity<OpenAndCloseUi>() {

    companion object{
        init {
            System.loadLibrary("opencv")
        }
    }


    override fun init() {
        val source = createArgbBitmap(R.drawable.ic_binary_image)
        getUi().image.setImageBitmap(source)

        runOnIoThread {
             val open = morphOpen(source)
             val  close = morphClose(source)
             val  topHat = morphTopHat(source)
             val  blackHat = morphBlackHat(source)
            runOnUiThread {
                  getUi().dest1.setImageBitmap(open)
                  getUi().dest2.setImageBitmap(close)
                  getUi().dest3.setImageBitmap(topHat)
                  getUi().dest4.setImageBitmap(blackHat)
            }
        }
    }


    /**
     * 形态学操作 - 开操作 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external  fun morphOpen(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap

    /**
     * 形态学操作 - 闭操作 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external  fun morphClose(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap




    /**
     * 形态学操作 - 顶帽 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external  fun morphTopHat(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap




    /**
     * 形态学操作 - 黑帽 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external  fun morphBlackHat(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap


}