/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::IO_Handler
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\IO_Handler.h
*********************************************************************/


#ifndef IO_Handler_H 

#define IO_Handler_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// operation callInputFunc(MessageType,unsigned int) 
#include "Framework.h"

//----------------------------------------------------------------------------
// IO_Handler.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
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
        //## class IO_Handler 
        class IO_Handler  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            IO_Handler();
            
            //## auto_generated 
            virtual ~IO_Handler();
        
        
        ////    Operations    ////
        public :
            
            //## operation callInputFunc(MessageType,unsigned int) 
            virtual void callInputFunc(MessageType Type, unsigned int timeout);
            
            //## operation callOutputFunc(MessageType) 
            virtual void callOutputFunc(MessageType Type);
            
            //## operation getType(Buffer*) 
            virtual MessageType* getType(Buffer* buffer);
            
            //## operation recvMessage(FederateMessage*) 
            virtual void recvMessage(FederateMessage* message);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            PostOffice* getItsPostOffice() const;
            
            //## auto_generated 
            void setItsPostOffice(PostOffice* p_PostOffice);
            
            //## auto_generated 
            Control::Serializer* getItsSerializer() const;
            
            //## auto_generated 
            void setItsSerializer(Control::Serializer* p_Serializer);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsPostOffice(PostOffice* p_PostOffice);
            
            //## auto_generated 
            void _setItsPostOffice(PostOffice* p_PostOffice);
            
            //## auto_generated 
            void _clearItsPostOffice();
            
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
            
            PostOffice* itsPostOffice;		//## link itsPostOffice 
            
            
            Control::Serializer* itsSerializer;		//## link itsSerializer 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IO_Handler.h
*********************************************************************/

