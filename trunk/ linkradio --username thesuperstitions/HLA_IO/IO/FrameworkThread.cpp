/********************************************************************
	Login		: rosskw1
	Model Element	: FrameworkThread
  Generated Date	: Mon, 21, Apr 2008

  Description: This class is based upon the "Thread" class.  It reads
  messages from a Queue, one at a time, and checks to make sure that
  the messages are received in sequence.
*********************************************************************/

#include "FrameworkThread.h"
//#include <stdio.h>
//#include <time.h>
//#include <sys/timeb.h>
//#include "Sleep.h"

//----------------------------------------------------------------------------
// FrameworkThread.cpp
//----------------------------------------------------------------------------



FrameworkThread::FrameworkThread(int unitNumber)
{
  // create the framework and FrameworkFederateAmbassador
  framework::initializeFramework();

  // Create an example Federate
  hlaCecFederate = new framework::Control::HlaCecFederate(unitNumber);
}

FrameworkThread::~FrameworkThread()
{
  delete hlaCecFederate;
  hlaCecFederate = NULL;

  framework::finalizeFramework();
}

void FrameworkThread::threadOperation()
{
}

/*********************************************************************
	FrameworkThread.cpp
*********************************************************************/

