/* inetLib.h - header for Internet address manipulation routines */


/*
modification history
--------------------
01l,16dec93,jag  Added definition for inet_aton.
01k,09aug93,elh  removed definitions of inet_addr, inet_ntoa, 
		 inet_makeaddr, and inet_network (SPR 2268). 
01j,22sep92,rrr  added support for c++
01i,04jul92,jcf  cleaned up.
01h,26may92,rrr  the tree shuffle
		  -changed includes to have absolute path from h/
01g,04oct91,rrr  passed through the ansification filter
		  -changed includes to have absolute path from h/
		  -changed VOID to void
01f,19oct90,shl  added #include "in.h".
01e,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01d,10aug90,dnw  added declaration of inet_ntoa_b().
01c,24mar88,ecs  added include of types.h.
01b,15dec87,gae  added INET_ADDR_LEN; used IMPORTs on function decl's.
01a,01nov87,llk  written
*/

#ifndef INET_LIB_H
#define INET_LIB_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define		INET_ADDR_LEN 18

void inet_ntoa_b (
	struct in_addr inetAddress,
	char *pString
);

void
inet_makeaddr_b (
	int netAddr,
	int hostAddr,
	struct in_addr *pInetAddr
);

#ifdef	__cplusplus
}
#endif

#endif
