/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_InputThread
//!	Generated Date	: Tue, 22, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_InputThread.cpp
*********************************************************************/

#include "FederateIO_InputThread.h"

//----------------------------------------------------------------------------
// FederateIO_InputThread.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateIO_InputThread 

namespace Framework {
    namespace IO {
        
        FederateIO_InputThread::FederateIO_InputThread() {
        }
        
        FederateIO_InputThread::~FederateIO_InputThread() {
        }
        
        void FederateIO_InputThread::threadOperation() {
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
                
                  // Send the message to the Post Office for delivery.  
                  if (/*fm_Ptr->getFederateInterface()->FederateInterface::*/getItsFederateIO_Handler()->passMessageToApplication(fm_Ptr) == true)
                  {
                    // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
                    removeItsFederateMessage(fm_Ptr);   // Remove the just-sent FederateMessage from the list.
                  }
                  
                  // Unlock mutex prior to sending message.
                  boost::detail::thread::lock_ops<boost::mutex>::unlock(myMutex);
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
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_InputThread.cpp
*********************************************************************/

