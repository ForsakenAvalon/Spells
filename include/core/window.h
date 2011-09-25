
#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/View.hpp>

// Action bar test code
namespace Core
{
	class GUIManager;
}
// End action bar test code

namespace Utility
{
	class Log;
	class ResourceManager;
}

namespace Core
{
	class StateManager;
	class Config;

	//! \brief Core of the program
	class Window 
	{
		public:
			//! \brief Constructor
			//! 
			//! Constructs a window with the specified title
			//! 
			//! \param title Window title
			Window( const char *title = "Unnamed" );

			//! \brief Default deconstructor
			~Window();

			//! \brief Starts the program
			void Run();

			//! \brief Changes the resolution of the window
			//! 
			//! The width & height should be validated as a video mode before
			//! sent to this function.
			//! 
			//! \param width	New resolution width
			//! \param height	New resolution height
			void Create( const unsigned short int &width, const unsigned short int &height );

			//! \brief Changes the resolution of the window
			//! 
			//! The video_mode should be validated before sent to this function.
			//! 
			//! \param video_mode New sf::VideoMode
			void Create( sf::VideoMode &video_mode );

			//! \brief Assesses whether the window is running
			//! 
			//! \return True if the window is running
			bool Running() { return isRunning; }

			//! \brief Assesses whether the window is initialised
			//! 
			//! \return True if the window has been initialised
			bool Initialised() { return isInit; };

			//! \brief Retrieves a reference to the render window
			//! 
			//! \return sf::RenderWindow reference
			sf::RenderWindow& RenderWindow()	{ return objWindow; }

		private:
			//! \brief Call when the game window is resized
			void Resized();

			//! \brief Validate a video mode
			void ValidateVideoMode( sf::VideoMode &video_mode );

			//! \brief Main program loop
			void Loop();

			//! \brief Clears the window
			void Clear();

			//! \brief Displays anything drawn to the window
			void Display();

			//! \brief Handles global drawing and calls to other draw functions
			void Draw();

			//! \brief Stops the window loop from running
			void Exit();

			//! \brief Handles any events and calls to other event functions
			void Events();

			sf::RenderWindow objWindow;					//!< RenderWindow
			sf::Event objEvent;							//!< Event object
			sf::View *view;								//!< Default view

			std::string window_title;					//!< Window title

			Core::StateManager *state_manager;			//!< Pointer to Core::StateManager
			Core::Config *config;						//!< Pointer to Core::Config

			Utility::Log *log;							//!< Pointer to Log
			Utility::ResourceManager *resource_manager;	//!< Pointer to ResourceManager

			bool isRunning;								//!< Window running state
			bool isInit;								//!< Window initialisation state

			// Action bar test code
			Core::GUIManager *gui_manager;
			// End action bar test code
	};
}

#endif // CORE_WINDOW_H

//! \class Core::Window
//! \ingroup core
//! 
//! Heart of the program.
