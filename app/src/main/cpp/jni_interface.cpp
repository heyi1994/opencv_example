#include "jni_interface.h"


extern "C"
JNIEXPORT jboolean JNICALL
Java_com_melrose1994_opencv_1example_OpenCvBitmap_gray(JNIEnv *env, jclass clazz, jobject src, jobject dest)
{
    Mat source,dst;
    if (lock_bitmap_pixels(env,src,dest,&source,&dst)){
        Mat grayMat;
        cvtColor(source, grayMat, CV_BGRA2GRAY);
        cvtColor(grayMat, dst, CV_GRAY2BGRA);
        unlock_bitmap_pixels(env,src);
        unlock_bitmap_pixels(env,dest);
        return true;
    }
    return false;
}



extern "C"
JNIEXPORT jboolean JNICALL
Java_com_melrose1994_opencv_1example_OpenCvBitmap_debug(JNIEnv *env, jclass clazz, jobject src, jobject dest)
{
    Mat source,dst;
    if (lock_bitmap_pixels(env,src,dest,&source,&dst)){

        //gray_read_pixel(source,dst);



        bgr_read_pixel(source,dst);

        unlock_bitmap_pixels(env,src);
        unlock_bitmap_pixels(env,dest);
        return true;
    }
    return false;
}




extern "C"
JNIEXPORT jboolean JNICALL
Java_com_melrose1994_opencv_1example_OpenCvBitmap_composite(JNIEnv *env, jclass clazz,jobject bitmap, jobject bitmap2,jobject dest)
{
  Mat img1,img2,show;
  if (bitmap2mat(env,bitmap,img1)&&bitmap2mat(env,bitmap2,img2)&&bitmap2mat(env,dest,show)){


      composite(img1,img2,show);

      unlock_bitmap_pixels(env,bitmap);
      unlock_bitmap_pixels(env,bitmap2);
      unlock_bitmap_pixels(env,dest);
      return true;
  }

    return false;
}

