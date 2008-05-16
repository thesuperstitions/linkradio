/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterface
//!	Generated Date	: Thu, 15, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.cpp
*********************************************************************/

#include "FederateInterface.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"
// operation processFederateMessage(FederateMessage*) 
#include "FederateMessage.h"
// link publisherQueue 
#include "InterprocessQueue.h"

//----------------------------------------------------------------------------
// FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateInterface 

namespace Framework {
    namespace IO {
        
        // Static class member attribute
        Framework::utils::InterprocessQueue* FederateInterface::subscribeQueue;
        
        FederateInterface::FederateInterface(int interfaceID, std::string name, unsigned long maxMessageSize, unsigned long maxMessages, FederateInterfaceType federateInterfaceType) : exitFlag(false) ,interfaceID(interfaceID), interfaceName(name), maxMessageSize(maxMessageSize), maxMessages(maxMessages) {
            subscriberQueue = NULL;
            publisherQueue = NULL;
            itsFederateIO_Handler = NULL;
            //#[ operation FederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
            
            switch (federateInterfaceType)
            {
              case FederateInterfaceTypePublisher: 
                setPublisherQueue(new InterprocessQueue(name, maxMessageSize, maxMessages)); 
              break;
              
              case FederateInterfaceTypeSubscriber:
                setSubscriberQueue(new InterprocessQueue(name, maxMessageSize, maxMessages)); 
                Thread::start();
              break;
              
              default:
            };
                    
            //#]
        }
        
        FederateInterface::~FederateInterface() {
            //#[ operation ~FederateInterface() 
                        
            exitFlag = true;
            
            this->Thread::join();
            
            Thread::stop();
            
            if (publisherQueue != NULL)
            {
              delete publisherQueue;  
              publisherQueue(NULL);
            }
            
            if (subscriberQueue != NULL)
            {
              delete subscriberQueue;  
              subscriberQueue(NULL);
            }
            
            //#]
            cleanUpRelations();
        }
        
        bool FederateInterface::processFederateMessage(FederateMessage* message) {
            //#[ operation processFederateMessage(FederateMessage*) 
            
            // This thread handles a message from a publisher that is to be sent to subscribers.              
            Buffer* bPtr;
            
              
            if (subscriberQueue->getQueueState() == InterprocessQueue::QueueSynchronizing)     
            {
              // Wait for process on other end of queue to be ready.
              if (subscriberQueue->SynchronizeQueueUsers() == false)   
              {  // The subscriber isn't ready to receive from the queue.
                return(false);
              }
            }  
            
            // Send the message to the subscriber.
            bPtr = message->getMessage()->getBuffer();
            inputQueue()->timedAddMessage(bPtr->byteArray, bPtr->sizeOfByteArray, 1, 0);
            return (inputQueue->timedAddMessage(((unsigned char*)bPtr->byteArray), bPtr->sizeOfByteArray, 1, 0) );
            
            //#]
        }
        
        void FederateInterface::threadOperation() {
            //#[ operation threadOperation() 
            
            // This thread handles a message from a publisher that is to be sent to subscribers.              
            unsigned char    message[INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES];    
            unsigned long    messageSizeInBytes;
            FederateMessage* fmPtr = (FederateMessage*)&message;  
            Buffer*          bPtr;
              
            while (exitFlag != true)
            {  
              if (outputQueue->getQueueState() == InterprocessQueue::QueueSynchronizing)     
              {
                // Wait for process on other end of queue to be ready.
                while (outputQueue->SynchronizeQueueUsers() == false);
              }  
              else
              {
                if (inputQueue->timedGetMessage((unsigned char*)&message, &messageSizeInBytes, 1, 0) == true )
                {    
                  // Create a FederateMessage instance and populate it.
            //                  FederateMessage* fm_Ptr = new FederateMessage( this, &message, messageSizeInBytes );    
                
                  // Send the message to the Post Office for delivery.
            //                  Framework::Control::getFederate()->getThePostOffice()->sendMessage( fm_Ptr);
                  Framework::Control::getFederate()->getThePostOffice()->sendMessage( &message, messageSizeInBytes);
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
        
        Framework::utils::InterprocessQueue* FederateInterface::getSubscribeQueue() {
            return subscribeQueue;
        }
        
        void FederateInterface::setSubscribeQueue(Framework::utils::InterprocessQueue* p_subscribeQueue) {
            subscribeQueue = p_subscribeQueue;
        }
        
        Framework::IO::FederateIO_Handler* FederateInterface::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void FederateInterface::__setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void FederateInterface::_setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler->_removeItsFederateInterface(this);
                }
            __setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateInterface::setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(p_FederateIO_Handler != NULL)
                {
                    p_FederateIO_Handler->_addItsFederateInterface(getInterfaceID(), this);
                }
            _setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateInterface::_clearItsFederateIO_Handler() {
            itsFederateIO_Handler = NULL;
        }
        
        Framework::utils::InterprocessQueue* FederateInterface::getPublisherQueue() const {
            return publisherQueue;
        }
        
        void FederateInterface::setPublisherQueue(Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            publisherQueue = p_InterprocessQueue;
        }
        
        Framework::utils::InterprocessQueue* FederateInterface::getSubscriberQueue() const {
            return subscriberQueue;
        }
        
        void FederateInterface::setSubscriberQueue(Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            subscriberQueue = p_InterprocessQueue;
        }
        
        void FederateInterface::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    Framework::IO::FederateIO_Handler* current = itsFederateIO_Handler;
                    if(current != NULL)
                        {
                            current->_removeItsFederateInterface(interfaceID);
                        }
                    itsFederateIO_Handler = NULL;
                }
            if(publisherQueue != NULL)
                {
                    publisherQueue = NULL;
                }
            if(subscriberQueue != NULL)
                {
                    subscriberQueue = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.cpp
*********************************************************************/

