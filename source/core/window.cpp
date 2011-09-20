
#include "core/window.h"
#include "core/state_manager.h"
#include "core/config.h"

#include "utility/class_parser.h"
#include "utility/log.h"
#include "utility/resource_manager.h"
#include "utility/config_parser.h"

// Action bar test code
#include "core/gui_manager.h"
#include "gui/action_bar.h"
// End action bar test code

#include <iostream>
#include <sstream>

namespace Core
{
	Window::Window( const char *title /* = "Unnamed" */ )
	{
		this->LoadConfig();
		
		objWindow.Create(sf::VideoMode(this->config->GetResolution().x, this->config->GetResolution().y), title, sf::Style::Close);
		isInit = true;
		isRunning = false;
		
		this->resource_manager = new Utility::ResourceManager();
		this->log = new Utility::Log("window.txt");
		this->class_parser = new Utility::ClassParser();

		this->state_manager = new Core::StateManager(*this);

		// Action bar test code
		this->gui_manager = new Core::GUIManager(this->objWindow, *this->config, *this->resource_manager);
		this->gui_manager->ActionBar("testbar", "actionbar.PNG").SetPosition((float) ((this->objWindow.GetWidth() - 502) / 2),
			(float) (this->objWindow.GetHeight() - 45));
		//this->gui_manager->ActionBar("testbar", "actionbar.PNG");
		//this->action_bar = new GUI::ActionBar(this->objWindow, *this->config, *this->resource_manager, "actionbar.PNG");
		// End action bar test code
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
		//this->gui_manager->ActionBar("testbar").Update();
		this->gui_manager->ActionBar("testbar").Draw();
		//this->objWindow.Draw(this->action_bar->GetActionBar());
		// End action bar test code

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
				if ( objEvent.Key.Code == sf::Keyboard::Escape )
				{
					if ( this->config->GetResolution().x != 1024 || this->config->GetResolution().y != 800 )
					{
						this->objWindow.Create(sf::VideoMode(1024, 800), "new title", sf::Style::Close);
						std::cout << "Setting config resultion to 1024, 800" << std::endl;
						this->config->SetResolution(1024, 800);
						this->gui_manager->UpdateElements(800, 600);
					}
					else
					{
						this->objWindow.Create(sf::VideoMode(800, 600), "new title", sf::Style::Close);
						std::cout << "Setting config resultion to 800, 600" << std::endl;
						this->config->SetResolution(800, 600);
						this->gui_manager->UpdateElements(1024, 800);
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

	void Window::LoadConfig()
	{
		// Attempt to load configuration.
		this->config = this->class_parser->ReadClass<Core::Config>("data/config.dat");

		// Create a default configuration if no configuration could be loaded.
		if ( !this->config )
			this->config = new Core::Config();

		// Attempt to load any text configuration settings.
		Utility::ConfigParser *config_parser = new Utility::ConfigParser("config.txt");

		// Exit function if the file can't be read.
		if ( !config_parser->ReadFile() )
		{
			// Create a new file if the file doesn't exist (with default data).
			if ( config_parser->FileExists() )
				return; // Error in the file.

			// Create the new default and empty config file.
			std::ofstream new_file("config.txt");
			std::string default_file = 
				"\nresolution = 1024x800\n\n"
				"music_volume = 100 // 0 - 200%.\n"
				"sound_volume = 100 // 0 - 200%.\n\n"
				"mouse_sensitivity = 100 // 0 - 200%\n"
				"mouse_inverted = false // Mouse inverted, true/false.\n";
			new_file.write(default_file.c_str(), default_file.length());

			return;
		}

		// Cycle through each configuration option.
		// Return from this function if at any point we cannot continue
		// as this suggests a corrupt config file we don't wish to use.

		// Resolution.
		{
			unsigned short int resolution_x;
			unsigned short int resolution_y;

			std::string s_resolution_x = config_parser->GetValue("resolution");
			unsigned int pos = s_resolution_x.find('x');
			if ( pos == std::string::npos )
				return;

			std::string s_resolution_y = s_resolution_x.substr(pos + 1);
			s_resolution_x = s_resolution_x.substr(0, pos);

			std::cout << "res x: " << s_resolution_x << ", res y: " << s_resolution_y << std::endl;

			std::stringstream ss_x(s_resolution_x);
			if ( !(ss_x >> resolution_x) )
				return;

			std::cout << "res x: " << resolution_x << std::endl;

			std::stringstream ss_y(s_resolution_y);
			if ( !(ss_y >> resolution_y) )
				return;

			std::cout << "res y: " << resolution_y << std::endl;

			this->config->SetResolution(resolution_x, resolution_y);
		}

		// Music volume.
		{
			unsigned short int music_volume;

			std::string s_music_volume = config_parser->GetValue("music_volume");
			std::stringstream ss(s_music_volume);

			if ( !(ss >> music_volume) )
				return;

			this->config->SetMusicVolume(music_volume);
		}

		// Sound volume.
		{
			unsigned short int sound_volume;

			std::string s_sound_volume = config_parser->GetValue("sound_volume");
			std::stringstream ss(s_sound_volume);

			if ( !(ss >> sound_volume) )
				return;

			this->config->SetSoundVolume(sound_volume);
		}

		// Mouse sensitivity.
		{
			unsigned short int mouse_sensitivity;

			std::string s_mouse_sensitivity = config_parser->GetValue("mouse_sensitivity");
			std::stringstream ss(s_mouse_sensitivity);

			if ( !(ss >> mouse_sensitivity) )
				return;

			this->config->SetMouseSensitivity(mouse_sensitivity);
		}

		// Mouse inverted.
		{
			bool mouse_inverted;

			std::string s_mouse_inverted = config_parser->GetValue("mouse_inverted");
			std::stringstream ss(s_mouse_inverted);

			if ( !(ss >> mouse_inverted) )
				return;

			this->config->SetMouseInverted(mouse_inverted);
		}
	}
}