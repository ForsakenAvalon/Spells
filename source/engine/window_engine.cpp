#include "engine/window_engine.h"

namespace Engine
{
	Window::Window(unsigned int height, unsigned int width)
	{
		objWindow.Create(sf::VideoMode(height, width), "Unnamed", sf::Style::Close);
		isInit = true;
		isRunning = false;
	}

	Window::~Window()
	{
		// Close window if still running
		if (isRunning || isInit) {
			objWindow.Close();
		}
		if (hasMain) {
			this->ptrMain = 0;
		}
	}

	void Window::Run()
	{
		if (!isRunning && hasMain) {
			isRunning = true;
			this->Loop();
		}
	}

	void Window::Run(void (*main)(Window & windowMain))
	{
		if (!isRunning) {
			isRunning = true;
			hasMain = true;
			this->ptrMain = main;
			this->Loop();
		}	
	}

	void Window::Clear()
	{
		objWindow.Clear();
	}

	void Window::Display()
	{
		objWindow.Display();
	}

	void Window::Draw()
	{
	}

	// Executes the main loop of the program. You cannot call Loop directly, use Run instead.
	void Window::Loop()
	{
		while (isRunning) 
		{
			// Handle Standard Window Events

			// Call main loop function for this window
			this->ptrMain(*(this));
		}
	}

	void Window::Exit()
	{
		if (isRunning) {
			isRunning = false;
			objWindow.Close();
		}
	}


}