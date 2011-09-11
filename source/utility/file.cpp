
#include "utility/file.h"

namespace Utility
{
	File::File(const char * staticFilePath)
	{
		if (DoesFileExist(staticFilePath)) {
			Path = new String(staticFilePath);
			IsOpen = false;
			IsInit = false;
			IsReadBufInit = false;
			IsWriteBufInit = false;
		}
		else {
			// Error Flag Set
		}
	}

	File::File(String &stringFilePath)
	{
		if (DoesFileExist(stringFilePath)) {
			Path = new String(stringFilePath);
			IsOpen = false;
			IsInit = false;
			IsReadBufInit = false;
			IsWriteBufInit = false;
		}
		else {
			// Error Flag Set
		}
	}

	File::~File()
	{
		delete [] Path;

		if (IsReadBufInit) {
			delete ReadBuffer;
		}
		else {
			ReadBuffer = 0;
		}

		if (IsWriteBufInit) {
			delete WriteBuffer;
		}
		else {
			WriteBuffer = 0;
		}
	}

	bool File::DoesFileExist(const char *staticFileName)
	{
		std::ifstream file(staticFileName);
		return file;
	}

	bool File::DoesFileExist(String &stringFileName)
	{
		std::ifstream file(stringFileName);
		return file;
	}

	int File::Write(String &stringText)
	{
		std::ofstream file(stringText,std::ios_base::app);

		if (!IsWriteBufInit) {
			WriteBuffer = new String(stringText);
			IsWriteBufInit = true;
		}
		else {
			*WriteBuffer = stringText;
		}


		file.close();

		return 0;
	}
}
