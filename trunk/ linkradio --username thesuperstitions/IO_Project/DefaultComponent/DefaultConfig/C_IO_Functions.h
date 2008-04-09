/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::C_IO_Functions
//!	Generated Date	: Tue, 8, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.h
*********************************************************************/


#ifndef C_IO_Functions_H 

#define C_IO_Functions_H 

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
// C_IO_Functions.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class Federate;
    }
    
}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class C_IO_Functions 
        class C_IO_Functions  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            C_IO_Functions();
            
            //## auto_generated 
            ~C_IO_Functions();
        
        
        ////    Operations    ////
        public :
            
            //## operation createInterface(std::string) 
            static void createInterface(std::string interfaceName);
            
            //## operation getMessageType(char*,Framework::InterfaceType) 
            static Framework::MessageType getMessageType(char* message, Framework::InterfaceType interfaceType);
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.h
*********************************************************************/

