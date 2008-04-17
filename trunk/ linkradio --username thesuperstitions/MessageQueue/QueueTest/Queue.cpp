//---------------------------------------------------------------------------

#include "Queue.h"
#include "boost/thread.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/thread/xtime.hpp>
#include <stdio.h>
#include <time.h>
#include <sys\timeb.h>
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

                myQueue.push_back(message);
              } // End of Scope.

              myMutex.unlock();  // Wake "getMessage".
            }
            catch (...)
            {
              LogMessage(s.sprintf("Queue::addMessage -EXCEPTION"));
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
                if (myQueue.empty() != true)
                {      
                  // Get the first message in the list.                                  
                  m_Ptr = myQueue.front();  // Get the first Message in the list. 
  
                  // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
                  myQueue.pop_front();   // Remove the just-sent Message from the list.
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
          catch(...)
          {
            //LogMessage(s.sprintf("Queue::getMessage - EXCEPTION"));
          };

          return(m_Ptr);
        }

        void Queue::LogMessage(QString Msg)
        {
          QString       s;
          struct timeb  t;
//          struct time_t tt;
          struct tm*    TS;
          int           Hours, Mins, Secs;

          // Grab the time in secs since 1/1/1970 GMT.
//          tt = time(NULL);
          ftime(&t);
          Secs = t.time % 86400; // 86400 = Seconds/24 hours
          Hours = Secs / 3600;
          Secs -= Hours * 3600;
          Mins = Secs / 60;
          Secs -= Mins * 60;
  
          //TS = gmtime( &tt );
          s.sprintf("%02u:%02u:%02u.%03u - ", Hours, Mins, Secs, t.millitm);
          s += Msg + " : ";
          this->OnLogText(s);
        }
        
        void Queue::cleanUpRelations()
        {
          while (myQueue.empty() != true)
            myQueue.pop_front();
        }

