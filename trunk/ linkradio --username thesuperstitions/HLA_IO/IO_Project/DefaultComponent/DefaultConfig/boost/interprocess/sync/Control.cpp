/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Control.cpp
*********************************************************************/

#include "boost\interprocess\sync\Control.h"
#include "boost\interprocess\sync\ExampleFederate.h"
#include "boost\interprocess\sync\Federate.h"
#include "boost\interprocess\sync\FederateInterfaceFactory.h"
#include "boost\interprocess\sync\Serializer.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\Control.cpp                                                                  
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
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Control.cpp
*********************************************************************/

