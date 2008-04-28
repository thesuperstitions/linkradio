//---------------------------------------------------------------------------
/*********************************************************************
	Login		: rosskw1
	Model Element	: Queue
  Generated Date	: Mon, 21, Apr 2008  
	File Path	: Queue.cpp

  Description: This class uses a boost timed-mutex to provide a means
  by which a user can de-queue messages and have an automatic timeout
  so that if a message isn't de-queued within a user-specified timout,
  control is returned to the user with a NULL pointer.

  For the producer, messages are dropped in the queue and control is
  returned, with a status of "true". If the queue is full, a return
  value of "false" is returned.  The user could then try to queue the
  message again.
*********************************************************************/


#include "Queue.h"
#include "boost/thread.hpp"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::interprocess;

//---------------------------------------------------------------------------


//Constructor

//---------------------------------------------------------------------------
InterprocessQueue::InterprocessQueue(char* queueName, UserType uType)
{
  exitFlag = false;
  strcpy(QueueName, queueName);

  //Erase previous shared memory
  if (uType == IPQ_SERVER)
    shared_memory_object::remove(queueName);

  //Create a shared memory object.
  shm = new shared_memory_object
    (open_or_create               //open or create
     ,queueName           //name
     ,read_write   //read-write mode
     );

    //Set size
    shm->truncate(sizeof(Shared_Memory_Queue));

    //Map the whole shared memory in this process
    region = new mapped_region
      (*shm                       //What to map
      ,read_write   //Map it as read-write
      );

    //Get the address of the mapped region
    addr       = region->get_address();

    //Construct the shared structure in memory
    myQueue = new (addr) Shared_Memory_Queue();

    myQueue->CurrentReadSlot = 0;
    myQueue->CurrentWriteSlot = 0;
    myQueue->NumberMessagesInQueue = 0;

    myQueue->myMutex.unlock();
}

//---------------------------------------------------------------------------

// Destructor

//---------------------------------------------------------------------------

InterprocessQueue::~InterprocessQueue() 
{
  //Erase shared memory
  shared_memory_object::remove(QueueName);
  delete region;
  delete shm;

  exitFlag = true;
  myQueue->myMutex.unlock();  // Wake "getMessage".
}

//---------------------------------------------------------------------------

// addMessage

// User adds messages by calling "addMessage".  Returns "true" if
// successful (queue not full) or "false" if unsuccessful (queue full).

//---------------------------------------------------------------------------
        
bool InterprocessQueue::addMessage(unsigned char* message, unsigned int messageSizeInBytes)
{
  //char s[200];

  if (exitFlag == true)
    return(false);
  
  try
  {
    { // Start of Scope.
      // Get the mutex just long enough to add the message to the queue.
      scoped_lock<interprocess_mutex> lock(myQueue->myDataAccessMutex); //This lock protects the queue itself.

      if (myQueue->NumberMessagesInQueue == MAX_MESSAGES_IN_QUEUE)
      {
        //sprintf(s, "****ExceededQueuCapacity****\n\n");
        //LogMessage(s, 0.0);
        return(false);
      }
      memcpy(&(myQueue->messages[myQueue->CurrentWriteSlot]), message, messageSizeInBytes);

      myQueue->NumberMessagesInQueue++;
      //myQueue->NumberMessagesInQueue %= MAX_MESSAGES_IN_QUEUE;

      myQueue->CurrentWriteSlot++;
      myQueue->CurrentWriteSlot %= MAX_MESSAGES_IN_QUEUE;
    
      //myQueue->CurrentWriteSlot %= MAX_MESSAGES_IN_QUEUE;

      myQueue->myMutex.unlock();  // Wake "getMessage".
//printf("Queued Message - Address=%p\n\n", &(myQueue->messages[myQueue->CurrentWriteSlot]));

      return(true); // Message was queued
    } // End of Scope.
  }
  catch (...)
  {
  };
  return(false);
}

//---------------------------------------------------------------------------

// CheckForMessage

// Waits on a mutex that protects access to the queue.  When mutex is received,
// a check is made to see if there's at least one message in the queue.  If
// not, a NULL pointer is returned.  If not empty, the first message (the 
// oldest one) is taken off the queue and passed back to the caller.
//---------------------------------------------------------------------------

void* InterprocessQueue::CheckForMessage(genericMessage* msg)
{ // Start of scope for the "scoped_lock" mutex.
  void* m_Ptr;

  //boost::mutex::scoped_lock myDataAccessLock(myDataAccessMutex); //This lock protects the queue itself.
  scoped_lock<interprocess_mutex> myDataAccessLock(myQueue->myDataAccessMutex); //This lock protects the queue itself.


  // Check to see if there's a Message in the list   
  if (myQueue->NumberMessagesInQueue > 0)
  {      
    // Get the first message in the list.                                  
    m_Ptr = &(myQueue->messages[myQueue->CurrentReadSlot]);  
    memcpy(msg, m_Ptr, sizeof(genericMessage));

    // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
    myQueue->NumberMessagesInQueue--; 
    myQueue->CurrentReadSlot++;
    
    myQueue->CurrentReadSlot %= MAX_MESSAGES_IN_QUEUE;
    //if (myQueue->CurrentReadSlot == MAX_MESSAGES_IN_QUEUE)// Remove the just-sent Message from the list.
    //  myQueue->CurrentReadSlot= 0;

    return(msg);
  }
  return(NULL);
} // End of Scope for the "scoped_lock" mutex.  This unlocks the timed mutex.

//---------------------------------------------------------------------------
        
// getMessage

// Immediately check to see if the thread should exit.  Check to see if there
// is a message in the queue and, if so, return it to the user.  If not, wait
// up to the user-defined timeout.  If a message becomes available in the
// queue within the timeout period, return the message.  If not, return a 
// NULL pointer.
//---------------------------------------------------------------------------

void* InterprocessQueue::getMessage(genericMessage* msg, unsigned int timeoutSecs, unsigned long int timeoutMicroSecs)
{
  void* m_Ptr;

  // Just in case this function gets invoked during shutdown.
  if (exitFlag == true)
    return(NULL);

  try
  {
    // Check to see if there's a message already waiting on the Queue.  If so, we just return it.
    if ( (m_Ptr = CheckForMessage(msg)) != NULL)
      return(m_Ptr);

    // There were no items in the Queue, so now we have to wait for either the queue to be unlocked or the timeout occurs.

    // Calculate the duration of the timeout.
    boost::posix_time::time_duration td = boost::posix_time::seconds(timeoutSecs) + boost::posix_time::microseconds(timeoutMicroSecs); //

    // Block on the mutex until either a message is received in the queue (addMessage function unlocks the mutex after dropping a message
    // in the queue), or the timer expires.
    if (myQueue->myMutex.timed_lock(boost::get_system_time() + td) == true)
    {
      return( CheckForMessage(msg) );
    }
    else
    {
      // mutex timed out
      return(NULL);
    }
  }
  catch(...)
  {
  };

  return(NULL);
}


static struct timeb previousTime;

        void InterprocessQueue::LogMessage(char* Msg, double count)
        {
          struct timeb  t;
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
          printf("%02u:%02u:%02u.%03u-DT=%7.3f S, Iter/Sec=%10.3f : %s", Hours, Mins, Secs, t.millitm, deltaTime, iterationsPerSecond, Msg);
        }


