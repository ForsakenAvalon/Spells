
// renderer.h
// Handles the rendering of all visible game objects.

#ifndef ENGINE_RENDER_H
#define ENGINE_RENDER_H

#include <SFML/Graphics/Sprite.hpp>

namespace Core
{
	class Window;
}

namespace GUI
{
	class Button;
}

namespace Engine
{
	class Render
	{
		public:
			Render( Core::Window &window );
			~Render();

			void RenderSprite( sf::Sprite &sprite );
			void RenderButton( GUI::Button &button );

		private:
			Core::Window &window;
	};
}

#endif // ENGINE_RENDER_H
