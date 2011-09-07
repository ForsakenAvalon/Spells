// include/base/entity.h
// inherits Vector in include/base/vector.h

#ifndef STATIC_ENTITY_BASE_H
#define STATIC_ENTITY_BASE_H

#include "vector.h"

namespace Base
{
	//! /brief Represents a Static Object
	class StaticEntity : public Vector<int>
	{
		public:
			// Constructor
			StaticEntity(int x, int y);
			// Deconstructor
			~StaticEntity();

			// Member Functions
			Vector<int> &	GetPos();
			void			GetPos(int x, int y);
		protected:
			int z;
	};
}

#endif