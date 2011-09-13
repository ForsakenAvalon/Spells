
#include "base/vector.h"

namespace Base
{
	template< typename T >
	inline Vector<T>::Vector()
		: x(0)
		, y(0)
	{

	}

	template< typename T >
	inline Vector<T>::Vector( T x, T y )
		: x(x)
		, y(y)
	{

	}
}
