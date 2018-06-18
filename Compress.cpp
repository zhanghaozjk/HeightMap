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
	//����ԭʼͼ��Ķ�ά�㼯����
	for (int i = 0; i < height; i++)
	{
		grayImage[i] = new short[width];
	}

	ifstream in("ͼ������.txt");
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

	//����ѹ��ͼƬ�Ķ�ά�㼯����
	compressGrayImage = new Point*[pHeight];
	for (int i = 0; i < pHeight; i++)
	{
		compressGrayImage[i] = new Point[pWidth];
	}

	//�������ڻ�ͼ�ĵ㼯
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
	cout << "���ڻ�ȡ��ͼ��ɫ" << endl;
	this->colorPath = path;
	pickColor(path);
	height = getHeight();
	width = getWidth();
	colorImage = new Color*[height];
	//����ԭʼ��ͼͼ��Ķ�ά�㼯����
	for (int i = 0; i < height; i++)
	{
		colorImage[i] = new Color[width];
	}

	ifstream in("ɫ������.txt");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//��ͼ��˳����bgr
			short b, g, r;
			in >> b >> g >> r;
			colorImage[i][j].setColor(r, g, b);
		}
	}
	in.close();
	pHeight = height / precision;
	pWidth = width / precision;

	//����ѹ��ͼƬ�Ķ�ά�㼯����
	compressColorImage = new Color*[pHeight];
	for (int i = 0; i < pHeight; i++)
	{
		compressColorImage[i] = new Color[pWidth];
	}

	//�������ڻ�ͼ�ĵ㼯
	for (short i = 0, ci = 0; i < height; i += precision, ci++) {
		for (short j = 0, cj = 0; j < width; j += precision, cj++) {
			compressColorImage[ci][cj].r = colorImage[i][j].r;
			compressColorImage[ci][cj].g = colorImage[i][j].g;
			compressColorImage[ci][cj].b = colorImage[i][j].b;
		}
	}
//	delete *colorImage;
	cout << "�Ѿ���ȡ������ͼ��ɫ" << endl;
}

void Compress::setCoordinate(char path[], int precision)
{
	cout << "���ڻ�������" << endl;
	this->grayPath = path;
	this->precision = precision;
	doIt(path);
	height = getHeight();
	width = getWidth();
	pointCount = height * width;
	grayImage = new short*[height];
	cout << height << " " << width << endl;
	//����ԭʼͼ��Ķ�ά�㼯����
	for (int i = 0; i < height; i++)
	{
		grayImage[i] = new short[width];
	}

	ifstream in("ͼ������.txt");
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

	//����ѹ��ͼƬ�Ķ�ά�㼯����
	compressGrayImage = new Point*[pHeight];
	for (int i = 0; i < pHeight; i++)
	{
		compressGrayImage[i] = new Point[pWidth];
	}

	//�������ڻ�ͼ�ĵ㼯
	for (short i = 0, ci = 0; i < height; i += precision, ci++) {
		for (short j = 0, cj = 0; j < width; j += precision, cj++) {
			compressGrayImage[ci][cj].x = i;
			compressGrayImage[ci][cj].y = j;
			compressGrayImage[ci][cj].z = grayImage[i][j];
		}
	}
	//delete *grayImage;
	cout << "�Ѿ���������������Ϣ" << endl;
}

Compress::~Compress()
{
}
