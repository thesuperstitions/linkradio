/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control::HlaCecFederate
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\HlaCecFederate.h
*********************************************************************/


#ifndef HlaCecFederate_H 

#define HlaCecFederate_H 

#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Control.h"
// class HlaCecFederate 
#include "Federate.h"

//----------------------------------------------------------------------------
// HlaCecFederate.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace Control {
        class FederateInterfaceFactory;
        
    } 
    
namespace io {
    class FederateIO_Handler;
    class HLA_PostOffice;
    class PostOffice;
}

}


//## package framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
    namespace Control {
        //## class HlaCecFederate 
        class HlaCecFederate : public Federate {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation HlaCecFederate() 
            HlaCecFederate(int unitNumber);
            
            //## auto_generated 
            ~HlaCecFederate();
        
        
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
	File Path	: DefaultComponent\DefaultConfig\HlaCecFederate.h
*********************************************************************/

