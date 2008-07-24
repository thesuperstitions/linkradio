/*
 * Lance Earwood
 *
 * 16 August 2006
 *
 * FileReader.cpp
 *
 * Description:
 *      FileReader reads SIMPLE-J packets from a binary file.
 */

#include <cstdio>
#include <cstdlib>
#include <string>
//#include <unistd.h>
#include <stdio.h>
//#include <iostream>

#include "FileReader.h"
//#include "Sleep.h"
//#include "simple.h"


//------------------------------------------------------------------------------
// FileReader
// - Constructor
FileReader::FileReader (char *filename) : _firstMessage(true), _lastTime(0)
{

    // Open input file
    if (NULL == (_fp = fopen(filename, "rb"))) {
        printf ("Unable to open input file \"%s\".\n", filename);
    }

}


//------------------------------------------------------------------------------
// getNextPacket
// - Reads the next SIMPLE-J packet from the file
// - XXX:WARNING, this method may (will) delay the calling thread.  This is by
// -    design as it is meant to mimic async receipt of multicast data.
//
char * FileReader::getNextPacket ()
{
    static const int NETWORK_HEADER_SZ = sizeof(networkHeader_t);

    networkHeader_t networkHeader;      // First SIMPLE header
    char            *packet = NULL;     // Return value: Entire SIMPLE-J packet
    char            *data = NULL;       // Container for packet hdr and message
//    int             linkBytes = 0;      // Size of link data only
    int             numBytes = 0;       // Bytes after header
    long            secs = 0;
    long            nsecs = 0;
    int             timeDelay = 0;
    int*            start = 0;
//    bool            errorOccurred = false;


    // Read the time
    fread (&secs, sizeof(long), 1, _fp);
    fread (&nsecs, sizeof(long), 1, _fp);

    // Define the offset and the delay
    if (true == _firstMessage) {
        _lastTime = secs;
        timeDelay = 0;
        _firstMessage = false;
    } else {
        timeDelay = secs - _lastTime;
        _lastTime = secs;
    }

    // Read the SIMPLE Network Header
    if (fread (&networkHeader, NETWORK_HEADER_SZ, 1, _fp) != 1) {
        if (!feof(_fp)) {
            printf ("Error reading network header!  byte position=%d\n", ftell(_fp));
        }
        return (NULL);
    }

    // Read the remainder of the packet
    data = (char*)calloc(1, SIMPLE_PACKET_MAX_SIZE);
    if (NULL == data) {
        printf ("Unable to allocate space for packet!\n");
        return (NULL);
    }
    numBytes = networkHeader.length - NETWORK_HEADER_SZ;
    if (fread (data, numBytes, 1, _fp) != 1) {
        printf ("Unable to read network packet payload! byte position=%d\n", ftell(_fp));
        free (data);
        return (NULL);
    }

    // Allocate space for return parameter and copy data read from the file
    packet = (char*)calloc(1, SIMPLE_PACKET_MAX_SIZE);
    // Copy header
    start = (int*)packet;
    memcpy ((void*)start, &networkHeader, NETWORK_HEADER_SZ);
    // Copy packet header and message
    start += NETWORK_HEADER_SZ;
    memcpy ((void*)(start), data, numBytes);

    // Cleanup
    free (data);

    // Sleep
    //printf ("getNextPacket:sleeping %d secs...\n", timeDelay);
    //framework::utils::Sleep::sleep (timeDelay);

    return ( packet );

}


//------------------------------------------------------------------------------
// closeFile
// - Tries to close the input file.
// - Follows standard UNIX style: returns 0 on success, non-zero on error
int FileReader::closeFile()
{
    return ( fclose (_fp) );
}


//------------------------------------------------------------------------------
// packetsRemain
// - Returns boolean indicating if packets remain:
// - True = packets remain
// - False = No packets remain or an error has occured somewhere
bool FileReader::packetsRemain()
{
    return ( ! ( (0 != feof(_fp)) || (NULL == _fp)) );
}
