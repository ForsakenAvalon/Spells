
#ifndef UTILITY_RESOURCE_MANAGER_H
#define UTILITY_RESOURCE_MANAGER_H

#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

#include <map>
#include <string>

//
// Handled resource includes.
//
#include <SFML/Graphics/Image.hpp>
typedef boost::shared_ptr<sf::Image> ImageRes; // Used outside of this file for this class.
#include <SFML/Graphics/Font.hpp>
typedef boost::shared_ptr<sf::Font> FontRes;
#include <SFML/Graphics/Shader.hpp>
typedef boost::shared_ptr<sf::Font> ShaderRes;
#include <SFML/Audio/SoundBuffer.hpp>
typedef boost::shared_ptr<sf::Font> SoundBufferRes;
#include <SFML/Audio/Music.hpp>
typedef boost::shared_ptr<sf::Font> MusicRes;

namespace Utility
{
	class ResourceManager
	{
	public:
		typedef std::map<std::string, boost::any> ResourceMap;

		ResourceManager();
		~ResourceManager();

		template< typename T >
		boost::shared_ptr<T> GetResource(const std::string &filename)
		{
			ResourceMap::iterator iter = resources_.find(filename);
			if ( iter != resources_.end() ) // If we have found a resource there is no need to load one.
				return boost::any_cast<boost::shared_ptr<T>>(iter->second);

			T* raw_resource = LoadResource<T>(filename); // Load a new resource.
			resources_[filename] = boost::shared_ptr<T>(raw_resource);

			return boost::any_cast<boost::shared_ptr<T>>(resources_[filename]);
		}

	private:
		template< typename T >
		T* LoadResource(const std::string &filename);

		ResourceMap resources_;
	};
}

#endif // UTILITY_RESOURCE_MANAGER_H
