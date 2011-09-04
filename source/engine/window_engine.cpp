#include "engine/window_engine.h"

namespace Engine
{
	Window::Window(unsigned int height /* = 800 */, unsigned int width /* =600 */, const char * title /* = "Unnamed" */)
	{
		objWindow.Create(sf::VideoMode(height, width), title, sf::Style::Close);
		isInit = true;
		isRunning = false;
	}

	Window::~Window()
	{
		// Close window if still running.
		this->Exit();

		//if (hasMain) {
		//	this->ptrMain = 0;
		//}
	}

	void Window::Run()
	{
		if ( !isRunning /* && hasMain */ ) 
		{
			isRunning = true;
			this->Loop();
		}
	}

	/*void Window::Run(void (*main)(Window & windowMain))
	{
		if (!isRunning) {
			isRunning = true;
			hasMain = true;
			this->ptrMain = main;
			this->Loop();
		}	
	}*/

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
		while ( isRunning ) 
		{
			// Handle Standard Window Events
			this->StandardEvents();

			// Call main loop function for this window
			//this->ptrMain(*(this));

			this->Clear();
			this->Draw();
			this->Display();
		}
	}

	// Handle standard window events.
	void Window::StandardEvents()
	{
		while ( objWindow.PollEvent(objEvent) )
		{
			if ( objEvent.Type == sf::Event::Closed ) 
			{
				this->Exit();
			}
		}
	}

	void Window::Exit()
	{
		if ( isRunning ) 
		{
			objWindow.Close();
			isRunning = false;
		}
	}

}