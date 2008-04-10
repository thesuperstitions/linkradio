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
//!	Date of createion:	Wed, 13, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************


#include "IO.h"
// operation getRawBuffer(Buffer) 
#include "Buffer.h"
#include "FederateInterface.h"
#include "FederateInterfaceFactory.h"
#include "FederateIO_Handler.h"
#include "FederateMessage.h"
#include "HLA_FederateInterface.h"
#include "HLA_PostOffice.h"
#include "IO_Handler.h"
#include "Message.h"
#include "OASIS_FederateInterface.h"
#include "PostOffice.h"
#include "RtiAmbassador.h"

//----------------------------------------------------------------------------
// IO.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

namespace Framework {
    namespace IO {
        
    }
}

namespace Framework {
    namespace IO {
        
        
        //## operation getFrameworkFederateAmbassador() 
        FrameworkFederateAmbassador getFrameworkFederateAmbassador() {
            //#[ operation getFrameworkFederateAmbassador() 
            if (SystemFrameworkFederateAmbassador == NULL)
              SystemFrameworkFederateAmbassador = new FrameworkFederateAmbassador();
              
            return(SystemFrameworkFederateAmbassador);
            //#]
        }
        
        //## operation getInterface(char*) 
        void getInterface(char* interfaceName) {
            //#[ operation getInterface(char*) 
            ///
            //#]
        }
        
        //## operation getRawBuffer(Buffer) 
        void getRawBuffer(const Buffer& buffer) {
            //#[ operation getRawBuffer(Buffer) 
            //#]
        }
        
        //## operation getRtiAmbassador() 
        void getRtiAmbassador() {
            //#[ operation getRtiAmbassador() 
            //#]
        }
        
    }
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IO.cpp
*********************************************************************/

