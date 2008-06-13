/* wdLib.h - watchdog timer library header */


/*
modification history
--------------------
02b,22sep92,rrr  added support for c++
02a,04jul92,jcf  cleaned up.
01h,26may92,rrr  the tree shuffle
01g,04oct91,rrr  passed through the ansification filter
01f,23oct90,shl  changed wdStart()'s third parameter type to VOIDFUNCPTR.
01e,05oct90,dnw  deleted private functions.
01d,05oct90,shl  added ANSI function prototypes.
01c,26jun90,jcf  removed generic status codes.
01b,17apr90,jcf  subsumed into wind 2.0.
01a,21may84,dnw  written
*/

#ifndef WD_LIB_H
#define WD_LIB_H

#include <vxWorks.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct _wdog_id {
	struct _wdog_id		*next;
	struct _wdog_id		*prev;
	struct timespec		abs_time;
	VOIDINTFUNCPTR		pRoutine;
	int			parameter;
	long msTimer;
} *WDOG_ID;

WDOG_ID
wdCreate (
	void
);

STATUS
wdDelete (
	WDOG_ID wdId
);

/*
 * @limitation In this POSIX implementation, the watch dog
 * capability is implemented using a thread that keeps a
 * time-sorted list of events. When a given timer expires,
 * the routine is called by this thread, <i>not</i> at interrupt
 * level.
 */
STATUS
wdStart (
	WDOG_ID wdId,
	int delay,
	FUNCPTR pRoutine,
	int parameter
);

STATUS
wdCancel (
	WDOG_ID wdId
);

void
wdShowInit (
	void
);

/*
 * @limitation Not supported
 */
STATUS
wdShow (
	WDOG_ID wdId
);

#ifdef	__cplusplus
}
#endif

#endif
