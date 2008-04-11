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


#include "C_FunctionCalls.h"
// operation getRawBuffer(Buffer) 
#include "Buffer.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"

//----------------------------------------------------------------------------
// C_FunctionCalls.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class C_FunctionCalls 

namespace Framework {
    namespace IO {
        
        
        C_FunctionCalls::C_FunctionCalls() {
            itsFederateIO_Handler = NULL;
        }
        
        C_FunctionCalls::~C_FunctionCalls() {
            cleanUpRelations();
        }
        
        void C_FunctionCalls::getInterface(char* interfaceName) {
            //#[ operation getInterface(char*) 
            ///
            //#]
        }
        
        void C_FunctionCalls::getRawBuffer(const Buffer& buffer) {
            //#[ operation getRawBuffer(Buffer) 
            //#]
        }
        
        Framework::IO::FederateIO_Handler* C_FunctionCalls::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void C_FunctionCalls::__setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void C_FunctionCalls::_setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler->_removeItsC_FunctionCalls(this);
                }
            __setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void C_FunctionCalls::setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(p_FederateIO_Handler != NULL)
                {
                    p_FederateIO_Handler->_addItsC_FunctionCalls(this);
                }
            _setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void C_FunctionCalls::_clearItsFederateIO_Handler() {
            itsFederateIO_Handler = NULL;
        }
        
        void C_FunctionCalls::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    Framework::IO::FederateIO_Handler* current = itsFederateIO_Handler;
                    if(current != NULL)
                        {
                            current->_removeItsC_FunctionCalls(this);
                        }
                    itsFederateIO_Handler = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_FunctionCalls.cpp
*********************************************************************/

