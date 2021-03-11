package com.melrose1994.opencv.ui.VerticaLines

import android.graphics.Bitmap
import com.melrose1994.opencv.BaseActivity
import com.melrose1994.opencv.R
import com.melrose1994.opencv.clone
import com.melrose1994.opencv.createArgbBitmap
import com.melrose1994.opencv.utils.runOnIoThread

class VerticalLinesActivity:BaseActivity<VerticalLinesUi>() {

    companion object{
        init {
            System.loadLibrary("opencv")
        }
    }


    override fun init() {
        val source = createArgbBitmap(R.drawable.ic_lines)
        getUi().image.setImageBitmap(source)

        runOnIoThread {
             val open = binaryGraph(source)
             val vertical = ocVertical(source)
             val horizontal = ocHorizontal(source)
            runOnUiThread {
                  getUi().dest1.setImageBitmap(open)
                  getUi().dest2.setImageBitmap(vertical)
                  getUi().dest3.setImageBitmap(horizontal)
//                  getUi().dest4.setImageBitmap(blackHat)
            }
        }
    }


    /**
     * 获取二值图 ;
     * @param source 原图 ;
     * @param config 返回图片的config ;
     */
    private external  fun binaryGraph(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap

    /**
     * 提取垂直线 ;
     */
    private external  fun ocVertical(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap


    private external  fun ocHorizontal(source:Bitmap,config:Bitmap.Config = Bitmap.Config.ARGB_8888):Bitmap



}