#include "Compress.h"

Compress::Compress(char path[], int precision)
{
	this->grayPath = path;
	this->precision = precision;
	doIt(path);
	height = getHeight();
	width = getWidth();
	pointCount = height * width;
	grayImage = new short*[height];
	cout << height << " " << width << endl;
	//创造原始图像的二维点集数组
	for (int i = 0; i < height; i++)
	{
		grayImage[i] = new short[width];
	}

	ifstream in("图像像素.txt");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			short p = 0;
			in >> p;
			grayImage[i][j] = p;
		}
	}
	in.close();
	pHeight = height / precision;
	pWidth = width / precision;

	//创建压缩图片的二维点集数组
	compressGrayImage = new Point*[pHeight];
	for (int i = 0; i < pHeight; i++)
	{
		compressGrayImage[i] = new Point[pWidth];
	}

	//创造用于画图的点集
	for (short i = 0, ci = 0; i < height; i += precision, ci++) {
		for (short j = 0, cj = 0; j < width; j += precision, cj++) {
			compressGrayImage[ci][cj].x = i;
			compressGrayImage[ci][cj].y = j;
			compressGrayImage[ci][cj].z = grayImage[i][j];
		}
	}
}
Compress::Compress() {}
void Compress::setColor(char path[], int precision)
{
	cout << "正在获取贴图颜色" << endl;
	this->colorPath = path;
	pickColor(path);
	height = getHeight();
	width = getWidth();
	colorImage = new Color*[height];
	//创造原始贴图图像的二维点集数组
	for (int i = 0; i < height; i++)
	{
		colorImage[i] = new Color[width];
	}

	ifstream in("色彩配置.txt");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//读图的顺序是bgr
			short b, g, r;
			in >> b >> g >> r;
			colorImage[i][j].setColor(r, g, b);
		}
	}
	in.close();
	pHeight = height / precision;
	pWidth = width / precision;

	//创建压缩图片的二维点集数组
	compressColorImage = new Color*[pHeight];
	for (int i = 0; i < pHeight; i++)
	{
		compressColorImage[i] = new Color[pWidth];
	}

	//创造用于画图的点集
	for (short i = 0, ci = 0; i < height; i += precision, ci++) {
		for (short j = 0, cj = 0; j < width; j += precision, cj++) {
			compressColorImage[ci][cj].r = colorImage[i][j].r;
			compressColorImage[ci][cj].g = colorImage[i][j].g;
			compressColorImage[ci][cj].b = colorImage[i][j].b;
		}
	}
//	delete *colorImage;
	cout << "已经获取所有贴图颜色" << endl;
}

void Compress::setCoordinate(char path[], int precision)
{
	cout << "正在获得坐标点" << endl;
	this->grayPath = path;
	this->precision = precision;
	doIt(path);
	height = getHeight();
	width = getWidth();
	pointCount = height * width;
	grayImage = new short*[height];
	cout << height << " " << width << endl;
	//创造原始图像的二维点集数组
	for (int i = 0; i < height; i++)
	{
		grayImage[i] = new short[width];
	}

	ifstream in("图像像素.txt");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			short p = 0;
			in >> p;
			grayImage[i][j] = p;
		}
	}
	in.close();
	pHeight = height / precision;
	pWidth = width / precision;

	//创建压缩图片的二维点集数组
	compressGrayImage = new Point*[pHeight];
	for (int i = 0; i < pHeight; i++)
	{
		compressGrayImage[i] = new Point[pWidth];
	}

	//创造用于画图的点集
	for (short i = 0, ci = 0; i < height; i += precision, ci++) {
		for (short j = 0, cj = 0; j < width; j += precision, cj++) {
			compressGrayImage[ci][cj].x = i;
			compressGrayImage[ci][cj].y = j;
			compressGrayImage[ci][cj].z = grayImage[i][j];
		}
	}
	//delete *grayImage;
	cout << "已经获得所有坐标点信息" << endl;
}

Compress::~Compress()
{
}
