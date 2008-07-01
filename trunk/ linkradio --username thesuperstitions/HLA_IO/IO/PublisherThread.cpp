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
#include "sps49_io_.h" 

//*******************************************************************
//*******************************************************************
//SPS-49 Code
static DEVICE_DATA NtdsDeviceData;
static int NtdsDeviceId = 120;
static int NtdsUnixDeviceNumber = 0;  
//*******************************************************************
//*******************************************************************


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

  //*******************************************************************
  //*******************************************************************
  //SPS-49 Code
	NtdsDeviceData.board.driver_type = NO_BOARD;
	NtdsDeviceData.board.primary_ntds_port_address = NtdsUnixDeviceNumber;
	NtdsDeviceData.board.secondary_driver_type = NO_BOARD;
	NtdsDeviceData.board.secondary_ntds_port_address = 0xffffffff;
	NtdsDeviceData.redundant_channel_flag	= FALSE;

	NtdsDeviceData.board.address_modifier = 0;
	NtdsDeviceData.board.enet_address[0] = 0;
	NtdsDeviceData.board.enet_port = unitNumber;
	NtdsDeviceData.board.io_mode = 0;
	NtdsDeviceData.board.interrupt_level = 0;
	NtdsDeviceData.board.manual_ei_mode = FALSE;	/* set AUTO */
	NtdsDeviceData.board.word_size = 4;
	NtdsDeviceData.board.io_type = 0;
	NtdsDeviceData.board.int_enable = TRUE;
	NtdsDeviceData.board.passive_mode = FALSE;
	NtdsDeviceData.board.server_enable = TRUE;
	NtdsDeviceData.board.init_mode = 0;
	NtdsDeviceData.device_id = NtdsDeviceId;
	NtdsDeviceData.port = 2;
	NtdsDeviceData.enet_port = unitNumber;
	NtdsDeviceData.enet_address[0] = 0;
	NtdsDeviceData.no_remote_enable	= TRUE;
	NtdsDeviceData.raw_input_que_type = 0;
	NtdsDeviceData.packed_output_queue = FALSE;
	NtdsDeviceData.in_signal_queue = FALSE;
	NtdsDeviceData.out_signal_queue = FALSE;
	NtdsDeviceData.name_string[0] = 0;
	NtdsDeviceData.user1 = 0;
	NtdsDeviceData.user2 = 0;
	NtdsDeviceData.user3 = 0;
	NtdsDeviceData.user4 = 0;
	NtdsDeviceData.user5 = 0;
	NtdsDeviceData.user6 = 0;
	NtdsDeviceData.user7 = 0;
	NtdsDeviceData.user8 = 0;
	NtdsDeviceData.user9 = 0;
	NtdsDeviceData.user10 = 0;
	NtdsDeviceData.next = NULL;

  Initialize_SPS_Interface (&NtdsDeviceData);

  //*******************************************************************
  //*******************************************************************
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

  Delete_NTDS_Interprocess_Queues(NtdsDeviceData.port);

  printf("\nPublisherThread::stop - Attempting to Join Thread.\n");
  this->Thread::join();

  printf("\nPublisherThread::stop - Stopping Thread.\n");
  Thread::stop();
  printf("\nPublisherThread::stop - Thread Stop Complete.\n");
}

int GetNtdsInterfaceStatus()
{
	return( CurrentNtdsStatus );
}

void PublisherThread::threadOperation()
{
  char           s[500];
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

      sprintf(s, "Pub - Msg #=%u, #Bytes=%u, words = %d, MT=%u\n", msg->MsgNumber, numBytes, hdr->num_wrds, hdr->msg_type);
      LogMessage(s);

      if ( (status = Send_NTDS_Mesg (NtdsDeviceId, &NtdsOutBufCtrl, 0)) != OK ) 
      {
		    printf ("\nSendToCep: Error %d sending msg to CEP\n",status);
		  }

      framework::utils::Sleep::sleep(0, 50000000);
    } /* end if ( NtdsInitialized && CONNECTION_UP) ... */
  }
  printf ("\nPublisherThread::threadOperation - Exiting Thread\n");
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
          printf("\n%02u:%02u:%02u.%03u : %s", Hours, Mins, Secs, t.millitm, Msg);
        }


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PublisherThread.cpp
*********************************************************************/

