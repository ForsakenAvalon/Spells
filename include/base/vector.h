#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

namespace Base
{
	template< typename Prec >
	class Vector 
	{
		public:
			// Constructors
			Vector()
			{
				x = 0;
				y = 0;
			}
			Vector(Prec iX, Prec iY)
			{
				x = iX;
				y = iY;
			}
			// Deconstructors
			~Vector()
			{
			}

			Prec X() { return x; }
			Prec Y() { return y; }

            Prec x() { return x; }
            Prec y() { return y; }
			
			Vector & operator=  (Vector & vector)
			{
				x = vector.X;
				y = vector.Y;
			}
		protected:
			Prec x;
			Prec y;
	};
}

#endif // BASE_VECTOR_H
