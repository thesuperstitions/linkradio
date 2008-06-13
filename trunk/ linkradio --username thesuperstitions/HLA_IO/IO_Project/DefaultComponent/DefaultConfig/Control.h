/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\Control.h
*********************************************************************/


#ifndef Control_H 

#define Control_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "framework.h"

//----------------------------------------------------------------------------
// Control.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace Control {
        class Federate;
        class FederateInterfaceFactory;
        class HlaCecFederate;
        
    } 
    
namespace IO {
    class PostOffice;
    
} 

namespace Control {
    class Serializer;
}

}


//## package framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif


namespace framework {
    
    namespace Control {
        
        
        //## operation getFederate() 
        framework::Control::Federate* getFederate();
        
        //## operation setFederate(framework::Control::Federate*) 
        void setFederate(framework::Control::Federate* federate);
        
        //## attribute theFederate 
        extern framework::Control::Federate* theFederate;
        
        
    }
    
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Control.h
*********************************************************************/

