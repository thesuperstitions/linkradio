/*
* Developed by The Johns Hopkins University/Applied Physics Laboratory (JHU/APL)
*
*
*/

/* static char rtc_h_rcsid[] = "$Header: /ceswbl2/src/include/RCS/rtc_.h,v 6.34.0.2 2008/04/03 15:23:04 marc Exp $"; */


/* 
	*
	*	Project:	CEP WASP CES BL2
	*
	*	File:		rtc_.h
	*
	*	Purpose:	defines for real time clock board software driver
	*
	*	Synopsis (Usage and Parameters):
	*			included in rtcLib.c
	*
	*	Description:	contains defines, variables, and function declarations.
	*	
	*		
	*	Programmer:	J. A. Frantz
	*      Date Created:   16jul92
	*
	*	Host System:    SunOS Release 4.1.3_U1
	*	Language:	C
	*	Modifications:                      
	*              $Log: rtc_.h,v $
	*              Revision 6.34.0.2  2008/04/03 15:23:04  marc
	*              Add Rtc_GetScenTimeAt() to rtclib - TR #2732
	*
	*              Revision 6.34.0.1  2007/10/19 14:23:24  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.34  2007/10/18 18:23:21  ceswbl2
	*              CESWBL2_6_34_OCT_18_07
	*
	*              Revision 6.33.0.2  2007/10/12 11:14:58  tallman
	*              Removed notices.  IAW TR#2677
	*
	*              Revision 6.33.0.1  2007/04/24 16:25:40  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.33  2007/04/23 16:57:24  ceswbl2
	*              CESWBL2_6_33_APR_23_07
	*
	*              Revision 6.32.0.1  2006/10/26 16:01:33  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.32  2006/10/25 17:20:00  ceswbl2
	*              CESWBL2_6_32_OCT_25_06
	*
	*              Revision 6.31.0.2  2006/08/15 17:18:19  twhite
	*              NO support for rtc_master in new communication infrastructure; IAW TR #2496.
	*
	*              Revision 6.31.0.1  2006/04/14 14:46:29  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.31  2006/04/13 19:04:38  ceswbl2
	*              CESWBL2_6_31_APR_14_06
	*
	*              Revision 6.30.0.2  2005/10/31 18:25:15  fran
	*              Add comment
	*              TR#2395
	*
	*              Revision 6.30.0.1  2005/10/12 16:49:46  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.30  2005/10/11 20:13:35  ceswbl2
	*              CESWBL2_6_30_OCT_12_05
	*
	*              Revision 6.29.0.3  2005/09/29 13:54:14  twhite
	*              Need to include sysLib.c for hidden dependency; IAW TR #2313.
	*
	*              Revision 6.29.0.2  2005/06/23 12:48:39  twhite
	*              Remove obsolete RTC board support : IAW TR #2313.
	*
	*              Revision 6.29.0.1  2004/12/03 14:30:49  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.29  2004/12/02 19:21:31  ceswbl2
	*              CESWBL2_6_29_DEC_03_04
	*
	*              Revision 6.28.0.1  2004/06/11 14:12:37  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.28  2004/06/10 18:49:42  ceswbl2
	*              CESWBL2_6_28_JUN_11_04
	*
	*              Revision 6.27.0.2  2004/02/19 21:32:32  fran
	*              Add WWS tick rate value.
	*              TR#2014
	*
	*              Revision 6.27.0.1  2003/12/17 17:52:59  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.27  2003/12/16 21:03:12  ceswbl2
	*              CESWBL2_6_27_DEC_17_03
	*
	*              Revision 6.26.0.1  2003/08/14 18:44:24  cwbl2tst
	*              Making_Branches
	*
	*              Revision 6.26  2003/08/13 20:06:48  ceswbl2
	*              CESWBL2_6_26_AUG_13_03
	*
	*              Revision 6.25.0.1  2003/04/04 17:33:56  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.25  2003/04/03 21:36:18  ceswbl2
	*              CESWBL2_6_25_APR_03_03
	*
	*              Revision 6.24.0.1  2002/12/18 18:09:06  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.24  2002/12/13 19:08:29  ceswbl2
	*              CESWBL2_6_24_DEC_13_02
	*
	*              Revision 6.23.0.1  2002/09/06 15:04:27  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.23  2002/09/05 20:44:06  ceswbl2
	*              CESWBL2_6_23_SEP_05_02
	*
	*              Revision 6.22.0.2  2002/08/27 19:24:52  fran
	*              Add include of file that defines the STATUS type used in
	*              prototypes defined in this .h file.
	*              TR#992
	*
	*              Revision 6.22.0.1  2002/02/22 15:26:35  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.22  2002/02/20 21:57:01  ceswbl2
	*              CESWBL2_6_22_FEB_20_02
	*
	*              Revision 6.21.0.1  2001/08/03 15:19:45  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.21  2001/08/02 20:15:22  ceswbl2
	*              CESWBL2_6_21_AUG_02_01
	*
	*              Revision 6.20.0.1  2001/05/09 18:47:36  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.20  2001/05/08 20:17:57  ceswbl2
	*              CESWBL2_6_20_MAY_08_01
	*
	*              Revision 6.19.0.1  2001/02/22 16:05:23  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.19  2001/02/21 22:04:22  ceswbl2
	*              CESWBL2_6_19_FEB_21_01
	*
	*              Revision 6.18.0.4  2001/01/29 15:11:27  fran
	*              Move c linkage directive down below include files.
	*              TR#992
	*
	*              Revision 6.18.0.3  2001/01/23 14:59:29  fran
	*              More file cleanup and standardization:
	*              Move includes down below the comment block normally found first in the file.
	*              Remove include guards around stdio.h and ceswbl2.h that are redundent with
	*              those already found in the .h files.
	*              Move the rtc_.h file's include guards down to the conventional place
	*              below the file's initial comment block and before the code.
	*              TR#992
	*
	*              Revision 6.18.0.2  2001/01/15 15:04:08  fran
	*              took out some unnecesary compiler directives.
	*              added function prototypes.
	*              added solaris-specific prototype.
	*              TR#992
	*
	*              Revision 6.18.0.1  2000/11/10 17:36:34  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.18  2000/11/09 21:21:15  ceswbl2
	*              CESWBL2_6_18_NOV_09_00
	*
	*              Revision 6.17.0.1  2000/09/08 15:29:48  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.17  2000/09/07 21:11:10  ceswbl2
	*              CESWBL2_6_17_SEPT_07_00
	*
	*              Revision 6.16.0.2  2000/08/28 20:29:04  fran
	*              fix return type of Rtc_SetGpsOffset to match implementation.
	*              TR#1048
	*              ,
	*
	*              Revision 6.16.0.1  2000/06/16 15:36:26  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.16  2000/06/15 21:20:25  ceswbl2
	*              CESWBL2_6_16_JUN_15_00
	*
	*              Revision 6.15.0.1  2000/04/13 14:38:04  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.15  2000/04/12 19:55:26  ceswbl2
	*              CESWBL2_6_15_APR_12_00
	*
	*              Revision 6.14.0.3  2000/04/12 15:43:49  dbocek
	*              Add include "stdio.h" to header file, if not already
	*              included, iaw TR #681.
	*
	*              Revision 6.14.0.2  2000/02/10 13:23:50  twhite
	*              Add prototype for Rtc_FprintTimeOfDay; IAW TR #809.
	*
	*              Revision 6.14.0.1  2000/01/28 15:58:21  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.14  2000/01/27 20:57:34  cwbl2adm
	*              CESWBL2_6_14_JAN_27_00
	*
	*              Revision 6.13.0.2  2000/01/03 14:38:22  twhite
	*              Add prototype for Rtc_PrintTimeOfDay function, IAW TR #750.
	*              Add include file ceswbl2_msg.h to solve typedef references, IAW TR #681.
	*
	*              Revision 6.13.0.1  1999/10/21 17:29:48  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.13  1999/10/20 20:13:51  ceswbl2
	*              CESWBL2_6_13_OCT_20_99
	*
	*              Revision 6.12.0.3  1999/09/10 17:26:45  twhite
	*              Add support for bandwidth and latency control; IAW TR #650.
	*
	*              Revision 6.12.0.2  1999/07/01 13:29:33  twhite
	*              Correcting prototypes, IAW TR #17.
	*
	*              Revision 6.12.0.1  1999/06/24 12:57:06  ceswbl2
	*              Making_Branches
	*
	*              Revision 6.12  1999/06/22 20:58:43  ceswbl2
	*              CESWBL2_6_12_JUN_22_99
	*
	*              Revision 6.11.0.4  1999/06/17 12:47:09  twhite
	*              Modifications to support rewritten RTC Library; IAW TR # 612.
	*
	*              Revision 6.11.0.3  1999/06/14 12:48:48  twhite
	*              MOdifications for RTC library rewrite; IAW TR #612.
	*
	* Revision 6.11.0.1  1999/03/30  17:25:40  ceswbl2
	* Making_Branches
	*
	* Revision 6.11  1999/03/29  20:21:36  ceswbl2
	* CESWBL2_6_11_MAR_29_99
	*
	* Revision 6.10.0.2  1999/03/15  19:11:43  twhite
	* Add a global function Rtc_Ping() that allows a processor to detect the presence of
	* a RTC board; iaw TR #559.
	*
	* Revision 6.10.0.1  1999/02/09  17:06:07  ceswbl2
	* Making_Branches
	*
	* Revision 6.10  1999/02/08  20:12:14  ceswbl2
	* CESWBL2_6_10_FEB_08_98
	*
	* Revision 6.9.0.6  1999/01/25  21:10:35  fran
	* took out HRS24 declaration since it also generates a warning about
	* an unused variable in many modules. TR#476.
	*
	* Revision 6.9.0.5  1999/01/12  21:19:05  fran
	* added a constant for use in modulo 24 hour time operations.
	* TR#476
	*
	* Revision 6.9.0.4  1999/01/05  20:15:53  twhite
	* Need to pick of tydef for BOOLEAN from ceswbl2.h for prototype
	* Rtc_GetGpsSyncFlag(); IAW TR #502.
	*
	* Revision 6.9.0.3  1999/01/05  19:55:29  twhite
	* Correct prototype for Rtc_GetGpsSyncFlag to match declaration in rtclib.c;
	* IAW TR #502.
	*
	* Revision 6.9.0.2  1998/12/04  20:26:26  lmc
	* Added sharp define for 24 hour clock in milliseconds IAW TR#467.
	*
	* Revision 6.9.0.1  1998/11/06  14:05:25  ceswbl2
	* Making_Branches
	*
	* Revision 6.9  1998/11/05  19:58:15  ceswbl2
	* CESWBL2_6_9_NOV_05_98
	*
	* Revision 6.8.0.3  1998/10/19  14:50:40  twhite
	* Add extern function declaration to return the status of gps lock; IAW TR #429.
	*
	* Revision 6.8.0.2  1998/10/01  19:09:51  fran
	* added linkage blocks so that C++ programs can use this .h file. TR#316.
	*
	* Revision 6.8.0.1  1998/09/03  15:43:14  ceswbl2
	* Making_Branches
	*
	* Revision 6.8  1998/09/02  20:11:44  ceswbl2
	* CESWBL2_6_8_SEPT_02_98
	*
	* Revision 6.7.0.7  1998/08/31  16:39:50  nancy
	* support new Makefile templates iaw TR # 315
	*
	* Revision 6.7.0.6  1998/08/31  13:17:02  dbocek
	* Change time references in prototypes to use unsigned int (CLOCK)
	* instead of int, iaw TR #343.
	*
	* Revision 6.7.0.5  1998/07/24  18:03:07  dbocek
	* Commenting out rcsid strings to avoid unused compiler warning,
	* iaw TR #315.
	*
	* Revision 6.7.0.4  1998/07/20  19:54:52  twhite
	* Add prototype for Setting GPS Offset; iaw TR #248.
	*
	* Revision 6.7.0.3  1998/07/20  19:39:24  dbocek
	* Removing comments within a comment, iaw TR #315.
	*
	* Revision 6.7.0.2  1998/07/07  11:53:50  marc
	* Add Message for GPS Time Synchronization IAW TR #248
	*
	* Revision 6.7.0.1  1998/06/18  16:10:21  ceswbl2
	* Making_Branches
	*
	* Revision 6.7  1998/06/16  21:18:08  ceswbl2
	* CESWBL2_6_7_JUN_16_98
	*
	* Revision 6.6.0.2  1998/05/27  19:35:43  twhite
	* Change to support WaspSimTime as static variable and CesiumSimTime based on WaspSimTime; iaw TR # 248.
	*
	* Revision 6.6.0.1  1998/05/11  18:43:49  ceswbl2
	* Making_Branches
	*
	* Revision 6.6  1998/05/08  18:23:38  ceswbl2
	* CESWBL2_6_6_MAY_8_98
	*
	* Revision 6.5.0.1  1998/03/18  16:04:49  ceswbl2
	* Making_Branches
	*
	* Revision 6.5  1998/03/17  20:57:18  ceswbl2
	* CESWBL2_6_5_MAR_17_98
	*
	* Revision 6.4.0.1  1998/01/14  14:17:20  ceswbl2
	* Making_Branches
	*
	* Revision 6.4  1998/01/13  21:00:31  ceswbl2
	* CESWBL2_6_4_JAN_13_98
	*
	* Revision 6.3.0.2  1998/01/12  21:08:51  dbocek
	* Make gateway board access correct for both 167/PPC, iaw TR #39.
	*
	* Revision 6.3.0.1  1997/11/20  21:35:22  ceswbl2
	* Making_Branches
	*
	* Revision 6.3  1997/11/19  21:09:00  ceswbl2
	* CESWBL2_6_3_NOV_19_97
	*
	* Revision 6.2.0.1  1997/10/08  14:19:54  ceswbl2
	* Making_Branches
	*
	* Revision 6.2  1997/10/07  20:45:24  ceswbl2
	* CESWBL2_6_2_OCT_07_97
	*
	* Revision 6.1.0.1  1997/09/12  16:51:15  ceswbl2
	* Making_Branches
	*
	* Revision 6.1  1997/09/12  14:25:49  ceswbl2
	* CESWBL2_6_1_SEP_12_97
	*
	******************************************************************************/

#ifndef	RTC__H		/* prevent multiple inclusion */
#define	RTC__H

/* Dependent include files for this module */
#include "ceswbl2.h"
#include "stdio.h"
#include "sysLib.h"
#include "vxWorks.h"
#include "ceswbl2.h"
#include "ceswbl2_msg.h"
#include "gps_sync_.h"
#include "rtc_sync_.h"*/
#include "stdio.h"
#include "sysLib.h"
#include "tcp_sync_.h"
#include "vxWorks.h"
#ifdef __cplusplus
extern "C"
{
#endif

/* Global defines */
#define RTC_POOL_SIZE   0x00002000 /* size of RTC System Memory Pool */
#define RTC_MASTER 	 1	/* 1 = rtc master */
#define NOT_RTC_MASTER 	 0	/* 0 = not rtc master */
#define INTR_LEVEL	 6	/* interrupt request level put onto VMEbus */
#define INTR_VECTOR      0x8e	/* interrupt vector put onto VMEbus */
#define RTCPRINTF       if(DebugRtc) printf
#define CESIUM_CONTU	0	/* 0 = do not sync cesium time with Scenario_Time */
				/* CesiumSimTime will run on indefinitely */
#define CESIUM_SYNC	1	/* 1 = sync cesium time with Scenario_Time */
				/* CesiumSimTime and Scenario_Time are the same */
#define TICKS_TO_MS		(1000/sysClkRateGet())		
#define MS_TO_TICKS     (sysClkRateGet()/1000.) /* must be a float or will return 0, see also "msec_to_ticks()" */
#define TEN_SECONDS_IN_MS	(10000)
#define SECONDS_TO_MICROSECONDS	1000000
#define SECONDS_IN_HOUR 3600
#define MSECS_IN_SECS 1000
#define SECONDS_IN_MINUTE 60
#define RTC_MAX_DELTA           TEN_SECONDS_IN_MS


#define TWENTY_FOUR_HOURS_IN_MS 86400000	/* 24 hours in milliseconds S0 */

/* Additions for the rewrite of rtclib.c */
#define GW_TIME_SOURCE	0  /* defines the  GW board as the current time source */
#define GPS_TIME_SOURCE 1  /* defines the GPS board as the current time source */
#define TCP_TIME_SOURCE 2  /* defines the TCP board as the current time source */
#define RTC_SYS_MEM_FILL 0x88888888 /* RTC System Memory fill value at initialization */

#define GATEWAY_PROC_NUM 0 /* Processor number of the gateway board for each chassis */

	/* WASP on a Workstation (WWS) ticks per sec. Set manually in 
	* /etc/system file by sys admin when configuring a WWS. rtclib checks for
	* this when it initializes.
	*/
enum {WWS_TICKS_PER_SEC = 1000}; 

typedef unsigned int CLOCK;	/* cep wasp simulation clock */

typedef struct 
{
	int ready_value;
	int proc_status;
	CLOCK master_time;
	int	time_source;
	BOOLEAN sync_to_source;
	GPS_STATUS gps_status;
	TCP_STATUS tcp_status;
	/*RTC_STATUS rtc_status;*/
} REAL_TIME_CLK_SYSTEM_STATUS;

/* Global variables */

extern REAL_TIME_CLK_SYSTEM_STATUS *RtcSystemStatus; /* overall RTC system status structure in RTC mem pool */
extern int DebugRtc;

/* Global function declarations */

#ifndef NEW_RPIDS
extern STATUS WaspSimTimeInit(int rtcMaster);/* init rtc board and connect waspSimTime */
#else
extern STATUS WaspSimTimeInit(void); /* init rtc board and connect waspSimTime */
#endif NEW_RPIDS

extern STATUS RtcRead(CLOCK *time);	/* read the real time clock value */

#ifdef INCLUDE_RTC_CODE
	#define RTC_BP_MEM_ADR  0x103ffff0 /* top of 4 MByte memory on gateway board*/
	extern STATUS RtcInit(void);	/* initialize rtc */
	extern STATUS RtcControl(int cmd);	/* rtc control */
	extern VOID   RtcLatch(CLOCK clkvalue);	/* latch the starting clock value */
	extern STATUS RtcConnectIntr( /* connect rtc interrupts */
		int level,      /* interrupt level 0-7 */
		int vector,     /* interrupt vector */
		FUNCPTR routine);    /* pointer to interrupt service routine (handler) */
	extern STATUS RtcIntr(	/* interrupt after ellapsed time */
		int ntimes,         /* 0 = infinite interrupts, 1 = one interrupt */
		CLOCK time);
	extern STATUS Rtc_Ping(void); /* returns OK if RTC board is readable in chassis else ERROR*/
	extern STATUS Rtc_GetRtcSyncTime(CLOCK *rtcTime, CLOCK *localTime);

	/* messages for clock sync process */
	#define	RTC_UNKNOWN	0
	#define	RTC_RESET	1
	#define	RTC_READY	2
	#define	RTC_SYNC	3

	/* Clock Masters -> Clock Master Master (Tg ) */
	typedef	struct
	{
		MSG_HDR	msg_hdr;	/* MID_RTC_STATUS                  */
		int	status;		/* RTC_RESET, RTC_READY            */
		int	func_id;	/* Simulation Function ID ( RPID ) */
	} RTC_STATUS_MSG;

	#define	RTC_STATUS_MSG_BYTES	(sizeof(RTC_STATUS_MSG))
	#define	RTC_STATUS_MSG_WORDS	(sizeof(RTC_STATUS_MSG)/sizeof(int))

	/* Clock Master Master ( Tg ) -> Clock Masters */
	typedef	struct
	{
		MSG_HDR	msg_hdr;	/* MID_RTC_RESET                   */
	} RTC_RESET_MSG;

	#define	RTC_RESET_MSG_BYTES	(sizeof(RTC_RESET_MSG))
	#define	RTC_RESET_MSG_WORDS	(sizeof(RTC_RESET_MSG)/sizeof(int))

	typedef	struct
	{
		MSG_HDR	msg_hdr;	/* MID_RTC_LATCH_TIME              */
		CLOCK	latch;		/* Time msec                       */
	} RTC_LATCH_TIME_MSG;

	#define	RTC_LATCH_TIME_MSG_BYTES	(sizeof(RTC_LATCH_TIME_MSG))
	#define	RTC_LATCH_TIME_MSG_WORDS	(sizeof(RTC_LATCH_TIME_MSG)/sizeof(int))

	typedef	struct
	{
		MSG_HDR	msg_hdr;	/* MID_RTC_GPS_OFFSET              */
		int	gps_offset;	/* GPS Offset msec                 */
	} RTC_GPS_OFFSET_MSG;

	#define	RTC_GPS_OFFSET_MSG_BYTES	(sizeof(RTC_GPS_OFFSET_MSG))
	#define	RTC_GPS_OFFSET_MSG_WORDS	(sizeof(RTC_GPS_OFFSET_MSG)/sizeof(int))

#endif


extern VOID  CesiumSimTimeSync(int flag); /* 0=no sync, 1=sync cesium time with Scenario_Time */
extern CLOCK  Rtc_GetScenTime(void); /* rets the current scenario time in ms. */
extern CLOCK  Rtc_GetScenTimeAt(CLOCK); /* rets the corresponding scenario time in ms. */
extern CLOCK  Rtc_GetCesiumSimTime(void); /* returns CesiumSimTime based on CesiumSimTimeSync */
extern CLOCK  Rtc_GetWaspSimTime(void); /* returns WaspSimTime*/
extern void   Rtc_SetWaspSimTime(void); /* does a RtcRead and places time read into WaspSimTime */
extern VOID   Rtc_SetRunTime(char *tmp); /* passes rtc_run_time to lib */
extern int Rtc_SetGpsOffset(int offset); /* set offset added to rtc time to sync with GPS */
extern int Rtc_GetGpsOffset();
extern BOOLEAN Rtc_GetGpsSyncFlag(void); /* returns flag indicating GPS reference lock on GPS time */
									 /* TRUE = Time is synchronized to time reference */
extern void Rtc_PrintTimeOfDay(CLOCK time); /* print time in HHH:MIN:SEC.MSECS format when given time in milliseconds */
extern void Rtc_FprintTimeOfDay(CLOCK time, FILE *fp); /* print time in HHH:MIN:SEC.MSECS format when given time in milliseconds */

#ifdef SOLARIS_WASP
extern STATUS WaspSimTimeDestroy();/* destroy rtc (Solaris only) */
#endif


/* msec_to_ticks
*
* Quickly convert milliseconds to ticks using 32 bit integer math.
*
* Fast and fairly accurate, but input value has a max value limited to 
* 4294967 or 42949672. This is a function of the sysClkRateGet() return value, 
* the 32 bit values used in
* the function's implementation, and the 2.95.3 version of the gcc compiler 
* which can only generate 32 bit programs. The upper limmit could be larger
* if the implementation used long longs, and the gcc compiler was updated
* to a version that generates 64 bit programs (reportedly version
* 3.3.2 or later. The UltraSPARC III and later chips, and the Solaris 8
* or later operating system are 64 bit.
*/
extern UINT msec_to_ticks(UINT msec);

/* typedefs */


#ifdef __cplusplus
}
#endif

#endif	RTC__H
