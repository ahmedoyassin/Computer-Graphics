#include "Window.h"

Window::Window(int width, int height) : m_width(width), m_height(height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	ptr_window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (ptr_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(ptr_window);
}

Window::~Window()
{
}

void Window::resize()
{
	int width, height;
	glfwGetFramebufferSize(ptr_window, &width, &height);
	if( width != m_width || height != m_height)
	{
		glViewport(0, 0, width, height);
		m_width = width;
		m_height = height;
		std::cout << "Window resized: " << width << "x" << height << std::endl;
	}
}

void Window::input()
{
	if (glfwGetKey(ptr_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(ptr_window, true);
}

void Window::mainLoop()
{
	while (!glfwWindowShouldClose(ptr_window))
	{
		resize();
		input();
		glClearColor(0.5f,0.8f,0.5f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(ptr_window);
		glfwPollEvents();
	}
	glfwTerminate();
}

void Window::resize(int width, int height)
{
}
