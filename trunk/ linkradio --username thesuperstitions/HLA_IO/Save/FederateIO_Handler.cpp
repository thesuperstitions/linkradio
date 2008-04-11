//*********************************************************************************  
//
//	File:				Framework::IO::FederateIO_Handler  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Fri, 8, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************


#include "FederateIO_Handler.h"
#include "Serializer.h"
// link itsFederate 
#include "Federate.h"
// operation getRawBuffer(Buffer*) 
#include "Buffer.h"
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
        
        std::list<Framework::IO::FederateInterface*>::const_iterator FederateIO_Handler::getItsFederateInterface() const {
            std::list<Framework::IO::FederateInterface*>::const_iterator iter;
            iter = itsFederateInterface.begin();
            return iter;
        }
        
        std::list<Framework::IO::FederateInterface*>::const_iterator FederateIO_Handler::getItsFederateInterfaceEnd() const {
            return itsFederateInterface.end();
        }
        
        void FederateIO_Handler::addItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            itsFederateInterface.push_back(p_FederateInterface);
        }
        
        void FederateIO_Handler::removeItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            std::list<Framework::IO::FederateInterface*>::iterator pos = std::find(itsFederateInterface.begin(), itsFederateInterface.end(),p_FederateInterface);
            if (pos != itsFederateInterface.end()) {
            	itsFederateInterface.erase(pos);
            }
        }
        
        void FederateIO_Handler::clearItsFederateInterface() {
            itsFederateInterface.clear();
        }
        
        std::list<Framework::IO::FederateMessage*>::const_iterator FederateIO_Handler::getItsFederateMessage() const {
            std::list<Framework::IO::FederateMessage*>::const_iterator iter;
            iter = itsFederateMessage.begin();
            return iter;
        }
        
        std::list<Framework::IO::FederateMessage*>::const_iterator FederateIO_Handler::getItsFederateMessageEnd() const {
            return itsFederateMessage.end();
        }
        
        void FederateIO_Handler::addItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            itsFederateMessage.push_back(p_FederateMessage);
        }
        
        void FederateIO_Handler::removeItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            std::list<Framework::IO::FederateMessage*>::iterator pos = std::find(itsFederateMessage.begin(), itsFederateMessage.end(),p_FederateMessage);
            if (pos != itsFederateMessage.end()) {
            	itsFederateMessage.erase(pos);
            }
        }
        
        void FederateIO_Handler::clearItsFederateMessage() {
            itsFederateMessage.clear();
        }
        
        void FederateIO_Handler::cleanUpRelations() {
            if(itsFederate != NULL)
                {
                    itsFederate = NULL;
                }
            {
                itsFederateInterface.clear();
            }
            {
                itsFederateMessage.clear();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/

