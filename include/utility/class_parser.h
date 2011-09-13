
#ifndef UTILITY_CLASS_PARSER_H
#define UTILITY_CLASS_PARSER_H

#include <string>
#include <fstream>
#include <assert.h>

namespace Utility
{
	//! \brief Writes and reads classes to and from files.
	class ClassParser
	{
	public:
		ClassParser();
		~ClassParser();

		template< typename T >
		bool WriteClass( T *a_class, std::string &filename )
		{
			std::ofstream output(filename, std::ios::binary);
			if ( !output )
				return false;

			output.write(reinterpret_cast< char* >(a_class), sizeof(*a_class));
			output.close();

			return true;
		}

		template< typename T >
		bool WriteClass( T *a_class, const char *filename )
		{
			std::ofstream output(filename, std::ios::binary);
			if ( !output )
				return false;

			output.write(reinterpret_cast< char* >(a_class), sizeof(*a_class));
			output.close();

			return true;
		}

		template< typename T >
		T* ReadClass( std::string &filename )
		{
			std::ifstream input(filename, std::ios::binary);
			if ( !input )
				return NULL;

			T *class_holder = new T();

			input.read(reinterpret_cast< char* >(class_holder), sizeof(*class_holder));
			input.close();
			return class_holder;
		}

		template< typename T >
		T* ReadClass( const char *filename )
		{
			std::ifstream input(filename, std::ios::binary);
			if ( !input )
				return NULL;

			T *class_holder = new T();

			input.read(reinterpret_cast< char* >(class_holder), sizeof(*class_holder));
			input.close();
			return class_holder;
		}

	private:

	};
}

#endif // UTILITY_CLASS_PARSER_H
