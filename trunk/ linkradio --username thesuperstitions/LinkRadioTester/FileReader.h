#ifndef _FILE_READER_H
#define _FILE_READER_H


/*
 * Lance Earwood
 *
 * 16 August 2006
 *
 * FileReader.h
 *
 * Description:
 *      FileReader reads SIMPLE-J packets from a binary file.
 *
 */


#include <stdio.h>
#include "simple.h"


class FileReader
{

    public:

        // Constructors
        FileReader (char *filename);

        // SIMPLE-J file parser
        char * getNextPacket();
        

        // Any more SIMPLE-J packets in the file?
        bool packetsRemain();

        // Close input file
        int closeFile();


    private:

        // File pointer to SIMPLE-J DX file
        FILE *_fp;
        
        // Boolean indicating that the first message has been
        // read from the DX file
        bool _firstMessage;

        // Last time read from the DX file
        long _lastTime;

};


#endif
