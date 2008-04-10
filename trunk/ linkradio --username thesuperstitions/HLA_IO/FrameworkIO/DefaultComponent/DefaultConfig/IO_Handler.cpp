//*********************************************************************************  
//
//	File:				Framework::IO::IO_Handler  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Mon, 11, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************


#include "IO_Handler.h"
// link itsSerializer 
#include "Serializer.h"
// operation getType(Buffer*) 
#include "Buffer.h"
// operation recvMessage(FederateMessage*) 
#include "FederateMessage.h"
// link itsPostOffice 
#include "PostOffice.h"

//----------------------------------------------------------------------------
// IO_Handler.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class IO_Handler 

namespace Framework {
    namespace IO {
        
        
        IO_Handler::IO_Handler() {
            itsPostOffice = NULL;
            itsSerializer = NULL;
        }
        
        IO_Handler::~IO_Handler() {
            cleanUpRelations();
        }
        
        void IO_Handler::callInputFunc(MessageType Type, unsigned int timeout) {
            //#[ operation callInputFunc(MessageType,unsigned int) 
            //#]
        }
        
        void IO_Handler::callOutputFunc(MessageType Type) {
            //#[ operation callOutputFunc(MessageType) 
            //#]
        }
        
        Framework::MessageType* IO_Handler::getType(Buffer* buffer) {
            //#[ operation getType(Buffer*) 
            return(NULL);  //This is just temporary until the code is fleshed out.
            //#]
        }
        
        void IO_Handler::recvMessage(FederateMessage* message) {
            //#[ operation recvMessage(FederateMessage*) 
            //#]
        }
        
        Framework::IO::PostOffice* IO_Handler::getItsPostOffice() const {
            return itsPostOffice;
        }
        
        void IO_Handler::__setItsPostOffice(Framework::IO::PostOffice* p_PostOffice) {
            itsPostOffice = p_PostOffice;
        }
        
        void IO_Handler::_setItsPostOffice(Framework::IO::PostOffice* p_PostOffice) {
            if(itsPostOffice != NULL)
                {
                    itsPostOffice->_removeItsIO_Handler(this);
                }
            __setItsPostOffice(p_PostOffice);
        }
        
        void IO_Handler::setItsPostOffice(Framework::IO::PostOffice* p_PostOffice) {
            if(p_PostOffice != NULL)
                {
                    p_PostOffice->_addItsIO_Handler(this);
                }
            _setItsPostOffice(p_PostOffice);
        }
        
        void IO_Handler::_clearItsPostOffice() {
            itsPostOffice = NULL;
        }
        
        Framework::Control::Serializer* IO_Handler::getItsSerializer() const {
            return itsSerializer;
        }
        
        void IO_Handler::__setItsSerializer(Framework::Control::Serializer* p_Serializer) {
            itsSerializer = p_Serializer;
        }
        
        void IO_Handler::_setItsSerializer(Framework::Control::Serializer* p_Serializer) {
            if(itsSerializer != NULL)
                {
                    itsSerializer->__setItsIO_Handler(NULL);
                }
            __setItsSerializer(p_Serializer);
        }
        
        void IO_Handler::setItsSerializer(Framework::Control::Serializer* p_Serializer) {
            if(p_Serializer != NULL)
                {
                    p_Serializer->_setItsIO_Handler(this);
                }
            _setItsSerializer(p_Serializer);
        }
        
        void IO_Handler::_clearItsSerializer() {
            itsSerializer = NULL;
        }
        
        void IO_Handler::cleanUpRelations() {
            if(itsPostOffice != NULL)
                {
                    Framework::IO::PostOffice* current = itsPostOffice;
                    if(current != NULL)
                        {
                            current->_removeItsIO_Handler(this);
                        }
                    itsPostOffice = NULL;
                }
            if(itsSerializer != NULL)
                {
                    Framework::IO::IO_Handler* p_IO_Handler = itsSerializer->getItsIO_Handler();
                    if(p_IO_Handler != NULL)
                        {
                            itsSerializer->__setItsIO_Handler(NULL);
                        }
                    itsSerializer = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IO_Handler.cpp
*********************************************************************/

