#include <GL/glut.h>
#include <cmath>

// Circle parameters
const float radius = 0.5;
const int numSegments = 100;

void drawCircle() {
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.5, 0.5, 0.0); // Pink color
   glVertex2f(0.0, 0.0); // Center of the circle
   for (int i = 0; i <= numSegments; ++i) {
       float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); // Angle in radians
       float x = radius * cos(theta);
       float y = radius * sin(theta);
       glVertex2f(x, y);
   }
   glEnd();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

   // Draw the circle
   drawCircle();

   glFlush();
}

void reshape(int w, int h) {
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(800, 600);
   glutCreateWindow(" Circle Drawing using GLUT");
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
