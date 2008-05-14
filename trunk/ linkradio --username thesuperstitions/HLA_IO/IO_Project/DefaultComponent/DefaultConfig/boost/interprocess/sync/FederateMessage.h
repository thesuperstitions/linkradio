/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateMessage
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FederateMessage.h
*********************************************************************/


#ifndef boost_interprocess_sync_FederateMessage_H 

#define boost_interprocess_sync_FederateMessage_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "boost\interprocess\sync\IO.h"
// class FederateMessage 
#include "boost\interprocess\sync\Message.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\FederateMessage.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        class FederateInterface;
    }
    
}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class FederateMessage 
        class FederateMessage : public Message {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation FederateMessage(Framework::IO::FederateInterface*,const rti1516::ParameterHandleValueMap &) 
            FederateMessage(Framework::IO::FederateInterface* interface, const rti1516::ParameterHandleValueMap & parameters);
            
            //## operation FederateMessage(Framework::IO::FederateInterface *,char*,unsigned long) 
            FederateMessage(Framework::IO::FederateInterface * interface, char* message, unsigned long messageSizeInBytes);
            
            //## auto_generated 
            FederateMessage();
            
            //## auto_generated 
            ~FederateMessage();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateInterface* getFederateInterface() const;
            
            //## auto_generated 
            void setFederateInterface(FederateInterface* p_federateInterface);
        
        
        ////    Attributes    ////
        protected :
            
            FederateInterface* federateInterface;		//## attribute federateInterface 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FederateMessage.h
*********************************************************************/

