#include <gl/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

int screenwidth = 640;
int screenheight = 440;

class canvas {
public:
	float x, y;
	float angle;
	canvas() {
		this->x = 225;
		this->y = 200;
	}
	void turnto(float angle) {
		this->angle = angle;
	}
	void turn(float angle) {
		this->angle += angle;
	}
	void lineto(float x, float y) {
		float t_x = x; float t_y = y;
		glcolor3f(1.0, 0.0, 0.0);
		gllinewidth(2.0);
		glbegin(gl_lines);
		glvertex2f(this->x, this->y);
		glvertex2f(x, y);
		glend();
		glflush();
		moveto(t_x, t_y);
	}
	void moveto(float x, float y) {
		this->x = x;
		this->y = y;

	}


	void forward(float dist, int isvisible) {
		const float radperdeg = 0.017453393;
		float x = this->x + dist * cos(radperdeg * this->angle);
		float y = this->y + dist * sin(radperdeg * this->angle);
		if (isvisible >= 1) {
			lineto(x, y);

		}
		else {
			moveto(x, y);
		}
	}

};

float l = 50.0;
canvas cvs;

void display() {
	glclear(gl_color_buffer_bit);
	// 3.5.2 (example motif)
	//for part(a) set i < 1, for part(b) set i < 4
	for (int i = 0; i < 4; i++) {
		cvs.forward(3 * l, 1);
		cvs.turn(90);
		cvs.forward(l, 1);
		cvs.turn(90);
		cvs.forward(l, 1);
		cvs.turn(90);
	}
}

int main(int argc, char** argv) {
	glutinit(&argc, argv);
	glutinitdisplaymode(glut_single | glut_rgb);
	glutinitwindowsize(screenwidth, screenheight);
	glutinitwindowposition(100, 100);
	glutcreatewindow("exmaple 3.5.2");

	glmatrixmode(gl_projection);
	glloadidentity();
	gluortho2d(0.0, screenwidth, 0.0, screenheight);
	glmatrixmode(gl_modelview);

	glutdisplayfunc(display);

	glutmainloop();
	return 0;
}