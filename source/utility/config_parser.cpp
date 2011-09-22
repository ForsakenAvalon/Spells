
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
			Utility::Log log("config_parser.txt");
			log.Write("Couldn't open file.");
			log.EndLine();

			return false;
		}

		std::string line;
		unsigned int line_number = 0;
		bool run = true;

		while ( file.good() && run )
		{
			std::getline(file, line);

			line_number++;
			std::string temp = line;

			if ( !temp.empty() )
			{
				this->ParseComments(temp);
				if ( !this->OnlyWhitespace(temp) )
				{
					if ( !this->ParseLine(temp, line_number) )
						run = false;
				}
			}
		}

		file.close();
		if ( run )
			return true;
		
		return false;
	}

	bool ConfigParser::FileExists() const
	{
		std::ifstream file(this->filename);
		if ( !file.is_open() )
			return false;

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

			Utility::Log log("config_parser.txt");
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

			Utility::Log log("config_parser.txt");
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
			this->contents.insert(std::make_pair<std::string, std::string>(key, value));
			return true;
		}

		Utility::Log log("config_parser.txt");
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
		key.erase(0, key.find_first_not_of("\t "));
		key.erase(key.find_last_not_of("\t ") + 1);
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
