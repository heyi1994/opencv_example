package com.melrose1994.opencv.ui.contrast

import android.content.Context
import android.view.View
import androidx.core.view.marginTop
import splitties.dimensions.dip
import splitties.views.dsl.core.*
import splitties.views.textResource
import com.melrose1994.opencv.R
import splitties.views.gravityCenter

class ContrastUi(override val ctx: Context):Ui {



    val image = imageView()
    val dest = imageView()



    val parent = verticalLayout {
        setPadding(dip(20),dip(30),dip(20),dip(30))

        add(textView {
            textResource = R.string.activity_contrast_contrast
            textSize = 20f
        },lParams {
            gravity = gravityCenter
        })
        add(image,lParams(matchParent,0){
            weight =1f
        })

        add(dest,lParams(matchParent,0){
            topMargin = dip(20)
            weight =1f
        })

    }


    override val root: View
        get() = parent
}