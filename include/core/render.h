
// render.h
// Handles the rendering of all visible game objects.

#ifndef CORE_RENDER_H
#define CORE_RENDER_H

#include <SFML/Graphics/Sprite.hpp>

namespace Core
{
	class Window;
}

namespace GUI
{
	class Button;
}

namespace Core
{
	class Render
	{
		public:
			Render( Core::Window &window );
			~Render();

			void RenderSprite( sf::Sprite &sprite );

		private:
			Core::Window &window;
	};
}

#endif // CORE_RENDER_H
