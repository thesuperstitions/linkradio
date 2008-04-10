/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::PostOffice
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\PostOffice.cpp
*********************************************************************/

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
// link itsMessage 
#include "Message.h"

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
                for (int pos = 0; pos < 2; ++pos) {
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
            for (int pos = 0; pos < 2; ++pos) {
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
            for (int pos = 0; pos < 2; ++pos) {
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
            while ((iter < 2) && itsIO_Handler[iter]){
                (itsIO_Handler[iter])->_clearItsPostOffice();
                iter++;
            }
            _clearItsIO_Handler();
        }
        
        OMIterator<Framework::IO::Message*> PostOffice::getItsMessage() const {
            OMIterator<Framework::IO::Message*> iter(itsMessage);
            return iter;
        }
        
        void PostOffice::addItsMessage(Framework::IO::Message* p_Message) {
            itsMessage.add(p_Message);
        }
        
        void PostOffice::removeItsMessage(Framework::IO::Message* p_Message) {
            itsMessage.remove(p_Message);
        }
        
        void PostOffice::clearItsMessage() {
            itsMessage.removeAll();
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
                while ((iter < 2) && itsIO_Handler[iter]){
                    Framework::IO::PostOffice* p_PostOffice = (itsIO_Handler[iter])->getItsPostOffice();
                    if(p_PostOffice != NULL)
                        {
                            (itsIO_Handler[iter])->__setItsPostOffice(NULL);
                        }
                    iter++;
                }
            }
            {
                itsMessage.removeAll();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PostOffice.cpp
*********************************************************************/

