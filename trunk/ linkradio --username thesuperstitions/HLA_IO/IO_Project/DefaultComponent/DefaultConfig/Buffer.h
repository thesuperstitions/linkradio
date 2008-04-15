/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Buffer
//!	Generated Date	: Mon, 14, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\Buffer.h
*********************************************************************/


#ifndef Buffer_H 

#define Buffer_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"

//----------------------------------------------------------------------------
// Buffer.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Message;
    }
    
}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class Buffer 
        class Buffer  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation Buffer(char*,unsigned long) 
            Buffer(char* byteArray, unsigned long sizeOfByteArray);
            
            //## auto_generated 
            Buffer();
            
            //## operation ~Buffer() 
            ~Buffer();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            char* getByteArray() const;
            
            //## auto_generated 
            void setByteArray(char* p_byteArray);
            
            //## auto_generated 
            unsigned long getSizeOfByteArray() const;
            
            //## auto_generated 
            void setSizeOfByteArray(unsigned long p_sizeOfByteArray);
            
            //## auto_generated 
            Message* getItsMessage() const;
            
            //## auto_generated 
            void setItsMessage(Message* p_Message);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsMessage(Message* p_Message);
            
            //## auto_generated 
            void _setItsMessage(Message* p_Message);
            
            //## auto_generated 
            void _clearItsMessage();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            char* byteArray;		//## attribute byteArray 
            
            unsigned long sizeOfByteArray;		//## attribute sizeOfByteArray 
            
        
        ////    Relations and components    ////
        protected :
            
            Message* itsMessage;		//## link itsMessage 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Buffer.h
*********************************************************************/

