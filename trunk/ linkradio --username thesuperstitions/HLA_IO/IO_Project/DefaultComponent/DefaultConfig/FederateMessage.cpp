/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateMessage
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateMessage.cpp
*********************************************************************/

#include "FederateMessage.h"
// operation create(FederateInterface*,Buffer*) 
#include "Buffer.h"
// operation create(FederateInterface*,unsigned int) 
#include "FederateInterface.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"

//----------------------------------------------------------------------------
// FederateMessage.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateMessage 

namespace Framework {
    namespace IO {
        
        
        FederateMessage::FederateMessage() {
            itsFederateIO_Handler = NULL;
        }
        
        FederateMessage::~FederateMessage() {
            cleanUpRelations();
        }
        
        void FederateMessage::create(FederateInterface* interface, unsigned int InstanceNumber) {
            //#[ operation create(FederateInterface*,unsigned int) 
            //#]
        }
        
        void FederateMessage::create(FederateInterface* interface, Buffer* buffer) {
            //#[ operation create(FederateInterface*,Buffer*) 
            //#]
        }
        
        Buffer* FederateMessage::getBuffer() {
            //#[ operation getBuffer() 
            return(NULL);  // This is just temporary until the code is fleshed out.
            //#]
        }
        
        Framework::IO::FederateIO_Handler* FederateMessage::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void FederateMessage::setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void FederateMessage::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateMessage.cpp
*********************************************************************/

