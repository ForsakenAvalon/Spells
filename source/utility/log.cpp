
#include "utility/log.h"

#include <sstream>
#include <fstream>

namespace Utility
{
	Log::Log( const char *filename )
	{
		this->name		= new Utility::String(filename);
		this->buffer	= new Utility::String();
	}

	Log::~Log()
	{
		delete this->name;
		delete this->buffer;
	}

	void Log::Write( const char *staticText )
	{
		*this->buffer += staticText;
	}

	void Log::Write( int value )
	{
		// If value is greater than max, print out of range.
		if ( value > 1000000 )
		{
			*this->buffer += "Value out of range!";
			return;
		}

		// Convert int to string and write to buffer.
		std::stringstream ss;
		ss << value;
		
		*this->buffer += ss.str();
	}

	void Log::Write( float value )
	{
		// If value is greater than max, print out of range.
		if( (value) > 1000000.f ) 
		{
			*this->buffer += "Value out of range!";
			return;
		}

		// Convert float to string and write to buffer.
		std::stringstream ss;
		ss << value;

		*this->buffer += ss.str();
	}

	void Log::EndLine()
	{
		std::fstream file("logs/" + *this->name, std::ios_base::app);
		
		*this->buffer += '\n';

		file.write(buffer->c_str(), buffer->size());
		file.close();
	}
}
