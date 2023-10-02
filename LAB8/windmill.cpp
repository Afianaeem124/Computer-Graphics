#include <gl/glut.h>
#include <cstdlib>
#define PI 3.141592

void display(void);
void drawWind(void);
void drawwindmill(void);
void drawplane();
void drawlandscape();
void Timer(int value);
void keyboard(unsigned char key, int x, int y);
void init(void);
void reshape(GLsizei w, GLsizei h);

// Define variables for windmill blade rotation and plane animation
float fanRotation = 0.0;
float planeX = 245.0;
float planeY = 230.0;
bool planeCrashed = false;
float fanRotationSpeed = 2.0;
float planeSpeed = 1.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawlandscape();
    drawplane();
    drawwindmill();

    glutSwapBuffers();
}

void drawWind()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(0.0, 0.0);
    glVertex2f(15.0, 30.0);
    glVertex2f(-15.0, 30.0);
    glEnd();
}
void drawlandscape()
{
    /* Draw a box of grass */
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(250.0, 0.0);
    glColor3f(0.0, 0.9, 0.0);
    glVertex2f(250.0, 50.0);
    glColor3f(0.0, 0.8, 0.0);
    glVertex2f(0.0, 50.0);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    /* An attempt at a few snow covered mountains */

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.6);
    glVertex2f(250.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(200.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(150.0, 50.0);

    //glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(200.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(150.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);

    glColor3f(0.0, 0.0, 0.7);
    glVertex2f(150.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(100.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(50.0, 50.0);

    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(50.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(0.0, 50.0);

    glEnd();

    

}

void drawwindmill()
{
    // Draw the windmill structure
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.0); // Gray color


    // Top part
    glVertex2f(110.0, 50.0);
    glVertex2f(140.0, 50.0);
    glVertex2f(125.0, 110.0);
    glVertex2f(125.0, 110.0);

    glEnd();

    // Draw the four fans
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(125.0, 110.0, 0.0);
        glRotatef(i * 90.0 + fanRotation, 0.0, 0.0, 1.0);
        drawWind();
        glPopMatrix();
    }
}


void Timer(int value)
{
    // Update fan rotation
    fanRotation += fanRotationSpeed;
    if (fanRotation > 360.0) {
        fanRotation -= 360.0;
    }

    // Update plane position (if not crashed)
    if (!planeCrashed) {
        // Translate the plane horizontally and vertically
        planeX -= planeSpeed;
        planeY -= 0.8;

        // Check if the plane has crashed
        if (planeY <= 50.0) {
            planeY = 50.0;       // Set the plane's position on the ground
            planeSpeed = 0.0;   // Stop the plane from moving further
            planeCrashed = true;
        }
    }

    // Redraw the scene
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 1);
}

void drawplane()
{
    glBegin(GL_TRIANGLES);

    if (!planeCrashed) {
        glColor3f(1.0, 1.0, 1.0); // Plane color
    }
    else {
        glColor3f(0.0, 0.0, 0.0); // Black color for crashed plane
    }

    glVertex2f(planeX, planeY);
    glVertex2f(planeX, planeY + 10.0);
    glVertex2f(planeX - 30.0, planeY);

    if (!planeCrashed) {
        glColor3f(0.2, 0.2, 0.2); // Tail color
    }
    else {
        glColor3f(0.0, 0.0, 0.0); // Black color for crashed plane
    }

    glVertex2f(planeX - 1.0, planeY - 2.0);
    glVertex2f(planeX - 1.0, planeY + 5.0);
    glVertex2f(planeX - 17.0, planeY + 5.0);

    glEnd();
}

void init()
{
    glClearColor(0.8f, 0.8f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(600, 600);
    glutCreateWindow("BSCS 514 Lab #8");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(30, Timer, 1);
    glutMainLoop();
    return 0;
}
