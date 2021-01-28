//
// @birth: created by Melrose on 1/28/21
// @version: 1.0.0
//
#ifndef OPENCV_EXAMPLE_CV_PIXEL_H
#define OPENCV_EXAMPLE_CV_PIXEL_H
#include <jni.h>
#include <android/bitmap.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/types_c.h>
using namespace cv;

#include "android/log.h"
#define LOG_TAG "Melrose_pixel"
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)



/**
 * 黑鲨2 : 75ms左右
 * 将BGRA 4通道图像转为 GRAY 1通道图像并读取每一个像素点 ;
 * @param src  BGRA格式的Mat数据 ;
 * @param dest BGRA格式的目标数据 ;
 */
void gray_read_pixel(Mat & src,Mat &dest);



/**
 * 黑鲨2 : 360ms左右
 * 将BGRA 4通道图像转为 bgr 3通道图像并读取每一个像素点 ;
 * @param src  BGRA格式的Mat数据 ;
 * @param dest BGRA格式的目标数据 ;
 */
void bgr_read_pixel(Mat & src,Mat &dest);

#endif //OPENCV_EXAMPLE_CV_PIXEL_H
