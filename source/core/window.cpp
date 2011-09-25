
#include "core/window.h"

#include "core/config.h"
#include "core/state_manager.h"
#include "utility/resource_manager.h"
#include "utility/log.h"
#include "utility/config_parser.h"

// Action bar test code
#include "core/gui_manager.h"
#include "gui/action_bar.h"
#include <iostream>
// End action bar test code

#include <sstream>
#include <fstream>

namespace Core
{
	Window::Window( const char *title /* = "Unnamed" */ )
		: window_title(title)
	{
		// Attempt to load configuration.
		this->config = new Core::Config(this);
		this->config->LoadConfig();
		
		if ( !this->objWindow.IsOpened() ) // Config should have already created the window.
			this->Create(this->config->GetResolution().x, this->config->GetResolution().y);

		this->isInit	= true;
		this->isRunning = false;
		
		this->resource_manager	= new Utility::ResourceManager();
		this->log				= new Utility::Log("window.txt");

		this->state_manager = new Core::StateManager(*this);

		// Action bar test code
		this->gui_manager = new Core::GUIManager(this->objWindow, *this->config, *this->resource_manager);
		this->gui_manager->Element("action_bar", "testbar", "actionbar.PNG").SetGUICoords(0, -45, true);
		this->gui_manager->Element("button", "testbutton", "button.png").SetGUICoords(0, 0, true);
		// End action bar test code

		this->view = new sf::View();
		this->Resized();
	}

	Window::~Window()
	{
		// Close window if still running.
		this->Exit();

		// Attempt to save the configuration.
		this->config->SaveConfig();
		
		// Action bar test code
		delete this->gui_manager;
		//delete this->action_bar;
		// End action bar test code

		delete this->state_manager;
		delete this->config;
		delete this->log;

		delete this->resource_manager;
	}

	// 
	// Public Functions
	// 

	void Window::Run()
	{
		if ( this->isRunning )
			return;

		this->isRunning = true;

		this->state_manager->SetState(StateType::MENU);

		this->Loop();
	}

	void Window::Create( const unsigned short int &width, const unsigned short int &height )
	{
		sf::VideoMode video_mode(width, height);
		this->ValidateVideoMode(video_mode);

		this->objWindow.Create(video_mode, this->window_title, sf::Style::Close | sf::Style::Resize);
	}

	void Window::Create( sf::VideoMode &video_mode )
	{
		this->ValidateVideoMode(video_mode);

		this->objWindow.Create(video_mode, this->window_title, sf::Style::Close | sf::Style::Resize);
	}

	// 
	// Private Functions
	// 

	void Window::Resized()
	{
		this->view->Reset(sf::FloatRect(0, 0, static_cast<float>(this->objWindow.GetWidth()), static_cast<float>(this->objWindow.GetHeight())));
		this->config->SetResolution(this->objWindow.GetWidth(), this->objWindow.GetHeight());
		this->gui_manager->UpdateElements();
	}

	void Window::ValidateVideoMode( sf::VideoMode &video_mode )
	{
		if ( video_mode.IsValid() )
			return;

		// Set the video mode to the smallest video mode the screen can handle.
		video_mode = video_mode.GetFullscreenModes().back();
	}

	void Window::Loop()
	{
		while ( this->isRunning ) 
		{
			// Handle events.
			this->Events();

			// Call draw functions.
			this->Clear();
			this->Draw();
			this->Display();
		}
	}

	void Window::Clear()
	{
		this->objWindow.Clear();
	}

	void Window::Display()
	{
		this->objWindow.Display();
	}

	void Window::Draw()
	{
		this->objWindow.SetView(*this->view);
		// Action bar test code
		//this->action_bar->Update();
		//this->gui_manager->ActionBar("testbar").Update();
		this->gui_manager->Element("action_bar", "testbar").Draw();
		this->gui_manager->Element("button", "testbutton").Draw();
		//this->objWindow.Draw(this->action_bar->GetActionBar());
		// End action bar test code

		this->state_manager->Update();
		this->objWindow.SetView(this->objWindow.GetDefaultView());
	}

	void Window::Exit()
	{
		if ( !this->isRunning )
			return;
		
		this->isRunning = false;
	}

	void Window::Events()
	{
		while ( this->objWindow.PollEvent(this->objEvent) )
		{
			// Global events.
			switch ( this->objEvent.Type )
			{
			case sf::Event::Closed:
				this->Exit();
				break;

			case sf::Event::Resized:
				this->Resized();
				break;

			case sf::Event::KeyPressed:
				// Action bar test code
				if ( this->objEvent.Key.Code == sf::Keyboard::Escape )
				{
					if ( this->config->GetResolution().x != 1024 || this->config->GetResolution().y != 768 )
					{
						std::cout << "Setting config resultion to 1024, 768" << std::endl;
						this->Create(1024, 768);
						this->Resized();
					}
					else
					{
						std::cout << "Setting config resultion to 800, 600" << std::endl;
						this->Create(800, 600);
						this->Resized();
					}
					std::cout << "Config resolution: " << this->config->GetResolution().x << ", " << this->config->GetResolution().y << std::endl;
				}
				// End action bar test code
				break;

			default:
				break;
			}
			// End global events.

			this->state_manager->Events(objEvent);
		}
	}
}