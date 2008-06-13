/* iosLib.h - I/O system header file */


/*
modification history
--------------------
01t,15jan93,wmd  added S_iosLib_INVALID_ETHERNET_ADDRESS
01s,22sep92,rrr  added support for c++
01r,23aug92,jcf  added iosShowInit() prototype.
		 changed to use dllLib.
01q,04jul92,jcf  cleaned up.
01p,26may92,rrr  the tree shuffle
01o,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01n,05oct90,dnw  deleted private routines.
01m,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01l,10aug90,dnw  added declaration of iosFdFree().
01k,07may90,hjb  added IMPORT declaration of iosFdDevFind().
01j,30jun88,llk  added definition of iosNextDevGet().
01i,04jun88,llk  removed S_iosLib_INVALID_DEVICE_NAME.
01h,12apr88,gae  moved defn's of FD_ENTRY & DRV_ENTRY to iosLib.c.
01g,16dec87,jlf  changed de_dummy field in DRV_ENTRY to de_inuse.
01f,30sep87,gae  added name field to FD_ENTRY.
01e,29apr87,dnw  added S_iosLib_CONTROLLER_NOT_PRESENT.
01d,24dec86,gae  changed stsLib.h to vwModNum.h.
01c,01dec86,dnw  changed DEV_HDR.name to be ptr to name instead array of name.
01b,07aug84,ecs  added status codes and include of stsLib.h
01a,08jun84,dnw  written
*/

#ifndef IOS_LIB_H
#define IOS_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#define M_iosLib             (13 << 16)
#define S_iosLib_INVALID_FILE_DESCRIPTOR       (M_iosLib | 3)

typedef struct 		/* DEV_HDR - device header for all device structures */
    {
    int		node;		/* device linked list node */
    short	drvNum;		/* driver number for this device */
    char *	name;		/* device name */
    } DEV_HDR;

/*
 * @limitation Not implemented, but always returns success.
 */
STATUS 
iosDrvRemove (
	int drvnum,
	BOOL forceClose
);

#ifdef	__cplusplus
}
#endif

#endif
