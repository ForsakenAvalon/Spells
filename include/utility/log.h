
#ifndef UTILITY_LOG_H
#define UTILITY_LOG_H

#include "utility/string.h"

namespace Utility
{
	class Log
	{
		public:
			//! \brief Constructor
			//! 
			//! Creates a new log file with the specified filename.
			//! 
			//! \param filename Name of the file to write to
			Log( const char *filename );

			//! \brief Default deconstructor
			~Log();

			//! \brief Add data to the buffer
			//! 
			//! Calling EndLine after writing data will cause
			//! all data stored since the last EndLine to be
			//! written to the log file.
			//! 
			//! \param staticText Text to add to the buffer
			//! 
			//! \see EndLine
			void Write( const char *staticText );

			//! \brief Add data to the buffer
			//! 
			//! Calling EndLine after writing data will cause
			//! all data stored since the last EndLine to be
			//! written to the log file.
			//! 
			//! \param value Float to add to the buffer
			//! 
			//! \see EndLine
			void Write( float value );

			//! \brief Add data to the buffer
			//! 
			//! Calling EndLine after writing data will cause
			//! all data stored since the last EndLine to be
			//! written to the log file.
			//! 
			//! \param value Integer to add to the buffer
			//! 
			//! \see EndLine
			void Write( int value );

			//! \brief Writes a line
			//! 
			//! Causes all data passed into the class through
			//! Write functions since the last EndLine call
			//! to be written to the file.
			//! 
			//! \see Write
			void EndLine();

		private:
			Utility::String *name;		//!< Stores the name of this file
			Utility::String *buffer;	//!< Stores the current un-written line
	};
}

#endif // UTILITY_LOG_H

//! \class Utility::Log
//! \ingroup utility
//! 
//! Opens a file for logging and then provides the functionality to write to it
//! using a buffer interface.
