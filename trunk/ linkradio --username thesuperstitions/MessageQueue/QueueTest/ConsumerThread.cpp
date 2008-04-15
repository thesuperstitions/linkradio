/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::ConsumerThread
//!	Generated Date	: Mon, 14, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\ConsumerThread.cpp
*********************************************************************/

#include "ConsumerThread.h"

const static int MILLISECONDS_PER_SECOND=1000;
const static int NANOSECONDS_PER_MILLISECOND=1000*1000;

//----------------------------------------------------------------------------
// ConsumerThread.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

//## class ConsumerThread 

        
ConsumerThread::ConsumerThread(Queue* queue)
{
  myQueue = queue;
  exitFlag = false;
}
        
ConsumerThread::~ConsumerThread() 
{
  exitFlag = true;
  stop();
}

struct MessageStruct
{
  unsigned long MsgNumber;
  unsigned char MsgBody[30];
};

void ConsumerThread::stop() 
{
  exitFlag = true;

  Thread::stop();	
}
        
void ConsumerThread::threadOperation()
{
  MessageStruct* msg;
  unsigned long msgCount = 0;

  while(exitFlag == false)
  {
    msg = (MessageStruct*)myQueue->getMessage(0, 500);
    if (msg != NULL)
    {
      msgCount = msg->MsgNumber;

      delete msg;
    }
  };
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ConsumerThread.cpp
*********************************************************************/

