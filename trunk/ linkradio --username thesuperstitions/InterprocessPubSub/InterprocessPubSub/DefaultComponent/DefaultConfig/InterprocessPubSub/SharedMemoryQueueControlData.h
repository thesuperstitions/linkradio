/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SharedMemoryQueueControlData
//!	Generated Date	: Tue, 15, Jul 2008  
	File Path	: DefaultComponent\DefaultConfig\InterprocessPubSub\SharedMemoryQueueControlData.h
*********************************************************************/


#ifndef InterprocessPubSub_SharedMemoryQueueControlData_H 

#define InterprocessPubSub_SharedMemoryQueueControlData_H 

#include "InterprocessPubSub\InterprocessPubSub.h"

//----------------------------------------------------------------------------
// InterprocessPubSub\SharedMemoryQueueControlData.h                                                                  
//----------------------------------------------------------------------------

//## package InterprocessPubSub 


//## class SharedMemoryQueueControlData 
class SharedMemoryQueueControlData  {


////    Constructors and destructors    ////
public :
    
    //## operation SharedMemoryQueueControlData(unsigned int) 
    SharedMemoryQueueControlData(unsigned int numMsgs);


////    Attributes    ////
public :
    
    unsigned int CurrentReadSlot;		//## attribute CurrentReadSlot 
    
    unsigned int CurrentWriteSlot;		//## attribute CurrentWriteSlot 
    
    bool InterfaceStatus;		//## attribute InterfaceStatus 
    
    unsigned int NumberMessagesInQueue;		//## attribute NumberMessagesInQueue 
    
    // ## Controls access to "Add" a message.
    boost::interprocess::interprocess_semaphore addMessageSemaphore;		//## attribute addMessageSemaphore 
    
    // ## Controls access to "Get" a message.
    boost::interprocess::interprocess_semaphore getMsgSemaphore;		//## attribute getMsgSemaphore 
    
    // ## Controls access to the Control Data.
    boost::interprocess::interprocess_mutex myDataAccessMutex;		//## attribute myDataAccessMutex 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\InterprocessPubSub\SharedMemoryQueueControlData.h
*********************************************************************/

