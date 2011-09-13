
// window_engine.h
// Wrapper for sfml window class

#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include "utility/string.h"

#include <SFML/Graphics.hpp>

namespace Utility
{
	class ClassParser;
	class Log;
}

namespace Core
{
	class StateManager;
	class Config;

	class Window 
	{
		public:
			Window(unsigned int width = 800, unsigned int height = 600, const char * title = "Unnamed");
			~Window();

			void Run();
			void Clear();
			void Display();
			void Draw();
			void Exit();

			bool IsRunning();
			bool IsInit();

			sf::RenderWindow& RenderWindow() { return objWindow; }

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
	};
}

#endif // CORE_WINDOW_H
