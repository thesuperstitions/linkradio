/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control
//!	Generated Date	: Mon, 7, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\Control.cpp
*********************************************************************/

#include "Control.h"
#include "ExampleFederate.h"
#include "Federate.h"
#include "FederateInterfaceFactory.h"
#include "Serializer.h"

//----------------------------------------------------------------------------
// Control.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::Control 

namespace Framework {
    namespace Control {
        
    }
}

namespace Framework {
    namespace Control {
        
        
        //## operation getFederate() 
        Framework::Control::Federate* getFederate() {
            //#[ operation getFederate() 
            return(theFederate);
            //#]
        }
        
        //## operation setFederate(Framework::Control::Federate*) 
        void setFederate(Framework::Control::Federate* federate) {
            //#[ operation setFederate(Framework::Control::Federate*) 
            theFederate = federate;
            //#]
        }
        
        //## attribute theFederate 
        Framework::Control::Federate* theFederate;
        
    }
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Control.cpp
*********************************************************************/

