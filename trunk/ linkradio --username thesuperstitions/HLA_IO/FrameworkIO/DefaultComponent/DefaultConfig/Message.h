//*********************************************************************************  
//
//	File:				Framework::IO::Message  
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



#ifndef Message_H 

#define Message_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"
// link itsBuffer 
#include "Buffer.h"

//----------------------------------------------------------------------------
// Message.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class Message 
        class Message  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            Message();
            
            //## auto_generated 
            ~Message();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Buffer* getItsBuffer() const;
        
        
        ////    Framework operations    ////
        protected :
            
            //## auto_generated 
            void initRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Buffer itsBuffer;		//## link itsBuffer 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Message.h
*********************************************************************/

