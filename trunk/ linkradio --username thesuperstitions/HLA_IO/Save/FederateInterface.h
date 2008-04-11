//*********************************************************************************  
//
//	File:				Framework::IO::FederateInterface  
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



#ifndef FederateInterface_H 

#define FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"

//----------------------------------------------------------------------------
// FederateInterface.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class FederateInterface 
        class FederateInterface  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation FederateInterface(std::string) 
            FederateInterface(std::string name);
            
            //## auto_generated 
            ~FederateInterface();
        
        
        ////    Additional operations    ////
        protected :
            
            //## auto_generated 
            std::string getInterfaceName() const;
            
            //## auto_generated 
            void setInterfaceName(std::string p_interfaceName);
        
        
        ////    Attributes    ////
        protected :
            
            std::string interfaceName;		//## attribute interfaceName 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/

