/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ReverseEngineering
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\ReverseEngineering.h
*********************************************************************/


#ifndef ReverseEngineering_H 

#define ReverseEngineering_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"

//----------------------------------------------------------------------------
// ReverseEngineering.h                                                                  
//----------------------------------------------------------------------------

//## package ReverseEngineering 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

//## type SharedMemoryQueueControlData 
struct SharedMemoryQueueControlData {
    unsigned int CurrentReadSlot;		//## attribute CurrentReadSlot 
    unsigned int CurrentWriteSlot;		//## attribute CurrentWriteSlot 
    bool InterfaceStatus;		//## attribute InterfaceStatus 
    unsigned int NumberMessagesInQueue;		//## attribute NumberMessagesInQueue 
    unsigned long UniqueValue;		//## attribute UniqueValue 
    boost::interprocess::interprocess_semaphore addMessageSemaphore;		//## attribute addMessageSemaphore 
    boost::interprocess::interprocess_semaphore getMsgSemaphore;		//## attribute getMsgSemaphore 
    boost::interprocess::interprocess_mutex myDataAccessMutex;		//## attribute myDataAccessMutex 
};


//## attribute INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE 
#define INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE 20

//## attribute INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES 
#define INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES 100

//## attribute __framework_utils__Thread__H 
#define __framework_utils__Thread__H 



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ReverseEngineering.h
*********************************************************************/

