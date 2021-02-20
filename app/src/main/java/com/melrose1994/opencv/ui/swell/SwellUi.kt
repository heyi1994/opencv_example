package com.melrose1994.opencv.ui.swell

import android.content.Context
import android.view.View
import splitties.dimensions.dip
import splitties.views.dsl.core.*
import splitties.views.textResource
import com.melrose1994.opencv.R
import splitties.views.dsl.recyclerview.wrapInRecyclerView
import splitties.views.gravityCenter
import splitties.views.gravityStart

class SwellUi(override val ctx: Context):Ui {



    val image = imageView()
    val dest1 = imageView()
    val dest2 = imageView()





    val parent = verticalLayout {
        setPadding(dip(20),dip(30),dip(20),dip(30))


        add(textView {
            textResource = R.string.activity_swell
            textSize = 20f
        },lParams {
            bottomMargin= dip(20)

            gravity = gravityCenter
        })


        add(textView {

            textResource = R.string.activity_blur
            textSize = 14f
        },lParams {
            gravity = gravityStart
        })

        add(image,lParams(matchParent,dip(200)){
        })


        add(textView {

            textResource = R.string.activity_swell_dilate
            textSize = 14f
        },lParams {
            gravity = gravityStart
        })


        add(dest1,lParams(matchParent,dip(200)){
        })

        add(textView {
            textResource = R.string.activity_swell_erode
            textSize = 14f
        },lParams {
            gravity = gravityStart
        })

        add(dest2,lParams(matchParent,dip(200)){

        })



    }.wrapInRecyclerView {  }


    override val root: View
        get() = parent
}