/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::Serializer
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\Serializer.h
*********************************************************************/


#ifndef Serializer_H 

#define Serializer_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Control.h"
// dependency IO 
#include "IO.h"

//----------------------------------------------------------------------------
// Serializer.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class IO_Handler;
    }
    
}


//## package Framework::Control 


namespace Framework {
    namespace Control {
        //## class Serializer 
        class Serializer  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            Serializer();
            
            //## auto_generated 
            ~Serializer();
        
        
        ////    Operations    ////
        public :
            
            //## operation deserialize(const Framework::IO::Buffer &) 
            inline void deserialize(const Framework::IO::Buffer & arg2) {
                //#[ operation deserialize(const Framework::IO::Buffer &) 
                //#]
            }
            
            
            //## operation serialize(const Framework::IO::Buffer &) 
            inline void serialize(const Framework::IO::Buffer & arg2) {
                //#[ operation serialize(const Framework::IO::Buffer &) 
                //#]
            }
            
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            IO::IO_Handler* getItsIO_Handler() const;
            
            //## auto_generated 
            void setItsIO_Handler(IO::IO_Handler* p_IO_Handler);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsIO_Handler(IO::IO_Handler* p_IO_Handler);
            
            //## auto_generated 
            void _setItsIO_Handler(IO::IO_Handler* p_IO_Handler);
            
            //## auto_generated 
            void _clearItsIO_Handler();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            IO::IO_Handler* itsIO_Handler;		//## link itsIO_Handler 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Serializer.h
*********************************************************************/

