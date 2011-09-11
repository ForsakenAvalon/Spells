#include "utility/log.h"

namespace Utility
{
	Log::Log(const char * fileName)
	{
		name = new String(fileName);
		buffer = new String;
	}

	Log::~Log()
	{
		delete name;
		delete buffer;
	}

	void Log::Write(const char * staticText)
	{

	}
}

