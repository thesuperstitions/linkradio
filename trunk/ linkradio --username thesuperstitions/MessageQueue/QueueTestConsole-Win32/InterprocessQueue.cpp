//---------------------------------------------------------------------------
/*********************************************************************
	Login		: rosskw1
	Model Element	: Queue
  Generated Date	: Mon, 21, Apr 2008  
	File Path	: Queue.cppmy

  Description: This class uses a boost timed-mutex to provide a means
  by which a user can de-queue messages and have an automatic timeout
  so that if a message isn't de-queued within a user-specified timout,
  control is returned to the user with a NULL pointer.

  For the producer, messages are dropped in the queue and control is
  returned, with a status of "true". If the queue is full, a return
  value of "false" is returned.  The user could then try to queue the
  message again.
*********************************************************************/


#include "InterprocessQueue.h"
#include <boost/interprocess/mapped_region.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/interprocess/sync/scoped_lock.hpp>
#include "boost/thread.hpp"
#include <sys/timeb.h>


using namespace boost::interprocess;

//---------------------------------------------------------------------------


//Constructor

//---------------------------------------------------------------------------
InterprocessQueue::InterprocessQueue(char* queueName, unsigned int maxMessageSizeInBytes=INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES, 
                                     unsigned long int maxNumberOfMessages=INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE) : 
exitFlag(false), queueState(QueueSynchronizing), QueueInitializationSemaphore(0), maxMsgSize(maxMessageSizeInBytes + sizeof(unsigned int)),
maxMsgs(maxNumberOfMessages), totalQueueSize(maxMsgSize * maxMsgs)
{
  bool alreadyCreatedFlag = false;
	char s[300];

  strcpy(QueueName, queueName);

  try
  {
    //Erase previous shared memory
//    shared_memory_object::remove(queueName);

    try
    {
      //Create a shared memory object.
      shm1 = new shared_memory_object(open_only, queueName, read_write);
      alreadyCreatedFlag = true;
			sprintf(s, "Queue Open-Only Succeeded\n");
			LogMessage(s, 0);
		}
    catch (...)
    {
      //Create a shared memory object.
      shm1 = new shared_memory_object(create_only, queueName, read_write);
  
      //Set size
      shm1->truncate(totalQueueSize);
			sprintf(s, "Queue Create-Only Succeeded\n");
			LogMessage(s, 0);
		};

    //Map the whole shared memory in this process
    region1 = new mapped_region
      (*shm1                       //What to map
      ,read_write   //Map it as read-write
      );

    //Get the address of the mapped region
    addr1       = region1->get_address();

    //Construct the shared structure in memory
    myQueue = new (addr1) unsigned char[totalQueueSize];


    sprintf(ControlDataName, "%s%s", queueName, "ControlData");
    //Erase previous shared memory
    //shared_memory_object::remove(ControlDataName);

    if (alreadyCreatedFlag == false)
    {
      //Create a shared memory object.
      shm2 = new shared_memory_object(create_only, ControlDataName, read_write);
			sprintf(s, "Queue Create-Only Succeeded\n");
			LogMessage(s, 0);
    
      //Set size
      shm2->truncate(sizeof(SharedMemoryQueueControlData));
    }
    else
    {
      //Create a shared memory object.
      shm2 = new shared_memory_object(open_only, ControlDataName, read_write);
			sprintf(s, "Queue Open-Only Succeeded\n");
			LogMessage(s, 0);
		}

    //Map the whole shared memory in this process
    region2 = new mapped_region
      (*shm2                       //What to map
      ,read_write   //Map it as read-write
      );

    //Get the address of the mapped region
    addr2       = region2->get_address();

    //Construct the shared structure in memory
    myControlData = new (addr2) SharedMemoryQueueControlData(maxNumberOfMessages);

    myControlData->CurrentReadSlot = 0;
    myControlData->CurrentWriteSlot = 0;
    myControlData->NumberMessagesInQueue = 0;
    myControlData->InterfaceStatus = false;
  }
  catch (...)
  {
    ////char s[300];
    ////sprintf(s, "InterprocessQueue-Server-EXCEPTION\n\n");
    ////LogMessage(s, 0);
  };
}

//---------------------------------------------------------------------------

// Destructor

//---------------------------------------------------------------------------

InterprocessQueue::~InterprocessQueue() 
{
  try
  {
    // Erase shared memory
    exitFlag = true;
//    myControlData->getMsgSemaphore.post();  // Wake "timedGetMessage".
    myControlData->getMsgSemaphore.unlock();  // Wake "timedGetMessage".
    myControlData->myDataAccessMutex.unlock();
    myControlData->addMessageSemaphore.post();

    shared_memory_object::remove(QueueName);
    delete region1;
    delete shm1;
    //Erase previous shared memory
    shared_memory_object::remove(QueueName);

    shared_memory_object::remove(ControlDataName);
    delete region2;
    delete shm2;
    // Erase previous shared memory
    shared_memory_object::remove(ControlDataName);
  }
  catch (...)
  {
  };
}

//**********************************************************************************************************************
//
//  Name: SynchronizeQueueUsers
// 
//  Purpose: This method writes a unique value that's generated using the lower bits of what's returned from "ftime",
//           into a location in shared memory.  It then checks periodically to see if that value has changed, which 
//           indicates that the other user has written its unique value in the same shared memory location.  Once 
//           there's a difference, the Queue is marked as synchronized and the original unique value is written back
//           to the shared memory location to ensure that the other user detects a different value than they last 
//           wrote to the location.
//
//**********************************************************************************************************************

bool InterprocessQueue::SynchronizeQueueUsers(void)
{
  unsigned long uniqueValue, newValue;
  timeb t;

  queueState = QueueSynchronizing;
  ftime(&t);
  srand(t.millitm);

  if (exitFlag == true)
    return(false);

  { // Start of scope.
    scoped_lock<interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
    myControlData->InterfaceStatus = false; // Declare interface "DOWN" so other side knows.
    uniqueValue = myControlData->UniqueValue = (((unsigned long)rand()) * 1000) % 10000;
  } // End of scope.

  QueueInitializationSemaphore.timed_wait(boost::get_system_time() + boost::posix_time::seconds(0) + 
    boost::posix_time::microseconds(uniqueValue));

  { // Start of scope.
    scoped_lock<interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
    newValue = myControlData->UniqueValue;
  } // End of scope.

  if (newValue != uniqueValue)
  {
    { // Start of scope.
      scoped_lock<interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.

      // Now change the shared memory location to force the other process that this process is ready.
      myControlData->UniqueValue = (((unsigned long)rand()) * 1000) % 1000000;
      myControlData->InterfaceStatus = true; // Declare interface "UP" so other side knows.
    } // End of scope.

    queueState = QueueSynchronized;
    return(true);
  }

  return(false);
}

InterprocessQueue::QueueState InterprocessQueue::getQueueState(void)
{
	bool sharedMemoryQueueState;

  { // Start of scope.
    scoped_lock<interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
		sharedMemoryQueueState = myControlData->InterfaceStatus;
  } // End of scope.

  if ((sharedMemoryQueueState == false) || (queueState == QueueSynchronizing) )
		return(QueueSynchronizing);
	else
		return(QueueSynchronized);
}

//---------------------------------------------------------------------------
//
// timedAddMessage
//
// User adds messages by calling "addMessage".  Returns "true" if
// successful (queue not full) or "false" if unsuccessful (queue full).
//
//---------------------------------------------------------------------------

bool InterprocessQueue::timedAddMessage(unsigned char* message, unsigned int messageSizeInBytes, 
                                        unsigned int timeoutSecs, unsigned long int timeoutMicroSecs)
{
  // Just in case this function gets invoked during shutdown or is synchronizing or the other side takes the interface down.
  if ((exitFlag == true) || (queueState == QueueSynchronizing) || (myControlData->InterfaceStatus == false) )
    return(false);
  try
  {
    if(myControlData->addMessageSemaphore.timed_wait(boost::get_system_time() + boost::posix_time::seconds(timeoutSecs) + 
    boost::posix_time::microseconds(timeoutMicroSecs)) == false)
      return(false);

    { // Start of Scope.
      // Get the mutex just long enough to add the message to the queue.
      scoped_lock<interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
      
      if (myControlData->NumberMessagesInQueue >= maxMsgs)
        return(false);

      unsigned char* ptr = &(myQueue[myControlData->CurrentWriteSlot*maxMsgSize]);
      ((unsigned int*)ptr)[0] = messageSizeInBytes; // Put the # of Message-bytes at front of message.

      ptr += sizeof(unsigned int);  // Set the pointer past the byte-count, to the message portion of the buffer.

      memcpy(ptr, message, messageSizeInBytes);

      myControlData->NumberMessagesInQueue++;

      ++myControlData->CurrentWriteSlot %= maxMsgs;

//      myControlData->getMsgSemaphore.post();  // Wake "timedGetMessage".
      myControlData->getMsgSemaphore.unlock();  // Wake "timedGetMessage".

      return(true); // Message was queued
    } // End of Scope.
  }
  catch (...)
  {
  };
  return(false);
}

bool InterprocessQueue::getMessage(unsigned char* msg, bool semTookFlag)
{
  // Just in case this function gets invoked during shutdown.
  if (exitFlag == true)
    return(false);

  scoped_lock<interprocess_mutex> myDataAccessLock(myControlData->myDataAccessMutex); //This lock protects the queue itself.

  // Check to see if the the "Producer" has declared the interface "DOWN".  If so, we'll go back into "Synchronizing" state.
  if (myControlData->InterfaceStatus == false)
    return(false);


  // Check to see if there's a Message in the list   
  if (myControlData->NumberMessagesInQueue > 0)
  {      
    // Get the first message in the list.                                  
    memcpy(msg, &(myQueue[(myControlData->CurrentReadSlot*maxMsgSize)+sizeof(unsigned int)]), 
      *((unsigned int*)&(myQueue[myControlData->CurrentReadSlot*maxMsgSize])));

    // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
    myControlData->NumberMessagesInQueue--; 
    
    ++myControlData->CurrentReadSlot %= maxMsgs;

    myControlData->addMessageSemaphore.post();

    return(true);
  }
  else
    return(false);
}

//---------------------------------------------------------------------------
        
// timedGetMessage

// Immediately check to see if the thread should exit.  Check to see if there
// is a message in the queue and, if so, return it to the user.  If not, wait
// up to the user-defined timeout.  If a message becomes available in the
// queue within the timeout period, return the message.  If not, return a 
// NULL pointer.
//---------------------------------------------------------------------------
//static  timeb         t, f;

bool InterprocessQueue::timedGetMessage(unsigned char* msg, unsigned int timeoutSecs, unsigned long int timeoutMicroSecs)
{
  // Just in case this function gets invoked during shutdown.
  //if (exitFlag == true)
  //  return(false);
  bool          result;
  unsigned long msgCount;

  try
  {
    if (getMessage(msg, false) == true)
    {
      //ftime(&t);
      return(true);
    }

    do
    {
      result = myControlData->getMsgSemaphore.timed_lock(boost::get_system_time() + boost::posix_time::seconds(timeoutSecs) + 
        boost::posix_time::microseconds(timeoutMicroSecs));

      {
        scoped_lock<interprocess_mutex> myDataAccessLock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
        msgCount = myControlData->NumberMessagesInQueue;
      }
      //if (result == true)
      //{
      //  if (msgCount == 0)
      //  {
      //    //ftime(&f);
      //    //printf("\n#1-result=true, msgCount=%u, DSecs=%u, Dms=%u", msgCount, f.time-t.time, f.millitm-t.millitm);
      //  }
      //}
      //else
      //{
      //  //ftime(&f);
      //  //printf("\n#1-result=false, msgCount=%u, DSecs=%u, Dms=%u", msgCount, f.time-t.time, f.millitm-t.millitm);
      //}
    } while ((result == true) && (msgCount == 0));
    

    if (result == true)
    {
      result = getMessage(msg, true);
      //if (result == true)
      //{
      //  ftime(&t);
      //  //printf("\n#2-result=true, msgCount=%u", msgCount);
      //}
      //else
      //{
      //  ftime(&f);
      //  printf("\n#2-result=false, msgCount=%u, DSecs=%u, Dms=%u", msgCount, f.time-t.time, f.millitm-t.millitm);
      //}
      return(result);
    }
    //{

      //if (queueState == QueueSynchronizing)
      //  return(false);

      //scoped_lock<interprocess_mutex> myDataAccessLock(myControlData->myDataAccessMutex); //This lock protects the queue itself.

      //// Check to see if the the "Producer" has declared the interface "DOWN".  If so, we'll go back into "Synchronizing" state.
      //if (myControlData->InterfaceStatus == false)
      //  return(false);


      //// Check to see if there's a Message in the list   
      //if (myControlData->NumberMessagesInQueue > 0)
      //{      
      //  // Get the first message in the list.                                  
      //  //unsigned int msgBytes = *((unsigned int*)&(myQueue[myControlData->CurrentReadSlot*maxMsgSize]));

      //  memcpy(msg, &(myQueue[(myControlData->CurrentReadSlot*maxMsgSize)+sizeof(unsigned int)]), 
      //    *((unsigned int*)&(myQueue[myControlData->CurrentReadSlot*maxMsgSize])));

      //  // Remove the message from the list now so that the mutex can be unlocked prior to sending.  
      //  myControlData->NumberMessagesInQueue--; 
    
      //  //myControlData->CurrentReadSlot++;
      //  ++myControlData->CurrentReadSlot %= maxMsgs;
      //  myControlData->addMessageSemaphore.post();

      //  return(true);
      //}
      //else
      //  return(false);
    //}
    //else
    //  return(false);
  }
  catch(...)
  {
    //printf("\n#3-result=false, msgCount=%u, DSecs=%u, Dms=%u", msgCount, f.time-t.time, f.millitm-t.millitm);
    //return(false);
  };

  //printf("\n#4-result=false, msgCount=%u, DSecs=%u, Dms=%u", msgCount, f.time-t.time, f.millitm-t.millitm);
  //return(false);
}


static timeb  previousTime;
static double previousCount;

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
            iterationsPerSecond = (count-previousCount) / deltaTime;
          }
          previousTime = t;
          previousCount = count;
  
          //TS = gmtime( &tt );
          printf("%02u:%02u:%02u.%03u-DT=%7.3f S, Iter/Sec=%10.3f : %s", Hours, Mins, Secs, t.millitm, deltaTime, iterationsPerSecond, Msg);
        }


