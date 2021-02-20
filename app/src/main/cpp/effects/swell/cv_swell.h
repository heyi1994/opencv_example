//
// Created by melrose on 21-2-20.
//

#ifndef OPENCV_EXAMPLE_CV_SWELL_H
#define OPENCV_EXAMPLE_CV_SWELL_H

#include "../../lib_headers.h"




extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_swell_SwellActivity_dilate(JNIEnv *env, jobject thiz, jobject source,
                                                          jobject config);


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_swell_SwellActivity_erode(JNIEnv *env, jobject thiz, jobject source,
                                                          jobject config);


#endif //OPENCV_EXAMPLE_CV_SWELL_H
