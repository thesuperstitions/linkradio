/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterface
//!	Generated Date	: Mon, 14, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.cpp
*********************************************************************/

#include "FederateInterface.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"

//----------------------------------------------------------------------------
// FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateInterface 

namespace Framework {
    namespace IO {
        
        
        FederateInterface::FederateInterface(std::string name, Framework::InterfaceType interfaceType) : interfaceName(name), interfaceType(interfaceType) {
            itsFederateIO_Handler = NULL;
            //#[ operation FederateInterface(std::string,Framework::InterfaceType) 
            
            
            //#]
        }
        
        FederateInterface::~FederateInterface() {
            cleanUpRelations();
        }
        
        std::string FederateInterface::getInterfaceName() const {
            return interfaceName;
        }
        
        void FederateInterface::setInterfaceName(std::string p_interfaceName) {
            interfaceName = p_interfaceName;
        }
        
        Framework::InterfaceType FederateInterface::getInterfaceType() const {
            return interfaceType;
        }
        
        void FederateInterface::setInterfaceType(Framework::InterfaceType p_interfaceType) {
            interfaceType = p_interfaceType;
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
                    p_FederateIO_Handler->_addItsFederateInterface(getInterfaceName(), this);
                }
            _setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void FederateInterface::_clearItsFederateIO_Handler() {
            itsFederateIO_Handler = NULL;
        }
        
        void FederateInterface::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    Framework::IO::FederateIO_Handler* current = itsFederateIO_Handler;
                    if(current != NULL)
                        {
                            current->_removeItsFederateInterface(interfaceName);
                        }
                    itsFederateIO_Handler = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.cpp
*********************************************************************/

