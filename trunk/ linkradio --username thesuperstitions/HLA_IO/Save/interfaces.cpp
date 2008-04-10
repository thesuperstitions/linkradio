//*********************************************************************************  
//
//	File:				Framework::IO::interfaces  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Mon, 11, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************


#include "interfaces.h"

//----------------------------------------------------------------------------
// interfaces.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class interfaces 

namespace Framework {
    namespace IO {
        
        
        interfaces::interfaces() {
        }
        
        interfaces::~interfaces() {
        }
        
        std::string interfaces::getName() const {
            return name;
        }
        
        void interfaces::setName(std::string p_name) {
            name = p_name;
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\interfaces.cpp
*********************************************************************/

