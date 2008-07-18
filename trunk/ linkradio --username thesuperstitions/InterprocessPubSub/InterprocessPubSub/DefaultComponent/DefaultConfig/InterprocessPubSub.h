/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: InterprocessPubSub
//!	Generated Date	: Tue, 15, Jul 2008  
	File Path	: DefaultComponent\DefaultConfig\InterprocessPubSub.h
*********************************************************************/


#ifndef InterprocessPubSub_H 

#define InterprocessPubSub_H 

#include "boost\interprocess\shared_memory_object.hpp"
#include "boost\interprocess\sync\interprocess_semaphore.hpp"
#include "boost\interprocess\sync\interprocess_mutex.hpp"

//----------------------------------------------------------------------------
// InterprocessPubSub.h                                                                  
//----------------------------------------------------------------------------

class InterprocessQueue;
class SharedMemoryQueueControlData;

//## package InterprocessPubSub 


//## type InterprocessQueueSyncMessage 
struct InterprocessQueueSyncMessage {
    unsigned int syncWord;		//## attribute syncWord 
};


//## attribute INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE 
#define INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE 1000

//## attribute INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES 
#define INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES 4096



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\InterprocessPubSub.h
*********************************************************************/

