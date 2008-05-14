/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Control.h
*********************************************************************/


#ifndef boost_interprocess_sync_Control_H 

#define boost_interprocess_sync_Control_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "boost\interprocess\sync\Framework.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\Control.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class ExampleFederate;
        class Federate;
        class FederateInterfaceFactory;
        
    } 
    
namespace IO {
    class PostOffice;
    
} 

namespace Control {
    class Serializer;
}

}


//## package Framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif


namespace Framework {
    
    namespace Control {
        
        
        //## operation getFederate() 
        Framework::Control::Federate* getFederate();
        
        //## operation setFederate(Framework::Control::Federate*) 
        void setFederate(Framework::Control::Federate* federate);
        
        //## attribute theFederate 
        extern Framework::Control::Federate* theFederate;
        
        
    }
    
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Control.h
*********************************************************************/

