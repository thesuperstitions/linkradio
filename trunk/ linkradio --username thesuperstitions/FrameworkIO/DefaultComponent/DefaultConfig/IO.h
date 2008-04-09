//*********************************************************************************  
//
//	File:				Framework::IO  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Thu, 14, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef IO_H 

#define IO_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
// operation getFrameworkFederateAmbassador() 
#include "FrameworkFederateAmbassador.h"
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

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif


namespace Framework {
    
    namespace IO {
        
        
        //## operation getFrameworkFederateAmbassador() 
        FrameworkFederateAmbassador getFrameworkFederateAmbassador();
        
        //## operation getInterface(char*) 
        void getInterface(char* interfaceName);
        
        //## operation getRawBuffer(Buffer) 
        void getRawBuffer(const Buffer& buffer);
        
        //## operation getRtiAmbassador() 
        void getRtiAmbassador();
        
        
    }
    
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IO.h
*********************************************************************/

