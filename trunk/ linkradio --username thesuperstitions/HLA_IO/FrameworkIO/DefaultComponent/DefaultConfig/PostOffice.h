//*********************************************************************************  
//
//	File:				Framework::IO::PostOffice  
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



#ifndef PostOffice_H 

#define PostOffice_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"
#include <list>
#include <iterator>
// operation sendMessage(FrameworkMessage*) 
#include "Framework.h"
// link itsMessage 
#include "Message.h"

//----------------------------------------------------------------------------
// PostOffice.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        
    } 
    
namespace Federate {
    class Federate;
    
} 

namespace IO {
    class FederateInterface;
    class FederateMessage;
    class IO_Handler;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class PostOffice 
        class PostOffice  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            PostOffice();
            
            //## auto_generated 
            virtual ~PostOffice();
        
        
        ////    Operations    ////
        public :
            
            //## operation announcePublication(FederateInterface*) 
            virtual void announcePublication(FederateInterface* interface);
            
            //## operation announceSubscription(FederateInterface*) 
            virtual void announceSubscription(FederateInterface* interface);
            
            //## operation findFederateInterface() 
            FederateInterface* findFederateInterface();
            
            //## operation receiveMessage(Buffer*,int) 
            virtual void receiveMessage(Buffer* buffer, int theInteraction);
            
            //## operation sendMessage(FederateMessage*) 
            virtual void sendMessage(FederateMessage* message);
            
            //## operation sendMessage(FrameworkMessage*) 
            virtual void sendMessage(FrameworkMessage* message);
            
            //## operation unsubscribe(FederateInterface*) 
            virtual void unsubscribe(FederateInterface* interface);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Federate::Federate* getItsFederate() const;
            
            //## auto_generated 
            void setItsFederate(Federate::Federate* p_Federate);
            
            //## auto_generated 
            int getItsIO_Handler() const;
            
            //## auto_generated 
            void addItsIO_Handler(IO_Handler* p_IO_Handler);
            
            //## auto_generated 
            void removeItsIO_Handler(IO_Handler* p_IO_Handler);
            
            //## auto_generated 
            void clearItsIO_Handler();
            
            //## auto_generated 
            std::list<Message*>::const_iterator getItsMessage() const;
            
            //## auto_generated 
            std::list<Message*>::const_iterator getItsMessageEnd() const;
            
            //## auto_generated 
            void addItsMessage(Message* p_Message);
            
            //## auto_generated 
            void removeItsMessage(Message* p_Message);
            
            //## auto_generated 
            void clearItsMessage();
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederate(Federate::Federate* p_Federate);
            
            //## auto_generated 
            void _setItsFederate(Federate::Federate* p_Federate);
            
            //## auto_generated 
            void _clearItsFederate();
            
            //## auto_generated 
            void _addItsIO_Handler(IO_Handler* p_IO_Handler);
            
            //## auto_generated 
            void _removeItsIO_Handler(IO_Handler* p_IO_Handler);
            
            //## auto_generated 
            void _clearItsIO_Handler();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Federate::Federate* itsFederate;		//## link itsFederate 
            
            
            IO_Handler* itsIO_Handler[2];		//## link itsIO_Handler 
            
            
            std::list<Message*> itsMessage;		//## link itsMessage 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PostOffice.h
*********************************************************************/

