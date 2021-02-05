@file:JvmName("Utils")
package com.melrose1994.opencv

import android.app.Activity
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.graphics.Color
import android.view.View
import android.view.WindowManager
import androidx.annotation.DrawableRes


fun createArgbBitmap(width:Int,height:Int) = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888)


fun Activity.createArgbBitmap(@DrawableRes id:Int) = BitmapFactory.decodeResource(
    resources,
    id,
    BitmapFactory.Options().apply {
        inPreferredConfig = Bitmap.Config.ARGB_8888
    })



fun Bitmap.clone()= Bitmap.createBitmap(width, height, config)




fun Activity.transparentStatusBarNoFitWindow(){
    window.clearFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS)
    window.getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
            or View.SYSTEM_UI_FLAG_LAYOUT_STABLE)
    window.addFlags(WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS)
    window.setStatusBarColor(Color.TRANSPARENT)
    window.getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_LIGHT_STATUS_BAR)
}
