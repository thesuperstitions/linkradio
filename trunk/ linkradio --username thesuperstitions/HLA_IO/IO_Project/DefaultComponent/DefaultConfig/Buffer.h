/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::Buffer
//!	Generated Date	: Wed, 14, May 2008  
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
        
        
        ////    Attributes    ////
        protected :
            
            char* byteArray;		//## attribute byteArray 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Buffer.h
*********************************************************************/

