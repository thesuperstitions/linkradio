/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_InputThread
//!	Generated Date	: Tue, 22, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_InputThread.h
*********************************************************************/


#ifndef FederateIO_InputThread_H 

#define FederateIO_InputThread_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"

//----------------------------------------------------------------------------
// FederateIO_InputThread.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class FederateIO_InputThread 
        class FederateIO_InputThread  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            FederateIO_InputThread();
            
            //## auto_generated 
            ~FederateIO_InputThread();
        
        
        ////    Operations    ////
        public :
            
            //## operation threadOperation() 
            void threadOperation();
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_InputThread.h
*********************************************************************/

