
#ifndef BASE_SCREEN_H
#define BASE_SCREEN_H

#include <list>

namespace Entities
{
	class StaticEntity;
}

namespace Core
{
	class Screen
	{
		public:
			Screen();
			~Screen();

			bool AddEntity( Entities::StaticEntity & entity );
		private:
	};
}

#endif // BASE_SCREEN_H
