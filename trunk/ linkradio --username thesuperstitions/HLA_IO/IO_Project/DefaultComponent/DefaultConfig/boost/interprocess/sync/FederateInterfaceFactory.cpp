/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::FederateInterfaceFactory
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FederateInterfaceFactory.cpp
*********************************************************************/

#include "boost\interprocess\sync\FederateInterfaceFactory.h"
// link itsFederateIO_Handler 
#include "boost\interprocess\sync\FederateIO_Handler.h"
// dependency HLA_FederateInterface 
#include "boost\interprocess\sync\HLA_FederateInterface.h"
// dependency OASIS_FederateInterface 
#include "boost\interprocess\sync\OASIS_FederateInterface.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\FederateInterfaceFactory.cpp                                                                  
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
        
        Framework::IO::FederateInterface* FederateInterfaceFactory::createFederateInterface(std::string name, Framework::InterfaceType interfaceType) {
            //#[ operation createFederateInterface(std::string,Framework::InterfaceType) 
            // Based upon some later-to-be-identified configuration value, the factory creates
            // the appropriate FederateInterface.
            switch(fedFrameworkType)
            {
              case HLA_FederateFrameworkType:
                return( static_cast<Framework::IO::FederateInterface*>( new Framework::IO::HLA_FederateInterface(name, interfaceType) ) );
              
              case OASIS_FederateFrameworkType:
                return( static_cast<Framework::IO::FederateInterface*>( new Framework::IO::OASIS_FederateInterface(name, interfaceType) ) );
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
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FederateInterfaceFactory.cpp
*********************************************************************/

