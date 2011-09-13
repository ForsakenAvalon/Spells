
#include "engine/render.h"

#include "core/window.h"
#include "gui/button.h"

namespace Engine
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

	void Render::RenderButton( GUI::Button &button )
	{
		this->window.RenderWindow().Draw(button);
	}
}
