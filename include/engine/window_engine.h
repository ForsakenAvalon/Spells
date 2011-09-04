
// window_engine.h
// Wrapper for sfml window class

#ifndef ENGINE_WINDOW_ENGINE_H
#define ENGINE_WINDOW_ENGINE_H

#include <SFML/Graphics.hpp>
#include "utility/string.h"

namespace Engine
{
	class Window 
	{
		public:
			Window(unsigned int width = 800, unsigned int height = 600, const char * title = "Unnamed");
			~Window();

			void Run();
			//void Run(void (*main)(Window & windowMain));
			void Clear();
			void Display();
			void Draw();
			void Exit();

			bool IsRunning();
			bool IsInit();

		private:
			sf::RenderWindow objWindow;
			sf::Event objEvent;
			//void (*ptrMain)(Window & windowMain);

			bool isRunning; // States if the window is running (Loop is being executed)
			bool isInit; // States if the window has been initialized
			//bool hasMain; // States if the window has a main function

			void Loop();
			virtual void StandardEvents();
	};
}

#endif // WINDOW_ENGINE_H
