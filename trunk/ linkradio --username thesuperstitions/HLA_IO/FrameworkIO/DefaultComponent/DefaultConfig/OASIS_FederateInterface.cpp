//*********************************************************************************  
//
//	File:				Framework::IO::OASIS_FederateInterface  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Thu, 14, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************


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

