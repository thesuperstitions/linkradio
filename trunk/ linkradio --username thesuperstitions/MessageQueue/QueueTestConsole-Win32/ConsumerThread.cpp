/********************************************************************
	Login		: rosskw1
	Model Element	: ConsumerThread
  Generated Date	: Mon, 21, Apr 2008  

  Description: This class is based upon the "Thread" class.  It reads
  messages from a Queue, one at a time, and checks to make sure that
  the messages are received in sequence.
*********************************************************************/

#include "ConsumerThread.h"
#include <stdio.h>
#include <time.h>
#include <sys\timeb.h>

#include "Sleep.h"

//----------------------------------------------------------------------------
// ConsumerThread.cpp                                                                  
//----------------------------------------------------------------------------

struct MessageStruct
{
  long MsgNumber;
  unsigned char MsgBody[96];
};


static struct timeb previousTime;

        
ConsumerThread::ConsumerThread(void)
{
  exitFlag = false;
  previousTime.time = 0;
  previousTime.millitm = 0;

  myQueue = new InterprocessQueue("MessageQueue", sizeof(MessageStruct), INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE);
}
        
ConsumerThread::~ConsumerThread() 
{
//  delete myQueue;

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

  this->Thread::join();

  Thread::stop();	
}
        
void ConsumerThread::threadOperation()
{
  char           s[500];
  MessageStruct  gmsg;
  bool           timeoutFlag = true; // This forces a "Queue Synchronization" operation.
  //bool           result;
  //MessageStruct* msg;
  long  msgCount = 0;
  long  prevMsgCount = -1;

//while(myQueue->SynchronizeQueueUsers() == false);

  while(exitFlag == false)
  {
    if (timeoutFlag == true)
    {
      // The "getMessage" call timed-out.  We didn't get a message within our timeout limit.
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

    if (myQueue->timedGetMessage((unsigned char*)&gmsg, 0, 500000) == true)
    {
      msgCount = gmsg.MsgNumber;

      if (msgCount != (prevMsgCount+1))
      {
        sprintf(s, "PROBLEM!!! - MsgNumber=%u, PrevMsgNum=%u\n", msgCount, prevMsgCount);
        myQueue->LogMessage(s, msgCount);
      }

      if ((msgCount % 10000000) == 0)
      {
        sprintf(s, "Msg Number=%u\n\n", msgCount);
        myQueue->LogMessage(s, msgCount);
      }
      prevMsgCount = msgCount;
    }
    else
    {
      sprintf(s, "TIMEOUT\n\n");
      myQueue->LogMessage(s, msgCount);
      timeoutFlag = true;
    }
  };
}



        //void ConsumerThread::LogMessage(char* Msg, double count)
        //{
        //  struct timeb  t;
        //  int           Hours, Mins, Secs;
        //  double        deltaTime, iterationsPerSecond, secs, milliSecs;

        //  ftime(&t);
        //  Secs = t.time % 86400; // 86400 = Seconds/24 hours
        //  Hours = Secs / 3600;
        //  Secs -= Hours * 3600;
        //  Mins = Secs / 60;
        //  Secs -= Mins * 60;

        //  if (previousTime.time == 0)
        //  {
        //    previousTime = t;
        //    deltaTime = 0.0;
        //    iterationsPerSecond = 0.0;
        //  }
        //  else
        //  {
        //    secs = (t.time - previousTime.time);
        //    secs *= 1000.0;
        //    milliSecs = (t.millitm - previousTime.millitm);
        //    secs += milliSecs;
        //    deltaTime = secs / 1000.0;
        //    iterationsPerSecond = count / deltaTime;
        //  }
  
        //  //TS = gmtime( &tt );
        //  printf("%02u:%02u:%02u.%03u-DT=%7.3f S, Iter/Sec=%10.3f : %s", Hours, Mins, Secs, t.millitm, deltaTime, iterationsPerSecond, Msg);
        //}
/*********************************************************************
	ConsumerThread.cpp
*********************************************************************/

