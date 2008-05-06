/********************************************************************
	Login		: rosskw1
	Model Element	: ProducerThread
	Generated Date	: Mon, 21, Apr 2008  
	File Path	: ProducerThread.cpp

  Description: This class is based upon the "Thread" class.  It
  generates messages that get queued for consumption by the 
  "consumerThread".

*********************************************************************/

#include "ProducerThread.h"

#include "Sleep.h"

static long msgCount = 0;

//#define MAX_MSG_COUNT 1048576

//----------------------------------------------------------------------------
// ProducerThread.cpp                                                                  
//----------------------------------------------------------------------------

//## class ProducerThread 

struct MessageStruct
{
  long          MsgNumber;
  unsigned char MsgBody[96];
};

ProducerThread::ProducerThread(void) 
{
  exitFlag = false;

  myQueue = new InterprocessQueue("MessageQueue", sizeof(MessageStruct), INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE);
}
        
ProducerThread::~ProducerThread() 
{
  exitFlag = true;
  stop();

  delete myQueue;
}

void ProducerThread::start() 
{
  exitFlag = false;
  this->Thread::join();

  Thread::start();	
}

void ProducerThread::stop() 
{
  exitFlag = true;

  Thread::stop();	
}

        
void ProducerThread::threadOperation()
{
  MessageStruct msg;
  char          s[300];
  unsigned int  slot = 0;
  bool          timeoutFlag = true; // This forces a "Queue Synchronization" operation.

//while(myQueue->SynchronizeQueueUsers() == false);

  while(exitFlag == false)
  {
    if (timeoutFlag == true)
    {// The "getMessage" call timed-out.  We didn't get a message within our timeout limit.
      // Go through the Queue synchonization procedure.  This mimics what might be done in
      // a tactical system where a computer goes down and the interface protocol tries to 
      // re-establish communications.
      sprintf(s, "Synching To Queue Partner\n");
      myQueue->LogMessage(s, msgCount);
      while(myQueue->SynchronizeQueueUsers() == false)
      {
        if (exitFlag == true)
          return;
      }      
      timeoutFlag = false;
    }

    msg.MsgNumber = msgCount++;
    if (myQueue->timedAddMessage((unsigned char*)&msg, sizeof(MessageStruct), 0, 500000) == false)
      timeoutFlag = true;
    //else
    //  framework::utils::Sleep::sleep(0, 250000000);
    //while(myQueue->timedAddMessage((unsigned char*)&msg, sizeof(MessageStruct), 0, 500000) == false);
    //framework::utils::Sleep::sleep(0, 500000000);
  };
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ProducerThread.cpp
*********************************************************************/

