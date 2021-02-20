//
// Created by melrose on 21-2-20.
//
#include "cv_swell.h"





extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_swell_SwellActivity_dilate(JNIEnv *env, jobject thiz, jobject source,
                                                          jobject config)
{

    Mat img;
    bitmap2Mat(env,source,&img);
    auto structuringElement = getStructuringElement(MORPH_RECT,Size(25,25));
    dilate(img,img,structuringElement);
    putAuthorToMat(img);
    return createBitmap(env,img,config);
}



extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_swell_SwellActivity_erode(JNIEnv *env, jobject thiz, jobject source,
                                                         jobject config)
{
    Mat img;
    bitmap2Mat(env,source,&img);
    //如果需要加深，调大ksize即可
    auto structuringElement = getStructuringElement(MORPH_RECT,Size(25,25));
    erode(img,img,structuringElement);
    putAuthorToMat(img);
    return createBitmap(env,img,config);
}