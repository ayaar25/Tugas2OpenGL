#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: //Escape Key.
		exit(0);
		break;
	}
	printf("x: %d, y: %d and key(int): %d | \n", x, y, (int)key);
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE); //automaticly normalize normals.
	glShadeModel(GL_SMOOTH); //enable smooth shading.
}

void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float skyRed = 0.73f;
float skyGreen = 0.87f;
float skyBlue = 1.0f;

void init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(skyRed, skyGreen, skyBlue, 0);  // (In fact, this is the default.)

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -8.0f);
}

void DrawCircle(float red, float green, float blue, float startangle, float finishangle, float r, float x1, float y1, float angl)
{
	float x2, y2;
	float angle;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(red, green, blue);
	glVertex2f(x1, y1);

	for (angle = startangle;angle<finishangle;angle += angl)
	{
		x2 = x1 + sin(angle)*r;
		y2 = y1 + cos(angle)*r;
		glVertex2f(x2, y2);
	}

	glEnd();
}

GLfloat _angle = 45.0f;

void car() {

	/**** ban mobil ****/

	glPushMatrix();
	glTranslatef(-1.6f, -1.6f, 0.0f);
	glRotatef(_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(1.6, 1.6f, 0.0f);
	glPushMatrix();
	DrawCircle(0.752941f, 0.752941f, 0.752941f, 1.0f, 360.1f, 0.4f, -1.6f, -1.6f, 2.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	DrawCircle(0.0f, 0.0f, 0.0f, 1.0f, 360.1f, 0.6f, -1.6f, -1.6f, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.6f, -1.6f, 0.0f);
	glRotatef(_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-1.6f, 1.6f, 0.0f);
	glPushMatrix();
	DrawCircle(0.752941f, 0.752941f, 0.752941f, 1.0f, 360.1f, 0.4f, 1.6f, -1.6f, 2.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	DrawCircle(0.0f, 0.0f, 0.0f, 1.0f, 360.1f, 0.6, 1.6f, -1.6f, 0.2f);
	glPopMatrix();

	/**** body mobil ****/

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	DrawCircle(0.0f, 1.0f, 1.0f, -1.58f, 0.64f, 1.2f, -1.6f, -1.6f, 0.2f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	DrawCircle(0.0f, 1.0f, 1.0f, 0.0f, 1.61f, 1.2f, 1.6f, -1.6f, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	DrawCircle(0.0f, 1.0f, 1.0f, -1.6f, 1.8f, 1.6f, 0.0f, -0.9f, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-1.6f, -1.6f);
	glVertex2f(-1.6f, -0.4f);
	glVertex2f(1.6f, -0.4f);
	glVertex2f(1.6f, -1.6f);
	glEnd();
	glPopMatrix();

}

float _translationDistance = 0.0f;
float cityBlue = 0.95f;

void road() {

	/**** ROAD ****/

	float leftest = -4.0f;
	float uppest = -2.5;
	float patternWidth = 0.3f;
	float patternHeight = 0.1f;
	float space = 1.0f;

	glPushMatrix();
	glTranslatef(_translationDistance, 0.0f, 0.0f);
	while (leftest < 16.0f) {
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(leftest, uppest);
		glVertex2f(leftest + patternWidth, uppest);
		glVertex2f(leftest + patternWidth, uppest - patternHeight);
		glVertex2f(leftest, uppest - patternHeight);
		glEnd();
		leftest = leftest + space;
	}
	glPopMatrix();

	glTranslatef(0.0f, 0.0f, 0.0f);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(-4.0f, -4.0f);
	glVertex2f(4.0f, -4.0f);
	glVertex2f(4.0f, -2.0f);
	glVertex2f(-4.0f, -2.0f);
	glEnd();
	glPopMatrix();

}

void city() {

	/**** CITY ****/
	glPushMatrix();
	glTranslatef(_translationDistance, 0.0f, 0.0f);
	float jarak = 0.0;
	for (int i = 0; i <= 1; i++) {
		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(-4.0f + jarak, -2.0f);
		glVertex2f(-4.0f + jarak, 0.4f);
		glVertex2f(-3.2f + jarak, 0.4f);
		glVertex2f(-3.2f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(-3.2f + jarak, -2.0f);
		glVertex2f(-3.2f + jarak, 0.0f);
		glVertex2f(-2.4f + jarak, 0.0f);
		glVertex2f(-2.4f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(-2.4f + jarak, -2.0f);
		glVertex2f(-2.4f + jarak, 2.4f);
		glVertex2f(-1.6f + jarak, 3.2f);
		glVertex2f(-1.6f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(-1.6f + jarak, -2.0f);
		glVertex2f(-1.6f + jarak, 0.8f);
		glVertex2f(-0.8f + jarak, 0.8f);
		glVertex2f(-0.8f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(-0.8f + jarak, -2.0f);
		glVertex2f(-0.8f + jarak, 2.0f);
		glVertex2f(-0.0f + jarak, 1.6f);
		glVertex2f(-0.0f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(-0.8f + jarak, -2.0f);
		glVertex2f(-0.8f + jarak, 1.2);
		glVertex2f(-0.0f + jarak, 1.2f);
		glVertex2f(-0.0f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(-0.0f + jarak, -2.0f);
		glVertex2f(-0.0f + jarak, 0.8f);
		glVertex2f(1.0f + jarak, 0.8f);
		glVertex2f(1.0f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(1.0f + jarak, -2.0f);
		glVertex2f(1.0f + jarak, 2.4f);
		glVertex2f(1.6f + jarak, 2.4f);
		glVertex2f(1.6f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(1.6f + jarak, -2.0f);
		glVertex2f(1.6f + jarak, 0.0f);
		glVertex2f(2.4f + jarak, 0.0f);
		glVertex2f(2.4f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(2.4f + jarak, -2.0f);
		glVertex2f(2.4f + jarak, 1.6f);
		glVertex2f(3.2f + jarak, 2.4f);
		glVertex2f(3.2f + jarak, -2.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.95, 0.95, cityBlue);
		glVertex2f(3.2f + jarak, -2.0f);
		glVertex2f(3.2f + jarak, 3.2f);
		glVertex2f(4.0f + jarak, 3.2f);
		glVertex2f(4.0f + jarak, -2.0f);
		glEnd();
		jarak += 8.0f;
	}
	glPopMatrix();

}

void display() {
	init();
	car();
	road();
	city();
	glutSwapBuffers();
}

bool isDay = true;

void update(int value)
{
	_translationDistance -= 0.05f;
	if (_translationDistance < -8.0f) {
		_translationDistance = 0.0f;
	}
	_angle -= 1.0f;
	if (_angle < 360) {
		_angle += 360;
	}
	if (isDay) {
		skyRed -= 0.0073;
		skyGreen -= 0.0087;
		skyBlue -= 0.01;
		cityBlue -= 0.0095;
		if (skyBlue <= 0) {
			isDay = false;
		}
	}
	else {
		skyRed += 0.0073;
		skyGreen += 0.0087;
		skyBlue += 0.01;
		cityBlue += 0.0095;
		if (skyBlue >= 1.0) {
			isDay = true;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 700);

	//create the window
	glutCreateWindow("Asoy Geboy");
	initRendering();

	//Set handler functions
	//glutDisplayFunc(drawScene);
	glutDisplayFunc(display);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(5, update, 0); //add a timer

	glutMainLoop();
	return 0;
}