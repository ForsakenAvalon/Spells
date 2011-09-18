
#include "core/render.h"

#include "core/window.h"
#include "gui/button.h"

namespace Core
{
	Render::Render( Core::Window &window )
		: window(window)
	{

	}

	Render::~Render()
	{
		
	}

	void Render::RenderSprite( sf::Sprite &sprite )
	{
		this->window.RenderWindow().Draw(sprite);
	}
}
