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
		*buffer += staticText;
	}

	void Log::Write(int value)
	{
		// If value is greater than max, print out of range
		if (value > _MAX_LOG_INT_VALUE) {
			*buffer += "Value Out Of Range!";
		}
		else {
			// Convert int to str and write to buffer
			char * temp = new char[6];
			_itoa_s(value, temp, 6, 10);

			// Clean up temp before writing to buffer
			for (uint x = 0; x < 7; x++) {
				if (temp[x] != '0' && temp[x] != '1' && temp[x] != '2' && temp[x] != '3' && temp[x] != '4' && temp[x] != '5' && temp[x] != '6' && temp[x] != '7' && temp[x] != '8' && temp[x] != '9') {
					temp[x] = ' ';
				}
			}

			for (uint x = 0; x < 7; x++) {
				*buffer += temp[x];
			}
		}
	}

	void Log::Write(float value)
	{
		if((value) > _MAX_LOG_FLOAT_VALUE) {
			*buffer += "Value Out Of Range!";
		}
		else {
			std::stringstream ss (std::stringstream::in | std::stringstream::out);
			ss << value;
			*buffer += ss.str();
		}
	}

	void Log::EndLine()
	{
		std::fstream file((*name),std::ios_base::app, 64);
		
		*buffer += '\n';

		file.write(buffer->c_str(),buffer->size());
		file.close();
	}
}

