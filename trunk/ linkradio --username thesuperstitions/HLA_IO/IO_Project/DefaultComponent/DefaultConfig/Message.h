/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Message
//!	Generated Date	: Wed, 14, May 2008  
	File Path	: DefaultComponent\DefaultConfig\Message.h
*********************************************************************/


#ifndef Message_H 

#define Message_H 

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
// Message.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class Message 
        class Message  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation Message(unsigned char*,unsigned long) 
            Message(unsigned char* message, unsigned long messageSizeInBytes);
            
            //## auto_generated 
            Message();
            
            //## auto_generated 
            ~Message();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            static unsigned long getMessageCount();
            
            //## auto_generated 
            static void setMessageCount(unsigned long p_messageCount);
            
            //## auto_generated 
            unsigned char* getMessagePtr() const;
            
            //## auto_generated 
            void setMessagePtr(unsigned char* p_messagePtr);
            
            //## auto_generated 
            unsigned long getSizeOfMessageInBytes() const;
            
            //## auto_generated 
            void setSizeOfMessageInBytes(unsigned long p_sizeOfMessageInBytes);
        
        
        ////    Attributes    ////
        protected :
            
            static unsigned long messageCount;		//## attribute messageCount 
            
            unsigned char* messagePtr;		//## attribute messagePtr 
            
            unsigned long sizeOfMessageInBytes;		//## attribute sizeOfMessageInBytes 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Message.h
*********************************************************************/

