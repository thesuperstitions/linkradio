/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils
//!	Generated Date	: Tue, 22, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\utils.h
*********************************************************************/


#ifndef utils_H 

#define utils_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Framework.h"

//----------------------------------------------------------------------------
// utils.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace utils {
        class Queue;
        class Sleep;
        class Thread;
        class Timer;
    }
    
}


//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif


namespace Framework {
    
    namespace utils {
        
        //## type InterfaceType 
        enum InterfaceType {
            CEC_NTDS_SPY = 0,
            CEC_NTDS_CND = 1,
            CEC_NTDS_R48 = 2,
            CEC_NTDS_R49 = 3,
            SSDS_TCP_CEC = 4



        };
        
        
        //## attribute MAX_QUEUE_SIZE 
        #define MAX_QUEUE_SIZE 262144
        
        
    }
    
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\utils.h
*********************************************************************/

