/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Buffer
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\Buffer.cpp
*********************************************************************/

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

