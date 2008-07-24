/********************************************************************
	Login		: rosskw1
	Model Element	: PublisherThread
	Generated Date	: Mon, 21, Apr 2008
	File Path	: PublisherThread.cpp

  Description: this class is based upon the "Thread" class.  It
  generates messages that get queued for consumption by the
  "consumerThread".

*********************************************************************/

#include "PublisherThread.h"

#include "Sleep.h"
#include <sys/timeb.h>
#include <string.h>
#include "FileReader.h"


#define FILE_TO_READ "LNE_DX_024_5min"

//---------------------------------------------------------------------------

#define NETWORK_HEADER_SIZE  (int)sizeof(networkHeader_t)
#define PACKET_HEADER_SIZE   (int)sizeof(packetHeader_t)
#define BUFFER_SIZE 4096

//struct MessageStruct
//{
//  unsigned char       UnitNumber;
//  long                MsgNumber;
//  unsigned char       MsgBody[96];
//};

struct DataHeader
{
  unsigned STN;
  unsigned NumberOfBytesInMessage;
};



    ReaderThread::ReaderThread(Socket* SC) : mySocket(SC), exitFlag(false) 
    {
    };

    ReaderThread::~ReaderThread(void) 
    {
      stop();
    }

    void ReaderThread::start()
    {
     exitFlag = false;
     Thread::start();
    }



    void ReaderThread::stop()
    {
      exitFlag = true;
  
      printf ("\nReaderThread::stop - Closing Socket\n");
      mySocket->Close();

      printf("\nReaderThread::stop - Attempting to Join Thread.\n");
      this->Thread::join();

      printf("\nReaderThread::stop - Stopping Thread.\n");
      Thread::stop();
      printf("\nReaderThread::stop - Thread Stop Complete.\n");
    }

 /*   void ReaderThread::threadOperation()
    {
      char          s[500];

      while(exitFlag == false)
      {
        MessageStruct dataBuffer;
        unsigned int BytesReceived;
        BytesReceived = mySocket->ReceiveBytes((char*)&dataBuffer, sizeof(dataBuffer));
        
        sprintf(s, "ReaderThread::threadOps-Receive-Unit=%p, Msg=%u", mySocket, dataBuffer.MsgNumber);
        mySocket->LogData(s);
      }

      sprintf (s, "\nReaderThread::threadOps - Exiting Thread\n");
    }*/
  
void ReaderThread::threadOperation()
{
  unsigned char ByteBuffer[MAX_SOCKET_BYTES];
  unsigned int  BytesReceived;
  unsigned long MsgLength;
  char s[500];
  int PktCount = 0;

  do
  {
    BytesReceived = mySocket->ReceiveBytes((char*)&MsgLength, sizeof(MsgLength));

    MsgLength = ntohl(MsgLength);
    mySocket->LogData("");
    mySocket->LogData("***** Start Client Socket Message Processor *****");
    mySocket->LogData("");

    sprintf(s, "MessageReader-Rcvd MsgLength (%u bytes).  MsgLength=%u.",
      sizeof(MsgLength), BytesReceived);
    mySocket->LogData(s);
 
    DataHeader*  DHptr = (DataHeader*)&ByteBuffer;
    unsigned int STN;
    unsigned int NumberOfBytesInMessage;

      BytesReceived = mySocket->ReceiveBytes((char*)&ByteBuffer, sizeof(DataHeader));
    if ((BytesReceived == ERROR) || (BytesReceived > MAX_SOCKET_BYTES))
      return;
    else
    {
      STN = htonl(DHptr->STN);
      NumberOfBytesInMessage = htonl(DHptr->NumberOfBytesInMessage);
      sprintf(s, "MessageReader-Rcvd=%u, STN=%u, NumberOfBytesInMessage=%u",
      BytesReceived, STN, NumberOfBytesInMessage);
      mySocket->LogData(s);
    }

    BytesReceived = mySocket->ReceiveBytes((char*)&MsgLength, sizeof(MsgLength));
    MsgLength = ntohl(MsgLength);
    sprintf(s, "MessageReader-Rcvd MsgLength (%u bytes).  Next Msg Length=%u.",
      sizeof(MsgLength), MsgLength);
    mySocket->LogData(s);

    BytesReceived = mySocket->ReceiveBytes((char*)&ByteBuffer, MsgLength);
    if ((BytesReceived == ERROR) || (BytesReceived > MAX_SOCKET_BYTES))
      return;
    else
    {
      sprintf(s, "MessageReader-Bytes Req=%u, Bytes Rcvd=%u, STN=%u",
      MsgLength, BytesReceived, STN);
      mySocket->LogData(s);

      this->ProcessLinkMessages((InitialWord*)ByteBuffer);
    }

    PktCount++;
    mySocket->LogData("***** End Client Socket Message Processor *****");
    mySocket->LogData("");

  } while (exitFlag == false);
}

//----------------------------------------------------------------------------
// PublisherThread.cpp
//----------------------------------------------------------------------------

//## class PublisherThread
PublisherThread::PublisherThread(int unitNumber, char* IP) : SocketClient(IP)
{
  //char s[200];
  exitFlag = false;
  myUnitNumber = unitNumber;
  strcpy(myIP, IP);
  myReader = NULL;
}

PublisherThread::~PublisherThread()
{
  stop();

  if (myReader != NULL)
    delete myReader;
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

//---------------------------------------------------------------------------

void PublisherThread::threadOperation()
{
  FileReader*      FR = new FileReader(FILE_TO_READ);
  networkHeader_t* Ptr;
  int              PktCount = 0;
  char             s[500];
  networkHeader_t *nHdr;
  packetHeader_t  *pHdr;
  InitialWord* LinkMsg;
  unsigned int     byteCount;

  while ((FR->packetsRemain()) && (exitFlag == FALSE))
  {
    if ((Ptr = ((networkHeader_t*)FR->getNextPacket())) != NULL)
    {
      nHdr = Ptr;
      pHdr = (packetHeader_t*)(((int*)nHdr) + NETWORK_HEADER_SIZE);
      LinkMsg  = (InitialWord*)(((int*)pHdr) + PACKET_HEADER_SIZE);
      byteCount = Ptr->length - (NETWORK_HEADER_SIZE + PACKET_HEADER_SIZE);

      DataHeader Hdr;
      unsigned long SwappedByteCount;

      Hdr.STN = /*htonl(*/myUnitNumber;
      Hdr.NumberOfBytesInMessage = /*htonl(*/byteCount;
      unsigned long totalSize = sizeof(DataHeader) + byteCount;
      SwappedByteCount = ntohl(totalSize);

      this->LogData("");
      this->LogData("********** Start of SUT Link Data Output **********");

      //this->SendBytes((char*)(&SwappedByteCount), sizeof(SwappedByteCount));
      //sprintf(s, "WriteDataToSUT - #Bytes sent=%u, Total Length=%u Bytes, STN=%u",
      //  sizeof(SwappedByteCount), totalSize, myUnitNumber);
      //this->LogData(s);

      this->SendBytes((char*)(&Hdr), sizeof(Hdr));
      sprintf(s, "WriteDataToSUT - Sent Header.  #Bytes=%u, STN#%u",
        sizeof(Hdr), myUnitNumber);
      this->LogData(s);

      //this->SendBytes((char*)(LinkMsg), byteCount);
      //sprintf(s, "WriteDataToSUT - Sent Packet#%u, Length=%u Bytes, STN=%u",
      //  PktCount, byteCount, myUnitNumber);
      //this->LogData(s);

      this->LogData("**********   END of SUT Link Data Output **********");
      this->LogData("");

//      this->ProcessSimpleMessages(((char*)Ptr), Ptr->length);

      framework::utils::Sleep::sleep(0, 500000000);
      free(Ptr);
      PktCount++;
    }
  }
  FR->closeFile();
  
  printf("\nPublisherThread::threadOperation - Exiting Thread\n");
}

void PublisherThread::ClientSocketConnected(Socket* ClientSocket)
{
  char s[500];
  //MessageStruct dataBuffer;
  //unsigned int BytesReceived;

  mySocket = ClientSocket;

  sprintf(s, "PublisherThread::ClientSocketConnected - Connected to server on %s", ClientHostString);
  this->LogData(s);

//  this->start();

  myReader = new ReaderThread(mySocket);
  myReader->start();
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

