#ifndef NTDS_CONFIG_KWR__H
#define NTDS_CONFIG_KWR__H

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
static char ntds_config_h[] = "$Header: /cec/generic/delivered/ntds_common/incl/RCS/ntds_config.h,v 5.9 1999/12/15 18:59:12 ceplib Exp $";
	*
	*
	* Developed by The Johns Hopkins University/Applied Physics Laboratory
	*        for the NAVSEA O6C Program Office, 1993.
	*
	*      Project:        Cooperative Engagement Capability Software
	*
	*  Module Name:  ntds_config.h  ( NTDS interface configuration package )
	*
	*	Synopsis (Usage and Parameters):
	*              See content.
	*
	*
	*	Description:
	*		This include file contains:
	*			a) constant definitions for use with the NIO_DRIVER
	*			   package.
	*			b) NIO_DRIVER function specifications.
	*
	*
	*
	*	Files:
	*           	ntds_config.c
	*
	*
	*	Programmer:	R.A. Beseke
	*	Organization:	JHU/APL
	*	Host System:	Sun 4/SunOS 4.1.2
	*	Language:	C
	*	Date Created:   03-11-91
	*	Reviewed:		By:
	*	Modifications:
	*
	* $Log: ntds_config.h,v $
	* Revision 5.9  1999/12/15 18:59:12  ceplib
	* Modified to compile under the Green Hills C and C++ compilers, as well as
	* under the GNU C and C++ compilers IAW TR#4387.  adb
	*
	* Revision 5.8  1999/04/13 18:00:00  ceplib
	* The "NTDS Trace" buffer size was increased from 1024 to 8192 IAW TR#4275.
	* adb
	*
	* Revision 5.7  1997/10/28 11:44:39  ceplib
	* Removed constant definitions that were also defined by Aegis application.
	* The defines that were removed are: #define  MAX_RECV_MESG_SIZE, #define
	* MAX_SEND_MESG_SIZE, and #define  DEFAULT_SEND_MESG_SIZE IAW TR#3559.  adb
	*
	* Revision 5.6  1997/09/10 13:10:34  ceplib
	* Modified the ethernet package to a functionality for application control
	* of Level 2 testing IAW TR#3504.  adb
	*
	* Revision 5.5  1997/03/03 18:03:25  ceplib
	* Added code to support CES remote interface communications.  Added
	* conditional compile for VSB_SUPPORT since the Power Pc does not use or
	* support VSB.  Increased the number of ports to support CES configurations
	* Added a macro for the NUMBER_OF_NTDS_SIGNAL_QUES to determine the maximum
	* number of tasks that can received a signal IAW TR#3279.  adb
	*
	* Revision 5.0  1996/01/30  17:30:29  ceplib
	* Initial program delivery.
	*
	* Revision 4.0  1994/07/12  14:23:03  ceplib
	* Initial code for start of CEP_2.1.1.
	*
	* Revision 1.2  1993/01/13  13:30:59  ceplib
	* Removed VME_PORT_VECTOR macro IAW TR#189.  adb
	*
	* Revision 1.1  1992/12/04  14:35:02  ceplib
	* Added capability of allowing more than one task to register for a
	* specific message IAW TR#128.  Added capability of allowing more than one
	* task to receive a NTDS Status change IAW TR#126.  adb
	*
	* Revision 1.0  1992/11/06  14:00:07  ceplib
	* Initial revision
	*
	*/

	/* The macro VSB_SUPPORT is only used with USG1 and older hardware.  This
		* macro causes VSB support to compiled into the nio_driver (Antares).
		* interface.
		*/
#ifdef USG1
#define VSB_SUPPORT
#endif

		/* This must be defined to allow the use of more than one driver */
#define MULTIPLE_DRIVERS

		/* This is the list of drivers that are beind used by the project */
#define ANTARES_DRIVER
#define GET_DRIVER

		/* Enables the REMOTE interface unit code to be added */
#define EXTERNAL_UNIT

		/* Enables the selection of special Dx messages using the CGA function
		* call.  This is used by the enet_client package.
		*/
#define CGA_NTDS_DX

		/* Allows a port to be reconfigured with a different NTDS card */
#define DYNAMIC_RECONFIGURATION

	/*  These  parameters are used by both the nio_driver and ntds_comm
		*  packages to determine sizing of arrays.
		*/

#define NUM_OF_NTDS_PORTS  15    /* defines the number of ports to be used */

#define MAX_NUM_EI         25   /* defines the maximum number of EIs to be
									* registered.
									*/

#define MAX_NUM_IN_QUES    12

#define MAX_NUM_IN_QUE_MTS 15

	/* This parameter is used by the ntds_comm package to size arrays
		* used to store message information
		*/

#define MAX_NUM_OF_MT   50

	/* Determines the number of status queues an application can
		* create to wait for a NTDS_Status_Change.  One queue is created for
		* each task receiving an error message.
		*/  
#define NUM_OF_NTDS_STATUS_QUES  5

	/* Determines the number of error queues an application can
		* create to wait for a Recv_NTDS_Error.  One queue is created for
		* each task receiving an error message.
		*/  
#define NUM_OF_NTDS_ERROR_QUES  1

	/* Determines the number of signal queues an application can
		* create to wait for a Recv_NTDS_Signal.  One queue is created for
		* each task receiving a signal.
		*/  
#define NUM_OF_NTDS_SIGNAL_QUES  1

	/* The maximum number of applications that can register for
		* a given message type.
		*/  
#define MAX_REGISTERS_PER_MT    3

	/*  The following parameter must be defined if the NIO_TRC compilation option
	* is used.  This definition determines the size of the trace buffer.
	*/

#define TRACE_SIZE 8192

	/* The Maximum and Default NTDS Message Sizes are required for Aegis 
		* Low Level Serial Interface Protocol only


	* Commented out 10/27/97 by Ken Ross.  Aegis code also defines these values. 
	* Reference TR #3559 for information on this change.                        */


/* #define  MAX_RECV_MESG_SIZE      350 */  /* TBS */
/* #define  MAX_SEND_MESG_SIZE      350 */  /* TBS */
/* #define  DEFAULT_SEND_MESG_SIZE  350 */  /* TBS */

			/* Used by the CDS BLOCK 1 interface application */
#define BLK1_PACKED_MESGS 1

	/* END OF CONFIG FILE  */

#ifdef __cplusplus
}
#endif




#endif // #define NTDS_CONFIG_KWR__H
