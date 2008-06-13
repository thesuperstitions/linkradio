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

namespace framework {
    namespace IO {
        
        // Static class member attribute
        framework::utils::InterprocessQueue* FederateInterface::subscribeQueue;
        
        FederateInterface::FederateInterface(int interfaceID, std::string name, unsigned long maxMessageSize, unsigned long maxMessages, FederateInterfaceType federateInterfaceType) : exitFlag(false) ,interfaceID(interfaceID), interfaceName(name), maxMessageSize(maxMessageSize), maxMessages(maxMessages) {
            itsFederateIO_Handler = NULL;
            //#[ operation FederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
            
            switch (federateInterfaceType)
            {
              case FederateInterfaceTypePublisher: 
                setPublishQueue(new framework::utils::InterprocessQueue((char*)name.c_str(), maxMessageSize, maxMessages)); 
              break;
              
              case FederateInterfaceTypeSubscriber:
                setSubscribeQueue(new framework::utils::InterprocessQueue((char*)name.c_str(), maxMessageSize, maxMessages)); 
                framework::utils::Thread::start();
              break;
              
              default:
              break;
            };
                    
            //#]
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
        
        bool FederateInterface::processFederateMessage(char* message, int messageSizeInBytes) {
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
            return (subscribeQueue->timedAddMessage(((unsigned char*)message), messageSizeInBytes, 1, 0) );
            
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
                  // Create a FederateMessage instance and populate it.
            //                  FederateMessage* fm_Ptr = new FederateMessage( this, &message, messageSizeInBytes );    
                
                  // Send the message to the Post Office for delivery.
            //                  Framework::Control::getFederate()->getThePostOffice()->sendMessage( fm_Ptr);
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

