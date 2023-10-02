//#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
//#include <cmath>
//using namespace std;
//
//const int screenWidth = 650;
//const int screenHeight = 450;
//const int numDinosaurs = 24;  // Number of dinosaurs in the circle
//const float circleRadius = min(screenWidth, screenHeight) * 0.4;  // Radius of the circle
//
//void drawDinosaur(string fileName) {
//    fstream inStream;
//    inStream.open(fileName, ios::in);
//
//    if (inStream.fail()) {
//        cout << "Can't open " << fileName << endl;
//        return;
//    }
//
//    // Read the number of polylines in the dinosaur
//    GLfloat numpolys, numPoints, x, y;
//    inStream >> numpolys;
//
//    for (int j = 0; j < numpolys; j++) {
//        inStream >> numPoints;
//        glBegin(GL_LINE_STRIP);
//
//        for (int i = 0; i < numPoints; i++) {
//            inStream >> x >> y;
//            glVertex2f(x, y);
//        }
//
//        glEnd();
//    }
//
//    inStream.close();
//}
//
//void myInit(void) {
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glPointSize(2.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
//    glViewport(0, 0, screenWidth, screenHeight);
//}
//
//void myDisplay(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0f, 0.0f, 0.0f);
//
//    for (int i = 0; i < numDinosaurs; i++) {
//        glPushMatrix();
//        // Calculate the angle for each dinosaur in the circle
//        float angle = (360.0 / numDinosaurs) * i;
//        // Translate to the position on the circle
//        glTranslatef(screenWidth / 2.0 + circleRadius * cos(angle * 3.14159265 / 180.0),
//            screenHeight / 2.0 + circleRadius * sin(angle * 3.14159265 / 180.0), 0);
//        // Scale down the size of the dinosaur
//        glScalef(0.1, 0.1, 0.1);  // Adjust the scaling factor as needed
//        // Rotate the dinosaur to point its feet towards the origin
//        glRotatef(angle - 90, 0, 0, 1);
//        drawDinosaur("dino.dat");
//        glPopMatrix();
//    }
//
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(screenWidth, screenHeight);
//    glutInitWindowPosition(10, 10);
//    glutCreateWindow("Dinosaur Circle");
//
//    glutDisplayFunc(myDisplay);
//    myInit();
//    glutMainLoop();
//    return 1;
//}
