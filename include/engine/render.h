
// renderer.h
// Handles the rendering of all visible game objects.

#ifndef ENGINE_RENDER_H
#define ENGINE_RENDER_H

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

#endif // ENGINE_RENDER_H
