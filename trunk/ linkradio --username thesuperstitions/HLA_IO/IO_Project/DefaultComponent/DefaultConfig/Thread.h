/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::utils::Thread
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\Thread.h
*********************************************************************/


#ifndef Thread_H 

#define Thread_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"

//----------------------------------------------------------------------------
// Thread.h                                                                  
//----------------------------------------------------------------------------


namespace boost {
    class thread;
}


//## package ReverseEngineering::framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
    namespace utils {
        // *
        // * Generic wrapper for a thread class.  This is an abstract class;
        // * clients should subclass and implement threadOperation, which contains
        // * the code executed in the new thread.
        //## class Thread 
        class Thread  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation Thread() 
            Thread();
            
            //## operation ~Thread() 
            virtual ~Thread();
        
        protected :
            
            // *
            // * Unimplemented copy constructor to prevent this object from being copied.
            //## operation Thread(const framework::utils::Thread &) 
            Thread(const framework::utils::Thread & arg1);
        
        
        ////    Operations    ////
        public :
            
            // *
            // * Wait for this thread to finish running.  Note:  if thread is in infinite loop
            // * you may be waiting quite a long time.
            //## operation join() 
            void join();
            
            // *
            // * Starts a new thread and calls the pure virtual member function threadOperation
            // * as the thread entry point.
            // * Currently this creates a new boost::thread object.
            //## operation start() 
            void start();
            
            // *
            // * Stops the thread.  Virtual so that subclasses can add behavior.
            // * Current implementation deletes the boost thread object.
            //## operation stop() 
            virtual void stop();
        
        protected :
            
            // *
            // * Unimplemented copy constructor to prevent this object from being copied.
            //## operation operator=(const framework::utils::Thread &) 
            framework::utils::Thread &  operator=(const framework::utils::Thread & arg1);
            
            // *
            // * This the actual operation that is started when a thread kicks off.
            // * It is started/called as soon as "start" is called.
            //## operation threadOperation() 
            virtual void threadOperation()=0;
            
            // *
            // * Yields to allow other threads to run.
            //## operation yield() 
            void yield();
        
        private :
            
            // *
            // * Returns a refernce to the boost::thread object.
            // *
            // * we could move this to protected if we ever think of a need
            // * for a subclass to have direct access to the thread.
            //## operation getThread() 
            inline boost::thread &  getThread() {
                //#[ operation getThread() 
                return *theThread;
                //#]
            }
            
            
            // *
            // * The static operation used to kick off the thread.  Static function
            // * is used because of the way boost handles function pointers,
            // * but there might be way to make this a member and still work.
            //## operation threadOper(framework::utils::Thread *) 
            static void threadOper(framework::utils::Thread * thisObject);
        
        
        ////    Relations and components    ////
        private :
            
            // < Pointer to the actual thread object.
            boost::thread* theThread;		//## link theThread 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Thread.h
*********************************************************************/

