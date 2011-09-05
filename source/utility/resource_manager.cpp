
#include "utility/resource_manager.hpp"

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
