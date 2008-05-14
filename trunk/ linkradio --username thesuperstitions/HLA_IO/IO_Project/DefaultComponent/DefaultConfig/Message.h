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


namespace Framework {
    
    namespace IO {
        class Buffer;
    }
    
}


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
            
            //## operation Message(char*,unsigned long) 
            Message(char* message, unsigned long messageSizeInBytes);
            
            //## auto_generated 
            Message();
            
            //## auto_generated 
            ~Message();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            std::string getFederateInterfaceEnetAddress() const;
            
            //## auto_generated 
            void setFederateInterfaceEnetAddress(std::string p_federateInterfaceEnetAddress);
            
            //## auto_generated 
            unsigned long getInstanceNumber() const;
            
            //## auto_generated 
            void setInstanceNumber(unsigned long p_instanceNumber);
            
            //## auto_generated 
            static unsigned long getMessageCount();
            
            //## auto_generated 
            static void setMessageCount(unsigned long p_messageCount);
            
            //## auto_generated 
            Buffer* getItsBuffer() const;
            
            //## auto_generated 
            void setItsBuffer(Buffer* p_Buffer);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsBuffer(Buffer* p_Buffer);
            
            //## auto_generated 
            void _setItsBuffer(Buffer* p_Buffer);
            
            //## auto_generated 
            void _clearItsBuffer();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            std::string federateInterfaceEnetAddress;		//## attribute federateInterfaceEnetAddress 
            
            unsigned long instanceNumber;		//## attribute instanceNumber 
            
            static unsigned long messageCount;		//## attribute messageCount 
            
        
        ////    Relations and components    ////
        protected :
            
            Buffer* itsBuffer;		//## link itsBuffer 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Message.h
*********************************************************************/

