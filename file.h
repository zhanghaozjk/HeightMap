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

//读图像的位图数据、宽、高、颜色表及每像素位数等数据进内存，存放在相应的全局变量中  
bool readBmp(char *bmpName);

//给定一个图像位图数据、宽、高、颜色表指针及每像素所占的位数等信息,将其写到指定文件中  
bool saveBmp(char *bmpName, unsigned char *imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable);

//以下为像素的读取函数  
void doIt(char path[]);

//以下为色彩读取函数
void pickColor(char path[]);

int getWidth();
int getHeight();