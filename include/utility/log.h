#ifndef UTILITY_LOG_H
#define UTILITY_LOG_H

// Include STL
#include <fstream>

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
		private:
			Util::String * name;
			Util::String * buffer;
	};
}

#endif //UTILITY_LOG_H