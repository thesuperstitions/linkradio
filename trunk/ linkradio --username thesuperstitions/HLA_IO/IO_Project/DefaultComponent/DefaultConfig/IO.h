/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\IO.h
*********************************************************************/


#ifndef IO_H 

#define IO_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Framework.h"

//----------------------------------------------------------------------------
// IO.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        class FederateInterface;
        class FederateIO_Handler;
        class FederateMessage;
        class HLA_FederateInterface;
        class HLA_PostOffice;
        class IO_Handler;
        class Message;
        class OASIS_FederateInterface;
        class PostOffice;
        class RtiAmbassador;
    }
    
}


//## package Framework::IO 


namespace Framework {
    
    namespace IO {
        
        
        //## operation getInterfaceName(char*) 
        void getInterfaceName(char* interfaceName);
        
        //## operation getRawBuffer(Buffer) 
        void getRawBuffer(const Buffer& buffer);
        
        
    }
    
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IO.h
*********************************************************************/

