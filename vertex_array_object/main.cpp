#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <common/shader.hpp>

using namespace glm;

void initGLFW();

GLFWwindow* window;
GLuint programID;

int main( void )
{
	// Initialise GLFW and Shader
	initGLFW();

	GLuint programID = LoadShaders("VertexShader.vertexshader", "FragmentShader.fragmentshader");
	GLuint programID2 = LoadShaders("VertexShaderTransformation.vertexshader", "FragmentShader.fragmentshader");

	// Dark blue background
	glClearColor(0.73, 0.87, 0.98, 0);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLfloat vertex_and_color_buffer[] = {
		// Right most building
		1, 0.85,
		0.46, 0.46, 0.46,
		1, -1,
		0.46, 0.46, 0.46,
		0.8, 0.65,
		0.46, 0.46, 0.46,
		0.8, 0.65,
		0.46, 0.46, 0.46,
		1, -1,
		0.46, 0.46, 0.46,
		0.8, -1,
		0.46, 0.46, 0.46,

		//2nd building
		0.8, 0.25,
		0.46, 0.46, 0.46,
		0.6, 0.25,
		0.46, 0.46, 0.46,
		0.8, -1,
		0.46, 0.46, 0.46,
		0.8, -1,
		0.46, 0.46, 0.46,
		0.6, -1,
		0.46, 0.46, 0.46,
		0.6, 0.25,
		0.46, 0.46, 0.46,

		//3rd building
		0.6, 0.65,
		0.46, 0.46, 0.46,
		0.4, 0.65,
		0.46, 0.46, 0.46,
		0.6, -1,
		0.46, 0.46, 0.46,
		0.6, -1,
		0.46, 0.46, 0.46,
		0.4, -1,
		0.46, 0.46, 0.46,
		0.4, 0.65,
		0.46, 0.46, 0.46,

		//4th building
		0.4, 0.35,
		0.46, 0.46, 0.46,
		0.2, 0.35,
		0.46, 0.46, 0.46,
		0.4, -1,
		0.46, 0.46, 0.46,
		0.4, -1,
		0.46, 0.46, 0.46,
		0.2, -1,
		0.46, 0.46, 0.46,
		0.2, 0.35,
		0.46, 0.46, 0.46,

		//5th building
		0.2, 0.85,
		0.46, 0.46, 0.46,
		0.2, -1,
		0.46, 0.46, 0.46,
		0, 0.65,
		0.46, 0.46, 0.46,
		0, 0.65,
		0.46, 0.46, 0.46,
		0.2, -1,
		0.46, 0.46, 0.46,
		0, -1,
		0.46, 0.46, 0.46,

		//6th building
		0, 0.55,
		0.46, 0.46, 0.46,
		-0.2, 0.55,
		0.46, 0.46, 0.46,
		0, -1,
		0.46, 0.46, 0.46,
		0, -1,
		0.46, 0.46, 0.46,
		-0.2, -1,
		0.46, 0.46, 0.46,
		-0.2, 0.55,
		0.46, 0.46, 0.46,

		//7th building
		-0.2, 0.25,
		0.46, 0.46, 0.46,
		-0.4, 0.25,
		0.46, 0.46, 0.46,
		-0.2, -1,
		0.46, 0.46, 0.46,
		-0.2, -1,
		0.46, 0.46, 0.46,
		-0.4, -1,
		0.46, 0.46, 0.46,
		-0.4, 0.25,
		0.46, 0.46, 0.46,

		//8th building
		-0.4, 0.85,
		0.46, 0.46, 0.46,
		-0.6, 0.85,
		0.46, 0.46, 0.46,
		-0.4, -1,
		0.46, 0.46, 0.46,
		-0.4, -1,
		0.46, 0.46, 0.46,
		-0.6, -1,
		0.46, 0.46, 0.46,
		-0.6, 0.85,
		0.46, 0.46, 0.46,

		//9th building
		-0.6, 0.35,
		0.46, 0.46, 0.46,
		-0.8, 0.35,
		0.46, 0.46, 0.46,
		-0.6, -1,
		0.46, 0.46, 0.46,
		-0.6, -1,
		0.46, 0.46, 0.46,
		-0.8, -1,
		0.46, 0.46, 0.46,
		-0.8, 0.35,
		0.46, 0.46, 0.46,

		//10th building
		-0.8, 0.25,
		0.46, 0.46, 0.46,
		-1, 0.25,
		0.46, 0.46, 0.46,
		-0.8, -1,
		0.46, 0.46, 0.46,
		-0.8, -1,
		0.46, 0.46, 0.46,
		-1, -1,
		0.46, 0.46, 0.46,
		-1, 0.25,
		0.46, 0.46, 0.46,

		//Road
		1, -0.6,
		0.38, 0.38, 0.38,
		-1, -0.6,
		0.38, 0.38, 0.38,
		1, -1,
		0.38, 0.38, 0.38,
		1, -1,
		0.38, 0.38, 0.38,
		-1, -1,
		0.38, 0.38, 0.38,
		-1, -0.6,
		0.38, 0.38, 0.38,

		//Car - Top
		0.25, 0.2,
		0.94, 0.6, 0.6,
		-0.25, 0.2,
		0.94, 0.6, 0.6,
		0.25, -0.1,
		0.94, 0.6, 0.6,
		0.25, -0.1,
		0.94, 0.6, 0.6,
		-0.25, -0.1,
		0.94, 0.6, 0.6,
		-0.25, 0.2,
		0.94, 0.6, 0.6,

		//Car - Bottom
		0.5, -0.1,
		0.9, 0.45, 0.45,
		-0.5, -0.1,
		0.9, 0.45, 0.45,
		0.5, -0.5,
		0.9, 0.45, 0.45,
		0.5, -0.5,
		0.9, 0.45, 0.45,
		-0.5, -0.5,
		0.9, 0.45, 0.45,
		-0.5, -0.1,
		0.9, 0.45, 0.45,

		//Car - wheel front
		0.3, -0.3,
		0.94, 0.6, 0.6,
		0.15, -0.3,
		0.94, 0.6, 0.6,
		0.3, -0.6,
		0.94, 0.6, 0.6,
		0.3, -0.6,
		0.94, 0.6, 0.6,
		0.15, -0.6,
		0.94, 0.6, 0.6,
		0.15, -0.3,
		0.94, 0.6, 0.6,

		//Car - wheel back
		-0.3, -0.3,
		0.94, 0.6, 0.6,
		-0.15, -0.3,
		0.94, 0.6, 0.6,
		-0.3, -0.6,
		0.94, 0.6, 0.6,
		-0.3, -0.6,
		0.94, 0.6, 0.6,
		-0.15, -0.6,
		0.94, 0.6, 0.6,
		-0.15, -0.3,
		0.94, 0.6, 0.6,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_and_color_buffer), vertex_and_color_buffer, GL_STATIC_DRAW);

	do{

		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT );

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*5, (void*)0);
		//  1: attribute 0. No particular reason for 0, but must match the layout in the shader.
		//  2: size, 3: type, 4: normalized?, 5: stride, 6:  array buffer offset

		// 2nd attribute buffer : color
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float)*2));

		// Draw the buffer
		glUseProgram(programID);
		glDrawArrays(GL_TRIANGLES, 0, 13*6); // Start from vertex 0, (number square * num vertx in square)
		
		glUseProgramObjectARB(0); // Disable Shader
		glDrawArrays(GL_TRIANGLES, 13*6, 6);
		
		for (int i = 0; i < 10; i++) {
			glUseProgram(programID2);
			glDrawArrays(GL_TRIANGLES, 14 * 6, 6);
		}
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);
	glDeleteProgram(programID2);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

void initGLFW() {
	if (!glfwInit())
	{
		fprintf(stderr, "Our Universe\n");
		getchar();
		exit(0);
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1350, 700, "Our Wonderful Universe", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		exit(0);
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		exit(0);
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}