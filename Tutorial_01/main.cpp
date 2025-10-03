#include <iostream>
#include "Window.h"
int main() {
	Window* window = new Window(800, 600);
	window->mainLoop();
	delete window;
	return 0;
}