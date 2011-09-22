
#ifndef UTILITY_RESOURCE_MANAGER_H
#define UTILITY_RESOURCE_MANAGER_H

#include <map>
#include <string>

namespace Utility
{
	//! \brief Loads and destroys resources
	class ResourceManager
	{
	public:
		typedef std::map<std::string, void*>	ResourceMap;
		typedef std::map<std::string, int>		ResourceCount;

		//! \brief Default constructor
		ResourceManager();

		//! \brief Default deconstrcutor
		~ResourceManager();

		//! \brief Creates or returns an existing resource
		//! 
		//! Filename is relative to the resource, e.g. when loading an
		//! image the resource manager will search for it in resources/images/.
		//! 
		//! Filename is also a unique identifier, no two resources should have
		//! the same filename.
		//! 
		//! \param filename Unique identifier and location of resource
		//! relative to resource type
		//! 
		//! \return New or existing resource of the specified type
		//! 
		//! \see KillResource
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

		//! \brief Attempts to destroy a resource
		//! 
		//! Will decrement the amount of references to a resource If the amount of 
		//! references to a resource reaches 0 then the resource is destroyed.
		//! 
		//! \param filename Unique identifier and location of resource
		//! relative to resource type
		//! 
		//! \see GetResource
		void KillResource( const std::string &filename );

	private:
		//! \brief Loads a resource depending on the specified resource type
		//! 
		//! \param filename Unique identifier and location of resource
		//! relative to resource type
		template< typename T >
		T* LoadResource( const std::string &filename );

		ResourceMap		resources;			//!< Contains all resources and their location/unique identifier
		ResourceCount	resources_count;	//!< Holds the amount of references to a resource
	};
}

#endif // UTILITY_RESOURCE_MANAGER_H

//! \class Utility::ResourceManager
//! \ingroup utility
//! 
//! Provides efficient resource managing by creating references to
//! a loaded image upon being created or retrieved. Destroyed when
//! a KillResource call is made and there are no more references.
