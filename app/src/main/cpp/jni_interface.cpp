#include "jni_interface.h"

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_melrose1994_opencv_1example_OpenCv_gray(JNIEnv *env, jclass clazz, jintArray buf,
                                                 jint width, jint height)
{
   jint * c_buf =env->GetIntArrayElements(buf,JNI_FALSE);
    Mat imgData(height, width, CV_8UC4, (unsigned char *) c_buf);
    uchar* ptr = imgData.ptr(0);
    for(int i = 0; i < width*height; i ++){
        //计算公式：Y(亮度) = 0.299*R + 0.587*G + 0.114*B
        // 对于一个int四字节，其彩色值存储方式为：BGRA
        int grayScale = (int)(ptr[4*i+2]*0.299 + ptr[4*i+1]*0.587 + ptr[4*i+0]*0.114);
        ptr[4*i+1] = grayScale;
        ptr[4*i+2] = grayScale;
        ptr[4*i+0] = grayScale;
    }
    int size = width * height;
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, c_buf);
    env->ReleaseIntArrayElements(buf, c_buf, 0);
    return result;
}