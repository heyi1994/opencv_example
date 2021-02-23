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

#include <string>

#include "android/log.h"


#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
/**
 * bitmap转mat ，会lock bitmap的pixels, 4通道 bgra ;
 * @deprecated old ;
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



/**
    * Bitmap Rotation matrix
    * @param env JNI Environmental Science
    * @param bitmap Bitmap object
    * @param mat Picture matrix
    * @param needPremultiplyAlpha Does it multiply transparency?
    */
void bitmap2Mat(JNIEnv *env, jobject &bitmap, Mat *mat, bool needPremultiplyAlpha = false);

/**
 * Matrix to Bitmap
 * @param env JNI Environmental Science
 * @param mat Picture matrix
 * @param bitmap Bitmap object
 * @param needPremultiplyAlpha Does it multiply transparency?
 */
void mat2Bitmap(JNIEnv *env, Mat &mat, jobject &bitmap, bool needPremultiplyAlpha = false);

/**
 *
 * Create Bitmap
 * @param env JNI Environmental Science
 * @param src matrix
 * @param config Bitmap To configure
 * @return Bitmap object
 */
jobject createBitmap(JNIEnv *env, Mat &src, jobject &config);


/**
 * 给图像加上名字 ;
 */
void putAuthorToMat(Mat &target,int thickness = 8,int fontScale = 3);


#endif //OPENCV_EXAMPLE_UTILS_H
