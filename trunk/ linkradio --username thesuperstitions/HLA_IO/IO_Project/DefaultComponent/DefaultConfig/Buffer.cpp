/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Buffer
//!	Generated Date	: Wed, 14, May 2008  
	File Path	: DefaultComponent\DefaultConfig\Buffer.cpp
*********************************************************************/

#include "Buffer.h"

//----------------------------------------------------------------------------
// Buffer.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class Buffer 

namespace Framework {
    namespace IO {
        
        
        Buffer::Buffer(char* byteArray, unsigned long sizeOfByteArray) : byteArray(byteArray), sizeOfByteArray(sizeOfByteArray) {
            //#[ operation Buffer(char*,unsigned long) 
            //#]
        }
        
        Buffer::Buffer() {
        }
        
        Buffer::~Buffer() {
            //#[ operation ~Buffer() 
            delete byteArray;
            byteArray = NULL; 
            sizeOfByteArray = 0;
            //#]
        }
        
        char* Buffer::getByteArray() const {
            return byteArray;
        }
        
        void Buffer::setByteArray(char* p_byteArray) {
            byteArray = p_byteArray;
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Buffer.cpp
*********************************************************************/

