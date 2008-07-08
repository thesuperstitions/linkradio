/*********************************************************************
	Login		: rosskw1
	Model Element	: PublisherThread
	Generated Date	: Mon, 21, Apr 2008  
	File Path	: PublisherThread.h
*********************************************************************/


#ifndef PublisherThread_H 

#define PublisherThread_H 

#include "InterprocessQueue.h"
#include "Thread.h"
//----------------------------------------------------------------------------
// PublisherThread.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

		//## class PublisherThread 
class PublisherThread  : public framework::utils::Thread
{             
	////    Constructors and destructors    ////
	public :
	framework::utils::InterprocessQueue* myQueue;

	//## auto_generated 
	PublisherThread(int unitNumber);

	//## auto_generated 
	~PublisherThread();

	  virtual void threadOperation();

	virtual void start();
	virtual void stop();
		void LogMessage(char* Msg);

	protected:
	bool exitFlag;
};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PublisherThread.h
*********************************************************************/

