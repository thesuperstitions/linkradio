/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::Thread
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Thread.h
*********************************************************************/


#ifndef boost_interprocess_sync_Thread_H 

#define boost_interprocess_sync_Thread_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "utils.h"
#include "boost/thread.hpp"
#include "boost/bind.hpp"

//----------------------------------------------------------------------------
// boost\interprocess\sync\Thread.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace utils {
        // / This class is a generic wrapper for threads.
        // / right now it does boost threads.
        //## class Thread 
        class Thread  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation Thread() 
            Thread();
            
            //## operation ~Thread() 
            virtual ~Thread();
        
        protected :
            
            //## operation Thread(const Thread &) 
            Thread(const Thread & arg1);
        
        
        ////    Operations    ////
        public :
            
            //## operation start() 
            void start();
            
            //## operation stop() 
            virtual void stop();
        
        protected :
            
            //## operation operator=(const Thread &) 
            Thread &  operator=(const Thread & arg1);
            
            //## operation sleep(unsigned int,unsigned int) 
            void sleep(unsigned int seconds, unsigned int nanoseconds = 0);
            
            // / This the actual operation that is started when a thread kicks off.
            // / It is started/called as soon as "start" is called.
            //## operation threadOperation() 
            virtual void threadOperation()=0;
            
            //## operation yield() 
            void yield();
        
        private :
            
            // we could move this to protected if we ever think of a need
            // for a subclass to have direct access to the thread.
            //## operation getThread() 
            inline boost::thread &  getThread() {
                //#[ operation getThread() 
                return *theThread;
                //#]
            }
            
            
            //## operation threadOper(Thread *) 
            static void threadOper(Thread * thisObject);
        
        
        ////    Attributes    ////
        protected :
            
            boost::thread* theThread;		//## attribute theThread 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\Thread.h
*********************************************************************/

