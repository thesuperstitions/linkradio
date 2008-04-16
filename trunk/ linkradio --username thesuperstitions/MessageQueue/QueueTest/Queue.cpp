//---------------------------------------------------------------------------

#include "Queue.h"
#include "boost/thread.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/thread/xtime.hpp>
#include <stdio.h>
#include <time.h>
#include "Sleep.h"

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


struct MessageStruct
{
  unsigned long MsgNumber;
  unsigned char MsgBody[30];
};

        Queue::Queue() 
        {
          exitFlag = false;
        }

        
        Queue::~Queue() 
        {
            exitFlag = true;
            myMutex.unlock();  // Wake "getMessage".

            cleanUpRelations();
        }
        
        void Queue::addMessage(void* message)
        {
            //#[ operation addMessage(void*)
            QString s;

            if (exitFlag == true)
              return;

            try
            {
              { // Start of Scope.
                // Get the mutex just long enough to add the message to the queue.
                boost::mutex::scoped_lock myDataAccessLock(myDataAccessMutex); //This lock protects the queue itself.

//MessageStruct* msg = (MessageStruct*) message;
//LogMessage(s.sprintf("Queue::addMessage - Message Added To Queue. Ptr=%p, MsgNumber=%u", message, msg->MsgNumber));

                this->addItsMessage(message);
              } // End of Scope.

              myMutex.unlock();  // Wake "getMessage".
            }
            catch (...)
            {
              //LogMessage(s.sprintf("Queue::addMessage -EXCEPTION"));
//              myMutex.unlock();
            };

            //#]
        }

        void* Queue::getMessage(unsigned int timeoutSecs, unsigned long int timeoutMilliSecs)
        {
          QString s;

          void* m_Ptr = NULL;

          if (exitFlag == true)
            return(NULL);

          try
          {
            boost::posix_time::time_duration td = boost::posix_time::seconds(timeoutSecs) + boost::posix_time::milliseconds(timeoutMilliSecs); //

            if (myMutex.timed_lock(boost::get_system_time() + td) == true)
            {
              //LogMessage(s.sprintf("Queue::getMessage - Mutex Indicates Message Available."));

              { // Start of scope
                boost::mutex::scoped_lock myDataAccessLock(myDataAccessMutex); //This lock protects the queue itself.

                // Check to see if there's a Message in the list   
                if (itsMessage.empty() != true)
                {      
                  // Get the first message in the list.                                  
                  m_Ptr = *itsMessage.begin();  // Get the first Message in the list. 
  
                  // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
                  removeItsMessage(m_Ptr);   // Remove the just-sent Message from the list.
//MessageStruct* msg = (MessageStruct*) m_Ptr;

                  //LogMessage(s.sprintf("Queue::getMessage - Message Being Returned To Application.  Ptr=%p, MsgNumber=%u", m_Ptr, msg->MsgNumber));
                }
              } // End of Scope.
            }
            else
            {
              // mutex timed out
              //LogMessage(s.sprintf("Queue::getMessage - Mutex Indicates Timeout."));
            }
          }
          catch (...)
          {
            //LogMessage(s.sprintf("Queue::getMessage - EXCEPTION"));
          };

          return(m_Ptr);
        }

        void Queue::LogMessage(QString Msg)
        {
          QString s;

          time_t      t;
          struct tm*  TS;
  
          t = time(NULL);
          TS = gmtime( &t );
          s.sprintf("%02u:%02u:%02u %02u/%02u/%4u - ", TS->tm_hour, TS->tm_min, TS->tm_sec, TS->tm_mon, TS->tm_mday, TS->tm_year+1900);
          s += Msg + " : ";
          this->OnLogText(s);
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

