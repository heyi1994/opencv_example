//
// @birth: created by Melrose on 2021/1/5
// @version: 1.0.0
//
#ifndef OPENCV_EXAMPLE_JNI_INTERFACE_H
#define OPENCV_EXAMPLE_JNI_INTERFACE_H

#define LOG_TAG "Melrose"
#include "lib_headers.h"

//亮度和对比度
#include "effects/contrast/cv_contrast.h"
//图像融合
#include "effects/composite/cv_composite.h"
//像素操作
#include "cv_pixel.h"

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_melrose1994_opencv_1example_OpenCvBitmap_gray(JNIEnv *env, jclass clazz, jobject src, jobject bitmap);

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_melrose1994_opencv_1example_OpenCvBitmap_debug(JNIEnv *env, jclass clazz, jobject src, jobject bitmap);


extern "C"
JNIEXPORT jboolean JNICALL
Java_com_melrose1994_opencv_1example_OpenCvBitmap_composite(JNIEnv *env, jclass clazz,
                                                            jobject bitmap, jobject bitmap2,
                                                            jobject dest);


#endif //OPENCV_EXAMPLE_JNI_INTERFACE_H
