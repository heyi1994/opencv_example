//
// Created by melrose on 21-2-6.
//

#ifndef OPENCV_EXAMPLE_CV_BLUR_H
#define OPENCV_EXAMPLE_CV_BLUR_H

//对比度和亮度的调整
#include "../../lib_headers.h"


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_blur_BlurActivity_blur(JNIEnv *env, jobject thiz, jobject source, jobject config);

extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_blur_BlurActivity_gaussianBlur(JNIEnv *env, jobject thiz, jobject source, jobject config);




extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_blur_BlurActivity_medianBlur(JNIEnv *env, jobject thiz, jobject source, jobject config);

extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_blur_BlurActivity_bilateralFilter(JNIEnv *env, jobject thiz, jobject source, jobject config);



#endif //OPENCV_EXAMPLE_CV_BLUR_H
