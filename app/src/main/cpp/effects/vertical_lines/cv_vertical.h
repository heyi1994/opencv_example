//
// @birth: created by Melrose on 3/10/21
// @version: 1.0.0
//
#include "../../lib_headers.h"



extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_VerticaLines_VerticalLinesActivity_binaryGraph(JNIEnv *env,
                                                                              jobject thiz,
                                                                              jobject source,
                                                                              jobject config);


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_VerticaLines_VerticalLinesActivity_ocVertical(JNIEnv *env,jobject thiz,jobject source,jobject config);



extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_VerticaLines_VerticalLinesActivity_ocHorizontal(JNIEnv *env,
                                                                               jobject thiz,
                                                                               jobject source,
                                                                               jobject config);