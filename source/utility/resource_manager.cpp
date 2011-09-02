
#include "utility/resource_manager.hpp"

namespace Yttrium
{
	namespace Utility
	{
		ResourceManager::ResourceManager()
		{

		}

		ResourceManager::~ResourceManager()
		{
			resources_.clear(); // Empty the map of resources.
		}

		template<>
		sf::Image* ResourceManager::LoadResource<sf::Image>(const std::string &filename)
		{
			sf::Image *image = new sf::Image();
			image->SetSmooth(false); // Pixel game!

			if ( image->LoadFromFile("resources/images/" + filename) )
				return image;
			
			delete image;
			return NULL;
		}
	}
}
