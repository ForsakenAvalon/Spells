
#ifndef UTILITY_STRING_H
#define UTILITY_STRING_H

#include <string>

namespace Utility
{
	class String : public std::string
	{
		public:
			String();
			String(const char * textString);
			String(Utility::String & textString);
			~String();
	};
}

#endif // UTILITY_STRING_H
