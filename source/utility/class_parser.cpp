
#include "utility/class_parser.h"

namespace Utility
{
	ClassParser::ClassParser()
	{

	}

	ClassParser::~ClassParser()
	{

	}

	/*template< typename T >
	bool ClassParser::WriteClass( T* a_class, std::string &filename )
	{
		std::ofstream output(filename, std::ios::binary);
		output.write(reinterpret_cast< const char* >(a_class), sizeof(*a_class));
		output.close();
	}

	template< typename T >
	T* ClassParser::ReadClass( std::string &filename )
	{
		std::ifstream input(filename, std::ios::binary);
		if ( !input )
			return false;

		T* ClassHolder();

		input.read(reinterpret_cast< const char* >(ClassHolder), sizeof(*ClassHolder));
		input.close();
	}*/
}
