//
// Created by melrose on 21-2-4.
//

#ifndef OPENCV_EXAMPLE_UTILS_H
#define OPENCV_EXAMPLE_UTILS_H

#include <jni.h>
#include <android/bitmap.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/types_c.h>
using namespace cv;

#include "android/log.h"


#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
/**
 *  bitmap转mat ，会lock bitmap的pixels, 4通道 bgra ;
 * @param src bitmap obj
 * @param dest mat address
 * @return success or failed .
 */
bool bitmap2mat(JNIEnv *env,jobject &src ,Mat &dest);

/**
 * 将两个bitmap转两个mat,4通道 bgra ;
 */
bool lock_bitmap_pixels(JNIEnv *env,jobject &src ,jobject &dest,Mat *source,Mat *dst);

/**
 * 解锁bitmap的 pixels;
 */
void unlock_bitmap_pixels(JNIEnv *env,jobject &bitmap);


#endif //OPENCV_EXAMPLE_UTILS_H
