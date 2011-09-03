
#ifndef UTILITY_STRING_H
#define UTILITY_STRING_H

#define uint unsigned int

namespace Utility
{
	class String
	{
		public:
			// Constructors
			String();
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

			const char * ToTextStatic();

		private:
			char    *   CharArray;
			uint        CharArraySize;
			uint        CharArrayLength;

			bool        isInit;
	};
}

#endif // UTILITY_STRING_H
