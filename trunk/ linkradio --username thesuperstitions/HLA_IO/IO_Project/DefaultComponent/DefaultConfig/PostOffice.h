/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::PostOffice
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\PostOffice.h
*********************************************************************/


#ifndef PostOffice_H 

#define PostOffice_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
#include <oxf/omcollec.h>
// operation sendMessage(FrameworkMessage*) 
#include "Framework.h"

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
    class Message;
}

}


//## package Framework::IO 


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
            OMIterator<Message*> getItsMessage() const;
            
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
            
            
            OMCollection<Message*> itsMessage;		//## link itsMessage 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PostOffice.h
*********************************************************************/

