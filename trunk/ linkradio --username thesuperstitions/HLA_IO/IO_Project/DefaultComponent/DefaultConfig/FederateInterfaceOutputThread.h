/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterfaceOutputThread
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceOutputThread.h
*********************************************************************/


#ifndef FederateInterfaceOutputThread_H 

#define FederateInterfaceOutputThread_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// class FederateInterfaceOutputThread 
#include "Thread.h"

//----------------------------------------------------------------------------
// FederateInterfaceOutputThread.h                                                                  
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
        //## class FederateInterfaceOutputThread 
        class FederateInterfaceOutputThread : public utils::Thread {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            FederateInterfaceOutputThread();
            
            //## auto_generated 
            ~FederateInterfaceOutputThread();
        
        
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
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceOutputThread.h
*********************************************************************/

