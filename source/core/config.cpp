
#include "core/config.h"

#include "core/window.h"
#include "utility/log.h"

namespace Core
{
	Config::Config( Core::Window *window /* = NULL */ )
		: window(window)
		, window_title(window_title)
		, volume_music(50)
		, volume_sound(50)
		, mouse_sensitivity(50)
		, mouse_inverted(false)
	{
		// By default we set all the keys to Count, which is not a key.
		for ( unsigned short int i = 0; i < Mapping::COUNT; i++ )
			this->keys[i] = sf::Keyboard::KeyCount;

		// Initialise the resolution via this class so that a window is created.
		if ( this->window != NULL )
			this->SetResolution(800, 600);
	}

	Config::~Config()
	{
		this->window = NULL;
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

		if ( this->window != NULL )
			this->window->Create(width, height);
		else
		{
			Utility::Log log("config.txt");
			log.Write("Warning, this->window is null, cannot create window.");
			log.EndLine();
		}
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
		if ( volume_percent > 200 )
			this->volume_music = 200;
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
		if ( volume_percent > 200 )
			this->volume_sound = 200;
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
		if ( sensitivity_percent > 200 )
			this->mouse_sensitivity = 200;
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
