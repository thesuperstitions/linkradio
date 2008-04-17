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

//----------------------------------------------------------------------------
// ConsumerThread.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

//## class ConsumerThread 

struct MessageStruct
{
  unsigned long MsgNumber;
  unsigned char MsgBody[30];
};

        
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

void ConsumerThread::start() 
{
  exitFlag = false;

  Thread::start();	
}

void ConsumerThread::stop() 
{
  exitFlag = true;

  Thread::stop();	
}
        
void ConsumerThread::threadOperation()
{
  QString s;
  MessageStruct* msg;
  unsigned long msgCount = 0;

  while(exitFlag == false)
  {
    msg = (MessageStruct*)myQueue->getMessage(0, 100);
    if (msg != NULL)
    {
      msgCount = msg->MsgNumber;
      if ((msgCount % 1000000) == 0)
        myQueue->LogMessage(s.sprintf("ConsumerThread::threadOperation - MsgNumber=%u", msg->MsgNumber));

      delete msg;
    }
  };
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ConsumerThread.cpp
*********************************************************************/

