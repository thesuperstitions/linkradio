/* ramDrv.h - header file for ramDrv.c */


/*
modification history
--------------------
01f,22sep92,rrr  added support for c++
01e,18sep92,jcf  added include of blkIo.h.
01d,04jul92,jcf  cleaned up.
01c,26may92,rrr  the tree shuffle
01b,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
01a,05oct90,shl created.
*/

#ifndef __INCramDrvh
#define __INCramDrvh

#include <blkIo.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @limitation Not implemented in POSIX version.
 */
BLK_DEV *
ramDevCreate (
	char *ramAddr,
	int bytesPerSec,
	int secPerTrack,
	int nSectors,
	int secOffset
);

#ifdef __cplusplus
}
#endif

#endif
