/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: InterprocessPubSub
//!	Generated Date	: Tue, 15, Jul 2008  
	File Path	: DefaultComponent\DefaultConfig\InterprocessPubSub\InterprocessPubSub.h
*********************************************************************/


#ifndef InterprocessPubSub_InterprocessPubSub_H 

#define InterprocessPubSub_InterprocessPubSub_H 

#include "boost\interprocess\shared_memory_object.hpp"
#include "boost\interprocess\sync\interprocess_semaphore.hpp"
#include "boost\interprocess\sync\interprocess_mutex.hpp"

//----------------------------------------------------------------------------
// InterprocessPubSub\InterprocessPubSub.h                                                                  
//----------------------------------------------------------------------------

class InterprocessQueue;
class SharedMemoryQueueControlData;

//## package InterprocessPubSub 


//## type InterprocessQueueSyncMessage 
struct InterprocessQueueSyncMessage {
    unsigned int syncWord;		//## attribute syncWord 
};




#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\InterprocessPubSub\InterprocessPubSub.h
*********************************************************************/

