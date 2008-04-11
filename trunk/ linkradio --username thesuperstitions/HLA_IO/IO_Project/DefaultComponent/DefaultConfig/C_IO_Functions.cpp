/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::C_IO_Functions
//!	Generated Date	: Tue, 8, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.cpp
*********************************************************************/

#include "C_IO_Functions.h"
// dependency Federate 
#include "Federate.h"

//----------------------------------------------------------------------------
// C_IO_Functions.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class C_IO_Functions 

namespace Framework {
    namespace IO {
        
        C_IO_Functions::C_IO_Functions() {
        }
        
        C_IO_Functions::~C_IO_Functions() {
        }
        
        void C_IO_Functions::createInterface(std::string interfaceName) {
            //#[ operation createInterface(std::string) 
             Framework::Control::Federate* fp = Framework::Control::getFederate();
             
             Framework::IO::FederateIO_Handler* fio = fp->getItsFederateIO_Handler();
             
             fio->createFederateInterface(interfaceName);
            //#]
        }
        
        Framework::MessageType C_IO_Functions::getMessageType(char* message, Framework::InterfaceType interfaceType) {
            //#[ operation getMessageType(char*,Framework::InterfaceType) 
            return(Framework::CEC_Msg_Type_1);
            //#]
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.cpp
*********************************************************************/

