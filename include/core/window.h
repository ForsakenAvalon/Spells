
// window_engine.h
// Wrapper for sfml window class

#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <SFML/Graphics.hpp>
#include "utility/string.h"
#include "base/state.h"

// Testing button class
#include "gui/button.h"
// End testing button class

namespace Core
{
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

		private:
			sf::RenderWindow objWindow;
			sf::Event objEvent;

			bool isRunning; // States if the window is running (Loop is being executed)
			bool isInit; // States if the window has been initialized

			void Loop();
			virtual void StandardEvents();

			// Testing button class
			GUI::Button *button;
			sf::Image *button_image;
			// End testing button class
	};
}

#endif // CORE_WINDOW_H
