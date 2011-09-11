
#include "core/window.h"
#include "core/state_manager.h"

namespace Core
{
	Window::Window(unsigned int height /* = 800 */, unsigned int width /* =600 */, const char * title /* = "Unnamed" */)
	{
		objWindow.Create(sf::VideoMode(height, width), title, sf::Style::Close);
		isInit = true;
		isRunning = false;

		this->state_manager = new Core::StateManager(*this);
	}

	Window::~Window()
	{
		// Close window if still running.
		this->Exit();

		delete this->state_manager;
	}

	void Window::Run()
	{
		if (!isRunning)  
		{
			isRunning = true;
			this->state_manager->SetState(States::MENU);
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
		this->state_manager->Update();
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
			// Global events.
			switch (objEvent.Type)
			{
			case sf::Event::Closed:
				this->Exit();
				break;
			case sf::Event::Resized:
				// Resize Code if required
				break;
			default :
				break;
			}

			this->state_manager->Events(objEvent);
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