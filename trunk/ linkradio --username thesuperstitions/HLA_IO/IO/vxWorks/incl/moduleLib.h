/* moduleLib.h - symbol structure header */


/*
modification history
--------------------
01f,11sep96,pad  added MODULE_GROUP_MAX definition (SPR #7133).
01e,30oct92,jmm  added prototype for moduleCheck() - spr 1693
01d,22sep92,rrr  added support for c++
01c,27aug92,jmm  changed MODULE_SEG_INFO struct to always include TEXT/DATA/BSS
                 changed symFlags to flags
		 added prototypes for moduleNameGet(), moduleFlagsGet()
		 changed type for ctors and dtors to VOIDFUNCPTR
01b,01aug92,srh  added lists for static constructors/destructors to
		 MODULE struct.
01a,09apr92,jmm	 written
*/

#ifndef MODULE_LIB_H
#define MODULE_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef void *MODULE_ID;

#ifdef	__cplusplus
}
#endif

#endif
