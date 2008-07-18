/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: InterprocessQueue
//!	Generated Date	: Tue, 15, Jul 2008  
	File Path	: DefaultComponent\DefaultConfig\InterprocessPubSub\InterprocessQueue.cpp
*********************************************************************/

// dependency mapped_region 
#include <boost\interprocess\mapped_region.hpp>
// dependency posix_time 
#include "boost\date_time\posix_time\posix_time.hpp"
// dependency scoped_lock 
#include <boost\interprocess\sync\scoped_lock.hpp>
// dependency thread 
#include "boost\thread.hpp"
// dependency timeb 
#include <sys\timeb.h>
#include "InterprocessPubSub\InterprocessQueue.h"

//----------------------------------------------------------------------------
// InterprocessPubSub\InterprocessQueue.cpp                                                                  
//----------------------------------------------------------------------------

//## package InterprocessPubSub 

//## class InterprocessQueue 



InterprocessQueue::InterprocessQueue(const char * queueName, unsigned int maxMessageSizeInBytes, unsigned long maxNumberOfMessages) : 
exitFlag(false), QueueInitializationSemaphore(0), 
maxMsgSize(maxMessageSizeInBytes + sizeof(unsigned int)),
maxMsgs(maxNumberOfMessages), totalQueueSize(maxMsgSize * maxMsgs)
 {
    //#[ operation InterprocessQueue(const char *,unsigned int,unsigned long) 
    bool alreadyCreatedFlag = false;
    
    strcpy(QueueName, queueName);
    
    try
    {
      try
      {
        //Create a shared memory object.
        shm1 = new boost::interprocess::shared_memory_object(boost::interprocess::create_only, queueName, boost::interprocess::read_write);
    
        //Set size
        shm1->truncate(totalQueueSize);
    	}
      catch (...)
      {
        //Create a shared memory object.
        shm1 = new boost::interprocess::shared_memory_object(boost::interprocess::open_only, queueName, boost::interprocess::read_write);
      };
    
      region1 = new boost::interprocess::mapped_region
        (*shm1                       //What to map
        ,boost::interprocess::read_write   //Map it as read-write
        );
    
      //Get the address of the mapped region
      addr1 = region1->get_address();
    
      //Construct the shared structure in memory
      myQueue = new (addr1) unsigned char[totalQueueSize];
      //printf("\nInterprocessQueue-QName=%s, Qadd=0x%x, Qsize=%u\n", queueName, myQueue, totalQueueSize);
    
    
      sprintf(ControlDataName, "%sControlData", queueName);
    
      try
      {
        //Create a shared memory object.
        shm2 = new boost::interprocess::shared_memory_object(boost::interprocess::create_only, ControlDataName, boost::interprocess::read_write);
    
        //Set size
        shm2->truncate(sizeof(SharedMemoryQueueControlData));
      }
      catch (...)
      {
        //Create a shared memory object.
        shm2 = new boost::interprocess::shared_memory_object(boost::interprocess::open_only, ControlDataName, boost::interprocess::read_write);
        alreadyCreatedFlag = true;
    	}
    
      //Map the whole shared memory in this process
      region2 = new boost::interprocess::mapped_region
        (*shm2                       //What to map
        ,boost::interprocess::read_write   //Map it as read-write
        );
    
      //Get the address of the mapped region
      addr2       = region2->get_address();
    
      //Construct the shared structure in memory
      myControlData = new (addr2) SharedMemoryQueueControlData(maxMsgs);
    
      if (alreadyCreatedFlag != true)
      {
        //myControlData->getMsgSemaphore = 0;
        //myControlData->addMessageSemaphore = maxMsgs;
        myControlData->CurrentReadSlot = 0;
        myControlData->CurrentWriteSlot = 0;
        myControlData->NumberMessagesInQueue = 0;
        myControlData->InterfaceStatus = false;
      }
      else
      {
        myControlData->InterfaceStatus = true;
        //queueState = QueueSynchronized;
        //printf("\nInterprocessQueue::InterprocessQueue-Queue Synching Complete");
      }
    
    }
    catch (...)
    {
    };
    //#]
}

InterprocessQueue::~InterprocessQueue() {
    //#[ operation ~InterprocessQueue() 
    bool result1, result2;
    try
    {
      exitFlag = true;
    
    { // Start of scope.
      boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
      myControlData->getMsgSemaphore.post();  // Wake "timedGetMessage".
      myControlData->myDataAccessMutex.unlock();
      myControlData->addMessageSemaphore.post();
      myControlData->InterfaceStatus = false;
    } // End of scope.
    
      delete region1;
      delete shm1;
      result1 = boost::interprocess::shared_memory_object::remove(QueueName);
    
      delete region2;
      delete shm2;
      result2 = boost::interprocess::shared_memory_object::remove(ControlDataName);
    }
    catch (...)
    {
    };
    //#]
}

bool InterprocessQueue::addMessage(const unsigned char* message, unsigned int* messageSizeInBytes) {
    //#[ operation addMessage(const unsigned char*,unsigned int*) 
    try
    {
      // Just in case this function gets invoked during shutdown.
      if (exitFlag == true)
        return(false);
    
      if (getQueueState() == QueueSynchronizing)
          return(false);
    
      { // Start of Scope.
        // Get the mutex just long enough to add the message to the queue.
    	  boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
    
        // If the queue is full, pull the 1st message out to make room for the new message.  Keep only the freshest data.  
        if (myControlData->NumberMessagesInQueue >= maxMsgs)
        {
          myControlData->NumberMessagesInQueue--; // Decrement # messages in the queue.
    
          ++myControlData->CurrentReadSlot %= maxMsgs; // Move pointer to next message in the queue.
        }
    
        unsigned char* ptr = &(myQueue[myControlData->CurrentWriteSlot*maxMsgSize]);
        (unsigned int*)ptr[0] = *messageSizeInBytes; // Put the # of Message-bytes at front of message.
    
        ptr += sizeof(unsigned int);  // Set the pointer past the byte-count, to the message portion of the buffer.
        memcpy(ptr, message, messageSizeInBytes);
    
        myControlData->NumberMessagesInQueue++;
    
        ++myControlData->CurrentWriteSlot %= maxMsgs;
    
        return(true); // Message was queued
      } // End of Scope.
    }
    catch (...)
    {
    	return(false);
    };
    return(false);
    //#]
}

InterprocessQueue::QueueState InterprocessQueue::getQueueState() {
    //#[ operation getQueueState() 
    bool sharedMemoryQueueState;
    
    { // Start of scope.
    boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
    	sharedMemoryQueueState = myControlData->InterfaceStatus;
    } // End of scope.
    
    if (sharedMemoryQueueState == true)
    {
    return(QueueSynchronized);
    }
    else
    return(QueueSynchronizing);
    //#]
}

bool InterprocessQueue::timedAddMessage(const unsigned char * message, unsigned int messageSizeInBytes, unsigned int timeoutSecs, unsigned long timeoutMicroSecs) {
    //#[ operation timedAddMessage(const unsigned char *,unsigned int,unsigned int,unsigned long) 
    try
    {
      // Just in case this function gets invoked during shutdown.
      if (exitFlag == true)
        return(false);
    
      if (getQueueState() == QueueSynchronizing)
          return(false);
    
      { // Start of Scope.
        // Get the mutex just long enough to add the message to the queue.
    	  boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
    
        // If the queue is full, pull the 1st message out to make room for the new message.  Keep only the freshest data.  
        if (myControlData->NumberMessagesInQueue >= maxMsgs)
        {
    //      unsigned char msg[INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES];
    //      unsigned int messageSizeInBytes;
    
          // Copy the message into the from the queue into the user's buffer.
    //	  messageSizeInBytes = *((unsigned int*)&(myQueue[myControlData->CurrentReadSlot*maxMsgSize]));
    //      memcpy(&msg, &(myQueue[(myControlData->CurrentReadSlot*maxMsgSize)+sizeof(unsigned int)]), messageSizeInBytes);
    
          myControlData->NumberMessagesInQueue--; // Decrement # messages in the queue.
    
          ++myControlData->CurrentReadSlot %= maxMsgs; // Move pointer to next message in the queue.
          myControlData->addMessageSemaphore.post();   // Indicate that there's now room in the queue for another message.
        }
      } // End of Scope.
    
      // Wait for the specified amount of time for a message to come into the queue.
      if(myControlData->addMessageSemaphore.timed_wait(boost::get_system_time() + boost::posix_time::seconds(timeoutSecs) +
      boost::posix_time::microseconds(timeoutMicroSecs)) == false)
        return(false);
    
      { // Start of Scope.
        // Get the mutex just long enough to add the message to the queue.
        boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
    
        unsigned char* ptr = &(myQueue[myControlData->CurrentWriteSlot*maxMsgSize]);
        ((unsigned int*)ptr)[0] = messageSizeInBytes; // Put the # of Message-bytes at front of message.
    
        ptr += sizeof(unsigned int);  // Set the pointer past the byte-count, to the message portion of the buffer.
        memcpy(ptr, message, messageSizeInBytes);
    
        myControlData->NumberMessagesInQueue++;
    
        ++myControlData->CurrentWriteSlot %= maxMsgs;
    
        myControlData->getMsgSemaphore.post();  // Wake "timedGetMessage".
    
        return(true); // Message was queued
      } // End of Scope.
    }
    catch (...)
    {
    	return(false);
    };
    return(false);
    //#]
}

bool InterprocessQueue::timedGetMessage(unsigned char * msg, unsigned * messageSizeInBytes, unsigned int timeoutSecs, unsigned long timeoutMicroSecs) {
    //#[ operation timedGetMessage(unsigned char *,unsigned *,unsigned int,unsigned long) 
    try
    {
      // Just in case this function gets invoked during shutdown.
      if (exitFlag == true)
        return(false);
    
      if (getQueueState() == QueueSynchronizing)
          return (false);
    
    	// Wait on a semaphore that indicates that there is room in the queue for another message.
      if (myControlData->getMsgSemaphore.timed_wait(boost::get_system_time() + boost::posix_time::seconds(timeoutSecs) +
          boost::posix_time::microseconds(timeoutMicroSecs)) == true)
      {
    		//This lock protects the queue itself.
        boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> myDataAccessLock(myControlData->myDataAccessMutex);
    
        // Copy the message into the from the queue into the user's buffer.
    		*messageSizeInBytes = *((unsigned int*)&(myQueue[myControlData->CurrentReadSlot*maxMsgSize]));
        memcpy(msg, &(myQueue[(myControlData->CurrentReadSlot*maxMsgSize)+sizeof(unsigned int)]), *messageSizeInBytes);
    
        myControlData->NumberMessagesInQueue--; // Decrement # messages in the queue.
    
        ++myControlData->CurrentReadSlot %= maxMsgs; // Move pointer to next message in the queue.
        myControlData->addMessageSemaphore.post();   // Indicate that there's now room in the queue for another message.
    
        return(true);
      }
      else
        return(false);
    }
    catch(...)
    {
      return(false);
    };
    
    return(false);
    //#]
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\InterprocessPubSub\InterprocessQueue.cpp
*********************************************************************/

