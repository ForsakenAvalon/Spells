
// window.h
// Wrapper for sfml window class

#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <SFML/Graphics.hpp>

namespace Utility
{
	class ClassParser;
	class Log;
	class ResourceManager;
}

namespace Core
{
	class StateManager;
	class Config;
	class GUIManager;

	class Window 
	{
		public:
			Window( const char *title = "Unnamed" );
			~Window();

			void Run();

			inline void Create( const unsigned short int &width, const unsigned short int &height );

			bool IsRunning();
			bool IsInit();

			sf::RenderWindow& RenderWindow()	{ return objWindow; }

		private:
			void Clear();
			void Display();
			void Draw();
			void Exit();

			void LoadConfig();
			void Loop();
			virtual void StandardEvents();

			sf::RenderWindow objWindow;
			sf::Event objEvent;

			std::string window_title;

			bool isRunning; // States if the window is running (Loop is being executed)
			bool isInit; // States if the window has been initialized

			Core::StateManager *state_manager;
			Core::Config *config;

			Utility::ClassParser *class_parser;
			Utility::Log *log;
			Utility::ResourceManager *resource_manager;

			// Action bar test code
			Core::GUIManager *gui_manager;
			//GUI::ActionBar *action_bar;
			// End action bar test code
	};
}

#endif // CORE_WINDOW_H
