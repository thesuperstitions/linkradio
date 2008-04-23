/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO
//!	Generated Date	: Tue, 22, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\IO.h
*********************************************************************/


#ifndef IO_H 

#define IO_H 

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
// IO.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        class C_IO_Functions;
        class FederateInterface;
        class FederateIO_Handler;
        class FederateMessage;
        class HLA_FederateInterface;
        class HLA_PostOffice;
        class IO_Handler;
        class Message;
        class OASIS_FederateInterface;
        class PostOffice;
    }
    
}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif


namespace Framework {
    
    namespace IO {
        
        
        //## operation getRawBuffer(Buffer) 
        void getRawBuffer(const Buffer& buffer);
        
        
    }
    
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IO.h
*********************************************************************/

