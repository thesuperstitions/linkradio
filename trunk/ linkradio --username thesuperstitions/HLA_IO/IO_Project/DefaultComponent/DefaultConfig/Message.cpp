/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Message
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\Message.cpp
*********************************************************************/

#include "Message.h"

//----------------------------------------------------------------------------
// Message.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class Message 

namespace Framework {
    namespace IO {
        
        
        Message::Message() {
            initRelations();
        }
        
        Message::~Message() {
        }
        
        Framework::IO::Buffer* Message::getItsBuffer() const {
            return (Framework::IO::Buffer*) &itsBuffer;
        }
        
        void Message::initRelations() {
            itsBuffer._setItsMessage(this);
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Message.cpp
*********************************************************************/

