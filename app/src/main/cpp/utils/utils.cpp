//
// Created by melrose on 21-2-4.
//

#include "utils.h"


bool bitmap2mat(JNIEnv *env,jobject &src ,Mat &dest)
{
    AndroidBitmapInfo bitmapInfo;
    void * bitmapPixels;
    if (AndroidBitmap_getInfo(env,src,&bitmapInfo)>=0
        &&AndroidBitmap_lockPixels(env,src,&bitmapPixels)>=0){
        dest = Mat(bitmapInfo.width,bitmapInfo.height,CV_8UC4,bitmapPixels);
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




void unlock_bitmap_pixels(JNIEnv *env,jobject &bitmap){
    AndroidBitmap_unlockPixels(env,bitmap);
}

