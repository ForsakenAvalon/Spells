
#include "utility/string.h"

namespace Utility
{
	String::String()
	{
	}

	String::String(const char * textStatic) : std::string(textStatic)
	{
	}

	String::String(Utility::String & textString)
	{
		*this = textString;
	}

	String::~String()
	{
	}
}
