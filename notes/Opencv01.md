## 图像混合

### 线性混合操作

```
  g(x) = (1-a)f0(x)+af1(x)
```
f0(x)为一幅图像，f1(x)表示另外一幅图像。其中a表示图像所占的权重，其取值范围为0～1之间，g(x)表示生成合成后的图像。


### 在opencv中的API

```c++

void addWeighted(InputArray src1, double alpha, InputArray src2,
                              double beta, double gamma, OutputArray dst, int dtype = -1);
```

 - src1 : 输入图像Mat 1
 - alpha : 输入图像src1的alpha值
 - src2 : 输入图像Mat 2
 - beta : 输入图像src2的alpha值
 - gamma : gamma值, 0
 - dst : 输出混合图像

 > 注意: 两张图片的大小和类型必须要一致才可以

 [cv_composite.h](../app/src/main/cpp/effects/composite/cv_composite.h)代码如下:

 ```c++
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
 ```

