/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: InterprocessQueue
//!	Generated Date	: Tue, 15, Jul 2008  
	File Path	: DefaultComponent\DefaultConfig\InterprocessQueue.h
*********************************************************************/


#ifndef InterprocessQueue_H 

#define InterprocessQueue_H 

#include "InterprocessPubSub.h"
// dependency SharedMemoryQueueControlData 
#include "SharedMemoryQueueControlData.h"
#include "boost\interprocess\shared_memory_object.hpp"
#include "boost\interprocess\sync\interprocess_semaphore.hpp"
#include "boost\interprocess\sync\interprocess_mutex.hpp"

//----------------------------------------------------------------------------
// InterprocessQueue.h                                                                  
//----------------------------------------------------------------------------

//## package InterprocessPubSub 


//## class InterprocessQueue 
class InterprocessQueue  {
public :
    //## type QueueState 
    enum QueueState {
        QueueSynchronizing = 0,
        QueueSynchronized = 1



    };
    
    


////    Constructors and destructors    ////
public :
    
    // ---------------------------------------------------------------------------
    //## operation InterprocessQueue(const char *,unsigned int,unsigned long) 
    InterprocessQueue(const char * queueName, unsigned int maxMessageSizeInBytes = INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES, unsigned long maxNumberOfMessages = INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE);
    
    // ## operation Queue()
    //## operation ~InterprocessQueue() 
    virtual ~InterprocessQueue();


////    Operations    ////
public :
    
    //## operation LogMessage(char*,double) 
    void LogMessage(char* Msg, double count);
    
    // **********************************************************************************************************************
    // 
    //  Name: getQueueState
    // 
    //  Purpose: Determines if either itself or the "Queue Partner" has taken the interface down.
    //           Returns "QueueState".
    // 
    //           QueueSynchronizing = Queue interface is down.
    // 
    //           QueueSynchronized = Queue interface is operational.
    // 
    // **********************************************************************************************************************
    //## operation getQueueState() 
    virtual QueueState getQueueState();
    
    // ## operation addMessage(FederateMessage*)
    //## operation timedAddMessage(const unsigned char *,unsigned int,unsigned int,unsigned long) 
    virtual bool timedAddMessage(const unsigned char * message, unsigned int messageSizeInBytes, unsigned int timeoutSecs, unsigned long timeoutMicroSecs);
    
    // Immediately check to see if the thread should exit.  Check to see if there
    // is a message in the queue and, if so, return it to the user.  If not, wait
    // up to the user-defined timeout.  If a message becomes available in the
    // queue within the timeout period, return value = "true".  If not, return
    // value = "false".
    // ---------------------------------------------------------------------------
    //## operation timedGetMessage(unsigned char *,unsigned *,unsigned int,unsigned long) 
    virtual bool timedGetMessage(unsigned char * msg, unsigned * messageSizeInBytes, unsigned int timeoutSecs, unsigned long timeoutMicroSecs);


////    Attributes    ////
protected :
    
    char QueueName[100];		//## attribute QueueName 
    
    char ControlDataName[150];		//## attribute ControlDataName 
    
    unsigned long maxMsgSize;		//## attribute maxMsgSize 
    
    unsigned long maxMsgs;		//## attribute maxMsgs 
    
    unsigned long totalQueueSize;		//## attribute totalQueueSize 
    
    boost::interprocess::interprocess_semaphore QueueInitializationSemaphore;		//## attribute QueueInitializationSemaphore 
    
    bool exitFlag;		//## attribute exitFlag 
    
public :
    
    unsigned char * myQueue;		//## attribute myQueue 
    
    boost::interprocess::shared_memory_object * shm1;		//## attribute shm1 
    
    boost::interprocess::mapped_region * region1;		//## attribute region1 
    
    void * addr1;		//## attribute addr1 
    
    SharedMemoryQueueControlData * myControlData;		//## attribute myControlData 
    
    boost::interprocess::shared_memory_object * shm2;		//## attribute shm2 
    
    boost::interprocess::mapped_region * region2;		//## attribute region2 
    
    void * addr2;		//## attribute addr2 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\InterprocessQueue.h
*********************************************************************/

