/* logLib.h - message logging library header */


/*
modification history
--------------------
01j,11feb93,jcf  added __PROTOTYPE_5_0 for compatibility.
01i,22sep92,rrr  added support for c++
01h,17jul92,gae  undid 01e.
01g,04jul92,jcf  cleaned up.
01f,26may92,rrr  the tree shuffle
01e,05mar92,gae  changed logMsg() to be true variable args.
01d,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01c,19oct90,shl  changed logMsg() to use variable length argument list.
01b,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01a,10aug90,dnw  written
*/

#ifndef _LOGLIB_H
#define _LOGLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef  __PROTOTYPE_5_0
extern int  logMsg (char *fmt, ...);
#else
int
logMsg (
	char *fmt,
	int arg1,
	int arg2,
	int arg3,
	int arg4,
	int arg5,
	int arg6
);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _LOGLIB_H */
