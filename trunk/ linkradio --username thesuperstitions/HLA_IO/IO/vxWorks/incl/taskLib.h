/* taskLib.h - generic kernel interface header */


/*
modification history
--------------------
04h,12mar99,dbs  add COM task-local storage to TCB
04g,29may98,cym  added windowsContextValid flag for SIMNT.
04f,24apr98,kkk  moved wdbInfo after ARM stuff in TCB. (bug created by merge)
04e,19aug97,cym  added SIMNT support.
04d,28nov96,cdp  added ARM support.
04c,06nov97,dbt  modified WIND_TCB for new debugger scheme. Removed Am29K 
		 family support.
04b,22jul96,jmb  merge ease patch for HP Sim
04a,26may94,yao  added PPC support.
03z,26may95,ms	 added wdbExitHook field to the TCB
03y,16may95,rrr  add WDB_INFO structure to TCB.
03y,12jul95,ism  added simsolaris support
03x,19mar95,dvs  removed #ifdef TRON - tron no longer supported.
03w,15mar94,smb  modified TASK_SAFE macro
03v,24jan94,smb  added instrumentation macros
03u,10dec93,smb  instrumented TASK_LOCK macro
03t,02dec93,pme  added Am29K family support
03s,12nov93,hdn  added support for I80X86
03r,15oct93,cd   removed junk values from MIPS TCB.
03q,16sep93,jmm  added S_taskLib_ILLEGAL_PRIORITY and taskPriRangeCheck
03p,11aug93,gae  vxsim hppa.
03o,20jun93,rrr  vxsim.
03m,11feb93,jcf  added __PROTOTYPE_5_0 for compatibility.
03l,08feb93,smb  added a null check to taskIdVerify.
03k,13nov92,dnw  changed declaration of pSmObjTcb to struct sm_obj_tcb *
		 removed include of smObjTcbP.h (SPR #1768)
		 moved typedef of DBG_INFO here from dbgLib.h
		 removed include of dbgLib.h (SPR #1768)
03j,22sep92,rrr  added support for c++
03i,21sep92,smb  removed exit prototype and added include of stdlib.h
03h,02aug92,jcf  changed reserved3 field to pExcRegSet for exception handling.
03g,29jul92,smb  made modification for the stdio library.
03f,28jul92,jcf  added windxLock/reserved[12]; moved dbgInfo/pSmTcbObj;
		 removed funcRestart.
03e,12jul92,yao  replace pDbgState pointer with data structure DBG_INFO
		 in WIND_TCB.  added dbgPCWSave to i960.
03d,19jul92,pme  added shared memory objects support.
03c,10jul92,jwt  moved padding out of REG_SET in into WIND_TCB for SPARC.
03b,06jul92,ajm  removed taskSummary from forward declarations
03a,04jul92,jcf  cleaned up.
02y,16jun92,yao  made pDbgState available for all architectures.
02x,26may92,rrr  the tree shuffle
		  -changed includes to have absolute path from h/
02w,19mar92,yao  added ANSI prototype for taskStackAllot().
02v,12mar92,yao  removed ifdef CPU.  added taskRegsShow().
02u,10jan92,jwt  added CPU_FAMILY==SPARC architecture dependent prototypes.
02t,11nov91,rrr  Added funcRestart to tcb for signals.
02s,28oct91,wmd  Added changes for i960KB from Intel.
02r,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed VOID to void
		  -changed ASMLANGUAGE to _ASMLANGUAGE
02q,20sep91,hdn  deleted foroff from WIND_TCB for TRON.
		 added pDbgState to WIND_TCB for TRON.
02p,20aug91,ajm  made architecture independant.
01o,10jun91,del  added pragma for gnu960 alignment.
01n,23may91,wmd  added defines and macros for SPARC architecture.
01m,29apr91,hdn  added defines and macros for TRON architecture.
01l,08apr91,jdi  added NOMANUAL to prevent mangen.
02k,24mar91,del  added pDbgState for use with new dbgLib. And I960 defines.
02j,16oct90,shl  made #else ANSI style.
02i,05oct90,dnw  deleted private functions.
		 made taskSpawn, taskInit, taskCreate take var args.
02h,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
02g,01oct90,jcf  added addtional spares to WIND_TCB.
02f,03aug90,jcf  moved arch dependent portion of WIND_TCB to end of struct
02e,13jul90,rdc  added support for environment variables and additional
		 select functionality.
02d,30jun90,jcf  added assembly language defines.
02c,26jun90,jcf  removed obsolete generic status codes
		 changed inheritance protocol.
		 changed safetyQSem to a safetyQHead.
		 reworked priority mananagement.
		 changed topOfStack to endOfStack.
02b,17may90,rdc  changed select semaphores in tcb to be binary semaphores.
02a,17apr90,jcf  added error codes.
		 changed to wind 2.0.
01l,16mar90,rdc  added select semaphore to tcbx.
01k,25may89,gae  added VX_FORTRAN option.
01j,21apr89,jcf  added KERNEL_{UNINIT,VRTX,PSOS,WIND}.
01i,07nov88,rdc  added VX_ADA_DEBUG to task options.
01h,22jun88,dnw  name tweaks.
01g,30may88,dnw  changed to v4 names.
01f,28may88,dnw  deleted obsolete status values.
		 added EXC_INFO to tcbx.
01e,18may88,jcf  added psos semaphore head to tcbx.
		  extended maximum number of hooks to 10.
01d,13may88,rdc  added signal info to tcbx.
01c,28apr88,ecs  added IMPORTs of idle & taskName.
01b,13apr88,gae  added function declarations; option bit VX_STDIO;
		 taskStd[] to TCB extension.
01a,25jan88,jcf  written by extracting from vxLib.h v02l.
*/

#ifndef TASKLIB_H
#define TASKLIB_H

#include <vxWorks.h>
#include <memLib.h>
#include <objLib.h>
#include <semLib.h>

#ifdef	__cplusplus
extern "C" {
#endif

/* miscellaneous */

#define MAX_TASK_ARGS		10	/* max args passed to a task */
#define VX_MAX_TASK_SWITCH_RTNS	16	/* max task switch callout routines */
#define VX_MAX_TASK_SWAP_RTNS	16	/* max task swap callout routines */
#define VX_MAX_TASK_DELETE_RTNS	16	/* max task delete callout routines */
#define VX_MAX_TASK_CREATE_RTNS	16	/* max task create callout routines */

/* task option bits */

#define VX_SUPERVISOR_MODE	0x01	/* OBSOLETE: tasks always in sup mode */
#define VX_SERVER_MODE		0x01    /* special for pthreads */
#define VX_UNBREAKABLE	  	0x02	/* INTERNAL: breakpoints ignored */
#define VX_DEALLOC_STACK  	0x04	/* INTERNAL: deallocate stack */
#define VX_FP_TASK	   	0x08	/* 1 = f-point coprocessor support */
#define VX_STDIO	   	0x10	/* 1 = stdioLib support */
#define VX_ADA_DEBUG	   	0x20	/* 1 = VADS debugger support */
#define VX_FORTRAN	   	0x40	/* 1 = NKR FORTRAN support */
#define VX_PRIVATE_ENV 		0x80    /* 1 = private environment variables */
#define VX_NO_STACK_FILL        0x0100

typedef struct {
	unsigned int	priority;
	int		taskid;
} WIND_TCB;

/*
 * taskSetBarrier
 *
 * Set up a barrier that will prevent all threads from running until
 * the barrier is lowered by a call to taskLowerBarrier().
 * Call this before the high level application begins its 
 * main initialization process.
 */
STATUS taskSetBarrier();

/*
 * taskLowerBarrier
 * 
 * Lower the barrier preventing threads from running.
 * Call this after the high level application completes its 
 * main initialization process.
 */
STATUS taskLowerBarrier();

STATUS
taskDelay (
	int ticks
);

/*
 * @limitation Calling taskDelete on one's self is not supported by POSIX.
 */
STATUS
taskDelete (
	int tid
);

/*
 * @limitation This is currently the same as calling taskDelete.
 */
STATUS
taskDeleteForce (
	int tid
);

STATUS
taskPrioritySet (
	int tid,
	int newPriority
);

STATUS
taskSuspend (
	int tid
);

/*
 * @limitation This is currently not implemented
 */
STATUS
taskRestart (
	int tid
);

STATUS
taskResume (
	int tid
);

STATUS
taskLock (
	void
);

STATUS
taskUnlock (
	void
);

int
taskIdSelf (
	void
);

STATUS
taskIdVerify (
	int
);

STATUS
taskPriorityGet (
	int tid,
	int *pPriority
); 

char *
taskName (
	int tid
);

int
taskNameToId (
	char *name
);

int
taskIdListGet (
	int idList [ ],
	int maxTasks
);

/*
 * NOTE: There is a one-to-one correspondence between
 * tasks and POSIX threads. If the program is run as root,
 * real-time scheduling (using the SCHED_RR policy) is used.
 * Otherwise, timeshare scheduling is used.
 * @limitation VxWorks has 256 priority levels, but POSIX typically has
 * much fewer. To get around this problem, any VxWorks priority level less
 * than 50 is mapped to 50, and any priority level greater than
 * 176 is mapped to 176.
 */

#ifdef  __PROTOTYPE_5_0
	int  taskSpawn (char *name, int priority, int options, int stackSize,
                   FUNCPTR entryPt, ...);
#else
	STATUS
	taskSpawn (
		char	*name,
		int	priority,
		int	options,
		int	stackSize,
		FUNCPTR	entryPt,
		int	arg1,
		int	arg2,
		int	arg3,
		int	arg4,
		int	arg5,
		int	arg6,
		int	arg7,
		int	arg8,
		int	arg9,
		int	arg10
	);
#endif  /* __PROTOTYPE_5_0 */

int
taskInit (
	WIND_TCB *pTcb,
	char	*name,
	int	priority,
	int	options,	/* ignored */
	char	*pStackBase,	/* ignored */
	int	stackSize,
	FUNCPTR	entryPt,
	int	arg1,
	int	arg2,
	int	arg3,
	int	arg4,
	int	arg5,
	int	arg6,
	int	arg7,
	int	arg8,
	int	arg9,
	int	arg10
);

STATUS
taskActivate (
	int tid
);

/*
 * Intended to be called by the infrastructure (cgai library) to register a POSIX
 * task so it can be displayed by the shell. Note: this function should be called
 * by the spawned task itself, not by the task that spawned it.
 */
void
register_task (
	char		*name,
	int		vxworks_priority,
	int		stack_size,
	FUNCPTR		entry_pt,
	pthread_t	thread_id
);

/*
 * Thread-friendly version of putenv: the environment is
 * inherited when threads (tasks) are spawned, but each
 * thread maintains its own environment.
 */
STATUS
put_task_environ (
	const char	*name,
	const char	*value
);

/*
 * Thread-friendly version of getenv: the environment is
 * inherited when threads (tasks) are spawned, but each
 * thread maintains its own environment.
 */
char *
get_task_environ (
	const char	*name
);

STATUS
task_name (
	unsigned int	task_id,
	char		*name_buf,
	int		name_buf_len
);

BOOL
taskIsReady (
	int		tid
);

BOOL
taskIsSuspended (
	int		tid
);

typedef struct {
	unsigned long int __psbits[8];  /* 256 bits */
} __priset_t;

/*
 * This function can be called to add a VxWorks priority
 * to a set of priorities. Normally, additions to this
 * set are made automatically by the task spawning functions
 * in taskLib. However, if task priorities in different
 * applications are known via some mechanism, this function
 * can be called to add these priorities (one at a time) to
 * the set. If the priority set has changed, the priorities
 * are automatically remapped; 0 is returned for no remapping,
 * 1 for successful remapping, and -1 for error during task
 * priority remapping.
 * 
 */
int add_priority(int vxworks_priority);

/*
 * This function returns a set of VxWorks priorities that have
 * been added either automtically (when the task is spawned)
 * via the add_priority function (see above) or by the call
 * to put_pri_set (see below).
 */
void get_pri_set(__priset_t *set);

/*
 * This function performs a set union of VxWorks priorities
 * in the argument with the current set of VxWorks priorities.
 * It is typically used when a priority set is received from
 * another process and must be combined with the current
 * process's set. If the priority set has changed, the priorities
 * are automatically remapped; 0 is returned for no remapping,
 * 1 for successful remapping, and -1 for error during task
 * priority remapping.
 */
int put_pri_set(__priset_t *set);

/*
 * Converts a VxWorks priority into a POSIX thread priority.
 */
int posix_priority(int vxworks_priority);

/*
 * Converts a POSIX thread priority into a VxWorks task priority.
 */
int vxworks_priority(int posix_priority);

STATUS
threadPriorityGet (
	const char *name,	/* in; task name, set in 1st arg to taskSpawn */
	int *tPriority		/* in,out; thread's posix priority */
);

STATUS
threadPrioritySet (
	const char *name,      /* in; task name, set in 1st arg to taskSpawn */
	int newPosixPriority   /* in; the new posix priority */
);

STATUS
taskGetInfo(
	int tid, char **name, int *posixPri, int *vxWorksPri, int *stackSize,
	int *threadId, int *lwProId
);
		

#ifdef	__cplusplus
}
#endif

#endif /* TASKLIB_H */
