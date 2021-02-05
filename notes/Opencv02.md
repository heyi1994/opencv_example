## 调整图像亮度和对比度

  图像的变换可以看作如下几点：

 - 像素变换：点变化
 - 领域操作：区域变化
  调整图像亮度和对比度属于像素变换，公式如下，g(i,j)表示输出图像的像素点,f(i,j)是输入图像的像素点。其中α>0，β是增益变量：
```
 g(i,j) = αf(i,j)+β
```
  提高亮度就是将β向255白色靠拢，提高对比度是将α提高

### OpenCv中的一些重要的API

 - 创建一张跟原图像大小和类型一致的空白图像、像素值初始化为0 ;
```
  Mat new_image = Mat::zeros(image.size(),image.type());
```
 - 确保值大小范围在0~255之间
```
  saturate_cast<uchar>(value);
```
 - 给每个像素点每个通道赋值

```
  Mat.at<Vec4b>(y,x)[index] = value ;
```

### 代码演示
 [cv_contrast.h](../app/src/main/cpp/effects/contrast/cv_contrast.h)代码如下:


```c++
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
```

