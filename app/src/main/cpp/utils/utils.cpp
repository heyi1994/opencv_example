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




void bitmap2Mat(JNIEnv *env, jobject &bitmap, Mat *mat, bool needPremultiplyAlpha) {
    AndroidBitmapInfo info;
    void *pixels = nullptr;
    Mat &dst = *mat;
    //Access to information and some assertions
    CV_Assert(AndroidBitmap_getInfo(env, bitmap, &info) >= 0);//Get Bitmap information
    CV_Assert(info.format == ANDROID_BITMAP_FORMAT_RGBA_8888//Picture format RGBA_8888 or RGB_565
              || info.format == ANDROID_BITMAP_FORMAT_RGB_565);
    CV_Assert(AndroidBitmap_lockPixels(env, bitmap, &pixels) >= 0);
    CV_Assert(pixels);

    dst.create(info.height, info.width, CV_8UC4);
    if (info.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
        Mat tmp(info.height, info.width, CV_8UC4, pixels);
        if (needPremultiplyAlpha) {
            cvtColor(tmp, dst, COLOR_mRGBA2RGBA);
        } else {
            tmp.copyTo(dst);
        }
    } else {
        Mat tmp(info.height, info.width, CV_8UC2, pixels);
        cvtColor(tmp, dst, COLOR_BGR5652RGBA);
    }
    AndroidBitmap_unlockPixels(env, bitmap);
}

void mat2Bitmap(JNIEnv *env,  Mat &mat, jobject &bitmap,bool needPremultiplyAlpha) {
    AndroidBitmapInfo info;
    void *pixels = nullptr;
    CV_Assert(AndroidBitmap_getInfo(env, bitmap, &info) >= 0);//Get Bitmap information
    CV_Assert(info.format == ANDROID_BITMAP_FORMAT_RGBA_8888//Picture format RGBA_8888 or RGB_565
              || info.format == ANDROID_BITMAP_FORMAT_RGB_565);
    CV_Assert(mat.dims==2&&info.height==(uint32_t)mat.rows && info.width==(uint32_t)mat.cols);
    CV_Assert(mat.type()==CV_8UC1||mat.type()==CV_8UC3||mat.type()==CV_8UC4);
    CV_Assert(AndroidBitmap_lockPixels(env, bitmap, &pixels) >= 0);
    CV_Assert(pixels);

    if (info.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
        Mat tmp(info.height, info.width, CV_8UC4, pixels);
        switch (mat.type()){
            case CV_8UC1:
                cvtColor(mat,tmp,COLOR_GRAY2RGBA);
                break;
            case CV_8UC3:
                cvtColor(mat,tmp,COLOR_RGB2RGBA);
                break;
            case CV_8UC4:
                cvtColor(mat,tmp,COLOR_RGBA2mRGBA);
                if (needPremultiplyAlpha) {
                    cvtColor(mat, tmp, COLOR_RGBA2mRGBA);
                } else {
                    mat.copyTo(tmp);
                }
                break;
            default:break;
        }
    } else {
        Mat tmp(info.height, info.width, CV_8UC2, pixels);
        switch (mat.type()){
            case CV_8UC1:
                cvtColor(mat,tmp,COLOR_GRAY2BGR565);
                break;
            case CV_8UC3:
                cvtColor(mat,tmp,COLOR_RGB2BGR565);
                break;
            case CV_8UC4:
                cvtColor(mat,tmp,COLOR_RGBA2BGR565);
                break;
            default:break;
        }
    }
    AndroidBitmap_unlockPixels(env, bitmap);
}


jobject createBitmap(JNIEnv *env, Mat &src, jobject &config){
    jclass java_bitmap_class=(jclass)env->FindClass("android/graphics/Bitmap");//Class name
    jmethodID mid=env->GetStaticMethodID(java_bitmap_class,"createBitmap",//Acquisition method
                                         "(IILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;");
    jobject bitmap=env->CallStaticObjectMethod(java_bitmap_class,mid,src.cols,src.rows,config);
    mat2Bitmap(env,src,bitmap, false);
    return  bitmap;
}



void putAuthorToMat(Mat &target,std::string author){
    putText(target,author,Point(10,200),FONT_HERSHEY_SIMPLEX,3,Scalar(255,255,255),8,LINE_AA);

}