/*********************************************************************
	Login		: rosskw1
	Model Element	: ProducerThread
  Generated Date	: Mon, 21, Apr 2008  
	File Path	: ProducerThread.h
*********************************************************************/


#ifndef ProducerThread_H 

#define ProducerThread_H 

#include "Thread.h"
#include "InterprocessQueue.h"

//----------------------------------------------------------------------------
// ProducerThread.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

        //## class ProducerThread 
class ProducerThread  : public Thread
{             
  ////    Constructors and destructors    ////
  public :
    InterprocessQueue* myQueue;
            
    //## auto_generated 
    ProducerThread(void);
            
    //## auto_generated 
    ~ProducerThread();

	  virtual void threadOperation();

    virtual void start();
  	virtual void stop();
		void LogMessage(char* Msg);

  protected:
    bool exitFlag;
};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ProducerThread.h
*********************************************************************/

