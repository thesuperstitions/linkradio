#ifdef __cplusplus
extern "C"
{
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
static char ntds_sys__h[] = "$Header: /cec/generic/delivered/ntds_common/incl/RCS/ntds_sys_.h,v 4.10 2000/02/04 16:28:30 ceplib Exp $";
	**************************************************************************
	* Developed by The Johns Hopkins University/Applied Physics Laboratory
	*
	*      Project:        Cooperative Engagement Processor Package
	*
	*      Module Name:    ntds_sys.c  ( NTDS system dependent functions package )
	*
	*      Synopsis (Usage and Parameters):
	*
	*      Description:
	*                      This package is used to resolve system or project
	*                      dependencies in the NTDS interface packages such as
	*                      nio_driver, ntds_comm, and the protocol packages.
	*
	*                      At a minimum, all of the functions prototyped in this
	*                      file must provide a function with an appropriate
	*                      return.
	*
	*                      This file contains all of the function specifications
	*                      corresponding to those functions declared
	*                      in the module (ntds_sys.c).
	*
	*                      The function declarations contained in this file
	*                      provide an interface between the CEP system functions
	*                      and the NTDS interface packages.
	*
	*
	*      Files:
	*              ntds_sys.c    program code
	*
	*      Programmer:     R. A. Beseke
	*      Organization:   JHU/APL
	*      Host System:    HP/HPUX
	*      Language:       C
	*      Date Created:   3/30/92
	*      Reviewed:               By:
	*      Modifications:
	*
	* $Log: ntds_sys_.h,v $
	* Revision 4.10  2000/02/04 16:28:30  ceplib
	* Modified to resolve C++ incompatability problems IAW TR#4387.  adb
	*
	* Revision 4.9  1999/12/15 19:01:10  ceplib
	* Modified to compile under the Green Hills C and C++ compilers, as well as
	* under the GNU C and C++ compilers IAW TR#4387.  adb
	*
	* Revision 4.8  1999/03/11 17:19:12  ceplib
	* Incorporate the new functionality of synchronizing the IOC's local and
	* UNIX Time-Of-Day clocks with those located at the CEP IAW TR#4193.  adb
	*
	* Revision 4.7  1998/09/16 18:15:53  ceplib
	* Implemented changes to accomodate new method of handling Log_NTDS_Mesg
	* IAW TR#3980.  adb
	*
	* Revision 4.6  1997/03/03 18:08:07  ceplib
	* Added code to support CES remote interface communications.  Removed
	* Register_Dx_Modifier function prototype.  Added function prototype for
	* Remote_NTDS_Log_Function, NTDS_Print, and NTDS_Bcast IAW TR#3279.  adb
	*
	* Revision 4.5  1996/04/12  17:04:27  ceplib
	* Modified copyright notice IAW TR#2702.  adb
	*
	* Revision 4.4  1996/04/11  19:20:08  ceplib
	* Added copyright notice to file IAW TR#2702.  adb
	*
	* Revision 4.3  1996/01/30  17:41:14  ceplib
	* Modified to support the new NTDS drivers IAW TR#2481.  Modified to support
	* the new remote NTDS capability IAW TR#2507.  adb
	*
	* Revision 4.1  1994/09/26  15:12:47  ceplib
	* Modified to support the new INS interface functions IAW 2044.  adb
	*
	* Revision 4.0  1994/07/12  14:33:44  ceplib
	* Initial code for start of CEP_2.1.1.
	*
	* Revision 1.10  1993/11/22  15:28:22  ceplib
	* Modified to be more project independent IAW TR#1291.  adb
	*
	* Revision 1.9  1993/11/02  16:02:45  ceplib
	* Added new Level2 test (bad word count in RD) IAW TR#1202.  adb
	*
	* Revision 1.8  1993/08/26  14:21:02  ceplib
	* Modified to define the Level2 testing structure  IAW TR#664.  adb
	*
	* Revision 1.7  1993/07/19  11:42:47  ceplib
	* Modified the NTDS files to compile without ANSI warnings IAW TR#855.  adb
	*
	* Revision 1.6  1993/06/01  14:34:37  ceplib
	* Modified to conditionally compile VSB support IAW TR#663.  Also modified to
	* add a level two test structure IAW TR#664.  adb
	*
	* Revision 1.5  1993/04/29  14:28:28  ceplib
	* Changed the SPS49 port id to 0 IAW TR#547.  adb
	*
	* Revision 1.4  1993/03/10  14:09:16  ceplib
	* Modified to enhance VSB board detection IAW TR#377.  adb
	*
	* Revision 1.3  1993/02/22  16:01:35  ceplib
	* Correct and enhance interrupt coverage for LLS interfaces IAW TR#296.  adb
	*
	* Revision 1.2  1993/01/15  14:32:32  ceplib
	* Modified to support I/O DX of NTDS interface messages IAW TR199.  Updated
	* to support the SPS49 message logging IAW TR#197.  adb
	*
	* Revision 1.1  1993/01/13  13:27:43  ceplib
	* Modified to support a common scan function for user input IAW TR#187.  adb
	*
	* Revision 1.0  1992/09/24  14:55:53  ceplib
	* This version re-initilizes the "Log" messages.  To obtain the differences,
	* perform an "rcsdiff" (format: rcsdiff -r<version#1> -r<version#2> <file-name>).
	*
	*/

//#ifdef SOLARIS_WASP

//#endif



/**********************************************************************
	* Constant Definitions for the NTDS SYS Package                      *
	**********************************************************************/

#define DEVICE_OFFSET  100    /* This macro aligns the device id to the
								* function _id
								*/


	/* Vectors used for external board interrupts */
#define VSB_PORT_VECTOR   0x49
#define VME_PORT_VECTOR   0x64 

	/* The following definitions are needed to resolve the board types
	* that are supported by the NTDS packages
	*/
#ifndef MVME165
#define MVME165 0x165
#endif
#ifndef MVME166
#define MVME166 0x166
#endif
#ifndef MVME167
#define MVME167 0x167
#endif
/*#ifndef POWER4B
#define POWER4B 0x4B
#endif*/
#ifndef MVME2600
#define MVME2600 0x2600
#endif
#ifndef MVME2700
#define MVME2700 0x2700
#endif

	/* The following definition determines the size of the Antares
	* NTDS memory pool.
	*/
#ifndef ANTARES_POOL_SIZE
#define ANTARES_POOL_SIZE  0x00040000   /* must be a multiple of 8kBytes*/
										/* 8Kb = 0x2000  (MMU PAGE SIZE)*/
										/* for proper MMU operation     */  
#endif

#ifdef VSB_SUPPORT
		/* The following definition determines the bus type for configuring
		* the driver and ntds_comm packages.
		*/
#ifndef VSB_BUS
#define VSB_BUS 0
#endif
#endif

	/* The following definitions are needed to resolve the category types
	* that can be set in the Log_NTDS_Mesg function calls.
	*/
#define NTDS_ERROR_CAT    0 /* Used by NTDS Packages to report errors */
#define NTDS_STATUS_CAT   1 /* Used by NTDS Packages to report configuration,
								* special operations, and warnings
								*/
#define NTDS_INPUT_CAT    2 /* Used by NTDS Packages to report Input events */
#define NTDS_OUTPUT_CAT   3 /* Used by NTDS Packages to report Output events*/
#define NTDS_TEST_CAT     4 /* Used by NTDS Packages for testing and debug */

			/* The following are protocols that can be DXed in the CEP */

#define DX_PROTOCOL_INPUT  30
#define DX_PROTOCOL_OUTPUT 31

/*********************************************************
	* External Definitions used by the NTDS Package         *
	*********************************************************/

extern char *sysNtdsPoolAdrs; /* Defines where the Antares memory pool will
								* begin.
								*/

/*********************************************************
	* Type Definitions for the NTDS_SYS Package Body        *
	*********************************************************/

/*#########################################################################
	*
	* SYNOPSIS: NTDS_Sys_Init
	*
	*
	* DESCRIPTION: This function initializes package variables and performs
	*              general house keeping as necessary.
	*
	* PARAMETERS:
	*
	*     INPUT : NONE
	*
	*    OUTPUT : NONE
	*
	*   RETURNS : NOTHING
	*
	* #########################################################################*/
//void
//NTDS_Sys_Init (
//   DEVICE_DATA *device_list
//);

/*#########################################################################
	*
	* SYNOPSIS: Log_NTDS_Mesg
	*
	*
	* DESCRIPTION: This function converts the generic NTDS message logging calls
	*              to the CEP logging format.
	*
	*  The string has to be of the following format.  The colon (:) is 
	*  mandatory.
	*
	*     "NIO:Get_IB-%d Some text here 0x%x"
	*
	* PARAMETERS:
	*
	*     INPUT :
	*       category  : This parameter determines the type of message that is
	*                   being logged.
	*
	*       string: This parameter is a pointer to the format string that
	*               is like a standard printf function call that is
	*               found in the 'C' language.
	*
	*       va    : The arguments to support the format string.
	*
	*   OUTPUT :  NONE
	*
	*  RETURNS : NOTHING
	*
	* #########################################################################*/

//#ifdef SOLARIS_WASP
// If on the WASP, use this name.
void
Log_NTDS_Mesg_CCSTF (
   int        device,
   int        category,
   const char *string_ptr,
   ...
);
//#else
//void
//Log_NTDS_Mesg (
//	int        device,
//	int     category,
//	const char    *string,
//	... 
//);
//#endif

/*#########################################################################
	*
	* SYNOPSIS: Log_NTDS_Cmnd
	*
	*
	* DESCRIPTION: This function converts the generic NTDS user log commands
	*              to the CEP command logging format.  Upon completion of this
	*              function call a new user command will be added to the command
	*              processor list.
	*
	* PARAMETERS:
	*
	*     INPUT :
	*
	*        cmnd :  This parameter is a string pointer to the command that the
	*                user will enter to activate the selected function.
	*
	*  descriptor :  This parameter is a string pointer to a text label that
	*                briefly describes what the command does.
	*
	*    password :   This parameter determines if the command is password
	*                 protected.
	*
	*    function :   This parameter is a pointer to the function that will
	*                 be called when the command is invoked.
	*
	*    priority :   This parameter determines the priority at which the
	*                 function will be run.
	*
	*   OUTPUT :  NONE
	*
	*   RETURNS : NOTHING
	*
	* #########################################################################*/
//void
//Log_NTDS_Cmnd (
//   const char    *label,
//   const char    *descriptor,
//   int     password,
//   FUNCPTR function,
//   int     priority
//);

/*#########################################################################
	*
	* SYNOPSIS: NTDS_Scan
	*
	*
	*  DESCRIPTION:
	*
	*             This routine is designed to work mostly the same as scanf(), with the exception
	*             that it first gets a string and then scans the string.  This effectively flushes
	*             bad input from the input buffer, avoiding the problem that if a user were scaning
	*             for a decimal and a non-decimal was input, scanf() would leave the non-decimal in the input
	*             buffer.  This routine will remove the non-decimal from the input buffer.
	*
	* PARAMETERS:
	*
	*     INPUT :
	*
	*        format :  This parameter is a string that describes the type of data that will be scanned
	*                  into variables.
	*
	*        ...    :  This is a list of parameters that will receive the scanned data.  There should be a
	*                  parameter for every format object.
	*
	*   OUTPUT :   The values in the parameter list will be changed.
	*
	*   RETURNS : Result of the scan.
	*
	*   COMMENTS :  The parameter list is limited to 10 parameters.
	*
	* #########################################################################*/
int
NTDS_Scan (
	char *format,             /* format string */
	...                       /* an array of variables to be formatted */
);

/*#########################################################################
	*
	* SYNOPSIS: NTDS_Time_Diff
	*
	*
	* DESCRIPTION: This function converts the generic NTDS function Time_Diff
	*              to the CEP Time_Diff function.
	*
	* PARAMETERS:
	*
	*     INPUT :
	*
	*      first_time :   The time value from which the second time will be
	*                     subtracted.
	*
	*     second_time :   The time value that will be subtractee from the first
	*                     time value.
	*
	*    OUTPUT :  NONE
	*
	*    RETURNS : The time difference between the first and second time.
	*
	* #########################################################################*/
int
NTDS_Time_Diff (
	unsigned int first_time,
	unsigned int second_time
);

/*#########################################################################
	*
	* SYNOPSIS: Get_NTDS_Time
	*
	*
	* DESCRIPTION: This function gets the IOC's local time with a granularity
	*              of 1 milli-second.
	*
	* PARAMETERS:
	*
	*     INPUT :  NONE
	*
	*    OUTPUT :  NONE.
	*
	*    RETURNS : Secs - local time, in milli-seconds.
	*
	* #########################################################################*/
unsigned int
Get_NTDS_Time (
	void
);

/*#########################################################################
	*
	* SYNOPSIS: Set_NTDS_UNIX_Time
	*
	*
	* DESCRIPTION: This function sets the IOC's UNIX time with a granularity
	*              of 1 microsecond.
	*
	* PARAMETERS:
	*
	*     INPUT :   Secs - UNIX "Epoch" time, in seconds.
	*               USecs - UNIX "Epoch" microseconds (calculated).
	*
	*    OUTPUT :  NONE
	*
	*    RETURNS : NONE.
	*
	* #########################################################################*/
void
Set_NTDS_UNIX_Time(
	long int Secs,
	long int USecs
);

/*#########################################################################
	*
	* SYNOPSIS: Get_NTDS_UNIX_Time
	*
	*
	* DESCRIPTION: This function gets the IOC's UNIX time with a granularity
	*              of 1 microsecond.
	*
	* PARAMETERS:
	*
	*     INPUT :  NONE
	*
	*    OUTPUT :  Secs - UNIX "Epoch" time, in seconds.
	*               USecs - UNIX "Epoch" microseconds (calculated).
	*
	*    RETURNS : NONE.
	*
	* #########################################################################*/
void
Get_NTDS_UNIX_Time(
	long int* Secs,
	long int* USecs
);

/*#########################################################################
	*
	* SYNOPSIS: Get_NTDS_Usec_Time
	*
	*
	* DESCRIPTION: This function reads a microprocessor clock that has an
	*              accuracy of 1 microsecond.
	*
	* PARAMETERS:
	*
	*     INPUT :   NONE
	*
	*    OUTPUT :  NONE
	*
	*    RETURNS : A time value with a granularity of 1 microsecond.
	*
	* #########################################################################*/
unsigned int
Get_NTDS_Usec_Time (
	void
);

/*#########################################################################
	*
	* SYNOPSIS: Dx_NTDS_Data
	*
	*
	* DESCRIPTION: This function sends a data buffer to the system DX package.
	*              The caller passes the ID of the data buffer which is of the
	*              following form:    SGS_DX_DATA or ADT_DX_DATA.
	*              If the DX capability is used, these definitions must reside
	*              in the ntds_sys.h file so that the appropriate interface
	*              protocol package can resolve the data source.  By placing the
	*              DX definitions in the ntds_sys package the data descriptors
	*              can be project independent.
	*
	*              This function also checks to ensure that the event being
	*              DX'ed is enabled before making the DX call.
	*
	*   PARAMETERS:
	*
	*     INPUT :
	*
	*        device      :  This parameter determines the protocol that
	*                       is providing the data buffer.
	*
	*        port        : The actual interface port used to transfer data
	*
	*        buffer_type :  This parameter determines what the source of
	*                       the data buffer is.  A definition similar to
	*                       the following:
	*                                           SGS_DX_DATA
	*
	*                       must be defined in the ntds_sys.h file for
	*                       each NTDS interface that is being Dx'ed.
	*
	*     buffer_address : This parameter is a pointer to the start of
	*                      the data buffer.
	*
	*      buffer_length : This parameter describes the length of the
	*                      data buffer in 32 bit words.
	*
	*    OUTPUT :  NONE
	*
	*    RETURNS : Status of the DX request.
	*                           0 = OK
	*                    NON_ZERO = ERROR
	*
	* #########################################################################*/
int
Dx_NTDS_Data (
	int devie,
	int port,
	int buffer_type,
	char *buffer_ptr,
	unsigned int buffer_length
);

/*#########################################################################
	*
	* SYNOPSIS: Is_NTDS_Board_There
	*
	*
	* DESCRIPTION: This function determines if an NTDS board is mapped at
	*              the address being passed as a parameter.
	*
	*   PARAMETERS:
	*
	*     INPUT :  address :  This parameter is the address of the NTDS board
	*                         being tested.
	*
	*    OUTPUT :  NONE
	*
	*    RETURNS : TRUE if board is found
	*              FALSE if board is not found
	*
	* #########################################################################*/
int
Is_NTDS_Board_There (
	volatile unsigned int *address
);

/*#########################################################################
	*
	* SYNOPSIS: NTDS_Get_Board_Type
	*
	*
	* DESCRIPTION: This function determines the type of host processor board
	*              that is being used to commincate with the NTDS board.
	*
	*   PARAMETERS:
	*
	*     INPUT :  NONE
	*
	*    OUTPUT :  NONE
	*
	*    RETURNS : Board Type being used.
	*
	* #########################################################################*/
int
NTDS_Get_Board_Type (
	void
);

/*#########################################################################
	*
	* SYNOPSIS: NTDS_Control_Task_Monitor
	*
	*
	* DESCRIPTION: This function determines what is to be done with the system
	*              task monitor and performs the appropriate action.
	*
	*   PARAMETERS:
	*
	*     INPUT :  task_id ; The id of the task being monitored.
	*
	*              enable : Determines if the monitor for the task id is to
	*                       be enabled or disabled.  NONZERO = enable
	*                                                ZERO    = disable
	*
	*    OUTPUT :  NONE
	*
	*    RETURNS : NOTHING
	*
	* #########################################################################*/
void
NTDS_Control_Task_Monitor (
	int task_id,
	int control
);


/*#########################################################################
	*
	* SYNOPSIS: NTDS_Clr_Screen
	*
	*
	* DESCRIPTION: This function converts the generic NTDS function Clr_Screen
	*              to the CEP Clr_Screen function.
	*
	* PARAMETERS:
	*
	*     INPUT : NOTHING
	*
	*    OUTPUT :  NONE
	*
	*    RETURNS : NOTHING
	*
	* #########################################################################*/
void
NTDS_Clr_Screen (
	void
);

#ifdef __cplusplus
}
#endif

