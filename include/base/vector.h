
#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

namespace Base
{
	template< typename T >
	class Vector
	{
	public:
		Vector();
		Vector( T x, T y );

		~Vector();

		T x;
		T y;
	};
}

#endif // BASE_VECTOR_H
