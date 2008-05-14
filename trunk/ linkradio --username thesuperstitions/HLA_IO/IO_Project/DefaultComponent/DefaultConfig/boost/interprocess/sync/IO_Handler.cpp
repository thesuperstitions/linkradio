/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::IO_Handler
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\IO_Handler.cpp
*********************************************************************/

#include "boost\interprocess\sync\IO_Handler.h"
// link itsSerializer 
#include "boost\interprocess\sync\Serializer.h"
// operation recvMessage(int,unsigned long) 
#include "boost\interprocess\sync\FederateMessage.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\IO_Handler.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class IO_Handler 

namespace Framework {
    namespace IO {
        
        
        IO_Handler::IO_Handler() {
            itsSerializer = NULL;
        }
        
        IO_Handler::~IO_Handler() {
            cleanUpRelations();
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
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\IO_Handler.cpp
*********************************************************************/

