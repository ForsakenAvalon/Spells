
// static_entity.h
// inherits Utility::Vector

#ifndef ENTITIES_STATIC_ENTITY_H
#define ENTITIES_STATIC_ENTITY_H

#include "utility/vector.h"

namespace Entities
{
	//! /brief Represents a Static Object
	class StaticEntity : public Utility::Vector<int>
	{
		public:
			// Constructor
			StaticEntity(int x, int y);
			// Deconstructor
			~StaticEntity();

			// Member Functions
			//Vector<int> &	GetPos();
			//void			GetPos(int x, int y);
		protected:
			int z;
	};
}

#endif // ENTITIES_STATIC_ENTITY_H
