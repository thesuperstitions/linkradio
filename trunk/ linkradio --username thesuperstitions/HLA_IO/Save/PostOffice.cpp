//*********************************************************************************  
//
//	File:				Framework::IO::PostOffice  
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


#include "PostOffice.h"
// link itsFederate 
#include "Federate.h"
// operation receiveMessage(Buffer*,int) 
#include "Buffer.h"
// operation announcePublication(FederateInterface*) 
#include "FederateInterface.h"
// operation sendMessage(FederateMessage*) 
#include "FederateMessage.h"
// link itsIO_Handler 
#include "IO_Handler.h"

//----------------------------------------------------------------------------
// PostOffice.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class PostOffice 

namespace Framework {
    namespace IO {
        
        
        PostOffice::PostOffice() {
            itsFederate = NULL;
            {
                for (int pos = 0; pos < 2; pos++) {
                	itsIO_Handler[pos] = NULL;
                }
            }
        }
        
        PostOffice::~PostOffice() {
            cleanUpRelations();
        }
        
        void PostOffice::announcePublication(FederateInterface* interface) {
            //#[ operation announcePublication(FederateInterface*) 
            //#]
        }
        
        void PostOffice::announceSubscription(FederateInterface* interface) {
            //#[ operation announceSubscription(FederateInterface*) 
            //#]
        }
        
        FederateInterface* PostOffice::findFederateInterface() {
            //#[ operation findFederateInterface() 
            return(NULL);  // This is just temporary until the code is fleshed out.
            //#]
        }
        
        void PostOffice::receiveMessage(Buffer* buffer, int theInteraction) {
            //#[ operation receiveMessage(Buffer*,int) 
            //#]
        }
        
        void PostOffice::sendMessage(FederateMessage* message) {
            //#[ operation sendMessage(FederateMessage*) 
            //#]
        }
        
        void PostOffice::sendMessage(FrameworkMessage* message) {
            //#[ operation sendMessage(FrameworkMessage*) 
            //#]
        }
        
        void PostOffice::unsubscribe(FederateInterface* interface) {
            //#[ operation unsubscribe(FederateInterface*) 
            //#]
        }
        
        Framework::Federate::Federate* PostOffice::getItsFederate() const {
            return itsFederate;
        }
        
        void PostOffice::__setItsFederate(Framework::Federate::Federate* p_Federate) {
            itsFederate = p_Federate;
        }
        
        void PostOffice::_setItsFederate(Framework::Federate::Federate* p_Federate) {
            if(itsFederate != NULL)
                {
                    itsFederate->__setItsPostOffice(NULL);
                }
            __setItsFederate(p_Federate);
        }
        
        void PostOffice::setItsFederate(Framework::Federate::Federate* p_Federate) {
            if(p_Federate != NULL)
                {
                    p_Federate->_setItsPostOffice(this);
                }
            _setItsFederate(p_Federate);
        }
        
        void PostOffice::_clearItsFederate() {
            itsFederate = NULL;
        }
        
        int PostOffice::getItsIO_Handler() const {
            int iter = 0;
            return iter;
        }
        
        void PostOffice::_addItsIO_Handler(Framework::IO::IO_Handler* p_IO_Handler) {
            for (int pos = 0; pos < 2; pos++) {
            	if (!itsIO_Handler[pos]) {
            		itsIO_Handler[pos] = p_IO_Handler;
            		break;
            	}
            }
        }
        
        void PostOffice::addItsIO_Handler(Framework::IO::IO_Handler* p_IO_Handler) {
            if(p_IO_Handler != NULL)
                {
                    p_IO_Handler->_setItsPostOffice(this);
                }
            _addItsIO_Handler(p_IO_Handler);
        }
        
        void PostOffice::_removeItsIO_Handler(Framework::IO::IO_Handler* p_IO_Handler) {
            for (int pos = 0; pos < 2; pos++) {
            	if (itsIO_Handler[pos] == p_IO_Handler) {
            		itsIO_Handler[pos] = NULL;
            	}
            }
        }
        
        void PostOffice::removeItsIO_Handler(Framework::IO::IO_Handler* p_IO_Handler) {
            if(p_IO_Handler != NULL)
                {
                    p_IO_Handler->__setItsPostOffice(NULL);
                }
            _removeItsIO_Handler(p_IO_Handler);
        }
        
        void PostOffice::_clearItsIO_Handler() {
            
        }
        
        void PostOffice::clearItsIO_Handler() {
            int iter = 0;
            while (iter < 2){
                (itsIO_Handler[iter])->_clearItsPostOffice();
                iter++;
            }
            _clearItsIO_Handler();
        }
        
        std::list<Framework::IO::Message*>::const_iterator PostOffice::getItsMessage() const {
            std::list<Framework::IO::Message*>::const_iterator iter;
            iter = itsMessage.begin();
            return iter;
        }
        
        std::list<Framework::IO::Message*>::const_iterator PostOffice::getItsMessageEnd() const {
            return itsMessage.end();
        }
        
        void PostOffice::addItsMessage(Framework::IO::Message* p_Message) {
            itsMessage.push_back(p_Message);
        }
        
        void PostOffice::removeItsMessage(Framework::IO::Message* p_Message) {
            std::list<Framework::IO::Message*>::iterator pos = std::find(itsMessage.begin(), itsMessage.end(),p_Message);
            if (pos != itsMessage.end()) {
            	itsMessage.erase(pos);
            }
        }
        
        void PostOffice::clearItsMessage() {
            itsMessage.clear();
        }
        
        void PostOffice::cleanUpRelations() {
            if(itsFederate != NULL)
                {
                    Framework::IO::PostOffice* p_PostOffice = itsFederate->getItsPostOffice();
                    if(p_PostOffice != NULL)
                        {
                            itsFederate->__setItsPostOffice(NULL);
                        }
                    itsFederate = NULL;
                }
            {
                int iter = 0;
                while (iter < 2){
                    Framework::IO::PostOffice* p_PostOffice = (itsIO_Handler[iter])->getItsPostOffice();
                    if(p_PostOffice != NULL)
                        {
                            (itsIO_Handler[iter])->__setItsPostOffice(NULL);
                        }
                    iter++;
                }
            }
            {
                itsMessage.clear();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PostOffice.cpp
*********************************************************************/

