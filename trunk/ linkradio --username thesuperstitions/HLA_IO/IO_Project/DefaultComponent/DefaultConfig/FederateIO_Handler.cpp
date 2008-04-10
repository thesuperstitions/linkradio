/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_Handler
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/

#include "FederateIO_Handler.h"
#include "Serializer.h"
// link itsFederate 
#include "Federate.h"
// operation getRawBuffer(Buffer*) 
#include "Buffer.h"
// link itsFederateInterface 
#include "FederateInterface.h"
// operation receiveMessage(FederateMessage*) 
#include "FederateMessage.h"
#include "PostOffice.h"

//----------------------------------------------------------------------------
// FederateIO_Handler.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateIO_Handler 

namespace Framework {
    namespace IO {
        
        
        FederateIO_Handler::FederateIO_Handler() {
            itsFederate = NULL;
        }
        
        FederateIO_Handler::~FederateIO_Handler() {
            cleanUpRelations();
        }
        
        char* FederateIO_Handler::getInterfacename() {
            //#[ operation getInterfacename() 
            return("");
            //#]
        }
        
        void FederateIO_Handler::getRawBuffer(Buffer* buffer) {
            //#[ operation getRawBuffer(Buffer*) 
            //#]
        }
        
        Framework::MessageType* FederateIO_Handler::getType(Buffer* buffer) {
            //#[ operation getType(Buffer*) 
            return(NULL);  //This is just temporary until the code is fleshed out.
            //#]
        }
        
        void FederateIO_Handler::receiveMessage(FederateMessage* message) {
            //#[ operation receiveMessage(FederateMessage*) 
            //#]
        }
        
        void FederateIO_Handler::registerRawMesgCallback(void  (* callbackFunction)(char * , int)) {
            //#[ operation registerRawMesgCallback(void  (* )(char * , int) ) 
            //#]
        }
        
        Framework::Federate::Federate* FederateIO_Handler::getItsFederate() const {
            return itsFederate;
        }
        
        void FederateIO_Handler::setItsFederate(Framework::Federate::Federate* p_Federate) {
            itsFederate = p_Federate;
        }
        
        OMIterator<Framework::IO::FederateInterface*> FederateIO_Handler::getItsFederateInterface() const {
            OMIterator<Framework::IO::FederateInterface*> iter(itsFederateInterface);
            return iter;
        }
        
        void FederateIO_Handler::addItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            itsFederateInterface.add(p_FederateInterface);
        }
        
        void FederateIO_Handler::removeItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            itsFederateInterface.remove(p_FederateInterface);
        }
        
        void FederateIO_Handler::clearItsFederateInterface() {
            itsFederateInterface.removeAll();
        }
        
        OMIterator<Framework::IO::FederateMessage*> FederateIO_Handler::getItsFederateMessage() const {
            OMIterator<Framework::IO::FederateMessage*> iter(itsFederateMessage);
            return iter;
        }
        
        void FederateIO_Handler::addItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            itsFederateMessage.add(p_FederateMessage);
        }
        
        void FederateIO_Handler::removeItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            itsFederateMessage.remove(p_FederateMessage);
        }
        
        void FederateIO_Handler::clearItsFederateMessage() {
            itsFederateMessage.removeAll();
        }
        
        void FederateIO_Handler::cleanUpRelations() {
            if(itsFederate != NULL)
                {
                    itsFederate = NULL;
                }
            {
                itsFederateInterface.removeAll();
            }
            {
                itsFederateMessage.removeAll();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/

