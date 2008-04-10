//*********************************************************************************  
//
//	File:				Framework::IO::C_FunctionCalls  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Fri, 8, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef C_FunctionCalls_H 

#define C_FunctionCalls_H 

#include <string>
#include <algorithm>
#include "IO.h"

//----------------------------------------------------------------------------
// C_FunctionCalls.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
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
        //## class C_FunctionCalls 
        class C_FunctionCalls  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            C_FunctionCalls();
            
            //## auto_generated 
            ~C_FunctionCalls();
        
        
        ////    Operations    ////
        public :
            
            //## operation callOutputFunc(T) 
            template <class T> inline static void callOutputFunc(T Type) {
                //#[ operation callOutputFunc(T) 
                //#]
            }
            
            
            //## operation callOutputFunc(T,int) 
            template <class T> inline static void callOutputFunc(T Type, int timeout) {
                //#[ operation callOutputFunc(T,int) 
                //#]
            }
            
            
            //## operation getInterface(char*) 
            static void getInterface(char* interfaceName);
            
            //## operation getRawBuffer(Buffer) 
            static void getRawBuffer(const Buffer& buffer);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _clearItsFederateIO_Handler();
        
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
	File Path	: DefaultComponent\DefaultConfig\C_FunctionCalls.h
*********************************************************************/

