
#ifndef BASE_SCREEN_H
#define BASE_SCREEN_H

#include "base/static_entity.h"
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
	};
}

#endif // BASE_SCREEN_H
