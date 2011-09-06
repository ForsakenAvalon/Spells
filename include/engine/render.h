
// renderer.h
// Handles the rendering of all visible game objects.

#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include <SFML\Graphics.hpp>
#include "core\window.h"

namespace Engine
{
	class Render
	{
		public:
			Render(Core::Window & attachWindow);
			~Render();
		private:
			Core::Window * objWindow;
	};
}

#endif // ENGINE_RENDERER_H