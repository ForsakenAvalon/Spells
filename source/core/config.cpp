
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

	const sf::Key::Code& Config::GetKey( Mapping::Code &mapping_code )
	{
		return this->keys[mapping_code];
	}

	void Config::SetKey( Mapping::Code &mapping_code, sf::Key::Code &key_code )
	{
		this->keys[mapping_code] = key_code;
	}
}
