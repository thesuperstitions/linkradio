/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::FederateIO_Handler
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/

#include "FederateIO_Handler.h"
// link itsFederate 
#include "Federate.h"
// link itsFederateInterfaceFactory 
#include "FederateInterfaceFactory.h"
// dependency C_IO_Functions 
#include "C_IO_Functions.h"
// dependency PostOffice 
#include "PostOffice.h"

#include "ValueCompare.h"

//----------------------------------------------------------------------------
// FederateIO_Handler.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::io 

//## class FederateIO_Handler 

namespace framework {
    namespace io {
        
        
        FederateIO_Handler::FederateIO_Handler(FederateFrameworkType frameworkType) : frameworkType(frameworkType) ,itsFederateInterface() {
            itsFederateInterfaceFactory = NULL;
            itsFederate = NULL;
            //#[ operation FederateIO_Handler(FederateFrameworkType) 
            
            setItsFederateInterfaceFactory( new framework::Control::FederateInterfaceFactory(frameworkType) );  
            
            //#]
        }
        
        FederateIO_Handler::FederateIO_Handler() : itsFederateInterface() {
            itsFederate = NULL;
            itsFederateInterfaceFactory = NULL;
        }
        
        FederateIO_Handler::~FederateIO_Handler() {
            //#[ operation ~FederateIO_Handler() 
            
            //#]
            cleanUpRelations();
        }
        
        FederateInterface* FederateIO_Handler::createFederateInterface(int interfaceID, int unitNumber, std::string interfaceName, unsigned long maxMessageSize, unsigned long maxMessages, FederateInterfaceType federateInterfaceType) {
            //#[ operation createFederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
              
            // Create a FederateInterface by calling the factory.
            framework::io::FederateInterface* FI_Ptr = getItsFederateInterfaceFactory()->createFederateInterface(
              interfaceID, unitNumber, interfaceName, maxMessageSize, maxMessages, federateInterfaceType);
                        
            // Map the Federate interface to its name.
            addItsFederateInterface(interfaceID, FI_Ptr);   
                       
            if ( (federateInterfaceType == FederateInterfaceTypePublisherSubscriber) || 
                 (federateInterfaceType == FederateInterfaceTypePublisher) )
            {
                getItsFederate()->getThePostOffice()->announcePublication( FI_Ptr );   
            }

            if ( (federateInterfaceType == FederateInterfaceTypePublisherSubscriber) || 
                 (federateInterfaceType == FederateInterfaceTypeSubscriber) )
            {
                getItsFederate()->getThePostOffice()->announceSubscription( FI_Ptr ); 
            }
                         
            return(FI_Ptr); 
            
            //#]
        }
        
        FederateFrameworkType FederateIO_Handler::getFrameworkType() const {
            return frameworkType;
        }
        
        void FederateIO_Handler::setFrameworkType(FederateFrameworkType p_frameworkType) {
            frameworkType = p_frameworkType;
        }
        
        framework::InterfaceType FederateIO_Handler::getInterfaceType() const {
            return interfaceType;
        }
        
        void FederateIO_Handler::setInterfaceType(framework::InterfaceType p_interfaceType) {
            interfaceType = p_interfaceType;
        }
        
        framework::Control::Federate* FederateIO_Handler::getItsFederate() const {
            return itsFederate;
        }
        
        void FederateIO_Handler::__setItsFederate(framework::Control::Federate* p_Federate) {
            itsFederate = p_Federate;
        }
        
        void FederateIO_Handler::_setItsFederate(framework::Control::Federate* p_Federate) {
            if(itsFederate != NULL)
                {
                    itsFederate->__setItsFederateIO_Handler(NULL);
                }
            __setItsFederate(p_Federate);
        }
        
        void FederateIO_Handler::setItsFederate(framework::Control::Federate* p_Federate) {
            if(p_Federate != NULL)
                {
                    p_Federate->_setItsFederateIO_Handler(this);
                }
            _setItsFederate(p_Federate);
        }
        
        void FederateIO_Handler::_clearItsFederate() {
            itsFederate = NULL;
        }
        
        std::map<int, framework::io::FederateInterface*>::const_iterator FederateIO_Handler::getItsFederateInterface() const {
            std::map<int, framework::io::FederateInterface*>::const_iterator iter;
            iter = itsFederateInterface.begin();
            return iter;
        }
        
        std::map<int, framework::io::FederateInterface*>::const_iterator FederateIO_Handler::getItsFederateInterfaceEnd() const {
            return itsFederateInterface.end();
        }
        
        void FederateIO_Handler::_clearItsFederateInterface() {
            itsFederateInterface.clear();
        }
        
        void FederateIO_Handler::clearItsFederateInterface() {
            std::map<int, framework::io::FederateInterface*>::const_iterator iter;
            iter = itsFederateInterface.begin();
            while (iter != itsFederateInterface.end()){
                ((*iter).second)->_clearItsFederateIO_Handler();
                iter++;
            }
            _clearItsFederateInterface();
        }
        
        void FederateIO_Handler::_removeItsFederateInterface(framework::io::FederateInterface* p_FederateInterface) {
            std::map<int, framework::io::FederateInterface*>::iterator pos = std::find_if(itsFederateInterface.begin(), itsFederateInterface.end(),ValueCompare<const int,framework::io::FederateInterface*>(p_FederateInterface));
            if (pos != itsFederateInterface.end()) {
            	itsFederateInterface.erase(pos);
            }
        }
        
        void FederateIO_Handler::removeItsFederateInterface(framework::io::FederateInterface* p_FederateInterface) {
            if(p_FederateInterface != NULL)
                {
                    p_FederateInterface->__setItsFederateIO_Handler(NULL);
                }
            _removeItsFederateInterface(p_FederateInterface);
        }
        
        framework::io::FederateInterface* FederateIO_Handler::getItsFederateInterface(int key) const {
            return (itsFederateInterface.find(key) != itsFederateInterface.end() ? (*itsFederateInterface.find(key)).second : NULL);
        }
        
        void FederateIO_Handler::_addItsFederateInterface(int key, framework::io::FederateInterface* p_FederateInterface) {
            itsFederateInterface.insert(std::map<int, framework::io::FederateInterface*>::value_type(key, p_FederateInterface));
        }
        
        void FederateIO_Handler::addItsFederateInterface(int key, framework::io::FederateInterface* p_FederateInterface) {
            if(p_FederateInterface != NULL)
                {
                    p_FederateInterface->_setItsFederateIO_Handler(this);
                }
            _addItsFederateInterface(key, p_FederateInterface);
        }
        
        void FederateIO_Handler::_removeItsFederateInterface(int key) {
            itsFederateInterface.erase(key);
        }
        
        void FederateIO_Handler::removeItsFederateInterface(int key) {
            framework::io::FederateInterface* p_FederateInterface = getItsFederateInterface(key);
            if(p_FederateInterface != NULL)
                {
                    p_FederateInterface->_setItsFederateIO_Handler(NULL);
                }
            _removeItsFederateInterface(key);
        }
        
        framework::Control::FederateInterfaceFactory* FederateIO_Handler::getItsFederateInterfaceFactory() const {
            return itsFederateInterfaceFactory;
        }
        
        void FederateIO_Handler::setItsFederateInterfaceFactory(framework::Control::FederateInterfaceFactory* p_FederateInterfaceFactory) {
            itsFederateInterfaceFactory = p_FederateInterfaceFactory;
            p_FederateInterfaceFactory->setItsFederateIO_Handler(this);
        }
        
        void FederateIO_Handler::cleanUpRelations() {
            if(itsFederate != NULL)
                {
                    framework::io::FederateIO_Handler* p_FederateIO_Handler = itsFederate->getItsFederateIO_Handler();
                    if(p_FederateIO_Handler != NULL)
                        {
                            itsFederate->__setItsFederateIO_Handler(NULL);
                        }
                    itsFederate = NULL;
                }
            {
                std::map<int, framework::io::FederateInterface*>::const_iterator iter;
                iter = itsFederateInterface.begin();
                while (iter != itsFederateInterface.end()){
                    framework::io::FederateIO_Handler* p_FederateIO_Handler = ((*iter).second)->getItsFederateIO_Handler();
                    if(p_FederateIO_Handler != NULL)
                        {
                          ((*iter).second)->__setItsFederateIO_Handler(NULL);
                          delete (*iter).second;
                        }
                    iter++;
                }
                itsFederateInterface.clear();
            }
            if(itsFederateInterfaceFactory != NULL)
                {
                  delete itsFederateInterfaceFactory;
                  itsFederateInterfaceFactory = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/

