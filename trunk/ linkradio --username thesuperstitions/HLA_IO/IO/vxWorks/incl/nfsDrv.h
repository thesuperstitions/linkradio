/* nfsDrv.h - nfsDrv header */


/*
modification history
--------------------
01n,16dec98,cjtc added prototype for nfsDrvNumGet
01m,28mar95,kdl  added includes of limits.h and hostLib.h (SPR 4157)..
01l,01dec93,jag  added NFS_DEV_INFO, nfsDevListGet(), and nfsDevInfoGet().
01k,22sep92,rrr  added support for c++
01j,04jul92,jcf  cleaned up.
01i,26may92,rrr  the tree shuffle
01h,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01g,05oct90,dnw  changed nfsMountAll() arg from verbose to quiet.
01f,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01e,07aug90,shl  added IMPORT type to function declarations.
01d,01may90,llk  added function declarations.
01c,30sep88,llk  removed S_nfsDrv_UNKNOWN_HOST.
01b,30jun88,llk  added S_nfsDrv_NO_HOST_NAME_SPECIFIED.
01a,19apr88,llk  written.
*/

#ifndef __INCnfsDrvh
#define __INCnfsDrvh

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @limitation Not implemented, but always returns success.
 */
STATUS 
nfsMount (
	char *host,
	char *fileSystem,
	char *localName
);

/*
 * @limitation Not implemented, but always returns success.
 */
STATUS 
nfsUnmount (
	char *localName
);

#ifdef __cplusplus
}
#endif

#endif /* __INCnfsDrvh */
