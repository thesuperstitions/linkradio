/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_Handler
//!	Generated Date	: Wed, 14, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/

#include "FederateIO_Handler.h"
// link itsFederate 
#include "Federate.h"
// link itsFederateInterfaceFactory 
#include "FederateInterfaceFactory.h"
#include "Serializer.h"
// dependency Buffer 
#include "Buffer.h"
// dependency C_IO_Functions 
#include "C_IO_Functions.h"
// dependency PostOffice 
#include "PostOffice.h"
// link itsInterprocessQueue 
#include "InterprocessQueue.h"

//----------------------------------------------------------------------------
// FederateIO_Handler.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateIO_Handler 

namespace Framework {
    namespace IO {
        
        
        FederateIO_Handler::FederateIO_Handler(FederateFrameworkType frameworkType) : exitFlag(false) ,frameworkType(frameworkType) ,itsFederateInterface() {
            itsInterprocessQueue = NULL;
            itsFederateInterfaceFactory = NULL;
            itsFederate = NULL;
            //#[ operation FederateIO_Handler(FederateFrameworkType) 
            
            setItsFederateInterfaceFactory( new Framework::Control::FederateInterfaceFactory(frameworkType) );  
            
            setItsInterprocessQueue(new Framework::utils::InterprocessQueue("FederatIO_Handler-Control");
            
            Thread::start();
            
            //#]
        }
        
        FederateIO_Handler::FederateIO_Handler() : exitFlag(false) ,itsFederateInterface() {
            itsFederate = NULL;
            itsFederateInterfaceFactory = NULL;
            itsInterprocessQueue = NULL;
        }
        
        FederateIO_Handler::~FederateIO_Handler() {
            //#[ operation ~FederateIO_Handler() 
            
            exitFlag = true;
            
            this->Thread::join();
            
            Thread::stop();   
            
            delete getItsFederateInterfaceFactory();  
            setItsFederateInterfaceFactory(NULL);
            
            delete getItsInterprocessQueue();
            setItsInterprocessQueue(NULL);
            
            //#]
            cleanUpRelations();
        }
        
        FederateInterface* FederateIO_Handler::createFederateInterface(std::string interfaceName, unsigned long maxMessageSize, unsigned long maxMessages) {
            //#[ operation createFederateInterface(std::string,unsigned long,unsigned long) 
              
            // Create a FederateInterface by calling the factory.
            Framework::IO::FederateInterface* FI_Ptr = getItsFederateInterfaceFactory()->createFederateInterface(interfaceName, maxMessageSize, maxMessages);
                        
            // Map the Federate interface to its name.
            addItsFederateInterface(interfaceName, FI_Ptr);   
            
            // Set the Federate Interface' link to the this FederateIO_Handler.
            //            FI_Ptr->setItsFederateIO_Handler(this);
            
            getItsFederate()->getThePostOffice()->announcePublication( FI_Ptr );   
             
            getItsFederate()->getThePostOffice()->announceSubscription( FI_Ptr ); 
            
            return(FI_Ptr); 
            
            //#]
        }
        
        void FederateIO_Handler::threadOperation() {
            //#[ operation threadOperation() 
              
            IO_InterfaceInformationType  info;  
            unsigned char                message[INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES];
            
              
            while (exitFlag != true)
            {  
              if (controlQueue->getQueueState() == InterprocessQueue::QueueSynchronizing)     
              {
                // Wait for process on other end of queue to be ready.
                while(myQueue->SynchronizeQueueUsers() == false);
              }  
              else
              {
                if (controlQueue->timedGetMessage((unsigned char*)&info, 1, 0) == true )
                { 
                  info.federateInterface = createFederateInterface(info.interfaceName, info.maxMessageSize, info.maxMessages);  
                                                                                                        
                  // Send a response with the pointer to the new Federate Interface in it.                 
                  controlQueue->timedAddMessage((unsigned char*)&info, sizeof(IO_InterfaceInformationType), 1, 0)                                                                                                   
                }   
              }
            };
                     
            //#]
        }
        
        bool FederateIO_Handler::getExitFlag() const {
            return exitFlag;
        }
        
        void FederateIO_Handler::setExitFlag(bool p_exitFlag) {
            exitFlag = p_exitFlag;
        }
        
        FederateFrameworkType FederateIO_Handler::getFrameworkType() const {
            return frameworkType;
        }
        
        void FederateIO_Handler::setFrameworkType(FederateFrameworkType p_frameworkType) {
            frameworkType = p_frameworkType;
        }
        
        Framework::InterfaceType FederateIO_Handler::getInterfaceType() const {
            return interfaceType;
        }
        
        void FederateIO_Handler::setInterfaceType(Framework::InterfaceType p_interfaceType) {
            interfaceType = p_interfaceType;
        }
        
        Framework::Control::Federate* FederateIO_Handler::getItsFederate() const {
            return itsFederate;
        }
        
        void FederateIO_Handler::__setItsFederate(Framework::Control::Federate* p_Federate) {
            itsFederate = p_Federate;
        }
        
        void FederateIO_Handler::_setItsFederate(Framework::Control::Federate* p_Federate) {
            if(itsFederate != NULL)
                {
                    itsFederate->__setItsFederateIO_Handler(NULL);
                }
            __setItsFederate(p_Federate);
        }
        
        void FederateIO_Handler::setItsFederate(Framework::Control::Federate* p_Federate) {
            if(p_Federate != NULL)
                {
                    p_Federate->_setItsFederateIO_Handler(this);
                }
            _setItsFederate(p_Federate);
        }
        
        void FederateIO_Handler::_clearItsFederate() {
            itsFederate = NULL;
        }
        
        std::map<std::string, Framework::IO::FederateInterface*>::const_iterator FederateIO_Handler::getItsFederateInterface() const {
            std::map<std::string, Framework::IO::FederateInterface*>::const_iterator iter;
            iter = itsFederateInterface.begin();
            return iter;
        }
        
        std::map<std::string, Framework::IO::FederateInterface*>::const_iterator FederateIO_Handler::getItsFederateInterfaceEnd() const {
            return itsFederateInterface.end();
        }
        
        void FederateIO_Handler::_clearItsFederateInterface() {
            itsFederateInterface.clear();
        }
        
        void FederateIO_Handler::clearItsFederateInterface() {
            std::map<std::string, Framework::IO::FederateInterface*>::const_iterator iter;
            iter = itsFederateInterface.begin();
            while (iter != itsFederateInterface.end()){
                ((*iter).second)->_clearItsFederateIO_Handler();
                iter++;
            }
            _clearItsFederateInterface();
        }
        
        void FederateIO_Handler::_removeItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            std::map<std::string, Framework::IO::FederateInterface*>::iterator pos = std::find_if(itsFederateInterface.begin(), itsFederateInterface.end(),OMValueCompare<const std::string,Framework::IO::FederateInterface*>(p_FederateInterface));
            if (pos != itsFederateInterface.end()) {
            	itsFederateInterface.erase(pos);
            }
        }
        
        void FederateIO_Handler::removeItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            if(p_FederateInterface != NULL)
                {
                    p_FederateInterface->__setItsFederateIO_Handler(NULL);
                }
            _removeItsFederateInterface(p_FederateInterface);
        }
        
        Framework::IO::FederateInterface* FederateIO_Handler::getItsFederateInterface(std::string key) const {
            return (itsFederateInterface.find(key) != itsFederateInterface.end() ? (*itsFederateInterface.find(key)).second : NULL);
        }
        
        void FederateIO_Handler::_addItsFederateInterface(std::string key, Framework::IO::FederateInterface* p_FederateInterface) {
            itsFederateInterface.insert(std::map<std::string, Framework::IO::FederateInterface*>::value_type(key, p_FederateInterface));
        }
        
        void FederateIO_Handler::addItsFederateInterface(std::string key, Framework::IO::FederateInterface* p_FederateInterface) {
            if(p_FederateInterface != NULL)
                {
                    p_FederateInterface->_setItsFederateIO_Handler(this);
                }
            _addItsFederateInterface(key, p_FederateInterface);
        }
        
        void FederateIO_Handler::_removeItsFederateInterface(std::string key) {
            itsFederateInterface.erase(key);
        }
        
        void FederateIO_Handler::removeItsFederateInterface(std::string key) {
            Framework::IO::FederateInterface* p_FederateInterface = getItsFederateInterface(key);
            if(p_FederateInterface != NULL)
                {
                    p_FederateInterface->_setItsFederateIO_Handler(NULL);
                }
            _removeItsFederateInterface(key);
        }
        
        Framework::Control::FederateInterfaceFactory* FederateIO_Handler::getItsFederateInterfaceFactory() const {
            return itsFederateInterfaceFactory;
        }
        
        void FederateIO_Handler::setItsFederateInterfaceFactory(Framework::Control::FederateInterfaceFactory* p_FederateInterfaceFactory) {
            itsFederateInterfaceFactory = p_FederateInterfaceFactory;
        }
        
        Framework::utils::InterprocessQueue* FederateIO_Handler::getItsInterprocessQueue() const {
            return itsInterprocessQueue;
        }
        
        void FederateIO_Handler::__setItsInterprocessQueue(Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            itsInterprocessQueue = p_InterprocessQueue;
        }
        
        void FederateIO_Handler::_setItsInterprocessQueue(Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            if(itsInterprocessQueue != NULL)
                {
                    itsInterprocessQueue->__setItsFederateIO_Handler(NULL);
                }
            __setItsInterprocessQueue(p_InterprocessQueue);
        }
        
        void FederateIO_Handler::setItsInterprocessQueue(Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            if(p_InterprocessQueue != NULL)
                {
                    p_InterprocessQueue->_setItsFederateIO_Handler(this);
                }
            _setItsInterprocessQueue(p_InterprocessQueue);
        }
        
        void FederateIO_Handler::_clearItsInterprocessQueue() {
            itsInterprocessQueue = NULL;
        }
        
        void FederateIO_Handler::cleanUpRelations() {
            if(itsFederate != NULL)
                {
                    Framework::IO::FederateIO_Handler* p_FederateIO_Handler = itsFederate->getItsFederateIO_Handler();
                    if(p_FederateIO_Handler != NULL)
                        {
                            itsFederate->__setItsFederateIO_Handler(NULL);
                        }
                    itsFederate = NULL;
                }
            {
                std::map<std::string, Framework::IO::FederateInterface*>::const_iterator iter;
                iter = itsFederateInterface.begin();
                while (iter != itsFederateInterface.end()){
                    Framework::IO::FederateIO_Handler* p_FederateIO_Handler = ((*iter).second)->getItsFederateIO_Handler();
                    if(p_FederateIO_Handler != NULL)
                        {
                            ((*iter).second)->__setItsFederateIO_Handler(NULL);
                        }
                    iter++;
                }
                itsFederateInterface.clear();
            }
            if(itsFederateInterfaceFactory != NULL)
                {
                    itsFederateInterfaceFactory = NULL;
                }
            if(itsInterprocessQueue != NULL)
                {
                    Framework::IO::FederateIO_Handler* p_FederateIO_Handler = itsInterprocessQueue->getItsFederateIO_Handler();
                    if(p_FederateIO_Handler != NULL)
                        {
                            itsInterprocessQueue->__setItsFederateIO_Handler(NULL);
                        }
                    itsInterprocessQueue = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/

