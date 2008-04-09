//*********************************************************************************  
//
//	File:				DefaultConfig  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Fri, 8, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************


#include "MainDefaultComponent.h"

//----------------------------------------------------------------------------
// MainDefaultComponent.cpp                                                                  
//----------------------------------------------------------------------------

//## configuration DefaultComponent::DefaultConfig 
int main(int argc, char* argv[]) {
    if(OXF::initialize(argc, argv, 6423))
        {
            //#[ configuration DefaultComponent::DefaultConfig 
            //#]
            OXF::start();
            return 0;
        }
    else
        {
            return 1;
        }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

