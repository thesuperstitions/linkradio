//*********************************************************************************  
//
//	File:				Framework::IO::interfaces  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Mon, 11, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef interfaces_H 

#define interfaces_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"

//----------------------------------------------------------------------------
// interfaces.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class interfaces 
        class interfaces  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            interfaces();
            
            //## auto_generated 
            ~interfaces();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            std::string getName() const;
            
            //## auto_generated 
            void setName(std::string p_name);
        
        
        ////    Attributes    ////
        protected :
            
            std::string name;		//## attribute name 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\interfaces.h
*********************************************************************/

