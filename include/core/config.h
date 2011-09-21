
#ifndef CORE_CONFIG_H
#define CORE_CONFIG_H

#include "utility/vector.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Core
{
	class Window;

	namespace Mapping
	{
		//! \brief Contains all of the games possible key maps
		enum Code
		{
			MOVE_UP = 0,	//!< Move the character up
			MOVE_RIGHT,		//!< Move the character right
			MOVE_DOWN,		//!< Move the character down
			MOVE_LEFT,		//!< Move the character left

			COUNT,			//!< Total number of key maps
		};
	}

	//! \brief Holds all the clients configuration settings.
	class Config
	{
	public:
		//! \brief Default constructor
		//! 
		//! This constructor doesn't initialise *window, therefore SetWindow
		//! must be called if this constructor is used.
		Config();

		//! \brief Constructor
		//! 
		//! SetWindow doesn't need to be called if this constructor is used.
		//! 
		//! \param window Pointer to Core::Window
		Config( Core::Window *window );

		//! \brief Default deconstructor
		~Config();

		//! \brief Sets the private window member
		//! 
		//! \param window Pointer to Core::Window
		void SetWindow( Core::Window *window );

		//! \brief Binds a specific key map to a key
		//! 
		//! \param mapping_code Mapping code
		//! \param key_code		Key code
		void SetKey( const Mapping::Code &mapping_code, const sf::Keyboard::Key &key_code );

		//! \brief Gets the key bound to a specific key map
		//! 
		//! \param mapping_code Mapping code
		//! 
		//! \return Key code
		const sf::Keyboard::Key& GetKey( const Mapping::Code &mapping_code );

		//! \brief Sets the resolution of the screen
		//! 
		//! Changes the windows resolution if a window has been set.
		//! 
		//! \param width	Width of the window in pixels
		//! \param height	Height of the window in pixels
        void SetResolution( const unsigned short int &width, const unsigned short int &height );

		//! \brief Gets the resolution of the screen
		//! 
		//! \return Resolution as a vector
        const Utility::Vector<unsigned short int>& GetResolution();

		//! \brief Sets the games music volume
		//! 
		//! A percentage from 0% - 200%.
		//! 
		//! \param volume_percent Music volume as a percentage of 200
		void SetMusicVolume( const unsigned short int &volume_percent );

		//! \brief Gets the games music volume
		//! 
		//! \return Music volume as a percentage of 200
		const unsigned short int& GetMusicVolume();

		//! \brief Sets the games sound volume
		//! 
		//! \param volume_percent Sound volume as a percentage of 200
		void SetSoundVolume( const unsigned short int &volume_percent );

		//! \brief Gets the games sound volume
		//! 
		//! \return Sound volume as a percentage of 200
		const unsigned short int& GetSoundVolume();

		//! \brief Sets the mouse sensitivity
		//! 
		//! \param sensitivity_percent Mouse sensitivity as a percentage of 200
		void SetMouseSensitivity( const unsigned short int &sensitivity_percent );

		//! \brief Gets the mouse sensitivity
		//! 
		//! \return Mouse sensitivity as a percentage of 200
		const unsigned short int& GetMouseSensitivity();

		//! \brief Controls whether the mouse is inverted
		//! 
		//! True to invert the mouse controls, false to leave them as default.
		//! 
		//! \param invert Mouse inversion state as a bool
		void SetMouseInverted( const bool &invert );

		//! \brief Assesses whether the mouse state is inverted
		//! 
		//! Returns true if the mouse is inverted, otherwise false.
		//! 
		//! \return Mouse inversion state as a bool
		const bool& GetMouseInverted();

	private:
		Core::Window *window;							//!< Holds a pointer to Core::Window.
		sf::Keyboard::Key keys[Mapping::COUNT];			//!< Holds a keycode for every Key::Code.
		std::string window_title;						//!< Holds the window title.

		Utility::Vector<unsigned short int> resolution;	//!< Game resolution, width/height.

		unsigned short int volume_music;				//!< Percentage volume of music.
		unsigned short int volume_sound;				//!< Percentage volume of sound.
		unsigned short int mouse_sensitivity;			//!< Percentage mouse sensitivity.
		
		bool mouse_inverted;							//!< True if mouse is inverted.
	};
}

#endif // CORE_CONFIG_H

//! \class Core::Config
//! \ingroup core
//! 
//! Holds all game config and data settings. The resolution of the game
//! should only ever be changed through this classes SetResolution
//! function as this ensures the window resolution and config resolution
//! are both updated.
//! 
//! Config is also used to map keys to key maps. Each mapping can have
//! one key. The mappings are stored in the Mapping namespace where as
//! the key codes use the sf::Keyboard enumerator.
