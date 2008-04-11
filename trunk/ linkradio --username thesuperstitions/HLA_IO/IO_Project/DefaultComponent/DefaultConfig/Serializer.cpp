/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::Serializer
//!	Generated Date	: Fri, 4, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\Serializer.cpp
*********************************************************************/

#include "Serializer.h"
// link itsIO_Handler 
#include "IO_Handler.h"

//----------------------------------------------------------------------------
// Serializer.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::Control 

//## class Serializer 

namespace Framework {
    namespace Control {
        
        
        Serializer::Serializer() {
            itsIO_Handler = NULL;
        }
        
        Serializer::~Serializer() {
            cleanUpRelations();
        }
        
        Framework::IO::IO_Handler* Serializer::getItsIO_Handler() const {
            return itsIO_Handler;
        }
        
        void Serializer::__setItsIO_Handler(Framework::IO::IO_Handler* p_IO_Handler) {
            itsIO_Handler = p_IO_Handler;
        }
        
        void Serializer::_setItsIO_Handler(Framework::IO::IO_Handler* p_IO_Handler) {
            if(itsIO_Handler != NULL)
                {
                    itsIO_Handler->__setItsSerializer(NULL);
                }
            __setItsIO_Handler(p_IO_Handler);
        }
        
        void Serializer::setItsIO_Handler(Framework::IO::IO_Handler* p_IO_Handler) {
            if(p_IO_Handler != NULL)
                {
                    p_IO_Handler->_setItsSerializer(this);
                }
            _setItsIO_Handler(p_IO_Handler);
        }
        
        void Serializer::_clearItsIO_Handler() {
            itsIO_Handler = NULL;
        }
        
        void Serializer::cleanUpRelations() {
            if(itsIO_Handler != NULL)
                {
                    Framework::Control::Serializer* p_Serializer = itsIO_Handler->getItsSerializer();
                    if(p_Serializer != NULL)
                        {
                            itsIO_Handler->__setItsSerializer(NULL);
                        }
                    itsIO_Handler = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Serializer.cpp
*********************************************************************/

