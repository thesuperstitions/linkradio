//*********************************************************************************  
//
//	File:				Framework::Control::Serializer  
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



#ifndef Serializer_H 

#define Serializer_H 

#include <oxf/oxf.h>


#include <string>
#include <algorithm>
#include "Control.h"
// dependency IO 
#include "IO.h"

//----------------------------------------------------------------------------
// Serializer.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class IO_Handler;
    }
    
}


//## package Framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace Control {
        //## class Serializer 
        class Serializer  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            Serializer();
            
            //## auto_generated 
            ~Serializer();
        
        
        ////    Operations    ////
        public :
            
            //## operation deserialize(T,const Framework::IO::Buffer &) 
            template <class T> inline void deserialize(T Type, const Framework::IO::Buffer & arg2) {
                //#[ operation deserialize(T,const Framework::IO::Buffer &) 
                //#]
            }
            
            
            //## operation serialize(T,const Framework::IO::Buffer &) 
            template <class T> inline void serialize(T Type, const Framework::IO::Buffer & arg2) {
                //#[ operation serialize(T,const Framework::IO::Buffer &) 
                //#]
            }
            
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            IO::IO_Handler* getItsIO_Handler() const;
            
            //## auto_generated 
            void setItsIO_Handler(IO::IO_Handler* p_IO_Handler);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsIO_Handler(IO::IO_Handler* p_IO_Handler);
            
            //## auto_generated 
            void _setItsIO_Handler(IO::IO_Handler* p_IO_Handler);
            
            //## auto_generated 
            void _clearItsIO_Handler();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            IO::IO_Handler* itsIO_Handler;		//## link itsIO_Handler 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Serializer.h
*********************************************************************/

