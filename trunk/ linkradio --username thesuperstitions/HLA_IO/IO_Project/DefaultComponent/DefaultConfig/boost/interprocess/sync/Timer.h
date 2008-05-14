/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::Timer
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Timer.h
*********************************************************************/


#ifndef boost_interprocess_sync_Timer_H 

#define boost_interprocess_sync_Timer_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "utils.h"
// class Timer 
#include "boost\interprocess\sync\Thread.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\Timer.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
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
        //## class Timer 
        class Timer : public Thread {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation Timer(int,unsigned long,bool,bool) 
            Timer(int seconds = 0, unsigned long nanoseconds = 0, bool startImmediately = false, bool periodic = false);
            
            //## auto_generated 
            virtual ~Timer();
        
        
        ////    Operations    ////
        public :
            
            //## operation onTimerExpired() 
            virtual void onTimerExpired()=0;
            
            //## operation startOneShotTimer(int,unsigned long) 
            void startOneShotTimer(int seconds, unsigned long nanoseconds);
            
            //## operation startPeriodicTimer(int,unsigned long) 
            virtual void startPeriodicTimer(int seconds, unsigned long nanoseconds);
            
            //## operation stopPeriodicTimer() 
            virtual void stopPeriodicTimer();
            
            //## operation threadOperation() 
            void threadOperation();
        
        
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
            int getSeconds() const;
            
            //## auto_generated 
            void setSeconds(int p_seconds);
            
            //## auto_generated 
            bool getTimerActive() const;
            
            //## auto_generated 
            void setTimerActive(bool p_timerActive);
        
        
        ////    Attributes    ////
        protected :
            
            bool isPeriodic;		//## attribute isPeriodic 
            
            unsigned long nanoseconds;		//## attribute nanoseconds 
            
            int seconds;		//## attribute seconds 
            
            bool timerActive;		//## attribute timerActive 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Timer.h
*********************************************************************/

