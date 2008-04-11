//*********************************************************************************  
//
//	File:				Framework::Control::RTI_Ambassador  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Thu, 14, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef RTI_Ambassador_H 

#define RTI_Ambassador_H 

#include <oxf/oxf.h>

#ifdef WIN32
#pragma warning(disable: 4251)
#pragma warning(disable: 4786)
#pragma warning(disable: 4290)
#endif

#include <RTI/RTI1516.h>

#include <string>
#include <algorithm>
#include "Control.h"

//----------------------------------------------------------------------------
// RTI_Ambassador.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

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
            
            //## operation publishInteractionClass(Handle*) 
            void publishInteractionClass(rti1516::InteractionClassHandle handle);
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RTI_Ambassador.h
*********************************************************************/

