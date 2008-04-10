//*********************************************************************************  
//
//	File:				Framework::IO::FederateIO_Handler  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Thu, 14, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef FederateIO_Handler_H 

#define FederateIO_Handler_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"
#include <list>
#include <iterator>
// operation getType(Buffer*) 
#include "Framework.h"
// link itsFederateInterface 
#include "FederateInterface.h"
// link itsFederateMessage 
#include "FederateMessage.h"
// class FederateIO_Handler 
#include "IO_Handler.h"

//----------------------------------------------------------------------------
// FederateIO_Handler.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        
    } 
    
namespace Federate {
    class Federate;
    
} 

namespace IO {
    class PostOffice;
    
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
        //## class FederateIO_Handler 
        class FederateIO_Handler : public IO_Handler {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            FederateIO_Handler();
            
            //## auto_generated 
            ~FederateIO_Handler();
        
        
        ////    Operations    ////
        public :
            
            //## operation callInputFunc(T,unsigned int) 
            template <class T> inline void callInputFunc(T Type, unsigned int timeout) {
                //#[ operation callInputFunc(T,unsigned int) 
                //#]
            }
            
            
            //## operation callOutputFunc(T) 
            template <class T> inline void callOutputFunc(T Type) {
                //#[ operation callOutputFunc(T) 
                //#]
            }
            
            
            //## operation getInterfacename() 
            char* getInterfacename();
            
            //## operation getRawBuffer(Buffer*) 
            void getRawBuffer(Buffer* buffer);
            
            //## operation getType(Buffer*) 
            MessageType* getType(Buffer* buffer);
            
            //## operation receiveMessage(FederateMessage*) 
            void receiveMessage(FederateMessage* message);
            
            //## operation registerRawMesgCallback(void  (* )(char * , int) ) 
            void registerRawMesgCallback(void  (* callbackFunction)(char * , int));
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Federate::Federate* getItsFederate() const;
            
            //## auto_generated 
            void setItsFederate(Federate::Federate* p_Federate);
            
            //## auto_generated 
            std::list<FederateInterface*>::const_iterator getItsFederateInterface() const;
            
            //## auto_generated 
            std::list<FederateInterface*>::const_iterator getItsFederateInterfaceEnd() const;
            
            //## auto_generated 
            void addItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void removeItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void clearItsFederateInterface();
            
            //## auto_generated 
            std::list<FederateMessage*>::const_iterator getItsFederateMessage() const;
            
            //## auto_generated 
            std::list<FederateMessage*>::const_iterator getItsFederateMessageEnd() const;
            
            //## auto_generated 
            void addItsFederateMessage(FederateMessage* p_FederateMessage);
            
            //## auto_generated 
            void removeItsFederateMessage(FederateMessage* p_FederateMessage);
            
            //## auto_generated 
            void clearItsFederateMessage();
        
        
        ////    Framework operations    ////
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Federate::Federate* itsFederate;		//## link itsFederate 
            
            
            std::list<FederateInterface*> itsFederateInterface;		//## link itsFederateInterface 
            
            
            std::list<FederateMessage*> itsFederateMessage;		//## link itsFederateMessage 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.h
*********************************************************************/

