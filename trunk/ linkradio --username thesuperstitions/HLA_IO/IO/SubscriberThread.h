/*********************************************************************
	Login		: rosskw1
	Model Element	: SubscriberThread
  Generated Date	: Mon, 21, Apr 2008  
	File Path	: SubscriberThread.h
*********************************************************************/


#ifndef SubscriberThread_H 

#define SubscriberThread_H 

#include "Thread.h"
#include "InterprocessQueue.h"
#include "HlaCecFederate.h"

//----------------------------------------------------------------------------
// SubscriberThread.h                                                                  
//----------------------------------------------------------------------------


#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

//## class SubscriberThread 
class SubscriberThread  : public framework::utils::Thread
{
  ////    Constructors and destructors    ////
  public :       
    framework::utils::InterprocessQueue* myQueue;
    framework::Control::HlaCecFederate* hlaCecFederate;

    //## auto_generated 
    SubscriberThread(int unitNumber);
            
    //## auto_generated 
    ~SubscriberThread();

    virtual void start();
  	virtual void stop();

	  virtual void threadOperation();

    void LogMessage(char* Msg);

  protected:
    bool exitFlag;
};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\SubscriberThread.h
*********************************************************************/

