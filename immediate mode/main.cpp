#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>   // freeglut.h might be a better alternative, if available.
#include <math.h>

void DrawCircle(float red, float green, float blue, float startangle, float finishangle, float r, float x1, float y1)
{
	float x2, y2;
	float angle;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(red, green, blue);
	glVertex2f(x1, y1);

	for (angle = startangle;angle<finishangle;angle += 0.2)
	{
		x2 = x1 + sin(angle)*r;
		y2 = y1 + cos(angle)*r;
		glVertex2f(x2, y2);
	}

	glEnd();
}

void sky() {  // Display function will draw the image.

	glClearColor(0.73, 0.87, 0.98, 1);  // (In fact, this is the default.)
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers(); // Required to copy color buffer onto the screen.

}

void city() {

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(-1.0f, -0.6f);
	glVertex2f(-1.0f, 0.4f);
	glVertex2f(-0.8f, 0.4f);
	glVertex2f(-0.8f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(-0.8f, -0.6f);
	glVertex2f(-0.8f, 0.3f);
	glVertex2f(-0.7f, 0.3f);
	glVertex2f(-0.7f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(-0.7f, -0.6f);
	glVertex2f(-0.7f, 0.6f);
	glVertex2f(-0.5f, 0.8f);
	glVertex2f(-0.5f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(-0.5f, -0.6f);
	glVertex2f(-0.5f, 0.2f);
	glVertex2f(-0.4f, 0.2f);
	glVertex2f(-0.4f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(-0.4f, -0.6f);
	glVertex2f(-0.4f, 0.6f);
	glVertex2f(-0.2f, 0.6f);
	glVertex2f(-0.2f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(-0.2f, -0.6f);
	glVertex2f(-0.2f, 0.8f);
	glVertex2f(0.0f, 0.6f);
	glVertex2f(0.0f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(0.0f, -0.6f);
	glVertex2f(0.0f, 0.4f);
	glVertex2f(0.2f, 0.4f);
	glVertex2f(0.2f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(0.2f, -0.6f);
	glVertex2f(0.2f, 0.8f);
	glVertex2f(0.5f, 0.8f);
	glVertex2f(0.5f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(0.5f, -0.6f);
	glVertex2f(0.5f, 0.7f);
	glVertex2f(0.6f, 0.7f);
	glVertex2f(0.6f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(0.6f, -0.6f);
	glVertex2f(0.6f, 0.9f);
	glVertex2f(0.8f, 0.8f);
	glVertex2f(0.8f, -0.6f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.95);
	glVertex2f(0.8f, -0.6f);
	glVertex2f(0.8f, 0.6f);
	glVertex2f(1.0f, 0.6f);
	glVertex2f(1.0f, -0.6f);
	glEnd();

	glutSwapBuffers(); // Required to copy color buffer onto the screen.

}


void road() {

	glClearColor(0.73, 0.87, 0.98, 0);  // (In fact, this is the default.)

	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, -0.6f);
	glVertex2f(-1.0f, -0.6f);
	glEnd();

	float leftest = -0.9;
	float uppest = -0.8;
	float patternWidth = 0.3;
	float patternHeight = 0.1;

	while (leftest < 1) {
		glBegin(GL_QUADS);
		if ((leftest + 0.1) < 1) {
			glColor3f(1, 1, 1);
			glVertex2f(leftest, uppest);
			glVertex2f(leftest + patternWidth, uppest);
			glVertex2f(leftest + patternWidth, uppest - patternHeight);
			glVertex2f(leftest, uppest - patternHeight);
		}
		else {
			glColor3f(1, 1, 1);
			glVertex2f(leftest, uppest);
			glVertex2f(1, uppest);
			glVertex2f(1, uppest - patternHeight);
			glVertex2f(leftest, uppest - patternHeight);
		}
		glEnd();
		leftest = leftest + 0.4;
	}

	glutSwapBuffers(); // Required to copy color buffer onto the screen.

}

void car() {

	glClearColor(0.73, 0.87, 0.98, 0);  // (In fact, this is the default.)

	DrawCircle(0.0f, 1.0f, 1.0f, -1.58f, 0.16f, 0.3f, -0.4f, -0.6f);
	DrawCircle(0.0f, 1.0f, 1.0f, 0.0f, 1.61f, 0.3f, 0.4f, -0.6f);
	DrawCircle(0.0f, 1.0f, 1.0f, -1.58f, 1.8f, 0.4f, 0.0f, -0.3f);

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.4f, -0.6f);
	glVertex2f(-0.4f, -0.3f);
	glVertex2f(0.4f, -0.3f);
	glVertex2f(0.4f, -0.6f);

	glEnd();

	DrawCircle(0.0f, 0.0f, 0.0f, 1.0f, 360.1f, 0.15f, -0.4f, -0.6f);
	DrawCircle(0.0f, 0.0f, 0.0f, 1.0f, 360.1f, 0.15f, 0.4f, -0.6f);

	glutSwapBuffers(); // Required to copy color buffer onto the screen.

}

void display() {

	sky();
	road();
	city();
	car();

}

int main(int argc, char** argv) {  // Initialize GLUT and 

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);    // Use single color buffer and no depth buffer.
	glutInitWindowSize(600, 600);         // Size of display area, in pixels.
	glutInitWindowPosition(100, 100);     // Location of window in screen coordinates.
	glutCreateWindow("GL Asoy Geboy"); // Parameter is window title.
	glutDisplayFunc(display);            // Called when the window needs to be redrawn.

	glutMainLoop(); // Run the event loop!  This function does not return.
					// Program ends when user closes the window.
	return 0;

}