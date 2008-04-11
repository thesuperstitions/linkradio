//*********************************************************************************  
//
//	File:				Framework::IO::FederateInterface  
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


#include "FederateInterface.h"

//----------------------------------------------------------------------------
// FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateInterface 

namespace Framework {
    namespace IO {
        
        
        FederateInterface::FederateInterface(std::string name) : name(name) {
            //#[ operation FederateInterface(std::string) 
            //#]
        }
        
        FederateInterface::~FederateInterface() {
        }
        
        std::string FederateInterface::getInterfaceName() const {
            return interfaceName;
        }
        
        void FederateInterface::setInterfaceName(std::string p_interfaceName) {
            interfaceName = p_interfaceName;
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.cpp
*********************************************************************/

