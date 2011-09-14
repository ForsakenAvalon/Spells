
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
			local_x = 0;
			local_y = 0;
		}

		Vector( T x, T y )
		{
			local_x = x;
			local_y = y;
		}

		~Vector()
		{

		}

		T local_x;
		T local_y;
	};
}

#endif // BASE_VECTOR_H
