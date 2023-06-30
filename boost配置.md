# Windows环境

## 准备MinGW编译环境

#### 下载MinGW编译器

[MinGW-w64 - for 32 and 64 bit Windows - Browse /mingw-w64 at SourceForge.net](https://sourceforge.net/projects/mingw-w64/files/mingw-w64/)

![image-20230701005004784](ImagesMarkDown/boost配置/image-20230701005004784.png)

#### 设置环境变量

![image-20230701005209301](ImagesMarkDown/boost配置/image-20230701005209301.png)

## 编译boost

```cmd
#第一步 
bootstrap.bat gcc
b2.exe install --prefix=D:\Program Files\common-cpp\boost\boost_1_71_0 --build-type=complete toolset=gcc threading=multi
```

