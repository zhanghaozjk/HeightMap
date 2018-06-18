#pragma once
#include "Point.h"
#include "Color.h"
#include "file.h"
class Compress
{
public:
	Compress(char path[], int precision);
	Compress();
	//用灰度图生成坐标点
	void setCoordinate(char path[], int precision);
	//用于贴图
	void setColor(char path[], int precision);
	~Compress();
	//原图像的长和高
	int height;
	int width;
	//压缩图像的长和宽
	int pHeight;
	int pWidth;
	//点的数量
	int pointCount;
	//图像每个点的灰度值
	short** grayImage;
	//压缩图片的灰度值
	Point** compressGrayImage;
	//压缩后点的数量
	int compressPointCount;
	//用于贴图的图片
	Color** colorImage;
	//用于贴图的图片压缩后的rgb
	Color** compressColorImage;
	//压缩精度
	int precision = 4;
	//灰度图图片路径
	char *grayPath;
	//贴图图片路径
	char *colorPath;
};

