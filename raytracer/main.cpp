#include <Windows.h>
#include <gl/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <time.h>

#pragma comment( lib, "OpenGl32.lib")
#pragma comment( lib, "glut32.lib")

#define WIDTH 800
#define HEIGHT 600

byte buffer[WIDTH][HEIGHT][3];
void DrawBuffer()
{
	for(int i=0;i<WIDTH;i++)
		for(int j=0;j<HEIGHT;j++)
		{
			glColor3b(buffer[i][j][0],buffer[i][j][1],buffer[i][j][2]);
			glVertex2i(i,j);
		}

}
void Reshape(int w,int h)
{ 
	if(w!=WIDTH || h!=HEIGHT) 
		glutReshapeWindow(WIDTH,HEIGHT); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, h, 0, 0, 1);
	glMatrixMode (GL_MODELVIEW);
}

void Init(void)
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);

}
void Display()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		DrawBuffer();
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	memset(buffer,0,sizeof(byte)*WIDTH*HEIGHT*3);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(200,100);
	glutCreateWindow("RayTracer-5100379008");
	Init();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	//glutKeyboardFunc(Keyboard);
	//glutMouseFunc(MouseEvent);

	glutMainLoop();
	return 0;

}