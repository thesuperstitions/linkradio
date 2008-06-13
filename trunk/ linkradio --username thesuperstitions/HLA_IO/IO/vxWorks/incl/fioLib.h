/* fioLib.h - header for formatted i/o library */


/*
modification history
--------------------
01o,14may95,p_m  added fioLibInit() prototype.
01n,20jul92,jmm  removed declaration of itob()
01m,13nov92,dnw  made include of stdarg.h conditional on __STDC__
01l,22sep92,rrr  added support for c++
01k,02aug92,jcf  added printExc().
01j,04jul92,jcf  cleaned up.
01i,26may92,rrr  the tree shuffle
01h,04dec91,rrr  some more ansi cleanup.
01g,04oct91,rrr  passed through the ansification filter
		  -changed includes to have absolute path from h/
		  -fixed #else and #endif
01f,24mar91,del  added include of varargs.h.
01e,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01d,07aug90,shl  added INCfioLibh to #endif.
01c,10jun90,dnw  removed S_fioLib_UNEXPECTED_EOF (no longer returned by fioRead)
		 This file is now just a place holder!
01b,24dec86,gae  changed stsLib.h to vwModNum.h.
01a,07aug84,ecs  written
*/

#ifndef FIO_LIB_H
#define FIO_LIB_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define fioRead read

int
fioRdString
(
	int	fd,		/* fd of device to read     */
	char	string[],	/* buffer to receive input  */
	int	maxbytes	/* max no. of chars to read */
);

#ifdef	__cplusplus
}
#endif

#endif
