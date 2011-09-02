#ifndef DFILE_H
#define DFILE_H

#include "string.h"
#include <fstream>

class File
{
    public:
        // Constructors
        File(const char * staticFilePath);
        File(String & stringFilePath);
        // Deconstructors
        ~File();

        int Write();
        int Write(const char * staticText);
        int Write(String & stringText);

        int Read();
        int Read(uint pointer);
        int Read(char * charDelim);

        static bool DoesFileExist(String & stringFileName);
        static bool DoesFileExist(const char * staticFileName);

    private:
        String * Path;

        String * ReadBuffer;
        String * WriteBuffer;

        std::ios_base WriteMode;

        bool     IsOpen;
        bool     IsInit;
        bool     IsReadBufInit;
        bool     IsWriteBufInit;
};

#endif
