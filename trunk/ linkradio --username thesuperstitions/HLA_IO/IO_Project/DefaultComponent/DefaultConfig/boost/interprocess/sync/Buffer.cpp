/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Buffer
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Buffer.cpp
*********************************************************************/

#include "boost\interprocess\sync\Buffer.h"
// link itsMessage 
#include "boost\interprocess\sync\Message.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\Buffer.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class Buffer 

namespace Framework {
    namespace IO {
        
        
        Buffer::Buffer(char* byteArray, unsigned long sizeOfByteArray) : byteArray(byteArray), sizeOfByteArray(sizeOfByteArray) {
            itsMessage = NULL;
            //#[ operation Buffer(char*,unsigned long) 
            //#]
        }
        
        Buffer::Buffer() {
            itsMessage = NULL;
        }
        
        Buffer::~Buffer() {
            //#[ operation ~Buffer() 
            delete byteArray;
            byteArray = NULL; 
            sizeOfByteArray = 0;
            //#]
            cleanUpRelations();
        }
        
        char* Buffer::getByteArray() const {
            return byteArray;
        }
        
        void Buffer::setByteArray(char* p_byteArray) {
            byteArray = p_byteArray;
        }
        
        unsigned long Buffer::getSizeOfByteArray() const {
            return sizeOfByteArray;
        }
        
        void Buffer::setSizeOfByteArray(unsigned long p_sizeOfByteArray) {
            sizeOfByteArray = p_sizeOfByteArray;
        }
        
        Framework::IO::Message* Buffer::getItsMessage() const {
            return itsMessage;
        }
        
        void Buffer::__setItsMessage(Framework::IO::Message* p_Message) {
            itsMessage = p_Message;
        }
        
        void Buffer::_setItsMessage(Framework::IO::Message* p_Message) {
            if(itsMessage != NULL)
                {
                    itsMessage->__setItsBuffer(NULL);
                }
            __setItsMessage(p_Message);
        }
        
        void Buffer::setItsMessage(Framework::IO::Message* p_Message) {
            if(p_Message != NULL)
                {
                    p_Message->_setItsBuffer(this);
                }
            _setItsMessage(p_Message);
        }
        
        void Buffer::_clearItsMessage() {
            itsMessage = NULL;
        }
        
        void Buffer::cleanUpRelations() {
            if(itsMessage != NULL)
                {
                    Framework::IO::Buffer* p_Buffer = itsMessage->getItsBuffer();
                    if(p_Buffer != NULL)
                        {
                            itsMessage->__setItsBuffer(NULL);
                        }
                    itsMessage = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Buffer.cpp
*********************************************************************/

