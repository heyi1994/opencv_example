//
// @birth: created by Melrose on 2021/1/5
// @version: 1.0.0
//
#ifndef OPENCV_EXAMPLE_JNI_INTERFACE_H
#define OPENCV_EXAMPLE_JNI_INTERFACE_H
#include <jni.h>
#include "opencv2/opencv.hpp"
#include <opencv2/gapi/own/mat.hpp>
#include <opencv2/imgproc/types_c.h>
#include "android/log.h"
#define LOG_TAG "Melrose"
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
using namespace cv;


extern "C"
JNIEXPORT jintArray JNICALL
Java_com_melrose1994_opencv_1example_OpenCv_gray(JNIEnv *env, jclass clazz, jintArray buf,
                                                 jint width, jint height);
#endif //OPENCV_EXAMPLE_JNI_INTERFACE_H
