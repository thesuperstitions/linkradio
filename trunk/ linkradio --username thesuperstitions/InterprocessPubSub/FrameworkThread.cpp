/********************************************************************
	Login		: rosskw1
	Model Element	: FrameworkThread
	Generated Date	: Mon, 21, Apr 2008

	Description: This class is based upon the "Thread" class.  It reads
	messages from a Queue, one at a time, and checks to make sure that
	the messages are received in sequence.
*********************************************************************/

#include "FrameworkThread.h"
//----------------------------------------------------------------------------
// FrameworkThread.cpp
//----------------------------------------------------------------------------



FrameworkThread::FrameworkThread(int unitNumber)
{
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

