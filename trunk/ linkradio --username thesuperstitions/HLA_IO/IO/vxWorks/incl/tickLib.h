/* tickLib.h - header file for tickLib.c */


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

#ifndef __INCtickLibh
#define __INCtickLibh

#include <vxTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* typedefs */

#if 0
typedef struct		/* TICK */
    {
    ULONG lower;		/* 00: least significant 32 bits */
    ULONG upper;		/* 04: most significant 32 bits */
    } TICK;

/* variable declarations */

extern ULONG	vxTicks;		/* relative time counter */
extern TICK	vxAbsTicks;		/* abs time since startup in ticks */
#endif

/* function declarations */

#if defined(__STDC__) || defined(__cplusplus)

/*
 * @limitation Not supported
 */
void 
tickAnnounce (
	void
);

/*
 * @limitation Not supported
 */
void 
tickSet (
	ULONG ticks
);

/*
 * @limitation In this POSIX implementation, there is no tick counter <i>per se</i>.
 * Instread, this routine returns the number of "ticks" since the first time it was
 * called. The Unix clock is used to calculate the tick value.
 */
ULONG 
tickGet (
	void
);

#else

extern void 	tickAnnounce ();
extern void 	tickSet ();
extern ULONG 	RT_tickGet ();

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif /* __INCtickLibh */
