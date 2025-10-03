#pragma once
#include <iostream>
#include <glew.h>
#include <glfw3.h>

class Window {
	public:
		Window(int width, int height);
		~Window();
		void resize();
		void input();
		void mainLoop();
		void resize(int width, int height);
	private:
		int m_width;
		int m_height;
		GLFWwindow* ptr_window;
};