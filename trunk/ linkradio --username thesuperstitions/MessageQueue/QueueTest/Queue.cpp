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

static struct timeb previousTime;

struct MessageStruct
{
  unsigned long MsgNumber;
  unsigned char MsgBody[30];
};

        Queue::Queue(unsigned long int numberOfItems) 
        {
          exitFlag = false;
          myMutex.unlock();
          myQueue = new boost::circular_buffer<void*>(numberOfItems);
previousTime.time = 0;
previousTime.millitm = 0;
        }

        
        Queue::~Queue() 
        {
            exitFlag = true;
            myMutex.unlock();  // Wake "getMessage".
            delete myQueue;
        }
        
        void Queue::addMessage(void* message)
        {
            QString s;

            if (exitFlag == true)
              return;

            try
            {
              { // Start of Scope.
                // Get the mutex just long enough to add the message to the queue.
                boost::mutex::scoped_lock myDataAccessLock(myDataAccessMutex); //This lock protects the queue itself.

                myQueue->push_back(message);
              } // End of Scope.

              myMutex.unlock();  // Wake "getMessage".
            }
            catch (...)
            {
              LogMessage(s.sprintf("Queue::addMessage -EXCEPTION"), 0);
            };
        }

        void* Queue::getMessage(unsigned int timeoutSecs, unsigned long int timeoutMicroSecs)
        {
          QString s;

          void* m_Ptr = NULL;

          // Just in case this function gets invoked during shutdown.
          if (exitFlag == true)
            return(NULL);

          try
          {
            // Calculate the duration of the timeout.
            boost::posix_time::time_duration td = boost::posix_time::seconds(timeoutSecs) + boost::posix_time::microseconds(timeoutMicroSecs); //

            // Block on the mutex until either a message is received in the queue (addMessage function unlocks the mutex after dropping a message
            // in the queue), or the timer expires.
            if (myMutex.timed_lock(boost::get_system_time() + td) == true)
            {
              { // Start of scope for the "scoped_lock" mutex.
                boost::mutex::scoped_lock myDataAccessLock(myDataAccessMutex); //This lock protects the queue itself.

                // Check to see if there's a Message in the list   
                if (myQueue->empty() != true)
                {      
                  // Get the first message in the list.                                  
                  m_Ptr = myQueue->front();  
  
                  // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
                  myQueue->pop_front();   // Remove the just-sent Message from the list.

                  //LogMessage(s.sprintf("Queue::getMessage - Message Being Returned To Application.  Ptr=%p, MsgNumber=%u", m_Ptr, msg->MsgNumber));
                }
                else
                {
                  // This should never get hit...
                }
              } // End of Scope for the "scoped_lock" mutex.  This unlocks the timed mutex.
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


        void Queue::LogMessage(QString Msg, double count)
        {
          QString       s;
          struct timeb  t;
          struct tm*    TS;
          int           Hours, Mins, Secs;
          double        deltaTime, iterationsPerSecond, secs, milliSecs;

          ftime(&t);
          Secs = t.time % 86400; // 86400 = Seconds/24 hours
          Hours = Secs / 3600;
          Secs -= Hours * 3600;
          Mins = Secs / 60;
          Secs -= Mins * 60;

          if (previousTime.time == 0)
          {
            previousTime = t;
            deltaTime = 0.0;
            iterationsPerSecond = 0.0;
          }
          else
          {
            secs = (t.time - previousTime.time);
            secs *= 1000.0;
            milliSecs = (t.millitm - previousTime.millitm);
            secs += milliSecs;
            deltaTime = secs / 1000.0;
            iterationsPerSecond = count / deltaTime;
          }
  
          //TS = gmtime( &tt );
          s.sprintf("%02u:%02u:%02u.%03u - Delta Time = %12.3f Secs, Iterations/Sec = %12.3f - ", Hours, Mins, Secs, t.millitm, deltaTime, iterationsPerSecond);
          s += Msg + " : ";
          this->OnLogText(s);
        }

