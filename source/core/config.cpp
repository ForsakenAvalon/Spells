
#include "core/config.h"

namespace Core
{
	Config::Config()
		: resolution(800, 600)
		, volume_music(50)
		, volume_sound(50)
		, mouse_sensitivity(50)
		, mouse_inverted(false)
	{
		// By default we set all the keys to Count, which is not a key.
		for ( unsigned short int i = 0; i < Mapping::COUNT; i++ )
			this->keys[i] = sf::Key::Count;
	}

	Config::~Config()
	{

	}

	// 
	// Keys
	// 
	void Config::SetKey( const Mapping::Code &mapping_code, const sf::Key::Code &key_code )
	{
		this->keys[mapping_code] = key_code;
	}
	
	const sf::Key::Code& Config::GetKey( const Mapping::Code &mapping_code )
	{
		return this->keys[mapping_code];
	}
	
	// 
	// Resolution
	// 
	void Config::SetResolution( const unsigned short int &width, const unsigned short int &height )
	{
		this->resolution.local_x = width;
		this->resolution.local_y = height;
	}
	
	const Base::Vector<unsigned short int>& Config::GetResolution()
	{
		return this->resolution;
	}

	// 
	// Music Volume
	// 
	void Config::SetMusicVolume( const unsigned short int &volume_percent )
	{
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
