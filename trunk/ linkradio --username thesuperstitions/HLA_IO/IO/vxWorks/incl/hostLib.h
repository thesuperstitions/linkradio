/* hostLib.h - header for hostLib.c */


/*
modification history
--------------------
01k,20aug97,jag  added function declations for hostTblSearchByAddr(),
                 hostTblSearchByName() (SPR #9175)
01j,19may97,spm  added S_hostLib_INVALID_PARAMETER error value
01i,22sep92,rrr  added support for c++
01h,27jul92,elh  Moved hostShow to netShow.
01g,04jul92,jcf  cleaned up.
01f,26may92,rrr  the tree shuffle
01e,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed VOID to void
01d,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01c,13apr89,shl  added MAXHOSTNAMELEN.
01b,04jun88,gae  changed S_remLib_* to S_hostLib_*.
01a,28may88,dnw  extracted from remLib.h
*/

#ifndef HOST_LIB_H
#define HOST_LIB_H

#include <vxTypes.h>
#include <unistd.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef MAXHOSTNAMELEN
#define MAXHOSTNAMELEN	256
#endif

/*
 * @limitation The host name and address are NOT added to the Unix host table,
 * which requires super-user permission. Instead, the hostLib module maintains
 * its own host table, which can be accessed by the <i>hostGetByName</i> and
 * <i>hostGetByAddr</i> routines.
 */
STATUS
hostAdd (
	char *hostName,
	char *hostAddr
);

/*
 * @limitation The host name and address are NOT deleted to the Unix host table,
 * which requires super-user permission. Instead, the hostLib module maintains
 * its own host table, which can be accessed by the <i>hostGetByName</i> and
 * <i>hostGetByAddr</i> routines.
 */
STATUS 
hostDelete (
	char *name,
	char *addr
);

/*
 * Returns the integer value of the host address, or ERROR.
 * @limitation This function accesses the host table maintained by this
 * module, NOT the Unix host table (see limitation for <i>hostAdd</i>).
 */
int
hostGetByName (
	char *name
);

/*
 * @limitation This function accesses the host table maintained by this
 * module, NOT the Unix host table (see limitation for <i>hostAdd</i>).
 */
STATUS
hostGetByAddr (
	int addr,
	char *name
);

/*
 * routine callable from shell
 */
int
hostShow(int ignore);

#ifdef	__cplusplus
}
#endif

#endif
