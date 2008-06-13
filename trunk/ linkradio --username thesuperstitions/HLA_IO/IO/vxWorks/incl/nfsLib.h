/* nfsLib.h - Network File System library header */


/*
modification history
--------------------
01q,20nov97,gnn  fix for spr#5436, need to support FIOFSTATFSGET
01p,28jul93,jmm  moved AUTH_UNIX_FIELD_LEN and MAX_GRPS definitions to here
01o,22sep92,rrr  added support for c++
01n,18sep92,jcf  removed ansi warnings.
01m,07sep92,smb  added includes xdr_nfs.h and sys/stat.h to remove ANSI warnings
01l,04jul92,jcf  cleaned up.
01k,26may92,rrr  the tree shuffle
01j,16dec91,gae  added missing prototypes for ANSI.
01i,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01h,08mar91,elh  added NFS_REXMIT_{SEC,USEC}.
01g,25oct90,dnw  deleted private function.
01f,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01e,10aug90,dnw  added declarations of nfsAuthUnix[GS]et().
01d,09sep88,llk  added NFS_TIMEOUT_SEC, NFS_TIMEOUT_USEC, NFS_SOCKOPTVAL.
01c,26aug88,gae  removed unused imports.
01b,04jun88,llk  moved FOLLOW_LINK, DEFAULT_FILE_PERM and DEFAULT_DIR_PERM
		   to ioLib.h.
01a,19apr88,llk  written.
*/

#ifndef __INCnfsLibh
#define __INCnfsLibh

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @limitation Not implemented.
 */
void
nfsAuthUnixShow (
	void
);

#ifdef __cplusplus
}
#endif

#endif /* __INCnfsLibh */
