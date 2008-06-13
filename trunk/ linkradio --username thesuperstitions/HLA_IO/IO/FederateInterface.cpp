/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::IO::FederateInterface
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.cpp
*********************************************************************/

#include "FederateInterface.h"
// dependency Federate 
#include "Federate.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"
// dependency PostOffice 
#include "PostOffice.h"

//----------------------------------------------------------------------------
// FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::IO 

//## class FederateInterface 
//typedef struct            /* R49_NTDS_HDR_STRUCT */
//{
//       unsigned short
//            num_wrds,     /*            Number of words in message            */
//            msg_type;     /*                  Type of message                 */
//		
//}	R49_NTDS_HDR_STRUCT;
//
//struct MessageStruct
//{
//  R49_NTDS_HDR_STRUCT Hdr;
//  long          MsgNumber;
//  unsigned char MsgBody[96];
//};

namespace framework {
    namespace IO {
        
        FederateInterface::FederateInterface(int interfaceID, int unitNumber, std::string name, 
          unsigned long maxMessageSize, unsigned long maxMessages, FederateInterfaceType federateInterfaceType) : 
        itsFederateIO_Handler(NULL), exitFlag(false) ,interfaceID(interfaceID), interfaceName(name), 
          maxMessageSize(maxMessageSize), maxMessages(maxMessages) 
        {
            
            //#[ operation FederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
            
            char s[200];

            if ( (federateInterfaceType == FederateInterfaceTypePublisherSubscriber) || 
                 (federateInterfaceType == FederateInterfaceTypePublisher) )
            {
              sprintf(s, "Unit%u-%s-Publisher", unitNumber, name.c_str());
              setPublishQueue(new framework::utils::InterprocessQueue((char*)&s, maxMessageSize, maxMessages)); 
              this->start(); // Start the thread that monitors messages coming from the Publish process.
            }
              
            if ( (federateInterfaceType == FederateInterfaceTypePublisherSubscriber) || 
                 (federateInterfaceType == FederateInterfaceTypeSubscriber) )
            {
              sprintf(s, "Unit%u-%s-Subscriber", unitNumber, name.c_str());
              setSubscribeQueue(new framework::utils::InterprocessQueue((char*)&s, maxMessageSize, maxMessages)); 
            }
        }
        
        FederateInterface::~FederateInterface() {
            //#[ operation ~FederateInterface() 
                        
            exitFlag = true;
            
            this->Thread::join();
            
            Thread::stop();
            
            if (publishQueue != NULL)
            {
              delete publishQueue;  
              publishQueue = NULL;
            }
            
            if (subscribeQueue != NULL)
            {
              delete subscribeQueue;  
              subscribeQueue = NULL;
            }
            
            //#]
            cleanUpRelations();
        }
        
        bool FederateInterface::processFederateMessage(unsigned char* message, int messageSizeInBytes) {
            //#[ operation processFederateMessage(char*,int) 
              
            if (subscribeQueue->getQueueState() == framework::utils::InterprocessQueue::QueueSynchronizing)     
            {
              // Wait for process on other end of queue to be ready.
              if (subscribeQueue->SynchronizeQueueUsers() == false)   
              {  // The subscriber isn't ready to receive from the queue.
                return(false);
              }
            }  
            
            // Send the message to the subscriber.
//printf("FederateInterface::processFederateMessage - Got Msg From Fed-Msg#=%u, #Bytes=%u\n", ((MessageStruct*)(message))->MsgNumber, messageSizeInBytes);
            return (subscribeQueue->timedAddMessage(message, messageSizeInBytes, 1, 0) );
            
            //#]
        }
        
        void FederateInterface::threadOperation() {
            //#[ operation threadOperation() 
            
            // This thread handles a message from a publisher that is to be sent to subscribers.              
            unsigned char    message[INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES];    
            unsigned int     messageSizeInBytes;
              
            while (exitFlag != true)
            {  
              if (publishQueue->getQueueState() == framework::utils::InterprocessQueue::QueueSynchronizing)     
              {
                // Wait for process on other end of queue to be ready.
                while (publishQueue->SynchronizeQueueUsers() == false);
              }  
              else
              {
                if (publishQueue->timedGetMessage((unsigned char*)&message, &messageSizeInBytes, 1, 0) == true )
                {    
//printf("\nFedIntfc::ThreadOps  - Got Msg From Pub-Msg#=%u, num_wds=%u, MT=%u\n", 
//((MessageStruct*)(&message))->MsgNumber, ((MessageStruct*)(&message))->Hdr.num_wrds,((MessageStruct*)(&message))->Hdr.msg_type);
                  // Send the message to the Post Office for delivery.
                  framework::Control::getFederate()->getThePostOffice()->sendMessage( (char*)&message, messageSizeInBytes, this);
                }   
              }
            };
                     
            //#]
        }
        
        bool FederateInterface::getExitFlag() const {
            return exitFlag;
        }
        
        void FederateInterface::setExitFlag(bool p_exitFlag) {
            exitFlag = p_exitFlag;
        }
        
        int FederateInterface::getInterfaceID() const {
            return interfaceID;
        }
        
        void FederateInterface::setInterfaceID(int p_interfaceID) {
            interfaceID = p_interfaceID;
        }
        
        std::string FederateInterface::getInterfaceName() const {
            return interfaceName;
        }
        
        void FederateInterface::setInterfaceName(std::string p_interfaceName) {
            interfaceName = p_interfaceName;
        }
        
        unsigned long FederateInterface::getMaxMessageSize() const {
            return maxMessageSize;
        }
        
        void FederateInterface::setMaxMessageSize(unsigned long p_maxMessageSize) {
            maxMessageSize = p_maxMessageSize;
        }
        
        unsigned long FederateInterface::getMaxMessages() const {
            return maxMessages;
        }
        
        void FederateInterface::setMaxMessages(unsigned long p_maxMessages) {
            maxMessages = p_maxMessages;
        }
        
        framework::utils::InterprocessQueue* FederateInterface::getPublishQueue() const {
            return publishQueue;
        }
        
        void FederateInterface::setPublishQueue(framework::utils::InterprocessQueue* p_publishQueue) {
            publishQueue = p_publishQueue;
        }
        
        framework::utils::InterprocessQueue* FederateInterface::getSubscribeQueue() {
            return subscribeQueue;
        }
        
        void FederateInterface::setSubscribeQueue(framework::utils::InterprocessQueue* p_subscribeQueue) {
            subscribeQueue = p_subscribeQueue;
        }
        
        framework::IO::FederateIO_Handler* FederateInterface::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void FederateInterface::__setItsFederateIO_Handler(framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void FederateInterface::_setItsFederateIO_Handler(framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler->_removeItsFederateInterface(this);
                }
            __setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateInterface::setItsFederateIO_Handler(framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(p_FederateIO_Handler != NULL)
                {
                    p_FederateIO_Handler->_addItsFederateInterface(getInterfaceID(), this);
                }
            _setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateInterface::_clearItsFederateIO_Handler() {
            itsFederateIO_Handler = NULL;
        }
        
        void FederateInterface::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    framework::IO::FederateIO_Handler* current = itsFederateIO_Handler;
                    if(current != NULL)
                        {
                            current->_removeItsFederateInterface(interfaceID);
                        }
                    itsFederateIO_Handler = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.cpp
*********************************************************************/

