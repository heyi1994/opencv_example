//
// @birth: created by Melrose on 1/28/21
// @version: 1.0.0
//
#include "cv_pixel.h"



void gray_read_pixel(Mat & src,Mat &dest)
{

    Mat gray;
    cvtColor(src,gray,CV_BGRA2GRAY);

    size_t  width = gray.cols;
    size_t  height = gray.rows;

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
             //读取每个像素点
              int gray_pixel =  gray.at<uchar>(row,col);
             //将其像素点进行修改
              gray.at<uchar>(row,col) = 255 - gray_pixel ;
        }
    }
    cvtColor(gray,dest,CV_GRAY2BGRA);
}


void bgr_read_pixel(Mat & src,Mat &dest)
{
    Mat bgr;
    cvtColor(src,bgr,CV_BGRA2BGR);

    size_t  width = bgr.cols;
    size_t  height = bgr.rows;
    //通道数 ;
    size_t  channels = bgr.channels();

    LOG_D("channels %d",channels);

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            //读取每个像素点
            int blue =  bgr.at<Vec3b>(row,col)[0];
            int green =  bgr.at<Vec3b>(row,col)[1];
            int red =  bgr.at<Vec3b>(row,col)[2];
            //将其像素点进行修改
            bgr.at<Vec3b>(row,col)[0] = 255 - blue;
            bgr.at<Vec3b>(row,col)[1] = 255 - green;
            bgr.at<Vec3b>(row,col)[2] = 255 - red;

        }
    }
    cvtColor(bgr,dest,CV_BGR2BGRA);
}