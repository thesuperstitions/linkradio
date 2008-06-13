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

#include "ntds_comm_.h"
//#include "sps49_ids.h"

enum Connections
{
  CONNECTION_DOWN = 0,
  CONNECTION_UP = 1
};

static long msgCount = 0;
static BOOLEAN NtdsInitialized = TRUE;
static char *NtdsOutBuf = NULL;
static NTDS_OUTPUT_MSGS NtdsOutBufCtrl;
static int CurrentNtdsStatus = CONNECTION_UP;
static int NtdsDeviceId = 120;

#define CONNECTION_UP 1
#define NUM_OUT_BFRS 8
#define MAX_OUT_BYTES 512

#define GEN_OUTPUT_BUFFER 0 /* MID for General data buffer from SPS49 to CEP */


//#define MAX_MSG_COUNT 1048576

typedef struct            /* R49_NTDS_HDR_STRUCT */
{
       unsigned short
            num_wrds,     /*            Number of words in message            */
            msg_type;     /*                  Type of message                 */
		
}	R49_NTDS_HDR_STRUCT;

//----------------------------------------------------------------------------
// PublisherThread.cpp
//----------------------------------------------------------------------------

//## class PublisherThread

struct MessageStruct
{
  R49_NTDS_HDR_STRUCT Hdr;
  long                MsgNumber;
  unsigned char       MsgBody[96];
};

PublisherThread::PublisherThread(int unitNumber)
{
  //char s[200];
  exitFlag = false;
  
  //sprintf(s, "Unit%u-CEC_R49-Publisher", unitNumber);
  //myQueue = new framework::utils::InterprocessQueue(s, 1000, 1000);
}

PublisherThread::~PublisherThread()
{

  stop();

  //delete myQueue;

}

void PublisherThread::start()
{
  exitFlag = false;

  Thread::start();
}

void PublisherThread::stop()
{
  exitFlag = true;

  this->Thread::join();
  Thread::stop();
}

int GetNtdsInterfaceStatus()
{
	return( CurrentNtdsStatus );
}

void PublisherThread::threadOperation()
{
  MessageStruct* msg;
  unsigned int   slot = 0;
	int status;

	if ( (NtdsOutBuf = Get_NTDS_Buffer(NUM_OUT_BFRS * (sizeof(R49_NTDS_HDR_STRUCT) + MAX_OUT_BYTES), &NtdsOutBufCtrl.partition_id)) == NULL ) 
	{
		printf ("\nInitializeExternalProcessing: Unable to get NTDS output buffer\n");
		status = ERROR;
	}

  msg = (MessageStruct*)NtdsOutBuf;

  while(exitFlag == false)
  {
    msg->MsgNumber = msgCount++;

    //***************************************************************************************
	  R49_NTDS_HDR_STRUCT *hdr;
	  int status;
    int numBytes = sizeof(MessageStruct);

	  if (NtdsInitialized && GetNtdsInterfaceStatus() == CONNECTION_UP) 
    { 
	    NtdsOutBufCtrl.io_pkt.time_out = 0;
	    NtdsOutBufCtrl.io_pkt.delay_time = 0;
	    NtdsOutBufCtrl.status = 0;
	    NtdsOutBufCtrl.confirm = FALSE;
	    NtdsOutBufCtrl.free_buffer = KEEP_MESG_BUFFER;

      /* send buffer to CEP */
		  hdr = (R49_NTDS_HDR_STRUCT *) NtdsOutBuf;
      hdr->num_wrds = ( numBytes - sizeof(R49_NTDS_HDR_STRUCT) ) / 4;
      hdr->msg_type = GEN_OUTPUT_BUFFER;
      NtdsOutBufCtrl.io_pkt.address = (unsigned int *)NtdsOutBuf;
      NtdsOutBufCtrl.io_pkt.req_size = numBytes / 4;
      NtdsOutBufCtrl.io_pkt.retry_count = 0;

      if ( (status = Send_NTDS_Mesg (NtdsDeviceId, &NtdsOutBufCtrl, 0)) != OK ) 
      {
		    printf ("SendToCep: Error %d sending msg to CEP\n",status);
		  }
      else
      {
        LogMessage("PublisherThread::threadOperation - Sent Message\n");
        framework::utils::Sleep::sleep(1, 0/*250000000*/);
      }
    } /* end if ( NtdsInitialized && CONNECTION_UP) ... */
  }
}







        void PublisherThread::LogMessage(char* Msg)
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
          printf("%02u:%02u:%02u.%03u : %s", Hours, Mins, Secs, t.millitm, Msg);
        }


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PublisherThread.cpp
*********************************************************************/

