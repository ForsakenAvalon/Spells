
#ifndef UTILITY_RESOURCE_MANAGER_H
#define UTILITY_RESOURCE_MANAGER_H

#include <map>
#include <string>

// debug
#include <iostream>
// end debug

//
// Handled resource includes.
//
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

namespace Utility
{
	class ResourceManager
	{
	public:
		typedef std::map<std::string, void*>	ResourceMap;
		typedef std::map<std::string, int>		ResourceCount;

		ResourceManager();
		~ResourceManager();

		template< typename T >
		T* GetResource( const std::string &filename )
		{
			ResourceMap::const_iterator iter = this->resources.find(filename);
			if ( iter != this->resources.end() ) // If we have found a resource there is no need to load one.
			{
				this->resources_count[filename] += 1;
				return (T*) iter->second;
			}

			T* raw_resource = LoadResource<T>(filename); // Load a new resource.
			this->resources[filename]		= raw_resource;
			this->resources_count[filename] = 1;

			return (T*) this->resources[filename];
		}

		void KillResource( const std::string &filename ); // Will only kill a resource if it has zero references.

	private:
		template< typename T >
		T* LoadResource( const std::string &filename );

		ResourceMap		resources;
		ResourceCount	resources_count;
	};
}

#endif // UTILITY_RESOURCE_MANAGER_H
