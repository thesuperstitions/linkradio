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
//!	Date of createion:	Thu, 14, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************


#include "Buffer.h"
// link itsMessage 
#include "Message.h"

//----------------------------------------------------------------------------
// Buffer.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class Buffer 

namespace Framework {
    namespace IO {
        
        
        Buffer::Buffer() {
            itsMessage = NULL;
        }
        
        Buffer::~Buffer() {
            cleanUpRelations();
        }
        
        Framework::IO::Message* Buffer::getItsMessage() const {
            return itsMessage;
        }
        
        void Buffer::__setItsMessage(Framework::IO::Message* p_Message) {
            itsMessage = p_Message;
        }
        
        void Buffer::_setItsMessage(Framework::IO::Message* p_Message) {
            __setItsMessage(p_Message);
        }
        
        void Buffer::setItsMessage(Framework::IO::Message* p_Message) {
            _setItsMessage(p_Message);
        }
        
        void Buffer::_clearItsMessage() {
            itsMessage = NULL;
        }
        
        void Buffer::cleanUpRelations() {
            if(itsMessage != NULL)
                {
                    itsMessage = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Buffer.cpp
*********************************************************************/

