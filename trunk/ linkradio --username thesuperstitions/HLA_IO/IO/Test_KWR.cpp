#include <vxWorks.h>
#include "ntdsTypes.h"
#include "stdio.h"
#include "ntds_config.h"

#include "ntds_comm_.h"


//******************************************************************************
// Used by Framework.
#include "InterprocessQueue.h"
static framework::utils::InterprocessQueue* publishQueue;
static framework::utils::InterprocessQueue* subscribeQueue;
//******************************************************************************
/**********************************************************************
 * Constant Definitions for the NTDS COMMUNICATIONS Package Body only *
 **********************************************************************/
 
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
          printf(
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
      printf(
        "NTDS:Get_Device_Configuration-Device=%d, Port=%c, Device Not Configured",
        device, 'A'+port);
      return (INVALID_DEVICE);
    }
  }
  else
  {
    printf(
      "NTDS:Get_Device_Configuration-Device=%d, Port=%c  UNKNOWN DEVICE",
      device, 'A'+port);
    return (status);
  }
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
find_mt_index (int port, unsigned int mt, int *index_ptr)
{
  int i;
  int last_one;

  if (mt == 0)
  {
    printf(
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
        printf("NTDS:Configure_NTDS_Device-Device=%d  Device table Full Norm=%d Alt=%d New=%d",
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
      printf("NTDS:Configure_NTDS_Device-Device=%d  Found First Board at Address 0x%x", 
        device,
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

      char s[200];
  
      sprintf(s, "Unit%u-%s-Publisher", device_ptr->enet_port, device_ptr->name_string);
      publishQueue = new framework::utils::InterprocessQueue(s, INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES, 
        INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE);

      sprintf(s, "Unit%u-%s-Subscriber", device_ptr->enet_port, device_ptr->name_string);
      subscribeQueue = new framework::utils::InterprocessQueue(s, INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES, 
        INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE);
      //***************************************************************************
    }
    /*  Initialize global values   */
    device_ptr = device_ptr->next;
  }

  return (return_code);
}
