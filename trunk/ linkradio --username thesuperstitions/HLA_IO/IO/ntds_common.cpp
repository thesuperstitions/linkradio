

/******************************************
	*   System-wide includes go here         *
	******************************************/

//#include <vxWorks.h>

/*####################################################*/
/*# Define module symbol for Conditional Compilation #*/
/*####################################################*/

/* ################### */
/* # Module INCLUDES # */
/* ################### */
#include "Sleep.h"
//#include "nio.h"

#include "ntds_comm_.h"
#include "ntds_config.h"
#include "ntds_sys_.h"
//#include <config.h>
//#include "scan_str_.h"
#include "stdio.h"
#include <math.h>
//#include "wrap_io_.h"
#include <time.h>
//#include <vxWorks.h>


typedef unsigned int CLOCK;	/* cep wasp simulation clock */

#if     !defined(FALSE) || (FALSE!=0)
#define FALSE           0
#endif

#if     !defined(TRUE) || (TRUE!=1)
#define TRUE            1
#endif
//
//#ifndef ERROR
//#define ERROR (-1)
//#endif

#ifndef OK
#define OK 0
#endif

typedef void *MSG_Q_ID;



typedef	int		STATUS;



int sysClkRateGet(void)
{
	return(CLOCKS_PER_SEC);
}




//
//#ifdef ANTARES_DRIVER
#include "Sleep.h"
//#include "nio.h"

//#include "nio_driver_.h"

#include "ntds_comm_.h"
#include "ntds_config.h"
#include "ntds_sys_.h"
//#include <config.h>
//#include "scan_str_.h"
#include "stdio.h"
#include <math.h>
//#include "wrap_io_.h"
#include <time.h>
//#include <vxWorks.h>

/************************************
	*    Other Includes go below        *
	************************************/
//#ifdef EXTERNAL_UNIT
//
#include "Sleep.h"
//#include "nio.h"

//#include "nio_driver_.h"

#include "ntds_comm_.h"
#include "ntds_config.h"
#include "ntds_sys_.h"
//#include <config.h>
//#include "scan_str_.h"
//#include "socket_mgr_.h"

#include "stdio.h"
//#endif
//#include "system.h"
#include <math.h>
//#include "wrap_io_.h"
#include <time.h>
//#include <vxWorks.h>

//#include "Nplus1.h"

#include "Sleep.h"
//#include "nio.h"

//#include "nio_driver_.h"

#include "ntds_comm_.h"
#include "ntds_config.h"
//#endif
//#include "ntds_sys_.h"
//#include <config.h>
//#include "scan_str_.h"
//#include "socket_mgr_.h"

#include "stdio.h"
//#endif
//#include "system.h"
#include <math.h>
//#include "wrap_io_.h"
#include <time.h>
//#include <vxWorks.h>


/**********************************************************************
	* Constant Definitions for the NTDS COMMUNICATIONS Package Body only *
	**********************************************************************/
	#define IS_LONG_ALIGNED(addr) (!((unsigned)addr & 03))

/**********   Queues used by the ntds_comm package **********/

#define NUM_OF_NTDS_QUEUES  3

#define NTDS_OUTPUT_QUE     0
#define NTDS_OUT_SIGNAL_QUE 1
#define NTDS_PACKED_OUT_QUE 2

/* Set the message queue message capacity higher for queues created in the    */
/* IOC.  The enet_input task runs at a higher priority than the NTDS Output   */
/* tasks.  It's possible for the app to send more messages to the IOC than the*/
/* queue can handle.  Since the enet_input_task queues them at a higher       */
/* priority than the output task de-queues them, the queue gets saturated.    */
/* This doesn't occur at the application because the task dequeing messages   */
/* runs at a higher priority than the task that's queing the them.            */ 
#ifdef REMOTE_APPLICATION
#define MAX_IN_QUE_ENTRIES     500
#define MAX_OUT_QUE_ENTRIES    500
#define MAX_PACKED_QUE_ENTRIES 500
int Que_Size = 500;
#else
#define MAX_IN_QUE_ENTRIES     150
#define MAX_OUT_QUE_ENTRIES    100
#define MAX_PACKED_QUE_ENTRIES 100
int Que_Size = 100;
#endif

#define MAX_ERR_QUE_ENTRIES     20
#define MAX_SIG_QUE_ENTRIES     10
#define MAX_STAT_QUE_ENTRIES    10

	/* The following macro determines the number of ports that can
	* be associated with a given device.  This code has been tested
	* with a count of 2, which makes the most sense since some apps
	* use redundant channels.
	*/
#define MAX_PORTS_PER_DEVICE 2

		/*  The following definitions are used by the 'find_mesg_type' function
		* to hash into the proper NTDS_QUE_CTRL_BLK for queuing and dequeuing
		* received messages
		*/


#define MAX_NUM_INPUT_MTS  64  /*  The Maximum number of input messages
								*  expected.  This number should be a power
								*  of two.
								*/

	/* The following macro is the hashing function used to compute the
	* index into the Mt_List array to find the index for the MT's
	* NTDS_QUEUE_CTRL_BLK entry.
	*/

#define HASH(n) (n % (MAX_NUM_INPUT_MTS - 1))


	/* The following are return codes from the 'find_mesg_type' function.  */

#define TABLE_FULL -1
#define INDEX_NULL  0
#define MT_FOUND    1

	/* The following definitions are for delaying tasks for whatever reasons */

#define TWO_SECONDS     (sysClkRateGet () * 2)
#define ONE_SECOND      (sysClkRateGet ())

	/* The following are indexes to determine one of multiple ports that
	* may be configured with a single device.
	*/
#define PRIMARY_PORT       0 /* The one being used */
#define SECONDARY_PORT     1 /* The back up port */
#define NORMAL_PORT        2 /* The first port to be configured */
#define ALTERNATE_PORT     3 /* The second port to be configured */

	/* The next defines are used to indicate if a port is the Normal or Alternate
	* Secondary port that's configured for a device. */
#define NORMAL_CHANNEL    00  /* Sent to AN/UYK-43 to identify the Normal Channel */
#define ALTERNATE_CHANNEL 01  /* Sent to AN/UYK-43 to identify the Alternate Channel */

/* The following defines are used in setting up a task that waits for an elapsed
	time and then attempts to swap channels in a redundant-channel configuration */
/*#define VX_TASK_OPTIONS                  VX_DEALLOC_STACK | VX_PRIVATE_ENV
#define CHANNEL_STABILIZATION_PRIORITY   200
#define CHANNEL_STABILIZATION_TASK_STACK 8192
#define PORT_SWAP_DELAY                  500  */   /* 500 MS */


/*********************************************************
	* Type Definitions for the NTDS_COMM Package Body only *
	*********************************************************/

	/*  This structure keeps track of the number of ports assigned to
	* a device.  It is used by this package to allow for dynamic interface
	* switching.
	*/
typedef struct
{
	int device_id;    /* The device that may have multiple ports */
	int primary_port; /* This value contains the port number of the
						* currently active I/O port.
						*/
	int secondary_port; /* This value contains the port number of the
						* port that will be used if the primary port
						* fails.
						*/
	int normal_port; /* The number of the first port to be configured */
	int alternate_port; /* The number of the second port to be configured*/
	int count;          /* Keeps track of the number of known ports */
} PORT_LIST;

	/*  This structure is used to maintain the input queue information for
	* routing messges to the proper application task and maintaining control
	* of the buffer management operations.
	*/

typedef struct
{
	MSG_Q_ID qid;
	PART_ID partition_id;
	unsigned int buffer_size;
	unsigned int que_type;
	int mt_count;
} NTDS_QUEUE_CTRL_BLK;

typedef struct
{
	unsigned int mt;
	unsigned int count;
	unsigned int registered_tasks;
	unsigned int queue_index[MAX_REGISTERS_PER_MT];
} NTDS_MT_CTRL_BLK;

typedef struct
{
	int      registered_tasks;
	int      tid[NUM_OF_NTDS_STATUS_QUES];
	MSG_Q_ID qid[NUM_OF_NTDS_STATUS_QUES];
} STATUS_Q_ID;

typedef struct
{
	int      registered_tasks;
	int      tid[NUM_OF_NTDS_ERROR_QUES];
	MSG_Q_ID qid[NUM_OF_NTDS_ERROR_QUES];
} ERROR_Q_ID;

typedef struct
{
	int      registered_tasks;
	int      tid[NUM_OF_NTDS_SIGNAL_QUES];
	MSG_Q_ID qid[NUM_OF_NTDS_SIGNAL_QUES];
} SIGNAL_Q_ID;

/* The following definitions are used to synchronize the message output queues*/
/* when ports are swapped in a redundant-channel situation.                   */
#define REDUNDANT_CHANNEL_SYNC_MT          0xFFFF
#define REDUNDANT_CHANNEL_SYNC_TIME_TAG    0xFFFFFFFF
#define REDUNDANT_CHANNEL_SYNC_OVERHEAD    4

typedef struct
{
	unsigned msg_size        :16,
			msg_type        :16;
	unsigned msg_time_tag;
} NTDS_MESSAGE_HEADER_STRUCTURE;


/******************************************************************
	* Global Data Definitions Needed by this module but defined in
	* other modules.                                                 *
	*******************************************************************/


/******************************************************************
	* Global Data Definitions Needed by other modules but controlled *
	* by this module.                                                *
	*******************************************************************/
int Debug_Interrupts = 0;
BOOL NTDS_Timing_Study_In_Progress = FALSE;


/******************************************************************
	* Global Data Definitions Needed by THIS modules ONLY,           *
	* they should be declared as static.                             *
	******************************************************************/
	/* Flag to initialize certain functions on the first call */
static int                 First_Time = TRUE;

		/* The following variable keeps track of the configured ports
		* and how many are configured.  The zeroth index contains a
		* count of configured ports, while the rest of the array keeps
		* track of which ports are configured.
		*/
static unsigned int        Comm_Configured[NUM_OF_NTDS_PORTS+1];

static DEVICE_DATA         device_config[NUM_OF_NTDS_PORTS];

//******************************************************************************
// Used by Framework.

#define NTDS_TICKS_TO_MICROSECS 1.0/( ((double)sysClkRateGet())/1000000.0)

#include "InterprocessQueue.h"
//#include "Nplus1.h"

#include "Sleep.h"
//#include "nio.h"

//#include "nio_driver_.h"

#include "ntds_comm_.h"
#include "ntds_config.h"
//#endif
//#include "ntds_sys_.h"
//#include <config.h>
//#include "scan_str_.h"
//#include "socket_mgr_.h"

#include "stdio.h"
//#endif
//#include "system.h"
#include <math.h>
//#include "wrap_io_.h"
#include <time.h>
//#include <vxWorks.h>

static framework::utils::InterprocessQueue* subscribeQueue[NUM_OF_NTDS_PORTS];
static char              buffer[INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES];

static bool exitFlag = false;

class QueueFactory
{
	public:
	QueueFactory(void);
	~QueueFactory(void);
	void createQueues(unsigned int port, unsigned int unit, char* name);
};

QueueFactory::QueueFactory(void)
{
	int i;
	for (i=0; i<NUM_OF_NTDS_PORTS; i++)
	{
		publishQueue[i] = NULL;
		subscribeQueue[i] = NULL;
	}
}

QueueFactory::~QueueFactory(void)
{
	int i;
	for (i=0; i<NUM_OF_NTDS_PORTS; i++)
	{
		if (publishQueue[i] != NULL)
		{
			delete publishQueue[i];
			publishQueue[i] = NULL;
			}
				if (subscribeQueue[i] != NULL)
					{
						delete subscribeQueue[i];
						subscribeQueue[i] = NULL;
						}
						}
}

void QueueFactory::createQueues(unsigned int port, unsigned int unit, char* name)
{
	char s[200];

	if (publishQueue[port] == NULL)
	{
		sprintf(s, "Unit%u-%s-Pub", unit, name);
		publishQueue[port] = new framework::utils::InterprocessQueue(s);
		if (subscribeQueue[port] == NULL)
		{
			sprintf(s, "Unit%u-%s-Sub", unit, name);
			subscribeQueue[port] = new framework::utils::InterprocessQueue(s);
			}
			}
}

static QueueFactory queueFactory;

//******************************************************************************

	/* The following is a pool of VME memory buffer used for communicating
	* with the NTDS board.  Data buffers and instruction chains MUST use
	* this pool for the NTDS board to communicate properly with the
	* host processor. (ie. NO BUS ERRORS).
	*/
static PART_ID Antares_Pool;

			/* port/device association  */
static unsigned int        Port_Device[NUM_OF_NTDS_PORTS];
static PORT_LIST           Device_Ports[NUM_OF_NTDS_PORTS];
static STATUS_Q_ID         Status_Queue_Table[NUM_OF_NTDS_PORTS];
static ERROR_Q_ID          Error_Queue_Table[NUM_OF_NTDS_PORTS];
static SIGNAL_Q_ID         Signal_Queue_Table[NUM_OF_NTDS_PORTS];
static MSG_Q_ID            Queue_Table[NUM_OF_NTDS_PORTS][NUM_OF_NTDS_QUEUES];
static int                 NTDS_Channel_Status[NUM_OF_NTDS_PORTS];
static int                 Input_Queue_Count[NUM_OF_NTDS_PORTS];
static unsigned int        Input_Queue_Type[NUM_OF_NTDS_PORTS];
static NTDS_QUEUE_CTRL_BLK Input_Queue_List[NUM_OF_NTDS_PORTS][MAX_NUM_IN_QUES];
static NTDS_MT_CTRL_BLK    Mt_List[NUM_OF_NTDS_PORTS][MAX_NUM_INPUT_MTS];

/* The following array keeps track of Redundant-Channel Queue synchronization */
/* semaphores.  One counting semaphore is created for each port pair of a of  */
/* a redundant-channel interface.  When an event occurs which causes the      */
/* output queues of the 2 ports to be swapped, both output tasks which are    */
/* blocked on their respective output queues must be awaken and synchronized  */
/* with each other prior to the queue swap.  This is done by creating a       */
/* counting semaphore when the first port wakes up and then, when the 2nd port*/
/* awakens, the output queues are swapped and then two "semGives" are         */
/* performed so that the two output tasks (that are now blocked on the        */
/* semaphore, simultaneously, block on their new QIDs.                        */
//#ifndef USG1
//static SEM_ID Redundant_Channel_Queue_Sync_Semaphore[NUM_OF_NTDS_PORTS];
//#endif

static char *NTDS_Status_String[] = {"UNKNOWN       ",
										"FAILED CONFIG ",
										"RESET         ",
										"INITIALIZING  ",
										"INITIALIZED   ",
										"TEST          ",
										"ENET DOWN     ",
										"ENET UP       ",
										"DISABLED      ",
										"ENABLING      ",
										"ENABLED       ",
										"RESTARTING    ",
										"READY         "
									};

/* This next variable contains the NTDS Gate's Revision Information. */
char NTDS_Gate_Revision_Info[NTDS_GATE_REVISION_SIZE] = "Unknown";

/* This is used to keep the operator from inadvertently starting more than one
	task switch hook task.                                                     */
static BOOL Task_Switch_Hook_Flag = FALSE;


/*************************************************************
	* Global Function Declarations Needed by THIS module ONLY   *
	* (ie "internal routines).  They should be declared as      *
	* 'static'.                                                 *
	*************************************************************/

void
NTDS_Msgs (
	void
);

void
NTDS_Ques (
	void
);


/*#########################################################################
	*
	* SYNOPSIS: get_port
	*
	* DESCRIPTION: This function attempts to find the port assigned to a logical
	*              device.
	*
	* PARAMETERS:
	*
	*   INPUT     device  This parameter contains the logical unit number of
	*                     the device whose port is being found.
	*
	*              port_type  This parameter determines which port will be
	*                         returned.
	*                         PRIMARY_PORT, SECONDARY_PORT, NORMAL_PORT, or 
	*                         ALTERNATE_PORT
	*
	*   OUTPUT    *port_ptr   This parameter is a pointer to the variable that will
	*                     contain the port id of the selected device.  If a port
	*                     cannot be found, a port id of -1 is returned.
	*
	*   RETURNS   OK
	*             INVALID_DEVICE
	*
	*
	* #########################################################################*/
static int
get_port (
	int device,
	int port_type,
	int *port_ptr
)

{

int lcl_index;

				/* Search the list */
	for (lcl_index = 0; lcl_index < NUM_OF_NTDS_PORTS; lcl_index++)
	{
		if (Device_Ports[lcl_index].device_id == device)
		{
			switch (port_type)
				{
					case PRIMARY_PORT :
					*port_ptr = Device_Ports[lcl_index].primary_port;
					break;
					case SECONDARY_PORT :
					*port_ptr = Device_Ports[lcl_index].secondary_port;
					break;
					case NORMAL_PORT :
					*port_ptr = Device_Ports[lcl_index].normal_port;
					break;
					case ALTERNATE_PORT :
					*port_ptr = Device_Ports[lcl_index].alternate_port;
					break;
						}
							return(OK);
							}
							}
	*port_ptr = -1;
	return (INVALID_DEVICE);
}

/*#########################################################################
	*
	* SYNOPSIS: Get_Device_Configuration  (application)
	*
	* DESCRIPTION: This function returns the configuration of a NTDS device.
	*
	* PARAMETERS:
	*
	*     INPUT  device :  This parameter contains the logical unit number of
	*                      of the device being read.
	*
	*    device_status_ptr :  This parameter is a pointer to a variable that
	*                      contains the device configuration information.
	*
	*    OUTPUT  status :   The device configuration information.
	*
	*    RETURNS OK
	*            INVALID_DEVICE
	*            vxWorks error code
	*
	*
	* #########################################################################*/
int
Get_Device_Configuration (
	int         device,
	NTDS_CONFIG *device_status_ptr
)

{
	int status, port;

	status = get_port (device, PRIMARY_PORT, &port);
	if ( (status != OK) || (port == NO_PRIMARY_PORT) )
	{
		if ( (status == OK) && (port == NO_PRIMARY_PORT) )
		{
			status = get_port (device, SECONDARY_PORT, &port);
			if ( (status != OK) || (port == NO_SECONDARY_PORT) )
				{
					if ( (status == OK) && (port == NO_SECONDARY_PORT) )
							{
								Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
								"NTDS:Get_Device_Configuration-Device=%d, Port=%c, There is no"
								" PRIMARY or SECONDARY port configured for this device.",
								device, 'A'+port);
								return (INVALID_DEVICE);
										}
												}
													}
													}

	if (status == OK)
	{
		device_status_ptr->port = port;
		if (Comm_Configured[port+1] == TRUE)
		{
			device_status_ptr->word_size = device_config[port].board.word_size;
			device_status_ptr->mode = device_config[port].board.io_mode;
			device_status_ptr->ei_mode = device_config[port].board.manual_ei_mode;
			device_status_ptr->init_mode = device_config[port].board.init_mode;
			strcpy (device_status_ptr->enet_address, device_config[port].enet_address);
			return (status);
			}
				else
					{
						Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
						"NTDS:Get_Device_Configuration-Device=%d, Port=%c, Device Not Configured",
						device, 'A'+port);
						return (INVALID_DEVICE);
						}
						}
	else
	{
		Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
		"NTDS:Get_Device_Configuration-Device=%d, Port=%c  UNKNOWN DEVICE",
		device, 'A'+port);
		return (status);
	}
}

/* #########################################################################
	*
	* SYNOPSIS:    Test_NTDS_Level2 (application)
	* 
	* DESCRIPTION: This function is used by the application to invoke a LEVEL 2
	*              test in a protocol. It's operation is similar to that of 
	*              NTDS_Control.  Upon protocol initialization, the protocol puts
	*              the address of its Level2 control function into the "level2_comm"
	*              function pointer (part of the NTDS_CTRL_FUNC structure which is
	*              part of the list of DEVICE_DATA structrures that are sent to
	*              the protocol initialization function).  The "level2_comm" function
	*              is invoked when an application calls Test_NTDS_Level2 in order
	*              to start a Level 2 test scenario.
	*
	* PARAMETERS:  
	*
	*   INPUT:     device - This parameter is the numeric identifier associated
	*                       with an NTDS port.
	*              level2_test_params - this is a structure of type NTDS_TEST_MSGS
	*                                   which is filled out by the application
	*                                   and passed to Test_NTDS_Level2, which 
	*                                   passes it to the protocol's "level2_comm"
	*                                   function.  By using a structure which
	*                                   contains several integers, NTDS_Comm 
	*                                   provides a way to let the protocol and
	*                                   application perform whatever Level2 
	*                                   functions that are needed.
	*
	*   OUTPUT:    NONE                                                         
	*   DATA :     OK                                                           
	*              DEVICE_NOT_CONFIGURED                                        
	*              LEVEL2_FUNCTIONS_NOT_AVAILABLE
	*              subordinate function returns
	*
	* #########################################################################*/
int 
Test_NTDS_Level2(
	int device,
	NTDS_TEST_MSGS level2_test_params
)

{
//  int status;
//  int port;
//
//  status = get_port (device, PRIMARY_PORT, &port);
//  if ( (status != OK) || (port == NO_PRIMARY_PORT) )
//
{
//    if ( (status == OK) && (port == NO_PRIMARY_PORT) )
//
{
//      status = get_port (device, SECONDARY_PORT, &port);
//      if ( (status != OK) || (port == NO_SECONDARY_PORT) )
//
{
//        if ( (status == OK) && (port == NO_SECONDARY_PORT) )
//
{
//          Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
//            "NTDS:Test_NTDS_Level2-Device=%d, Port=%c, There is no"
//            " PRIMARY or SECONDARY port configured for this device.",
//            device, 'A'+port);
//          return (INVALID_DEVICE);
//        }
//      }
//    }
//  }
//  if (status != OK)
//
{
//    Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
//      "NTDS:Test_NTDS_Level2-Device=%d, Port=%c, UNKNOWN DEVICE",
//      device, 'A'+port);
//    return (status);
//  }
//
//   /* Lie a wee bit an tell the app all was OK if we are simply testing
//    * the interface without a protocol or NTDS card.
//    */
//   if (device_config[port].board.init_mode == TEST_INTERFACE)
//
{
//     return (OK);
//   }
//       /* We only check we are a satellite or local box */
//   if ((Comm_Configured[port+1] != TRUE) &&
//   (device_config[port].board.init_mode != REMOTE_INTERFACE))
//
{
//     Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
//       "NTDS:Test_NTDS_Level2-Port=%c  Device is NOT Configured", 'A'+port);
//      return (DEVICE_NOT_CONFIGURED);
//   }
//#ifdef EXTERNAL_UNIT
//	/* Figure out where to Queue the Message (Local or Remote) */
//
//   if (device_config[port].board.init_mode == REMOTE_INTERFACE)
//
{
//#ifndef REMOTE_APPLICATION /* Used to prevent linking unused code */
//      if ((status = Test_Remote_NTDS_Level2 (device, level2_test_params)) != OK)
//
{
//        Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
//          "NTDS:Test_NTDS_Level2-Port=%c  Could Not Send Ethernet buffer",
//          'A'+port);
//      }
//#endif
//      return (status);
//   }
//   else
//#endif
//
{
//     if (device_config[port].function.level2_comm != NULL)
//
{
//       return ( status = (device_config[port].function.level2_comm)(port, level2_test_params) );
//     }
//     else
//
{
//       Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
//         "NTDS:Test_NTDS_Level2-Port=%c  Level 2 NOT enabled for this device ",
//         'A'+port);
//         return (LEVEL2_FUNCTIONS_NOT_AVAILABLE);
//     }
//   }
	return(0);
}

/* #########################################################################
	*
	* SYNOPSIS:    Get_NTDS_Device_Name (application)
	*
	* DESCRIPTION: This function is used to convert the input Device ID value (an
	*              integer) to its associated Device Name (a string), which is
	*              returned to the calling routine.
	*
	* PARAMETERS:
	*
	*   INPUT:     port - This parameter is the numeric identifier associated
	*                     with an NTDS port.
	*
	*   OUTPUT:    Device Name - This function returns a character string which
	*                            represents the input Device_ID.
	*
	*   DATA :     device_config - Static data structure which contains port
	*                              context information for each NTDS device. 
	*
	* #########################################################################*/
char* 
Get_NTDS_Device_Name(
	int port 
)

{
	return(device_config[port].name_string);  /* return the results to the caller. */
}
/* ##############################################################################
	*
	* SYNOPSIS:    Show_NTDS_Device_Name (Application) 
	*
	* DESCRIPTION: This function is used to convert the input Port ID value to      
	*              its associated Device Name and then display it on the standard
	*              output device.  First, the input Port ID is examined to see if
	*              is within the legal range (A - Z).  If not, an error message is
	*              displayed, along with the correct calling format.
	*
	* INPUT:       device_ID - This parameter is the integer identifier associated 
	*                          with an NTDS port.
	*
	* OUTPUT:      The device name associated with the input Device_ID is printed 
	*              to stdout.                
	*
	* FUNCTIONS CALLED : Get_NTDS_Device_Name - This function is called to obtain
	*                                           device name of the input Device ID. 
	*
	* ###########################################################################*/
void 
Show_NTDS_Device_Name(
	int device_ID
)

{
	printf("%s\n", Get_NTDS_Device_Name(device_ID));
} 

/* #########################################################################
	*
	* SYNOPSIS: Get_Device_Index
	*
	* DESCRIPTION: This function attempts to find the index into the Device_Ports
	*              array for the input device.
	*
	* PARAMETERS:
	*
	*   INPUT     device  This parameter contains the logical unit number of
	*                     the device whose port is being found.
	*
	*   OUTPUT    Nothing
	*   RETURNS   Index used when referencing the Device_Ports array.
	*             INVALID_DEVICE
	*
	*
	* #########################################################################*/
int
Get_Device_Index (
	int device
)

{

int lcl_index;

				/* Search the list */
	for (lcl_index = 0; lcl_index < NUM_OF_NTDS_PORTS; lcl_index++)
	{
		if (Device_Ports[lcl_index].device_id == device)
		return(lcl_index);
	}
	return (INVALID_DEVICE);

}

/*#########################################################################
	*
	* SYNOPSIS: port_used
	*
	* DESCRIPTION: This function checks to see if a device id is assigned to the
	*              port.
	*
	* PARAMETERS:
	*
	*   INPUT     device  This parameter contains the logical unit number
	*                     of device being tested.
	*
	*             port    This parameter contains the logical unit number
	*                     of hardware port being tested.
	*
	*   OUTPUT    NONE
	*
	*   RETURNS   TRUE
	*             FALSE
	*
	* #########################################################################*/
static int
port_used (
	int device,
	int port
)

{

int lcl_index;

	for (lcl_index = 0; lcl_index < NUM_OF_NTDS_PORTS; lcl_index++)
	{
		/* Entry is empty so start a new one */
		if (Device_Ports[lcl_index].device_id == device)
		{
			if (Device_Ports[lcl_index].count < MAX_PORTS_PER_DEVICE)
				{
					return (OK);
						}
							else
									{
										return (Port_Device[port]);
											}
												}
												}
	return (OK);
}

/*#########################################################################
	*
	* SYNOPSIS: assign_port_to_device
	*
	* DESCRIPTION: This function links a port with a device so that it may be
	*              dynamically switched at run time.
	*
	*                 NOTE:   This function assumes that
	*                       the device id will be nonzero.
	*
	* PARAMETERS:
	*
	*   INPUT     device  This parameter contains the logical unit number
	*                     of device being tested.
	*
	*             port :  This parameter contains the port id of the hardware
	*                     interface.
	*
	*   OUTPUT    NONE
	*
	*   RETURNS   OK if successful
	*             ERROR if an error is detected
	*                   TABLE_FULL
	*
	* #########################################################################*/
static int
assign_port_to_device (
	int device,
	int port,
	int redundant_channel_flag
)

{

	int lcl_index;

	/* Search the list */
	for (lcl_index = 0; lcl_index < NUM_OF_NTDS_PORTS; lcl_index++)
	{
		if (Device_Ports[lcl_index].device_id == 0)
		{
			/* Entry is empty so start a new one */
			Device_Ports[lcl_index].device_id = device;
			if (redundant_channel_flag == NTDS_SECONDARY_PORT)
				{
					Device_Ports[lcl_index].normal_port = NO_PRIMARY_PORT;
					Device_Ports[lcl_index].primary_port = NO_PRIMARY_PORT;
					Device_Ports[lcl_index].secondary_port = port;
					Device_Ports[lcl_index].alternate_port = port;
						}
							else
									{
										Device_Ports[lcl_index].normal_port = port;
										Device_Ports[lcl_index].primary_port = port;
										Device_Ports[lcl_index].secondary_port = NO_SECONDARY_PORT;
										Device_Ports[lcl_index].alternate_port = NO_SECONDARY_PORT;
											}
												/*Initialize the Queue-Synchronization semaphores for Redundant-Channel */
												/* Operations.                                                          */
												Device_Ports[lcl_index].count++;
												return (OK);
												}
													/* Found a previous entry  */
													else if (Device_Ports[lcl_index].device_id == device)
														{
															/* Do we have a secondary port yet? */
															if (Device_Ports[lcl_index].count < MAX_PORTS_PER_DEVICE)
																	{
																		if (redundant_channel_flag == NTDS_SECONDARY_PORT)
																					{
																						Device_Ports[lcl_index].secondary_port = port;
																						Device_Ports[lcl_index].alternate_port = port;
																								}
																									else
																												{
																													/* If Alternate port already configured, it may have been swapped   */
																													/* to Primary.  Check to see if Primary has a "Port" assigned to it.*/
																													if (Device_Ports[lcl_index].primary_port == NO_PRIMARY_PORT)
																													Device_Ports[lcl_index].primary_port = port;
																													else
																													Device_Ports[lcl_index].secondary_port = port;
																													Device_Ports[lcl_index].normal_port = port;
																															}
																																Device_Ports[lcl_index].count++;
																																return (OK);
																																	}
																																		else  /* Yes */
																																				{
																																					return (TABLE_FULL);
																																						}
																																							}
																																							}
	return (TABLE_FULL);
}

/*#########################################################################
	*
	* SYNOPSIS: find_mt_index
	*
	* DESCRIPTION: This function finds an array index determined by the value of
	*              of the message type received.
	*
	* PARAMETERS:
	*
	*   INPUT     port : The port_id of the device that will received the message
	*                    type being hashed.
	*
	*     message_type :  This parameter contains the value that will be
	*                     hashed to an array index.
	*
	*   OUTPUT    *index_ptr : This parameter is pointer to a variable that will
	*                      contain the index into the Mt_List which contains the
	*                      queue_index for the NTDS_QUEUE_CTRL_BLK for the
	*                      specified message type.
	*
	*
	*   RETURNS   INDEX_NULL
	*             MT_FOUND
	*             TABLE_FULL
	*
	*
	* #########################################################################*/
static int
find_mt_index (
	int          port,
	unsigned int mt,
	int          *index_ptr
)

{

int i;
int last_one;

	if (mt == 0)
	{
		Log_NTDS_Mesg (Get_Device_Id(port), NTDS_ERROR_CAT,
		"NTDS:find_mt_index-Port=%c Trying to hash a message type of zero (0)",
		'A'+port);
		return (INDEX_NULL);
	}
			/* Compute the index from the hashing function */
	*index_ptr = HASH (mt); 
	if (mt == Mt_List[port][*index_ptr].mt)         /* Found it */
	{
		return (MT_FOUND);
	}
	else if (Mt_List[port][*index_ptr].mt == 0)  /* Entry is empty */
	{
		return (INDEX_NULL);
	}
	last_one = *index_ptr;  /* Save the current index pointer */
	i = last_one + 1;  /* Set up to start with the next index */
	while (i != last_one)  /* Attempt to resolve a collision  */
	{
		if (i >= MAX_NUM_INPUT_MTS)  /* Check to wrap at the end */
		{
			i = 0;
			}
				*index_ptr = i;
				if (mt == Mt_List[port][i].mt)   /* Found a match  */
					{
						return (MT_FOUND);
						}
							else if (Mt_List[port][i].mt == 0)     /* Cell is empty */
								{
									return (INDEX_NULL);
									}
										i++;
									}
	*index_ptr = -1;
	return (TABLE_FULL);  /* No empty slots and no matches   */
}
/*#########################################################################
	*
	* SYNOPSIS:  queue_ifc_status    (protocol)
	*
	* DESCRIPTION:      This function wakes up applications that may be waiting
	*                for a status change.  The status will only be queued if
	*                the status changes.
	*
	* PARAMETERS:
	*
	*    INPUT   port :    This parameter contains the port id of the board
	*                   reporting a status change.
	*
	*            status :  This parameter contains the new interface status.
	*
	*    OUTPUT  NOTHING
	*
	* RETURNS OK or
	*         BAD_PORT_ID
	*         vxWorks ERROR code.
	*
	*#########################################################################*/
int
queue_ifc_status (
	int        port,
	int        readiness
)

{

//NTDS_STATUS_MSGS event;
//
//int status;
//int lcl_index;
//int normalport;
//
//   if (NTDS_Channel_Status[port] != readiness)
//
{
//      NTDS_Channel_Status[port] = readiness;
//      lcl_index = 0;
//      event.status = readiness;
//      event.time   = Get_NTDS_Time ();
//
//      /* If this port is the alternate port, we have to find the normal port  */
//      /* and queue the status change to its status queues.  This prevents     */
//      /* having to create and monitor two sets of status queues, one for the  */
//      /* normal port and one for the alternate port.  We will always queue    */
//      /* INTERFACE status changes to the "Normal" port's registered tasks.    */
//      normalport = Get_Normal_NTDS_Port (Port_Device[port]);
//      if ( (normalport < 0) || (normalport >= NUM_OF_NTDS_PORTS) )
//        return (normalport); /* normalport will contain an error status.      */
//
//      if (port != normalport) /* If this is the alt port, change to normal    */
//
{
//        port = normalport;
//      }
//      while (lcl_index < Status_Queue_Table[port].registered_tasks)
//
{
//         status = msgQSend (Status_Queue_Table[port].qid[lcl_index],
//                            (char *) &event,
//                            sizeof (NTDS_STATUS_MSGS), NO_WAIT, MSG_PRI_NORMAL);
//         if (status == ERROR)
//
{
//            Log_NTDS_Mesg (Get_Device_Id(port), NTDS_ERROR_CAT,
//              "NTDS:queue_ifc_status-Port=%c  msgQSend FAILURE. 0x%x QID= 0x%x",
//              'A'+port, errnoGet(), Status_Queue_Table[port].qid[lcl_index]);
//            return (errnoGet());
//         }
//         lcl_index++;
//      }
//   }
	return (OK);
}

/*#########################################################################
	*
	* SYNOPSIS:           NTDS_Control   (application)
	*
	* DESCRIPTION:       NTDS_Control provides run time control of the NTDS
	*                   interface.  The definition and usage of these functions is
	*       dependent on the protocol being used.  Therefore, each
	*       interface protocol function provides the functions required to
	*       implement the protocol.  The following is a list of functions that
	*       may be invoked by NTDS control.
	*
	*        Init_Comm ()
	*        Enable_Comm ()
	*        Suspend_Comm ()
	*        Resume_Comm ()
	*        Disable_Comm ()
	*        Reset_Comm ()
	*        Restart_Comm ()
	*        Test_Comm ()
	*
	*     NOTE:    If any of these functions are not required by a protocol a
	*              NULL pointer should be provided for those functions when
	*              the device is initialized.  See "Configure_NTDS_Device".
	*
	* PARAMETERS:
	*
	*   INPUT   device :        This parameter contains the logical unit number of the
	*                      device being used.
	*
	*             command : This parameter contains the command to be executed.
	*
	*   OUTPUT  NONE
	*
	*   RETURNS OK
	*           DEVICE_NOT_CONFIGURED
	*           INVALID_COMMAND
	*           subordinate function returns
	*
	* #########################################################################*/
int
NTDS_Control (
	int device,
	int command
)

{
	/* Check to see if the N+1 channel needs to operate on this command.       */
	/* If it does, the call to the N+1 function returns a non-OK value, which  */
	///* tells us to ignore the NTDS_Control command and return OK to our caller.*/
	//if (NPLUS1_Control(device, command) != OK)
		return(OK);

	//return( local_ntds_control (device, NORMAL_PORT, command) );
}
/*#########################################################################
	*
	* SYNOPSIS:           NTDS_Secondary_Control   (application)
	*
	* DESCRIPTION:       NTDS_Secondary_Control provides run time control of the secondary
	*       NTDS interface.  The definition and usage of these functions is
	*       dependent on the protocol being used.  Therefore, each
	*       interface protocol function provides the functions required to
	*       implement the protocol.  The following is a list of functions that
	*       may be invoked by NTDS control.
	*
	*        Init_Comm ()
	*        Enable_Comm ()
	*        Suspend_Comm ()
	*        Resume_Comm ()
	*        Disable_Comm ()
	*        Reset_Comm ()
	*        Restart_Comm ()
	*        Test_Comm ()
	*
	*     NOTE:    If any of these functions are not required by a protocol a
	*              NULL pointer should be provided for those functions when
	*              the device is initialized.  See "Configure_NTDS_Device".
	*
	* PARAMETERS:
	*
	*   INPUT   device :        This parameter contains the logical unit number of the
	*                      device being used.
	*
	*             command : This parameter contains the command to be executed.
	*
	*   OUTPUT  NONE
	*
	*   RETURNS OK
	*           DEVICE_NOT_CONFIGURED
	*           INVALID_COMMAND
	*           subordinate function returns
	*
	* #########################################################################*/
int
NTDS_Secondary_Control (
	int device,
	int command
)

{
	//return ( local_ntds_control(device, ALTERNATE_PORT, command) );
		return(OK);
}

#ifndef USG1
/*#########################################################################
	*
	* SYNOPSIS:           Redundant_Channel_Control   (application)
	*
	* DESCRIPTION:        Redundant_Channel_Control provides a means by which
	*                     a state, detected on one channel in a redundant-channel
	*                     configuration, can cause the invocation of an action on
	*                     the other channel, assuming it is able to carry out the
	*                     action.
	*
	*
	* PARAMETERS:
	*
	*   INPUT   device :   This parameter contains the logical unit number of the
	*                      device being used.
	*
	*           port   :   The port detected the "State" which is to be acted upon.
	*
	*
	*           state  : This parameter contains the "state" of the port. An action
	*                    may be carried out on the redundant-channel in response
	*                    to this "state" being reported.
	*
	*   OUTPUT  NONE
	*
	*   RETURNS OK
	*           DEVICE_NOT_CONFIGURED
	*           INVALID_COMMAND
	*           subordinate function returns
	*
	* #########################################################################*/
int
Redundant_Channel_Control(
	int device,
	int port,
	int state
)
{
//  int status;
//  int redundant_port;
//
//  /* Find the redundant port, if any, for the port reporting the "state"      */
//  status = get_port (device, NORMAL_PORT, &redundant_port);
//  if ((status == OK) && (redundant_port >= 0))
//
{
//    if (port == redundant_port)
//      status = get_port (device, ALTERNATE_PORT, &redundant_port);
//  }
//
//  if ( (status != OK) || (redundant_port < 0) )
//
{
//    if (status != OK)
//
{
//      Log_NTDS_Mesg (device, NTDS_ERROR_CAT, "NTDS:Redundant_Channel_Control-"
//        "Device=%d, Port=%c,  UNKNOWN DEVICE", device, 'A'+port);
//    }
//    else
{
//      Log_NTDS_Mesg (device, NTDS_STATUS_CAT, "NTDS:Redundant_Channel_Control-"
//        "Device=%d, Port=%d,  UNKNOWN PORT, redundant_port=%d",
//        device, port, redundant_port);
//    }
//    status = CHANNEL_STATUS_UNKNOWN;
//    return(status);
//  }
//
//  /* Call the protocol function which can handle this "state".                */
//  return( (device_config[redundant_port].function.redundant_channel_comm)
//    (device, redundant_port, port, state) );
		return(OK);
}
#endif


#ifndef USG1
/*#########################################################################
	*
	* SYNOPSIS:           Sync_Redundant_Channel_Queues   (application)
	*
	* DESCRIPTION:        Sync_Redundant_Channel_Queues handles the task of
	*                       dropping a synchronization message
	*                       into the port's queue so that this particular
	*                       instances of the protocol's output task wakes up,
	*                       processes the synch message and then blocks on its new
	*                       QID.
	*
	* PARAMETERS:
	*
	*   INPUT   port :   Channel identifier for Synch Message operation.
	*
	*   OUTPUT  Queue synchronization messages
	*
	*
	*   RETURNS None
	*
	* #########################################################################*/
void
Sync_Redundant_Channel_Queues(
	int port
)
{
	//NTDS_MESSAGE_HEADER_STRUCTURE* Header;
	//NTDS_OUTPUT_MSGS               out_block;
	//PART_ID                        pid;
	//int                            status;
	//int                            device = Get_Device_Id(port);

	//Header = (NTDS_MESSAGE_HEADER_STRUCTURE *)Get_NTDS_Buffer((
	//  sizeof(NTDS_MESSAGE_HEADER_STRUCTURE)+4), &pid);
	//if (Header == NULL)
	//
	{
	//  Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
	//    "NTDS:Sync_Redundant_Channel_Queues-port=%c, Mem Alloc Error",
	//    port+'A');
	//}
	//else
	//
	{
	//  Header->msg_size = (sizeof(NTDS_MESSAGE_HEADER_STRUCTURE)) / 4;
	//  Header->msg_type = REDUNDANT_CHANNEL_SYNC_MT;
	//  Header->msg_time_tag = REDUNDANT_CHANNEL_SYNC_TIME_TAG;

	//  out_block.partition_id = pid;
	//  out_block.status = NULL;
	//  out_block.free_buffer = FREE_MESG_BUFFER;
	//  out_block.confirm = NO_CONFIRM_OUTPUT;
	//  out_block.io_pkt.address = (unsigned int *)Header;
	//  out_block.io_pkt.req_size = Header->msg_size + REDUNDANT_CHANNEL_SYNC_OVERHEAD;
	//  out_block.io_pkt.time_out = 0;
	//  out_block.io_pkt.delay_time = 0;
	//  out_block.io_pkt.retry_count = 0;

	//  status = Send_NTDS_Mesg_To_Port(port, &out_block, MSG_PRI_URGENT);
	//  if (status != OK)
	//
	{
	//    Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
	//      "NTDS:Sync_Redundant_Channel_Queues-port=%c, "
	//      "Send_NTDS_Mesg Error - Status=%x",
	//      port+'A', status);
	//  }
	//}
}
#endif

#ifndef USG1
/*#########################################################################
	*
	* SYNOPSIS:           Get_Redundant_Channels_Queue_Sync_Semaphore (application)
	*
	* DESCRIPTION:        Get_Redundant_Channels_Queue_Sync_Semaphore is called by
	*                     a port when its output message queue is awakened by the
	*                     receipt of a REDUNDANT_CHANNEL_SYNC_MT.  This function
	*                     returns a semaphore to the caller.  The caller blocks on
	*                     this semaphore, waiting for 2nd port to wake up and call
	*                     this function.  When this function is called by the 2nd
	*                     port of the redundant-channel pair, the QIDs of the two
	*                     ports are swapped and then a "semGive" is
	*                     performed on each semaphore.  This will allow both ports
	*                     to block on their output message queues, which were
	*                     swapped, at the same time.  This prevents one port from
	*                     swapping prior to the 2nd and stealing the 2nd port's
	*                     REDUNDANT_CHANNEL_SYNC_MT message.
	*
	*
	* PARAMETERS:
	*
	*   INPUT   port :   Channel identifier for queue sync operations.
	*
	*
	*   OUTPUT  Swapped QIDs
	*
	*
	*
	*   RETURNS Semaphore ID - the SEM_ID of the counting semaphore set up by this
	*                          function.
	*
	*           GET_REDUNDANT_CHANNEL_QUEUE_SYNC_SEMAPHORE_ERROR - Error code
	*             denoting the condition of one or both ports not being configured.
	*
	* #########################################################################*/
SEM_ID
Get_Redundant_Channels_Queue_Sync_Semaphore(
	int port
)
{
	//MSG_Q_ID   QID;
	//char       str[100];
	//int        device = Port_Device[port];
	//int        normalport = Get_Normal_NTDS_Port(device);
	//int        alternateport = Get_Alternate_NTDS_Port(device);
	//SEM_ID     Semaphore = Redundant_Channel_Queue_Sync_Semaphore[port];


	//if (Redundant_Channel_Queue_Sync_Semaphore[port] == (SEM_ID)0xFFFFFFFF)
	//
	{
	//  Semaphore = semBCreate(SEM_Q_FIFO, SEM_EMPTY);
	//  Redundant_Channel_Queue_Sync_Semaphore[port] = Semaphore;
	//}

	//if ( (Redundant_Channel_Queue_Sync_Semaphore[normalport] !=
	//(SEM_ID)0xFFFFFFFF) &&
	//(Redundant_Channel_Queue_Sync_Semaphore[alternateport] !=
	//(SEM_ID)0xFFFFFFFF) )
	//
	{
	//  /* Both of the ports for this redundant-channel-configured device have  */
	//  /* checked in.  Swap the output queues and then performa a "semGive"    */
	//  /* for each one.                                                        */

	//  /* Swap the QIDs so that data that's queued at the port being swapped   */
	//  /* out will be dequeued by the port being swapped in.                   */
	//  QID = Queue_Table[normalport][NTDS_OUTPUT_QUE];
	//  Queue_Table[normalport][NTDS_OUTPUT_QUE] =
	//    Queue_Table[alternateport][NTDS_OUTPUT_QUE];
	//  Queue_Table[alternateport][NTDS_OUTPUT_QUE] = QID;

	//  QID = Queue_Table[normalport][NTDS_PACKED_OUT_QUE];
	//  Queue_Table[normalport][NTDS_PACKED_OUT_QUE] =
	//    Queue_Table[alternateport][NTDS_PACKED_OUT_QUE];
	//  Queue_Table[alternateport][NTDS_PACKED_OUT_QUE] = QID;

	//  QID = Queue_Table[normalport][NTDS_OUT_SIGNAL_QUE];
	//  Queue_Table[normalport][NTDS_OUT_SIGNAL_QUE] =
	//    Queue_Table[alternateport][NTDS_OUT_SIGNAL_QUE];
	//  Queue_Table[alternateport][NTDS_OUT_SIGNAL_QUE] = QID;

	//  /* We need to swap the name strings of the two ports so that calls to
	//   * "Show_NTDS_Config" display the correct string for the port that is
	//   * actively performing I/O with the other side of the interface.        */
	//  strcpy(str, device_config[normalport].name_string);
	//  strcpy(device_config[normalport].name_string,
	//    device_config[alternateport].name_string);
	//  strcpy(device_config[alternateport].name_string, str);

	//  Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
	//    "NTDS:Get_Redundant_Channels_Queue_Sync_Semaphore-Swapped from "
	//    "Port '%c' to Port '%c'.  Port Swap Successful.",
	//    'A'+Get_Secondary_NTDS_Port(device), 'A'+Get_Primary_NTDS_Port(device) );

	//  /* Give each instance of the redundant-channel configuration a semaphore*/
	//  /* At this point, the first output task that called this function is    */
	//  /* blocking on its semaphore.  The instance that's currently being      */
	//  /* processed will not "take" the semaphore until we return from this    */
	//  /* function.                                                            */
	//  semGive(Redundant_Channel_Queue_Sync_Semaphore[normalport]);
	//  semGive(Redundant_Channel_Queue_Sync_Semaphore[alternateport]);

	//  /* Reset each semaphore ID to initialized value.                          */
	//  Redundant_Channel_Queue_Sync_Semaphore[normalport] = (SEM_ID)0xFFFFFFFF;
	//  Redundant_Channel_Queue_Sync_Semaphore[alternateport] = (SEM_ID)0xFFFFFFFF;
	//}

	//return(Semaphore);

	SEM_ID     Semaphore;
	return(Semaphore);
}

#endif

#ifndef USG1
/*#########################################################################
	*
	* SYNOPSIS:           Change_Port_Name (application)
	*
	* DESCRIPTION:        This function changes the name of the input port, to
	*                     the name specified in the "New_Name" parameter.
	*
	*
	* PARAMETERS:
	*
	*   INPUT   Port :   Channel identifier for queue sync operations.
	*           New_Name: Name to give the port.
	*
	*
	*   OUTPUT  Nothing
	*
	*
	*
	*   RETURNS Nothing.
	*
	*
	* #########################################################################*/
void
Change_Port_Name(
	int Port,
	char* New_Name
)
{
	strcpy(device_config[Port].name_string, New_Name);
}

#endif

/*#########################################################################
	*
	* SYNOPSIS:  Send_Swap_Status    (protocol)
	*
	* DESCRIPTION:      This function sends swap notifications to applications
	*                that have redundant channels.  The notification will be
	*                sent only after a swap has occurred.
	*
	* PARAMETERS:
	*
	*    INPUT   device    :  This parameter contains the device id of the
	*                         interface cards involved in the port swap.
	*
	*            swap_msg  :  This parameter indicates the direction of the swap.
	*
	*    OUTPUT  NOTHING
	*
	* RETURNS OK or
	*         vxWorks ERROR code.
	*
	*#########################################################################*/
int
Send_Swap_Status (
	int device,
	int swap_msg
)

{

	//NTDS_STATUS_MSGS event;

	//int status;
	//int lcl_index;
	//int port;

	//status = get_port (device, NORMAL_PORT, &port);
	//if ( (status != OK) || (port == NO_NORMAL_PORT) )
	//
	{
	//  if ( (status == OK) && (port == NO_NORMAL_PORT) )
	//
	{
	//    Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
	//      "NTDS:Send_Swap_Status-Device=%d, Port=%c, There is no"
	//      " NORMAL port configured for this device.",
	//      device, 'A'+port);
	//    return (INVALID_DEVICE);
	//  }
	//}
	//if (status != OK)
	//
	{
	//  Log_NTDS_Mesg (device, NTDS_ERROR_CAT, "NTDS:Send_Swap_Status-Device=%d,"
	//    "  UNKNOWN DEVICE", device);
	//  return (status);
	//}

	//lcl_index = 0;
	//event.status = swap_msg;
	//event.time   = Get_NTDS_Time ();
	//while (lcl_index < Status_Queue_Table[port].registered_tasks)
	//
	{
	//  status = msgQSend (Status_Queue_Table[port].qid[lcl_index],
	//                    (char *) &event,
	//                    sizeof (NTDS_STATUS_MSGS),
	//                    NO_WAIT, MSG_PRI_NORMAL);

	//  if (status == ERROR)
	//
	{
	//     Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
	//       "NTDS:Send_Swap_Status-Port=%c  msgQSend FAILURE. 0x%x QID= 0x%x",
	//       'A'+port, errnoGet(), Status_Queue_Table[port].qid[lcl_index]);

	//     return (errnoGet());
	//  }
	//  lcl_index++;
	//}
	return (OK);
}





/*#########################################################################
	*
	* SYNOPSIS: Configure_NTDS_Device  (application)
	*
	*
	* DESCRIPTION: This function configures and initializes an interface to
	*                a specified device.
	*
	*                To communicate with the protocol tasks, the ntds_comm package
	*                uses queues which are created by this function.  The
	*              application determines the queues that may be created in
	*                addition to an output queue which is always created and input
	*                queues created by the 'Create_NTDS_Input_Q' function.
	*
	* PARAMETERS:
	*
	*     INPUT
	*       device_list_ptr :  This parameter is a pointer to a list of structures
	*                 that contain the information necessary for initializing a
	*                 device's channel.  The list may contain a single device or
	*                 list of devices.  The last entry in the list must have a
	*                 NULL entry.
	*
	*                 The parameters in this structure include the following
	*                 parameters:
	*
	*       id : The identification number of the device being initialized.
	*
	*       port : The hardware port that will be assigned to the device.
	*
	*       normal_port_address : The base VME address of the NTDS interface board
	*                              being used.
	*
	*       alternate_port_address : The base VSB address of the NTDS interface
	*                                board being used.
	*
	*                   NOTE : If a board does not respond at the VME address
	*                          the VSB base address will be used to attempt to
	*                          establish a communications link.
	*
	*       mode :  This parameter determines the NTDS mode of the interface.
	*               The options are:
	*                                COMPUTER
	*                                INTERCOMPUTER
	*                                PERIPHERIAL
	*
	*       interrupt_level :  The VME interrupt level that the interface
	*                          board will use to communicate response information
	*                          back to the host.
	*
	*       host_interrupt_level :  The VME interrupt level that this board will
	*                               use to communicate with the remote board that
	*                               is on the bus.
	*
	*       manual_ei_mode :   This parameter determines the method of accepting 
	*                          External Interrupts from the remote NTDS device.
	*                          The options are: AUTO_EI_MODE, MANUAL_EI_MODE.
	*
	*       word_size :  This parameter determines the word width of the NTDS
	*                         interface device.  The options are: W_16, W_32.
	*
	*       io_type :  This parameter determines the type of NTDS interface being
	*                  used.  The following choices are available: 
	*                                      NTDS_SLOW
	*                                      NTDS_FAST
	*                                      NTDS_ANEW
	*                                      NTDS_SERIAL
	*                                      NTDS_NATO_SERIAL
	*
	*       queues : This parameter contains information for creating
	*                           queues used by the application.  The application
	*                           has the option of creating an error queue and/or
	*                           a signal queue for receiving information from
	*                           the interface protocol package.  The following 
	*                           codes are used to enable the creation of queues:
	*
	*                                     NTDS_IN_SIGNAL_QUEUE
	*                                     NTDS_OUT_SIGNAL_QUEUE
	*                                     NTDS_PACKED_OUT_QUEUE
	*                                     BOTH_NTDS_SIGNAL_QUEUES
	*                                     ALL_NTDS_QUEUES
	*
	*        input_que_type :  This parameter determines the type of input message
	*                          queuing to be performed.  The options are:
	*                               QUEUE_RAW_INPUT_BUFFER or
	*                               QUEUE_INPUT_MESSAGES
	*
	*           NOTE:
	*
	*          The following parameters are pointers to functions
	*          that may be called by the application using the
	*          NTDS_Control function.
	*
	*       *init_comm_func :  This parameter is a pointer to the protocol
	*                          function that will be invoked when NTDS_Control
	*                          is called with an INITIALIZE_CHANNEL command code.
	*
	*       *enable_comm_func : This parameter is a pointer to the protocol
	*                           function that will be invoked when NTDS_Control
	*                           is called with an ENABLE_CHANNEL command code.
	*
	*       *disable_comm_func : This parameter is a pointer to the protocol
	*                            function that will be invoked when NTDS_Control
	*
	*       *reset_comm_func : This parameter is a pointer to the protocol
	*                          function that will be invoked when NTDS_Control
	*                          is called with a RESET_CHANNEL command code.
	*
	*       *restart_comm_func : This parameter is a pointer to the protocol
	*                            function that will be invoked when NTDS_Control
	*                            is called with a RESTART_CHANNEL command code.
	*
	*       *test_comm_func : This parameter is a pointer to the protocol
	*                         function that will be invoked when NTDS_Control
	*                         is called with an TEST_CHANNEL command code.
	*
	*   OUTPUT  NONE
	*
	*   RETURNS OK
	*           NO_MEMORY_POOL
	*           INVALID_CONFIGURATION
	*           VxWorks error code
	*
	* #########################################################################*/
int Configure_NTDS_Device (DEVICE_DATA *device_list_ptr)
{
	int return_code;
	int status;
	int i;
	//int j;

	unsigned int primary_adr_mod=0;
//  unsigned int secondary_adr_mod;
	unsigned int primary_address=0;
	unsigned int secondary_address;
	unsigned int primary_driver;
	unsigned int secondary_driver;

	DEVICE_DATA *device_ptr;

	//NIO_CONFIG real_board;
	int        device;
	int        port;

	return_code = OK;
	device_ptr = device_list_ptr;
	device = device_ptr->device_id;
	port = device_ptr->port;


	if (First_Time == TRUE)
	{
		/* Initialize the comm port monitor array. This should
		* initialize the number of ports + 1 because the counter
		* is the zeroth index
		*/
		Comm_Configured[0] = FALSE;
		for (i = 0; i < NUM_OF_NTDS_PORTS; i++)
		{
			Comm_Configured[i+1] = FALSE;
			Port_Device[i] = 0;
			}
				First_Time = FALSE;
			}
	status = OK;
	while ((device_ptr != NULL) && status == OK)
	{
		/* Check to make sure the port is in range and that the port has
		* not been initialized.  If we are doing dynamic reconfiguration,
		* we force a new port and it will become the normal port.
		*/
		if ((port < NUM_OF_NTDS_PORTS) && (!port_used (device, port)))
		{
			status = assign_port_to_device (device, port, device_ptr->redundant_channel_flag);
			if (status != OK)
				{
					Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
					"NTDS:Configure_NTDS_Device-Device=%d  Device table Full Norm=%d "
					"Alt=%d New=%d",
					device,
					Device_Ports[Get_Device_Index(device)].normal_port,
					Device_Ports[Get_Device_Index(device)].alternate_port,
					port);
					return (status);
						}
							/* Initialize the name string if the application hasn't */
							if (strcmp (device_config[port].name_string, "") == 0)
									{
										strcpy (device_config[port].name_string, "UNK");
											}
												/* Initialize the system function package.  Only do it if       */
												/* the port check was successful.                               */
												//   NTDS_Sys_Init (device_ptr);
												device_ptr->board.init_mode = LOCAL_INTERFACE;
												Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
												"NTDS:Configure_NTDS_Device-Device=%d  Found First Board "
												"at Address 0x%x", device,
												device_ptr->board.primary_ntds_port_address);
												Port_Device[port] = device;
												NTDS_Channel_Status[port] = CHANNEL_STATUS_UNKNOWN;
												/* Save the configuration data for use later. */
												device_config[port] = *device_ptr;
												/* If VSB is not used just do VME */
												//primary_adr_mod = VME_AM_EXT_USR_DATA;
												primary_address = device_ptr->board.primary_ntds_port_address;
												//secondary_adr_mod = VME_AM_EXT_USR_DATA;
												secondary_address = device_ptr->board.secondary_ntds_port_address;
												primary_driver = device_ptr->board.driver_type;
												secondary_driver = device_ptr->board.secondary_driver_type;
												device_ptr->board.primary_ntds_port_address = primary_address;
												device_ptr->board.secondary_ntds_port_address = secondary_address;
												device_ptr->board.address_modifier = primary_adr_mod;
												/* Update the driver type for configuration in
												* case there was a reversal.
												*/
												device_ptr->board.driver_type = primary_driver;
												device_ptr->board.secondary_driver_type = secondary_driver;
												/* This tells us if we tried to configure the port not
												* necessarily that we were successful.
												*/
												Comm_Configured[port+1] = TRUE;
												Report_Port_Status (port, CHANNEL_RESET);
												/* Add another port to the count */
												Comm_Configured[port+1] = TRUE;
												Comm_Configured[0]++;
												//***************************************************************************
												// Configure to use the Framework to do I/O to other units.
												queueFactory.createQueues(port, device_ptr->enet_port, device_ptr->name_string);
												//***************************************************************************
												}
													/*  Initialize global values   */
													device_ptr = device_ptr->next;
												}

	return (return_code);
}



/* #########################################################################
	*
	* Create_NTDS_Input_Q
	*
	* #########################################################################*/
int Create_NTDS_Input_Q(int device, unsigned int buffer_size, unsigned int n_buffers, 
						NTDS_MSG_TYPES *msg_type_list_ptr, NTDS_QUE_ID *index_ptr)

{
	return(0);
}


//#########################################################################
//
// SYNOPSIS:  NTDS_Status_Change_  (application)
//
//########################################################################
int
NTDS_Status_Change (
	int              device,
	NTDS_STATUS_MSGS *mesg_ptr,
	int              time_out
)
{
	return(CHANNEL_READY);
}

/*#########################################################################
	*
	* SYNOPSIS:  Get_NTDS_Buffer
	*
	* #########################################################################*/
char *
Get_NTDS_Buffer (
	unsigned int size,
	PART_ID      *partition_id
)
{
	char *address_ptr;

	*partition_id = NULL;
	if ((STATUS)(address_ptr = (char *) malloc (size)) == 0)
	{
		*partition_id = NULL;
		printf("\nntds_comm.c - Get_NTDS_Buffer - "
		"memPartAlloc FAILURE 0x%x Size = %d\n", errno, size);
	}
	return (address_ptr);
}


// #########################################################################
//
// Send_NTDS_Mesg
//
// #########################################################################
int Send_NTDS_Mesg (int device, NTDS_OUTPUT_MSGS* buffer_ptr, int priority)
{
	int status, port/*, xferSize*/;

	if (exitFlag == true)
	return(CHANNEL_READINESS_ERR);

	status = get_port (device, PRIMARY_PORT, &port);
	if ( (status != OK) || (port == NO_PRIMARY_PORT) )
	{
		if ( (status == OK) && (port == NO_PRIMARY_PORT) )
		{
			Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
			"NTDS:Send_NTDS_Mesg-Device=%d, Port=%c, There is no"
			" PRIMARY port configured for this device.",
			device, 'A'+port);
			return (INVALID_DEVICE);
			}
			}
	if (status != OK)
	return(status);

	//**********************************************************************************************************
	// Framework Publish Code.

	// Convert input ticks to microseconds.
	double microSecs = ((double)buffer_ptr->io_pkt.time_out) * NTDS_TICKS_TO_MICROSECS;

	// Drop the message in the Queue to the framework.
	if (publishQueue[port]->timedAddMessage((unsigned char*)buffer_ptr->io_pkt.address, 
	buffer_ptr->io_pkt.req_size*Get_NTDS_Word_Size(device), 0, (unsigned long)microSecs ) == true)
	return(OK);
	else
	return (CHANNEL_READINESS_ERR);
	//**********************************************************************************************************
}



// #########################################################################
//
// Recv_NTDS_Mesg
//
// #########################################################################
int Recv_NTDS_Mesg (int device, NTDS_QUE_ID lcl_index, NTDS_INPUT_MSGS *buffer_ptr, int timeout)
{
	int          port;
	int          status;
	//double       microSecs;

	if (exitFlag == true)
	return(CHANNEL_READINESS_ERR);

	buffer_ptr->io_pkt.address = (unsigned int*)&buffer;

/* Get logical device assignment */

	status = get_port (device, NORMAL_PORT, &port);
	if ( (status != OK) || (port == NO_NORMAL_PORT) )
	{
		if ( (status == OK) && (port == NO_NORMAL_PORT) )
		{
			Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
			"NTDS:Recv_NTDS_Mesg-Device=%d, Port=%c, There is no"
			" NORMAL port configured for this device.",
			device, 'A'+port);
			return (INVALID_DEVICE);
			}
			}
	if (status != OK)
	{
		Log_NTDS_Mesg (device, NTDS_ERROR_CAT, "NTDS:Recv_NTDS_Mesg-Port=%c, "
		"UNKNOWN DEVICE", 'A'+port);
		return (status);
	}
	if (Comm_Configured[port+1] != TRUE)
	{
		Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
		"NTDS:Recv_NTDS_Mesg-Port=%c  Device is NOT Configured",
		'A'+port);
		return (DEVICE_NOT_CONFIGURED);
	}
	//*********************************************************************************************************
	// Framework Subscribe Code

	if (timeout == WAIT_FOREVER)
	{
		while (exitFlag == false)
		{
			// Sit on Queue waiting for the next message from the framework.
			if (subscribeQueue[port]->timedGetMessage((unsigned char*)buffer_ptr->io_pkt.address, &buffer_ptr->io_pkt.tfr_size, 0, 10000)  == true)
			return(OK);
			};
			}
				else
					{
						// Attempt to read a message.
						if (subscribeQueue[port]->timedGetMessage((unsigned char*)buffer_ptr->io_pkt.address, &buffer_ptr->io_pkt.tfr_size, 0, 
						((unsigned long)((double)buffer_ptr->io_pkt.time_out) * NTDS_TICKS_TO_MICROSECS))  == true)
						return(OK);
						else
						return (CHANNEL_READINESS_ERR);
						}
							return (CHANNEL_READINESS_ERR);
							*
							* SYNOPSIS: Send_NTDS_Mesg_To_Port   (application)
							*
							* DESCRIPTION:     This function queues an output request to the specified
							*                port queue.  The caller provides the port id, a buffer
							*                descriptor, and a queuing priority.
							*
							*                The buffer descriptor is of an NTDS_OUTPUT_MSGS type containing
							*                the starting address of the message, and the length of the
							*                message. It also includes the buffer partition_id.
							*
							*                   The caller determines how the output request will be queued
							*                by setting the priority parameter to either MSG_PRI_NORMAL
							*                or MSG_PRI_URGENT.  If the priority is set to MSG_PRI_NORMAL,
							*                the output request is placed at the end of the output queue.
							*                If the priority is set to MSG_PRI_URGENT, the output request
							*                is placed at the front of the queue.
							*
							*                   The protocol output task is expected to dequeue the
							*                output messages by calling the Deque_NTDS_Output_Mesg
							*                function.
							*
							* PARAMETERS:
							*
							*    INPUT   port    :    This parameter contains the logical unit number of
							*                        the port being used.
							*
							*        *buffer_ptr :    This parameter contains a pointer to the message
							*                        buffer of type NTDS_OUTPUT_MSGS.
							*
							*                     The following fields are passed to the application in the
							*                     buffer parameter:
							*
							*        io_pkt  : This field is a structure of information required for
							*                  performing the buffer transfer.
							*
							*        partition_id : This field contains the partition_id of the
							*                       buffer.  This allows the protocol task to return
							*                       the buffer to the proper partition when partitions
							*                       are being used. When malloc is being used this
							*                       field should be NULL.
							*
							*        status : This field contains a pointer to the status buffer that
							*            will be used by the protocol to save the transfer status.  This
							*            field is only used if the "confirm" flag is set.  Likewise, if the
							*            "confirm" flag is set a valid pointer must be provided.  If the
							*            "confirm" flag is false the status pointer should be NULL.
							*
							*        confirm : This field determines if the protocol task should return a
							*            status to the application.  If the flag is "TRUE" a valid status
							*            pointer must be provided.  There are two possibilities for this
							*            field  (TRUE, FALSE).
							*
							*        free_buffer : This field determines if the protocol should free the
							*            buffer being sent.  There are two possibilities for this field.
							*            (TRUE, FALSE)
							*
							*              priority :    This parameter contains the priority at which the
							*             message buffer will be placed into the output
							*             queue.  If the priority is set to MSG_PRI_NORMAL,
							*             the message will be put at the end of the queued
							*             message list.  If the priority is set to
							*             MSG_PRI_URGENT the message will be placed at the
							*             front of the list.
							*
							*   OUTPUT  NONE
							*
							*   RETURNS OK
							*           NOT_LONG_ALIGNED
							*           DEVICE_NOT_CONFIGURED
							*           CHANNEL_READINESS_ERR
							*           FUNCTION_NOT_IMPLEMENTED
							*           NO_STATUS_BUFFER
							*
							*           subordinate function returns
							*           VxWorks error code
							*
							*########################################################################*/
							int                  port,
							NTDS_OUTPUT_MSGS   * buffer_ptr,
							int                  priority
							return(0);
							*
							* SYNOPSIS: Send_NTDS_Mesg_Block   (application)
							*
							* DESCRIPTION:    This function queues a mesg block for output to the specified
							*                device queue.  The caller provides the device id, a buffer
							*                descriptor, and a queuing priority.
							*
							*                The buffer descriptor is of a NTDS_OUTPUT_MSGS type containing
							*                the starting address of the message, and the length of the
							*                message. It also includes the buffer partition_id.
							*
							*                   The caller determines how the output request will be queued
							*                by setting the priority parameter to either MSG_PRI_NORMAL
							*                or MSG_PRI_URGENT.  If the priority is set to MSG_PRI_NORMAL,
							*                the output request is placed at the end of the output queue.
							*                If the priority is set to MSG_PRI_URGENT, the output request
							*                is placed at the front of the queue.
							*
							*                   The protocol output task is expected to dequeue the
							*                output messages by calling the Deque_NTDS_Output_Mesg_Block
							*                function.
							*
							* PARAMETERS:
							*
							*    INPUT   device  :    This parameter contains the logical unit number of
							*                        the device being used.
							*
							*        *buffer_ptr :    This parameter contains a pointer to the message
							*                        buffer of type NTDS_OUTPUT_MSGS.
							*
							*                     The following fields are passed to the application in the
							*                     buffer parameter:
							*
							*        io_pkt  : This field is a structure of information required for
							*                  performing the buffer transfer.
							*
							*   partition_id : This field contains the partition_id of the
							*                  buffer.  This allows the protocol task to return
							*                  the buffer to the proper partition when partitions
							*                  are being used. When malloc is being used this
							*                  field should be NULL.
							*
							*        status : This field contains a pointer to the status buffer that
							*            will be used by the protocol to save the transfer status.  This
							*            field is only used if the "confirm" flag is set.  Likewise, if the
							*            "confirm" flag is set a valid pointer must be provided.  If the
							*            "confirm" flag is false the status pointer should be NULL.
							*
							*        confirm : This field determines if the protocol task should return a
							*            status to the application.  If the flag is "TRUE" a valid status
							*            pointer must be provided.  There are two possibilities for this
							*            field  (TRUE, FALSE).
							*
							*        free_buffer : This field determines if the protocol should free the
							*            buffer being sent.  There are two possibilities for this field.
							*            (TRUE, FALSE)
							*
							*              priority :    This parameter contains the priority at which the
							*             message buffer will be placed into the output
							*             queue.  If the priority is set to MSG_PRI_NORMAL,
							*             the message will be put at the end of the queued
							*             message list.  If the priority is set to
							*             MSG_PRI_URGENT the message will be placed at the
							*             front of the list.
							*
							*   OUTPUT  NONE
							*
							*   RETURNS OK
							*           NOT_LONG_ALIGNED
							*           DEVICE_NOT_CONFIGURED
							*           CHANNEL_READINESS_ERR
							*           FUNCTION_NOT_IMPLEMENTED
							*           NO_STATUS_BUFFER
							*
							*           subordinate function returns
							*           VxWorks error code
							*
							* ########################################################################*/
							int                device,
							NTDS_OUTPUT_MSGS   * buffer_ptr,
							int                priority
							return(0);
							*
							* SYNOPSIS:       Recv_NTDS_Signal   (application)
							*
							* DESCRIPTION:    This function returns a special event signal from the
							*                 selected device.  The caller determines if it will wait for
							*                 a signal response by setting the time_out variable.
							*
							*                    It is expected that the interface protocol will place
							*                 detected signals in the signal queue by calling the
							*                 Report_NTDS_Signal function.
							*
							* PARAMETERS:
							*
							*    INPUT  device :   This parameter contains the logical unit number of the
							*                    device being monitored.
							*
							*         signal_ptr :   A pointer the variable that will hold the updated
							*                      signal information.
							*
							*         time_out :   This parameter determines how long the caller will
							*                      wait for a message to be received before declaring
							*                      an input failure.  The time_out can also be specified
							*                      as NO_WAIT or WAIT_FOREVER.
							*
							*    OUTPUT :
							*
							*        *signal_ptr :  This parameter contains the following updated
							*                     information if the timeout did not occur; otherwise
							*                     the values are zero.
							*
							*                   event_ptr:     This parameter is a pointer to the
							*                                  variable that will contain the signal
							*                                  status.  The actual status that is
							*                                  transferred is dependent on the application.
							*
							*                   time_ptr:      This parameter is a pointer to the
							*                                  variable that will contain the time the
							*                                  signal status was detected.
							*
							* RETURNS   OK
							*           DEVICE_NOT_CONFIGURED
							*           VxWorks error status
							*
							* #########################################################################*/
							int              device,
							NTDS_SIGNAL_MSGS *signal_ptr,
							int              timeout
														return(0);
							*
							* SYNOPSIS:  Send_NTDS_Signal    (application)
							*
							* DESCRIPTION:       This function routes a signal code to the protocol for
							*                 processing.  The protocol is expected to remove the
							*                 signal entry by calling the Deque_Output_Signal function.
							*
							* PARAMETERS:
							*
							*     INPUT :
							*
							*         device :   This variable determines which devices's signal queue
							*                    will receive the signal code.
							*
							*       signal_ptr :   A pointer the variable that will hold the updated
							*                    signal information.
							*
							*                   event :   This parameter is the variable that contains
							*                             the signal value.  The actual value that is
							*                             transferred is dependent on the application.
							*
							*                   time  :   This parameter is the variable that contains
							*                             the time that the signal was sent.  The use of
							*                             this values is application dependent.
							*
							*     OUTPUT     NOTHING
							*
							*     RETURNS  OK
							*              DEVICE_NOT_CONFIGURED
							*              vxWorks error code
							*
							*#########################################################################*/
							int              device,
							NTDS_SIGNAL_MSGS *signal_ptr
							return(0);
							*
							* SYNOPSIS:         Recv_NTDS_Error (application)
							*
							* DESCRIPTION:       Returns an error message from the selected device.  The
							*                 caller determines if it will wait for an error response.
							*                 If the caller sets the wait option, the timeout parameter
							*                 will be used to determine how long the caller will wait.
							*
							*                 It is expected that the interface protocol will place
							*                 detected errors in the queue by calling the Report_NTDS_Error
							*                 function.
							*
							* PARAMETERS:
							*
							*    INPUT :
							*         device :   This parameter contains the logical unit number of the
							*                    device being monitored.
							*
							*       error_ptr:   A pointer the variable that will hold the updated
							*                    error information.
							*
							*                   *event_ptr :   This parameter is a pointer to the
							*                                  variable that will contain the error
							*                                  status.  The actual status that is
							*                                  transferred is dependent on the application.
							*
							*                   *time_ptr  :   This parameter is a pointer to the
							*                                  variable that will contain the time the
							*                                  error status was detected.
							*
							*            time_out :   This parameter determines how long the caller will
							*                       wait for a message to be received before declaring
							*                       an input failure.  The time_out can also be specified
							*                       as NO_WAIT or WAIT_FOREVER.
							*
							*    OUTPUT :
							*
							*       error_ptr :   A pointer the variable that will hold the updated
							*                    error information.
							*
							*                   *event_ptr :   This parameter is a pointer to the
							*                                  variable that will contain the error
							*                                  status.  The actual status that is
							*                                  transferred is dependent on the application.
							*
							*                   *time_ptr  :   This parameter is a pointer to the
							*                                  variable that will contain the time the
							*                                  error status was detected.
							*
							* RETURNS   OK
							*           DEVICE_NOT_CONFIGURED
							*           VxWorks error status
							*
							* #########################################################################*/
							int             device,
							NTDS_ERROR_MSGS *mesg_ptr,
							int             timeout
							//return( local_recv_ntds_error(device, PRIMARY_PORT, mesg_ptr, timeout) );
							return(0);
							*
							* SYNOPSIS:       Recv_Secondary_NTDS_Error   (application)
							*
							* DESCRIPTION:       Returns an error message from the selected device's
							*                 secondary port.  The caller determines if it will wait for
							*                 an error response.  If the caller sets the wait option, the
							*                 timeout parameter will be used to determine how long the
							*                 caller will wait.
							*
							*                 It is expected that the interface protocol will place
							*                 detected errors in the queue by calling the Report_NTDS_Error
							*                 function.
							*
							*                 This function is typically called by interfaces that use
							*                 redundant channels.  Typically, both channels are maintaining
							*                 an interface by passing protocol messages.  Only one of the
							*                 channels is actually sending and receiving messages.  It is
							*                 the application's responsibility to determine which channel
							*                 is the primary channel (NORMAL_PORT).  The function
							*                 _Ports performs the actual swapping if 
							*                 channels.
							*
							* PARAMETERS:
							*
							*    INPUT :
							*         device :   This parameter contains the logical unit number of the
							*                    device being monitored.
							*
							*       error_ptr:   A pointer the variable that will hold the updated
							*                    error information.
							*
							*                   *event_ptr :   This parameter is a pointer to the
							*                                  variable that will contain the error
							*                                  status.  The actual status that is
							*                                  transferred is dependent on the application.
							*
							*                   *time_ptr  :   This parameter is a pointer to the
							*                                  variable that will contain the time the
							*                                  error status was detected.
							*
							*            time_out :   This parameter determines how long the caller will
							*                       wait for a message to be received before declaring
							*                       an input failure.  The time_out can also be specified
							*                       as NO_WAIT or WAIT_FOREVER.
							*
							*    OUTPUT :
							*
							*       error_ptr :   A pointer the variable that will hold the updated
							*                    error information.
							*
							*                   *event_ptr :   This parameter is a pointer to the
							*                                  variable that will contain the error
							*                                  status.  The actual status that is
							*                                  transferred is dependent on the application.
							*
							*                   *time_ptr  :   This parameter is a pointer to the
							*                                  variable that will contain the time the
							*                                  error status was detected.
							*
							* RETURNS   OK
							*           DEVICE_NOT_CONFIGURED
							*           VxWorks error status
							*
							* #########################################################################*/
							int             device,
							NTDS_ERROR_MSGS *mesg_ptr,
							int             timeout
														//return( local_recv_ntds_error(device, SECONDARY_PORT, mesg_ptr, timeout) );
							return(0);
							*
							* SYNOPSIS:  Get_NTDS_Port    (application)
							*
							* DESCRIPTION:    The Get_NTDS_Port function finds the current low
							*                 level port that is mapped to the selected device.
							*
							* PARAMETERS:
							*
							*    INPUT   device :  This parameter contains the logical unit number of
							*                      the device being used.
							*
							*    OUTPUT  NOTHING
							*
							*
							* RETURNS  The device's current port.
							*          INVALID_DEVICE  If a valid port could not be found.
							*
							*#########################################################################*/
							int device
							status = get_port (device, PRIMARY_PORT, &port);
							if ( (status != OK) || (port == NO_PRIMARY_PORT) )
								{
									if ( (status == OK) && (port == NO_PRIMARY_PORT) )
											{
												status = get_port (device, SECONDARY_PORT, &port);
												if ( (status != OK) || (port == NO_SECONDARY_PORT) )
															{
																if ( (status == OK) && (port == NO_SECONDARY_PORT) )
																				{
																					Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
																					"NTDS:Get_NTDS_Port-Device=%d, Port=%c, There is no"
																					" PRIMARY or SECONDARY port configured for this device.",
																					device, 'A'+port);
																					return (INVALID_DEVICE);
																								}
																											}
																													}
																														}
																															if (status != OK)
																															return (status);
																															else
																															return (port);
																															*
																															* SYNOPSIS:  Get_NTDS_Word_Size    (application)
																															*
																															* DESCRIPTION:    The Get_NTDS_Word_Size function returns the interface's
																															*                 word size as defined in the IDS.
																															*
																															* PARAMETERS:
																															*
																															*    INPUT   device :  This parameter contains the logical unit number of
																															*                      the device being used.
																															*
																															*    OUTPUT  NOTHING
																															*
																															*
																															* RETURNS  The device's word_size.
																															*          INVALID_DEVICE  If a valid port could not be found.
																															*
																															*#########################################################################*/
																															int device
																																																														status = get_port (device, PRIMARY_PORT, &port);
																															if ( (status != OK) || (port == NO_PRIMARY_PORT) )
																																{
																																	if ( (status == OK) && (port == NO_PRIMARY_PORT) )
																																			{
																																				status = get_port (device, SECONDARY_PORT, &port);
																																				if ( (status != OK) || (port == NO_SECONDARY_PORT) )
																																							{
																																								if ( (status == OK) && (port == NO_SECONDARY_PORT) )
																																												{
																																													Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
																																													"NTDS:Get_NTDS_Word_Size-Device=%d, Port=%c, There is no"
																																													" PRIMARY or SECONDARY port configured for this device.",
																																													device, 'A'+port);
																																													return ((unsigned int)INVALID_DEVICE);
																																																}
																																																			}
																																																					}
																																																						}
																																																							if (status != OK)
																																																								{
																																																									return (status);
																																																									}
																																																										else
																																																											{
																																																												return (device_config[port].board.word_size);
																																																												}
																																																													*
																																																													* SYNOPSIS:  Get_Interface_Status    (application)
																																																													*
																																																													* DESCRIPTION:    The Get_Interface_Status function returns one of two values
																																																													*                 to the caller.  Either the "Interface_Down_Status" or the
																																																													*                 "Interface_Up_Status".  If there is no viable channel
																																																													*                 operating for the "device", then "Interface_Down_Status" is
																																																													*                 returned.  If at least one channel is viable,
																																																													*                 "Interface_Up_Status" is returned.
																																																													*
																																																													* PARAMETERS:
																																																													*
																																																													*    INPUT   device :  number associated with the piece of hardware on the
																																																													*                      other side of the interface.
																																																													*            Interface_Up_Status : value that's returned if at least one
																																																													*                      channel to the device is viable.
																																																													*            Interface_Down_Status : value that's returned if there is NO
																																																													*                      viable channel to the device is viable.
																																																													*
																																																													*    OUTPUT  NOTHING
																																																													*
																																																													*
																																																													* RETURNS  The Interface status.
																																																													*
																																																													*
																																																													*#########################################################################*/
																																																													int Device,
																																																													int Interface_Down_Status,
																																																													int Interface_Up_Status
																																																													int Index = Get_Device_Index(Device);
																																																													if (Get_Port_Status (Device_Ports[Index].normal_port) < CHANNEL_READY)
																																																														{
																																																															/* Make sure that there IS an alternate port before using it in a call    */
																																																															/* to Get_Port_Status.                                                    */
																																																															if (Device_Ports[Index].alternate_port == NO_SECONDARY_PORT)
																																																																	{
																																																																		return(Interface_Down_Status);
																																																																			}
																																																																				if (Get_Port_Status (Device_Ports[Index].alternate_port) < CHANNEL_READY)
																																																																						{
																																																																							return(Interface_Down_Status);
																																																																								}
																																																																									else
																																																																											{
																																																																												return(Interface_Up_Status);
																																																																													}
																																																																														}
																																																																															else
																																																																																{
																																																																																	return(Interface_Up_Status);
																																																																																	}
																																																																																		*
																																																																																		* SYNOPSIS:  Get_Port_Characteristic    (application)
																																																																																		*
																																																																																		* DESCRIPTION:    The Get_Port_Characteristic function returns one of two values
																																																																																		*                 to the caller.  Either the Primary Port's characteristic or the
																																																																																		*                 Secondary port's characteristic, depending if the input port
																																																																																		*                 identifier is the Primary or Secondary port for the device.
																																																																																		*
																																																																																		* PARAMETERS:
																																																																																		*
																																																																																		*    INPUT   device :  number associated with the piece of hardware on the
																																																																																		*                      other side of the interface.
																																																																																		*            Primary_Port_Characteristic : value that's returned if the input
																																																																																		*                      port identifier is the Primary port for the device.
																																																																																		*            Secondary_Port_Characteristic : value that's returned if the input
																																																																																		*                      port identifier is the Secondary port for the device.
																																																																																		*
																																																																																		*    OUTPUT  NOTHING
																																																																																		*
																																																																																		*
																																																																																		* RETURNS  The appropriate characteristic value.
																																																																																		*
																																																																																		*
																																																																																		*#########################################################################*/
																																																																																		int Device,
																																																																																		int Port,
																																																																																		int Primary_Port_Characteristic,
																																																																																		int Secondary_Port_Characteristic
																																																																																		if ( Port == Device_Ports[Get_Device_Index(Device)].primary_port )
																																																																																		return(Primary_Port_Characteristic);
																																																																																		else
																																																																																		return(Secondary_Port_Characteristic);
																																																																																		*
																																																																																		* SYNOPSIS:  Get_Channel_ID    (application)
																																																																																		*
																																																																																		* DESCRIPTION:    The Get_Channel_ID function determines if the input "port"
																																																																																		*                 parameter is the "Primary" or "Secondary" port for
																																																																																		*                 its associated device.  The return value is a Channel ID
																																																																																		*                 value associated with either the Primary or Secondary channel.
																																																																																		*
																																																																																		* PARAMETERS:
																																																																																		*
																																																																																		*    INPUT   port :  This parameter contains the port number assigned to a
																																																																																		*                    particular instance of a protocol which is servicing a
																																																																																		*                    particular device.
																																																																																		*
																																																																																		*    OUTPUT  NOTHING
																																																																																		*
																																																																																		*
																																																																																		* RETURNS  The port's associated "Channel ID".
																																																																																		*
																																																																																		*
																																																																																		*#########################################################################*/
																																																																																		int port
																																																																																		if ( port == Get_Normal_NTDS_Port( Get_Device_Id(port) ) )
																																																																																		return(NORMAL_CHANNEL);
																																																																																		else
																																																																																		return(ALTERNATE_CHANNEL);
																																																																																		*
																																																																																		* SYNOPSIS:  Get_Primary_NTDS_Port    (application)
																																																																																		*
																																																																																		* DESCRIPTION:    The Get_Primary_NTDS_Port function finds the primary low
																																																																																		*                 level port that is mapped to the selected device.
																																																																																		*
																																																																																		* PARAMETERS:
																																																																																		*
																																																																																		*    INPUT   device :  This parameter contains the logical unit number of
																																																																																		*                      the device being used.
																																																																																		*
																																																																																		*    OUTPUT  NOTHING
																																																																																		*
																																																																																		*
																																																																																		* RETURNS  The device's primary port.
																																																																																		*          INVALID_DEVICE  If a valid port could not be found.
																																																																																		*
																																																																																		*#########################################################################*/
																																																																																		int device
																																																																																		status = get_port (device, PRIMARY_PORT, &port);
																																																																																		if ( (status != OK) || (port == NO_PRIMARY_PORT) )
																																																																																			{
																																																																																				if ( (status == OK) && (port == NO_PRIMARY_PORT) )
																																																																																						{
																																																																																							Log_NTDS_Mesg (device, NTDS_STATUS_CAT,
																																																																																							"NTDS:Get_Primary_NTDS_Port-Device=%d, Port=%c, There is no"
																																																																																							" PRIMARY port configured for this device.",
																																																																																							device, 'A'+port);
																																																																																							return (INVALID_DEVICE);
																																																																																								}
																																																																																									}
																																																																																										if (status != OK)
																																																																																										return (status);
																																																																																										else
																																																																																										return (port);
																																																																																										*
																																																																																										* SYNOPSIS:  Get_Secondary_NTDS_Port    (application)
																																																																																										*
																																																																																										* DESCRIPTION:    The Get_Secondary_NTDS_Port function finds the secondary low
																																																																																										*                 level port that is mapped to the selected device.
																																																																																										*
																																																																																										* PARAMETERS:
																																																																																										*
																																																																																										*    INPUT   device :  This parameter contains the logical unit number of
																																																																																										*                      the device being used.
																																																																																										*
																																																																																										*    OUTPUT  NOTHING
																																																																																										*
																																																																																										*
																																																																																										* RETURNS  The device's secondary port.
																																																																																										*          INVALID_DEVICE  If a valid port could not be found.
																																																																																										*
																																																																																										*#########################################################################*/
																																																																																										int device
																																																																																																																																																																																				int port;
																																																																																										int status;
																																																																																										status = get_port (device, SECONDARY_PORT, &port);
																																																																																										if ( (status != OK) || (port == NO_SECONDARY_PORT) )
																																																																																											{
																																																																																												if ( (status == OK) && (port == NO_SECONDARY_PORT) )
																																																																																														{
																																																																																															Log_NTDS_Mesg (device, NTDS_STATUS_CAT,
																																																																																															"NTDS:Get_Secondary_NTDS_Port-Device=%d, Port=%c, There is no"
																																																																																															" SECONDARY port configured for this device.",
																																																																																															device, 'A'+port);
																																																																																															return (INVALID_DEVICE);
																																																																																																}
																																																																																																	}
																																																																																																		if (status != OK)
																																																																																																		return (status);
																																																																																																		else
																																																																																																		return (port);
																																																																																																		*
																																																																																																		* SYNOPSIS:  Get_Normal_NTDS_Port    (application)
																																																																																																		*
																																																																																																		* DESCRIPTION:    The Get_NTDS_Port function finds the "normal" low 
																																																																																																		*                 level port that is mapped to the selected device.
																																																																																																		*
																																																																																																		* PARAMETERS:
																																																																																																		*
																																																																																																		*    INPUT   device :  This parameter contains the logical unit number of
																																																																																																		*                      the device being used.
																																																																																																		*
																																																																																																		*    OUTPUT  NOTHING
																																																																																																		*
																																																																																																		*
																																																																																																		* RETURNS  The device's secondary port.
																																																																																																		*          INVALID_DEVICE  If a valid port could not be found.
																																																																																																		*
																																																																																																		*#########################################################################*/
																																																																																																		int device
																																																																																																																																																																																																				int port;
																																																																																																		int status;
																																																																																																		status = get_port (device, NORMAL_PORT, &port);
																																																																																																		if ( (status != OK) || (port == NO_NORMAL_PORT) )
																																																																																																			{
																																																																																																				if ( (status == OK) && (port == NO_NORMAL_PORT) )
																																																																																																						{
																																																																																																							Log_NTDS_Mesg (device, NTDS_STATUS_CAT,
																																																																																																							"NTDS:Get_Normal_NTDS_Port-Device=%d, Port=%c, There is no"
																																																																																																							" NORMAL port configured for this device.",
																																																																																																							device, 'A'+port);
																																																																																																							return (INVALID_DEVICE);
																																																																																																								}
																																																																																																									}
																																																																																																										if (status != OK)
																																																																																																										return (status);
																																																																																																										else
																																																																																																										return (port);
																																																																																																										*
																																																																																																										* SYNOPSIS:  Get_Alternate_NTDS_Port    (application)
																																																																																																										*
																																																																																																										* DESCRIPTION:    The Get_NTDS_Port function finds the alternate low 
																																																																																																										*                 level port that is mapped to the selected device.
																																																																																																										*
																																																																																																										* PARAMETERS:
																																																																																																										*
																																																																																																										*    INPUT   device :  This parameter contains the logical unit number of
																																																																																																										*                      the device being used.
																																																																																																										*
																																																																																																										*    OUTPUT  NOTHING
																																																																																																										*
																																																																																																										*
																																																																																																										* RETURNS  The device's secondary port.
																																																																																																										*          INVALID_DEVICE  If a valid port could not be found.
																																																																																																										*
																																																																																																										*#########################################################################*/
																																																																																																										int device
																																																																																																																																																																																																																				status = get_port (device, ALTERNATE_PORT, &port);
																																																																																																										if ( (status != OK) || (port == NO_ALTERNATE_PORT) )
																																																																																																											{
																																																																																																												if ( (status == OK) && (port == NO_ALTERNATE_PORT) )
																																																																																																														{
																																																																																																															Log_NTDS_Mesg (device, NTDS_STATUS_CAT,
																																																																																																															"NTDS:Get_Alternate_NTDS_Port-Device=%d, Port=%c, There is no"
																																																																																																															" ALTERNATE port configured for this device.",
																																																																																																															device, 'A'+port);
																																																																																																															return (INVALID_DEVICE);
																																																																																																																}
																																																																																																																	}
																																																																																																																		if (status != OK)
																																																																																																																		return (status);
																																																																																																																		else
																																																																																																																		return (port);
																																																																																																																		*
																																																																																																																		* SYNOPSIS:  Get_NTDS_Port_Status    (application)
																																																																																																																		*
																																																																																																																		* DESCRIPTION:    The Get_NTDS_Port_Status function returns the current status
																																																																																																																		*                 of a particular port.
																																																																																																																		*
																																																																																																																		* PARAMETERS:
																																																																																																																		*
																																																																																																																		*    INPUT   port :     This parameter contains the logical unit number of
																																																																																																																		*                      the port being used.
																																																																																																																		*
																																																																																																																		*    OUTPUT  NOTHING
																																																																																																																		*
																																																																																																																		*
																																																																																																																		* RETURNS PORT_STATUS
																																																																																																																		*         PORT_STATUS_UNKNOWN
																																																																																																																		*
																																																																																																																		*#########################################################################*/
																																																																																																																		int port
																																																																																																																		int status;
																																																																																																																		if ((port >= 0) && (port < NUM_OF_NTDS_PORTS) )
																																																																																																																		status = NTDS_Channel_Status[port];
																																																																																																																		else
																																																																																																																			{
																																																																																																																				Log_NTDS_Mesg (Get_Device_Id(port), NTDS_STATUS_CAT,
																																																																																																																				"NTDS:NTDS_Status-Port=%d, UNKNOWN PORT", port);
																																																																																																																				status = PORT_STATUS_UNKNOWN;
																																																																																																																				}
																																																																																																																					return (status);
																																																																																																																					*
																																																																																																																					* SYNOPSIS:  Check_NTDS_Block_Que    (protocol)
																																																																																																																					*
																																																																																																																					* DESCRIPTION:    The Check_NTDS_Block_Que function checks the NTDS Blocked
																																																																																																																					*                 message queue for messages waiting to be sent.  The
																																																																																																																					*                 number of messages waiting to be sent is returned to the
																																																																																																																					*                 caller.
																																																																																																																					*
																																																																																																																					* PARAMETERS:
																																																																																																																					*
																																																																																																																					*    INPUT   port :     This parameter contains the logical unit number of
																																																																																																																					*                      the port being used.
																																																																																																																					*
																																																																																																																					*    OUTPUT  NOTHING
																																																																																																																					*
																																																																																																																					*
																																																																																																																					* RETURNS 0     = No Messages waiting
																																																																																																																					*         Non 0 = Messages in Queue
																																																																																																																					*         BAD_PORT_ID
																																																																																																																					*
																																																																																																																					*#########################################################################*/
																																																																																																																					int port
																																																																																																																																																																																																																																										//   /* Validate the port to be in range at least */
																																																																																																																					//if (((port < 0) || (port >= NUM_OF_NTDS_PORTS)) || 
																																																																																																																					//(Comm_Configured[port+1] != TRUE))
																																																																																																																					//
																																																																																																																				{
																																																																																																																					//  Log_NTDS_Mesg (Get_Device_Id(port), NTDS_ERROR_CAT,
																																																																																																																					//    "NTDS:Check_NTDS_Block_Que-Port=%c Unkown/Unconfigured Port",
																																																																																																																					//    'A'+port);
																																																																																																																					//  return (BAD_PORT_ID);
																																																																																																																					//}
																																																																																																																					//else
																																																																																																																					//
																																																																																																																				{
																																																																																																																					//  return (msgQNumMsgs (Queue_Table[port][NTDS_PACKED_OUT_QUE]));
																																																																																																																					//}
																																																																																																																					return(OK);
																																																																																																																					*
																																																																																																																					* SYNOPSIS:  Check_NTDS_Output_Que    (protocol)
																																																																																																																					*
																																																																																																																					* DESCRIPTION:    The Check_NTDS_Output_Que function checks the NTDS output
																																																																																																																					*                 message queue for messages waiting to be sent.  The
																																																																																																																					*                 number of messages waiting to be sent is returned to the
																																																																																																																					*                 caller.
																																																																																																																					*
																																																																																																																					* PARAMETERS:
																																																																																																																					*
																																																																																																																					*    INPUT   port :     This parameter contains the logical unit number of
																																																																																																																					*                      the port being used.
																																																																																																																					*
																																																																																																																					*    OUTPUT  NOTHING
																																																																																																																					*
																																																																																																																					*
																																																																																																																					* RETURNS 0     = No Messages waiting
																																																																																																																					*         Non 0 = Messages in Queue
																																																																																																																					*         BAD_PORT_ID
																																																																																																																					*
																																																																																																																					*#########################################################################*/
																																																																																																																					int port
																																																																																																																																																																																																																																										//   /* Validate the port to be in range at least */
																																																																																																																					//if (((port >= 0) && (port < NUM_OF_NTDS_PORTS)) &&
																																																																																																																					//    (Comm_Configured[port+1] != TRUE))
																																																																																																																					//
																																																																																																																				{
																																																																																																																					//   return (msgQNumMsgs (Queue_Table[port][NTDS_OUTPUT_QUE]));
																																																																																																																					//}
																																																																																																																					//else
																																																																																																																					//
																																																																																																																				{
																																																																																																																					//  Log_NTDS_Mesg (Get_Device_Id(port), NTDS_ERROR_CAT,
																																																																																																																					//    "NTDS:Check_NTDS_Output_Que-Port=%c  Unkown/Unconfigured Port",
																																																																																																																					//    'A'+port);
																																																																																																																					//  return (BAD_PORT_ID);
																																																																																																																					//}
																																																																																																																					return(OK);
																																																																																																																					*
																																																																																																																					* SYNOPSIS:  NTDS_Status    (application)
																																																																																																																					*
																																																																																																																					* DESCRIPTION:    The NTDS_Status function returns the current status of the
																																																																																																																					*                 interface.  It is the responsbility of the protocol
																																																																																																																					*                 interface to keep the NTDS_Channel_Status updated to
																																																																																																																					*                 provide a timely status.  This can be accomplished
																																																																																																																					*                 by calling the Report_Port_Status function.
																																																																																																																					*
																																																																																																																					* PARAMETERS:
																																																																																																																					*
																																																																																																																					*    INPUT   device :     This parameter contains the logical unit number of
																																																																																																																					*                      the device being used.
																																																																																																																					*
																																																																																																																					*    OUTPUT  NOTHING
																																																																																																																					*
																																																																																																																					*
																																																																																																																					* RETURNS CHANNEL_STATUS
																																																																																																																					*         CHANNEL_STATUS_UNKNOWN
																																																																																																																					*
																																																																																																																					*#########################################################################*/
																																																																																																																					int device
																																																																																																																					int port;
																																																																																																																					int status;
																																																																																																																					status = get_port (device, PRIMARY_PORT, &port);
																																																																																																																					if ( (status != OK) || (port == NO_PRIMARY_PORT) )
																																																																																																																						{
																																																																																																																							if ( (status == OK) && (port == NO_PRIMARY_PORT) )
																																																																																																																									{
																																																																																																																										status = get_port (device, SECONDARY_PORT, &port);
																																																																																																																										if ( (status != OK) || (port == NO_SECONDARY_PORT) )
																																																																																																																													{
																																																																																																																														if ( (status == OK) && (port == NO_SECONDARY_PORT) )
																																																																																																																																		{
																																																																																																																																			Log_NTDS_Mesg (device, NTDS_STATUS_CAT,
																																																																																																																																			"NTDS:NTDS_Status-Device=%d, Port=%c, There is no"
																																																																																																																																			" PRIMARY or SECONDARY port configured for this device.",
																																																																																																																																			device, 'A'+port);
																																																																																																																																			return (CHANNEL_STATUS_UNKNOWN);
																																																																																																																																						}
																																																																																																																																									}
																																																																																																																																											}
																																																																																																																																												}
																																																																																																																																													if (status == OK)
																																																																																																																																													status = NTDS_Channel_Status[port];
																																																																																																																																													else
																																																																																																																																													status = CHANNEL_STATUS_UNKNOWN;
																																																																																																																																													return (status);
																																																																																																																																													*
																																																																																																																																													* SYNOPSIS:  Get_NTDS_Status_String    (application)
																																																																																																																																													*
																																																																																																																																													* DESCRIPTION:    The Get_NTDS_Status_String function returns a pointer
																																																																																																																																													*                 to a string that describes the current status of
																																																																																																																																													*                 the interface.
																																																																																																																																													*
																																																																																																																																													* PARAMETERS:
																																																																																																																																													*
																																																																																																																																													*    INPUT   device :     This parameter contains the logical unit number of
																																																																																																																																													*                      the device being used.
																																																																																																																																													*
																																																																																																																																													*    OUTPUT  NOTHING
																																																																																																																																													*
																																																																																																																																													*
																																																																																																																																													* RETURNS Pointer to a text string describing the interface status.
																																																																																																																																													*
																																																																																																																																													*#########################################################################*/
																																																																																																																																													int device
																																																																																																																																													status = get_port (device, PRIMARY_PORT, &port);
																																																																																																																																													if ( (status != OK) || (port == NO_PRIMARY_PORT) )
																																																																																																																																														{
																																																																																																																																															if ( (status == OK) && (port == NO_PRIMARY_PORT) )
																																																																																																																																																	{
																																																																																																																																																		status = get_port (device, SECONDARY_PORT, &port);
																																																																																																																																																		if ( (status != OK) || (port == NO_SECONDARY_PORT) )
																																																																																																																																																					{
																																																																																																																																																						if ( (status == OK) && (port == NO_SECONDARY_PORT) )
																																																																																																																																																										{
																																																																																																																																																											Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
																																																																																																																																																											"NTDS:Get_NTDS_Status_String-Device=%d, Port=%c, There is no"
																																																																																																																																																											" PRIMARY or SECONDARY port configured for this device.",
																																																																																																																																																											device, 'A'+port);
																																																																																																																																																											return (NTDS_Status_String[NTDS_Channel_Status[port] - CHANNEL_STATUS_UNKNOWN]);
																																																																																																																																																														}
																																																																																																																																																																	}
																																																																																																																																																																			}
																																																																																																																																																																				}
																																																																																																																																																																					if (status == OK)
																																																																																																																																																																						{
																																																																																																																																																																							/* We have to subtract CHANNEL_STATUS_UNKNOWN (-2) to get the
																																																																																																																																																																							* zeroth index of the strings.
																																																																																																																																																																							*/
																																																																																																																																																																							return (NTDS_Status_String[NTDS_Channel_Status[port] - CHANNEL_STATUS_UNKNOWN]);
																																																																																																																																																																							}
																																																																																																																																																																								else
																																																																																																																																																																									{
																																																																																																																																																																										Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
																																																																																																																																																																										"NTDS:Get_NTDS_Status_String-Device=%d, Port=%c, UNKNOWN DEVICE",
																																																																																																																																																																										device, port+'A');
																																																																																																																																																																										return (NTDS_Status_String[0]);
																																																																																																																																																																										}
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:   Deque_Output_Mesg  (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:     This function allows a protocol task to dequeue a message
																																																																																																																																																																											*                from the application's output queue.  The function checks
																																																																																																																																																																											*                the message queue for a pending output request.  If an
																																																																																																																																																																											*                output request is not available, the timeout parameter is
																																																																																																																																																																											*                tested to determine if the caller wants to wait for an
																																																																																																																																																																											*                output request before returning.  If the caller elects
																																																																																																																																																																											*                not to wait, a S_objLib_OBJ_UNAVAILABLE status may be returned
																																																																																																																																																																											*                with the address field set to a NULLPTR.
																																																																																																																																																																											*
																																																																																																																																																																											*
																																																																																																																																																																											*        PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*    INPUT   port :     This parameter contains the port id of the board
																																																																																																																																																																											*                    dequeuing the message buffer.
																																																																																																																																																																											*
																																																																																																																																																																											*            timeout :   This parameter determines the amount of time the
																																																																																																																																																																											*                       caller will wait.  The time_out can also be specified
																																																																																																																																																																											*                       as NO_WAIT or WAIT_FOREVER.
																																																																																																																																																																											*
																																																																																																																																																																											*             NOTE :   If an output buffer is not taken from the output queue
																																																																																																																																																																											*                    the caller will receive an error response and the buffer
																																																																																																																																																																											*                    parameters will be zeroed.
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT  *buffer_ptr :    This parameter contains a pointer to the message
																																																																																																																																																																											*                      buffer of type NTDS_OUTPUT_MSGS.
																																																																																																																																																																											*
																																																																																																																																																																											*                   The following fields are passed to the application in the
																																																																																																																																																																											*                   buffer parameter:
																																																																																																																																																																											*
																																																																																																																																																																											*                  *address : This field is a pointer to the message buffer to
																																																																																																																																																																											*                            be transferred.
																																																																																																																																																																											*
																																																																																																																																																																											*                  partition_id : This field contains the partition_id of the
																																																																																																																																																																											*                             buffer.  This allows the protocol task to return
																																																																																																																																																																											*                            the buffer to the proper partition when partitions
																																																																																																																																																																											*                            are being used. When malloc is being used this
																																																																																																																																																																											*                            field should be NULL.
																																																																																																																																																																											*
																																																																																																																																																																											*                  timeout : This field provides a timeout value for the
																																																																																																																																																																											*                            output task to use for the buffer transfer.  This
																																																																																																																																																																											*                            parameter has a range of 0..255.  The actual
																																																																																																																																																																											*                            time involved with this count is dependent on
																																																																																																																																																																											*                            the protocol implementation.  However, the value
																																																																																																																																																																											*                            is expected to be referenced in VxWorks ticks.
																																																																																																																																																																											*
																																																																																																																																																																											*                   length : This field contains the length of the data buffer
																																																																																																																																																																											*                            to be transferred. The range of this field is from
																																																																																																																																																																											*                            0 to 65535.
																																																																																																																																																																											*
																																																																																																																																																																											*
																																																																																																																																																																											*    RETURNS   OK
																																																																																																																																																																											*              BAD_PORT_ID
																																																																																																																																																																											*              VxWorks error code
																																																																																																																																																																											*
																																																																																																																																																																											*########################################################################*/
																																																																																																																																																																											int              port,
																																																																																																																																																																											NTDS_OUTPUT_MSGS *buffer_ptr,
																																																																																																																																																																											int              timeout
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											return (OK);
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:   Deque_Packed_Output_Mesg_Block  (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:     This function allows a protocol task to dequeue a packed
																																																																																																																																																																											*                message block from the application's output queue.  The
																																																																																																																																																																											*                function checks the message queue for a pending output
																																																																																																																																																																											*                request.  If an output request is not available, the timeout
																																																																																																																																																																											*                parameter is tested to determine if the caller wants to wait
																																																																																																																																																																											*                for an output request before returning.  If the caller elects
																																																																																																																																																																											*                not to wait, a S_objLib_OBJ_UNAVAILABLE status may be returned
																																																																																																																																																																											*                with the address field set to a NULLPTR.
																																																																																																																																																																											*
																																																																																																																																																																											*
																																																																																																																																																																											*        PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*    INPUT   port :     This parameter contains the port id of the board
																																																																																																																																																																											*                    dequeuing the message buffer.
																																																																																																																																																																											*
																																																																																																																																																																											*            timeout :   This parameter determines the amount of time the
																																																																																																																																																																											*                       caller will wait.  The time_out can also be specified
																																																																																																																																																																											*                       as NO_WAIT or WAIT_FOREVER.
																																																																																																																																																																											*
																																																																																																																																																																											*             NOTE :   If an output buffer is not taken from the output queue
																																																																																																																																																																											*                    the caller will receive an error response and the buffer
																																																																																																																																																																											*                    parameters will be zeroed.
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT  *buffer_ptr :    This parameter contains a pointer to the message
																																																																																																																																																																											*                      buffer of type NTDS_OUTPUT_MSGS.
																																																																																																																																																																											*
																																																																																																																																																																											*                   The following fields are passed to the application in the
																																																																																																																																																																											*                   buffer parameter:
																																																																																																																																																																											*
																																																																																																																																																																											*                  *address : This field is a pointer to the message buffer to
																																																																																																																																																																											*                            be transferred.
																																																																																																																																																																											*
																																																																																																																																																																											*                  partition_id : This field contains the partition_id of the
																																																																																																																																																																											*                             buffer.  This allows the protocol task to return
																																																																																																																																																																											*                            the buffer to the proper partition when partitions
																																																																																																																																																																											*                            are being used. When malloc is being used this
																																																																																																																																																																											*                            field should be NULL.
																																																																																																																																																																											*
																																																																																																																																																																											*                  timeout : This field provides a timeout value for the
																																																																																																																																																																											*                            output task to use for the buffer transfer.  This
																																																																																																																																																																											*                            parameter has a range of 0..255.  The actual
																																																																																																																																																																											*                            time involved with this count is dependent on
																																																																																																																																																																											*                            the protocol implementation.  However, the value
																																																																																																																																																																											*                            is expected to be referenced in VxWorks ticks.
																																																																																																																																																																											*
																																																																																																																																																																											*                   length : This field contains the length of the data buffer
																																																																																																																																																																											*                            to be transferred. The range of this field is from
																																																																																																																																																																											*                            0 to 65535.
																																																																																																																																																																											*
																																																																																																																																																																											*
																																																																																																																																																																											*    RETURNS   OK
																																																																																																																																																																											*              BAD_PORT_ID
																																																																																																																																																																											*              VxWorks error code
																																																																																																																																																																											*
																																																																																																																																																																											*########################################################################*/
																																																																																																																																																																											int              port,
																																																																																																																																																																											NTDS_OUTPUT_MSGS *buffer_ptr,
																																																																																																																																																																											int              timeout
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											return (OK);
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:       Deque_Output_Signal   (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:    This function returns a special event signal from the
																																																																																																																																																																											*                 selected application.  The caller determines if it will wait for
																																																																																																																																																																											*                 a signal response by setting the time_out variable.
																																																																																																																																																																											*
																																																																																																																																																																											*                    It is expected that the application will place
																																																																																																																																																																											*                 special event signals in the queue by calling the
																																																																																																																																																																											*                 Send_NTDS_Signal function.
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*    INPUT :
																																																																																																																																																																											*
																																																																																																																																																																											*           port :   This parameter determines the queue from which the
																																																																																																																																																																											*                    signal messages will be taken.
																																																																																																																																																																											*
																																																																																																																																																																											*       mesg_ptr :   A pointer the variable that will hold the updated
																																																																																																																																																																											*                    signal information.
																																																																																																																																																																											*
																																																																																																																																																																											*       time_out :   This parameter determines how long the caller will
																																																																																																																																																																											*                    wait for a message to be received before declaring
																																																																																																																																																																											*                    an input failure.  The time_out can also be specified
																																																																																																																																																																											*                    as NO_WAIT or WAIT_FOREVER.
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT :
																																																																																																																																																																											*
																																																																																																																																																																											*         mesg_ptr :  This parameter contains the following updated
																																																																																																																																																																											*                     information if the timeout did not occur; otherwise
																																																																																																																																																																											*                     the values are zero.
																																																																																																																																																																											*
																																																																																																																																																																											*                   *event_ptr :   This parameter is a pointer to the
																																																																																																																																																																											*                                  variable that will contain the signal
																																																																																																																																																																											*                                  status.  The actual status that is
																																																																																																																																																																											*                                  transferred is dependent on the application.
																																																																																																																																																																											*
																																																																																																																																																																											*                   *time_ptr  :   This parameter is a pointer to the
																																																																																																																																																																											*                                  variable that will contain the time the
																																																																																																																																																																											*                                  signal status was detected.
																																																																																																																																																																											*
																																																																																																																																																																											* RETURNS   OK
																																																																																																																																																																											*           BAD_PORT_ID
																																																																																																																																																																											*           VxWorks error status
																																																																																																																																																																											*
																																																																																																																																																																											* #########################################################################*/
																																																																																																																																																																											int              port,
																																																																																																																																																																											NTDS_SIGNAL_MSGS *mesg_ptr,
																																																																																																																																																																											int              timeout
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											return (OK);
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:   Queue_Input_Mesg    (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:     This function queues a message to an application's input
																																																																																																																																																																											*                queue.  This function searches the message list for a queue
																																																																																																																																																																											*                that matches the message type received in the buffer.  If a
																																																																																																																																																																											*                queue is found, the message buffer is placed in that queue.
																																																																																																																																																																											*                If a queue is not found, the function returns to the caller
																																																																																																																																																																											*                with an error status.
																																																																																																																																																																											*
																																																																																																																																																																											*                    The caller's port is checked to ensure that the "normal" 
																																																																																																																																																																											*                port is used so that the application receives the message.
																																																																																																																																																																											*                This is to support redundant channel interfaces.
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*    INPUT   port :    This parameter contains the port id of the board queuing
																																																																																																																																																																											*                    the message buffer.  The actual port that may be used may
																																																																																																																																																																											*                     be different if redundant channels are used.
																																																																																																																																																																											*
																																																																																																																																																																											*            *buffer_ptr :    This parameter contains a pointer to the message
																																																																																																																																																																											*                      buffer of type NIO_MESG.
																																																																																																																																																																											*
																																																																																																																																																																											*      The following fields are passed to the application in the
																																																																																																																																																																											*      buffer parameter:
																																																																																																																																																																											*
																																																																																																																																																																											*                 *address : This field is a pointer to the message buffer to
																																																																																																																																																																											*                            be transferred.
																																																																																																																																																																											*
																																																																																																																																																																											*                 time : Time stamp of received message.
																																																																																																																																																																											*
																																																																																																																																																																											*                 length : This field contains the length of the data buffer
																																																																																																																																																																											*                            to be transferred. The range of this field is from
																																																																																																																																																																											*                            0 to 65535.
																																																																																																																																																																											*
																																																																																																																																																																											*              message_type :  This parameter contains the message type of the
																																																																																																																																																																											*                              buffer being queued.
																																																																																																																																																																											*
																																																																																																																																																																											*    free_buffer  : This parameter determines if the buffer should be
																																																																																																																																																																											*        released to the memory pool.  It is the responsibility of the
																																																																																																																																																																											*        application to coordinate buffer releasing with the NTDS Comm
																																																																																																																																																																											*        package.  (See Recv_NTDS_Mesg)
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT  NOTHING
																																																																																																																																																																											*
																																																																																																																																																																											*    RETURNS   OK
																																																																																																																																																																											*              COULD_NOT_QUE_MESG
																																																																																																																																																																											*              BAD_PORT_ID
																																																																																																																																																																											*              BUFFER_PART_ERR
																																																																																																																																																																											*              MT_REGISTER_ERR
																																																																																																																																																																											*              QUE_NOT_FOUND
																																																																																																																																																																											*              VxWorks error code
																																																																																																																																																																											*
																																																																																																																																																																											*########################################################################*/
																																																																																																																																																																											int            port,
																																																																																																																																																																											NIO_MESG     * buffer_ptr,
																																																																																																																																																																											unsigned int   mesg_type,
																																																																																																																																																																											char           free_buffer
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											return (OK);
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:   Queue_Remote_Input_Mesg    (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:   This function queues a message to an ethernet socket output
																																																																																																																																																																											*                queue.  The message will be packed and transmitted to the
																																																																																																																																																																											*                CEP where the Applcation's parser function will be called
																																																																																																																																																																											*                to deliver the message to the appropriate input queue.
																																																																																																																																																																											*                The socket ID is associated with the Device ID via a table.
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*    INPUT   port :    This parameter contains the port id of the board queuing
																																																																																																																																																																											*                      the message buffer.
																																																																																																																																																																											*
																																																																																																																																																																											*            *buffer_ptr :  This parameter contains a pointer to the message
																																																																																																																																																																											*                           buffer of type NIO_MESG.
																																																																																																																																																																											*
																																																																																																																																																																											*           free_buffer  : This parameter determines if the buffer should be
																																																																																																																																																																											*                          released to the memory pool.  It is the
																																																																																																																																																																											*                          responsibility of the application to coordinate
																																																																																																																																																																											*                          buffer releasing with the NTDS Comm package. 
																																																																																																																																																																											*                          (See Recv_NTDS_Mesg)
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT  NOTHING
																																																																																																																																																																											*
																																																																																																																																																																											*    RETURNS   OK
																																																																																																																																																																											*              COULD_NOT_QUE_MESG
																																																																																																																																																																											*              BAD_PORT_ID
																																																																																																																																																																											*              BUFFER_PART_ERR
																																																																																																																																																																											*              MT_REGISTER_ERR
																																																																																																																																																																											*              QUE_NOT_FOUND
																																																																																																																																																																											*              VxWorks error code
																																																																																																																																																																											*
																																																																																																																																																																											* ########################################################################*/
																																																																																																																																																																											int          port,
																																																																																																																																																																											NIO_MESG     *buffer,
																																																																																																																																																																											char         free_buffer
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											return (OK);
																																																																																																																																																																																																																																																																																																																																																						*
																																																																																																																																																																											* SYNOPSIS: Parse_Remote_Port_Mesg  (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION: This function performs a callback to a port's protocol
																																																																																																																																																																											*             parse function in order to queue a received input message.
																																																																																																																																																																											*             It is  the responsibility of the protocol to properly
																																																																																																																																																																											*             parse the input data.  This function provides a sanitary
																																																																																																																																																																											*             method of accessing that function.
																																																																																																																																																																											*
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*     INPUT  port :  This parameter contains the logical unit number of
																																																																																																																																																																											*                      of the port for which the device ID is requested.
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT  NOTHING
																																																																																																																																																																											*
																																																																																																																																																																											*    RETURNS Result of the parse
																																																																																																																																																																											*            OK if NO parse function is available
																																																																																																																																																																											*
																																																																																																																																																																											*
																																																																																																																																																																											* #########################################################################*/
																																																																																																																																																																											int      port,
																																																																																																																																																																											int      data_src,
																																																																																																																																																																											NIO_MESG *packet
																																																																																																																																																																											//if (device_config[port].function.input_comm != NULL)
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//   return ((device_config[port].function.input_comm)(port,
																																																																																																																																																																											//                                                     data_src,
																																																																																																																																																																											//                                                     packet));
																																																																																																																																																																											//}
																																																																																																																																																																											//else
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//  Log_NTDS_Mesg (Get_Device_Id(port), NTDS_ERROR_CAT,
																																																																																																																																																																											//    "NTDS:Parse_Remote_Port_Mesg-Port=%c  Cannot Parse Recvd Message No "
																																																																																																																																																																											//    "Parse function available", 'A'+port);
																																																																																																																																																																											return (OK);
																																																																																																																																																																											//}
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:  Get_Device_Id    (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:    The Get_Device_Id function finds the current device 
																																																																																																																																																																											*                 that is mapped to the selected port.
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*    INPUT   port :  This parameter contains the logical unit number of
																																																																																																																																																																											*                    the port being used.
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT  NOTHING
																																																																																																																																																																											*
																																																																																																																																																																											*
																																																																																																																																																																											* RETURNS  The device assigned to the port.
																																																																																																																																																																											*          0 if no device is found.
																																																																																																																																																																											*
																																																																																																																																																																											*#########################################################################*/
																																																																																																																																																																											int port
																																																																																																																																																																																																																																																																																																																																																						if ( (port >= 0) && (port <= NUM_OF_NTDS_PORTS) )
																																																																																																																																																																											return (Port_Device[port]);
																																																																																																																																																																											else
																																																																																																																																																																											return(0);
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:  Report_Port_Error   (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:      This function routes an error_code to the application's
																																																																																																																																																																											*                 error queue.  The application is expected to remove the
																																																																																																																																																																											*                 error entry from the queue by calling the Recv_NTDS_Error
																																																																																																																																																																											*                 function.
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*     INPUT :
																																																																																																																																																																											*
																																																																																																																																																																											*           port :    This variable determines which port's error queue
																																																																																																																																																																											*                     will receive the error code.
																																																																																																																																																																											*
																																																																																																																																																																											*            mesg_ptr :   A structure that contains the following information:
																																																																																																																																																																											*
																																																																																																																																																																											*                     error_code :    This parameter contains the error that
																																																																																																																																																																											*                                     will be posted to the queue.
																																																																																																																																																																											*
																																																																																																																																																																											*                           time :    This parameter contains the time that
																																																																																																																																																																											*                                     the error occurred.
																																																																																																																																																																											*
																																																																																																																																																																											*     OUTPUT     NOTHING
																																																																																																																																																																											*
																																																																																																																																																																											*     RETURNS  OK
																																																																																																																																																																											*              BAD_PORT_ID
																																																																																																																																																																											*              vxWorks error code
																																																																																																																																																																											*
																																																																																																																																																																											*#########################################################################*/
																																																																																																																																																																											int             port,
																																																																																																																																																																											NTDS_ERROR_MSGS *mesg_ptr
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											return (OK);
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:  Report_Port_Signal    (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:       This function routes a signal code to the appliation's
																																																																																																																																																																											*                 signal queue.  The application is expected to remove the
																																																																																																																																																																											*                 signal entry by calling the Recv_NTDS_Signal function.
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*     INPUT  port :   This variable determines which port's signal queue
																																																																																																																																																																											*                   will receive the signal code.
																																																																																																																																																																											*
																																																																																																																																																																											*            mesg_ptr :   A structure that contains the following information:
																																																																																																																																																																											*
																																																																																																																																																																											*                   signal_code : This parameter contains the signal that
																																																																																																																																																																											*                                 will be posted to the queue.
																																																																																																																																																																											*
																																																																																																																																																																											*                   time :  This parameter contains the time that the signal
																																																																																																																																																																											*                           occurred.
																																																																																																																																																																											*
																																																																																																																																																																											*     OUTPUT     NOTHING
																																																																																																																																																																											*
																																																																																																																																																																											*     RETURNS  OK
																																																																																																																																																																											*              BAD_PORT_ID
																																																																																																																																																																											*              vxWorks error code
																																																																																																																																																																											*
																																																																																																																																																																											*#########################################################################*/
																																																																																																																																																																											int               port,
																																																																																																																																																																											NTDS_SIGNAL_MSGS  *mesg_ptr
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											//
																																																																																																																																																																										{
																																																																																																																																																																											return (OK);
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:  Report_Port_Status    (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:      This function saves the interface status of a port for
																																																																																																																																																																											*                 the application to use.
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*    INPUT   port :    This parameter contains the port id of the board
																																																																																																																																																																											*                   reporting a status change.
																																																																																																																																																																											*
																																																																																																																																																																											*            status :  This parameter contains the new interface status.
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT  NOTHING
																																																																																																																																																																											*
																																																																																																																																																																											* RETURNS OK or
																																																																																																																																																																											*         BAD_PORT_ID
																																																																																																																																																																											*         vxWorks ERROR code.
																																																																																																																																																																											*
																																																																																																																																																																											*#########################################################################*/
																																																																																																																																																																											int port,
																																																																																																																																																																											int readiness
																																																																																																																																																																											int         status = OK;
																																																																																																																																																																											int         device;
																																																																																																																																																																											device = Port_Device[port]; /* Find the device number for this port. */
																																																																																																																																																																											NTDS_Channel_Status[port] = readiness; /* Update the channel's status before swapping ports. */
																																																																																																																																																																											return (status);
																																																																																																																																																																											*
																																																																																																																																																																											* SYNOPSIS:  Get_Port_Status    (protocol)
																																																																																																																																																																											*
																																																																																																																																																																											* DESCRIPTION:      This function saves the interface status of a port for
																																																																																																																																																																											*                 the application to use.
																																																																																																																																																																											*
																																																																																																																																																																											* PARAMETERS:
																																																																																																																																																																											*
																																																																																																																																																																											*    INPUT   port :    This parameter contains the port id of the board
																																																																																																																																																																											*                   reporting a status change.
																																																																																																																																																																											*
																																																																																																																																																																											*            status :  This parameter contains the new interface status.
																																																																																																																																																																											*
																																																																																																																																																																											*    OUTPUT  NOTHING
																																																																																																																																																																											*
																																																																																																																																																																											* RETURNS Port status
																																																																																																																																																																											*         BAD_PORT_ID
																																																																																																																																																																											*
																																																																																																																																																																											*#########################################################################*/
																																																																																																																																																																											int port
																																																																																																																																																																											/* Validate the port to be in range at least */
																																																																																																																																																																											if ((port >= 0) && (port < NUM_OF_NTDS_PORTS))
																																																																																																																																																																												{
																																																																																																																																																																													if  (Comm_Configured[port+1])
																																																																																																																																																																															{
																																																																																																																																																																																return (NTDS_Channel_Status[port]);
																																																																																																																																																																																	}
																																																																																																																																																																																		else /* Port Not Configured. */
																																																																																																																																																																																				{
																																																																																																																																																																																					if (NTDS_Channel_Status[port] == CHANNEL_FAILED_CONFIG)
																																																																																																																																																																																					return (NTDS_Channel_Status[port]);
																																																																																																																																																																																					else
																																																																																																																																																																																					return (BAD_PORT_ID);
																																																																																																																																																																																						}
																																																																																																																																																																																							}
																																																																																																																																																																																								else
																																																																																																																																																																																								return (BAD_PORT_ID);
																																																																																																																																																																																								*
																																																																																																																																																																																								* SYNOPSIS:  Get_Port_Status_String    (protocol)
																																																																																																																																																																																								*
																																																																																																																																																																																								* DESCRIPTION:    The Get_Port_Status_String function returns a pointer
																																																																																																																																																																																								*                 to a string that describes the current status of
																																																																																																																																																																																								*                 the interface at the port level.
																																																																																																																																																																																								*
																																																																																																																																																																																								* PARAMETERS:
																																																																																																																																																																																								*
																																																																																																																																																																																								*    INPUT   port :     This parameter contains the port number of
																																																																																																																																																																																								*                      the channel being used.
																																																																																																																																																																																								*
																																																																																																																																																																																								*    OUTPUT  NOTHING
																																																																																																																																																																																								*
																																																																																																																																																																																								*
																																																																																																																																																																																								* RETURNS Pointer to a text string describing the interface status. 
																																																																																																																																																																																								*
																																																																																																																																																																																								*#########################################################################*/
																																																																																																																																																																																								int port
																																																																																																																																																																																																																																																																																																																																																																																/* Validate the port to be in range at least */
																																																																																																																																																																																								if ((port >= 0) && (port < NUM_OF_NTDS_PORTS))
																																																																																																																																																																																									{
																																																																																																																																																																																										/* We have to subtract CHANNEL_STATUS_UNKNOWN (-2) to get the
																																																																																																																																																																																										* zeroth index of the strings.
																																																																																																																																																																																										*/
																																																																																																																																																																																										return (NTDS_Status_String[NTDS_Channel_Status[port] - CHANNEL_STATUS_UNKNOWN]);
																																																																																																																																																																																										}
																																																																																																																																																																																											else
																																																																																																																																																																																												{
																																																																																																																																																																																													Log_NTDS_Mesg (Get_Device_Id(port), NTDS_ERROR_CAT,
																																																																																																																																																																																													"NTDS:Get_Port_Status_String-Port=%c  Unknown/Unconfigured Port",
																																																																																																																																																																																													'A'+port);
																																																																																																																																																																																													return (NTDS_Status_String[0]);
																																																																																																																																																																																													}
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:  Check_For_NTDS_Boards
																																																																																																																																																																																														*
																																																																																																																																																																																														* DESCRIPTION:      This function queries the VME bus for a maximum of two
																																																																																																																																																																																														*              interface cards.  If the first board and only the first is
																																																																																																																																																																																														*              found a status of 1 is returned.  If the second board and
																																																																																																																																																																																														*              only the second board is found, a status of 2 is returned.
																																																																																																																																																																																														*              If both boards are found, a status of 3 is returned.  Any
																																																																																																																																																																																														*              other condition results in a 0 being returned.
																																																																																																																																																																																														*
																																																																																																																																																																																														* PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*    INPUT   address_1 :    This parameter is the first board address.
																																																																																																																																																																																														*
																																																																																																																																																																																														*            address_2 :    This parameter is the second board address.
																																																																																																																																																																																														*
																																																																																																																																																																																														*    OUTPUT  NOTHING
																																																																																																																																																																																														*
																																																																																																																																																																																														* RETURNS 0 NO BOARDS FOUND
																																																																																																																																																																																														*         1 FIRST BOARD FOUND
																																																																																																																																																																																														*         2 SECOND BOARD FOUND
																																																																																																																																																																																														*         3 BOTH BOARDS FOUND
																																																																																																																																																																																														*
																																																																																																																																																																																														*#########################################################################*/
																																																																																																																																																																																														unsigned int address_1,
																																																																																																																																																																																														unsigned int address_2
																																																																																																																																																																																														//char *lcl_address;
																																																																																																																																																																																														//int status;
																																																																																																																																																																																														// status = NO_BOARDS_FOUND;
																																																																																																																																																																																														// if ((sysBusToLocalAdrs (VME_AM_EXT_USR_DATA, (char *)address_1,
																																																																																																																																																																																														// (char **)&lcl_address)) != ERROR)
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//    if (Is_NTDS_Board_There ((unsigned int *) lcl_address))
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//       status = FIRST_BOARD_FOUND;
																																																																																																																																																																																														//    }
																																																																																																																																																																																														// }
																																																																																																																																																																																														// if ((sysBusToLocalAdrs (VME_AM_EXT_USR_DATA, (char *)address_2,
																																																																																																																																																																																														// (char **)&lcl_address)) != ERROR)
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//    if (Is_NTDS_Board_There ((unsigned int *) lcl_address))
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//       status += SECOND_BOARD_FOUND;
																																																																																																																																																																																														//    }
																																																																																																																																																																																														// }
																																																																																																																																																																																														// return (status);
																																																																																																																																																																																														return (OK);
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:  Find_NTDS_Boards
																																																																																																																																																																																														*
																																																																																																																																																																																														* DESCRIPTION:      This function tests a list of possible NTDS card
																																																																																																																																																																																														*                 addresses that may be available. Each possible address is
																																																																																																																																																																																														*                 tested until two valid boards are found or the list is
																																																																																																																																																																																														*                 exhausted, which ever comes first.
																																																																																																																																																																																														*
																																																																																																																																																																																														* PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*    INPUT   address_list :  This parameter is a pointer to a list of
																																																																																																																																																																																														*                            addresses to be tested for validity.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             first_result :  This parameter contains a pointer to store the
																																																																																																																																																																																														*                             information on the first board found.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             second_result :  This parameter contains a pointer to store the
																																																																																																																																																																																														*                              information on the second board found.
																																																																																																																																																																																														*
																																																																																																																																																																																														*    OUTPUT   first_result :  This parameter updates the pointer values
																																																																																																																																																																																														*                             storing information on the first board found.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             second_result :  This parameter updates the pointer values
																																																																																																																																																																																														*                              storing information on the second board found.
																																																																																																																																																																																														*
																																																																																																																																																																																														*
																																																																																																																																																																																														* RETURNS 0 If no boards are found
																																																																																																																																																																																														*         1 If 1 board is found
																																																																																																																																																																																														*         2 If 2 boards are found
																																																																																																																																																																																														*
																																																																																																																																																																																														*#########################################################################*/
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														return (0);
																																																																																																																																																																																														*
																																																																																																																																																																																														*        SYNOPSIS:        Find_NTDS_Mesg
																																																																																																																																																																																														*
																																																																																																																																																																																														*        DESCRIPTION:   This function finds the message type and buffer size
																																																																																																																																																																																														*                of a message.  The message type and buffer size are
																																																																																																																																																																																														*                expected to be in the first word pointed to by the
																																																																																																																																																																																														*                buffer pointer.
																																																																																																																																																																																														*
																																																																																																																																																																																														*                This function will also determine if the next message address
																																																																																																																																																																																														*                is really the next message or the end of the input buffer.
																																																																																																																																																																																														*                This is to support those interfaces that want to pass the raw
																																																																																																																																																																																														*                buffer to the application.  The type of message parsing
																																																																																																																																																																																														*                that is performed is determined when the device is
																																																																																																																																																																																														*                configured.
																																																																																																																																																																																														*
																																																																																																																																																																																														*                Find_NTDS_Mesg receives a mask to determine the bits
																																																																																																																																																																																														*                to save for both the message type and size of the
																																																																																																																																																																																														*                buffer.  Also included are variables used to determine
																																																																																																																																																																																														*                how far to shift the data to right justify it.
																																																																																																																																																																																														*
																																																																																																																																																																																														*                This function returns the message type, size of the
																																																																																																																																																																																														*                buffer, and the next buffer address.
																																																																																																																																																																																														*
																																																																																																																																																																																														*
																																																																																																																																																																																														*        PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*    INPUT
																																																																																																																																																																																														*             port  :  This parameter determines the port that is attempting
																																																																																																																																																																																														*                      to sort out a message.  This parameter is required
																																																																																																																																																																																														*                      to determine if raw buffers or messages are being
																																																																																																																																																																																														*                      computed.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             mesg_ptr :  This parameter is a pointer to a structure
																																																																																																																																																																																														*                         that has the following characteristics.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             *buffer_address :  This parameter is a pointer to a pointer
																																																																																																																																																																																														*                                that points to the first word of the mesg
																																																																																																																																																																																														*                                buffer.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             word_size :  This parameter determines the word width of the
																																																																																																																																																																																														*                          buffer being used. The two options are WORD_32
																																																																																																																																																																																														*                          and WORD_16.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             msg_mask  :  This parameter contains the mask to be applied
																																																																																																																																																																																														*                          to the first word of the message to get the
																																																																																																																																																																																														*                          message type.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             size_mask :  This parameter contains the mask to be applied
																																																																																																																																																																																														*                          to the first word of the message to get the
																																																																																																																																																																																														*                          size of the buffer.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             msg_shift :  This parameter contains the number of shifts
																																																																																																																																																																																														*                          required to right justify the message type.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             size_shift : This parameter contains the number of shifts
																																																																																																																																																																																														*                          required to right justify the message size.
																																																																																																																																																																																														*
																																																																																																																																																																																														*       num_of_words_type: This parameter determines if an extra word will
																																																																																																																																																																																														*                          be added to the message size and the next message
																																																																																																																																																																																														*                          address.  If the parameter is set to
																																																																																																																																																																																														*                          NW_WORDS_DOES_NOT_INCLUDE_HEADER_WORD, both values
																																																																																																																																																																																														*                          will be incremented appropriately.  If the
																																																																																																																																																																																														*                          parameter is set to NW_WORDS_INCLUDES_HEADER_WORD,
																																																																																																																																																																																														*                          the values will be returned as decoded.
																																																																																																																																																																																														*
																																																																																																																																																																																														*       buffer_length:     This parameter determines the length of the raw
																																																																																																																																																																																														*                          input buffer.  This value is usually extracted from
																																																																																																																																																																																														*                          the input packet's tfr_count parameter.
																																																																																																																																																																																														*
																																																																																																																																																																																														*    OUTPUT  *test_patt :  This parameter is updated to point to the
																																																																																																																																																																																														*                          test pattern following the message.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             *buffer_size : This parameter is a pointer that will contain
																																																																																																																																																																																														*                            the size of the message.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             *msg_type    : This parameter is a pointer that will contain
																																																																																																																																																																																														*                            the message type of the message.
																																																																																																																																																																																														*
																																																																																																																																																																																														*             *next_msg_address : This parameter is a pointer that will
																																																																																																																																																																																														*                                 contain the address of the next message.
																																																																																																																																																																																														*
																																																																																																																																																																																														*    RETURNS   NOTHING
																																																																																																																																																																																														*
																																																																																																																																																																																														*########################################################################*/
																																																																																																																																																																																														int port,
																																																																																																																																																																																														MESG_BLOCK *mesg_ptr
																																																																																																																																																																																																																																																																																																																																																																																												//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:  Get_NTDS_Partition
																																																																																																																																																																																														*
																																																																																																																																																																																														* DESCRIPTION:     This function gets a block of memory that can be accessed by
																																																																																																																																																																																														*               across the VME bus.  The memory block is taken from the
																																																																																																																																																																																														*               NTDS buffer pool.  This memory block is converted to a
																																																																																																																																																																																														*               partition that the caller can used to transfer data to or from
																																																																																																																																																																																														*               the NIO interface board.  The memory buffer is addressable
																																																																																																																																																																																														*               by off board processors. (Mapped to VME memory).
																																																																																																																																																																																														*
																																																																																																																																																																																														* PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*   INPUT : size     This parameter determines the number of bytes that will be
																																																																																																																																																																																														*                    allocated.
																																																																																																																																																																																														*
																																																																																																																																																																																														*
																																																																																																																																																																																														* OUTPUT :  NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														* RETURNS : partition  This parameter returns the partition id of the newly
																																																																																																																																																																																														*                    created partition.  If the partition id is NULL, a
																																																																																																																																																																																														*                    partition was not created.
																																																																																																																																																																																														*
																																																																																																																																																																																														* #########################################################################*/
																																																																																																																																																																																														unsigned int size
																																																																																																																																																																																														//char *buffer_ptr;
																																																																																																																																																																																														//PART_ID partition;
																																																																																																																																																																																														//PART_ID t_partition;
																																																																																																																																																																																														//partition = NULL;
																																																																																																																																																																																														///* Get a buffer from the NTDS pool */
																																																																																																																																																																																														//if ((buffer_ptr = Get_NTDS_Buffer (size, &t_partition)) != NULL)
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//  /* Create a memory partition for the caller */
																																																																																																																																																																																														//  if ((STATUS)(partition = memPartCreate (buffer_ptr, size)) == 0)
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//    printf("\nntds_comm.c - Get_NTDS_Partition - "
																																																																																																																																																																																														//      "memPartCreate FAILURE 0x%x Size = %d\n", errnoGet(), size);
																																																																																																																																																																																														//  }
																																																																																																																																																																																														//}
																																																																																																																																																																																														///* Set the options to just return on an error NOT suspend the task */
																																																																																																																																																																																														//memPartOptionsSet (partition,
																																																																																																																																																																																														//  MEM_BLOCK_CHECK | MEM_BLOCK_ERROR_RETURN | MEM_ALLOC_ERROR_RETURN);
																																																																																																																																																																																														//return (partition);
																																																																																																																																																																																														return (0);
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:   Free_NTDS_Msg_Buffer
																																																																																																																																																																																														*
																																																																																																																																																																																														*  DESCRIPTION:   This function releases a buffer back to the buffer pool.
																																																																																																																																																																																														*        The partition id determines the buffer pool that will receive the
																																																																																																																																																																																														*        memory block.  If the partition id is NULL, the memory block will
																																																																																																																																																																																														*        be returned using a free block, implying the memory was gotten by
																																																																																																																																																																																														*        using a malloc command.  If the partition id is not NULL, a
																																																																																																																																																																																														*        memPartFree call.
																																																																																																																																																																																														*
																																																																																																																																																																																														*        PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*      INPUT:
																																																																																																																																																																																														*
																																																																																																																																																																																														*          partition_id : The identifier determining where the memory
																																																																																																																																																																																														*                         block was taken.
																																																																																																																																																																																														*
																																																																																																																																																																																														*          *address_ptr :  A pointer to the memory block being freed.
																																																																																																																																																																																														*
																																																																																																																																																																																														*      OUTPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*    RETURNS   OK
																																																																																																																																																																																														*              vxWorks error code
																																																																																																																																																																																														*
																																																																																																																																																																																														*########################################################################*/
																																																																																																																																																																																														PART_ID partition_id,
																																																																																																																																																																																														char    *address_ptr
																																																																																																																																																																																														STATUS status;
																																																																																																																																																																																														status = OK;
																																																																																																																																																																																														//if (address_ptr != NULL)
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//  if (partition_id != (PART_ID)NULL)
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//    status = memPartFree(partition_id, address_ptr);
																																																																																																																																																																																														//    if (status != OK)
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//      Log_NTDS_Mesg (0, NTDS_ERROR_CAT, "ntds_comm.c - Free_NTDS_Msg_Buffer - "
																																																																																																																																																																																														//        "Error Returning Memory Buffer 0x%x to Part ID = 0x%x Status = 0x%x",
																																																																																																																																																																																														//        (int) address_ptr, partition_id, errnoGet());
																																																																																																																																																																																														//    }
																																																																																																																																																																																														//  }
																																																																																																																																																																																														//  else
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//    free(address_ptr);
																																																																																																																																																																																														//  }
																																																																																																																																																																																														//}
																																																																																																																																																																																														return(status);
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:   NTDS_Msgs
																																																																																																																																																																																														*
																																																																																																																																																																																														*  DESCRIPTION:   This function displays a count of all the data messages
																																																																																																																																																																																														*        that have been received for application processing.
																																																																																																																																																																																														*
																																																																																																																																																																																														*        PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*      INPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*      OUTPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*    RETURNS   NOTHING
																																																																																																																																																																																														*
																																																																																																																																																																																														*########################################################################*/
																																																																																																																																																																																														void
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:   NTDS_Ques
																																																																																																																																																																																														*
																																																																																																																																																																																														*  DESCRIPTION:   This function displays a count of all the data 
																																																																																																																																																																																														*               messages that have been received for application 
																																																																																																																																																																																														*               processing.
																																																																																																																																																																																														*
																																																																																																																																																																																														*        PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*      INPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*      OUTPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*    RETURNS   NOTHING
																																																																																																																																																																																														*
																																																																																																																																																																																														*########################################################################*/
																																																																																																																																																																																														void
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:   Test_NTDS_Card
																																																																																																																																																																																														*
																																																																																																																																																																																														*  DESCRIPTION:   This function allows a person to configure the NTDS
																																																																																																																																																																																														*               package to communicate with a NTDS card.  The caller is
																																																																																																																																																																																														*               queried for the appropriate parameters before configuration.
																																																																																																																																																																																														*               The caller must also provide a valid NTDS card address before
																																																																																																																																																																																														*               the configuration will continue.
																																																																																																																																																																																														*
																																																																																																																																																																																														*  PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*      INPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*      OUTPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*    RETURNS   NOTHING
																																																																																																																																																																																														*
																																																																																																																																																																																														*########################################################################*/
																																																																																																																																																																																														void
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//
																																																																																																																																																																																													{
																																																																																																																																																																																														//   else
																																																																																																																																																																																													{
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:   Set_NTDS_Gate_Revision_Info
																																																																																																																																																																																														*
																																																																																																																																																																																														*  DESCRIPTION:   This function is used primarily by the enet client
																																																																																																																																																																																														*                 in order to report the NTDS Gate's revision information.
																																																																																																																																																																																														*                 The enet server down in the NTDS Gate board sends a
																																																																																																																																																																																														*                 structure called SATELLITE_CONFIGURATION_HDR up to the
																																																																																																																																																																																														*                 enet client which is in the application's board.  The
																																																																																																																																																																																														*                 enet client calls this function which stores the revision
																																																																																																																																																																																														*                 information in the "NTDS_Gate_Revision_Info" string.
																																																																																																																																																																																														*
																																																																																																																																																																																														*  PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*      INPUT : revision_info - the revision information string.
																																																																																																																																																																																														*
																																																																																																																																																																																														*      OUTPUT : NTDS_Gate_Revision_Info is set to the input string.
																																																																																																																																																																																														*
																																																																																																																																																																																														*    RETURNS   NOTHING
																																																																																																																																																																																														*
																																																																																																																																																																																														*########################################################################*/
																																																																																																																																																																																														char* revision_info
																																																																																																																																																																																														strcpy(NTDS_Gate_Revision_Info, revision_info);
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:   Get_NTDS_Gate_Revision_Info
																																																																																																																																																																																														*
																																																																																																																																																																																														*  DESCRIPTION:    This function is used by anyone needing the NTDS Gate's
																																																																																																																																																																																														*                 revision information.
																																																																																																																																																																																														*                 The enet server down in the NTDS Gate board sends a
																																																																																																																																																																																														*                 structure called SATELLITE_CONFIGURATION_HDR up to the
																																																																																																																																																																																														*                 enet client which is in the application's board.  The
																																																																																																																																																																																														*                 enet client calls the "Set_NTDS_Gate_Revision_Info"
																																																																																																																																																																																														*                 function which stores the revision information in the
																																																																																																																																																																																														*                "NTDS_Gate_Revision_Info" string.
																																																																																																																																																																																														*
																																																																																																																																																																																														*  PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*      INPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*      OUTPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*    RETURNS   The NTDS Gate revision information string.
																																																																																																																																																																																														*
																																																																																																																																																																																														*########################################################################*/
																																																																																																																																																																																														void
																																																																																																																																																																																														return(NTDS_Gate_Revision_Info);
																																																																																																																																																																																														*
																																																																																																																																																																																														* SYNOPSIS:   Print_NTDS_Gate_Revision_Info
																																																																																																																																																																																														*
																																																																																																																																																																																														*  DESCRIPTION:   This function is used by anyone needing to know
																																																																																																																																																																																														*                 the NTDS Gate's revision information.  This function
																																																																																																																																																																																														*                 generates a Log message which contains the Revision
																																																																																																																																																																																														*                 string of the NTDS Gate function.  This information is
																																																																																																																																																																																														*                 available at the NTDS_Gate board, as well as each function
																																																																																																																																																																																														*                 which communicates with the NTDS_Gate.
																																																																																																																																																																																														*
																																																																																																																																																																																														*  PARAMETERS:
																																																																																																																																																																																														*
																																																																																																																																																																																														*      INPUT : NONE
																																																																																																																																																																																														*
																																																																																																																																																																																														*      OUTPUT : Log Message containing the NTDS_Gate's Revision information.
																																																																																																																																																																																														*
																																																																																																																																																																																														*    RETURNS  Nothing
																																																																																																																																																																																														*
																																																																																																																																																																																														*########################################################################*/
																																																																																																																																																																																														printf("\nNTDS:- Revision Info = '%s'", NTDS_Gate_Revision_Info);
																																																																																																																																																																																														char *ifName,		        /* "ei0" for example */
																																																																																																																																																																																														char *destAddr,		/* destination IP */
																																																																																																																																																																																														char *gateAddr		/* gateway IP */
																																																																																																																																																																																														char ipAddr [20];
																																																																																																																																																																																														int status;
																																																																																																																																																																																														ifFlagChange (ifName, IFF_UP, FALSE);       /* turn off the interface */
																																																																																																																																																																																														status = ifAddrGet (ifName, ipAddr);        /* save correct addr */
																																																																																																																																																																																														if (status == OK)
																																																																																																																																																																																															{
																																																																																																																																																																																																ifAddrSet (ifName,"127.127.127.127");    /* temp change inet address */
																																																																																																																																																																																																status = routeAdd (destAddr, gateAddr);  /* subnet thru proxy client */
																																																																																																																																																																																																ifAddrSet (ifName, ipAddr);              /* return original address */
																																																																																																																																																																																																ifFlagChange (ifName, IFF_UP, TRUE);     /* turn interface back on */
																																																																																																																																																																																																}
																																																																																																																																																																																																	return (status);
																																																																																																																																																																																																	printf("\n\nNTDS_Comm library.  Last modified : 07/12/99\n\n");
																																																																																																																																																																																																	Log_NTDS_Mesg(0, NTDS_ERROR_CAT, "NTDS:- Get_NTDS_Gate_Revision_Info - %s", NTDS_Gate_Revision_Info);
																																																																																																																																																																																																	*
																																																																																																																																																																																																	* SYNOPSIS:   switchHook
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*  DESCRIPTION:    This function is called whenever a task is switched by
																																																																																																																																																																																																	*                  vxWorks.  It is used for debugging applications.  A
																																																																																																																																																																																																	*                  sample is saved to the NTDS Trace buffer which contains
																																																																																																																																																																																																	*                  the Task ID and the priority of the Task that is being
																																																																																																																																																																																																	*                  "swapped in".
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*  PARAMETERS:
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*      INPUT : NONE
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*      OUTPUT : A sample is saved in the NTDS Trace buffer.
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*    RETURNS   NONE.
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*########################################################################*/
																																																																																																																																																																																																	//
																																																																																																																																																																																																{
																																																																																																																																																																																																	*
																																																																																																																																																																																																	* SYNOPSIS:   Hook_Task_Switching
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*  DESCRIPTION:    This function turns on the capture of task swaps to
																																																																																																																																																																																																	*                  the NTDS Trace buffer.  The user must supply the port
																																																																																																																																																																																																	*                  to which the trace data is to be captured for.
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*  PARAMETERS:
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*      INPUT : port - port for which Tracing of task swaps should be captured.
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*      OUTPUT : Task_Switching_Port.
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*    RETURNS   NONE.
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*########################################################################*/
																																																																																																																																																																																																	//if (Task_Switch_Hook_Flag == FALSE)
																																																																																																																																																																																																	//
																																																																																																																																																																																																{
																																																																																																																																																																																																	//  Task_Switching_Port = port;
																																																																																																																																																																																																	//  taskSwitchHookAdd ( (FUNCPTR)switchHook );
																																																																																																																																																																																																	//  Task_Switch_Hook_Flag = TRUE;
																																																																																																																																																																																																	//}
																																																																																																																																																																																																	*
																																																																																																																																																																																																	* SYNOPSIS:   Unhook_Task_Switching
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*  DESCRIPTION:    This function turns off the capture of task swaps to
																																																																																																																																																																																																	*                  the NTDS Trace buffer.
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*  PARAMETERS:
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*      INPUT : NONE
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*      OUTPUT : NONE
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*    RETURNS   NONE.
																																																																																																																																																																																																	*
																																																																																																																																																																																																	*########################################################################*/
																																																																																																																																																																																																	/* if (Task_Switch_Hook_Flag == TRUE)
																																																																																																																																																																																																		{
																																																																																																																																																																																																			taskSwitchHookDelete ( (FUNCPTR)switchHook );
																																																																																																																																																																																																			Task_Switch_Hook_Flag = FALSE;
																																																																																																																																																																																																			}*/
																																																																																																																																																																																																			*
																																																																																																																																																																																																			* SYNOPSIS: Start_IO_Timing_Data_Capture
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*  DESCRIPTION:    This function turns on the capture of task switch info,
																																																																																																																																																																																																			*                  Interrupt and all IO timing.  Data is placed in the
																																																																																																																																																																																																			*                  NTDS Trace buffer.
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*  PARAMETERS: Port - channel which data is associated with when put in Trace
																																																																																																																																																																																																			*                     buffer.  Port = -1 = Capture data on all ports.
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*      INPUT : NONE
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*      OUTPUT : NONE
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*    RETURNS   NONE.
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*########################################################################*/
																																																																																																																																																																																																			//Task_Trace_Hook(1);
																																																																																																																																																																																																			//Debug_Interrupts = 1;
																																																																																																																																																																																																			//printf("\nDebug Interrupts Enabled");
																																																																																																																																																																																																			//if (Port == -1) /* TRACE_ANY_SOURCE = -1 = All Ports          */
																																																																																																																																																																																																			//
																																																																																																																																																																																																		{
																																																																																																																																																																																																			//  Hook_Task_Switching(0);     /* 0 = Port A.  All task-switch info will go to 'A' */
																																																																																																																																																																																																			//  printf("\nDebug Of Task Swapping Enabled For ALL ports.  Debug Info Goes To Port 'A'");
																																																																																																																																																																																																			//}
																																																																																																																																																																																																			//else
																																																																																																																																																																																																			//
																																																																																																																																																																																																		{
																																																																																																																																																																																																			//  Hook_Task_Switching(Port);
																																																																																																																																																																																																			//  printf("\nDebug Of Task Swapping Enabled For port '%c'.", Port+'A');
																																																																																																																																																																																																			//}
																																																																																																																																																																																																			//NTDS_Timing_Study_In_Progress = TRUE;
																																																																																																																																																																																																			//printf("\nDebug Of I/O Timing Data Enabled.");
																																																																																																																																																																																																			//Control_Trace(1, Port);
																																																																																																																																																																																																			//printf("\nNTDS Trace Enabled.\n");
																																																																																																																																																																																																			*
																																																																																																																																																																																																			* SYNOPSIS: Stop_IO_Timing_Data_Capture
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*  DESCRIPTION:    This function turns off the capture of task switch info,
																																																																																																																																																																																																			*                  Interrupt and all IO timing.
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*  PARAMETERS:
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*      INPUT : NONE
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*      OUTPUT : NONE
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*    RETURNS   NONE.
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*########################################################################*/
																																																																																																																																																																																																			//Task_Trace_Hook(0);
																																																																																																																																																																																																			//Debug_Interrupts = 0;
																																																																																																																																																																																																			//printf("\nDebug Interrupts Disabled");
																																																																																																																																																																																																			//Unhook_Task_Switching();
																																																																																																																																																																																																			//printf("\nDebug Of Task Swapping Disabled.");
																																																																																																																																																																																																			//NTDS_Timing_Study_In_Progress = FALSE;
																																																																																																																																																																																																			//printf("\nDebug Of I/O Timing Data Disabled.");
																																																																																																																																																																																																			//Control_Trace(0, 0);
																																																																																																																																																																																																			//printf("\nNTDS Trace Disabled.\n");
																																																																																																																																																																																																			*
																																																																																																																																																																																																			* SYNOPSIS:   Get_Board_Driver_Type
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*  DESCRIPTION:    This function returns the NTDS board driver type.
																																																																																																																																																																																																			*                  Sometimes apps need to know what kind of NTDS board
																																																																																																																																																																																																			*                  they're talking to.  A call to this function will
																																																																																																																																																																																																			*                  return that information.
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*  PARAMETERS:
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*      INPUT : port - port number associated with the NTDS board of interest.
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*      OUTPUT : NONE
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*    RETURNS   the driver-type of the NTDS board associated with the input port.
																																																																																																																																																																																																			*
																																																																																																																																																																																																			*########################################################################*/
																																																																																																																																																																																																			return(device_config[Port].board.driver_type);
