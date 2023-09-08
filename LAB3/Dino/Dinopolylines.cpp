

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <fstream>
#include <vector>

struct Point {
   GLfloat x, y;
};

std::vector<std::vector<Point>> polylines;

void drawPolylines() {
   glColor3f(1.0, 0.0, 1.0); // Set drawing color to black

   for (const auto& polyline : polylines) {
       glBegin(GL_LINE_STRIP);
       for (const auto& point : polyline) {
           glVertex2f(point.x, point.y);
       }
       glEnd();
   }
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   drawPolylines();
   glFlush();
}

void init() {
   glClearColor(0.0, 1.0, 0.0, 0.7); // Set background color to green
   gluOrtho2D(0.0, 650.0, 0.0, 450.0);
   glLineWidth(3.0);
}

void parseData() {
   std::ifstream inFile("dino.dat");
   if (!inFile) {
       std::cerr << "Unable to open file." << std::endl;
       exit(1);
   }

   int numPolylines;
   inFile >> numPolylines;

   for (int i = 0; i < numPolylines; i++) {
       int numVertices;
       inFile >> numVertices;

       std::vector<Point> polyline;
       for (int j = 0; j < numVertices; j++) {
           Point point;
           inFile >> point.x >> point.y;
           polyline.push_back(point);
       }

       polylines.push_back(polyline);
   }

   inFile.close();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(650, 450);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Lab 03: Making Dinosaur");

   parseData();

   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}

