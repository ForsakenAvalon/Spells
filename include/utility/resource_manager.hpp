
#ifndef UTILITY_RESOURCE_MANAGER
#define UTILITY_RESOURCE_MANAGER

#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

#include <map>
#include <string>

//
// Handled resource includes.
//
#include <SFML/Graphics/Image.hpp>
typedef boost::shared_ptr<sf::Image> ImageRes; // Used outside of this file for this class.

namespace Yttrium
{
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
}

#endif // UTILITY_RESOURCE_MANAGER
