/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterfaceInputThread
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceInputThread.h
*********************************************************************/


#ifndef FederateInterfaceInputThread_H 

#define FederateInterfaceInputThread_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// class FederateInterfaceInputThread 
#include "Thread.h"

//----------------------------------------------------------------------------
// FederateInterfaceInputThread.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateInterface;
        
    } 
    
} 
class InterprocessQueue;

//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class FederateInterfaceInputThread 
        class FederateInterfaceInputThread : public utils::Thread {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            FederateInterfaceInputThread();
            
            //## auto_generated 
            ~FederateInterfaceInputThread();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateInterface* getItsFederateInterface() const;
            
            //## auto_generated 
            void setItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            InterprocessQueue* getItsInterprocessQueue() const;
            
            //## auto_generated 
            void setItsInterprocessQueue(InterprocessQueue* p_InterprocessQueue);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void _setItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void _clearItsFederateInterface();
            
            //## auto_generated 
            void __setItsInterprocessQueue(InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            void _setItsInterprocessQueue(InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            void _clearItsInterprocessQueue();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            FederateInterface* itsFederateInterface;		//## link itsFederateInterface 
            
            
            InterprocessQueue* itsInterprocessQueue;		//## link itsInterprocessQueue 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceInputThread.h
*********************************************************************/

