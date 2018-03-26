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
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    // Define shapes enclosed within a pair of glBegin and glEnd
//    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
//    glColor3f(1.0f, 0.0f, 0.0f); // Red
//    glVertex2f(-0.8f, 0.1f);     // Define vertices in counter-clockwise (CCW) order
//    glVertex2f(-0.2f, 0.1f);     //  so that the normal (front-face) is facing you
//    glVertex2f(-0.2f, 0.7f);
//    glVertex2f(-0.8f, 0.7f);
//    
//    glColor3f(0.0f, 1.0f, 0.0f); // Green
//    glVertex2f(-0.7f, -0.6f);
//    glVertex2f(-0.1f, -0.6f);
//    glVertex2f(-0.1f,  0.0f);
//    glVertex2f(-0.7f,  0.0f);
//    
//    glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
//    glVertex2f(-0.9f, -0.7f);
//    glColor3f(1.0f, 1.0f, 1.0f); // White
//    glVertex2f(-0.5f, -0.7f);
//    glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
//    glVertex2f(-0.5f, -0.3f);
//    glColor3f(1.0f, 1.0f, 1.0f); // White
//    glVertex2f(-0.9f, -0.3f);
//    glEnd();
//    
//    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
//    glColor3f(0.0f, 0.0f, 1.0f); // Blue
//    glVertex2f(0.1f, -0.6f);
//    glVertex2f(0.7f, -0.6f);
//    glVertex2f(0.4f, -0.1f);
//    
//    glColor3f(1.0f, 0.0f, 0.0f); // Red
//    glVertex2f(0.3f, -0.4f);
//    glColor3f(0.0f, 1.0f, 0.0f); // Green
//    glVertex2f(0.9f, -0.4f);
//    glColor3f(0.0f, 0.0f, 1.0f); // Blue
//    glVertex2f(0.6f, -0.9f);
//    glEnd();
//    
//    glBegin(GL_POLYGON);            // These vertices form a closed polygon
//    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//    glVertex2f(0.4f, 0.2f);
//    glVertex2f(0.6f, 0.2f);
//    glVertex2f(0.7f, 0.4f);
//    glVertex2f(0.6f, 0.6f);
//    glVertex2f(0.4f, 0.6f);
//    glVertex2f(0.3f, 0.4f);
//    glEnd();
    
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
    
    DrawCircle(0.0f,1.0f,1.0f,-1.58f,0.16f,0.3f,-0.4f,-0.6f);
    
    DrawCircle(0.0f,1.0f,1.0f,0.0f,1.61f,0.3f,0.4f,-0.6f);
    
    DrawCircle(0.0f,1.0f,1.0f,-1.58f,1.8f,0.4f,0.0f,-0.3f);
    
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-0.4f, -0.6f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, -0.6f);
    glEnd();
    
    DrawCircle(0.0f,0.0f,0.0f,1.0f,360.1f,0.15f,-0.4f,-0.6f);
    
    DrawCircle(0.0f,0.0f,0.0f,1.0f,360.1f,0.15f,0.4f,-0.6f);
    
    
    
    glFlush();  // Render now
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
