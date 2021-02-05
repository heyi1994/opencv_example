//
// Created by melrose on 21-2-5.
//

#ifndef OPENCV_EXAMPLE_LIB_HEADERS_H
#define OPENCV_EXAMPLE_LIB_HEADERS_H

#include <jni.h>
#include <android/bitmap.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/types_c.h>
using namespace cv;

#include "android/log.h"
#include "utils/utils.h"



#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

#endif //OPENCV_EXAMPLE_LIB_HEADERS_H
