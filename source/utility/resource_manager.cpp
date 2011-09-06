
<<<<<<< HEAD
#include "utility/resource_manager.h"
=======
#include "utility/resource_manager.hpp"
>>>>>>> 22cb710905185047480f77f4a09522eeffa1f60a

namespace Utility
{
	ResourceManager::ResourceManager()
	{

	}

	ResourceManager::~ResourceManager()
	{
<<<<<<< HEAD
		this->resources.clear(); // Empty the map of resources.
	}

	void ResourceManager::KillResource( const std::string &filename )
	{
		{
			ResourceCount::iterator iter = this->resources_count.find(filename);
			if ( iter == this->resources_count.end() )
				return;
		}

		this->resources_count[filename] -= 1;
		if ( this->resources_count[filename] != 0 )
			return;

		{
			ResourceMap::iterator iter = this->resources.find(filename);
			if ( iter == this->resources.end() )
				return;
		}
		
		delete this->resources[filename];
		this->resources.erase(filename);
		this->resources_count.erase(filename);
=======
		resources_.clear(); // Empty the map of resources.
>>>>>>> 22cb710905185047480f77f4a09522eeffa1f60a
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

	template<>
	sf::Font* ResourceManager::LoadResource<sf::Font>(const std::string &filename)
	{
		sf::Font *font = new sf::Font();

		if ( font->LoadFromFile("resources/fonts/" + filename) )
			return font;

		delete font;
		return NULL;
	}

	template<>
	sf::Shader* ResourceManager::LoadResource<sf::Shader>(const std::string &filename)
	{
		sf::Shader *shader = new sf::Shader();

		if ( shader->LoadFromFile("resources/shaders/" + filename) )
			return shader;
		
		delete shader;
		return NULL;
	}

	template<>
	sf::SoundBuffer* ResourceManager::LoadResource<sf::SoundBuffer>(const std::string &filename)
	{
		sf::SoundBuffer *sound_buffer = new sf::SoundBuffer();

		if ( sound_buffer->LoadFromFile("resources/sounds/" + filename) )
			return sound_buffer;

		delete sound_buffer;
		return NULL;
	}

	template<>
	sf::Music* ResourceManager::LoadResource<sf::Music>(const std::string &filename)
	{
		sf::Music *music = new sf::Music();

		if ( music->OpenFromFile("resources/music/" + filename) )
			return music;

		delete music;
		return NULL;
	}
}
