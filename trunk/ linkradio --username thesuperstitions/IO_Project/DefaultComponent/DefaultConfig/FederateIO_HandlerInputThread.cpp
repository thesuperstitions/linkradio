/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_HandlerInputThread
//!	Generated Date	: Thu, 3, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_HandlerInputThread.cpp
*********************************************************************/

#include "FederateIO_HandlerInputThread.h"
// dependency Control 
#include "Control.h"
// operation FederateIO_HandlerInputThread(FederateInterface*) 
#include "FederateInterface.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"
// dependency PostOffice 
#include "PostOffice.h"
#include "boost/bind.hpp"
#include "boost/function.hpp"
#include "boost/thread.hpp"

//----------------------------------------------------------------------------
// FederateIO_HandlerInputThread.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateIO_HandlerInputThread 

namespace Framework {
    namespace IO {
        
        
        FederateIO_HandlerInputThread::FederateIO_HandlerInputThread(FederateInterface* federateInterface) : federateInterface(federateInterface) {
            itsFederateIO_Handler = NULL;
            //#[ operation FederateIO_HandlerInputThread(FederateInterface*) 
            //#]
        }
        
        FederateIO_HandlerInputThread::FederateIO_HandlerInputThread() {
            itsFederateIO_Handler = NULL;
            //#[ operation FederateIO_HandlerInputThread() 
            itsFederateIO_Handler = NULL;
            //#]
        }
        
        FederateIO_HandlerInputThread::~FederateIO_HandlerInputThread() {
            cleanUpRelations();
        }
        
        void FederateIO_HandlerInputThread::addFederateMessage(FederateMessage* message) {
            //#[ operation addFederateMessage(FederateMessage*) 
            this->addItsFederateMessage(message);
            //#]
        }
        
        void FederateIO_HandlerInputThread::threadOperation() {
            //#[ operation threadOperation() 
            
            FederateMessage* fm_Ptr;  
                      
            while (true)
            {    
              try
              {  
                boost::detail::thread::lock_ops<boost::mutex>::lock(myMutex);
                
                // Check to see if there's a Federate Message in the list   
                if (itsFederateMessage.empty() != true)
                {                                        
                  // Send the message to the Post Office for delivery.
                  fm_Ptr = *itsFederateMessage.begin();  // Get the first FederateMessage in the list. 
                
                  Framework::Control::getPostOffice()->sendMessage( federateInterface, fm_Ptr);
                     
                  removeItsFederateMessage(fm_Ptr);   // Remove the just-sent FederateMessage from the list.
                }   
              } 
              catch (...)
              {
                boost::detail::thread::lock_ops<boost::mutex>::unlock(myMutex);
              } 
              
              boost::detail::thread::lock_ops<boost::mutex>::unlock(myMutex);
            //              Sleep(1);
            };  
            //#]
        }
        
        FederateInterface* FederateIO_HandlerInputThread::getFederateInterface() const {
            return federateInterface;
        }
        
        void FederateIO_HandlerInputThread::setFederateInterface(FederateInterface* p_federateInterface) {
            federateInterface = p_federateInterface;
        }
        
        Framework::IO::FederateIO_Handler* FederateIO_HandlerInputThread::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void FederateIO_HandlerInputThread::__setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void FederateIO_HandlerInputThread::_setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler->__setItsFederateIO_HandlerInputThread(NULL);
                }
            __setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateIO_HandlerInputThread::setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(p_FederateIO_Handler != NULL)
                {
                    p_FederateIO_Handler->_setItsFederateIO_HandlerInputThread(this);
                }
            _setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateIO_HandlerInputThread::_clearItsFederateIO_Handler() {
            itsFederateIO_Handler = NULL;
        }
        
        std::vector<Framework::IO::FederateMessage*>::const_iterator FederateIO_HandlerInputThread::getItsFederateMessage() const {
            std::vector<Framework::IO::FederateMessage*>::const_iterator iter;
            iter = itsFederateMessage.begin();
            return iter;
        }
        
        std::vector<Framework::IO::FederateMessage*>::const_iterator FederateIO_HandlerInputThread::getItsFederateMessageEnd() const {
            return itsFederateMessage.end();
        }
        
        void FederateIO_HandlerInputThread::addItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            itsFederateMessage.push_back(p_FederateMessage);
        }
        
        void FederateIO_HandlerInputThread::removeItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            std::vector<Framework::IO::FederateMessage*>::iterator pos = std::find(itsFederateMessage.begin(), itsFederateMessage.end(),p_FederateMessage);
            if (pos != itsFederateMessage.end()) {
            	itsFederateMessage.erase(pos);
            }
        }
        
        void FederateIO_HandlerInputThread::clearItsFederateMessage() {
            itsFederateMessage.clear();
        }
        
        void FederateIO_HandlerInputThread::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    Framework::IO::FederateIO_HandlerInputThread* p_FederateIO_HandlerInputThread = itsFederateIO_Handler->getItsFederateIO_HandlerInputThread();
                    if(p_FederateIO_HandlerInputThread != NULL)
                        {
                            itsFederateIO_Handler->__setItsFederateIO_HandlerInputThread(NULL);
                        }
                    itsFederateIO_Handler = NULL;
                }
            {
                itsFederateMessage.clear();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_HandlerInputThread.cpp
*********************************************************************/

