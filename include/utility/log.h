#ifndef UTILITY_LOG_H
#define UTILITY_LOG_H

// Define Max Numerical Write Value
#define _MAX_LOG_INT_VALUE		1000000
#define _MAX_LOG_FLOAT_VALUE	1000000

// Include STL
#include <fstream>
#include <sstream>

// Include Util
#include "utility/string.h"

namespace Utility
{
	class Log
	{
		public:
			//Constructors
			Log(const char * fileName);
			//Deconstructors
			~Log();

			void Write(const char * staticText);
			void Write(float value);
			void Write(int value);
			void EndLine();
		private:
			Util::String * name;
			Util::String * buffer;
	};
}

#endif //UTILITY_LOG_H