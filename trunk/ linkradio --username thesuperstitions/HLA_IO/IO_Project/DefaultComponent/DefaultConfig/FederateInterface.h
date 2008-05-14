/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterface
//!	Generated Date	: Wed, 14, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/


#ifndef FederateInterface_H 

#define FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// class FederateInterface 
#include "Thread.h"

//----------------------------------------------------------------------------
// FederateInterface.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateIO_Handler;
        class FederateMessage;
        
    } 
    
namespace utils {
    class InterprocessQueue;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class FederateInterface 
        class FederateInterface : public utils::Thread {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation FederateInterface(std::string,unsigned long,unsigned long) 
            FederateInterface(std::string name, unsigned long maxMessageSize, unsigned long maxMessages);
            
            //## operation ~FederateInterface() 
            ~FederateInterface();
        
        
        ////    Operations    ////
        public :
            
            //## operation processFederateMessage(FederateMessage*) 
            virtual bool processFederateMessage(FederateMessage* message);
            
            //## operation threadOperation() 
            void threadOperation();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            bool getExitFlag() const;
            
            //## auto_generated 
            void setExitFlag(bool p_exitFlag);
            
            //## auto_generated 
            std::string getInterfaceName() const;
            
            //## auto_generated 
            void setInterfaceName(std::string p_interfaceName);
            
            //## auto_generated 
            unsigned long getMaxMessageSize() const;
            
            //## auto_generated 
            void setMaxMessageSize(unsigned long p_maxMessageSize);
            
            //## auto_generated 
            unsigned long getMaxMessages() const;
            
            //## auto_generated 
            void setMaxMessages(unsigned long p_maxMessages);
            
            //## auto_generated 
            utils::InterprocessQueue* getInputQueue() const;
            
            //## auto_generated 
            void setInputQueue(utils::InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            utils::InterprocessQueue* getOutputQueue() const;
            
            //## auto_generated 
            void setOutputQueue(utils::InterprocessQueue* p_InterprocessQueue);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _clearItsFederateIO_Handler();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            bool exitFlag;		//## attribute exitFlag 
            
            std::string interfaceName;		//## attribute interfaceName 
            
            unsigned long maxMessageSize;		//## attribute maxMessageSize 
            
            unsigned long maxMessages;		//## attribute maxMessages 
            
        
        ////    Relations and components    ////
        protected :
            
            utils::InterprocessQueue* inputQueue;		//## link inputQueue 
            
            
            FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
            
            utils::InterprocessQueue* outputQueue;		//## link outputQueue 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/

