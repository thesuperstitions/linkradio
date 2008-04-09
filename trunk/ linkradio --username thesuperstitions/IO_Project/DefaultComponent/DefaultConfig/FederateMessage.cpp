/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateMessage
//!	Generated Date	: Tue, 1, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateMessage.cpp
*********************************************************************/

#include "FederateMessage.h"
#include "Buffer.h"
// attribute federateInterface 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// FederateMessage.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateMessage 

namespace Framework {
    namespace IO {
        
        
        FederateMessage::FederateMessage(Framework::IO::FederateInterface* interface, const rti1516::ParameterHandleValueMap & parameters) {
            //#[ operation FederateMessage(Framework::IO::FederateInterface*,const rti1516::ParameterHandleValueMap &) 
            //#]
        }
        
        FederateMessage::FederateMessage(Framework::IO::FederateInterface * interface, char* message, unsigned long messageSizeInBytes) : Message(message, messageSizeInBytes), federateInterface(interface) {
            //#[ operation FederateMessage(Framework::IO::FederateInterface *,char*,unsigned long) 
                         
            //#]
        }
        
        FederateMessage::FederateMessage() {
        }
        
        FederateMessage::~FederateMessage() {
        }
        
        FederateInterface* FederateMessage::getFederateInterface() const {
            return federateInterface;
        }
        
        void FederateMessage::setFederateInterface(FederateInterface* p_federateInterface) {
            federateInterface = p_federateInterface;
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateMessage.cpp
*********************************************************************/

