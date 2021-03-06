
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

using namespace std;

void display();
void drawXYCoordinatePlane(int left, int right, int bottom, int top);
void drawGrid(int left, int right, int bottom, int top);


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	//  glutInitWindowSize(350, 350);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("openGL");
	glutDisplayFunc(display);
	glutSwapBuffers();
	glutMainLoop();
	return 0;
}


void display(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//  glViewport(0,0,640,480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 5.0, -5.0, 5);
	glMatrixMode(GL_MODELVIEW);

	drawXYCoordinatePlane(-5, 5, -5, 5);
	//  drawGrid(-5, 5, -5, 5);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	glColor3f(1.0, 0.0, 0.0);
	//    glBegin(GL_POINTS);
	//    glBegin(GL_LINES);
	//    glBegin(GL_LINE_STRIP);
	glBegin(GL_TRIANGLES);
	glVertex2i(-4, 0);
	glVertex2i(-3, 2);
	glVertex2i(-2, 0);
	glVertex2i(-1, 2);
	glVertex2i(0, 0);
	glVertex2i(1, 2);
	glVertex2i(2, 0);
	glVertex2i(3, 2);
	glEnd();

	glFlush();

}

void drawXYCoordinatePlane(int left, int right, int bottom, int top){

	glEnable(GL_LINE_WIDTH);
	glLineWidth(2);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	//X axis
	glVertex2i(left, 0);
	glVertex2i(right, 0);

	//Y axis
	glVertex2i(0, bottom);
	glVertex2i(0, top);
	glEnd();

	glLineWidth(1);
	glDisable(GL_LINE_WIDTH);
	drawGrid(left, right, bottom, top);
}

void drawGrid(int left, int right, int bottom, int top){
	glColor3f(0.0, 0.0, 0.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xAAAA);
	glBegin(GL_LINES);
	for (int i = left; i < right; i++){
		glVertex2i(i, bottom);
		glVertex2i(i, top);
	}
	for (int i = bottom; i < top; i++){
		glVertex2i(bottom, i);
		glVertex2i(top, i);
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);


}

//    glBegin(GL_LINE_STRIP);
//    glBegin(GL_LINE_LOOP);
