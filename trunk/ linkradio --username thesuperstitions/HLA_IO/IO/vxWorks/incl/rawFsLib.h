/* rawFsLib.h - header for raw block device file system library */


/*
modification history
--------------------
03f,31jul99,jkf  changes for CBIO API.
03e,31jul99,jkf  T2 merge, tidiness & spelling.
03d,15oct98,lrn  moved 64-bit extended ioctl codes to ioLib.h
03c,08oct98,vld  added definition of RAWFS_DEF_MAX_FILES
03b,08oct98,vld  driver interface changed to CBIO_DEV.
		 replaced rawvd_pBlkDev with CBIO_DEV * rawvd_pCbio
    	    	 changed prototype of rawFsDevInit().
03a,23jul98,vld  added ioctl codes for 64-bit ioctl requests; new error codes.
02b,22sep92,rrr  added support for c++
02a,04jul92,jcf  cleaned up.
01d,26may92,rrr  the tree shuffle
01c,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01b,05oct90,shl  added ANSI function prototypes.
01a,02oct90,kdl  written
*/

#ifndef __INCrawFsLibh
#define __INCrawFsLibh

#include <iosLib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct		/* RAW_VOL_DESC */
    {
    DEV_HDR	rawvd_devHdr;		/* std. I/O system device header */
    int		rawvd_status;		/* (OK | ERROR) */
    int		rawvd_retry;		/* current retry count for I/O errors */
    } RAW_VOL_DESC;

/*
 * @limitation Has no effect in POSIX, but still returns success.
 */
STATUS 
rawFsInit (
	int maxFiles
);

/*
 * @limitation Has no effect in POSIX, but still returns success.
 */
RAW_VOL_DESC *
rawFsDevInit (
	char *volName,
	void *pBlkDev
);

/*
 * @limitation Has no effect in POSIX, but still returns success.
 */
STATUS 
rawFsVolUnmount (
	RAW_VOL_DESC *vdptr
);

#ifdef __cplusplus
}
#endif

#endif /* __INCrawFsLibh */
