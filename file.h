#define _CRT_SECURE_NO_WARNINGS  
#pragma once
#include <windows.h>  
#include <stdlib.h>  
#include <math.h>  
#include <iomanip>   
#include <fstream>  
#include <iostream>  
#include <string>
using namespace std;

//��ͼ���λͼ���ݡ����ߡ���ɫ��ÿ����λ�������ݽ��ڴ棬�������Ӧ��ȫ�ֱ�����  
bool readBmp(char *bmpName);

//����һ��ͼ��λͼ���ݡ����ߡ���ɫ��ָ�뼰ÿ������ռ��λ������Ϣ,����д��ָ���ļ���  
bool saveBmp(char *bmpName, unsigned char *imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable);

//����Ϊ���صĶ�ȡ����  
void doIt(char path[]);

//����Ϊɫ�ʶ�ȡ����
void pickColor(char path[]);

int getWidth();
int getHeight();