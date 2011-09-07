#ifndef VECTOR_BASE_H
#define VECTOR_BASE_H

namespace Base
{
	template< typename Prec >
	class Vector 
	{
		public:
			// Constructors
			Vector();
			Vector(Prec x, Prec y);
			// Deconstructors
			~Vector();

			Prec X() { return x; }
			Prec Y() { return y; }
			Vector & operator[] (Prec iX, Prec iY) 
			{
				x = iX;
				y = iY;
			}
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

#endif