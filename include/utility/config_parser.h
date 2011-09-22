
#ifndef UTILITY_CONFIG_PARSER_H
#define UTILITY_CONFIG_PARSER_H

#include <map>

namespace Utility
{
	//! \brief Parses a configuration file
	class ConfigParser
	{
	public:
		//! \brief Constructor
		//! 
		//! Creates a new config parses which reads/writes from/to
		//! filename.
		//! 
		//! \param File to read/write from
		ConfigParser( const std::string &filename );

		//! \brief Default deconstructor
		~ConfigParser();

		//! \brief Opens a file and then extracts keys and their values
		//! 
		//! \return False if file couldn't be read
		bool ReadFile();

		//! \brief Checks if filename exists
		//! 
		//! \return False if file doesn't exist
		bool FileExists() const;

		//! \brief Retrieves a value for a specified key
		//! 
		//! \param key Unique key code
		//! 
		//! \return Value for the specified key (or an empty 
		//! string if the key doesn't exist).
		std::string GetValue( const std::string &key ) const;

	private:
		//! \brief Parses a line and then extracts its contents
		//! 
		//! \param line			Line to parse
		//! \param line_number	Number of the line (used for debugging)
		//! 
		//! \return False if the line couldn't be parsed
		bool ParseLine( const std::string &line, const unsigned int &line_number );

		//! \brief Extracts the contents from a file
		//! 
		//! \param line Line to extract contents from
		//! 
		//! \return False if contents couldn't be extracted
		bool ExtractContents( const std::string &line );

		//! \brief Removes any comments from the line
		//! 
		//! \param line Line to remove comments from
		void ParseComments( std::string &line ) const;

		//! \brief Returns true if no characters (except spaces) could be found in the line
		//! 
		//! \param line Line to check for only whitespace
		//! 
		//! \return False if the line contains characters
		bool OnlyWhitespace( const std::string &line ) const;

		//! \brief Checks whether the line is a valid configuration line (x = y)
		//! 
		//! \param line Line to validate
		//! 
		//! \return True if the line is valid
		bool ValidLine( const std::string &line ) const;

		//! \brief Leaves only a key in the key string
		//! 
		//! \param key			Variable to contain the filtered key
		//! \param equal_pos	Position of the equals sign
		//! \param line			Line to extract the key from
		void ExtractKey( std::string &key, const unsigned int &equal_pos, const std::string &line ) const;

		//! \brief Leaves only a value in the value string
		//! 
		//! \param value		Variable to contain the filtered value
		//! \param equal_pos	Position of the equals sign
		//! \param line			Line to extract the value from
		void ExtractValue( std::string &value, const unsigned int &equal_pos, const std::string &line ) const;

		//! \brief Check if a key already exists
		//! 
		//! \param key Key to check existance of
		//! 
		//! \return True if key exists
		bool KeyExists( const std::string &key ) const;

		std::map<std::string, std::string> contents;	//!< Holds every configuration setting and its value
		std::string filename;							//!< The filename this class is reading from
	};
}

#endif // UTILITY_CONFIG_PARSER_H

//! \class Utility::ConfigParser
//! \ingroup utility
//! 
//! Parses a configuration file; a file which is stored in
//! plain text that can be edited easily by a user.
