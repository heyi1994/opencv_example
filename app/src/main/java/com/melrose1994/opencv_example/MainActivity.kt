package com.melrose1994.opencv_example

import android.annotation.SuppressLint
import android.graphics.Bitmap
import android.graphics.drawable.BitmapDrawable
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ImageView
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)


        show()
    }


    @SuppressLint("UseCompatLoadingForDrawables")
    private fun show(){
        val bitmap = (resources.getDrawable(R.drawable.ic_pic) as BitmapDrawable).bitmap
        val w = bitmap.width
        val h = bitmap.height
        val pix =IntArray(w*h)
        bitmap.getPixels(pix, 0, w, 0, 0, w, h)
        findViewById<ImageView>(R.id.ivSrc).setImageBitmap(bitmap)
        val resultPixes = OpenCv.gray(pix,w,h)
        val result = Bitmap.createBitmap(w,h,Bitmap.Config.RGB_565)
        result.setPixels(resultPixes, 0, w, 0, 0,w, h)
        findViewById<ImageView>(R.id.ivDest).setImageBitmap(result)


    }

}