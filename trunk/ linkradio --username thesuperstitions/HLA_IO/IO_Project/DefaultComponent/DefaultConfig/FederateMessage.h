/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateMessage
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateMessage.h
*********************************************************************/


#ifndef FederateMessage_H 

#define FederateMessage_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// class FederateMessage 
#include "Message.h"

//----------------------------------------------------------------------------
// FederateMessage.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        class FederateInterface;
        class FederateIO_Handler;
    }
    
}


//## package Framework::IO 


namespace Framework {
    namespace IO {
        //## class FederateMessage 
        class FederateMessage : public Message {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            FederateMessage();
            
            //## auto_generated 
            ~FederateMessage();
        
        
        ////    Operations    ////
        public :
            
            //## operation create(FederateInterface*,unsigned int) 
            void create(FederateInterface* interface, unsigned int InstanceNumber);
            
            //## operation create(FederateInterface*,Buffer*) 
            void create(FederateInterface* interface, Buffer* buffer);
            
            //## operation getBuffer() 
            Buffer* getBuffer();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
        
        
        ////    Framework operations    ////
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateMessage.h
*********************************************************************/

