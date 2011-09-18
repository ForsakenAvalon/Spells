
#ifndef UTILITY_VECTOR_H
#define UTILITY_VECTOR_H

namespace Utility
{
	template< typename T >
	class Vector
	{
	public:
		Vector()
		{
			this->x = 0;
			this->y = 0;
		}

		Vector( T x, T y )
		{
			this->x = x;
			this->y = y;
		}

		~Vector()
		{

		}

		T x;
		T y;
	};
}

#endif // UTILITY_VECTOR_H
