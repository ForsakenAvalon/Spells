
#ifndef UTILITY_STRING_H
#define UTILITY_STRING_H

#define Util Utility
#define uint unsigned int

// Include STL
#include <string>

namespace Utility
{
	class String : public std::string
	{
		public:
			String();
			String(const char * textString);
			String(String & textString);
			~String();
	};
}

#endif // UTILITY_STRING_H
