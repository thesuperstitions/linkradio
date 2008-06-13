#ifdef __cplusplus
extern "C" {
#endif


/*
 *                             COPYRIGHT NOTICE
 *
 *Developed by The Johns Hopkins University/Applied Physics Laboratory (JHU/APL)
 * Copyright (c) 1996 The Johns Hopkins University/Applied Physics Laboratory
 *
 * Permission to copy all or part of this work is granted, provided that 
 * the copies are made or distributed only for the CEC project 
 * and that this copyright notice is reproduced on all such copies.  This 
 * material may be reproduced by or for the U.S. Government pursuant to the
 * copyright license under the clause at DFARS 252.227-7013 (OCT 1988).
 * For any other permissions please contact the CEC Program Office at JHU/APL.
 *
 *
static char ntds_drivers_h[] = "$Header: /cec/generic/delivered/ntds_common/incl/RCS/ntds_drivers.h,v 5.5 1999/12/15 18:59:27 ceplib Exp $";
 ************************************************************************
 * Developed by The Johns Hopkins University/Applied Physics Laboratory
 *
 *  Project:    NTDS Interface Driver for NTDS Interface Boards
 *
 *  Module Name:  ntds_drivers.h  ( NTDS Driver Common definitions )
 *
 *	Synopsis (Usage and Parameters):
 *              See content.
 *
 *
 *	Description:
 *		This include file contains:
 *			a) constant definitions for use with the NTDS interface driver
 *			   packages.
 *
 *
 *	Files:
 *           	nio_driver.c
 *           	vme_driver.c
 *
 *
 *	Programmer:	R.A. Beseke
 *	Organization:	JHU/APL
 *	Host System:	Sun 4/SunOS 4.1.2
 *	Language:	C
 *	Date Created:   11-20-90
 *	Reviewed:		By: No One
 *	Modifications:
 *
 * $Log: ntds_drivers.h,v $
 * Revision 5.5  1999/12/15 18:59:27  ceplib
 * Modified to compile under the Green Hills C and C++ compilers, as well as
 * under the GNU C and C++ compilers IAW TR#4387.  adb
 *
 * Revision 5.4  1999/05/12 14:24:47  ceplib
 * Added Send_CV_OB and Get_CV_IB definitions IAW SPR#844.  adb
 *
 * Revision 5.3  1996/04/12  17:04:22  ceplib
 * Modified copyright notice IAW TR#2702.  adb
 *
 * Revision 5.2  1996/04/11  19:20:03  ceplib
 * Added copyright notice to file IAW TR#2702.  adb
 *
 * Revision 5.1  1996/02/14  12:50:47  ceplib
 * Modified to support the expanded capability of the the NTDS trace package
 * IAW TR#2604.  adb
 *
 * Revision 5.0  1996/01/30  17:30:29  ceplib
 * The TASCDS device id was modified to be compatible with the TAS application
 * IAW TR#2559.  adb
 *
 *
 */



   /*  The maximum number of NTDS ports allowed for a host to service */

#define A_PORT 0      /* used as logical indexes into device tables */
#define B_PORT 1
#define C_PORT 2
#define D_PORT 3
#define E_PORT 4
#define F_PORT 5
#define G_PORT 6
#define H_PORT 7
#define I_PORT 8
#define J_PORT 9
#define K_PORT 10
#define L_PORT 11
#define M_PORT 12
#define N_PORT 13
#define O_PORT 14
#define P_PORT 15
#define Q_PORT 16
#define R_PORT 17
#define S_PORT 18
#define T_PORT 19
#define U_PORT 20

#define NTDS_FAST        0
#define NTDS_SLOW        1
#define NTDS_ANEW        2
#define NTDS_SERIAL      3
#define NTDS_NATO_SERIAL 4

     /* These are used by the various driver board detectors.
      *
      * WARNING  WARNING  WARNING  WARNING  WARNING  WARNING
      *
      * These values MUST NOT BE USED to initialize an interface.
      * They are used to report a NTDS card's configuration.
      */
#define NTDS_FAST_SLOW      10
#define NTDS_FAST_SLOW_ANEW 11

 
     /* The following categories are used to configure the NTDS card
      * for the selected type of data transfers.
      */
#define COMP_PERIPH    0    /* Field for Catagory 0, Loop back
                             * peripheral/computer mode */
#define COMPUTER       1    /* Field for Catagory 1,normal computer mode */
#define INTERCOMPUTER  2    /* Field for Catagory 2,normal intercomputer mode */
#define PERIPHERAL     3    /* Field for Catagory 3,normal peripheral mode */

#define LLS_POLLED         4       /* Field for Catagory 4,LLS Polled Mode */
#define LLS_BURST          5       /* Field for Catagory 5,LLS Burst Mode */
#define LLS_BURST_PARITY   6       /* Field for Catagory 6,LLS Parity Mode */
#define LLS_POLLED_PARITY  7       /* Field for Catagory 7,LLS Burst/Parity Mode */


#define NTDS_MODE 0    /* Uses the NTDS board for interfacing */
#define VME_MODE  1    /* Uses VME backplane for interfacing */

              /* Determines the type of EI processing to be used */
#define AUTO_EI_MODE   0  /*  The user will dequeue EIs routed by the driver */
#define MANUAL_EI_MODE 1  /*  The user will use the Get_EI function  */

#define NORMAL_EF  0
#define FORCED_EF  1

    /* The following macros are used by only the nio driver */ 
 
#define NTDS_CLOCK_RATE  1000000 /* This is the clock frequency of the 
                                  * real time clock. 1 usec period
                                 */ 
  
#define MAX_TIME_DELAY  5000000 /*  Set an arbitrary value of 5 seconds
                                 * to make sure the user doesn't go crazy 
                                 * with this time delay stuff.  It is also a 
                                 * sanity check to make sure he or she 
                                 * initialized the variable. 
                                 */ 

            /* The maxmium number of EIs that we will keep track of in
             * the input buffer.
             */
#define MAX_EI_INDEX  7

    /* The following definitions are used when creating a NTDS EI queue.  The
     * first parameter is placed at the end of a message list when a queue
     * is created.  The latter definition defines the EI type for an error
     * queue.  The latter definition should only be used with a message list of
     * one terminated with an EI_LIST_END.
     */

#define EI_LIST_END          0
#define NTDS_ERR_QUE_EI     -1


       /* This parameter determines the number of I/O operations allowed on 
        * most if not all of the NTDS cards.  The name is a carryover from
        * the first driver (nio_driver).
        */
#define NUM_OF_IO_CHAINS  5

       /*********************
        * NTDS EVENT FLAGS  *
        *********************/
/*********************************************************************
 *
 *   The following event codes are used by the device driver
 *
 ***********************************************************************/
#define NIO_CMPLT           0
#define NIO_FAULT           1
#define NIO_BUSY            2
#define NIO_TIMEOUT         3
#define NIO_TERM            4
#define NIO_CMD_FAULT       5
#define NIO_DATA_FAULT      6
#define NIO_EI_FAULT        7
#define LLS_SINK_FAULT      8
#define LLS_SOURCE_FAULT    9
#define LLS_SINK_TIMEOUT   10
#define LLS_SOURCE_TIMEOUT 11
#define LLS_SINK_TERM      12


#define UNLOCK 0      /* used by the EI locking function  */
#define LOCK   1


	/************************************
	 * Function Return Code Definitions *
	 ************************************/
#define INVALID_PORT                0x1000
#define PORT_NOT_LINKED             0x1010
#define INVALID_QID                 0x1020
#define ILLEGAL_MODE                0x1030
#define INVALID_WDSIZE              0x1040
#define INVALID_EI_MODE             0x1050
#define NO_MEMORY_POOL              0x1060
#define NTDS_DRIVER_NOT_IMPLEMENTED 0x1070


        /*******************************
         * Driver Command ERROR codes  *
         * generated for service cmds  *
	      ******************************/
#define BCW_IN_ERR         0x2000
#define BCW_OUT_ERR        0x2100
#define BCW_EF_ERR         0x2200
#define BCW_EI_ERR         0x2300
#define TERM_IN_ERR        0x2400
#define TERM_OUT_ERR       0x2500
#define TERM_EF_ERR        0x2600
#define TERM_EI_ERR        0x2700
#define READ_RTC_ERR       0x2800
#define SET_RTC_ERR        0x2900
#define LONG_ALIGN_ERR     0x3000
#define LOCK_ADR_ERR       0x3100
#define SET_RTC_ACTIVE_ERR 0x3200
#define GET_EI_ACTIVE_ERR  0x3300
#define GET_IB_ACTIVE_ERR  0x3400
#define GET_BCW_ERR        0x3500
#define SET_MODE_ERR       0x3600
#define SET_TERM_ACT_ERR   0x3700
#define SEND_OB_ACTIVE_ERR 0x3800
#define SEND_EF_ACTIVE_ERR 0x3900
#define EI_LOCK_ERR        0x4000
#define SECOND_EI_ERR      0x4100
#define EI_COUNT_ERR       0x4200
#define INVALID_CHAIN      0x4300
#define PASSIVE_MODE_ERR   0x4400
#define PASSIVE_PORT_ERR   0x4500


   /**********************************************
    *   Types and structures used by NTDS driver *
    **********************************************/

union config {
 
   struct   /* structure of NIO Configuration */
   {
 
      unsigned int bus_type;
      unsigned int board_address;
      unsigned int host_board_address;
      unsigned int                    :  3,
                io_mode               :  4, /* CAT I, CAT II, CAT III */
                host_interrupt_level  :  3, /* VME driver host        */
                interrupt_level       :  3, /* VME interrupt level    */
                manual_ei_mode        :  1, /* Auto or Manual         */
                word_size             :  4, /* BYTE, WORD, LONG WORD  */
                int_enable            :  1, /* Enable interrupts T/F  */
                passive_mode          :  1, /* Use passive tap        */
                driver_type           :  4, /* NTDS or VME            */
                secondary_driver_type :  4, /* NTDS or VME            */
                init_mode             :  2; /* LOCAL, REMOTE, or TEST */

      float        prom_rev;
      unsigned int part_no;
      unsigned short io_type;
      unsigned char  io_active;
   } config;
 
   struct
   {
      unsigned int bus_type;
      unsigned int board_address;
      unsigned int host_board_address;
      unsigned int config;
      float        prom_rev;
      unsigned int part_no;
      unsigned short io_type;
      unsigned char  io_active;
   } nio;
};    
 
typedef union config NIO_CONFIG;
 

typedef struct   /* structure of BCW */
{
    short int    command,
                 count;
    unsigned int bufadrs,
                 chnadrs;
} BCW_Format;
 
/***** define message packets for EIs **********/

typedef struct {
       int ei_word;
       int nio_time;
       } EI_MESSAGES;

#define EI_MESSAGES_SIZE	sizeof(EI_MESSAGES)


/*#########################################################################
 *
 *  SYNOPSIS:      Configure_NTDS_Driver
 *
 *  DESCRIPTION:   This function initializes the NTDS board to the NTDS
 *                 mode and transfer parameters defined by the user.  This
 *                 function also enables the VME or VSB interrupt on the
 *                 host processor board to accept interrupts from the NTDS
 *                 board.
 *
 *  PARAMETERS:
 *
 *     INPUT   port :  This parameter defines the NTDS board that will be
 *                     used by the driver.
 *
 *             bus_type : This parameter determines whether the NTDS board
 *                        is on the VME or VSB bus.
 *
 *             NIO_board_address : This parameter is the VME or VSB base address
 *                                 of the NTDS board.
 *
 *             vme_int_level :  This value determines what VME interrupt line
 *                              will be used to interrupt the host processor.
 *                              The range of this variable is 1..7
 *
 *             ei_mode :  This parameter determines whether the automatic
 *                        queuing feature or if the manual (Get_EI) function
 *                        will be used.  The parameter definitions are
 *                        MANUAL_EI_MODE or AUTO_EI_MODE.
 *
 *             word_size : This parameter determines the bus width for NTDS
 *                         transfers.  The two options are WORD_16 or WORD_32.
 *
 *             ntds_mode : This parameter determines the mode of operation of
 *                         the NTDS interface board.  The three choices for
 *                         parallel interfaces are:
 *                                 COMPUTER
 *                                 INTERCOMPUTER
 *                                 PERIPHERAL
 *                          The four choices for Low Level Serial (LLS)
 *                          Type E interfaces are:
 *                                  LLS_BURST
 *                                  LLS_POLLED
 *                                  LLS_BURST_PARITY
 *                                  LLS_POLLED_PARITY
 *
 *             int_enable : This parameter determines if the host interrupts
 *                          shall be enabled during this initialization.
 *                          This value shall be TRUE when configuring the
 *                          last board of a specific interrupt level.
 *
 *     OUTPUT :  NOTHING
 *
 *     RETURNS OK
 *             INVALID_PORT
 *             INVALID_WDSIZE
 *             ILLEGAL_MODE
 *             subordinate function error codes
 *
 *#########################################################################*/
int
Configure_NTDS_Driver (
   int           port,
   NIO_BD_CONFIG port_config
);

/*#########################################################################
 *
 * SYNOPSIS:     NTDS_Debug
 *
 * DESCRIPTION:  This function writes a value to a selected NIO board.  The
 *               port is determined by the caller.  This function writes to
 *               the selected port's RESET address so the user can write any
 *               value except 0x808 which is a reset command.
 *
 *               This function also saves the value in the nio_trace buffer.
 *
 * PARAMETERS:
 *
 *   INPUT  port : The board that will be accessed.
 *
 *          value1 : The value to be written to the NIO board.  This value
 *                   is also saved in the nio trace buffer.
 *
 *          value2 : This value is saved in the bufaddr field of the trace
 *                   buffer sample.
 *
 *          value3 : This value is saved in the count field of the trace
 *                   buffer sample.
 *
 *   OUTPUT NOTHING
 *
 *   RETURNS  NOTHING
 *
 *######################################################################### */
void
NTDS_Debug (
   int port,
   int value1,
   int value2,
   short int value3
);

/*#########################################################################
 *
 * SYNOPSIS:     Reset_NTDS_Board
 *
 * DESCRIPTION:  This function passes a Master Reset command to the requested
 *               NTDS Board.
 *
 * PARAMETERS:
 *
 *   INPUT  port : The board that will be RESET.
 *
 *   OUTPUT NOTHING
 *
 *   RETURNS   NOTHING
 *
 *######################################################################### */
void
Reset_NTDS_Board (
	int	port
);

/*#########################################################################
 *
 * SYNOPSIS:     Warm_Reset_NTDS_Board
 *
 * DESCRIPTION:  This function passes a Master Reset command to the requested
 *               NTDS Board and restarts the EI chain if the Auto_EI_Mode
 *               is set.
 *
 * PARAMETERS:
 *
 *   INPUT  port : The board that will be RESET.
 *
 *   OUTPUT NOTHING
 *
 *   RETURNS   OK
 *             Status of subordinate functions
 *
 *######################################################################### */
int
Warm_Reset_NTDS_Board (
   int port
);

/*#########################################################################
 *
 * SYNOPSIS:     Wrap_Init_NTDS_Board
 *
 * DESCRIPTION:  This function configures the NTDS Board for wrap test.
 *
 * PARAMETERS:
 *
 *   INPUT  port : The board that will be RESET.
 *
 *   OUTPUT NOTHING
 *
 *   RETURNS   OK
 *             vxWorks Error Status
 *             Status of subordinate functions
 *
 *######################################################################### */
int
Wrap_Init_NTDS_Board (
   int port
);

/*#########################################################################
 *
 * SYNOPSIS:     Get_NTDS_Configuration
 *
 * DESCRIPTION:  This function returns the board current board configuration
 *               of an NTDS board.
 *
 * PARAMETERS:
 *
 *   INPUT  port : The board that will be read.
 *
 *   OUTPUT  board_config :  The current configuration of the NIO board.
 *
 *   RETURNS   OK
 *             INVALID_PORT
 *
 *######################################################################### */
int
Get_NTDS_Configuration (
   int        port,
   NIO_CONFIG *board_config_ptr
);

/*#########################################################################
 *
 * SYNOPSIS: Get_RTC
 *
 * DESCRIPTION:  This function reads the Real Time Clock of a selected board.
 *
 * PARAMETERS:
 *
 *   INPUT   port : This variable determines which board will be accessed.
 *
 *   OUTPUT  NOTHING
 *
 *   RETURNS  The RTC value.
 *
 * ######################################################################### */
unsigned int
Get_RTC (
	int	port
);

/*#########################################################################
 *
 * SYNOPSIS:  Set_RTC
 *
 * DESCRIPTION:  This function sets the Real Time Clock on a selected NTDS
 *               board to a value provided by the caller.
 *
 * PARAMETERS:
 *
 *    INPUT  port : This parameter determines which board's clock will be set.
 *
 *           rtc  : This parameter contains the new Real Time Clock value.
 *
 *    OUTPUT   NOTHING
 *
 *    RETURNS  OK
 *             SET_RTC_ACTIVE_ERR
 *             PASSIVE_MODE_ERR
 *
 * ######################################################################### */
int
Set_RTC (
	int	       port,
	unsigned int rtc
);

/*#########################################################################
 *
 * SYNOPSIS: Send_OB
 *
 * DESCRIPTION:     This function transfers normal NTDS data buffers to a
 *              remote NTDS device.  The user provides the address of the
 *              buffer, the buffer size, and a timeout parameter.
 *
 *                  The caller may also provide a delay time that may be used
 *              to ensure that an output buffer are properly spaced a minimum
 *              amount of time.
 *
 *                  In return the driver will return the status of the request
 *              along with a transfer count and time stamp of when the buffer
 *              was completed or terminated.
 *
 *                  The user may also provide a list of EI codes that will be
 *              unlocked when the transfer request is complete.  See the
 *              Change_EI_Lock function.
 *
 *                  The user may also provide a user function which will
 *              be executed when the buffer is completed or terminated.
 *
 *                  This function is not reentrant.  Any calls made to this
 *              function while another process is receiving a buffer will be
 *              blocked until the resource is available or the timeout has
 *              expired.  If the timeout expires, an error is returned to the
 *              caller.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          *mesg_packet :   This parameter is a pointer to a structure that
 *                         contains the information necessary for the driver
 *                         to send a data buffer and return the appropriate
 *                         responses.  The caller must reserve memory for
 *                         storage of information in this parameter.  The
 *                         packet variable contains the following information:
 *
 *                            *address :  A pointer to the data buffer.  This
 *                                        address MUST be long aligned.
 *
 *                            req_size :  The size of the data buffer in the
 *                                        word size of the NTDS transfer size.
 *
 *                         delay_time  :    The amount of time to delay before
 *                                        starting the output.  This delay is
 *                                        computed from the previous output
 *                                        request.  This value has a granularity
 *                                        of 10 usecs. The NTDS RTC is used
 *                                        to measure this delay.
 *
 *                            tfr_size :  The number of words actually
 *
 *                            time_out :  The amount of time to wait for a
 *                                        transfer to complete in vxWorks ticks.
 *
 *                         retry_count :  The number of times to retry to complete the
 *                                        transmission, if a failure other than a timeout
 *                                        occurs.
 *
 *                            buf_time :  The time when the buffer transfer
 *                                        completed or was terminated.
 *
 *         *lock_adr_list_ptr :   This parameter is a pointer to a list of
 *                         pointers that contain the addresses of EIs that
 *                         will be unlocked when the output transfer is
 *                         complete. The list of pointers must have a NULL
 *                         pointer at the end to allow the Change_EI_Lock
 *                         function to determine the end of the list.  See
 *                         Change_EI_Lock function.
 *
 *                             If the user does not desire to use this
 *                         capability a NULL pointer should be passed when
 *                         the function is invoked.
 *
 *         *user_intrpt_func_ptr :   This parameter is a pointer to a user
 *                             function that will be invoked upon completion
 *                             of the buffer transfer.  It should be noted
 *                             that this function will be executed in an ISR
 *                             so processing should be kept to a minimum.
 *
 *                                If the user does not want to use this
 *                             capability a NULL pointer should be passed when
 *                             called.
 *
 * OUTPUT : Information is returned in the mesg_packet variable. As described
 *          previously.
 *
 * RETURNS  OK
 *          GET_OB_ACTIVE_ERR
 *          subordinate function returns
 *          vxWorks error codes
 *          PASSIVE_PORT_ERR
 *
 *######################################################################### */
int
Send_OB (
	int          port,
	NIO_MESG     *msg_packet_ptr,
	unsigned int **lock_adr_list_ptr,
	void	       (*user_intrpt_func_ptr) (int)
);

/*#########################################################################
 *
 * SYNOPSIS: Send_CV_OB
 *
 * DESCRIPTION:     This function transfers normal NTDS data buffers to a
 *              remote NTDS device.  The user provides the address of the
 *              buffer, the buffer size, and a timeout parameter.
 *
 *                  The message is transferred to the remote NTDS device
 *              one word at a time with a delay in between each word
 *              transmission.
 *
 *                  In return the driver will return the status of the request
 *              along with a transfer count and time stamp of when the buffer
 *              was completed or terminated.
 *
 *                  The user may also provide a list of EI codes that will be
 *              unlocked when the transfer request is complete.  See the
 *              Change_EI_Lock function.
 *
 *                  The user may also provide a user function which will
 *              be executed when the buffer is completed or terminated.
 *
 *                  This function is not reentrant.  Any calls made to this
 *              function while another process is receiving a buffer will be
 *              blocked until the resource is available or the timeout has
 *              expired.  If the timeout expires, an error is returned to the
 *              caller.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          *mesg_packet :   This parameter is a pointer to a structure that
 *                         contains the information necessary for the driver
 *                         to send a data buffer and return the appropriate
 *                         responses.  The caller must reserve memory for
 *                         storage of information in this parameter.  The
 *                         packet variable contains the following information:
 *
 *                            *address :  A pointer to the data buffer.  This
 *                                        address MUST be long aligned.
 *
 *                            req_size :  The size of the data buffer in the
 *                                        word size of the NTDS transfer size.
 *
 *                         delay_time  :    The amount of time to delay before
 *                                        starting the output.  This delay is
 *                                        computed from the previous output
 *                                        request.  This value has a granularity
 *                                        of 10 usecs. The Antares RTC is used
 *                                        to measure this delay.
 *
 *                            tfr_size :  The number of words actually
 *
 *                            time_out :  The amount of time to wait for a
 *                                        transfer to complete in vxWorks ticks.
 *
 *                         retry_count :  The number of times to retry to 
 *                                        complete the transmission, if a  
 *                                        failure other than a timeout occurs.
 *
 *                            buf_time :  The time when the buffer transfer
 *                                        completed or was terminated.
 *
 *         *lock_adr_list_ptr :   This parameter is a pointer to a list of
 *                         pointers that contain the addresses of EIs that
 *                         will be unlocked when the output transfer is
 *                         complete. The list of pointers must have a NULL
 *                         pointer at the end to allow the Change_EI_Lock
 *                         function to determine the end of the list.  See
 *                         Change_EI_Lock function.
 *
 *                             If the user does not desire to use this
 *                         capability a NULL pointer should be passed when
 *                         the function is invoked.
 *
 *         *user_intrpt_func_ptr :   This parameter is a pointer to a user
 *                             function that will be invoked upon completion
 *                             of the buffer transfer.  It should be noted
 *                             that this function will be executed in an ISR
 *                             so processing should be kept to a minimum.
 *
 *                                If the user does not want to use this
 *                             capability a NULL pointer should be passed when
 *                             called.
 *
 * OUTPUT : Information is returned in the mesg_packet variable. As described
 *          previously.
 *
 * RETURNS  OK
 *          GET_OB_ACTIVE_ERR
 *          subordinate function returns
 *          vxWorks error codes
 *          PASSIVE_PORT_ERR
 *
 *######################################################################### */
int
Send_CV_OB (
	int          port,
	NIO_MESG     *msg_packet_ptr,
	unsigned int **lock_adr_list_ptr,
	void	       (*user_intrpt_func_ptr) (int)
);

/*#########################################################################
 *
 * SYNOPSIS: Get_IB
 *
 * DESCRIPTION:     This function receives NTDS data buffers from a
 *              remote NTDS device.  The user provides the address of the
 *              buffer, the buffer size, and a timeout parameter.
 *
 *                  In return the driver will return the status of the request
 *              along with a transfer count and time stamp of when the buffer
 *              was completed or terminated.
 *
 *                  This function is not reentrant.  Any calls made to this
 *              function while another process is receiving a buffer will be
 *              blocked until the resource is available or the timeout has
 *              expired.  If the timeout expires, an error is returned to the
 *              caller.
 *
 *                  The user may also provide a list of EI codes that will be
 *              unlocked when the transfer request is complete.  See the
 *              Change_EI_Lock function.
 *
 *                  The user may also provide a user function which will
 *              be executed when the buffer is completed or terminated.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          *mesg_packet : This parameter is a pointer to a variable that
 *                         contains the information necessary for the driver
 *                         to receive a data buffer and return the appropriate
 *                         responses.  The packet variable contains the
 *                         following information:
 *
 *                            *address :  A pointer to the data buffer.  This
 *                                        address MUST be long aligned.
 *
 *                            req_size :  The size of the data buffer in the
 *                                        word size of the NTDS transfer size.
 *
 *                            time_out :  The amount of time to wait for a
 *                                        transfer to complete in vxWorks ticks.
 *
 *                            NOTE : A value of zero in the timeout field will
 *                                   cause the function to wait forever for a
 *                                   response.
 *
 *                            NOTE : This function call should have a finite
 *                                   timeout value to eliminate the possibility
 *                                   of deadlock.
 *
 *                            tfr_size :  The number of words actually
 *                                        transferred.
 *
 *                            buf_time :  The time when the buffer transfer
 *                                        completed or was terminated.
 *
 *         *lock_adr_list_ptr :   This parameter is a pointer to a list of
 *                         pointers that contain the addresses of EIs that
 *                         will be unlocked when the input transfer is
 *                         complete. The list of pointers must have a NULL
 *                         pointer at the end to allow the Change_EI_Lock
 *                         function to determine the end of the list.  See
 *                         Change_EI_Lock function.
 *
 *                             If the user does not desire to use this
 *                         capability a NULL pointer should be passed when the
 *                         function is invoked.
 *
 *         *user_intrpt_func_ptr :   This parameter is a pointer to a user
 *                             function that will be invoked upon completion
 *                             of the buffer transfer.  It should be noted that  *                             this function will be executed in an ISR so
 *                             processing should be kept to a minimum.
 *
 *                                If the user does not want to use this
 *                             capability a NULL pointer should be passed when
 *                             called.
 *
 * OUTPUT : Information is returned in the mesg_packet variable. As described
 *          previously.
 *
 * RETURNS  OK
 *          GET_IB_ACTIVE_ERR
 *          subordinate function returns
 *          vxWorks error codes
 *
 *######################################################################### */
int
Get_IB (
	int	       port,
	NIO_MESG     *msg_packet_ptr,
	unsigned int **lock_adr_list_ptr,
	void	       (*user_intrpt_func_ptr) (int)
);

/*#########################################################################
 *
 * SYNOPSIS: Get_CV_IB
 *
 * DESCRIPTION:     This function receives NTDS data buffers from a
 *              remote NTDS device.  The user provides the address of the
 *              buffer, the buffer size, and a timeout parameter.
 *
 *                  In return the driver will return the status of the request
 *              along with a transfer count and time stamp of when the buffer
 *              was completed or terminated.
 *
 *                  This function is not reentrant.  Any calls made to this
 *              function while another process is receiving a buffer will be
 *              blocked until the resource is available or the timeout has
 *              expired.  If the timeout expires, an error is returned to the
 *              caller.
 *
 *                  The user may also provide a list of EI codes that will be
 *              unlocked when the transfer request is complete.  See the
 *              Change_EI_Lock function.
 *
 *                  The user may also provide a user function which will
 *              be executed when the buffer is completed or terminated.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          *mesg_packet : This parameter is a pointer to a variable that
 *                         contains the information necessary for the driver
 *                         to receive a data buffer and return the appropriate
 *                         responses.  The packet variable contains the
 *                         following information:
 *
 *                            *address :  A pointer to the data buffer.  This
 *                                        address MUST be long aligned.
 *
 *                            req_size :  The size of the data buffer in the
 *                                        word size of the NTDS transfer size.
 *
 *                            time_out :  The amount of time to wait for a
 *                                        transfer to complete in vxWorks ticks.
 *
 *                            NOTE : A value of zero in the timeout field will
 *                                   cause the function to wait forever for a
 *                                   response.
 *
 *                            NOTE : This function call should have a finite
 *                                   timeout value to eliminate the possibility
 *                                   of deadlock.
 *
 *                            tfr_size :  The number of words actually
 *                                        transferred.
 *
 *                            buf_time :  The time when the buffer transfer
 *                                        completed or was terminated.
 *
 *         *lock_adr_list_ptr :   This parameter is a pointer to a list of
 *                         pointers that contain the addresses of EIs that
 *                         will be unlocked when the input transfer is
 *                         complete. The list of pointers must have a NULL
 *                         pointer at the end to allow the Change_EI_Lock
 *                         function to determine the end of the list.  See
 *                         Change_EI_Lock function.
 *
 *                             If the user does not desire to use this
 *                         capability a NULL pointer should be passed when the
 *                         function is invoked.
 *
 *         *user_intrpt_func_ptr :   This parameter is a pointer to a user
 *                             function that will be invoked upon completion
 *                             of the buffer transfer.  It should be noted that  *                             this function will be executed in an ISR so
 *                             processing should be kept to a minimum.
 *
 *                                If the user does not want to use this
 *                             capability a NULL pointer should be passed when
 *                             called.
 *
 * OUTPUT : Information is returned in the mesg_packet variable. As described
 *          previously.
 *
 * RETURNS  OK
 *          GET_IB_ACTIVE_ERR
 *          subordinate function returns
 *          vxWorks error codes
 *
 *######################################################################### */
int
Get_CV_IB (
	int	       port,
	NIO_MESG     *msg_packet_ptr,
	unsigned int **lock_adr_list_ptr,
	void	       (*user_intrpt_func_ptr) (int)
);
/*#########################################################################
 *
 * SYNOPSIS: Send_EF
 *
 * DESCRIPTION:     This function transfers external function buffers to a
 *              remote NTDS device.  The user provides the address of the
 *              buffer, the buffer size, and a timeout parameter.
 *
 *                  The caller may also provide a delay time that may be used
 *              to ensure that an output buffer are properly spaced a minimum
 *              amount of time.
 *
 *                  In return the driver will return the status of the request
 *              along with a 1ransfer count and time stamp of when the buffer
 *              was completed or terminated.
 *
 *                 The user provides a parameter that will determine if the
 *              information will be sent with force or as a normal transfer.
 *
 *                  This function is not reentrant.  Any calls made to this
 *              function while another process is receiving a buffer will be
 *              blocked until the resource is available or the timeout has
 *              expired.  If the timeout expires, an error is returned to the
 *              caller.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          *mesg_packet : This parameter is a pointer to a structure that
 *                         contains the information necessary for the driver
 *                         to send the EF buffer and return the appropriate
 *                         responses.  The user must allocate memory for
 *                         storage of information in this parameter.  The
 *                         packet variable contains the following information:
 *
 *                            *address :  A pointer to the data buffer.  This
 *                                        address MUST be long aligned.
 *
 *                            req_size :  The size of the data buffer in the
 *                                        word size of the NTDS transfer size.
 *
 *                          delay_time :    The amount of time to delay before
 *                                        starting the output.  This delay is
 *                                        computed from the previous output
 *                                        request.  This value has a granularity
 *                                        of 10 usecs. The NTDS RTC is used
 *                                        to measure this delay.
 *
 *                            tfr_size :  The number of words actually
 *
 *                            time_out :  The amount of time to wait for a
 *                                        transfer to complete in vxWorks ticks.
 *
 *                            NOTE : This function call should have a finite
 *                                   timeout value to eliminate the possibility
 *                                   of deadlock.  This situation may occur if
 *                                   the Anatres board does not return an
 *                                   interrupt status of the transfer command,
 *                                   resulting in future output requests to be
 *                                   suspended.
 *
 *                         retry_count :  The number of times to retry to complete the
 *                                        transmission, if a failure other than a timeout
 *                                        occurs.
 *
 *                            buf_time :  The time when the buffer transfer
 *                                        completed or was terminated.
 *
 *         forced :     This parameter determines physical transfer
 *                   operation of the EF words.  If FORCE is true (FORCED_EF),
 *                   the hardware will send the EF data without waiting for an
 *                   External Function request.  On the other hand, if FORCE
 *                   is false (NORMAL_EF) the EF data will be transferred
 *                   using the normal NTDS handshake convention.
 *
 * OUTPUT : Information is returned in the mesg_packet variable. As described
 *          previously.
 *
 * RETURNS  OK
 *          PASSIVE_PORT_ERR
 *          SEND_EF_ACTIVE_ERR
 *          suborinate function returns
 *          vxWorks error codes
 *
 *######################################################################### */
int
Send_EF (
    int          port,
    NIO_MESG     *msg_packet_ptr,
    unsigned int forced
);

/****************************************************************************
 *
 * SYNOPSIS: Get_EI
 *
 * DESCRIPTION:     This function receives external function buffers from a
 *              remote NTDS device.  The user provides the address of the
 *              buffer, the buffer size, and a timeout parameter.
 *
 *                  In return the driver will return the status of the request
 *              along with a transfer count and time stamp of when the buffer
 *              was completed or terminated.
 *
 *                  This function is not reentrant.  Any calls made to this
 *              function while another process is receiving a buffer will be
 *              blocked until the resource is available or the timeout has
 *              expired.  If the timeout expires, an error is returned to the
 *              caller.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          *mesg_packet : This parameter is a pointer to a variable that
 *                         contains the information necessary for the driver
 *                         to send the EF buffer and return the appropriate
 *                         responses.  The packet variable contains the
 *                         following information:
 *
 *                            *address :  A pointer to the data buffer.  This
 *                                        address MUST be long aligned.
 *
 *                            req_size :  The size of the data buffer in the
 *                                        word size of the NTDS transfer size.
 *
 *                            time_out :  The amount of time to wait for a
 *                                        transfer to complete in vxWorks ticks.
 *
 *                            tfr_size :  The number of words actually
 *                                        transferred.
 *
 *                            buf_time :  The time when the buffer transfer
 *                                        completed or was terminated.
 *
 * OUTPUT : Information is returned in the mesg_packet variable. As described
 *          previously.
 *
 * RETURNS  OK
 *          INVALID_EI_MODE
 *          GET_EI_ACTIVE_ERR
 *          vxWorks error codes
 *
 *######################################################################### */
int
Get_EI (
	int		port,
	NIO_MESG	*msg_packet_ptr
);

/*#########################################################################
 *
 * SYNOPSIS: Nio_Wait
 *
 * DESCRIPTION:     This function takes an application request to
 *              wait a specified period of time defined in tens (10s) of
 *              microseconds.  The value is passed in the delay_time parameter
 *              of the NIO_MESG structure.
 *
 *              This function will return upon completion of the
 *              time delay specified, assuming the time_out value is
 *              sufficiently long enough to ensure the delay can be realized.
 *
 *                  The caller also provides the NTDS Chain register to be
 *              used.  This is because NTDS board's command register can not
 *              execute DELAY instructions directly.
 *
 *                  This function is not reentrant.  Any calls made to this
 *              function while another process is receiving a buffer will be
 *              returned with a busy status if the resource does not become
 *              available within the timeout period.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          *mesg_packet : This parameter is a pointer to a variable that
 *                         contains the information necessary for the driver
 *                         to receive a data buffer and return the appropriate
 *                         responses.  The packet variable contains the
 *                         following information:
 *
 *                            delay_time :  The amount of time to delay before
 *                                        returning to the caller.
 *
 *                            time_out :  The amount of time to wait for the
 *                                      chain semaphore to start the wait.
 *
 *                            NOTE  :   This value should be longer than the
 *                                    delay_time to ensure a successful return.
 *
 *                            NOTE : A value of -1 in the timeout field will
 *                                   cause the function to wait forever for a
 *                                   response.
 *
 *                            NOTE : This function call should have a finite
 *                                   timeout value to eliminate the possibility
 *                                   of deadlock.
 *
 *                            buf_time :  The time when the delay completed or
 *                                        was terminated.
 *
 *                 chain :  The NTDS Chain register to be used.
 *                               XB_CHAIN
 *                               IB_CHAIN
 *                               OB_CHAIN
 *                               FB_CHAIN
 *
 *                 term_chain :  The NTDS Chain that will be terminated upon
 *                               completion of the timeout (if applicable).
 *                               XB_CHAIN
 *                               IB_CHAIN
 *                               OB_CHAIN
 *                               FB_CHAIN
 *                               NO_CHAIN
 *
 * OUTPUT : Information is returned in the mesg_packet variable. As described
 *          previously.
 *
 * RETURNS  OK
 *          PASSIVE_MODE_ERR
 *          INVALID_EI_MODE
 *          INVALID_CHAIN
 *          subordinate function returns
 *          vxWorks error codes
 *
 *######################################################################### */
int
Nio_Wait (
	int	     port,
	NIO_MESG   *msg_packet_ptr,
   int        chain,
   int        term_chain
);

/*#########################################################################
 *
 * SYNOPSIS: Terminate_Chain
 *
 * DESCRIPTION: Terminate a requested NTDS transfer and its related chain
 *              program.
 *
 * PARAMETERS:
 *
 *    INPUT port  The board that will receive the termination request.
 *
 *          function  This parameter determines the I/O buffer that will be
 *                    terminated.  One of the following parameters may be
 *                    used.
 *
 *                          TIB  Terminate input buffer
 *                          TOB  Terminate output buffer
 *                          TFB  Terminate external function buffer
 *                          TXB  Terminate external interrupt buffer
 *
 *    OUTPUT   NOTHING
 *
 *    RETURNS  OK
 *             PASSIVE_MODE_ERR
 *             INVALID_CHAIN
 *             SET_TERM_ACT_ERR
 *
 *######################################################################### */
int
Terminate_Chain (
	int	         port,
	unsigned short	func
);

/*#########################################################################
 *
 * SYNOPSIS: Get_BCW
 *
 * DESCRIPTION:  This function returns the requested Buffer Control Word
 *               (transfer Word Count) for the selected NTDS transfer
 *               operation.
 *
 * PARAMETERS:
 *
 *    INPUT  port  : This parameter defines the board that will be accessed.
 *
 *           function : This parameter defines which transfer buffer will be
 *                     read.  The following are valid parameter codes for the
 *                     Get_BCW function:
 *
 *                              SOBCW :  Used for Output chain.
 *                              SIBCW :  Used for Input chain.
 *                              SFBCW :  Used for External Function chain.
 *                              SXBCW :  Used for External Interrupt chain.
 *
 *    OUTPUT  bcw_ptr : The BCW is returned to the user in a variable of the type
 *                  BCW_Format.  This variable type contains the information
 *                  returned by the NTDS board.  The returned information
 *                  is as follows:
 *
 *                       command  The command being executed.
 *
 *                       count    The number of words left to transfer.
 *
 *                       bufadrs  A pointer to current data buffer address
 *                                being used.
 *
 *                       chnadrs  The address of the chain instruction in host
 *                                memory.
 *
 * RETURNS   OK
 *           PASSIVE_MODE_ERR
 *           SET_TERM_ACT_ERR
 *
 * ######################################################################### */
int
Get_BCW (
	int            port,
	unsigned short function,
	BCW_Format     *bcw_ptr
);

/*#########################################################################
 *
 * SYNOPSIS:  Create_EI_Q
 *
 * DESCRIPTION:  This function sets up the External Interrupt queues for the
 *               specified port.  It also returns the qid to be used when
 *               requesting an EI from a specific port by calling the
 *               Deque_EI function.
 *
 *               The caller provides a list of EIs and a mask that will be
 *               associated with the queue.  The EI list must be terminated
 *               with and EI_LIST_END (0).  When an EI is received the
 *               ei_queuing function will check the list using the mask on the
 *               received EI.  If a match occurs, the EI will placed in the
 *               queue.
 *
 *               During the creation of a queue or multiple queues, the user
 *               has a number of options:
 *
 *                 1. Create only one queue:  All EIs will be routed to that
 *                                            queue.
 *                 2. Create multiple queues: EIs will be decoded and routed
 *                                            to the appropriate queue.  If
 *                                            an unrecognized EI is received
 *                                            it is printed out and discarded.
 *                 3. Create multiple queues
 *                    w/ an error queue     : The EI routing is identical to
 *                                            option 2.  However, unrecognized
 *                                            EIs will be routed to the error
 *                                            queue.
 *
 *                 An error queue is created by including a NTDS_ERR_QUE_EI (-1)
 *                 in any queue that may be expected to receive unsolicited EIs
 *                 or the an error EI queue may be created with the single
 *                 NTDS_ERR_QUE_EI with an EI_LIST_END (0) at the end.
 *
 *                 NOTE: For 16 bit interface developers.
 *
 *                16 bit EIs are stored in 32 bits of memory space in the
 *                ei_list.  When registering 16 bit EI's, the developer uses
 *                the LOWER half of the 32 bit space to put the 16 bits of EI
 *                data. The ei_mask for 16 bit EIs works the same way.
 *
 * PARAMETERS:
 *
 *   INPUT port     This parameter determines which qids to check for routing
 *               the received EI.
 *
 *         ei_mask     This parameter allows the user to mask unwanted bits in
 *                  the received EI words that are not needed to determine
 *                  the recipient of the EI word.  This is particularly
 *                  useful for those interface conventions that contain buffer
 *                  sizes in the EI word that are not of a constant size.
 *                  The mask will clear any bits in the EI word that are not
 *                  set in the mask before testing for a match.  If a match
 *                  occurs the received EI word is queued for processing.
 *
 *                     If the user sends a mask of zeros, the queuing function
 *                  will not mask any bits.
 *
 *         *ei_type_list_ptr     This parameter contains a list of EI codes that
 *                        will be associated with the qid being created.  The
 *                        list must be terminated with a EI_LIST_END.
 *
 *                           If the ei list contains an EI code of -1
 *                        NTDS_ERR_QUE_EI followed by an EI_LIST_END (0), all
 *                        unsolicited EIs will be routed to this queue.
 *
 * OUTPUT :  *qid_ptr     This parameter is pointer to the variable that will
 *                 contain the queue id of the newly created queue.  The user
 *                 receives a queue id that will be associated with the EI
 *                 list.  The user must provide this qid to the Deque_EI
 *                 function to take EIs from the queue.
 *
 * RETURNS:  OK
 *           EI_COUNT_ERR
 *           SECOND_EI_ERR
 *           vxWorks error code
 *
 * #########################################################################*/
int
Create_EI_Q (
	int		     port,
	unsigned int ei_mask,
	unsigned int *ei_type_list_ptr,
	MSG_Q_ID 	 *qid_ptr
);

/*#########################################################################
 *
 * SYNOPSIS: Deque_EI
 *
 * DESCRIPTION:      This function deques an NTDS EI word from a specified
 *                EI queue.  The user provides the address of the buffer to
 *                receive the EI and a parameter determining how much time
 *                will be spent waiting for an EI to be received.
 *
 *                   The caller may elect to check the queue without waiting
 *                for an EI by setting the time_out parameter to NO_WAIT.  If
 *                this parameter is set to anything else, the value in the
 *                message packet will be used to determine the maximum time to
 *                wait for an EI.
 *
 *                   In return the driver will return the status of the request
 *                along with a time stamp of when the EI was received if it
 *                was successful.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          *mesg_packet_ptr : This parameter contains the information necessary
 *                         for the driver to accept an EI word and return
 *                         the appropriate responses.  The packet variable
 *                         contains the following information:
 *
 *                            *address :  A pointer to the data buffer
 *                            req_size :  This size is not tested because
 *                                        only one EI can be dequeued at a
 *                                        time.
 *                            time_out :  The amount of time to wait for a
 *                                        transfer to complete in vxWorks ticks.
 *					  NO_WAIT or WAIT_FOREVER are options.
 *                            tfr_size :  The number of words actually
 *                                        transferred.
 *                            buf_time :  The time when the buffer transfer
 *                                        completed or was terminated.
 *
 *          qid : This parameter determines the queue from which the EI word
 *                will be taken.
 *
 * OUTPUT : Information is returned in the mesg_packet variable. As described
 *          before.
 *
 * RETURNS   OK
 *           INVALID_QID
 *           vxWorks error codes
 *
 *######################################################################### */
int
Deque_EI (
	int		port,
	NIO_MESG	*msg_packet_ptr,
	MSG_Q_ID	qid
);

/*#########################################################################
 *
 * SYNOPSIS: Flush_EI_Que
 *
 * DESCRIPTION:      This function flushes EIs from a specified
 *                EI queue.  The user provides the qid of the queue to be
 *                flushed.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          qid : This parameter determines the queue from which the EI word
 *                will be taken.
 *
 * OUTPUT : NOTHING
 *
 * RETURNS   OK
 *           INVALID_QID
 *
 *######################################################################### */
int
Flush_EI_Que (
   int      port,
   MSG_Q_ID qid
);

/*#########################################################################
 *
 * SYNOPSIS: Force_EI_Response
 *
 * DESCRIPTION:      This function forces an EI response to a selected queue.
 *                The user provides the qid of the queue to be serviceed and
 *                the value to be sent.
 *
 * PARAMETERS:
 *
 *   INPUT  port :  The board that will used to transfer the data.
 *
 *          qid : This parameter determines the queue from which the EI word
 *                will be taken.
 *
 *         value : The number that will be placed in the users queue.
 *
 * OUTPUT : NOTHING
 *
 * RETURNS   OK
 *           INVALID_QID
 *
 *######################################################################### */
int
Force_EI_Response (
   int      port,
   MSG_Q_ID qid,
   int      value
);

/*#########################################################################
 *
 * SYNOPSIS:  Change_EI_Lock
 *
 * DESCRIPTION: This function allows an application to control the queuing of
 *              received EIs.  The user provides a list of EIs to be
 *              controlled and/or the address of the lock for each EI.  If
 *              the lock address of the EIs is known the key is applied to the
 *              address immediately.  If the lock address is not provided,
 *              the function attempts to find the lock addresses of the EIs by
 *              searching the queue list checking for a matching EI code.
 *
 *              If the function searches the EI queue and finds a lock address
 *              for the EI, the lock address is returned to the caller to
 *              eliminate the need for searching the list every time the lock
 *              is modified.
 *
 *              The user can either set or clear the lock.  If the EI lock is
 *              set, a received EI is sent to the error queue or thrown away
 *              depending on the configuration of the queuing system.
 *              If the lock is cleared, queuing of the EI is resumed.
 *
 * PARAMETERS:
 *
 *   INPUT  port : This parameter determines which EI queue list will be
 *                 used to find a lock address.
 *
 *          *ei_ptr    This parameter is a pointer to a list of EI codes that
 *                 will have their lock modified or at least checked.  The
 *                 list must be terminated with an EI_LIST_END word.
 *
 *          *lock_address_ptr  : This parameter is a pointer to a list of pointers
 *                           that point to an EI lock address or NULL.
 *                           If this pointer is not NULL, the function
 *                           modifies the lock directly without checking the
 *                           EI list.
 *
 *          key  : This parameter determines if the Ei will be locked or
 *                 opened for use. Options are LOCK and UNLOCK.
 *
 *   OUTPUT  *lock_address_ptr  This parameter may be returned updated if the
 *                          pointer's pointer was pointing to a NULL and a
 *                          valid EI list was provided.
 *
 *             NOTE :   To initialize the lock address pointers.  The user is
 *                    expected to call this function with a list of EIs
 *                    and a pointer to an array of NULL pointers sufficiently
 *                    large enough to hold all of the lock pointers including
 *                    a NULL pointer at the end of the list.
 *
 *                A limited error check is made to ensure the pointers don't
 *              run hopelessly through memory trashing everything in their
 *              path.
 *
 * RETURNS :  OK
 *            LOCK_ADR_ERR
 *            EI_LOCK_ERR
 *
 *######################################################################### */
int
Change_EI_Lock (
	int		    port,
	unsigned int *ei_ptr,
	unsigned int **lock_address_ptr,
	int          key
);

/*#########################################################################
 *
 * SYNOPSIS:  Enable_EI_Process
 *
 * DESCRIPTION: This function activates an External Interrupt I/O chain on the
 *              specified NTDS board.  This function should be called only
 *              once after all requested EI's have been registered.  The
 *              External Interrupt chain activated by this function operates
 *              in conjunction with automatic EI queueinq and EI registration.
 *              This operation is mutually exclusive of the Get_EI function.
 *
 * PARAMETERS:
 *
 *   INPUT  port  This parameter determines the board that will be used.
 *
 *   OUTPUT  NOTHING
 *
 *   RETURNS  OK
 *            subordinate function error
 *
 *######################################################################### */
int
Enable_EI_Process (
	int port
);
#ifdef PASSIVE_TAP

/*#########################################################################
 *
 * SYNOPSIS:       Initialize_Passive_Monitor
 *
 * DESCRIPTION:    This function configures the NIO Passive Tap board for
 *                 operation with the driver.  If the driver is configured for
 *                 AUTO_EI_MODE, the passive tap will route received EIs in the
 *                 same way the regular driver routes EIs.  Data words are read
 *                 into a 64K word buffer.  The application is expected to
 *                 call Get_IB to remove the received data.
 *
 * PARAMETERS:
 *
 *     INPUT
 *
 *             port :  This parameter determines the port that the passive
 *                     task will use.
 *
 *             ei_set :  This parameter is a pointer to a table of Eis and masks
 *                       to be associated each EI.  The following entries are
 *                       contained in each array entry.
 * 
 *                       NOTE : If a mask entry is zero, the enry and all 
 *                              subsequent table enrties will be ignored.
 *
 *                       ei_mask: This parameter determines the mask that will 
 *                                be used on received EIs before the data
 *                                pattern is tested.
 *
 *                       ei_pattern : This parameter determines the EI data
 *                                    pattern that will be recorded when 
 *                                    received.
 *
 *     OUTPUT  NOTHING
 *
 * RETURNS   NOTHING
 *
 * COMMENTS This is a nonterminating task
 *
 *#########################################################################*/
void
Initialize_Passive_Monitor (
   int port,
   Passive_Ei_Table *ei_set
);

/*#########################################################################
 *
 * SYNOPSIS:       Show_Passive_Config
 *
 * DESCRIPTION:    This function displays the NIO Passive Tap board's
 *                 configuration with the driver.
 *
 * PARAMETERS:
 *
 *     INPUT
 *
 *             port :  This parameter determines the port that will be
 *                     displayed.
 *
 *     OUTPUT  NOTHING
 *
 * RETURNS   NOTHING
 *
 *#########################################################################*/
void
Show_Passive_Config (
   void
);

/*#########################################################################
 *
 * SYNOPSIS:       Enable_Passive_Monitor
 *
 * DESCRIPTION:    This function starts the NIO Passive Tap board by writing
 *                 the command structure to the board.  The function
 *                 "Initialize_Passive_Monitor" should have been called before
 *                 calling this function.
 *
 * PARAMETERS:
 *
 *     INPUT
 *
 *             port :  This parameter determines the port of the passive
 *                     monitor to be started.
 *
 *     OUTPUT  NOTHING
 *
 * RETURNS   NOTHING
 *
 * COMMENTS OK
 *          PASSIVE_PORT_ERR
 *
 *#########################################################################*/
int
Enable_Passive_Monitor (
   int port
);

/*#########################################################################
 *
 * SYNOPSIS:       Flush_Passive_Buffer
 *
 * DESCRIPTION:    This function effectively removes any data that has been
 *               caught from the buffer, allowing an applicaiton to
 *               discard messages that may not be wanted.
 *
 * PARAMETERS:
 *
 *     INPUT
 *
 *             port :  This parameter determines the port of the passive
 *                     monitor to be started.
 *
 *             chain : An array index describing the buffer type.
 *
 *     OUTPUT  NOTHING
 *
 * RETURNS   NOTHING
 *
 *#########################################################################*/
void
Flush_Passive_Buffer (
   int port,
   int io_type
);
#endif

#ifdef STANDALONE_DRIVER
/*#########################################################################
 *
 * SYNOPSIS:  Get_VME_Partition
 *
 * DESCRIPTION:     This function gets a block of memory that can be accessed by
 *               the NIO interface board.  The memory block is taken from the
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
PART_ID
Get_VME_Partition (
   unsigned int   size
);

/*#########################################################################
 *
 * SYNOPSIS:  Get_VME_Buffer
 *
 * DESCRIPTION:     This function gets a block of memory that can be accessed by
 *               the NIO interface board.  The memory buffer is addressable
 *               by off board processors. (Mapped to VME memory).
 *
 * PARAMETERS:
 *
 *   INPUT : size     This parameter determines the number of bytes that will be
 *                    allocated.
 *
 *                    This parameter is a pointer to the variable that will
 *                    contain the partition id of the buffer.
 *
 *  OUTPUT : partition_id  This parameter will contain the new paritition id.
 *
 * RETURNS : *address The base address of the newly received buffer is returned.
 *                    If the buffer address is NULL, a buffer was not allocated.
 *
 * #########################################################################*/
char *
Get_VME_Buffer (
   unsigned int size,
   PART_ID      *partition_id
);

/*#########################################################################
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
 *              vxWorks Function errs
 *
 *########################################################################*/
int
Free_NTDS_Msg_Buffer (
  PART_ID partition_id,
  char    *address_ptr
);
#endif

#ifdef __cplusplus
}
#endif

