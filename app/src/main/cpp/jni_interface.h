//
// @birth: created by Melrose on 2021/1/5
// @version: 1.0.0
//
#ifndef OPENCV_EXAMPLE_JNI_INTERFACE_H
#define OPENCV_EXAMPLE_JNI_INTERFACE_H
#include <jni.h>
#include <android/bitmap.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/types_c.h>
using namespace cv;

#include "android/log.h"
#include "cv_pixel.h"
#define LOG_TAG "Melrose"
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


extern "C"
JNIEXPORT jboolean JNICALL
Java_com_melrose1994_opencv_1example_OpenCvBitmap_gray(JNIEnv *env, jclass clazz, jobject src, jobject bitmap);

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_melrose1994_opencv_1example_OpenCvBitmap_debug(JNIEnv *env, jclass clazz, jobject src, jobject bitmap);


bool lock_bitmap_pixels(JNIEnv *env,jobject &src ,jobject &dest,Mat *source,Mat *dst);
void unlock_bitmap_pixels(JNIEnv *env,jobject &src ,jobject &dest);

void test();
#endif //OPENCV_EXAMPLE_JNI_INTERFACE_H
