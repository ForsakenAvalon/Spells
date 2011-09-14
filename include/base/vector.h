
#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

namespace Base
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

#endif // BASE_VECTOR_H
