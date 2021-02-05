package com.melrose1994.opencv

import android.app.Activity
import android.content.Context
import android.os.Bundle
import splitties.views.dsl.core.Ui
import splitties.views.dsl.core.setContentView
import java.lang.reflect.ParameterizedType

abstract class BaseActivity<UI:Ui>: Activity(){


    private lateinit var  mUi:UI


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        transparentStatusBarNoFitWindow()
        val genType = this.javaClass.genericSuperclass
        val params = (genType as? ParameterizedType)?.actualTypeArguments
        val constructor = (params?.get(0) as? Class<*>)?.getConstructor(Context::class.java)
        mUi = constructor?.newInstance(this) as UI
        setContentView(mUi)
        init()
    }



    protected abstract fun init()


    protected fun getUi() = mUi

}