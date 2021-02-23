package com.melrose1994.opencv.ui.oc

import android.content.Context
import android.view.View
import splitties.dimensions.dip
import splitties.views.dsl.core.*
import splitties.views.textResource
import com.melrose1994.opencv.R
import splitties.views.dsl.recyclerview.wrapInRecyclerView
import splitties.views.gravityCenter
import splitties.views.gravityStart

class OpenAndCloseUi(override val ctx: Context):Ui {

    val image = imageView()
    val dest1 = imageView()
    val dest2 = imageView()
    val dest3 = imageView()
    val dest4 = imageView()





    val parent = verticalLayout {
        setPadding(dip(20),dip(30),dip(20),dip(30))


        add(textView {
            textResource = R.string.activity_oc
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

            textResource = R.string.activity_oc_open
            textSize = 14f
        },lParams {
            gravity = gravityStart
        })


        add(dest1,lParams(matchParent,dip(200)){
        })

        add(textView {
            textResource = R.string.activity_oc_close
            textSize = 14f
        },lParams {
            gravity = gravityStart
        })

        add(dest2,lParams(matchParent,dip(200)){

        })



        add(textView {
            textResource = R.string.activity_oc_top_hat
            textSize = 14f
        },lParams {
            gravity = gravityStart
        })

        add(dest3,lParams(matchParent,dip(200)){

        })


        add(textView {
            textResource = R.string.activity_oc_black_hat
            textSize = 14f
        },lParams {
            gravity = gravityStart
        })

        add(dest4,lParams(matchParent,dip(200)){

        })

    }.wrapInRecyclerView {  }


    override val root: View
        get() = parent
}