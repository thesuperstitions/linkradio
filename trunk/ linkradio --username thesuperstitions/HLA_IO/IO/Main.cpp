/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DefaultConfig
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

#include "Main.h"
#include "PublisherThread.h"
#include "SubscriberThread.h"
#include "FrameworkThread.h"
#include "ntds_comm_.h"
#include "sps49_io_.h" 


PublisherThread*    publisherThread;
SubscriberThread*   subscriberThread;
FrameworkThread*    frameworkThread;

//*******************************************************************
//*******************************************************************
//SPS-49 Code
static DEVICE_DATA NtdsDeviceData;
static int NtdsDeviceId = 120;
static int NtdsUnixDeviceNumber = 0;  
//*******************************************************************
//*******************************************************************

//----------------------------------------------------------------------------
// MainDefaultComponent.cpp                                                                  
//----------------------------------------------------------------------------

//## configuration DefaultComponent::DefaultConfig 
int main(int argc, char* argv[]) 
{

  char c[5];
  int unitNumber = atoi(argv[1]);

  printf("Hit any key to CREATE Federate/Application");
  fgets(c, 2, stdin);

  frameworkThread = new FrameworkThread(unitNumber);


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



  publisherThread = new PublisherThread(unitNumber);

  subscriberThread = new SubscriberThread(unitNumber);

  subscriberThread->start();

  printf("Hit any key to START sending messages");
  fgets(c, 2, stdin);

  publisherThread->start();

  printf("Hit any key to STOP  queing/de-queing messages\n\n");
  fgets(c, 2, stdin);

  publisherThread->stop();

	delete publisherThread;

  subscriberThread->stop();

  delete subscriberThread;

  delete frameworkThread;

  printf("Hit any key to EXIT\n\n");
  fgets(c, 2, stdin);

  return 0;
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

