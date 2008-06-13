/* sysLib.h - system dependent routines header */


/*
modification history
--------------------
03p,09jun98,dat  rework of optional BSP routine declarations
03o,14nov97,db   added functions forward declarations for PPC family.
03n,05nov96,hdn  moved NETIF structure from bootConfig.c.
03m,18sep96,dat  added sysBspRev, sysPhysMemTop, sysScsiConfig,
		 sysSerialHwInit, sysSerialHwInit2, sysSerialReset
03l,06aug96,dat  using #include timerDev.h to declare timer functions
03k,13jun96,hdn  added sysInLong() sysInLongString() sysOutLong()
		 sysOutLongString().
03j,15jun95,ms	 updated for new serial driver
03i,14jun95,hdn  added x86 specific prototypes.
03h,22may95,ms   added sysSerialDevGet() prototype.
03g,22sep92,rrr  added support for c++
03f,15sep92,jcf  cleaned up.
03e,31jul92,ccc  added tyCoDrv() and tyCoDevCreate() prototypes.
03d,27jul92,ccc  added prototypes to clean up os warnings.
03c,09rdc92,rdc  moved PHYS_MEM_DESC struct to vmLib.c.
03b,08rdc92,rdc  added PHYS_MEM_DESC struct.
03a,04jul92,jcf  cleaned up.
02b,26jun92,wmd  modified prototype for sysFaultTableInit().
02a,16jun92,ccc  removed function declarations for sysLib break-up.
01z,26may92,rrr  the tree shuffle
01y,23apr92,wmd  added sysFaultVecSet() prototype declaration for i960.
01x,21apr92,ccc  added SCSI declarations.
01w,16apr92,elh  added SYSFLG_PROXY.
01v,04apr92,elh  added SYSFLG_TFTP.
01u,18dec91,wmd  added mre ANSI prototypes for i960.
01t,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed VOID to void
		  -changed ASMLANGUAGE to _ASMLANGUAGE
01s,23oct90,shl  added a set of generic system dependent function prototypes.
01r,05oct90,dnw  added some ANSI prototypes.
                 made #endif ANSI style.
01p,10aug90,dnw  added SYSFLG_BOOTP
01o,28jul90,dnw  removed BOOT_FIELD_LEN to bootLib.h
		 added declaration of sysBootParams
		 added include of bootLib.h
01m,20jun90,gae  changed start types to be bit fields and renamed types.
		 added import of sysModel.
01l,24apr90,shl  added SYSFLG_NO_SECURITY.
01k,23may89,dnw  added SYSFLG_NO_STARTUP_SCRIPT.
01j,02may89,dnw  added SYSFLG_VENDOR_{0,1,2,3}.
01i,15oct88,dnw  added SYSFLG_NO_AUTOBOOT, SYSFLG_QUICK_AUTOBOOT,
		   and BOOT_WARM_QUICK_AUTOBOOT.
01h,24mar88,ecs  added declaration of sysExcMsg.
01g,13nov87,jcf  changed names of boot types.
01f,29oct87,dnw  added SYSFLG_DEBUG.
01e,14oct87,dnw  added SYSFLG_NO_SYS_CONTROLLER.
01d,14jul87,dnw  added more system global varaibles.
		 deleted sysLocalToBusAdrs().
		 added system restart types.
01c,14feb87,dnw  added sysBus, sysCpu, sysLocalToBusAdrs
01b,18dec86,llk  added BOOT_FIELD_LEN.
01a,04aug84,dnw  written
*/

#ifndef SYS_LIB_H
#define SYS_LIB_H

#include <bootLib.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * @limitation This routine has no effect in this
 * POSIX implementation, and always returns ERROR.
 */
STATUS
sysBusToLocalAdrs (
	int adrsSpace,
	char *busAdrs,
	char **pLocalAdrs
);

/*
 * @limitation This routine has no effect in this
 * POSIX implementation, and always returns ERROR.
 */
STATUS
sysLocalToBusAdrs (
	int adrsSpace,
	char *localAdrs,
	char **pBusAdrs
);

/*
 * @limitation Not implemented.
 */
STATUS
sysBoardIsThere (
	int *addr
);

/*
 * @limitation This routine has no effect in this
 * POSIX implementation, and always returns ERROR.
 */
STATUS
sysIntDisable (
	int intLevel
);

/*
 * @limitation This routine has no effect in this
 * POSIX implementation, and always returns ERROR.
 */
STATUS
sysIntEnable (
	int intLevel
);

/*
 * @limitation This routine has no effect in this
 * POSIX implementation, and always returns ERROR.
 */
STATUS
sysScsiInit (
	void
);

/*
 * @limitation This routine has no effect in this
 * POSIX implementation, but always returns 0.
 */
int
sysProcNumGet (
	void
);

#ifdef	__cplusplus
}
#endif

#endif
