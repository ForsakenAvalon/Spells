
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
			void Clear();
			void Display();
			void Draw();
			void Exit();

			bool IsRunning();
			bool IsInit();

			sf::RenderWindow& RenderWindow()	{ return objWindow; }

		private:
			sf::RenderWindow objWindow;
			sf::Event objEvent;

			bool isRunning; // States if the window is running (Loop is being executed)
			bool isInit; // States if the window has been initialized

			void Loop();
			virtual void StandardEvents();

			Core::StateManager *state_manager;
			Core::Config *config;

			Utility::ClassParser *class_parser;
			Utility::Log *log;
			Utility::ResourceManager *resource_manager;

			// Action bar test code
			Core::GUIManager *gui_manager;
			//GUI::ActionBar *action_bar;
			// End action bar test code

			// Debug code
			sf::Sprite *sprite_1;
			sf::Image *image_1;
			// End debug code
	};
}

#endif // CORE_WINDOW_H
