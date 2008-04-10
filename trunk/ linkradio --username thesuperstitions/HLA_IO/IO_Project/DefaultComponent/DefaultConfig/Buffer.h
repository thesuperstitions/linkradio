/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Buffer
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\Buffer.h
*********************************************************************/


#ifndef Buffer_H 

#define Buffer_H 

#include <oxf/oxf.h>
#include <string>
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


namespace Framework {
    namespace IO {
        //## class Buffer 
        class Buffer  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            Buffer();
            
            //## auto_generated 
            ~Buffer();
        
        
        ////    Additional operations    ////
        public :
            
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

