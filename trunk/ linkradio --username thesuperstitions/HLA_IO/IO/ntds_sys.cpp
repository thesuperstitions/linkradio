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
static char rcs_id[] = "$Header: /cec/generic/delivered/ntds_common/src/RCS/ntds_sys.c,v 4.28 2000/02/04 16:28:27 ceplib Exp $";
 * Developed by The Johns Hopkins University/Applied Physics Laboratory
 *
 *      Project:        Cooperative Engagement Capability Software
 *
 *      Module Name:    ntds_sys.c  ( NTDS system dependent functions package )
 *
 *      Synopsis (Usage and Parameters):
 *
 *      Description:    This file contains all of the function definitions
 *                      (actual code) as well as global data definitions
 *                      corresponding to those functions specified and declared
 *                      in the module specification (ntds_sys_.h).
 *                      This file may also contain functions and data
 *                      localized to this module body (i.e. use of "static").
 *
 *                      The functions contained in this file provide an
 *                      interface between the CEP system functions and the
 *                      NTDS interface packages.
 *
 *
 *      Files:
 *              ntds_sys_.h    program declarations
 *
 *      Programmer:     R. A. Beseke
 *      Organization:   JHU/APL
 *	Host System:	Sun 4/SunOS 4.1.2
 *      Language:       C
 *      Date Created:   3/30/92
 *      Reviewed:               By:
 *      Modifications:
 *
 * $Log: ntds_sys.c,v $
 * Revision 4.28  2000/02/04 16:28:27  ceplib
 * Modified to resolve C++ incompatability problems IAW TR#4387.  adb
 *
 * Revision 4.27  1999/12/15 19:00:01  ceplib
 * Modified to compile under the Green Hills C and C++ compilers, as well as
 * under the GNU C and C++ compilers IAW TR#4387.  Modified to correct
 * problems handling strings with no colon embedded in them and also to call
 * the function "va_end" after the variable list of arguments is processed IAW
 * TR#4426.  adb
 *
 * Revision 4.26  1999/03/11 17:19:01  ceplib
 * Incorporate the new functionality of synchronizing the IOC's local and
 * UNIX Time-Of-Day clocks with those located at the CEP IAW TR#4193.  adb
 *
 * Revision 4.25  1998/09/16 18:15:37  ceplib
 * Implemented changes to "Log_NTDS_Mesg", adding a "device" parameter to the
 * function call IAW TR#3980.  adb
 *
 * Revision 4.23  1998/02/27 11:25:28  ceplib
 * Allow dx of special dx points less than 31 IAW TR#3763.  adb
 *
 * Revision 4.22  1998/02/10  16:52:33  ceplib
 * The function "Dx_NTDS_Data" was modified to include a call to "Get_Bus_ID"
 * when filling out the DX header IAW TR#3720. adb
 *
 * Revision 4.21  1998/01/09 15:00:11  ceplib
 * The function "Get_NTDS_Usec_Time" was modified to use the function
 * "vxTimeBaseGet" to form a 32-bit micro-second time value IAW TR#3660.  adb
 *
 * Revision 4.20  1997/12/16 15:49:04  ceplib
 * Modified to "include" the header file "function_ids_.h" in order to pick
 * up the definition for the function "Get_Func_Id" IAW CGA TR#66.  adb
 *
 * Revision 4.19  1997/06/06 20:31:09  ceplib
 * Remove time_diff_.h include IAW CAG TR#55.  adb
 *
 * Revision 4.18  1997/05/20 10:44:07  ceplib
 * The time-related functions are now in a new module, so an include
 * directive for time_utils_.h was added IAW CGA TR#55.  adb
 *
 * Revision 4.17  1997/04/15 16:43:28  ceplib
 * Modified to use vxmemProbe to detect NTDS cards for both the 68040 and
 * Power-PC boards IAW TR#3363.  adb
 *
 * Revision 4.16  1997/03/03 18:06:27  ceplib
 * Added code to support CES remote interface communications.  Function
 * Register_DX_Modifier has been removed.  Modified NTDS_Scan to properly
 * pass va_arg parameters for the Power PC.  Modified Is_NTDS_Board_There to
 * use Dma_Mem_Probe on Power PC machines.  Added Remote_NTDS_Log_Function for
 * CES compatibility.  Added NTDS_Print function for CES compatibility.
 * Added NTDS_Bcast function for CES comaptibility.  Modified vxWorks
 * includes to be enclosed in <> instead of "" IAW TR#3279.  adb
 *
 * Revision 4.15  1996/06/07 15:30:19  ceplib
 * Add the INS protocols to the log string processor IAW TR#2837.  adb
 *
 * Revision 4.14  1996/04/22  16:05:12  ceplib
 * Cleaned up to remove protocol include files in the system configuration
 * source IAW TR#2741.  adb
 *
 * Revision 4.12  1996/02/29  13:24:30  ceplib
 * Modified to further support the IMS infrastructure change IAW CGA TR#15. adb
 *
 * Revision 4.11  1996/02/14  12:51:27  ceplib
 * Modified to add NTDS wrap to the list of commands available at the Command
 * Processor IAW TR#2607.  adb
 *
 * Revision 4.10  1996/02/09  17:08:32  ceplib
 * Modified to use the new CGA DX message type (IO_BUFFER_DX_MT) IAW TR#2596.
 * adb
 *
 * Revision 4.9  1996/02/07  15:20:47  ceplib
 * Modified to use the correct DX message type IAW TR#2594.  adb
 *
 * Revision 4.8  1996/02/05  20:16:55  ceplib
 * Modified to support the IMS infrastructure change IAW CGA TR#15.  adb
 *
 * Revision 4.7  1996/01/30  17:49:30  ceplib
 * Modified to support the new NTDS drivers IAW TR#2481.  Modified to support
 * the new remote NTDS capability IAW TR# 2507.  adb
 *
 * Revision 4.1  1994/09/26  15:28:05  ceplib
 * Modified to support the new INS interface functions IAW TR#2044.  adb
 *
 * Revision 4.0  1994/07/12  14:33:13  ceplib
 * Initial code for start of CEP_2.1.1.
 *
 * Revision 1.11  1993/11/22  15:28:10  ceplib
 * Modified to be more project independent IAW TR#1291.  adb
 *
 * Revision 1.10  1993/07/19  12:52:54  ceplib
 * Modified the NTDS files to compile without ANSI warnings IAW TR#855.  adb
 *
 * Revision 1.9  1993/04/29  14:28:00  ceplib
 * Modified to be compliant with the compile option -Wall IAW TR#548.  adb
 *
 * Revision 1.8  1993/04/09  15:58:07  ceplib
 * Modifying code to run under the new vxWorks 5.1 kernel IAW TR#457.  adb
 *
 * Revision 1.7  1993/03/10  13:41:05  ceplib
 * Modified to enhance VSB board detection IAW TR#377.  adb
 *
 * Revision 1.6  1993/01/26  13:54:21  ceplib
 * Updated with the proper log string IAW TR#219.  adb
 *
 * Revision 1.5  1993/01/22  16:53:51  ceplib
 * Modified to properly print message counts IAW TR#210.  adb
 *
 * Revision 1.4  1993/01/20  22:27:57  ceplib
 * Added a string for the 49 IAW TR#204.  adb
 *
 * Revision 1.3  1993/01/15  14:30:43  ceplib
 * Modified to support I/O DX of NTDS interface messages IAW TR199.  Updated
 * to support the SPS49 message logging IAW TR#197.  adb
 *
 * Revision 1.2  1993/01/13  13:26:38  ceplib
 * Modified to support a common scan function for user input IAW TR#187.  adb
 *
 * Revision 1.1  1992/12/04  14:09:24  ceplib
 * Modified device ID's and board configuration database IAW TR#129.  adb
 *
 * Revision 1.0  1992/09/28  16:49:01  ceplib
 * This version re-initilizes the "Log" messages.  To obtain the differences,
 * perform an "rcsdiff" (format: rcsdiff -r<version#1> -r<version#2> <file-name>).
 *
 */


/******************************************
 *   System-wide includes go here         *
 ******************************************/

//#include <vxWorks.h>
#include <stdarg.h>
//#include <msgQLib.h>
//#include <strLib.h>
///*#include <stdlib.h>*/
//#include <taskLib.h>
///*#include <logLib.h>*/
//#include <errnoLib.h>
//#include <lstLib.h>
//#include <fioLib.h>
//#include <stdioLib.h>
//#include <ctype.h>
//#include <ioLib.h>
//#include <symLib.h>
//#include <vxLib.h>
#include <time.h>
/*#include <sys.h>*/

/*####################################################*/
/*# Define module symbol for Conditional Compilation #*/
/*####################################################*/

/* ################### */
/* # Module INCLUDES # */
/* ################### */
//#include "system.h"
//#include "project.h"
//#include "transport_.h"
//#include "root_.h"
//#include "crt_ctrl_.h"
//#include "cmnd_.h"
//#include "task_mon_.h"
//#include "q_vector_.h"
//#include "common_msgs_struc.h"
//#include "system_msgs.h"
//#include "project_msgs.h"
//#include "special_dx_.h"
//#include "function_ids_.h"
//#include "time_utils_.h"
//
//#include "ntds_comm_.h"
//#include "ntds_config.h"
//#include "wrap_io_.h"
//#include "log_mgr_.h"
//#include "scan_str_.h"

/*#include "sys/times.h"*/  /* needed for timeval, timezone */

//#ifdef REMOTE_APPLICATION
//
//#include "ntds_drivers.h"
//#include "socket_mgr_.h"
//#include "net_utils_.h"
//#include "sock_utils_.h"
//#include "hosttable.h"
//#include "enet_client_.h"
//#include "enet_server_.h"
//#include "ntds_enet_hdrs.h"
//#include "ts_server_.h"
//
//#endif
//
//         /* We have to be using the chip */
//#if BOARD_TYPE == POWER4B || BOARD_TYPE == MVME2600 || BOARD_TYPE == MVME2700
//#include "dma_universe_.h"
//#endif
//
#include "ntds_sys_.h"


/**********************************************************************
 * Constant Definitions for the NTDS SYS Package Body only            *
 **********************************************************************/

#define MAX_MOD_STRING_LIST  29   /* The maximum number of string buffers that
                                   * can be used by Log_NTDS_Mesg.
                                   * This should be one short of the 
                                   * "module_string" array size.
                                   */

/*********************************************************
 * Type Definitions for the NTDS_SYS Package Body only   *
 *********************************************************/
/*
extern unsigned int readTimeBaseUpper(void);
extern unsigned int readTimeBaseLower(void);*/

/******************************************************************
 * Global Data Definitions Needed by other modules but controlled *
 * by this module.                                                *
 *******************************************************************/

/******************************************************************
 * Global Data Definitions Needed by THIS modules ONLY,           *
 * they should be declared as static.                             *
 ******************************************************************/

//static DEVICE_DATA device_data[NUM_OF_NTDS_PORTS];
//
//     /* A pointer to the list of initialized devices/ports */
//static DEVICE_DATA *master_ptr = NULL;
//
//        /* Used to bullet proof if someone doesn't call NTDS_Sys_Init. */
//static int called = FALSE;
//
///* Determines if the configuration is as a satellite unit (CIOC)  */
//#ifdef REMOTE_APPLICATION
//static int satellite_unit;
//#endif
//
//static QUEUE_CTL_BLKS *qid;

       /*  We need these constants because we can't pass stack variables.
        *  It is also a list of all the NTDS protocols and packages.
        *
        * Don't forget the MAX_MOD_STRING_LIST #def if you change
        * the initialization of this string.
        */
static const char *module_string[] = {"NIO",
                                      "GET",
                                      "SAB",
                                      "VME",
                                      "NTDS",
                                      "WRAP",
                                      "ENET_C",
                                      "ENET_S",
                                      "REMOTE",
                                      "ADT",
                                      "ADP",
                                      "ATES",
                                      "C&D_IFF",
                                      "CDS",
                                      "DDS",
				      "DX",
				      "FCS",
                                      "INS",
                                      "WSN5_060",
                                      "WSN5_050",
                                      "LCDS",
                                      "LLS",
				      "RCP",
				      "RDR49",
                                      "SGS",
                                      "TAS",
                                      "TCDS",
                                      "UPX29",
                                      "WDS",
                                      "WCS",
                                      "UNK"};

static const char *category_string[] = {"NTDS_MSG",
                                        "NTDS_STATUS",
                                        "NTDS_INPUT",
                                        "NTDS_OUTPUT",
                                        "NTDS_TEST"};

/* static variables for handling unix time.                                   */
static struct {
	unsigned long unix_epoch_seconds;       /* seconds since 1 Jan 70     */
	unsigned int  unix_epoch_microseconds;  /* micro seconds              */
        unsigned int  local_time;               /* Local time.                */
} time_cache;
//int UNIX_Time_Flag = FALSE;

/*************************************************************
 * Global Function Declarations Needed by THIS module ONLY   *
 * (ie "internal routines).  They should be declared as      *
 * 'static'.                                                 *
 *************************************************************/

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
 *     INPUT : device data list = A list of the data sets being
 *                               used for different devices.
 *
 *    OUTPUT : NONE
 *
 *   RETURNS : NOTHING
 *
 * #########################################################################*/
//void
//NTDS_Sys_Init (
//   DEVICE_DATA *device_list_ptr
//)
//
//{

//int i;
//
//DEVICE_DATA *device_ptr;
//DEVICE_DATA *old_ptr;
//DEVICE_DATA *t_ptr;
//
//   device_ptr = device_list_ptr;
//   if (called == FALSE)
//   {
//      Log_NTDS_Cmnd ("Wrap", "NTDS Wrap", FALSE,
//                     (FUNCPTR)NTDS_Wrap, -1);
//      master_ptr = NULL;
//      for (i = 0; i < NUM_OF_NTDS_PORTS; i++)
//      {
//         device_data[i].next = NULL;
//      }
//      if (device_ptr->board.init_mode != SATELLITE_INTERFACE)
//      {
//#ifdef REMOTE_APPLICATION
//         satellite_unit = FALSE;
//#endif
//         qid = Special_Dx_Output_Qid ();
//         if (qid == NULL)       
//         {
//            Log_NTDS_Mesg (device_ptr->device_id, NTDS_ERROR_CAT,
//                           "NIO:NTDS_Sys_Init-%d No Output Qid 0x%x",
//                           device_ptr->device_id, qid);
//            return;
//         }
//      }
//      else
//      {
//#ifdef REMOTE_APPLICATION
//         satellite_unit = TRUE;
//#endif
//      }
//         /* We need both because we don't know which processor it may have
//          * been compiled for and both types are processor compatible
//          */
//#if BOARD_TYPE == MVME2600 || BOARD_TYPE == POWER4B || BOARD_TYPE == MVME2700
//      if ( (NTDS_Get_Board_Type () == MVME2600) ||
//      (NTDS_Get_Board_Type () == MVME2700) )
//      {
//         Init_Local_Dma();
//      }
//#endif
//      called = TRUE;
//   }
//
//         /* Save the device data */
//   while (device_ptr != NULL)
//   {
//          /* Save the data for use later */
//      device_data[device_ptr->port] = *device_ptr;
//
//
//           /* Start a pointer list for fast access */
//      if (master_ptr == NULL)
//      {
//         master_ptr = &device_data[device_ptr->port];
//      }
//      else
//      {
//
//         /* We are adding another. Find the end of the list to put it at the
//          * end.
//          */
//         t_ptr = master_ptr;
//         while (t_ptr != NULL)
//         {
//           old_ptr = t_ptr;
//           t_ptr = t_ptr->next;
//         }
//            /* Add the new one to the list */
//         old_ptr->next = &device_data[device_ptr->port];
//      }
//
//            /* Set the pointer to NULL so we don't over run */
//      device_data[device_ptr->port].next = NULL;
//
//      device_ptr = device_ptr->next;
//   }
//   return;
//}

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
 *
 * PARAMETERS:
 *
 *     INPUT :
 *       device : number assigned to a particular interface.  A value of NULL
 *                can be used if a device number is not available or is not
 *                appropriate for the type of message that is to be logged.  A
 *                NULL value will cause the log message to be broadcast to all
 *                NTDS Application boards (when in a USG2 environment).
 *
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
#include <sys/timeb.h>
#include <stdlib.h>
#include <stdio.h>


void
Log_NTDS_Mesg (
   int        device,
   int        category,
   const char *string_ptr,
   ...
)

{
  char S1[500];
  struct timeb  t;
  int           Hours, Mins, Secs;


  va_list va;

  /* Initialize the variable list process */
  va_start (va, string_ptr);

  vsprintf(S1, string_ptr, va);

  ftime(&t);
  Secs = t.time % 86400; // 86400 = Seconds/24 hours
  Hours = Secs / 3600;
  Secs -= Hours * 3600;
  Mins = Secs / 60;
  Secs -= Mins * 60;

  printf("\n%02u:%02u:%02u.%03u : %s", Hours, Mins, Secs, t.millitm, S1);
  
  va_end(va);
}


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
//)
//
//{
//
//int new_priority;
//
//   if (priority == -1)
//   {
//      new_priority = 0;
//   }
//   else
//   {
//      new_priority = priority;
//   }
//   Log_Cmnd (password, label, descriptor, function, new_priority);
//
//}

/*#########################################################################
 *
 * SYNOPSIS: NTDS_Scan
 *
 *
 *  DESCRIPTION:
 *
 *             This routine is designed to work mostly the same as scanf(),
 *  with the exception that it first gets a string and then scans the string.
 *  This effectively flushes bad input from the input buffer, avoiding the 
 *  problem that if a user were scaning for a decimal and a non-decimal was 
 *  input, scanf() would leave the non-decimal in the input buffer.  This 
 *  routine will remove the non-decimal from the input buffer.
 *
 * PARAMETERS:
 *
 *     INPUT :
 *
 *        format :  This parameter is a string that describes the type of data
 *                  that will be scanned into variables.
 *
 *        ...    :  This is a list of parameters that will receive the scanned
 *                  data.  There should be a parameter for every format object.
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
)

{

 /*------*/
 /* DATA */
 /*------*/
//
//int scan_stat;			/* error return for sscanf() */
//int index;
//int *ptr[10];
//
//char *t_char;
//
//va_list args;
//
// /*------*/
// /* PROG */
// /*------*/
//
//   va_start (args, format);                /* get pointer to arguments */
//   t_char = format;
//   index = 0;
//   while (*t_char != '\0')
//   {
//        /* Find the format specifier character */
//      while ((*t_char != '%') && (*t_char != '\0'))
//      { 
//         t_char++;
//      }
//      if (*t_char == '%')
//      {
//           /* We need to skip over precision */
//         t_char++;
//         while (((isdigit (*t_char) != 0) || (*t_char == '.')) &&
//                (*t_char != '\0'))
//         {
//            t_char++;
//         }
//         switch (*t_char)
//         {
//            case 'c' :
//            case 'd' :
//            case 'i' :
//            case 'o' :
//            case 'u' :
//            case 'x' :
//            case 'X' :
//               ptr[index++] = (int *)(va_arg (args,int *));
//               break;
//            case 'f' :
//            case 'g' :
//            case 'e' :
//            case 'G' :
//            case 'E' :
//               ptr[index++] = (int *)(va_arg (args, float *));
//               break;
//            case 'l' :
//               switch (*(t_char+1))
//               {
//                  case 'f' :
//                  case 'g' :
//                  case 'e' :
//                  case 'G' :
//                  case 'E' :
//                     ptr[index++] = (int *)(va_arg (args, double *));
//                     break;
//               }
//               break;
//            case 's' :
//               ptr[index++] = (int *)(va_arg (args, char *));
//               break;
//            default :
//               printf ("NTDS_SYS Unknown format character (%c) in %s\n",
//                       *t_char, format);
//               break;
//         }
//         t_char++;
//      }
//   }
//   scan_stat = Str (format, ptr[0], ptr[1], ptr[2],
//                         ptr[3], ptr[4], ptr[5], ptr[6], ptr[7],
//                         ptr[8], ptr[9]);
//
//   return(scan_stat);

  return(0);
}


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
)

{
   //return (time_diff (first_time, second_time));
  return(0);
}

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
)
{
  //return ( Get_Local_Time() );
  return(0);
}


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
)
{
  /*First, Set the sysutils UNIX time of day so that the Log messages are     */
  /* tagged properly.  The sysutils time is only millisecond-accurate so we   */
  /* keep out own microsecond-accurate time so we can time events.            */
  //Set_Unix_Timeofday(Secs, Get_Local_Time());

  //time_cache.unix_epoch_seconds = Secs;
  //time_cache.unix_epoch_microseconds = USecs;
  //time_cache.local_time = Get_Local_Time();
  //UNIX_Time_Flag = TRUE;
}

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
)
{
  //int time_delta_ms;
  //int S;
  //int ms;

  ///* If we haven't received a UNIX Time message, return zeroes to the caller. */
  //if (UNIX_Time_Flag == FALSE)
  //{
  //  Secs = 0;
  //  USecs = 0;
  //  return;
  //}

  ///* The Delta milliseconds = difference between the time we received the last*/
  ///* UNIX Time and the current time.                                          */
  //time_delta_ms = (Get_Local_Time() - time_cache.local_time);
  //ms = (time_cache.unix_epoch_microseconds / 1000) + time_delta_ms;
  //S = ms / 1000;
  //ms = ms % 1000;
  //*Secs = time_cache.unix_epoch_seconds + S;
  //*USecs = (time_cache.unix_epoch_microseconds % 1000) + (ms * 1000);
}


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
)

{
//#if BOARD_TYPE == POWER4B || BOARD_TYPE == MVME2600 || BOARD_TYPE == MVME2700
//  unsigned upper,lower;
//#endif
//
//  if ((NTDS_Get_Board_Type() == 0x166) || 
//      (NTDS_Get_Board_Type() == 0x167))
//  {
//    return (Get_Usec_Time());
//  }
//#if BOARD_TYPE == POWER4B || BOARD_TYPE == MVME2600 || BOARD_TYPE == MVME2700
//  else
//  {
//    vxTimeBaseGet (&upper, &lower);
//    return (((upper << 28) & 0xF0000000) | ((lower >> 4) & 0x0FFFFFFF));
//  }
//#else
//  else
//  {
//    Log_NTDS_Mesg (0, NTDS_ERROR_CAT, "NIO:Get_NTDS_Usec_Time-Processor is NOT supported = 0x%x",
//                   NTDS_Get_Board_Type());
    return(0);
//  }
//#endif
}


/*#########################################################################
 *
 * SYNOPSIS: Dx_NTDS_Data
 *
 *
 * DESCRIPTION: This function sends a data buffer to the system DX package.
 *              The caller passes the id of the protocol performing the DX
 *              request.  The caller also passes the ID of the data buffer
 *              which is of the following form:    DX_OUT_DATA or DX_IN_DATA.
 *              If the DX capability is used, these definitions must reside
 *              in the ntds_sys.h file so that the appropriate interface
 *              protocol package can resolve the data source.  By placing the
 *              DX definitions in the ntds_sys package the data descriptors
 *              can be project independent.
 *
 *              This function also checks to ensure that the event being
 *              DX'ed is enabled before making the DX call.
 *
 *              This function will also add an application subevent modifier
 *              if one has been registered for that function.
 *
 *
 *   PARAMETERS:
 *
 *     INPUT :
 *
 *           device :   This parameter determines the callers function id + 100.
 *                      This parameter shold be unique for every protocol in
 *                      the system.
 *
 *           port   :   The actual interface that is used to transfer 
 *                      intformation.
 *
 *        buffer_type :  This parameter determines what the source of
 *                       the data buffer is.  This parameter should contain
 *                       one of the following:
 *                                      DX_PROTOCOL_INPUT
 *                                      DX_PROTOCOL_OUTPUT
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
   int device,
   int port,
   int buffer_type,
   char *buffer_ptr,
   unsigned int buffer_length
)

{

//IO_BUFFER_DXS  dx_header;
//
//unsigned int *mesg_list[3];
//
//int mesg_len_list[3];
//int func_id;
//int status;
//
//unsigned int buf_type;
//
//   func_id = device % DEVICE_OFFSET;
//   switch (buffer_type)
//   {
//      case DX_PROTOCOL_INPUT :
//         buf_type = CEP_PROTOCOL_INPUT;
//         break;
//      case DX_PROTOCOL_OUTPUT :
//         buf_type = CEP_PROTOCOL_OUTPUT;
//         break;
//      default :
//         buf_type = buffer_type+1;
//   }
//   if (func_id > MAX_NUM_FUNCTIONS)
//   {
//      Log_NTDS_Mesg (device, NTDS_ERROR_CAT, "NIO:Dx_NTDS_Data-%d Invalid Function ID",
//                     func_id);
//      return (BAD_PORT_ID);
//   }
//
//#ifdef REMOTE_APPLICATION
//
//   if (satellite_unit == TRUE)
//   {
//
//      if (Remote_Special_Dx_Event_On (port, buffer_type) != FALSE)
//      {
//         return (Queue_Remote_Dx_Data (device, port, buffer_type, (char *)buffer_ptr,
//                                       buffer_length));
//      }
//
//         /* Just return if Dx is not enabled  */
//   }
//   else
//#endif
//
//   {
//           /* Determine if Special DX is turned on */
//      if ((status = Special_Dx_Event_On (func_id, buf_type)) == TRUE)
//      {
//         if (qid == NULL)
//         {
//               /* Just in case we missed it on boot up */
//            qid = Special_Dx_Output_Qid ();
//            if (qid == NULL)
//            {
//               Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
//                              "NIO:Dx_NTDS_Data-%d No Output Qid", func_id);
//               return (QUE_NOT_FOUND);
//            }
//         }
//           /* If it wasn't saved as a modifier use the hundreds value if it
//            * is larger than 100.
//            */
//         if (device > 100)
//         {
//              /* Buf type will reflect the hundreds portion of the device id.
//               */
//            dx_header.device_id = device / DEVICE_OFFSET;
//         }
//         dx_header.msg_hdr.msg_type = IO_BUFFER_DX_MT;
//         dx_header.msg_hdr.num_wrds = DX_EVENT_SZ + buffer_length;
//         dx_header.msg_hdr.time = Get_Local_Time ();
//         dx_header.msg_hdr.bus_id = Get_Bus_Id ();
//         dx_header.msg_hdr.board_id = Get_Board_Id ();
//         dx_header.msg_hdr.function_id = Get_Func_Id ();
//         if (Get_Normal_NTDS_Port (device) == port)
//         {
//            /* This buffer is from the Normal port. */
//            dx_header.secondary_channel = FALSE;
//         }
//         else
//         {
//            /* This buffer is from the Alternate port. */
//            dx_header.secondary_channel = TRUE;
//         }
//         dx_header.device = NTDS_IO_BUFFER;
//         dx_header.pre_processed = FALSE;
//         dx_header.sub_msg_type = buf_type;
//         mesg_list[0] = (unsigned int *)&dx_header;
//         mesg_list[1] = (unsigned int *)buffer_ptr;
//         mesg_list[2] = 0;
//         mesg_len_list[0] = DX_EVENT_SZ + 1;
//         mesg_len_list[1] = buffer_length;
//         mesg_len_list[2] = 0;
//         Log_NTDS_Mesg (device, NTDS_STATUS_CAT,
//                        "NIO:Dx_NTDS_Data- Queued from 0x%x buffer of size %d",
//		                  dx_header.msg_hdr.msg_type, dx_header.msg_hdr.num_wrds);
//         status = Que_Msg_Parts (qid, mesg_list, mesg_len_list);
//         if (status != OK)
//         {
//            Log_NTDS_Mesg (device, NTDS_ERROR_CAT,
//                           "NIO:Dx_NTDS_Data-%d Data Extract Failed Status = 0x%x",
//                           port, status);
//         }
//      }
//      else
//      {
//         Log_NTDS_Mesg (device, NTDS_STATUS_CAT,
//                        "NIO:Dx_NTDS_Data-%d Data Extract not Enabled", func_id);
//      }
//   }
   //return (OK);
  return(0);

}


/*#########################################################################
 *
 * SYNOPSIS: Is_NTDS_Board_There
 *
 *
 * DESCRIPTION: This function determines if an NTDS board is mapped at
 *              the address being passed as a parameter.  The address
 *              MUST be a VME or VSB address.
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
)

{
  //char value[4];

  // return (!(vxMemProbe ((char *) address, READ, 4, value)));
  return(0);
}

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
)

{
   //return (Get_Board_Type ());
  return(0);
}

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
	int enable
)

{
   //if (enable == TRUE)
   //{
   //   Enable_Task_In_Monitor (task_id);
   //}
   //else
   //{
   //   Disable_Task_In_Monitor (task_id);
   //}
}

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
)

{
  //Clr_Screen();
}

void ntds_sys_mod_date(void)
{
  //printf("\n\nNTDS_Comm library.  Last modified : 01/07/98\n\n");
}

