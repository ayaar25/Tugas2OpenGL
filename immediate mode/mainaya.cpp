#include <OpenGL/gl.h>
#include <math.h>
#include <GLUT/glut.h>   // freeglut.h might be a better alternative, if available.

GLfloat angle = 45.0f;
int refreshmill = 1;

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(refreshmill, timer, 0);
    
}

void DrawCircle(float red, float green, float blue, float startangle, float finishangle, float r, float x1, float y1, float angl)
{
    float x2,y2;
    float angle;
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue);
    glVertex2f(x1,y1);
    
    for (angle=startangle;angle<finishangle;angle+=angl)
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

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width/GLfloat(height);
    glViewport(0, 0, width, height);
    if (width>=height) {
        gluOrtho2D(-1.0*aspect,1.0*aspect,-1.0,1.0);
    } else {
        gluOrtho2D(-1.0, 1.0, -1.0/aspect, 1.0/aspect);
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glBegin(GL_QUADS);
    glColor3f(0.329412f, 0.329412f, 0.329412f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(-1.0f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(-0.8f, 0.4f);
    glVertex2f(-0.8f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, -0.6f);
    glVertex2f(-0.8f, 0.3f);
    glVertex2f(-0.7f, 0.3f);
    glVertex2f(-0.7f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.7f, 0.6f);
    glVertex2f(-0.5f, 0.8f);
    glVertex2f(-0.5f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-0.5f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.4f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.4f, -0.6f);
    glVertex2f(-0.4f, 0.6f);
    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.2f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(-0.2f, 0.8f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.0f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, -0.6f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.2f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(0.2f, 0.8f);
    glVertex2f(0.5f, 0.8f);
    glVertex2f(0.5f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.5f, 0.7f);
    glVertex2f(0.6f, 0.7f);
    glVertex2f(0.6f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(0.6f, 0.9f);
    glVertex2f(0.8f, 0.8f);
    glVertex2f(0.8f, -0.6f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.8f, -0.6f);
    glVertex2f(0.8f, 0.6f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(1.0f, -0.6f);
    glEnd();
    
    //body mobil
    
    DrawCircle(0.0f,1.0f,1.0f,-1.58f,0.16f,0.3f,-0.4f,-0.6f, 0.2f);
    
    DrawCircle(0.0f,1.0f,1.0f,0.0f,1.61f,0.3f,0.4f,-0.6f, 0.2f);
    
    DrawCircle(0.0f,1.0f,1.0f,-1.58f,1.8f,0.4f,0.0f,-0.3f, 0.2f);
    
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-0.4f, -0.6f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, -0.6f);
    glEnd();
    
    
    //ban mobil
    
    DrawCircle(0.0f,0.0f,0.0f,1.0f,360.1f,0.15f,-0.4f,-0.6f, 0.2f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.4f, -0.6f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.4f, 0.6f, 0.0f);
    glPushMatrix();
    DrawCircle(0.752941f,0.752941f,0.752941f,1.0f,360.1f,0.1f,-0.4f,-0.6f, 2.0f);
    glPopMatrix();
    
    
    DrawCircle(0.0f,0.0f,0.0f,1.0f,360.1f,0.15f,0.4f,-0.6f, 0.2f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.4f, -0.6f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.4f, 0.6f, 0.0f);
    glPushMatrix();
    DrawCircle(0.752941f,0.752941f,0.752941f,1.0f,360.1f,0.1f,0.4f,-0.6f, 2.0f);
    glPopMatrix();

    
    //glutSwapBuffers();
    glFlush();
    angle-=0.2f;
    
//    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(800, 800);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Tugas 2 OpenGL");  // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}
