/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Message
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\Message.h
*********************************************************************/


#ifndef Message_H 

#define Message_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// link itsBuffer 
#include "Buffer.h"

//----------------------------------------------------------------------------
// Message.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 


namespace Framework {
    namespace IO {
        //## class Message 
        class Message  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            Message();
            
            //## auto_generated 
            ~Message();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Buffer* getItsBuffer() const;
        
        
        ////    Framework operations    ////
        protected :
            
            //## auto_generated 
            void initRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Buffer itsBuffer;		//## link itsBuffer 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Message.h
*********************************************************************/

