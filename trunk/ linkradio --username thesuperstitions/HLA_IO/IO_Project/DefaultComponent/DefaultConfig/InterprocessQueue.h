/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::InterprocessQueue
//!	Generated Date	: Tue, 13, May 2008  
	File Path	: DefaultComponent\DefaultConfig\InterprocessQueue.h
*********************************************************************/


#ifndef InterprocessQueue_H 

#define InterprocessQueue_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "utils.h"
// attribute myControlData 
#include "Framework.h"

//----------------------------------------------------------------------------
// InterprocessQueue.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateIO_Handler;
    }
    
}


//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace utils {
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
            //## operation InterprocessQueue(std::string,unsigned int,unsigned long) 
            InterprocessQueue(std::string queueName, unsigned int maxMessageSizeInBytes, unsigned long maxNumberOfMessages);
            
            // ## operation Queue()
            //## operation ~InterprocessQueue() 
            virtual ~InterprocessQueue();
        
        
        ////    Operations    ////
        public :
            
            //## operation LogMessage(char*,double) 
            void LogMessage(char* Msg, double count);
            
            // **********************************************************************************************************************
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
            // **********************************************************************************************************************
            //## operation SynchronizeQueueUsers() 
            virtual bool SynchronizeQueueUsers();
            
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
            inline QueueState* getQueueState() {
                //#[ operation getQueueState() 
                //        QueueState qs;
                bool       sharedMemoryQueueState;
                
                { // Start of scope.
                  scoped_lock<interprocess_mutex> lock(myControlData->myDataAccessMutex); //This lock protects the queue itself.
                	sharedMemoryQueueState = myControlData->InterfaceStatus;
                } // End of scope.
                
                if ((sharedMemoryQueueState == false) || (queueState == QueueSynchronizing) )
                	return(QueueSynchronizing);
                else
                	return(QueueSynchronized);
                //#]
            }
            
            
            // ## operation addMessage(FederateMessage*)
            //## operation timedAddMessage(unsigned char *,unsigned int,unsigned int,unsigned long) 
            virtual bool timedAddMessage(unsigned char * message, unsigned int messageSizeInBytes, unsigned int timeoutSecs, unsigned long timeoutMicroSecs);
            
            // Immediately check to see if the thread should exit.  Check to see if there
            // is a message in the queue and, if so, return it to the user.  If not, wait
            // up to the user-defined timeout.  If a message becomes available in the
            // queue within the timeout period, return value = "true".  If not, return
            // value = "false".
            // ---------------------------------------------------------------------------
            //## operation timedGetMessage(unsigned char *,unsigned int,unsigned long) 
            virtual bool timedGetMessage(unsigned char * msg, unsigned int timeoutSecs, unsigned long timeoutMicroSecs);
        
        
        ////    Attributes    ////
        protected :
            
            // unsigned long CurrentMessageSlot;
            char QueueName[100];		//## attribute QueueName 
            
            char ControlDataName[150];		//## attribute ControlDataName 
            
            unsigned long maxMsgSize;		//## attribute maxMsgSize 
            
            unsigned long maxMsgs;		//## attribute maxMsgs 
            
            unsigned long totalQueueSize;		//## attribute totalQueueSize 
            
            boost::interprocess::interprocess_semaphore QueueInitializationSemaphore;		//## attribute QueueInitializationSemaphore 
            
            QueueState queueState;		//## attribute queueState 
            
            bool exitFlag;		//## attribute exitFlag 
            
        public :
            
            unsigned char * myQueue;		//## attribute myQueue 
            
            shared_memory_object * shm1;		//## attribute shm1 
            
            mapped_region * region1;		//## attribute region1 
            
            void * addr1;		//## attribute addr1 
            
            SharedMemoryQueueControlData * myControlData;		//## attribute myControlData 
            
            shared_memory_object * shm2;		//## attribute shm2 
            
            mapped_region * region2;		//## attribute region2 
            
            void * addr2;		//## attribute addr2 
            
        
        ////    Relations and components    ////
        protected :
            
            IO::FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\InterprocessQueue.h
*********************************************************************/

