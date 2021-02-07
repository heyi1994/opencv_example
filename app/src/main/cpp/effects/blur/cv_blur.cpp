//
// Created by melrose on 21-2-6.
//

#include "cv_blur.h"


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_blur_BlurActivity_blur(JNIEnv *env, jobject thiz, jobject source, jobject config)
{
    Mat img;
    bitmap2Mat(env,source,&img);
    blur(img,img,Size(81,81));
    putAuthorToMat(img);
    return createBitmap(env,img,config);
}


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_blur_BlurActivity_gaussianBlur(JNIEnv *env, jobject thiz, jobject source, jobject config)
{

    Mat img;
    bitmap2Mat(env,source,&img);
    GaussianBlur(img,img,Size(81,81),81,81);
    putAuthorToMat(img);
    return createBitmap(env,img,config);
}


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_blur_BlurActivity_medianBlur(JNIEnv *env, jobject thiz, jobject source, jobject config)
{
    Mat img;
    bitmap2Mat(env,source,&img);
    medianBlur(img,img,81);
    putAuthorToMat(img);
    return createBitmap(env,img,config);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_blur_BlurActivity_bilateralFilter(JNIEnv *env, jobject thiz, jobject source, jobject config)
{
    Mat img,bgr,result;
    bitmap2Mat(env,source,&img);
    cvtColor(img,bgr,CV_BGRA2BGR);
    bilateralFilter(bgr,result,15,100,5);
    putAuthorToMat(result);
    return createBitmap(env,result,config);
}

