/********************************************************************
	Login		: rosskw1
	Model Element	: PublisherThread
	Generated Date	: Mon, 21, Apr 2008
	File Path	: PublisherThread.cpp

  Description: This class is based upon the "Thread" class.  It
  generates messages that get queued for consumption by the
  "consumerThread".

*********************************************************************/

#include "PublisherThread.h"

#include "Sleep.h"
#include <sys/timeb.h>
#include <string.h>


#define BUFFER_SIZE 4096


//----------------------------------------------------------------------------
// PublisherThread.cpp
//----------------------------------------------------------------------------

//## class PublisherThread

struct MessageStruct
{
  unsigned char       UnitNumber;
  long                MsgNumber;
  unsigned char       MsgBody[96];
};

PublisherThread::PublisherThread(int unitNumber, char* IP) : SocketClient(IP)
{
  //char s[200];
  exitFlag = false;
  myUnitNumber = unitNumber;
  strcpy(myIP, IP);
}

PublisherThread::~PublisherThread()
{
  stop();
}

void PublisherThread::start()
{
  exitFlag = false;

  Thread::start();
}

void PublisherThread::stop()
{
  exitFlag = true;

  printf("\nPublisherThread::stop - Attempting to Join Thread.\n");
  this->Thread::join();

  printf("\nPublisherThread::stop - Stopping Thread.\n");
  Thread::stop();
  printf("\nPublisherThread::stop - Thread Stop Complete.\n");
}

void PublisherThread::threadOperation()
{
  char          s[500];
  MessageStruct msg;
  unsigned int  slot = 0;

  msg.MsgNumber = 0;
  msg.UnitNumber = myUnitNumber;

  while(exitFlag == false)
  {
    msg.MsgNumber++;

    this->SendBytes((char*)(&msg), sizeof(msg));

    sprintf(s, "PublisherThread::threadOps-Send-   Unit=%u, Msg=%u", msg.UnitNumber, msg.MsgNumber);
    this->LogData(s);


    //MessageStruct dataBuffer;
    //unsigned int BytesReceived;
    //BytesReceived = this->ReceiveBytes((char*)&dataBuffer, sizeof(dataBuffer));
    //
    //sprintf(s, "PubThread::ClientConnected-Receive-Unit=%u, Msg=%u", dataBuffer.UnitNumber, dataBuffer.MsgNumber);
    //this->LogData(s);

    framework::utils::Sleep::sleep(0, 500000000);
  }
  
  sprintf (s, "\nPublisherThread::threadOperation - Exiting Thread\n");
}

void PublisherThread::ClientSocketConnected(Socket* ClientSocket)
{
  char s[500];
  MessageStruct dataBuffer;
  unsigned int BytesReceived;

  mySocket = ClientSocket;

  sprintf(s, "PublisherThread::ClientSocketConnected - Connected to server on %s", ClientHostString);
  this->LogData(s);

  this->start();

  while(exitFlag == false)
  {
    BytesReceived = this->ReceiveBytes((char*)&dataBuffer, sizeof(dataBuffer));
    
    sprintf(s, "PubThread::ClientConnected-Receive-Unit=%u, Msg=%u", dataBuffer.UnitNumber, dataBuffer.MsgNumber);
    this->LogData(s);
  }
}






        void PublisherThread::LogData(char* Str)
        {
          struct timeb  t;
          int           Hours, Mins, Secs;

          ftime(&t);
          Secs = t.time % 86400; // 86400 = Seconds/24 hours
          Hours = Secs / 3600;
          Secs -= Hours * 3600;
          Mins = Secs / 60;
          Secs -= Mins * 60;

          //TS = gmtime( &tt );
          printf("\n%02u:%02u:%02u.%03u : %s", Hours, Mins, Secs, t.millitm, Str);
        }


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PublisherThread.cpp
*********************************************************************/

