#pragma once
#include "Point.h"
#include "Color.h"
#include "file.h"
class Compress
{
public:
	Compress(char path[], int precision);
	Compress();
	//�ûҶ�ͼ���������
	void setCoordinate(char path[], int precision);
	//������ͼ
	void setColor(char path[], int precision);
	~Compress();
	//ԭͼ��ĳ��͸�
	int height;
	int width;
	//ѹ��ͼ��ĳ��Ϳ�
	int pHeight;
	int pWidth;
	//�������
	int pointCount;
	//ͼ��ÿ����ĻҶ�ֵ
	short** grayImage;
	//ѹ��ͼƬ�ĻҶ�ֵ
	Point** compressGrayImage;
	//ѹ����������
	int compressPointCount;
	//������ͼ��ͼƬ
	Color** colorImage;
	//������ͼ��ͼƬѹ�����rgb
	Color** compressColorImage;
	//ѹ������
	int precision = 4;
	//�Ҷ�ͼͼƬ·��
	char *grayPath;
	//��ͼͼƬ·��
	char *colorPath;
};

