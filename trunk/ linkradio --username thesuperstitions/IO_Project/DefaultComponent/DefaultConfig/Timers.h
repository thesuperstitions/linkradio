/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::Timers
//!	Generated Date	: Tue, 8, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\Timers.h
*********************************************************************/


#ifndef Timers_H 

#define Timers_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
// class Timers 
#include "Thread.h"

//----------------------------------------------------------------------------
// Timers.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateIO_Handler;
        
    } 
    
namespace utils {
    class Sleep;
}

}


//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace utils {
        //## class Timers 
        class Timers : public Thread {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation Timers(int,unsigned long,bool,bool) 
            Timers(int seconds = 0, unsigned long nanoseconds = 0, bool startImmediately = true, bool periodic = false);
            
            //## auto_generated 
            virtual ~Timers();
        
        
        ////    Operations    ////
        public :
            
            //## operation onTimerExpired() 
            virtual void onTimerExpired()=0;
            
            //## operation startPeriodicTimer() 
            virtual void startPeriodicTimer();
            
            //## operation stopPeriodicTimer() 
            virtual void stopPeriodicTimer();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            bool getIsPeriodic() const;
            
            //## auto_generated 
            void setIsPeriodic(bool p_isPeriodic);
            
            //## auto_generated 
            unsigned long getNanoseconds() const;
            
            //## auto_generated 
            void setNanoseconds(unsigned long p_nanoseconds);
            
            //## auto_generated 
            bool getPeriodicTimerActive() const;
            
            //## auto_generated 
            void setPeriodicTimerActive(bool p_periodicTimerActive);
            
            //## auto_generated 
            int getSeconds() const;
            
            //## auto_generated 
            void setSeconds(int p_seconds);
            
            //## auto_generated 
            IO::FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(IO::FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            IO::FederateIO_Handler* getItsFederateIO_Handler_1() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler_1(IO::FederateIO_Handler* p_FederateIO_Handler);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederateIO_Handler(IO::FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _setItsFederateIO_Handler(IO::FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _clearItsFederateIO_Handler();
            
            //## auto_generated 
            void __setItsFederateIO_Handler_1(IO::FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _setItsFederateIO_Handler_1(IO::FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _clearItsFederateIO_Handler_1();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            bool isPeriodic;		//## attribute isPeriodic 
            
            unsigned long nanoseconds;		//## attribute nanoseconds 
            
            bool periodicTimerActive;		//## attribute periodicTimerActive 
            
            int seconds;		//## attribute seconds 
            
        
        ////    Relations and components    ////
        protected :
            
            IO::FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
            
            IO::FederateIO_Handler* itsFederateIO_Handler_1;		//## link itsFederateIO_Handler_1 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Timers.h
*********************************************************************/

