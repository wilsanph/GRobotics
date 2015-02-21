#include <glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "Application.hpp"
#include "BaseRobot.hpp"

static void error_callback( int error, const char* description );
static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods );
void init();

double time_now = 0;
double time_before = 0;
double dt = 0;

Application app( 10 );

int main( void )
{
	Application::instance = reinterpret_cast<Application*>(&app);
	GLFWwindow* window;
	glfwSetErrorCallback( error_callback );
	if ( !glfwInit() )
	{
		exit( EXIT_FAILURE );
	}

	window = glfwCreateWindow( Application::instance->width() * 25,
							   Application::instance->height() * 25,
							   "Simple example",
							   NULL,
							   NULL );
	if ( !window )
	{
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
	glfwMakeContextCurrent( window );
	glfwSetKeyCallback( window, key_callback );

	init();

	while ( !glfwWindowShouldClose( window ) )
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize( window, &width, &height );
		ratio = width / (float)height;
		glViewport( 0, 0, width, height );
		//glViewport( 0, 0, 500, 500 );
		glClear( GL_COLOR_BUFFER_BIT );


		time_now = glfwGetTime();
		dt = time_now - time_before;
		time_before = time_now;

		//std::cout << "dt: " << dt << "\n\r";
		std::cout << "ratio: " << ratio << ", width: " << width << ", height: " << height << "\n\r";

		app.update( dt );
		app.render();

		glfwSwapBuffers( window );
		glfwPollEvents();
	}
	glfwDestroyWindow( window );
	glfwTerminate();
	exit( EXIT_SUCCESS );
}

static void error_callback( int error, const char* description )
{
	fputs( description, stderr );
}

static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
		glfwSetWindowShouldClose( window, GL_TRUE );
}

void init()
{
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
	app.init();
}