/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::ExampleFederate
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\ExampleFederate.h
*********************************************************************/


#ifndef boost_interprocess_sync_ExampleFederate_H 

#define boost_interprocess_sync_ExampleFederate_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "boost\interprocess\sync\Control.h"
// operation ExampleFederate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
#include "boost\interprocess\sync\Framework.h"
// class ExampleFederate 
#include "boost\interprocess\sync\Federate.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\ExampleFederate.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class FederateInterfaceFactory;
        
    } 
    
namespace IO {
    class FederateIO_Handler;
    
} 

} 

namespace Framework {
    class FrameworkFederateAmbassador;
    
} 

namespace Framework {
    
    namespace IO {
        class HLA_PostOffice;
        class PostOffice;
    }
    
}


//## package Framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace Control {
        //## class ExampleFederate 
        class ExampleFederate : public Federate {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation ExampleFederate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
            ExampleFederate(FederateFrameworkType fedFrameworkType, FederateType fedType, FrameworkFederateAmbassador* frameworkFederateAmbassador);
            
            //## auto_generated 
            ~ExampleFederate();
        
        
        ////    Operations    ////
        public :
            
            //## operation useCase_42_1_announcePublication() 
            void useCase_42_1_announcePublication();
            
            //## operation useCase_42_2_announceSubscription() 
            void useCase_42_2_announceSubscription();
            
            //## operation useCase_42_3_sendMessageOnFederateInterface() 
            void useCase_42_3_sendMessageOnFederateInterface();
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\ExampleFederate.h
*********************************************************************/

