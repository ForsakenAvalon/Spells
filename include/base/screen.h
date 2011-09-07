
#ifndef SCREEN_BASE_H
#define SCREEN_BASE_H

#include "static_entity.h"
#include <list>

namespace Base
{
	class Screen 
	{
		public:
			Screen();
			~Screen();

			bool AddEntity(StaticEntity & entity);
		private:
			std::list<StaticEntity> _static;
	};
}

#endif