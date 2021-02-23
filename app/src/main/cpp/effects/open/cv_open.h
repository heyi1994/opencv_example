//
// @birth: created by Melrose on 2/23/21
// @version: 1.0.0
//
#ifndef OPENCV_EXAMPLE_CV_OPEN_H
#define OPENCV_EXAMPLE_CV_OPEN_H

#include "../../lib_headers.h"


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_oc_OpenAndCloseActivity_morphOpen(JNIEnv *env, jobject thiz,
                                                                 jobject source, jobject config);



extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_oc_OpenAndCloseActivity_morphClose(JNIEnv *env, jobject thiz,
                                                                  jobject source, jobject config);



extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_oc_OpenAndCloseActivity_morphTopHat(JNIEnv *env, jobject thiz,
                                                                   jobject source, jobject config) ;



extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_oc_OpenAndCloseActivity_morphBlackHat(JNIEnv *env, jobject thiz,
                                                                     jobject source,
                                                                     jobject config) ;
#endif //OPENCV_EXAMPLE_CV_OPEN_H
