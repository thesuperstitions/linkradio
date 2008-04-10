/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_Handler
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.h
*********************************************************************/


#ifndef FederateIO_Handler_H 

#define FederateIO_Handler_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
#include <oxf/omcollec.h>
// operation getType(Buffer*) 
#include "Framework.h"
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
    class FederateInterface;
    class FederateMessage;
    class PostOffice;
    
} 

namespace Control {
    class Serializer;
}

}


//## package Framework::IO 


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
            
            //## operation callInputFunc(unsigned int) 
            inline void callInputFunc(unsigned int timeout) {
                //#[ operation callInputFunc(unsigned int) 
                //#]
            }
            
            
            //## operation callOutputFunc() 
            inline void callOutputFunc() {
                //#[ operation callOutputFunc() 
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
            OMIterator<FederateInterface*> getItsFederateInterface() const;
            
            //## auto_generated 
            void addItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void removeItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void clearItsFederateInterface();
            
            //## auto_generated 
            OMIterator<FederateMessage*> getItsFederateMessage() const;
            
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
            
            
            OMCollection<FederateInterface*> itsFederateInterface;		//## link itsFederateInterface 
            
            
            OMCollection<FederateMessage*> itsFederateMessage;		//## link itsFederateMessage 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.h
*********************************************************************/

