/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::OASIS_FederateInterface
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.cpp
*********************************************************************/

#include "OASIS_FederateInterface.h"
// link itsFederateInterfaceFactory 
#include "FederateInterfaceFactory.h"

//----------------------------------------------------------------------------
// OASIS_FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class OASIS_FederateInterface 

namespace Framework {
    namespace IO {
        
        
        OASIS_FederateInterface::OASIS_FederateInterface() {
            itsFederateInterfaceFactory = NULL;
        }
        
        OASIS_FederateInterface::~OASIS_FederateInterface() {
            cleanUpRelations();
        }
        
        Framework::Federate::FederateInterfaceFactory* OASIS_FederateInterface::getItsFederateInterfaceFactory() const {
            return itsFederateInterfaceFactory;
        }
        
        void OASIS_FederateInterface::setItsFederateInterfaceFactory(Framework::Federate::FederateInterfaceFactory* p_FederateInterfaceFactory) {
            itsFederateInterfaceFactory = p_FederateInterfaceFactory;
        }
        
        void OASIS_FederateInterface::cleanUpRelations() {
            if(itsFederateInterfaceFactory != NULL)
                {
                    itsFederateInterfaceFactory = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.cpp
*********************************************************************/

