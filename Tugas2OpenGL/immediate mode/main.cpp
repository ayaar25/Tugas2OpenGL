#include <OpenGL/gl.h>
#include <math.h>
#include <GLUT/glut.h>   // freeglut.h might be a better alternative, if available.

void DrawCircle(float red, float green, float blue, float startangle, float finishangle, float r, float x1, float y1)
{
    float x2,y2;
    float angle;
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue);
    glVertex2f(x1,y1);
    
    for (angle=startangle;angle<finishangle;angle+=0.2)
    {
        x2 = x1+sin(angle)*r;
        y2 = y1+cos(angle)*r;
        glVertex2f(x2,y2);
    }
    
    glEnd();
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    
	glClearColor(0.73, 0.87, 0.98, 1);  // (In fact, this is the default.)
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, -0.6f);
	glVertex2f(-1.0f, -0.6f);
	glEnd();

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

	DrawCircle(0.0f, 1.0f, 1.0f, -1.58f, 0.16f, 0.3f, -0.4f, -0.6f);

	DrawCircle(0.0f, 1.0f, 1.0f, 0.0f, 1.61f, 0.3f, 0.4f, -0.6f);

	DrawCircle(0.0f, 1.0f, 1.0f, -1.58f, 1.8f, 0.4f, 0.0f, -0.3f);

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.4f, -0.6f);
	glVertex2f(-0.4f, -0.3f);
	glVertex2f(0.4f, -0.3f);
	glVertex2f(0.4f, -0.6f);

	float leftest = -0.9;
	float uppest = -0.8;
	float patternWidth = 0.3;
	float patternHeight = 0.1;

	while (leftest < 1) {
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
		leftest = leftest + 0.4;
	}


	glEnd();

	DrawCircle(0.0f, 0.0f, 0.0f, 1.0f, 360.1f, 0.15f, -0.4f, -0.6f);

	DrawCircle(0.0f, 0.0f, 0.0f, 1.0f, 360.1f, 0.15f, 0.4f, -0.6f);

	glutSwapBuffers(); // Required to copy color buffer onto the screen.

}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(800, 800);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Tugas 2 OpenGL");  // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}
