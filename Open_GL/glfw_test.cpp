#include "glfw_test.h"


void framebuffer_size_callback(GLFWwindow* window, GLsizei width, GLsizei height)
{
	cout << "window resize event: " << width <<"x" << height << endl;
	glViewport(0, 0, width, height);
}


void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		cout << "Escape pressed" << endl;
		glfwSetWindowShouldClose(window, true);
	}
}


int glfw_window(int argc, char** argv) {
	
	if (glfwInit())
		cout << "Initialized correctly" << endl;
	else
	{
		cout << "Initialization faile" << endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	/*Telling GLFW explicitly that we want to use 
	the core-profile means we'll get access to a smaller 
	subset of OpenGL features (without backwards-compatible
	features we no longer need)*/
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	
	GLsizei win_width{ 1000 }, win_height{ 700 };
	GLFWwindow* window = glfwCreateWindow(win_width, win_height, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//GLAD Initialization
	/*We pass GLAD the function to load the adress of 
	the OpenGL function pointers which is OS-specific.*/
	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "GLAD Initialized" << endl;
	}
	else {
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	/*Setting to OpenGL the size of the rendering window
	Behind the scenes OpenGL uses the data specified via glViewport
	to transform the 2D coordinates it processed to coordinates on 
	your screen. For example, a processed point of location (-0.5,0.5)
	would (as its final transformation) be mapped to (200,450) in screen
	coordinates. Note that processed coordinates in OpenGL are between -1 and 1 
	
	However, the moment a user resizes the window the viewport should be adjusted as well
	*/
	glViewport(0, 0, win_width, win_height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//state setting func


	//RENDER LOOP
	while (!glfwWindowShouldClose(window)) {
		//input
		processInput(window);

		//rendering
		//...
		/*
		some other options GL_COLOR_BUFFER_BIT, 
		GL_DEPTH_BUFFER_BIT and GL_STENCIL_BUFFER_BIT. 
		*/
		glClear(GL_COLOR_BUFFER_BIT);//state using func


		glfwSwapBuffers(window);
		/*Cause callbacks associated with events to be called*/
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}