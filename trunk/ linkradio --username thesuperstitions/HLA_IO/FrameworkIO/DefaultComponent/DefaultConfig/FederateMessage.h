//*********************************************************************************  
//
//	File:				Framework::IO::FederateMessage  
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



#ifndef FederateMessage_H 

#define FederateMessage_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"
// class FederateMessage 
#include "Message.h"

//----------------------------------------------------------------------------
// FederateMessage.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        class FederateInterface;
        class FederateIO_Handler;
    }
    
}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class FederateMessage 
        class FederateMessage : public Message {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            FederateMessage();
            
            //## auto_generated 
            ~FederateMessage();
        
        
        ////    Operations    ////
        public :
            
            //## operation create(FederateInterface*,unsigned int) 
            void create(FederateInterface* interface, unsigned int InstanceNumber);
            
            //## operation create(FederateInterface*,Buffer*) 
            void create(FederateInterface* interface, Buffer* buffer);
            
            //## operation getBuffer() 
            Buffer* getBuffer();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
        
        
        ////    Framework operations    ////
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateMessage.h
*********************************************************************/

