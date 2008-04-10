//*********************************************************************************  
//
//	File:				Framework::IO::Buffer  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Fri, 15, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef Buffer_H 

#define Buffer_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"

//----------------------------------------------------------------------------
// Buffer.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Message;
    }
    
}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        // namespace Framework {
        //    namespace IO {
        //## class Buffer 
        class Buffer  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            Buffer();
            
            //## auto_generated 
            ~Buffer();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Message* getItsMessage() const;
            
            //## auto_generated 
            void setItsMessage(Message* p_Message);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsMessage(Message* p_Message);
            
            //## auto_generated 
            void _setItsMessage(Message* p_Message);
            
            //## auto_generated 
            void _clearItsMessage();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Message* itsMessage;		//## link itsMessage 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Buffer.h
*********************************************************************/

