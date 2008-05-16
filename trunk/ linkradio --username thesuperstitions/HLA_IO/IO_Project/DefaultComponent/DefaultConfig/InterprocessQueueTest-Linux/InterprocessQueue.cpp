/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::InterprocessQueue
//!	Generated Date	: Thu, 15, May 2008  
	File Path	: DefaultComponent\DefaultConfig\InterprocessQueueTest-Linux\InterprocessQueue.cpp
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
#include "InterprocessQueue.h"
// dependency interprocess 
#include <interprocess.h>
// link itsC_IO_Functions 
#include "C_IO_Functions.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"

//----------------------------------------------------------------------------
// InterprocessQueueTest-Linux\InterprocessQueue.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

//## class InterprocessQueue 

namespace Framework {
    namespace utils {
        
        
        InterprocessQueue::InterprocessQueue(std::string queueName, unsigned int maxMessageSizeInBytes, unsigned long maxNumberOfMessages) : 
        exitFlag(false), queueState(QueueSynchronizing), QueueInitializationSemaphore(0), maxMsgSize(maxMessageSizeInBytes + sizeof(unsigned int)),
        maxMsgs(maxNumberOfMessages), totalQueueSize(maxMsgSize * maxMsgs)
         {
            itsFederateIO_Handler = NULL;
            itsC_IO_Functions = NULL;
            //#[ operation InterprocessQueue(std::string,unsigned int,unsigned long) 
            bool alreadyCreatedFlag = false;
            
            strcpy(QueueName, queueName);
            
            try
            {
              try
              {
                //Create a shared memory object.
                shm1 = new shared_memory_object(open_only, queueName, read_write);
                alreadyCreatedFlag = true;
            	}
              catch (...)
              {
                //Create a shared memory object.
                shm1 = new shared_memory_object(create_only, queueName, read_write);
            
                //Set size
                shm1->truncate(totalQueueSize);
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
            
                //Set size
                shm2->truncate(sizeof(SharedMemoryQueueControlData));
              }
              else
              {
                //Create a shared memory object.
                shm2 = new shared_memory_object(open_only, ControlDataName, read_write);
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
            };
            //#]
        }
        
        InterprocessQueue::~InterprocessQueue() {
            //#[ operation ~InterprocessQueue() 
            try
            {
              exitFlag = true;
              myControlData->getMsgSemaphore.post();  // Wake "timedGetMessage".
              myControlData->myDataAccessMutex.unlock();
              myControlData->addMessageSemaphore.post();
            
              shared_memory_object::remove(QueueName);
              delete region1;
              delete shm1;
            
              shared_memory_object::remove(ControlDataName);
              delete region2;
              delete shm2;
            
              //Erase shared memory
            	shared_memory_object::remove(QueueName);
            	shared_memory_object::remove(ControlDataName);
            }
            catch (...)
            {
            };
            //#]
        }
        
        bool InterprocessQueue::SynchronizeQueueUsers() {
            //#[ operation SynchronizeQueueUsers() 
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
            //#]
        }
        
        bool InterprocessQueue::timedAddMessage(unsigned char * message, unsigned int messageSizeInBytes, unsigned int timeoutSecs, unsigned long timeoutMicroSecs) {
            //#[ operation timedAddMessage(unsigned char *,unsigned int,unsigned int,unsigned long) 
            { // Start of Scope.
            // Get the mutex just long enough to add the message to the queue.
            	scoped_lock<interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
            
            // Just in case this function gets invoked during shutdown or is synchronizing or the other side takes the interface down.
            if ((exitFlag == true) || (queueState == QueueSynchronizing) || (myControlData->InterfaceStatus == false) )
              return(false);
            } // End of Scope.
            
            try
            {
            	// Wait for the specified amount of time for a message to come into the queue.
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
        
        bool InterprocessQueue::timedGetMessage(unsigned char * msg, unsigned int* messageSizeInBytes, unsigned int timeoutSecs, unsigned long timeoutMicroSecs) {
            //#[ operation timedGetMessage(unsigned char *,unsigned int*,unsigned int,unsigned long) 
            // Just in case this function gets invoked during shutdown.
            if (exitFlag == true)
              return(false);
            
            try
            {
            	// Wait on a semaphore that indicates that there is room in the queue for another message.
              if (myControlData->getMsgSemaphore.timed_wait(boost::get_system_time() + boost::posix_time::seconds(timeoutSecs) +
                  boost::posix_time::microseconds(timeoutMicroSecs)) == true)
              {
            		//This lock protects the queue itself.
                scoped_lock<interprocess_mutex> myDataAccessLock(myControlData->myDataAccessMutex);
                                     
                // Check to see if the the "Producer" has declared the interface "DOWN".  If so, we'll go back into
            		// "Synchronizing" state.
                if (myControlData->InterfaceStatus == false)
                  return(false);
            
                // Copy the message into the from the queue into the user's buffer.
                *messageSizeInBytes = *((unsigned int*)&(myQueue[myControlData->CurrentReadSlot*maxMsgSize]))
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
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\InterprocessQueueTest-Linux\InterprocessQueue.cpp
*********************************************************************/

