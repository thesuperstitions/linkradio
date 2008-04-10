//*********************************************************************************  
//
//	File:				Framework::Federate::ExampleFederate  
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



#ifndef ExampleFederate_H 

#define ExampleFederate_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
// class ExampleFederate 
#include "Federate.h"

//----------------------------------------------------------------------------
// ExampleFederate.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Federate {
        class FederateInterfaceFactory;
        
    } 
    
namespace IO {
    class PostOffice;
}

}


//## package Framework::Federate 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

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

