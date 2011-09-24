
#include "utility/resource_manager.h"

#include "utility/log.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

namespace Utility
{
	ResourceManager::ResourceManager()
	{

	}

	ResourceManager::~ResourceManager()
	{
		if ( this->resources.empty() )
		{
			this->resources.clear();		// Empty the map of resources.
			this->resources_count.clear();	// Empty the map of resource counts.
		}
		else
		{
			Utility::Log log("resource_manager.txt");
			log.Write("Warning, not all resources have been destroyed: ");
			log.EndLine();

			for ( ResourceMap::const_iterator iter = this->resources.begin(); iter != this->resources.end(); iter++ )
			{
				log.Write("\t");
				log.Write(iter->first.c_str());
				log.EndLine();
			}
		}
	}

	void ResourceManager::KillResource( const std::string &filename )
	{
		
		{
			ResourceCount::const_iterator iter = this->resources_count.find(filename);
			if ( iter == this->resources_count.end() )
				return;
		}
		
		this->resources_count[filename] -= 1;
		if ( this->resources_count[filename] != 0 )
			return;
		
		{
			ResourceMap::const_iterator iter = this->resources.find(filename);
			if ( iter == this->resources.end() )
				return;
		}
		
		delete this->resources[filename];
		this->resources.erase(filename);
		this->resources_count.erase(filename);
		
	}

	template<>
	sf::Texture* ResourceManager::LoadResource<sf::Texture>( const std::string &filename )
	{
		sf::Texture *texture = new sf::Texture();
		texture->SetSmooth(false); // Pixel game!

		if ( texture->LoadFromFile("resources/images/" + filename) )
			return texture;
		
		delete texture;
		return NULL;
	}

	template<>
	sf::Font* ResourceManager::LoadResource<sf::Font>( const std::string &filename )
	{
		sf::Font *font = new sf::Font();

		if ( font->LoadFromFile("resources/fonts/" + filename) )
			return font;

		delete font;
		return NULL;
	}

	template<>
	sf::Shader* ResourceManager::LoadResource<sf::Shader>( const std::string &filename )
	{
		sf::Shader *shader = new sf::Shader();

		if ( shader->LoadFromFile("resources/shaders/" + filename) )
			return shader;
		
		delete shader;
		return NULL;
	}

	/*template<>
	sf::SoundBuffer* ResourceManager::LoadResource<sf::SoundBuffer>( const std::string &filename )
	{
		sf::SoundBuffer *sound_buffer = new sf::SoundBuffer();

		if ( sound_buffer->LoadFromFile("resources/sounds/" + filename) )
			return sound_buffer;

		delete sound_buffer;
		return NULL;
	}

	template<>
	sf::Music* ResourceManager::LoadResource<sf::Music>( const std::string &filename )
	{
		sf::Music *music = new sf::Music();

		if ( music->OpenFromFile("resources/music/" + filename) )
			return music;

		delete music;
		return NULL;
	}*/
}
