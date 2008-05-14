/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::Queue
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\Queue.h
*********************************************************************/


#ifndef Queue_H 

#define Queue_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "utils.h"

//----------------------------------------------------------------------------
// Queue.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace utils {
        //## class Queue 
        class Queue  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            // ---------------------------------------------------------------------------
            //## operation Queue(unsigned long) 
            Queue(unsigned long numberOfItems = MAX_QUEUE_SIZE);
            
            // ## operation Queue()
            //## operation ~Queue() 
            virtual ~Queue();
        
        
        ////    Operations    ////
        public :
            
            // ## operation addMessage(FederateMessage*)
            //## operation addMessage(void *) 
            virtual bool addMessage(void * message);
            
            // Immediately check to see if the thread should exit.  Check to see if there
            // is a message in the queue and, if so, return it to the user.  If not, wait
            // up to the user-defined timeout.  If a message becomes available in the
            // queue within the timeout period, return the message.  If not, return a 
            // NULL pointer.
            // ---------------------------------------------------------------------------
            //## operation getMessage(unsigned int,unsigned long) 
            virtual void * getMessage(unsigned int timeoutSecs, unsigned long timeoutMicroSecs);
        
        protected :
            
            // Waits on a mutex that protects access to the queue.  When mutex is received,
            // a check is made to see if there's at least one message in the queue.  If
            // not, a NULL pointer is returned.  If not empty, the first message (the 
            // oldest one) is taken off the queue and passed back to the caller.
            // ---------------------------------------------------------------------------
            //## operation CheckForItemsInQueue() 
            void * CheckForItemsInQueue();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            bool getExitFlag() const;
            
            //## auto_generated 
            void setExitFlag(bool p_exitFlag);
            
            //## auto_generated 
            boost::mutex getMyDataAccessMutex() const;
            
            //## auto_generated 
            void setMyDataAccessMutex(boost::mutex p_myDataAccessMutex);
            
            //## auto_generated 
            boost::timed_mutex getMyMutex() const;
            
            //## auto_generated 
            void setMyMutex(boost::timed_mutex p_myMutex);
            
            //## auto_generated 
            boost::circular_buffer<void*> * getMyQueue() const;
            
            //## auto_generated 
            void setMyQueue(boost::circular_buffer<void*> * p_myQueue);
        
        
        ////    Attributes    ////
        public :
            
            boost::circular_buffer<void*> * myQueue;		//## attribute myQueue 
            
        protected :
            
            bool exitFlag;		//## attribute exitFlag 
            
            boost::mutex myDataAccessMutex;		//## attribute myDataAccessMutex 
            
            // ## attribute myMutex
            boost::timed_mutex myMutex;		//## attribute myMutex 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Queue.h
*********************************************************************/

