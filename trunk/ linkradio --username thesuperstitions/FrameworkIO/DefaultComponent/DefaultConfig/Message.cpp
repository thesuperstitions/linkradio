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
//!	Date of createion:	Fri, 8, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************


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

