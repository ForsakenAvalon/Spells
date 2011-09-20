
#ifndef CORE_CONFIG_H
#define CORE_CONFIG_H

#include "utility/vector.h"

#include <SFML/Window/Event.hpp>

namespace Core
{
	namespace Mapping
	{
		//! Contains all of the games possible input actions.
		enum Code
		{
			MOVE_UP = 0,
			MOVE_RIGHT,
			MOVE_DOWN,
			MOVE_LEFT,
			COUNT,
		};
	}

	//! \brief Holds all the clients configuration settings.
	class Config
	{
	public:
		Config();
		~Config();

		void						SetKey( const Mapping::Code &mapping_code, const sf::Keyboard::Key &key_code );
		const sf::Keyboard::Key&	GetKey( const Mapping::Code &mapping_code );

        void										SetResolution( const unsigned short int &width, const unsigned short int &height );
        const Utility::Vector<unsigned short int>&	GetResolution();

		void						SetMusicVolume( const unsigned short int &volume_percent );
		const unsigned short int&	GetMusicVolume();

		void						SetSoundVolume( const unsigned short int &volume_percent );
		const unsigned short int&	GetSoundVolume();

		void						SetMouseSensitivity( const unsigned short int &sensitivity_percent );
		const unsigned short int&	GetMouseSensitivity();

		void		SetMouseInverted( const bool &invert );
		const bool& GetMouseInverted();

	private:
		sf::Keyboard::Key keys[Mapping::COUNT];			//!< Holds a keycode for every Key::Code.

		Utility::Vector<unsigned short int> resolution;	//!< Game resolution, width/height.

		unsigned short int volume_music;				//!< Percentage volume of music.
		unsigned short int volume_sound;				//!< Percentage volume of sound.
		unsigned short int mouse_sensitivity;			//!< Percentage mouse sensitivity.
		
		bool mouse_inverted;							//!< True if mouse is inverted.
	};
}

#endif // CORE_CONFIG_H
