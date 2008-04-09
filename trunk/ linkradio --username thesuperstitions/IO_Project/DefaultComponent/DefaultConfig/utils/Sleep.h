/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: __framework_utils_Sleep__H
//!	Generated Date	: Thu, 3, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\utils\Sleep.h
*********************************************************************/


#ifndef utils_Sleep_H 

#define utils_Sleep_H 

// dependency ctime 
#include <ctime>
// dependency Exception 
#include "framework\utils\Exception.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include <oxf/oxf.h>
#include <algorithm>
// operation sleep(const timespec &,const bool) 
#include <timespec.h>

//----------------------------------------------------------------------------
// utils\Sleep.h                                                                  
//----------------------------------------------------------------------------

class timespec;

//## attribute ::ReverseEngineering::TopLevel.__framework_utils_Sleep__H 
#define __framework_utils_Sleep__H 
//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace utils {
        //## class Sleep 
        class Sleep  {
        
        
        ////    Operations    ////
        public :
            
            //## operation sleep(const timespec &,const bool) 
            inline static void sleep(const timespec & request, const bool interposition_safe = false) {
                //#[ operation sleep(const timespec &,const bool) 
                #ifdef UNIX
                
                	
                	
                	if (!interposition_safe)
                	{
                		struct timespec remaining;
                		if (nanosleep(&request, &remaining) == -1)
                		{
                			throw framework::utils::Exception("sleep failed");
                		}
                	}
                	else
                	{
                	
                		const static struct timespec INTERPOSITION_SAFE_SLEEP  = {-1,-1};
                		if (nanosleep(&request, const_cast<struct timespec*>(&INTERPOSITION_SAFE_SLEEP))==-1)
                		{
                			throw framework::utils::Exception("sleep failed");
                		}
                	
                	}
                #elif defined WIN32
                
                	// TODO use a higher-res sleep at some point.
                	time_t numberMilliseconds = request.tv_sec*MILLISECONDS_PER_SECOND;
                	
                	// in this case the truncation shouldn't matter because windows
                	// timer using Sleep is not that precise.
                	numberMilliseconds += (request.tv_nsec / NANOSECONDS_PER_MILLISECOND);
                	
                	::Sleep(static_cast<DWORD>(numberMilliseconds));
                	
                
                #endif
                //#]
            }
            
            
            //## operation sleep(const time_t,const long,const bool) 
            inline static void sleep(const time_t seconds, const long nanoseconds, const bool interposition_safe = false) {
                //#[ operation sleep(const time_t,const long,const bool) 
                struct timespec request = { seconds, nanoseconds };
                sleep(request, interposition_safe);
                //#]
            }
            
        
        
        ////    Attributes    ////
        public :
            
            static const int MILLISECONDS_PER_SECOND;		//## attribute MILLISECONDS_PER_SECOND 
            
            static const int NANOSECONDS_PER_MILLISECOND;		//## attribute NANOSECONDS_PER_MILLISECOND 
            
        
        };
    }
}
//## package Framework::utils 

//## class Sleep 

namespace Framework {
    namespace utils {
        
        // Static class member attribute
        const int Sleep::MILLISECONDS_PER_SECOND = 1000;
        // Static class member attribute
        const int Sleep::NANOSECONDS_PER_MILLISECOND = 1000*1000;
        
    }
}



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\utils\Sleep.h
*********************************************************************/

