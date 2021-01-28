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
        unlock_bitmap_pixels(env,src,dest);
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

        unlock_bitmap_pixels(env,src,dest);
        return true;
    }
    return false;
}

bool lock_bitmap_pixels(JNIEnv *env,jobject &src ,jobject &dest,Mat *source,Mat *dst)
{
    AndroidBitmapInfo bitmapInfo;
    void * bitmapPixels;
    void * destBitmapPixels;
    if (AndroidBitmap_getInfo(env,src,&bitmapInfo)>=0
        &&AndroidBitmap_lockPixels(env,src,&bitmapPixels)>=0&&AndroidBitmap_lockPixels(env,dest,&destBitmapPixels)>=0){
        *source = Mat(bitmapInfo.width,bitmapInfo.height,CV_8UC4,bitmapPixels);
        *dst = Mat(bitmapInfo.width,bitmapInfo.height,CV_8UC4,destBitmapPixels);
        return true;
    }

    return false;
}




void unlock_bitmap_pixels(JNIEnv *env,jobject &src ,jobject &dest)
{
    AndroidBitmap_unlockPixels(env,src);
    AndroidBitmap_unlockPixels(env,dest);
}

