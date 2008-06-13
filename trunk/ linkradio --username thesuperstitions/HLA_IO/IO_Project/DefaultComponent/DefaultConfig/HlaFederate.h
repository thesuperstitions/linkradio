/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control::HlaFederate
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\HlaFederate.h
*********************************************************************/


#ifndef HlaFederate_H 

#define HlaFederate_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Control.h"
// class HlaFederate 
#include "Federate.h"

//----------------------------------------------------------------------------
// HlaFederate.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace Control {
        class FederateInterfaceFactory;
        
    } 
    
namespace IO {
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
        //## class HlaFederate 
        class HlaFederate : public Federate {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation HlaFederate() 
            HlaFederate();
            
            //## auto_generated 
            ~HlaFederate();
        
        
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
	File Path	: DefaultComponent\DefaultConfig\HlaFederate.h
*********************************************************************/

