/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Federate::ExampleFederate
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\ExampleFederate.h
*********************************************************************/


#ifndef ExampleFederate_H 

#define ExampleFederate_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
// class ExampleFederate 
#include "Federate.h"

//----------------------------------------------------------------------------
// ExampleFederate.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateInterface;
        
    } 
    
namespace Federate {
    class FederateInterfaceFactory;
    
} 

namespace IO {
    class PostOffice;
}

}


//## package Framework::Federate 


namespace Framework {
    namespace Federate {
        //## class ExampleFederate 
        class ExampleFederate : public Federate {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            ExampleFederate();
            
            //## auto_generated 
            ~ExampleFederate();
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ExampleFederate.h
*********************************************************************/

