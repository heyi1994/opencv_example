//
// @birth: created by Melrose on 2/23/21
// @version: 1.0.0
//
#include "cv_open.h"


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_oc_OpenAndCloseActivity_morphOpen(JNIEnv *env, jobject thiz,
                                                                 jobject source, jobject config)
{
    Mat img;
    bitmap2Mat(env,source,&img);
    auto element = getStructuringElement(MORPH_RECT,Size(7,7));
    morphologyEx(img,img,MORPH_OPEN,element);

    putAuthorToMat(img,1,1);
    return createBitmap(env,img,config);
}



extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_oc_OpenAndCloseActivity_morphClose(JNIEnv *env, jobject thiz,
                                                                  jobject source, jobject config)
{
    Mat img;
    bitmap2Mat(env,source,&img);
    auto element = getStructuringElement(MORPH_RECT,Size(7,7));
    morphologyEx(img,img,MORPH_CLOSE,element);
    putAuthorToMat(img,1,1);
    return createBitmap(env,img,config);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_oc_OpenAndCloseActivity_morphTopHat(JNIEnv *env, jobject thiz,
                                                                   jobject source, jobject config)
{
    Mat img,bgr;
    bitmap2Mat(env,source,&img);
    cvtColor(img,bgr,COLOR_RGBA2BGR);
    auto element = getStructuringElement(MORPH_RECT,Size(7,7));
    morphologyEx(bgr,bgr,MORPH_TOPHAT,element);
    putAuthorToMat(bgr,1,1);
    cvtColor(bgr,img,COLOR_BGR2RGBA);
    return createBitmap(env,img,config);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_oc_OpenAndCloseActivity_morphBlackHat(JNIEnv *env, jobject thiz,
                                                                     jobject source,
                                                                     jobject config)
{
    Mat img,bgr;
    bitmap2Mat(env,source,&img);
    cvtColor(img,bgr,COLOR_RGBA2BGR);
    auto element = getStructuringElement(MORPH_RECT,Size(7,7));
    morphologyEx(bgr,bgr,MORPH_BLACKHAT,element);
    putAuthorToMat(bgr,1,1);
    cvtColor(bgr,img,COLOR_BGR2RGBA);
    return createBitmap(env,img,config);
}