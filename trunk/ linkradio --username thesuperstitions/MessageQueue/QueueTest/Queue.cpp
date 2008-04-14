//---------------------------------------------------------------------------

#include "Queue.h"
//#include "boost/bind.hpp"
//#include "boost/function.hpp"
#include "boost/thread.hpp"

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


        
        Queue::~Queue() {
            cleanUpRelations();
        }
        
        void Queue::addMessage(void* message)
        {
            //#[ operation addMessage(void*)

            boost::lock_guard<boost::mutex> lock(myMutex);

            this->addItsMessage(message);

            myDataReady=true;
            myCondition.notify_one();

            //#]
        }
        
        void Queue::threadOperation()
        {
            //#[ operation threadOperation()
            
            boost::unique_lock<boost::mutex> myLock(myMutex);
            timespec ts;
            void* m_Ptr;  
                      
            while (true)
            {    
              try
              {  
                while(!myDataReady)
                {
                  myCondition.wait(myLock);
                };

                //boost::detail::thread::lock_ops<boost::mutex>::lock(myMutex);
                
                // Check to see if there's a Federate Message in the list   
                if (itsMessage.empty() != true)
                {      
                  // Get the first message in the list.                                  
                  m_Ptr = *itsMessage.begin();  // Get the first FederateMessage in the list. 
                
                  // Send the message to the Post Office for delivery.  
                  if (this->processMessage(m_Ptr) == true)
                  {
                    // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
                    removeItsMessage(m_Ptr);   // Remove the just-sent FederateMessage from the list.
                  }
                  
                  // Unlock mutex prior to sending message.
                  //boost::detail::thread::lock_ops<boost::mutex>::unlock(myMutex);
                }   
              } 
              catch (...)
              {
                //boost::detail::thread::lock_ops<boost::mutex>::unlock(myMutex);
              } 
                  
              //this->yield();

            };  
            //#]
        }
        
        
        std::vector<void*>::const_iterator Queue::getItsMessage() const
        {
            std::vector<void*>::const_iterator iter;
            iter = itsMessage.begin();
            return iter;
        }
        
        std::vector<void*>::const_iterator Queue::getItsMessageEnd() const {
            return itsMessage.end();
        }
        
        void Queue::addItsMessage(void* p_Message) {
            itsMessage.push_back(p_Message);
        }
        
        void Queue::removeItsMessage(void* p_Message) {
            std::vector<void*>::iterator pos = std::find(itsMessage.begin(), itsMessage.end(),p_Message);
            if (pos != itsMessage.end()) {
            	itsMessage.erase(pos);
            }
        }
        
        void Queue::clearItsMessage() {
            itsMessage.clear();
        }
        
        void Queue::cleanUpRelations()
        {
                itsMessage.clear();
        }

