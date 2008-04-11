/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::RTI_Ambassador
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\RTI_Ambassador.h
*********************************************************************/


#ifndef RTI_Ambassador_H 

#define RTI_Ambassador_H 

#include <oxf/oxf.h>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Control.h"

//----------------------------------------------------------------------------
// RTI_Ambassador.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::Control 


namespace Framework {
    namespace Control {
        //## class RTI_Ambassador 
        class RTI_Ambassador  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            RTI_Ambassador();
            
            //## auto_generated 
            ~RTI_Ambassador();
        
        
        ////    Operations    ////
        public :
            
            //## operation publishInteractionClass(rti1516::InteractionClassHandle) 
            void publishInteractionClass(rti1516::InteractionClassHandle handle);
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RTI_Ambassador.h
*********************************************************************/

