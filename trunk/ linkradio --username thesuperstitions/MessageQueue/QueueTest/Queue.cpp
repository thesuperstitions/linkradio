//---------------------------------------------------------------------------

#include "Queue.h"
//#include "boost/bind.hpp"
//#include "boost/date_time/time_duration.hpp"
#include "boost/thread.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
//#include "boost/date_time/time_duration.hpp"
#include <boost/thread/xtime.hpp>
#include <stdio.h>
#include <time.h>
#include "Sleep.h"

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


        Queue::Queue() 
        {
          exitFlag = false;
        }

        
        Queue::~Queue() 
        {
//            char msg[100];

//            addMessage((void*)&msg);
            exitFlag = true;

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
              myMutex.lock();

              this->addItsMessage(message);
              //LogMessage(s.sprintf("Queue::addMessage - Message Added To Queue. Ptr=%p", message));
              myMutex.unlock();
            }
            catch (...)
            {
              myMutex.unlock();
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
              // Check to see if there's a Message in the list   
              if (itsMessage.empty() != true)
              {      
                // Get the first message in the list.                                  
                m_Ptr = *itsMessage.begin();  // Get the first Message in the list. 

                // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
                removeItsMessage(m_Ptr);   // Remove the just-sent Message from the list.

                //LogMessage(s.sprintf("Queue::getMessage - Message Being Returned To Application.  Ptr=%p", m_Ptr));
              } 
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
          this->OnLogText(Msg);
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

