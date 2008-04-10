/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::FrameworkControl
//!	Generated Date	: Wed, 20, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FrameworkControl.cpp
*********************************************************************/

#include "FrameworkControl.h"

//----------------------------------------------------------------------------
// FrameworkControl.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework 

//## class FrameworkControl 

namespace Framework {
    
    FrameworkControl::FrameworkControl() {
        //#[ operation FrameworkControl() 
        PostOffice = new static_cast<PostOffice*>(Framework::IO::HLA_PostOffice());
        
        Federate_1 = new Framework::Control::Federate(FederateFrameworkType, CEC);
        
        Federate_2 = new Framework::Control::Federate(FederateFrameworkType, SSDS);
        //#]
    }
    
    FrameworkControl::~FrameworkControl() {
    }
    
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkControl.cpp
*********************************************************************/

