
#include "core/config.h"

#include "core/window.h"
#include "utility/log.h"
#include "Utility/config_parser.h"

#include <SFML/Window/VideoMode.hpp>

#include <fstream>
#include <sstream>

namespace Core
{
	Config::Config( Core::Window *window /* = NULL */ )
		: window(window)
		, window_title(window_title)
		, resolution(1024, 768)
		, volume_music(50)
		, volume_sound(50)
		, mouse_sensitivity(50)
		, mouse_inverted(false)
	{
		// By default we set all the keys to Count, which is not a key.
		for ( unsigned short int i = 0; i < Mapping::COUNT; i++ )
			this->keys[i] = sf::Keyboard::KeyCount;
	}

	Config::~Config()
	{
		this->window = NULL;
	}

	void Config::LoadConfig()
	{
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
					if ( resolution_x != this->GetResolution().x || resolution_y != this->GetResolution().y )
						this->SetResolution(resolution_x, resolution_y);
				}
			}
		}

		// Music volume.
		{
			unsigned short int music_volume;

			std::string s_music_volume = config_parser->GetValue("music_volume");
			std::stringstream ss(s_music_volume);

			if ( (ss >> music_volume) )
				if ( music_volume != this->GetMusicVolume() )
					this->SetMusicVolume(music_volume);
		}

		// Sound volume.
		{
			unsigned short int sound_volume;

			std::string s_sound_volume = config_parser->GetValue("sound_volume");
			std::stringstream ss(s_sound_volume);

			if ( (ss >> sound_volume) )
				if ( sound_volume != this->GetSoundVolume() )
					this->SetSoundVolume(sound_volume);
		}

		// Mouse sensitivity.
		{
			unsigned short int mouse_sensitivity;

			std::string s_mouse_sensitivity = config_parser->GetValue("mouse_sensitivity");
			std::stringstream ss(s_mouse_sensitivity);

			if ( (ss >> mouse_sensitivity) )
				if ( mouse_sensitivity != this->GetMouseSensitivity() )
					this->SetMouseSensitivity(mouse_sensitivity);
		}

		// Mouse inverted.
		{
			bool mouse_inverted;

			std::string s_mouse_inverted = config_parser->GetValue("mouse_inverted");
			std::stringstream ss(s_mouse_inverted);

			if ( (ss >> mouse_inverted) )
				if ( mouse_inverted != this->GetMouseInverted() )
					this->SetMouseInverted(mouse_inverted);
		}

		// Clean up.
		delete config_parser;
	}

	void Config::SaveConfig()
	{
		// Attempts to save the configuration settings
		Utility::ConfigParser *config_parser = new Utility::ConfigParser("config.txt");

		std::ofstream new_file("config.txt", std::ofstream::in | std::ofstream::trunc);

		new_file << "\nresolution = " << this->GetResolution().x << "x" << this->GetResolution().y << "\n\n";
		new_file << "music_volume = " << this->GetMusicVolume() << " // 0 - 100%.\n";
		new_file << "sound_volume = " << this->GetSoundVolume() << " // 0 - 100%.\n\n";
		new_file << "mouse_sensitivity = " << this->GetMouseSensitivity() << " // 0 - 200%\n";
		new_file << "mouse_inverted = " << this->GetMouseInverted() << " // Mouse inverted, true/false.\n";

		new_file.close();

		delete config_parser;
	}

	void Config::SetWindow( Core::Window *window )
	{
		this->window = window;
	}

	// 
	// Keys
	// 
	void Config::SetKey( const Mapping::Code &mapping_code, const sf::Keyboard::Key &key_code )
	{
		this->keys[mapping_code] = key_code;
	}
	
	const sf::Keyboard::Key& Config::GetKey( const Mapping::Code &mapping_code )
	{
		return this->keys[mapping_code];
	}
	
	// 
	// Resolution
	// 
	void Config::SetResolution( const unsigned short int &width, const unsigned short int &height )
	{
		this->resolution.x = width;
		this->resolution.y = height;
	}
	
	const Utility::Vector<unsigned short int>& Config::GetResolution()
	{
		return this->resolution;
	}

	// 
	// Music Volume
	// 
	void Config::SetMusicVolume( const unsigned short int &volume_percent )
	{
		if ( volume_percent > 100 )
			this->volume_music = 100;
		else if ( volume_percent < 0 )
			this->volume_music = 0;
		else
			this->volume_music = volume_percent;
	}

	const unsigned short int& Config::GetMusicVolume()
	{
		return this->volume_music;
	}

	// 
	// Sound Volume
	// 
	void Config::SetSoundVolume( const unsigned short int &volume_percent )
	{
		if ( volume_percent > 100 )
			this->volume_sound = 100;
		else if ( volume_percent < 0 )
			this->volume_sound = 0;
		else
			this->volume_sound = volume_percent;
	}

	const unsigned short int& Config::GetSoundVolume()
	{
		return this->volume_sound;
	}

	// 
	// Mouse Sensitivity
	// 
	void Config::SetMouseSensitivity( const unsigned short int &sensitivity_percent )
	{
		if ( sensitivity_percent > 100 )
			this->mouse_sensitivity = 100;
		else if ( sensitivity_percent < 0 )
			this->mouse_sensitivity = 0;
		else
			this->mouse_sensitivity = sensitivity_percent;
	}

	const unsigned short int& Config::GetMouseSensitivity()
	{
		return this->mouse_sensitivity;
	}

	// 
	// Mouse Inverted
	// 
	void Config::SetMouseInverted( const bool &invert )
	{
		this->mouse_inverted = invert;
	}

	const bool& Config::GetMouseInverted()
	{
		return this->mouse_inverted;
	}
}
