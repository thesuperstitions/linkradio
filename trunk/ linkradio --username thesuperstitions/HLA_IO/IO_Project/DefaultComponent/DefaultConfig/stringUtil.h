/*******************************************************************************
** Copyright (c) 2004 MaK Technologies, Inc.
** All rights reserved.
*******************************************************************************/
/*******************************************************************************
** $RCSfile: stringUtil.h,v $ $Revision: 1.4 $ $State: Exp $
*******************************************************************************/

#ifndef stringUtil_H_
#define stringUtil_H_

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

// Convert narrow C string to wide string
inline wstring DtToWString(const char * in_val)
{
   wstring temp;
   while (*in_val != '\0')
   temp += *in_val++;
   return temp;
}

// Convert narrow string to wide string
inline string DtToString(const wstring &in_val)
{
   string temp;
   wstring::const_iterator b = in_val.begin();
   const wstring::const_iterator e = in_val.end();
   while (b != e)
   {
      temp += static_cast<char>(*b);
      ++b;
   }
   return temp;
}


inline string usage()
{
   ostringstream ostr;
   ostr << "Usage: simple(d) [-fedFile fedFileName][-m #Federates][-phaseLine #][-sleepTime s][-dedicated][-unManaged]"
        << endl << endl

        << setw( 20 ) << " -fedFile "
        << " Specify the Fed file name \n"
        << setw ( 24 ) << " " << "Default : MAKsimple.xml/fed. \n"     
      
        << setw( 20 ) << " -s "
        << " Specify whether this federate is the server and if so, how many \n"
        << setw( 24 ) << " " << "total federates it should wait for. \n"

        << setw( 20 ) << " -time "
        << " Specify whether time management is turned on (the feds become TCTR.\n"
        << setw( 24 ) << " " << "0=false, any other int=true\n"
        << setw( 24 ) << " " << "Default is false \n"
        
        << setw( 20 ) << " -tick "
        << " Specify whether to call RTI tick() or not.\n"
         << setw( 24 ) << " " << "needed if callbacks from RTI are synchronous with main app\n"
        << setw( 24 ) << " " << "0=false, any other int=true\n"
        << setw( 24 ) << " " << "Default is false \n"

        << setw( 20 ) << " -sleepTime "
        << " Specify the time in ms to sleep between iterations of the main loop. \n"
        << setw( 24 ) << " " << "  Default is 850 ms. \n"
		      
        << setw( 20 ) << " -dedicated "
        << " Specify whether this federate is on a machine dedicated to running\n"
        << setw( 24 ) << " " 
        << " this federate.  Invalidates all sleeps and yields.  Default is true\n"
                
        << setw( 20 ) << " -unManaged "
        << " Specify whether this federate will respect the synchronization step\n"
        << setw( 24 ) << " " << " before time advancing.\n"

        << endl; 
   return ostr.str();
}

template< class T > 
bool convert( const string& param,
             const string& value,
             T& dest )
{
   istringstream convert( value );
   convert >> dest;
   if ( convert.fail() )
   {
      std::cout << "Bad Parameter Value\n"
         << "Param: " << param
         << "\tValue: " << value << endl;
      return false;
   }
   return true;
}


#endif

