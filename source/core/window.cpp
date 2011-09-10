
#include "core/window.h"

namespace Core
{
	Window::Window(unsigned int height /* = 800 */, unsigned int width /* =600 */, const char * title /* = "Unnamed" */)
	{
		objWindow.Create(sf::VideoMode(height, width), title, sf::Style::Close);
		isInit = true;
		isRunning = false;

		// Testing button class
		this->button_image = new sf::Image();
		this->button_image->LoadFromFile("resources/images/button.png");
		this->button = new GUI::Button(*this->button_image);
		// End testing button class
	}

	Window::~Window()
	{
		// Close window if still running.
		this->Exit();

		// Testing button class
		delete this->button;
		delete this->button_image;
		// End testing button class
	}

	void Window::Run()
	{
		if (!isRunning)  
		{
			isRunning = true;
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
		// Testing button class
		objWindow.Draw(*this->button);
		// End testing button class
	}

	// Executes the main loop of the program. You cannot call Loop directly, use Run instead.
	void Window::Loop()
	{
		while (isRunning) 
		{
			// Handle Standard Window Events
			this->StandardEvents();

			// Do standard draw process
			this->Clear();
			this->Draw();
			this->Display();
		}
	}

	//! /brief Handle Common Window Events
	//! /descrip Clears the event stack of common events that occur in
	//! the window.
	void Window::StandardEvents()
	{
		while (objWindow.PollEvent(objEvent))
		{
			switch (objEvent.Type)
			{
			case sf::Event::Closed :
				this->Exit();
				break;
			case sf::Event::Resized :
				// Resize Code if required
				break;
			// Testing button class
			case sf::Event::MouseButtonPressed:
				if ( this->button->CheckClicked(objEvent.MouseButton.X, objEvent.MouseButton.Y) )
					this->Exit();

				break;
			// End testing button class
			default :
				break;
			}
		}
	}

	void Window::Exit()
	{
		if (isRunning) 
		{
			objWindow.Close();
			isRunning = false;
		}
	}

}