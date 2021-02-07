//
// Created by melrose on 21-2-5.
//

#ifndef OPENCV_EXAMPLE_CV_CONTRAST_H
#define OPENCV_EXAMPLE_CV_CONTRAST_H

//对比度和亮度的调整
#include "../../lib_headers.h"



/**
 *
 * 提高图像的对比度和亮度 ;
 * @param source 需要操作的图像, bgra 4通道 ;
 * @param contrast 对比度 1.0 - 2.0;
 * @param intensity 亮度 0.0-255.0 ;
 */
void cv_contrast(Mat &source,float contrast,float intensity);




extern "C"
JNIEXPORT void JNICALL
Java_com_melrose1994_opencv_ui_contrast_ContrastActivity_contrast(JNIEnv *env, jobject jthz,jobject source,jobject dest,jfloat contrast,jfloat intensity);


#endif //OPENCV_EXAMPLE_CV_CONTRAST_H
