/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::Serializer
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Serializer.h
*********************************************************************/


#ifndef boost_interprocess_sync_Serializer_H 

#define boost_interprocess_sync_Serializer_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "boost\interprocess\sync\Control.h"
// dependency IO 
#include "boost\interprocess\sync\IO.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\Serializer.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class IO_Handler;
    }
    
}


//## package Framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

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
            inline void deserialize(const Framework::IO::Buffer & buffer) {
                //#[ operation deserialize(const Framework::IO::Buffer &) 
                //#]
            }
            
            
            //## operation serialize(const Framework::IO::Buffer &) 
            inline void serialize(const Framework::IO::Buffer & buffer) {
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
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Serializer.h
*********************************************************************/

