
#include "core/window.h"
#include "core/state_manager.h"
#include "core/config.h"

#include "utility/class_parser.h"
#include "utility/log.h"
#include "utility/resource_manager.h"

// Action bar test code
#include "core/gui_manager.h"
#include "gui/action_bar.h"
// End action bar test code

#include <iostream>

namespace Core
{
	Window::Window( const char *title /* = "Unnamed" */ )
	{
		// Attempt to load configuration.
		this->config = this->class_parser->ReadClass<Core::Config>("config.dat");

		// Create a default configuration if no configuration could be loaded.
		if ( !this->config )
			this->config = new Core::Config();
		else
		{
			std::cout << "Setting window size to config size: " << this->config->GetResolution().x << ", " << this->config->GetResolution().y << std::endl;
			this->objWindow.SetSize(this->config->GetResolution().x, this->config->GetResolution().y);
			std::cout << "Config window size: " << this->config->GetResolution().x << ", " << this->config->GetResolution().y << std::endl;
		}
		// End creating/loading configuration.

		objWindow.Create(sf::VideoMode(this->config->GetResolution().x, this->config->GetResolution().y), title, sf::Style::Close);
		isInit = true;
		isRunning = false;
		
		this->resource_manager = new Utility::ResourceManager();
		this->log = new Utility::Log("log.txt");
		this->class_parser = new Utility::ClassParser();

		this->state_manager = new Core::StateManager(*this);

		// Action bar test code
		this->gui_manager = new Core::GUIManager(this->objWindow, *this->config, *this->resource_manager);
		this->gui_manager->ActionBar("testbar", "actionbar.PNG");
		//this->action_bar = new GUI::ActionBar(this->objWindow, *this->config, *this->resource_manager, "actionbar.PNG");
		// End action bar test code

		// Debug code
		this->image_1 = new sf::Image();
		this->image_1->LoadFromFile("resources/images/button.png");
		this->sprite_1 = new sf::Sprite(*this->image_1);
		// End debug code
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
		
		// Action bar test code
		delete this->gui_manager;
		//delete this->action_bar;
		// End action bar test code

		delete this->state_manager;
		delete this->config;
		delete this->class_parser;
		delete this->log;

		delete this->resource_manager;

		// Debug code
		delete this->sprite_1;
		delete this->image_1;
		// End debug code
	}

	void Window::Run()
	{
		if ( isRunning )
			return;

		isRunning = true;
		this->state_manager->SetState(StateType::MENU);
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
		// Action bar test code
		//this->action_bar->Update();
		this->gui_manager->ActionBar("testbar").Update();
		//this->objWindow.Draw(this->action_bar->GetActionBar());
		// End action bar test code
		this->state_manager->Update();
		// Debug code
		this->objWindow.Draw(*this->sprite_1);
		// End debug code
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
				if ( objEvent.Key.Code == sf::Key::Escape )
				{
					if ( this->config->GetResolution().x != 1024 || this->config->GetResolution().y != 800 )
					{
						this->objWindow.Create(sf::VideoMode(1024, 800), "new title", sf::Style::Close);
						std::cout << "Setting config resultion to 1024, 800" << std::endl;
						this->config->SetResolution(1024, 800);
					}
					else
					{
						this->objWindow.Create(sf::VideoMode(800, 600), "new title", sf::Style::Close);
						std::cout << "Setting config resultion to 800, 600" << std::endl;
						this->config->SetResolution(800, 600);
					}
					std::cout << "Config resolution: " << this->config->GetResolution().x << ", " << this->config->GetResolution().y << std::endl;
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