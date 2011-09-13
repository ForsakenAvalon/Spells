
#ifndef CORE_CONFIG_H
#define CORE_CONFIG_H

#include "base/vector.h"

#include <SFML/Window/Event.hpp>

namespace Core
{
	namespace Action
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

		void					SetKey( Action::Code &action_code, sf::Key::Code &key_code );
		const sf::Key::Code&	GetKey( Action::Code &action_code );

	private:
		sf::Key::Code keys[Action::COUNT];				//!< Holds a keycode for every Key::Code.

		Base::Vector<unsigned short int> resolution;	//!< Game resolution, width/height.

		unsigned short int volume_music;				//!< Percentage volume of music.
		unsigned short int volume_sound;				//!< Percentage volume of sound.
		unsigned short int mouse_sensitivity;			//!< Percentage mouse sensitivity.
		
		bool mouse_inverted;							//!< True if mouse is inverted.
	};
}

#endif // CORE_CONFIG_H
