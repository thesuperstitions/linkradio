/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::IO_Handler
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\IO_Handler.h
*********************************************************************/


#ifndef boost_interprocess_sync_IO_Handler_H 

#define boost_interprocess_sync_IO_Handler_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "boost\interprocess\sync\IO.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\IO_Handler.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateMessage;
        
    } 
    
namespace Control {
    class Serializer;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class IO_Handler 
        class IO_Handler  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            IO_Handler();
            
            //## auto_generated 
            virtual ~IO_Handler()=0;
        
        
        ////    Operations    ////
        public :
            
            //## operation recvMessage(int,unsigned long) 
            virtual FederateMessage* recvMessage(int seconds, unsigned long nanoseconds)=0;
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Control::Serializer* getItsSerializer() const;
            
            //## auto_generated 
            void setItsSerializer(Control::Serializer* p_Serializer);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsSerializer(Control::Serializer* p_Serializer);
            
            //## auto_generated 
            void _setItsSerializer(Control::Serializer* p_Serializer);
            
            //## auto_generated 
            void _clearItsSerializer();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Control::Serializer* itsSerializer;		//## link itsSerializer 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\IO_Handler.h
*********************************************************************/

