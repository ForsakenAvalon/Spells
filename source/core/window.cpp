
#include "core/window.h"
#include "core/state_manager.h"
#include "core/config.h"

#include "utility/class_parser.h"
#include "utility/log.h"

#include <iostream>

namespace Core
{
	Window::Window(unsigned int height /* = 800 */, unsigned int width /* =600 */, const char * title /* = "Unnamed" */)
	{
		objWindow.Create(sf::VideoMode(height, width), title, sf::Style::Close);
		isInit = true;
		isRunning = false;
		
		this->log = new Utility::Log("log.txt");
		this->class_parser = new Utility::ClassParser();

		this->state_manager = new Core::StateManager(*this);
		this->config = new Core::Config();
	}

	Window::~Window()
	{
		// Close window if still running.
		this->Exit();

		// Attempt to write the configuration.
		if ( !this->class_parser->WriteClass<Core::Config>(this->config, "config.dat") )
		{
			this->log->Write("Couldn't save configuration.");
			this->log->EndLine();
		}
		
		delete this->config;
		delete this->state_manager;
		delete this->class_parser;
		delete this->log;
	}

	void Window::Run()
	{
		if ( isRunning )
			return;

		// Delete existing configuration.
		delete this->config;

		// Attempt to load configuration.
		this->config = this->class_parser->ReadClass<Core::Config>("config.dat");

		// Create a default configuration if no configuration could be loaded.
		if ( !this->config )
			this->config = new Core::Config();
		else
		{
			std::cout << "Setting window size to config size: " << this->config->GetResolution().x << ", " << this->config->GetResolution().y << std::endl;
			this->objWindow.SetSize(this->config->GetResolution().x, this->config->GetResolution().y);
		}

		isRunning = true;
		this->state_manager->SetState(States::MENU);
		this->Loop();
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
			case sf::Event::KeyPressed:
				if ( objEvent.Key.Code == sf::Key::A )
				{
					this->config->SetResolution(this->config->GetResolution().x + 50, this->config->GetResolution().y + 50);
					std::cout << "Incremented config resolution by 50, now = " << this->config->GetResolution().x << ", " << this->config->GetResolution().y << std::endl;
				}
				else if ( objEvent.Key.Code == sf::Key::D )
				{
					this->config->SetResolution(this->config->GetResolution().x - 50, this->config->GetResolution().y - 50);
					std::cout << "Decremented config resolution by 50, now = " << this->config->GetResolution().x << ", " << this->config->GetResolution().y << std::endl;
				}

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