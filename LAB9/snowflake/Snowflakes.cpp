#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "Canvas.h"

#define TWOPI 2*3.14159265

const int SCREENWIDTH = 680;
const int SCREENHEIGHT = 480;

Point2 CP1;
Canvas cvs(SCREENWIDTH, SCREENHEIGHT, "Snowflake");

void snowflakemotif(float L) {
	cvs.moveTo(0.0, 0.1 * L);
	cvs.turnTo(0);
	cvs.forward(2 * L, 1);
	cvs.turn(60);
	cvs.forward(1 * L, 1);
	cvs.turn(270);
	cvs.forward(0.2 * L, 1);
	cvs.turn(270);
	cvs.forward(0.9 * L, 1);
	cvs.turn(120);
	cvs.forward(1 * L, 1);
	cvs.turn(60);
	cvs.forward(0.9 * L, 1);
	cvs.turn(270);
	cvs.forward(0.2 * L, 1);
	cvs.turn(270);
	cvs.forward(0.8 * L, 1);
	cvs.turn(120);
	cvs.forward(1 * L, 1);
	cvs.turn(330);
	cvs.forward(0.2 * L, 1);
	cvs.turn(30);
}
void snowflake(float L) {
	glTranslatef(SCREENWIDTH / 2.0, SCREENHEIGHT / 2.0, 0.0);
	for (int count = 0; count < 6; count++) // draw a snowflake
	{
		snowflakemotif(L);
		cvs.scale2D(1.0, -1.0);
		snowflakemotif(L);
		cvs.scale2D(1.0, -1.0);
		cvs.rotate2D(60.0); // concatenate a 60 degree rotation
	}

}
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);  // set white background color
	glColor3f(0.0f, 0.0f, 0.0f);  // set the drawing color
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	cvs.setWindow(0.0, SCREENWIDTH, 0.0, SCREENHEIGHT);
	cvs.setViewport(0, SCREENWIDTH, 0, SCREENHEIGHT);
	snowflake(50.0);

	glFlush();
}
void main(int argc, char** argv) {
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}