package com.melrose1994.opencv_example

import android.annotation.SuppressLint
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.os.Bundle
import android.util.Log
import android.widget.ImageView
import androidx.appcompat.app.AppCompatActivity


class MainActivity : AppCompatActivity() {
    private  val TAG = "MainActivity"
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)




        show()
    }




    @SuppressLint("UseCompatLoadingForDrawables")
    private fun show(){
        val bitmap = BitmapFactory.decodeResource(
            resources,
            R.drawable.ic_pic,
            BitmapFactory.Options().apply {
                inPreferredConfig = Bitmap.Config.ARGB_8888
            })
        findViewById<ImageView>(R.id.ivSrc).setImageBitmap(bitmap)
        val new = Bitmap.createBitmap(bitmap.width, bitmap.height, Bitmap.Config.ARGB_8888)
        val before = System.currentTimeMillis()
        if (OpenCvBitmap.debug(bitmap, new)){
            val after = System.currentTimeMillis()
            Log.d(TAG, "take time : ${after - before} ms")
            findViewById<ImageView>(R.id.ivDest).setImageBitmap(new)
        }
    }


}