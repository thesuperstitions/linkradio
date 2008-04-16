/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::ProducerThread
//!	Generated Date	: Mon, 14, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\ProducerThread.cpp
*********************************************************************/

#include "ProducerThread.h"
#include "Sleep.h"

const static int MILLISECONDS_PER_SECOND=1000;
const static int NANOSECONDS_PER_MILLISECOND=1000*1000;

//----------------------------------------------------------------------------
// ProducerThread.cpp                                                                  
//----------------------------------------------------------------------------

//## class ProducerThread 

ProducerThread::ProducerThread(Queue* queue) 
{
  myQueue = queue;
  exitFlag = false;
}
        
ProducerThread::~ProducerThread() 
{
  exitFlag = true;
  stop();
}

struct MessageStruct
{
  unsigned long MsgNumber;
  unsigned char MsgBody[30];
};

void ProducerThread::start() 
{
  exitFlag = false;

  Thread::start();	
}

void ProducerThread::stop() 
{
  exitFlag = true;

  Thread::stop();	
}

        
void ProducerThread::threadOperation()
{
  MessageStruct* msg;
  unsigned long msgCount = 0;

  while(exitFlag == false)
  {
    msg = new MessageStruct;
    msg->MsgNumber = msgCount++;

    myQueue->addMessage((void*)msg);

    framework::utils::Sleep::sleep(1, 0);
  };
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ProducerThread.cpp
*********************************************************************/

