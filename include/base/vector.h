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
				local_x = 0;
				local_y = 0;
			}
			Vector(Prec x, Prec y)
			{
				local_x = x;
				local_y = y;
			}
			// Deconstructors
			~Vector()
			{

			}

			Prec X() { return local_x; }
			Prec Y() { return local_y; }

            Prec x() { return local_x; }
            Prec y() { return local_y; }
			
			Vector & operator=  (Vector & vector)
			{
				local_x = vector.X;
				local_y = vector.Y;
			}

		protected:
			Prec local_x;
			Prec local_y;
	};
}

#endif // BASE_VECTOR_H
