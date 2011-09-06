
#include "utility/string.h"

namespace Utility
{
	String::String()
	{
		isInit = false;
	}

	String::String(const char *textStatic)
	{
		this->Copy(textStatic);
	}

	String::String(String &textString)
	{
		this->Copy(textString);
	}

	String::~String()
	{
		delete [] CharArray;
	}

	String & String::Copy(const char *textStatic)
	{
		uint inTextSize = 0;
		uint pointer = 0;

		while(textStatic[pointer] == '\0') {
			inTextSize++;
			pointer++;
		}

		CharArray = new char[inTextSize];
		CharArraySize = inTextSize;
		CharArrayLength = inTextSize - 1;

		for (uint pointer = 0; pointer < inTextSize + 1; pointer++) {
			CharArray[pointer] = textStatic[pointer];
		}

		return *this;
	}

	String & String::Copy(String &textString)
	{
		this->Copy(textString.ToTextStatic());
		return *this;
	}

	uint String::Length()
	{
		return CharArrayLength;
	}

	uint String::Size()
	{
		return CharArraySize;
	}

	char & String::operator[](uint pointer)
	{
		return (CharArray[pointer]);
	}

	String & String::operator =(const char * textStatic)
	{
		return this->Copy(textStatic);
	}

	String & String::operator =(String & textString)
	{
		this->Copy(textString);
		return *this;
	}

	const char * String::ToTextStatic()
	{
		return (const_cast<char *> (this->CharArray));
	}
}
