
#ifndef UTILITY_STRING_H
#define UTILITY_STRING_H

#define Util Utility
#define uint unsigned int

// Not implemented yet
#define _MAX_STATIC_TEXT_SIZE_ 

namespace Utility
{
	class String
	{
		public:
			// Constructors
			String();
			String(unsigned int size);
			String(const char * textStatic);
			String(char * textBuffer);
			String(String & textString);
			// Deconstructors
			~String();
	
			String &    Copy        (const char * textStatic);
			String &    Copy        (String & textString);
			uint        Length      ();
			uint        Size        ();

			int         Find        (const char charStatic);
			int         Find        (char & charString);

			char   &    operator[]  (uint pointer);

			String &    operator=   (const char * textStatic);
			String &    operator=   (String & textString);

			String &	operator+	(const char * textStatic);
			String &	operator+	(String & textString);

			const char * ToTextStatic();

			static int GetLength(const char * textStatic);

		private:
			char    *   CharArray;
			uint        CharArraySize;
			uint        CharArrayLength;

			bool        isInit;
	};
}

#endif // UTILITY_STRING_H
