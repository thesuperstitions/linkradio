/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Message
//!	Generated Date	: Wed, 14, May 2008  
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
        
        // Static class member attribute
        unsigned long Message::messageCount( 0 );
        
        Message::Message(unsigned char* message, unsigned long messageSizeInBytes) : messagePtr(message), sizeOfMessageInBytes(SizeInBytes), messageCount++ {
            //#[ operation Message(unsigned char*,unsigned long) 
            
            // Give this message a unique instance number.
            instanceNumber = messageCount++;
              
            // Creat the Buffer object 
            setItsBuffer(new Buffer(message, messageSizeInBytes)); 
            getItsBuffer()->setItsMessage(this); 
            
            //#]
        }
        
        Message::Message() {
        }
        
        Message::~Message() {
        }
        
        unsigned long Message::getMessageCount() {
            return messageCount;
        }
        
        void Message::setMessageCount(unsigned long p_messageCount) {
            messageCount = p_messageCount;
        }
        
        unsigned char* Message::getMessagePtr() const {
            return messagePtr;
        }
        
        void Message::setMessagePtr(unsigned char* p_messagePtr) {
            messagePtr = p_messagePtr;
        }
        
        unsigned long Message::getSizeOfMessageInBytes() const {
            return sizeOfMessageInBytes;
        }
        
        void Message::setSizeOfMessageInBytes(unsigned long p_sizeOfMessageInBytes) {
            sizeOfMessageInBytes = p_sizeOfMessageInBytes;
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Message.cpp
*********************************************************************/

