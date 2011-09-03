// window_engine.h
// Wrapper for sfml window class
// GUI features like inventory screens should be called from here and passed to renderer.

#ifndef WINDOW_ENGINE_H
#define WINDOW_ENGINE_H

#include <SFML/Graphics.hpp>
#include "utility/string.h"

namespace Engine
{
	class Window 
	{
		public:
			Window(unsigned int width, unsigned int height);
			~Window();

			void Run();
			void Run(void (*main)(Window & windowMain));
			void Clear();
			void Display();
			void Draw();
			void Exit();

			bool IsRunning();
			bool IsInit();

		private:
			sf::RenderWindow objWindow;
			sf::Event objEvent;
			void (*ptrMain)(Window & windowMain);

			bool isRunning; // States if the window is running (Loop has been executed)
			bool isInit; // States if the window has been initialized
			bool hasMain; // States if the window has a main function

			void Loop();
	};
}

#endif