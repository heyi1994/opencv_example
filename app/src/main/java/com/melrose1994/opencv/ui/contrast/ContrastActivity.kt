package com.melrose1994.opencv.ui.contrast

import android.graphics.Bitmap
import android.widget.SeekBar
import com.melrose1994.opencv.BaseActivity
import com.melrose1994.opencv.R
import com.melrose1994.opencv.clone
import com.melrose1994.opencv.createArgbBitmap

class ContrastActivity:BaseActivity<ContrastUi>() {

    companion object{
        init {
            System.loadLibrary("opencv")
        }
    }

    private  val TAG = "ContrastActivity"




    override fun init() {

       val source = createArgbBitmap(R.drawable.ic_pic_2)
       val dest = source.clone()

        getUi().image.setImageBitmap(source)

        contrast(source,dest,1.2f,80f)

        getUi().dest.setImageBitmap(dest)

    }

    /**
     * 调整图片亮度和对比度;
     * @param source  需要调整的图片;
     * @param contrast 对比度;
     * @param intensity 亮度 ;
     */
    external fun contrast(source:Bitmap,dest:Bitmap,contrast:Float,intensity:Float)



}