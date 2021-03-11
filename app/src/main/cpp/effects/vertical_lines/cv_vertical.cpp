//
// @birth: created by Melrose on 3/10/21
// @version: 1.0.0
//
#include "cv_vertical.h"


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_VerticaLines_VerticalLinesActivity_binaryGraph(JNIEnv *env,
                                                                              jobject thiz,
                                                                              jobject source,
                                                                              jobject config)
{
    Mat img,gray,binary;
    bitmap2Mat(env,source,&img);
    //转为灰度图
    cvtColor(img,gray,COLOR_RGBA2GRAY);
    //转为二值图
    adaptiveThreshold(~gray,binary,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,0);
    putAuthorToMat(binary);
    return createBitmap(env,binary,config);
}


extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_VerticaLines_VerticalLinesActivity_ocVertical(JNIEnv *env,jobject thiz,jobject source,jobject config)
{

    Mat img,gray,binary,temp;
    bitmap2Mat(env,source,&img);
    cvtColor(img,gray,COLOR_RGBA2GRAY);
    adaptiveThreshold(~gray,binary,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,0);
    //横向的线
    auto vLine = getStructuringElement(MORPH_RECT,Size(1,binary.rows/16));

    //开操作
    erode(binary,temp,vLine);
    dilate(temp,temp,vLine);

    //将背景变为白色
    bitwise_not(temp,temp);

    putAuthorToMat(temp);
    return createBitmap(env,temp,config);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_melrose1994_opencv_ui_VerticaLines_VerticalLinesActivity_ocHorizontal(JNIEnv *env,
                                                                               jobject thiz,
                                                                               jobject source,
                                                                               jobject config)
{
    Mat img,gray,binary,temp;
    bitmap2Mat(env,source,&img);
    cvtColor(img,gray,COLOR_RGBA2GRAY);
    adaptiveThreshold(~gray,binary,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,0);
    //横向的线
    auto hLine = getStructuringElement(MORPH_RECT,Size(binary.cols/16,1));

    //开操作
    erode(binary,temp,hLine);
    dilate(temp,temp,hLine);
    bitwise_not(temp,temp);
    putAuthorToMat(temp);
    return createBitmap(env,temp,config);
}