@file:JvmName("Utils")
package com.melrose1994.opencv_example

import android.app.Activity
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import androidx.annotation.DrawableRes


fun createArgbBitmap(width:Int,height:Int) = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888)


fun Activity.createArgbBitmap(@DrawableRes id:Int) = BitmapFactory.decodeResource(
    resources,
    id,
    BitmapFactory.Options().apply {
        inPreferredConfig = Bitmap.Config.ARGB_8888
    })



fun Bitmap.clone()= Bitmap.createBitmap(width, height, config)