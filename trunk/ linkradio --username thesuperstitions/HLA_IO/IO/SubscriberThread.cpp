/********************************************************************
	Login		: rosskw1
	Model Element	: SubscriberThread
  Generated Date	: Mon, 21, Apr 2008

  Description: This class is based upon the "Thread" class.  It reads
  messages from a Queue, one at a time, and checks to make sure that
  the messages are received in sequence.
*********************************************************************/

#include "SubscriberThread.h"
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#include "Sleep.h"
#include "ntds_comm_.h"
#include "sps49_io_.h" 

//*******************************************************************
//*******************************************************************
//SPS-49 Code
static DEVICE_DATA NtdsDeviceData;
static int NtdsDeviceId = 120;
static int NtdsUnixDeviceNumber = 0;  
//*******************************************************************


//----------------------------------------------------------------------------
// SubscriberThread.cpp
//----------------------------------------------------------------------------
typedef struct            /* R49_NTDS_HDR_STRUCT */
{
       unsigned short
            num_wrds,     /*            Number of words in message            */
            msg_type;     /*                  Type of message                 */
		
}	R49_NTDS_HDR_STRUCT;

struct MessageStruct
{
  R49_NTDS_HDR_STRUCT Hdr;
  long MsgNumber;
  unsigned char MsgBody[96];
};


static timeb previousTime;
static NTDS_QUE_ID NtdsInputQ = 0;
static NTDS_INPUT_MSGS NtdsInBufCtrl;
//static char *NtdsInBuf = NULL;


SubscriberThread::SubscriberThread(int unitNumber)
{
  //char s[200];
  exitFlag = false;
  
  //sprintf(s, "Unit%u-CEC_R49-Subscriber", unitNumber);
  //myQueue = new framework::utils::InterprocessQueue(s, 1000, 1000);

  previousTime.time = 0;
  previousTime.millitm = 0;

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

SubscriberThread::~SubscriberThread()
{
  stop();
}

void SubscriberThread::start()
{
  exitFlag = false;

  Thread::start();
}

void SubscriberThread::stop()
{
  exitFlag = true;

  printf("\nSubscriberThread::stop - Attempting to Join Thread.\n");
  this->Thread::join();

  printf("\nSubscriberThread::stop - Stopping Thread.\n");
  Thread::stop();
  printf("\nSubscriberThread::stop - Thread Stop Complete.\n");
}

void SubscriberThread::threadOperation()
{
  char           s[500];
  MessageStruct* gmsg;
  bool           timeoutFlag = true; // This forces a "Queue Synchronization" operation.
  unsigned int   msgCount = 0;
  long           prevMsgCount = -1;

	unsigned int    msgBytes;
	char           *inputBuffer;
	R49_NTDS_HDR_STRUCT *hdr;

//while(myQueue->SynchronizeQueueUsers() == false);
	    NtdsInBufCtrl.partition_id = 0;
    	NtdsInBufCtrl.free_buffer = KEEP_MESG_BUFFER;
      NtdsInBufCtrl.io_pkt.time_out = 0;

  while(exitFlag == false)
  {
    if (Recv_NTDS_Mesg(NtdsDeviceId, NtdsInputQ, &NtdsInBufCtrl, 1000) == OK)
    {
		  inputBuffer = (char *) NtdsInBufCtrl.io_pkt.address;
      gmsg = (MessageStruct*)inputBuffer;
		  hdr = (R49_NTDS_HDR_STRUCT *) inputBuffer;
		  msgBytes = hdr->num_wrds * sizeof(int);
		  inputBuffer += sizeof(R49_NTDS_HDR_STRUCT);	/* bypass header */

      //if (gmsg.MsgNumber != (prevMsgCount+1))
      //{
        //sprintf(s, "PROBLEM!!! - MsgNumber=%u, PrevMsgNum=%u\n", gmsg.MsgNumber, prevMsgCount);
        //LogMessage(s);
      //}

      //if ((msgCount % 100000) == 0)
      //{
      sprintf(s, "Sub - Msg #=%u, #Bytes=%u, words = %d, MT=%u\n", gmsg->MsgNumber, NtdsInBufCtrl.io_pkt.tfr_size, hdr->num_wrds, hdr->msg_type);
        LogMessage(s);
      //}
      prevMsgCount = msgCount;
    }
    else
    {
      //framework::utils::Sleep::sleep(0, 1000000);
      
      //LogMessage("TIMEOUT\n");
//      timeoutFlag = true;
    }
  };

  //Delete_NTDS_Interprocess_Queues(NtdsDeviceData.port);
  printf("\nSubscriberThread::threadOperation - Exiting Thread.\n");
}



        void SubscriberThread::LogMessage(char* Msg)
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
	SubscriberThread.cpp
*********************************************************************/

