//
// Created by melrose on 21-2-5.
//

#include "cv_contrast.h"



void cv_contrast(Mat &source,float contrast,float intensity)
{
    if (!source.data){
        LOG_W("Picture data is empty");
        return;
    }


    for (int i = 0; i < source.rows; ++i) {

        for (int j = 0; j < source.cols; ++j) {
            float b = source.at<Vec4b>(i,j)[0];
            float g = source.at<Vec4b>(i,j)[1];
            float r = source.at<Vec4b>(i,j)[2];
            source.at<Vec4b>(i,j)[0] = saturate_cast<uchar>(b*contrast+intensity);
            source.at<Vec4b>(i,j)[1] = saturate_cast<uchar>(g*contrast+intensity);
            source.at<Vec4b>(i,j)[2] = saturate_cast<uchar>(r*contrast+intensity);
        }

    }

}




extern "C"
JNIEXPORT void JNICALL
Java_com_melrose1994_opencv_ui_contrast_ContrastActivity_contrast(JNIEnv *env, jobject jthz,jobject source,jobject dest,jfloat contrast,jfloat intensity)
{

    Mat img,img2;

    if (bitmap2mat(env,source,img)&&bitmap2mat(env,dest,img2)){
        img.copyTo(img2);
        cv_contrast(img2,contrast,intensity);
        unlock_bitmap_pixels(env,source);
        unlock_bitmap_pixels(env,dest);
    }

}

