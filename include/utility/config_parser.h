
#ifndef UTILITY_CONFIG_PARSER_H
#define UTILITY_CONFIG_PARSER_H

#include <map>

namespace Utility
{
	class ConfigParser
	{
	public:
		ConfigParser( const std::string &filename );
		~ConfigParser();

		//! \brief Opens a file and then extracts keys and their values.
		bool ReadFile();

		//! \brief Checks if filename exists.
		bool FileExists() const;

		//! \brief Retrieves a value for a specified key.
		std::string GetValue( const std::string &key ) const;

	private:
		//! \brief Parses a line and then extracts its contents.
		bool ParseLine( const std::string &line, const unsigned int &line_number );

		//! \brief Extracts the contents from a file.
		bool ExtractContents( const std::string &line );

		//! \brief Removes any comments from the line.
		void ParseComments( std::string &line ) const;

		//! \brief Returns true if no characters (except spaces) could be found in the line.
		bool OnlyWhitespace( const std::string &line ) const;

		//! \brief Checks whether the line is a valid configuration line (x = y).
		bool ValidLine( const std::string &line ) const;

		//! \brief Leaves only a key in the key string.
		void ExtractKey( std::string &key, const unsigned int &equal_pos, const std::string &line ) const;

		//! \brief Leaves only a value in the value string.
		void ExtractValue( std::string &value, const unsigned int &equal_pos, const std::string &line ) const;

		//! \brief Check if a key already exists.
		bool KeyExists( const std::string &key ) const;

		std::map<std::string, std::string> contents;	//!< Holds every configuration setting and its value.
		std::string filename;							//!< The filename this class is reading from.
	};
}

#endif // UTILITY_CONFIG_PARSER_H
