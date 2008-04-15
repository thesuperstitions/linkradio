//---------------------------------------------------------------------------

#include "Queue.h"
//#include "boost/bind.hpp"
//#include "boost/date_time/time_duration.hpp"
#include "boost/thread.hpp"
#include <boost/thread/xtime.hpp>
#include <stdio.h>
#include <time.h>

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


        
        Queue::~Queue() {
            cleanUpRelations();
        }
        
        void Queue::addMessage(void* message)
        {
            //#[ operation addMessage(void*)
            try
            {
              myMutex.lock();

              this->addItsMessage(message);
              myMutex.unlock();
            }
            catch (...)
            {
              myMutex.unlock();
            };

            //#]
        }

        void* Queue::getMessage(unsigned int timeoutSecs, unsigned long int timeoutNanoSecs)
        {
          void* m_Ptr;
          boost::condition c; 
          boost::xtime xt;
          boost::xtime_get(&xt,boost::TIME_UTC);
          xt.sec += timeoutSecs;
          xt.nsec += timeoutNanoSecs;
          //boost::system_time xt = boost::get_system_time()+boost::posix_time::nanoseconds(timeoutNanoSecs);

//          boost::timed_mutex::scoped_lock lock(myMutex);

//          boost::date_time::time_duration td(0, 0, timeoutSecs + nanoseconds(timeoutNanoSecs); 

          boost::timed_mutex::scoped_timed_lock lock(myMutex, xt);
          bool b = lock ? true : false;

          if (b == true)
          {
            // Check to see if there's a Message in the list   
            if (itsMessage.empty() != true)
            {      
              // Get the first message in the list.                                  
              m_Ptr = *itsMessage.begin();  // Get the first Message in the list. 

              // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
              removeItsMessage(m_Ptr);   // Remove the just-sent Message from the list.
                
              // Send the message to the back to the application for delivery.  
              return(m_Ptr);
            } 
            else
              return(NULL); // The mutex unlocked but no message was in the queue.  Should NOT occur.
          }
          else
          {
            // mutex timed out
            return(NULL);
          }
        }

        QString* Queue::LogMessage(QString* Msg)
        {
          QString s = *Msg;

          char        timedate[300];
          time_t      t;
          struct tm*  TS;
  
          t = time(NULL);
          TS = gmtime( &t );
          Msg->sprintf("%02u:%02u:%02u %02u/%02u/%4u - %s", TS->tm_hour, TS->tm_min, TS->tm_sec, TS->tm_mon, TS->tm_mday, TS->tm_year+1900, s.c_string());
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

