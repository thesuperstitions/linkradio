/* semLib.h - semaphore library header file */


/*
modification history
--------------------
04e,16feb98,cdp  added #ifndef _ASMLANGUAGE.
04d,10jul96,dbt  added declaration of semMGiveForce (SPR #4352).
03c,14jul94,dvs  added non-ANSI prototype for semCreate/semOLibInit (SPR# 2648).
03b,22sep92,rrr  added support for c++
03a,04jul92,jcf  cleaned up.
02k,26may92,rrr  the tree shuffle
02j,18apr92,jmm  added prototype for semTerminate
02i,19nov91,rrr  shut up some ansi warnings.
02h,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed ASMLANGUAGE to _ASMLANGUAGE
02g,10jun91.del  added pragma for gnu960 alignment.
02f,16oct90,shl  made #else ANSI style.
02e,05oct90,dnw  deleted private functions; doc tweaks
02d,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
02c,27jun90,jcf  added defines for optimized version.
02a,26jun90,jcf  rewritten to provide binary/counting/mutex w/ one structure.
		 introduced semaphore options.
		 removed generic status codes.
01a,02jan90,jcf  written.
*/

#ifndef SEMLIB
#define SEMLIB

#ifndef CPU
#include <sys/ipc.h>
#endif
#include <prototype.h>
#include <vxWorks.h>

typedef void* SEM_ID;

#ifdef CPU
#include <semLib.h>
#else

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum            /* SEM_B_STATE */
{
        SEM_EMPTY,                  /* 0: semaphore not available */
        SEM_FULL                    /* 1: semaphore available */
} SEM_B_STATE;

#define M_semLib             (22 << 16)

#define S_semLib_INVALID_STATE			(M_semLib | 101)
#define S_semLib_INVALID_OPTION			(M_semLib | 102)
#define S_semLib_INVALID_QUEUE_TYPE		(M_semLib | 103)
#define S_semLib_INVALID_OPERATION		(M_semLib | 104)

/* semaphore options */
#define SEM_Q_MASK              0x3     /* q-type mask */
#define SEM_Q_FIFO              0x0     /* first in first out queue */
#define SEM_Q_PRIORITY          0x1     /* priority sorted queue */
#define SEM_DELETE_SAFE         0x4     /* owner delete safe (mutex opt.) */
#define SEM_INVERSION_SAFE      0x8     /* no priority inversion (mutex opt.) */
#endif


/* semaphore routines */

SEM_ID
semBCreate (
	int options,
	SEM_B_STATE initialState
);

SEM_ID
semCCreate (
	int options,
	int initialCount
);

SEM_ID
semMCreate (
	int options
);

STATUS
semGive (
	SEM_ID semId
);

STATUS
semFlush (
	SEM_ID semId
);

STATUS
semMGiveForce (
	SEM_ID semId
);

int
semInfo (
	SEM_ID semId,
	int idList[],
	int maxTasks
);

STATUS
semTake (
	SEM_ID semId,
	int timeout
);

STATUS
semDelete (
	SEM_ID semId
);

void
Sem_Show (
	void
);

STATUS
semShow (
	SEM_ID semId,
	int level
);

#ifdef	__cplusplus
}
#endif

#endif /* SEMLIB */
