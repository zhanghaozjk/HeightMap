#define GLUT_DISABLE_ATEXIT_HACK

#include "Compress.h"
#include <iostream>
#include <gl\gl.h>
#include <gl\glut.h>

using namespace std;
//相机位置
int eyex = 512, eyey = -60, eyez = 400;
//相机镜头朝向
int centerx = 512, centery = 512, centerz = 0;
//相机位置朝向
int upx = 0, upy = 0, upz = 1;

Compress compress;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(120.0, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(1.0f);    //修改点的尺寸，默认大小为1.0f
	cout << "三维点集加载中" << endl;
	glShadeModel(GL_SMOOTH);// 三角形贴图平滑过渡
	
	for (int i = 0; i < compress.pHeight - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP); // 三角形带
		for (int j = 0; j < compress.pWidth; j++) {
			glColor3f((float)compress.compressColorImage[i][j].r / 255,
				(float)compress.compressColorImage[i][j].g / 255,
				(float)compress.compressColorImage[i][j].b / 255);
			glVertex3f(compress.compressGrayImage[i][j].x,
				compress.compressGrayImage[i][j].y,
				compress.compressGrayImage[i][j].z);
			glColor3f((float)compress.compressColorImage[i+1][j].r / 255,
				(float)compress.compressColorImage[i+1][j].g / 255,
				(float)compress.compressColorImage[i+1][j].b / 255);
			glVertex3f(compress.compressGrayImage[i+1][j].x,
				compress.compressGrayImage[i+1][j].y,
				compress.compressGrayImage[i+1][j].z);
		}
		glEnd();
	}
	cout << "三维点集加载完毕，请等待绘制" << endl;
	glutSwapBuffers();
}

void userInterface() 
{
	int choice = 0;
	int precision = 1;
	cout << "请选择图像\n1、峡谷\n2、山丘" << endl;
	cin >> choice;
	cout << "请输入精度,所输入的数应为1或能被2整除" << endl;
	cin >> precision;
	if (choice == 1)
	{
		char grayPath[] = "images/canyon_elev.bmp";
		char colorPath[] = "images/canyon_text.bmp";
		compress.setCoordinate(grayPath, precision);
		compress.setColor(colorPath, precision);
	}
	else if (choice == 2)
	{
		char grayPath[] = "images/puget_elev.bmp";
		char colorPath[] = "images/puget_text.bmp";
		compress.setCoordinate(grayPath, precision);
		compress.setColor(colorPath, precision);
	}

	cout << "请输入视角\n1、正视图 \n2、侧视图 \n3、俯视图 \n4、右视图" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		eyex = compress.height / 2;
		eyey = -60;
		centerx = compress.height / 2;
		centery = compress.width / 2;
		break;
	case 2:
		eyex = -60;
		eyey = compress.width / 2;
		centerx = compress.height / 2;
		centery = compress.width / 2;
		break;
	case 3:
		eyex = compress.height / 2;
		eyey = compress.width / 2;
		centerx = compress.height / 2;
		centery = compress.width / 2;
		upz = 0;
		upy = 1;
		break;
	case 4:
		eyex = compress.height / 2;
		eyey = compress.width + 60;
		centerx = compress.height / 2;
		centery = compress.width / 2;
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	
	userInterface();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("三维地形绘制");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
