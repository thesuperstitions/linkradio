/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::Thread
//!	Generated Date	: Thu, 3, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\Thread.cpp
*********************************************************************/

#include "Thread.h"

//----------------------------------------------------------------------------
// Thread.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

//## class Thread 

namespace Framework {
    namespace utils {
        
        
        Thread::Thread() : theThread(0)  {
            //#[ operation Thread() 
            //#]
        }
        
        Thread::~Thread() {
            //#[ operation ~Thread() 
            
                stop();
            
            //#]
        }
        
        void Thread::sleep(unsigned int seconds, unsigned int nanoseconds) {
            //#[ operation sleep(unsigned int,unsigned int) 
            
            boost::xtime time;
            
            xtime_get(&time,boost::TIME_UTC);
            time.sec += seconds;
            time.nsec += nanoseconds;
            theThread->sleep(time);
            
            //#]
        }
        
        void Thread::start() {
            //#[ operation start() 
            
                if (this->theThread) {
                
                    std::cout<<"Tried to start a new thread when one is already running"
                    <<std::endl;
                    
                
                }
            
               //boost::function0<void> fun(boost::bind(&(TestThread::memberThread),*this));
               boost::function0<void> fun( boost::bind( &(Thread::threadOper), this )  );
               this->theThread = new boost::thread(fun);
            
            //#]
        }
        
        void Thread::stop() {
            //#[ operation stop() 
            
                delete theThread;
                theThread=0;
                
            //#]
        }
        
        void Thread::threadOper(Thread * thisObject) {
            //#[ operation threadOper(Thread *) 
            
                thisObject->threadOperation();
            //#]
        }
        
        void Thread::yield() {
            //#[ operation yield() 
            
                theThread->yield();
                
            //#]
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Thread.cpp
*********************************************************************/

