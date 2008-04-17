/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_OutputThread
//!	Generated Date	: Wed, 16, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_OutputThread.h
*********************************************************************/


#ifndef FederateIO_OutputThread_H 

#define FederateIO_OutputThread_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
#include <vector>
#include <iterator>
// link itsFederateMessage 
#include "FederateMessage.h"
// class FederateIO_OutputThread 
#include "Thread.h"
#include "boost/thread/mutex.hpp"

//----------------------------------------------------------------------------
// FederateIO_OutputThread.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class Federate;
        
    } 
    
namespace IO {
    class FederateIO_Handler;
    class PostOffice;
    
} 

namespace utils {
    class Sleep;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class FederateIO_OutputThread 
        class FederateIO_OutputThread : public utils::Thread {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            FederateIO_OutputThread();
            
            //## auto_generated 
            virtual ~FederateIO_OutputThread();
        
        
        ////    Operations    ////
        public :
            
            //## operation addFederateMessage(FederateMessage*) 
            virtual void addFederateMessage(FederateMessage* message);
            
            //## operation threadOperation() 
            virtual void threadOperation();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            std::vector<FederateMessage*>::const_iterator getItsFederateMessage() const;
            
            //## auto_generated 
            std::vector<FederateMessage*>::const_iterator getItsFederateMessageEnd() const;
            
            //## auto_generated 
            void addItsFederateMessage(FederateMessage* p_FederateMessage);
            
            //## auto_generated 
            void removeItsFederateMessage(FederateMessage* p_FederateMessage);
            
            //## auto_generated 
            void clearItsFederateMessage();
        
        
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
            
            boost::mutex myMutex;		//## attribute myMutex 
            
        
        ////    Relations and components    ////
        protected :
            
            FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
            
            std::vector<FederateMessage*> itsFederateMessage;		//## link itsFederateMessage 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_OutputThread.h
*********************************************************************/

