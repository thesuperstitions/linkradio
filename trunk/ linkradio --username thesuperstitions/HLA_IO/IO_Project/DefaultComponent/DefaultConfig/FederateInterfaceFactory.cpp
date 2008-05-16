/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::FederateInterfaceFactory
//!	Generated Date	: Thu, 15, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.cpp
*********************************************************************/

#include "FederateInterfaceFactory.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"
// dependency HLA_FederateInterface 
#include "HLA_FederateInterface.h"
// dependency OASIS_FederateInterface 
#include "OASIS_FederateInterface.h"

//----------------------------------------------------------------------------
// FederateInterfaceFactory.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::Control 

//## class FederateInterfaceFactory 

namespace Framework {
    namespace Control {
        
        
        FederateInterfaceFactory::FederateInterfaceFactory(const FederateFrameworkType& frameworkType) {
            itsFederateIO_Handler = NULL;
            //#[ operation FederateInterfaceFactory(FederateFrameworkType) 
            //#]
        }
        
        FederateInterfaceFactory::FederateInterfaceFactory() {
            itsFederateIO_Handler = NULL;
        }
        
        FederateInterfaceFactory::~FederateInterfaceFactory() {
            cleanUpRelations();
        }
        
        Framework::IO::FederateInterface* FederateInterfaceFactory::createFederateInterface(std::string name, Framework::InterfaceType interfaceType, FederateInterfaceType federateInterfaceType) {
            //#[ operation createFederateInterface(std::string,Framework::InterfaceType,FederateInterfaceType) 
            switch(fedFrameworkType)
            {
              case HLA_FederateFrameworkType:
                return( static_cast<Framework::IO::FederateInterface*>( new Framework::IO::HLA_FederateInterface(interfaceID, name, interfaceType) ) );
              
              case OASIS_FederateFrameworkType:
                return( static_cast<Framework::IO::FederateInterface*>( new Framework::IO::OASIS_FederateInterface(interfaceID, name, interfaceType) ) );
            };  
            
            return(NULL);          
            //#]
        }
        
        FederateFrameworkType FederateInterfaceFactory::getFedFrameworkType() const {
            return fedFrameworkType;
        }
        
        void FederateInterfaceFactory::setFedFrameworkType(FederateFrameworkType p_fedFrameworkType) {
            fedFrameworkType = p_fedFrameworkType;
        }
        
        Framework::IO::FederateIO_Handler* FederateInterfaceFactory::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void FederateInterfaceFactory::setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void FederateInterfaceFactory::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.cpp
*********************************************************************/

