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
// link itsBuffer 
#include "Buffer.h"

//----------------------------------------------------------------------------
// Message.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class Message 

namespace Framework {
    namespace IO {
        
        // Static class member attribute
        unsigned long Message::messageCount( 0 );
        
        Message::Message(char* message, unsigned long messageSizeInBytes) {
            itsBuffer = NULL;
            //#[ operation Message(char*,unsigned long) 
            
            // Give this message a unique instance number.
            instanceNumber = messageCount++;
              
            // Creat the Buffer object 
            setItsBuffer(new Buffer(message, messageSizeInBytes)); 
            getItsBuffer()->setItsMessage(this); 
            
            //#]
        }
        
        Message::Message() {
            itsBuffer = NULL;
        }
        
        Message::~Message() {
            cleanUpRelations();
        }
        
        std::string Message::getFederateInterfaceEnetAddress() const {
            return federateInterfaceEnetAddress;
        }
        
        void Message::setFederateInterfaceEnetAddress(std::string p_federateInterfaceEnetAddress) {
            federateInterfaceEnetAddress = p_federateInterfaceEnetAddress;
        }
        
        unsigned long Message::getInstanceNumber() const {
            return instanceNumber;
        }
        
        void Message::setInstanceNumber(unsigned long p_instanceNumber) {
            instanceNumber = p_instanceNumber;
        }
        
        unsigned long Message::getMessageCount() {
            return messageCount;
        }
        
        void Message::setMessageCount(unsigned long p_messageCount) {
            messageCount = p_messageCount;
        }
        
        Framework::IO::Buffer* Message::getItsBuffer() const {
            return itsBuffer;
        }
        
        void Message::__setItsBuffer(Framework::IO::Buffer* p_Buffer) {
            itsBuffer = p_Buffer;
        }
        
        void Message::_setItsBuffer(Framework::IO::Buffer* p_Buffer) {
            if(itsBuffer != NULL)
                {
                    itsBuffer->__setItsMessage(NULL);
                }
            __setItsBuffer(p_Buffer);
        }
        
        void Message::setItsBuffer(Framework::IO::Buffer* p_Buffer) {
            if(p_Buffer != NULL)
                {
                    p_Buffer->_setItsMessage(this);
                }
            _setItsBuffer(p_Buffer);
        }
        
        void Message::_clearItsBuffer() {
            itsBuffer = NULL;
        }
        
        void Message::cleanUpRelations() {
            if(itsBuffer != NULL)
                {
                    Framework::IO::Message* p_Message = itsBuffer->getItsMessage();
                    if(p_Message != NULL)
                        {
                            itsBuffer->__setItsMessage(NULL);
                        }
                    itsBuffer = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Message.cpp
*********************************************************************/

