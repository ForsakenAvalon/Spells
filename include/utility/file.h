
#ifndef UTILITY_FILE_H
#define UTILITY_FILE_H

#include "utility/string.h"

namespace Utility
{
	class File
	{
		public:
			// Constructors
			File(const char * staticFilePath);
			File(String & stringFilePath);
			// Deconstructors
			~File();

			int Write();
			int Write(const char * staticText);
			int Write(String & stringText);

			int Read();
			int Read(unsigned int pointer);
			int Read(char * charDelim);

			static bool DoesFileExist(String & stringFileName);
			static bool DoesFileExist(const char * staticFileName);

		private:
			String * Path;

			String * ReadBuffer;
			String * WriteBuffer;

			bool     IsOpen;
			bool     IsInit;
			bool     IsReadBufInit;
			bool     IsWriteBufInit;
	};
}

#endif // UTILITY_FILE_H
