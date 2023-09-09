#include <iostream>
#include <fstream>
#include <string>
#include <gl/glut.h>
#include <vector>

class Dot {
public:
    int x = -1;
    int y = -1;
    Dot(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Dot() = default;
};

int screenWidth = 640;
int screenHeight = 480;
int dot_x = -1;
int dot_y = -1;

float minX = -1.0, minY = -1.0, maxX = 1.0, maxY = 1.0;
int VPBottom = 0, VPLeft = 0, VPWidth = 640, VPHeight = 480;

std::vector<Dot> dotsVector = {};
std::string enteredText = "";  // New variable to store entered text

void initGL() {
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glColor3f(0, 0, 0);
}

void drawDot(int x, int y) {
    glColor3f(1.0f, 0.0f, 1.0f);
    glPointSize(11.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// New function to display entered text
void drawText(int x, int y, const std::string& text) {
    glColor3f(0.0f, 1.0f, 1.0f);  // Set text color to black
    glRasterPos2i(x, y);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw all the stored dots
    for (int i = 0; i < dotsVector.size(); i++) {
        drawDot(dotsVector[i].x, dotsVector[i].y);
    }

    // Display the entered text
    drawText(10, 10, enteredText);

    glFlush();
}

void reshape(int width, int height) {
    screenWidth = width;
    screenHeight = height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboardHandler(unsigned char key, int x, int y) {
    switch (key) {
    case 'q':
        exit(0);
    case 13:  // 13 is the ASCII code for Enter key
        enteredText += '\n';  // Add a newline character when Enter is pressed
        break;
    case 8:   // 8 is the ASCII code for Backspace key
        if (!enteredText.empty()) {
            enteredText.pop_back();  // Remove the last character when Backspace is pressed
        }
        break;
    default:
        enteredText += key;  // Add the pressed key to the entered text
        break;
    }
    glutPostRedisplay();
}

void mouseHandler(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        dot_x = x;
        dot_y = screenHeight - y;
        Dot newDot = Dot(x, screenHeight - y);
        dotsVector.push_back(newDot);
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glutPostRedisplay();
}

void motionHandler(int x, int y) {
    dot_x = x;
    dot_y = screenHeight - y;
    Dot newDot = Dot(x, screenHeight - y);
    dotsVector.push_back(newDot);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Writing & Drawing with Brush");
    glutInitWindowPosition(30, 30);
    initGL();

    glutDisplayFunc(myDisplay);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardHandler);
    glutMouseFunc(mouseHandler);
    glutMotionFunc(motionHandler);

    glutMainLoop();
    return 0;
}
