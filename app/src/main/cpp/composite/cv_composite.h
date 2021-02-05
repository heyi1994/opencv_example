//
// Created by melrose on 21-2-2.
//

#ifndef OPENCV_EXAMPLE_CV_COMPOSITE_H
#define OPENCV_EXAMPLE_CV_COMPOSITE_H

//图像混合
#include <jni.h>
#include <android/bitmap.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/types_c.h>
using namespace cv;

#include "android/log.h"
#define LOG_TAG "Melrose_composite"
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


/**
 * 将两张图片混合 ;
 * @param img 图片1 ;
 * @param img2 图片2 ;
 * @param dest 目标 ;
 */
void composite(Mat &img,Mat &img2,Mat &dest);


#endif //OPENCV_EXAMPLE_CV_COMPOSITE_H
