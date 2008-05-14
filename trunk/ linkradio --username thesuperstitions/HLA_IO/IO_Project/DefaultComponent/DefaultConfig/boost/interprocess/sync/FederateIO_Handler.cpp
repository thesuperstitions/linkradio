/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_Handler
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FederateIO_Handler.cpp
*********************************************************************/

#include "boost\interprocess\sync\FederateIO_Handler.h"
// link itsFederate 
#include "boost\interprocess\sync\Federate.h"
// link itsFederateInterfaceFactory 
#include "boost\interprocess\sync\FederateInterfaceFactory.h"
#include "boost\interprocess\sync\Serializer.h"
// dependency Buffer 
#include "boost\interprocess\sync\Buffer.h"
// dependency C_IO_Functions 
#include "boost\interprocess\sync\C_IO_Functions.h"
// operation passMessageToApplication(FederateMessage*) 
#include "boost\interprocess\sync\FederateMessage.h"
// dependency PostOffice 
#include "boost\interprocess\sync\PostOffice.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\FederateIO_Handler.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateIO_Handler 

namespace Framework {
    namespace IO {
        
        
        FederateIO_Handler::FederateIO_Handler(FederateFrameworkType frameworkType) : recvMessageActive(false) ,timerExpired(false) ,frameworkType(frameworkType) ,itsFederateInterface() {
            itsFederateMessage = NULL;
            itsFederateInterfaceFactory = NULL;
            itsFederate = NULL;
            //#[ operation FederateIO_Handler(FederateFrameworkType) 
            
            setItsFederateInterfaceFactory( new Framework::Control::FederateInterfaceFactory(frameworkType) ); 
            
            // Spin off a thread to handle output of Federate Messages.
            //todo            setItsFederateIO_OutputThread( new  FederateIO_OutputThread() );
            //todo            getItsFederateIO_OutputThread()->start();
            
            // Spin off a thread to handle input of Federate Messages.
            //todo            setItsFederateIO_InputThread( new  FederateIO_InputThread() );
            //todo            getItsFederateIO_InputThread()->start();
            
            
            //#]
        }
        
        FederateIO_Handler::FederateIO_Handler() : recvMessageActive(false) ,timerExpired(false) ,itsFederateInterface() {
            itsFederate = NULL;
            itsFederateInterfaceFactory = NULL;
            itsFederateMessage = NULL;
        }
        
        FederateIO_Handler::~FederateIO_Handler() {
            cleanUpRelations();
        }
        
        void FederateIO_Handler::createFederateInterface(std::string interfaceName) {
            //#[ operation createFederateInterface(std::string) 
              
            // Create a FederateInterface by calling the factory.
            Framework::IO::FederateInterface* FI_Ptr = getItsFederateInterfaceFactory()->createFederateInterface(interfaceName, interfaceType);
                        
            // Map the Federate interface to its name.
            addItsFederateInterface(interfaceName, FI_Ptr);   
            
            // Set the Federate Interface' link to the this FederateIO_Handler.
            //            FI_Ptr->setItsFederateIO_Handler(this);
            
            getItsFederate()->getThePostOffice()->announcePublication( getItsFederateInterface(interfaceName));   
             
            getItsFederate()->getThePostOffice()->announceSubscription( getItsFederateInterface(interfaceName) );   
            
            //#]
        }
        
        void FederateIO_Handler::onTimerExpired() {
            //#[ operation onTimerExpired() 
            
            timerExpired = true;
            
            //#]
        }
        
        bool FederateIO_Handler::passMessageToApplication(FederateMessage* federateMessage) {
            //#[ operation passMessageToApplication(FederateMessage*) 
            
            // Give the message to the application for processing. 
            if (getRecvMessageActive() == true)
            {
              if (getItsFederateMessage() == NULL)
              {  
                setItsFederateMessage(federateMessage);
                setRecvMessageActive(false);  
                return(true);
              } 
            }
            
            return(false);
            
            //#]
        }
        
        FederateMessage* FederateIO_Handler::recvMessage(int timeoutSeconds, unsigned long timeoutNanoseconds) {
            //#[ operation recvMessage(int,unsigned long) 
              
            //setRecvMessageActive(true);
            //setTimerExpired(false);
                           
            // Only start the timer if at least one of the input values is non-zero.
            //if ( (timeoutSeconds != 0) ||  (timeoutNanoseconds != 0) )
            //{
            //              startOneShotTimer(timeoutSeconds, timeoutNanoseconds);
            
            //              while (getRecvMessageActive() == true)
              //{
            //                if (getTimerExpired() == true)
                //{    
                  // The Recieve Timer has timed out.  Return NULL to indicate that no message is available.
                  //setRecvMessageActive(false);
                  //return(NULL);  
                //}  // if (getTimerExpired() == true)
              
                // Give up the processor for a while.
                //yield(); 
                
            //              }; // while (getRecvMessageActive() == true)
            //}; // if ( (timeoutSeconds != 0) ||  (timeoutNanoseconds != 0) )
            
            // Reset the flag that indicates that a message recieve is in progress.    
            //setRecvMessageActive(false);
                                                
            // Send the message back to the caller.                                    
            //return( getItsFederateMessage() );
            return(NULL);            
            //#]
        }
        
        void FederateIO_Handler::sendMessage(std::string interfaceName, char* message, int messageSizeInBytes) {
            //#[ operation sendMessage(std::string,char*,int) 
            
            Framework::IO::FederateInterface* fi_Ptr = getItsFederateInterface(interfaceName);
            
            // Serialize the message data.  
            //            message = Framework::IO::serializer( getMessageType( message, fi_Ptr->getInterfaceType() ), message);
            
            // Create a FederateMessage instance and populate it.
            FederateMessage* fm_Ptr = new FederateMessage( fi_Ptr, message, messageSizeInBytes );
            
            // Add this FederateMessage to the outgoing list of messages
            //todo            getItsFederateIO_OutputThread()->addItsFederateMessage(fm_Ptr);
            
            //#]
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
        
        bool FederateIO_Handler::getRecvMessageActive() const {
            return recvMessageActive;
        }
        
        void FederateIO_Handler::setRecvMessageActive(bool p_recvMessageActive) {
            recvMessageActive = p_recvMessageActive;
        }
        
        bool FederateIO_Handler::getTimerExpired() const {
            return timerExpired;
        }
        
        void FederateIO_Handler::setTimerExpired(bool p_timerExpired) {
            timerExpired = p_timerExpired;
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
        
        Framework::IO::FederateMessage* FederateIO_Handler::getItsFederateMessage() const {
            return itsFederateMessage;
        }
        
        void FederateIO_Handler::setItsFederateMessage(Framework::IO::FederateMessage* p_FederateMessage) {
            itsFederateMessage = p_FederateMessage;
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
            if(itsFederateMessage != NULL)
                {
                    itsFederateMessage = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FederateIO_Handler.cpp
*********************************************************************/

