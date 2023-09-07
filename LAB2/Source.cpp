#include <GL/glut.h>
#include <cmath>

int screenWidth = 1000;
int screenHeight = 600;

void initGL() {
    glClearColor(135 / 255.0, 206 / 255.0, 235 / 255.0, 1.0f / 255.0);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.142 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void drawHouse() {
    // House Body
    glColor3ub(255, 170, 190);
    glBegin(GL_POLYGON);
    glVertex2d(150, 100);
    glVertex2d(450, 100);
    glVertex2d(450, 300);
    glVertex2d(150, 300);
    glEnd();

    // Roof
    glColor3ub(255, 0, 255);
    glBegin(GL_TRIANGLES);
    glVertex2d(150, 300);
    glVertex2d(300, 400);
    glVertex2d(450, 300);
    glEnd();

    // Door
    glColor3ub(128, 0, 128);
    glBegin(GL_POLYGON);
    glVertex2d(270, 100);
    glVertex2d(330, 100);
    glVertex2d(330, 170);
    glVertex2d(270, 170);
    glEnd();
}

void drawSun() {
    // Sun
    glColor3ub(255, 255, 0);
    circle(40, 40, 850, 500);
}

void drawTree() {
    // Tree Trunk
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(700, 100);
    glVertex2d(750, 100);
    glVertex2d(750, 250);
    glVertex2d(700, 250);
    glEnd();

    // Tree Top
    glColor3ub(0, 128, 0);
    circle(120, 80, 725, 275);
}



void drawGrass() {
    // Green Grass
    glColor3ub(0, 128, 0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(screenWidth, 0);
    glVertex2d(screenWidth, 100);
    glVertex2d(0, 100);
    glEnd();
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    drawGrass();
    drawSun();
    drawHouse();
    drawTree();
    

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple Scene");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screenWidth, 0, screenHeight, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(myDisplay);
    initGL();
    glutMainLoop();

    return 0;
}
