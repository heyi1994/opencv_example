package com.melrose1994.opencv

import android.annotation.SuppressLint
import android.graphics.Bitmap
import android.os.Bundle
import android.util.Log
import android.widget.ImageView
import androidx.appcompat.app.AppCompatActivity
import com.melrose1994.opencv.ui.blur.BlurActivity
import com.melrose1994.opencv.ui.swell.SwellActivity
import splitties.activities.start
import splitties.dimensions.dip


class MainActivity : AppCompatActivity() {
    private  val TAG = "MainActivity"
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)



        //composite()

        //start<ContrastActivity>()
        //start<BlurActivity>()
        start<SwellActivity>()
    }




    @SuppressLint("UseCompatLoadingForDrawables")
    private fun show(){

        val bitmap = createArgbBitmap(R.drawable.ic_pic)
        showBitmap(bitmap)
        val new = bitmap.clone()
        val before = System.currentTimeMillis()
        if (OpenCvBitmap.debug(bitmap, new)){
            val after = System.currentTimeMillis()
            Log.d(TAG, "take time : ${after - before} ms")
            showBitmap(new)
        }
    }





    private fun composite(){
        val bitmap =  createArgbBitmap(R.drawable.ic_pic_1)
        val bitmap2 =  createArgbBitmap(R.drawable.ic_pic_2)
        val dest = bitmap.clone()
        if (OpenCvBitmap.composite(bitmap, bitmap2, dest)){
            showBitmap(dest)
        }
    }







    private fun showBitmap(bitmap: Bitmap) = findViewById<ImageView>(R.id.ivDest).setImageBitmap(bitmap)



}