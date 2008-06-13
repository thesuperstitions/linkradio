/* vme.h - VMEbus constants header file */


/*
modification history
--------------------
02c,10feb99,tm   added documentation about number 0x40 and above
02b,22sep92,rrr  added support for c++
02a,04jul92,jcf  cleaned up.
01g,26may92,rrr  the tree shuffle
01f,13jan92,ccc  fixed VME_AM_IS_XXX macro for 16 and 24 bit AM's.
01e,04oct91,rrr  passed through the ansification filter
                 made #endif ANSI style.
01c,04may90,gae  added VME_AM_IS_XXX test macros for 16, 24, & 32 bit AM's.
01b,08nov89,shl  added ifdef to prevent inclusion of vxWorks.h more than once.
01a,02jun87,dnw  written.
*/

#ifndef INC_VME_H
#define INC_VME_H

#ifdef	__cplusplus
extern "C" {
#endif

#define VME_AM_EXT_USR_DATA             0x09

#ifdef	__cplusplus
}
#endif

#endif
