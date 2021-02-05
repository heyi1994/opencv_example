//
// Created by melrose on 21-2-2.
//

#include "cv_composite.h"


void composite(Mat &img,Mat &img2,Mat &dest)
{
    if (img.rows != img2.rows || img.cols != img2.cols || img.type() != img2.type()){
        LOG_W("The two pictures are not the same!");
        return;
    }
    //第一张图片的透明度
    double  alpha = 0.4;
    addWeighted(img,alpha,img2,1-alpha,0.0,dest);
}