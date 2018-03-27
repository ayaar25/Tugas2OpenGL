#include <windows.h>
#include <iostream>
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

	// Dark blue background
	glClearColor(0.73, 0.87, 0.98, 0);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLfloat background_buffer[] = {
		1, 1,
		0.89, 0.95, 0.99,
		1, -1,
		0.89, 0.95, 0.99,
		-1, 1,
		0.89, 0.95, 0.99,
		-1, 1,
		0.89, 0.95, 0.99,
		1, -1,
		0.89, 0.95, 0.99,
		-1, -1,
		0.89, 0.95, 0.99, 
	};

	GLfloat building_buffer[] = {
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

		//Base building
		-1, 0.25,
		0.46, 0.46, 0.46,
		1, 0.25,
		0.46, 0.46, 0.46,
		1, -1,
		0.46, 0.46, 0.46,
		1, -1,
		0.46, 0.46, 0.46,
		-1, 0.25,
		0.46, 0.46, 0.46,
		-1, -1,
		0.46, 0.46, 0.46,
	};

	std::cout << "Length of Building Array = " << (sizeof(building_buffer)/sizeof(*building_buffer)) << std::endl;

	GLfloat road_buffer[] = {
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

		//Road Line
		1, -0.65,
		1, 1, 1,
		0.85, -0.65,
		1, 1, 1,
		1, -0.7,
		1, 1, 1,
		1, -0.7,
		1, 1, 1,
		0.85, -0.7,
		1, 1, 1,
		0.85, -0.65,
		1, 1, 1,

		//Road Line
		0.7, -0.65,
		1, 1, 1,
		0.55, -0.65,
		1, 1, 1,
		0.7, -0.7,
		1, 1, 1,
		0.7, -0.7,
		1, 1, 1,
		0.55, -0.7,
		1, 1, 1,
		0.55, -0.65,
		1, 1, 1,

		//Road Line
		0.4, -0.65,
		1, 1, 1,
		0.25, -0.65,
		1, 1, 1,
		0.4, -0.7,
		1, 1, 1,
		0.4, -0.7,
		1, 1, 1,
		0.25, -0.7,
		1, 1, 1,
		0.25, -0.65,
		1, 1, 1,

		//Road Line
		0.1, -0.65,
		1, 1, 1,
		-0.05, -0.65,
		1, 1, 1,
		0.1, -0.7,
		1, 1, 1,
		0.1, -0.7,
		1, 1, 1,
		-0.05, -0.7,
		1, 1, 1,
		-0.05, -0.65,
		1, 1, 1,

		//Road Line
		-0.2, -0.65,
		1, 1, 1,
		-0.35, -0.65,
		1, 1, 1,
		-0.2, -0.7,
		1, 1, 1,
		-0.2, -0.7,
		1, 1, 1,
		-0.35, -0.7,
		1, 1, 1,
		-0.35, -0.65,
		1, 1, 1,

		//Road Line
		-0.5, -0.65,
		1, 1, 1,
		-0.65, -0.65,
		1, 1, 1,
		-0.5, -0.7,
		1, 1, 1,
		-0.5, -0.7,
		1, 1, 1,
		-0.65, -0.7,
		1, 1, 1,
		-0.65, -0.65,
		1, 1, 1,

		//Road Line
		-0.8, -0.65,
		1, 1, 1,
		-0.95, -0.65,
		1, 1, 1,
		-0.8, -0.7,
		1, 1, 1,
		-0.8, -0.7,
		1, 1, 1,
		-0.95, -0.7,
		1, 1, 1,
		-0.95, -0.65,
		1, 1, 1,

		//Road Line
		-1.1, -0.65,
		1, 1, 1,
		-1.25, -0.65,
		1, 1, 1,
		-1.1, -0.7,
		1, 1, 1,
		-1.1, -0.7,
		1, 1, 1,
		-1.25, -0.7,
		1, 1, 1,
		-1.25, -0.65,
		1, 1, 1,
	};

	std::cout << "Length of Road Array = " << (sizeof(road_buffer) / sizeof(*road_buffer)) << std::endl;

	GLfloat car_buffer[] = {
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
		0.9, 0.45, 0.45,
		0.15, -0.3,
		0.9, 0.45, 0.45,
		0.3, -0.6,
		0.9, 0.45, 0.45,
		0.3, -0.6,
		0.9, 0.45, 0.45,
		0.15, -0.6,
		0.9, 0.45, 0.45,
		0.15, -0.3,
		0.9, 0.45, 0.45,

		//Car - wheel back
		-0.3, -0.3,
		0.9, 0.45, 0.45,
		-0.15, -0.3,
		0.9, 0.45, 0.45,
		-0.3, -0.6,
		0.9, 0.45, 0.45,
		-0.3, -0.6,
		0.9, 0.45, 0.45,
		-0.15, -0.6,
		0.9, 0.45, 0.45,
		-0.15, -0.3,
		0.9, 0.45, 0.45,
	};

	std::cout << "Length of Car Array = " << (sizeof(car_buffer) / sizeof(*car_buffer)) << std::endl;

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	GLfloat delta = 0.01;
	int rise = 0;
	int timeCounter = 0;

	do{
		Sleep(0.5);

		if(timeCounter == 1500){
			rise = (rise == 1)?0:1;
			timeCounter = 0;
		}

		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT );
		// Run shader
		glUseProgram(programID);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*5, (void*)0);
		// 2nd attribute buffer : color
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float)*2));
		//  1: layout in the shader, declared in glEnableVertexAttribArray.
		//  2: size, 3: type, 4: normalized?, 5: stride, 6:  array buffer offset

		if (rise == 1) {
			background_buffer[2] += delta*0.1; background_buffer[3] += delta*0.1; background_buffer[4] += delta*0.1;
			background_buffer[12] += delta*0.1; background_buffer[13] += delta*0.1; background_buffer[14] += delta*0.1;
			background_buffer[17] += delta*0.1; background_buffer[18] += delta*0.1; background_buffer[19] += delta*0.1;
		}
		else {
			background_buffer[2] -= delta*0.1; background_buffer[3] -= delta*0.1; background_buffer[4] -= delta*0.1;
			background_buffer[12] -= delta*0.1; background_buffer[13] -= delta*0.1; background_buffer[14] -= delta*0.1;
			background_buffer[17] -= delta*0.1; background_buffer[18] -= delta*0.1; background_buffer[19] -= delta*0.1;
		}

		// Change Buffer to background
		glBufferData(GL_ARRAY_BUFFER, sizeof(background_buffer), background_buffer, GL_STATIC_DRAW);

		// Draw background
		glDrawArrays(GL_TRIANGLES, 0, 1 * 6); // Start from vertex 0, (number square * num vertx in square)

		int i = 0;
		int count = 0;
		//stop until 297
		while (i < 300) {
			if (count % 3 == 0 && building_buffer[i] <= -1 && building_buffer[i + 5] <= -1 && building_buffer[i + 10] <= -1) {
				building_buffer[i] += 2.25;
				building_buffer[i+5] += 2.25;
				building_buffer[i+10] += 2.25;
			}
			building_buffer[i] -= delta;
			i += 5;
			count++;
		}

		// Change Buffer to Buildings
		glBufferData(GL_ARRAY_BUFFER, sizeof(building_buffer), building_buffer, GL_STATIC_DRAW);

		// Draw buildings
		glDrawArrays(GL_TRIANGLES, 0, 11*6); // Start from vertex 0, (number square * num vertx in square)

		i = 30;
		count = 0;
		//stop until 267
		while (i < 270) {
			if (count % 3 == 0 && road_buffer[i] <= -1 && road_buffer[i + 5] <= -1 && road_buffer[i + 10] <= -1) {
				road_buffer[i] += 2.15;
				road_buffer[i + 5] += 2.15;
				road_buffer[i + 10] += 2.15;
			}
			road_buffer[i] -= delta;
			i += 5;
			count++;
		}
											 
		// Change Buffer to Road
		glBufferData(GL_ARRAY_BUFFER, sizeof(road_buffer), road_buffer, GL_STATIC_DRAW);

		// Draw road
		glDrawArrays(GL_TRIANGLES, 0, 8 * 6); // Start from vertex 0, (number square * num vertx in square)

		// Change buffer to car
		glBufferData(GL_ARRAY_BUFFER, sizeof(car_buffer), car_buffer, GL_STATIC_DRAW);

		// Draw Car
		glDrawArrays(GL_TRIANGLES, 0, 4*6);
		// glUseProgramObjectARB(0); // Disable Shader, just in case needed
		
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

		timeCounter++;

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);

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