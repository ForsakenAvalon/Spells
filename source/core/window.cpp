
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
		this->LoadConfig();
		
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
	}

	Window::~Window()
	{
		// Close window if still running.
		this->Exit();

		// Attempt to save the configuration.
		this->SaveConfig();
		
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

	inline void Window::Create( const unsigned short int &width, const unsigned short int &height )
	{
		this->objWindow.Create(sf::VideoMode(width, height), this->window_title, sf::Style::Close);
	}

	void Window::Create( sf::VideoMode video_mode )
	{
		this->objWindow.Create(video_mode, this->window_title, sf::Style::Close);
	}

	// 
	// Private Functions
	// 

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
		// Action bar test code
		//this->action_bar->Update();
		//this->gui_manager->ActionBar("testbar").Update();
		this->gui_manager->Element("action_bar", "testbar").Draw();
		this->gui_manager->Element("button", "testbutton").Draw();
		//this->objWindow.Draw(this->action_bar->GetActionBar());
		// End action bar test code

		this->state_manager->Update();
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
				break;

			case sf::Event::KeyPressed:
				// Action bar test code
				if ( this->objEvent.Key.Code == sf::Keyboard::Escape )
				{
					if ( this->config->GetResolution().x != 1024 || this->config->GetResolution().y != 768 )
					{
						std::cout << "Setting config resultion to 1024, 768" << std::endl;
						this->config->SetResolution(1024, 768);
						this->gui_manager->UpdateElements();
					}
					else
					{
						std::cout << "Setting config resultion to 800, 600" << std::endl;
						this->config->SetResolution(800, 600);
						this->gui_manager->UpdateElements();
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

	void Window::LoadConfig()
	{
		// Attempt to load configuration.
		this->config = new Core::Config(this);

		// Attempt to load any text configuration settings.
		Utility::ConfigParser *config_parser = new Utility::ConfigParser("config.txt");

		// Exit function if the file can't be read.
		if ( !config_parser->ReadFile() )
		{
			// Create a new file or overwrite one that exists as it's corrupt.
			std::ofstream new_file("config.txt", std::ofstream::in | std::ofstream::trunc);

			new_file << 
				"\nresolution = 1024x768\n\n"
				"music_volume = 50 // 0 - 100%.\n"
				"sound_volume = 50 // 0 - 100%.\n\n"
				"mouse_sensitivity = 50 // 0 - 200%\n"
				"mouse_inverted = false // Mouse inverted, true/false.\n";

			new_file.close();

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
			if ( pos != std::string::npos )
			{
				std::string s_resolution_y = s_resolution_x.substr(pos + 1);
				s_resolution_x = s_resolution_x.substr(0, pos);

				std::stringstream ss_x(s_resolution_x);
				std::stringstream ss_y(s_resolution_y);

				if ( (ss_x >> resolution_x) && (ss_y >> resolution_y) )
				{
					if ( resolution_x != this->config->GetResolution().x || resolution_y != this->config->GetResolution().y )
					{
						// Ensure that the resolution is never below 1024, 768 when starting.
						if ( resolution_x < 1024 )
							resolution_x = 1024;
						if ( resolution_y < 768 )
							resolution_y = 768;

						this->config->SetResolution(resolution_x, resolution_y);
					}
				}
				else // If we couldn't use this new resolution, create the window with the default resolution.
					this->config->SetResolution(1024, 768);
			}
			else // If we couldn't use this new resolution, create the window with the default resolution.
				this->config->SetResolution(1024, 768);
		}

		// Music volume.
		{
			unsigned short int music_volume;

			std::string s_music_volume = config_parser->GetValue("music_volume");
			std::stringstream ss(s_music_volume);

			if ( (ss >> music_volume) )
				if ( music_volume != this->config->GetMusicVolume() )
					this->config->SetMusicVolume(music_volume);
		}

		// Sound volume.
		{
			unsigned short int sound_volume;

			std::string s_sound_volume = config_parser->GetValue("sound_volume");
			std::stringstream ss(s_sound_volume);

			if ( (ss >> sound_volume) )
				if ( sound_volume != this->config->GetSoundVolume() )
					this->config->SetSoundVolume(sound_volume);
		}

		// Mouse sensitivity.
		{
			unsigned short int mouse_sensitivity;

			std::string s_mouse_sensitivity = config_parser->GetValue("mouse_sensitivity");
			std::stringstream ss(s_mouse_sensitivity);

			if ( (ss >> mouse_sensitivity) )
				if ( mouse_sensitivity != this->config->GetMouseSensitivity() )
					this->config->SetMouseSensitivity(mouse_sensitivity);
		}

		// Mouse inverted.
		{
			bool mouse_inverted;

			std::string s_mouse_inverted = config_parser->GetValue("mouse_inverted");
			std::stringstream ss(s_mouse_inverted);

			if ( (ss >> mouse_inverted) )
				if ( mouse_inverted != this->config->GetMouseInverted() )
					this->config->SetMouseInverted(mouse_inverted);
		}

		// Clean up.
		delete config_parser;
	}

	void Window::SaveConfig()
	{
		// Attempts to save the configuration settings
		Utility::ConfigParser *config_parser = new Utility::ConfigParser("config.txt");

		std::ofstream new_file("config.txt", std::ofstream::in | std::ofstream::trunc);

		new_file << "\nresolution = " << this->config->GetResolution().x << "x" << this->config->GetResolution().y << "\n\n";
		new_file << "music_volume = " << this->config->GetMusicVolume() << " // 0 - 100%.\n";
		new_file << "sound_volume = " << this->config->GetSoundVolume() << " // 0 - 100%.\n\n";
		new_file << "mouse_sensitivity = " << this->config->GetMouseSensitivity() << " // 0 - 200%\n";
		new_file << "mouse_inverted = " << this->config->GetMouseInverted() << " // Mouse inverted, true/false.\n";

		new_file.close();

		delete config_parser;
	}
}