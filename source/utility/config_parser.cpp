
#include "utility/config_parser.h"

#include "utility/log.h"

#include <sstream>
#include <fstream>

namespace Utility
{
	ConfigParser::ConfigParser( const std::string &filename )
		: filename(filename)
	{
		
	}

	ConfigParser::~ConfigParser()
	{

	}

	bool ConfigParser::ReadFile()
	{
		std::ifstream file(this->filename);
		if ( !file.is_open() )
		{
			Utility::Log log("config_parser.cpp");
			log.Write("Couldn't open file.");
			log.EndLine();

			return false;
		}

		std::string line;
		unsigned int line_number = 0;
		bool exit = false;

		while ( !file.eof() && !exit )
		{
			line_number++;
			std::string temp = line;

			if ( !temp.empty() )
			{
				this->ParseComments(temp);
				if ( !this->OnlyWhitespace(temp) )
				{
					if ( !this->ParseLine(temp, line_number) )
						exit = true;
				}
			}
		}

		file.close();
		if ( exit )
			return false;
		else
			return true;
	}

	std::string ConfigParser::GetValue( const std::string &key ) const
	{
		if ( !this->KeyExists(key) ) // If there isn't such a key return an empty string.
			return std::string();

		return this->contents.find(key)->second;
	}

	bool ConfigParser::ParseLine( const std::string &line, const unsigned int &line_number )
	{
		if ( line.find('=') == std::string::npos )
		{
			std::stringstream ss;
			ss << line_number;

			Utility::Log log("config_parser.cpp");
			log.Write("No equals seperator (");
			log.Write(ss.str().c_str());
			log.Write(").");
			log.EndLine();

			return false;
		}

		if ( !this->ValidLine(line) )
		{
			std::stringstream ss;
			ss << line_number;

			Utility::Log log("config_parser.cpp");
			log.Write("Invalid format (");
			log.Write(ss.str().c_str());
			log.Write(").");
			log.EndLine();

			return false;
		}

		if ( !this->ExtractContents(line) )
			return false;

		return true;
	}

	bool ConfigParser::ExtractContents( const std::string &line )
	{
		std::string temp = line;
		temp.erase(0, temp.find_first_not_of("\t "));
		unsigned int equal_pos = temp.find('=');

		std::string key, value;
		this->ExtractKey(key, equal_pos, temp);
		this->ExtractValue(value, equal_pos, temp);

		if ( !this->KeyExists(key) )
		{
			this->contents.insert(key, value);
			return true;
		}

		Utility::Log log("config_parser.cpp");
		log.Write("Duplicate key detected.");
		log.EndLine();

		return false;
	}

	void ConfigParser::ParseComments( std::string &line ) const
	{
		if ( line.find("//") != std::string::npos )
			line.erase(line.find("//"));
	}

	bool ConfigParser::OnlyWhitespace( const std::string &line ) const
	{
		return ( line.find_first_not_of(' ') == std::string::npos );
	}

	bool ConfigParser::ValidLine( const std::string &line ) const
	{
		std::string temp = line;
		temp.erase(0, temp.find_first_not_of("\t "));
		if ( temp[0] == '=' ) // Check that there is a key.
			return false;

		for ( unsigned int i = temp.find('=') + 1; i < temp.length(); i++ )
		{
			if ( temp[i] != ' ' ) // Check there is a value.
				return true;
		}

		return false; // The value was missing.
	}

	void ConfigParser::ExtractKey( std::string &key, const unsigned int &equal_pos, const std::string &line ) const
	{
		key = line.substr(0, equal_pos);
		if ( key.find('\t') != std::string::npos || key.find(' ') != std::string::npos )
			key.erase(key.find_first_of("\t "));
	}

	void ConfigParser::ExtractValue( std::string &value, const unsigned int &equal_pos, const std::string &line ) const
	{
		value = line.substr(equal_pos + 1);
		value.erase(0, value.find_first_not_of("\t "));
		value.erase(value.find_last_not_of("\t ") + 1);
	}

	bool ConfigParser::KeyExists( const std::string &key ) const
	{
		return ( this->contents.find(key) != this->contents.end() );
	}
}