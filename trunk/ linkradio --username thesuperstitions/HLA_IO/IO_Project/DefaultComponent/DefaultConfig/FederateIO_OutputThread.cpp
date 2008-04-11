/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_OutputThread
//!	Generated Date	: Wed, 9, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_OutputThread.cpp
*********************************************************************/

#include "FederateIO_OutputThread.h"
// dependency Control 
#include "Control.h"
// dependency Federate 
#include "Federate.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"
// dependency PostOffice 
#include "PostOffice.h"
// dependency Sleep 
#include "Sleep.h"
#include "boost/bind.hpp"
#include "boost/function.hpp"
#include "boost/thread.hpp"

//----------------------------------------------------------------------------
// FederateIO_OutputThread.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateIO_OutputThread 

namespace Framework {
    namespace IO {
        
        
        FederateIO_OutputThread::FederateIO_OutputThread() {
            itsFederateIO_Handler = NULL;
        }
        
        FederateIO_OutputThread::~FederateIO_OutputThread() {
            cleanUpRelations();
        }
        
        void FederateIO_OutputThread::addFederateMessage(FederateMessage* message) {
            //#[ operation addFederateMessage(FederateMessage*) 
            
            // Lock the mutex so that we can use the FederateMessage list.
            boost::detail::thread::lock_ops<boost::mutex>::lock(myMutex);
               
            // Add the message to the list.   
            this->addItsFederateMessage(message);
                                           
            // Unlock the mutex so that the reader thread can access it.
            boost::detail::thread::lock_ops<boost::mutex>::unlock(myMutex);
            
            //#]
        }
        
        void FederateIO_OutputThread::threadOperation() {
            //#[ operation threadOperation() 
            
            timespec ts;
            FederateMessage* fm_Ptr;  
                      
            while (true)
            {    
              try
              {  
                boost::detail::thread::lock_ops<boost::mutex>::lock(myMutex);
                
                // Check to see if there's a Federate Message in the list   
                if (itsFederateMessage.empty() != true)
                {      
                  // Get the first message in the list.                                  
                  fm_Ptr = *itsFederateMessage.begin();  // Get the first FederateMessage in the list. 
                  
                  // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
                  removeItsFederateMessage(fm_Ptr);   // Remove the just-sent FederateMessage from the list.
                  
                  // Unlock mutex prior to sending message.
                  boost::detail::thread::lock_ops<boost::mutex>::unlock(myMutex);
                
                  // Send the message to the Post Office for delivery.
                  Framework::Control::getFederate()->getThePostOffice()->sendMessage( fm_Ptr);
                }   
              } 
              catch (...)
              {
                boost::detail::thread::lock_ops<boost::mutex>::unlock(myMutex);
              } 
              
              this->yield();
               
            //              ts.tv_nsec = 1 * Framework::utils::Sleep::NANOSECONDS_PER_MILLISECOND;
            //              ts.tv_sec = 0;
            //              Framework::utils::Sleep::sleep(ts);
            };  
            //#]
        }
        
        Framework::IO::FederateIO_Handler* FederateIO_OutputThread::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void FederateIO_OutputThread::__setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void FederateIO_OutputThread::_setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler->__setItsFederateIO_OutputThread(NULL);
                }
            __setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateIO_OutputThread::setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(p_FederateIO_Handler != NULL)
                {
                    p_FederateIO_Handler->_setItsFederateIO_OutputThread(this);
                }
            _setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateIO_OutputThread::_clearItsFederateIO_Handler() {
            itsFederateIO_Handler = NULL;
        }
        
        std::vector<Framework::IO::FederateMessage*>::const_iterator FederateIO_OutputThread::getItsFederateMessage() const {
            std::vector<Framework::IO::FederateMessage*>::const_iterator iter;
            iter = itsFederateMessage.begin();
            return iter;
        }
        
        std::vector<Framework::IO::FederateMessage*>::const_iterator FederateIO_OutputThread::getItsFederateMessageEnd() const {
            return itsFederateMessage.end();
        }
        
        void FederateIO_OutputThread::addItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            itsFederateMessage.push_back(p_FederateMessage);
        }
        
        void FederateIO_OutputThread::removeItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            std::vector<Framework::IO::FederateMessage*>::iterator pos = std::find(itsFederateMessage.begin(), itsFederateMessage.end(),p_FederateMessage);
            if (pos != itsFederateMessage.end()) {
            	itsFederateMessage.erase(pos);
            }
        }
        
        void FederateIO_OutputThread::clearItsFederateMessage() {
            itsFederateMessage.clear();
        }
        
        void FederateIO_OutputThread::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    Framework::IO::FederateIO_OutputThread* p_FederateIO_OutputThread = itsFederateIO_Handler->getItsFederateIO_OutputThread();
                    if(p_FederateIO_OutputThread != NULL)
                        {
                            itsFederateIO_Handler->__setItsFederateIO_OutputThread(NULL);
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
	File Path	: DefaultComponent\DefaultConfig\FederateIO_OutputThread.cpp
*********************************************************************/

