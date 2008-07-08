/*********************************************************************
	Login		: rosskw1
	Model Element	: FrameworkThread
	Generated Date	: Mon, 21, Apr 2008  
	File Path	: FrameworkThread.h
*********************************************************************/


#ifndef FrameworkThread_H 

#define FrameworkThread_H 

#include "HlaCecFederate.h"
#include "InterprocessQueue.h"
#include "Thread.h"
//----------------------------------------------------------------------------
// FrameworkThread.h                                                                  
//----------------------------------------------------------------------------


#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

//## class FrameworkThread 
class FrameworkThread  : public framework::utils::Thread
{
	////    Constructors and destructors    ////
	public :       
//    framework::utils::InterprocessQueue* myQueue;
	framework::Control::HlaCecFederate* hlaCecFederate;

	//## auto_generated 
	FrameworkThread(int unitNumber);

	//## auto_generated 
	~FrameworkThread();

	// virtual void start();
	//virtual void stop();

	  virtual void threadOperation();

	// void LogMessage(char* Msg, double count);

	protected:
	bool exitFlag;
};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkThread.h
*********************************************************************/

