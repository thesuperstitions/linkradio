/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::Queue
//!	Generated Date	: Tue, 22, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\utils\Queue.cpp
*********************************************************************/

// dependency thread 
#include "boost\thread.hpp"
// dependency posix_time 
#include "boost\date_time\posix_time\posix_time.hpp"
#include "Queue.h"

//----------------------------------------------------------------------------
// utils\Queue.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

//## class Queue 

namespace Framework {
    namespace utils {
        
        
        Queue::Queue(unsigned long numberOfItems) {
            //#[ operation Queue(unsigned long) 
            exitFlag = false;
            myMutex.unlock();
            myQueue = new boost::circular_buffer<void*>(numberOfItems);
            //#]
        }
        
        Queue::~Queue() {
            //#[ operation ~Queue() 
            exitFlag = true;
            myMutex.unlock();  // Wake "getMessage".
            delete myQueue;
            //#]
        }
        
        void * Queue::CheckForItemsInQueue() {
            //#[ operation CheckForItemsInQueue() 
            // Start of scope for the "scoped_lock" mutex.
             void* m_Ptr = NULL;
            
             boost::mutex::scoped_lock myDataAccessLock(myDataAccessMutex); //This lock protects the queue itself.
            
             // Check to see if there's a Message in the list   
             if (myQueue->empty() != true)
             {      
               // Get the first message in the list.                                  
               m_Ptr = myQueue->front();  
            
               // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
               myQueue->pop_front();   // Remove the just-sent Message from the list.
             }
            
             return(m_Ptr);
            //#]
        }
        
        bool Queue::addMessage(void * message) {
            //#[ operation addMessage(void *) 
            if (exitFlag == true)
              return(false);
            
            try
            {
              { // Start of Scope.
                // Get the mutex just long enough to add the message to the queue.
                boost::mutex::scoped_lock myDataAccessLock(myDataAccessMutex); //This lock protects the queue itself.
              
                if (myQueue->full() != true)
                {
                  //myQueue.push_back(message);
                  myQueue->push_back(message);
            
                  myMutex.unlock();  // Wake "getMessage".
            
                  return(true); // Message was queued
                }  // if (myQueue->full() != true)
                else
                  return (false); // Message was NOT queued.
              } // End of Scope.
            }
            catch (...)
            {
            };
            return(false);
            //#]
        }
        
        void * Queue::getMessage(unsigned int timeoutSecs, unsigned long timeoutMicroSecs) {
            //#[ operation getMessage(unsigned int,unsigned long) 
            void* m_Ptr = NULL;
            
            // Just in case this function gets invoked during shutdown.
            if (exitFlag == true)
              return(NULL);
            
            try
            {
              // Check to see if there's a message already waiting on the Queue.  If so, we just return it.
              if ( (m_Ptr = CheckForItemsInQueue()) != NULL)
                return(m_Ptr);
            
              // There were no items in the Queue, so now we have to wait for either the queue to be unlocked or the timeout occurs.
            
              // Calculate the duration of the timeout.
              boost::posix_time::time_duration td = boost::posix_time::seconds(timeoutSecs) + boost::posix_time::microseconds(timeoutMicroSecs); //
            
              // Block on the mutex until either a message is received in the queue (addMessage function unlocks the mutex after dropping a message
              // in the queue), or the timer expires.
              if (myMutex.timed_lock(boost::get_system_time() + td) == true)
              {
                return( CheckForItemsInQueue() );
              }
              else
              {
                // mutex timed out
                return(m_Ptr);
              }
            }
            catch(...)
            {
            };
            
            return(m_Ptr);
            //#]
        }
        
        bool Queue::getExitFlag() const {
            return exitFlag;
        }
        
        void Queue::setExitFlag(bool p_exitFlag) {
            exitFlag = p_exitFlag;
        }
        
        boost::mutex Queue::getMyDataAccessMutex() const {
            return myDataAccessMutex;
        }
        
        void Queue::setMyDataAccessMutex(boost::mutex p_myDataAccessMutex) {
            myDataAccessMutex = p_myDataAccessMutex;
        }
        
        boost::timed_mutex Queue::getMyMutex() const {
            return myMutex;
        }
        
        void Queue::setMyMutex(boost::timed_mutex p_myMutex) {
            myMutex = p_myMutex;
        }
        
        boost::circular_buffer<void*> * Queue::getMyQueue() const {
            return myQueue;
        }
        
        void Queue::setMyQueue(boost::circular_buffer<void*> * p_myQueue) {
            myQueue = p_myQueue;
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\utils\Queue.cpp
*********************************************************************/

