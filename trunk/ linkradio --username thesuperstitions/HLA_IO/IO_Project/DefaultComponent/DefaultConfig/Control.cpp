/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\Control.cpp
*********************************************************************/

#include "Control.h"
#include "Federate.h"
#include "FederateInterfaceFactory.h"
#include "HlaCecFederate.h"
#include "Serializer.h"

//----------------------------------------------------------------------------
// Control.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::Control 

namespace framework {
    namespace Control {
        
    }
}

namespace framework {
    namespace Control {
        
        
        //## operation getFederate() 
        framework::Control::Federate* getFederate() {
            //#[ operation getFederate() 
            return(theFederate);
            //#]
        }
        
        //## operation setFederate(framework::Control::Federate*) 
        void setFederate(framework::Control::Federate* federate) {
            //#[ operation setFederate(framework::Control::Federate*) 
            theFederate = federate;
            //#]
        }
        
        //## attribute theFederate 
        framework::Control::Federate* theFederate;
        
    }
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Control.cpp
*********************************************************************/

