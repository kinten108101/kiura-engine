
/*

Basic workflow: 
Create binaries/libraries that stores the code
An executable will run the functions from the libaries

On Windows there are DLLs
On Linux, there are SOs, or so I think.
On Mac, there's none. Mac is shit.

*/

#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0,width,height);
}

void processInput(GLFWwindow * window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window,true);
}

int main()
{
	
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	// Create window object
	GLFWwindow* window = glfwCreateWindow(800,600, "This is a window", NULL, NULL);
	if (window == NULL)
	{
		printf("Failed to create GLFW window.\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	printf("Failed to initialize GLAD\n");
    	return -1;
	}    
	
	glViewport(0,0,800,600);
	glfwSetFramebufferSizeCallback(window, &framebuffer_size_callback);
	// Passing function as an argument, so technically we're working with its pointer.
	// In their example, there was no ampersand. Still both versions worked, ampersand or not.

	// render loop


	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f,0.9f,0.9f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
		processInput(window);
	}
	glfwTerminate();
	printf("Hello world!");
	return 0;
	// ABOUT: init glfw -> glad
	// for more details, read up on GLAD
	// TODO: GLAD, GCC
	
}

