
#include "entities/static_entity.h"

namespace Entities
{
	StaticEntity::StaticEntity(int x, int y) : Utility::Vector<int>(x, y)
	{
		z = 0;
	}

	StaticEntity::~StaticEntity()
	{
	}

	/*Vector<int> & StaticEntity::GetPos()
	{
		return *this;
	}

	void StaticEntity::GetPos(int x, int y)
	{
		x = this->x;
		y = this->y;
	}*/
}
