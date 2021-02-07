//
// @birth: created by Melrose on 1/28/21
// @version: 1.0.0
//
#ifndef OPENCV_EXAMPLE_CV_PIXEL_H
#define OPENCV_EXAMPLE_CV_PIXEL_H

#include "lib_headers.h"


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
