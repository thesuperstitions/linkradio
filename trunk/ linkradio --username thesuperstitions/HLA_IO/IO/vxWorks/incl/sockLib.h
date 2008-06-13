/* sockLib.h -  UNIX BSD 4.3 compatible socket library header */


/*
modification history
--------------------
02f,25jul95,dzb  added prototype for sockLibAdd().
02e,24jul95,dzb  changed sockInit() to sockLibInit().
02d,23jul93,jmm  changed #include "socket.h" to "sys/socket.h" (spr 2033)
02c,22sep92,rrr  added support for c++
02b,19aug92,smb  changed systime.h to sys/times.h
02a,04jul92,jcf  cleaned up.
01e,26may92,rrr  the tree shuffle
01d,16dec91,gae  added includes for ANSI.
01c,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
01b,23oct90,shl replaced all occurances of "int flag s" to "int s".
01a,05oct90,shl created.
*/

#ifndef SOCK_LIB_H
#define SOCK_LIB_H

#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct sockaddr SOCKADDR;

STATUS
connectWithTimeout (
	int sock,
	struct sockaddr *adrs,
	int adrsLen,
	struct timeval *timeVal
);

void
tcp_fasttimo (
	void
);

#ifdef	__cplusplus
}
#endif

#endif
