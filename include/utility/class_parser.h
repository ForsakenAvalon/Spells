
#ifndef UTILITY_CLASS_PARSER_H
#define UTILITY_CLASS_PARSER_H

#include <string>
#include <fstream>

namespace Utility
{
	//! \brief Writes and reads classes to and from files
	class ClassParser
	{
	public:
		//! \brief Default constructor
		ClassParser();

		//! \brief Default deconstructor
		~ClassParser();

		//! \brief Write the specified class to a file
		//! 
		//! \param a_class	Class to write
		//! \param filename Filename to write class to
		//! 
		//! \return False if class couldn't be written
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

		//! \brief Write the specified class to a file
		//! 
		//! \param a_class	Class to write
		//! \param filename Filename to write class to
		//! 
		//! \return False if class couldn't be written
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

		//! \brief Read a class from the specified file
		//! 
		//! \param filename Filename to read class from
		//! 
		//! \return Class read from file, NULL if no class could be read
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

		//! \brief Read a class from the specified file
		//! 
		//! \param filename Filename to read class from
		//! 
		//! \return Class read from file, NULL if no class could be read
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
	};
}

#endif // UTILITY_CLASS_PARSER_H

//! \class Utility::ClassParser
//! \ingroup utility
//! 
//! Parses a class to or from a file. Classes written to files in
//! this way will not be editable by a user as if they were a text
//! file. Instead use Utility::ConfigParser.
