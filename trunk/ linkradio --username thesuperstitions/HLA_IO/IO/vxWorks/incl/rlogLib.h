/* rlogLib.h - header file for rlogLib.c */


/*
modification history
--------------------
02b,22sep92,rrr  added support for c++
02a,04jul92,jcf  cleaned up.
01c,26may92,rrr  the tree shuffle
01b,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed VOID to void
01a,05oct90,shl created.
*/

#ifndef RLOG_LIB_H
#define RLOG_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * @limitation This function is not implemented in the POSIX
 * implementation. Instead, it prompts the user to manually
 * connect to the argument host.
 */
int
rlogin (
	char *host
);

#ifdef	__cplusplus
}
#endif

#endif
