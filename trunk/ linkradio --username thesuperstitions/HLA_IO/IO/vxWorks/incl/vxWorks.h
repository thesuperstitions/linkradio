/* vxWorks.h - VxWorks standard definitions header */


/*
modification history
--------------------
03h,17feb99,mrs  Add C++ support for NULL, (SPR #25079).
03g,25nov97,dat  added BUS_TYPE macros
03f,26nov96,vin  modified BSD to 44.
03e,23aug94,ism  added the MSW() and LSW() macros (SPR#3541)
03d,22sep92,rrr  added support for c++
03c,07sep92,smb  added #undef BSD to remove previous definition
03b,11jul92,smb  moved CPU definitions to types/vxCpu.h
03a,04jul92,jcf  cleaned up.
02q,28jun92,smb  reworked for ANSI lib.
02p,22jun92,rrr  added MIPS CPU_FAMILY
02o,16jun92,jwt  added (CPU_FAMILY = SPARC) for (CPU == SPARClite).
02n,26may92,rrr  the tree shuffle
02m,17mar92,yao  added _STACK_GROWS_DOWN/UP.  added macros ROUND_UP/DOWN,
		 ALIGNED, MEM_ROUND_UP/DOWN, STACK_ROUND_UP/DOWN, MEM_ALIGNED.
		 definitions for 960 to changed BYTE_ORDER to _BYTE_ORDER,
		 BIG/LITTLE_ENDIAN to _BIG/LITTLE_ENDIAN.  arch960.h.  removed
		 conditional include of r3k/arch.h.
02l,09jan91,wmd  conditionalized out ffsMSB inline definition to shut up
 		 ansi warnings.
02k,11nov91,jpb  added definition for R3K CPU_FAMILY.
02j,28oct91,wmd  for lack of better place -  added Intel's 960 ffsMSB
		 inline definition here.
02i,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed READ, WRITE and UPDATE to O_RDONLY O_WRONLY and ...
02h,25sep91,yao  added CPU32.
02g,10sep91,wmd  added MIPS to conditional for BIG_ENDIAN byte order.
02f,20aug91,ajm  added MIPS_R3k support.
02e,14aug91,del  (intel) added I960KA/KB defines.
02d,29apr91,hdn  added defines and macros for TRON architecture
02c,31mar91,del  added #define of BYTE_ORDER for network etc.
02b,25oct90,dnw  changed to allow NULL to be redefined.
02a,25oct90,shl  combined CPU test for I960KB and I960CA into one.
...deleted pre v2a history - see RCS
*/

#ifndef VXWORKS_H
#define VXWORKS_H

#include <mathALib.h>   /* fix Unix/VxWorks mismatch with math.h */
#include <strings.h>	/* fix Unix/VxWorks mismatch with strings.h & string.h */
#include <lstLib.h>
#include <pthread.h>
#include <stdlib.h>
#include <vxTypes.h>
#include <errno.h>
#include <semLib.h>

#undef NULL
#define NULL 0

#define WAIT_FOREVER	(-1)
#define NO_WAIT		0

#if     !defined(FALSE) || (FALSE!=0)
#define FALSE           0
#endif

#if     !defined(TRUE) || (TRUE!=1)
#define TRUE            1
#endif

#ifndef ERROR
#define ERROR (-1)
#endif

#ifndef OK
#define OK 0
#endif

#ifndef EOS
#define EOS '\0'
#endif

#ifndef NONE
#define NONE (-1)
#endif

#ifndef FOREVER
#define FOREVER while (1)
#endif

#define STD_IN 0
#define STD_OUT 1
#define STD_ERR 2

#define INUM_TO_IVEC(intNum) (intNum)

#define	max(a, b) 		((a) < (b) ? (b) : (a))
#define	min(a, b) 		((a) > (b) ? (b) : (a))

#define NUM_DOSFS_FILES	20
#define NUM_RAWFS_FILES	5

#define VX_READ	0

#define LOCAL	static

#define BBRAM_ADRS	0

#include <taskLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Set the system clock rate.
 *
 * Possible return values are OK and ERROR. 
 *
 * Solaris: If the application requests a real time clock via the -r0
 * command line argument (or no -r argument), and a clock rate that is greater than what 
 * the system booted with, the function returns ERROR and prints a 
 * warning message. If the requested rate matches what the system was booted
 * with and actually running then the function will return OK. 
 *
 * @limitation Solaris: The clock rate can't be set during runtime
 * but instead is set at system boot time. It defaults to 10msec or 100 ticks
 * per second. It can be changed to 1msec or 1000 ticks per second by adding the
 * hires_tick boolean to the /etc/system file and rebooting. It can also be 
 * changed to other values but more complicated techniques are used and
 * not described here. 
 *
 */
STATUS
sysClkRateSet (
	int  ticksPerSecond
);

int
sysClkRateGet (
	void
);

void
bcopyLongs (
	char *source,		/* pointer to source buffer      */
	char *destination,	/* pointer to destination buffer */
	int nlongs		/* number of longs to copy       */
);

void
bfill (
	char *buf,
	int nbytes,
	int ch
);

/*
 * @limitation In this POSIX implementation, this "shell" provides
 * an interface that looks a little bit like the VxWorks shell, and
 * it also incorporates any registered "Command Processor" commands.
 * Note that one can terminate the program by typing a Ctrl-C from
 * the keyboard, and responding "y" to the question. This routine is
 * run in the context of the programs "main" function, which is
 * automatically added to the func_start.cc file when the program
 * is compiled.
 */
void
shell (
	VOIDINTFUNCPTR	terminate_function
);

void
no_shell (
	VOIDINTFUNCPTR	terminate_function
);

void
set_shell_prompt (
	const char *new_prompt
);

/*
 * @limitation This routine should be called for every mq_open in order
 * to register the message queue's name. On exit from the program,
 * the message queues are removed, as POSIX doesn't automatically do this.
 */
void
remember_mq_name (
	const char *name,
	const unsigned int mq_id
);

/*
 * This routine returns the string corresponding to the command-line
 * argument <i>arg</i>, which ranges from 'a' to 'z'. A NULL is returned
 * if there is no argument in that position. The program name argv[0] can
 * be retrieved by calling this function with arg = 0 (zero).
 * @limitation The "standard" command-line arguments are copied
 * into an array by the main function.
 */
char *
get_command_line_arg (
	char arg
);

/*
 * This routine returns the string corresponding to an application-specific option,
 * embedded within the special -x option. For example, if a program is invoked with
 * -x "Debug=2;B", then this routine parses the string and returns "2" when invoked with
 * 'Debug' and the string "1" when invoked with 'B'. If the application-specific option
 * is not defined, NULL is returned.
 */
const char *
get_appl_option (
	char *arg
);

/*
 * This function returns an integer version of
 * the user index, provided via the command-line
 * argument "-i". Note that if an index hasn't
 * been provided, 0 is returned.
 */
int
get_ws_user_index ();


void
save_standard_args (
	int	argc,
	char	*argv[],
	int	*new_argc,
	char	***new_argv
);

/*
 * This routine saves a "Command Processor" command, and is
 * invoked by Log_Cmnd.
 */
int
shell_cmnd (
	const char *name,
	const char *def,
	int (*start)(int)
);

/*
 * Same as shell_cmnd, but 4th argument is passed
 * to start() whenever invoked.
 */
int
shell_cmnd_plus (
	const char *name,
	const char *def,
	int (*start)(int),
	int arg
);

/*			SET_CLOCK_RATE
 *
 * This routine is called whenever the clock rate exponent
 * is to be changed. Typically it would be called during a
 * playback, and its value is distributed via the
 * status monitoring mechanism.
 * @limitation There is a built-in timeout
 * of 30 sec. after each change before the next change is
 * accepted. This is required to allow status monitoring
 * to settle down.
 */
void
Set_Clock_Rate (
	int	clock_rate_exponent
);

/*			GET_CLOCK_RATE
 * Returns the clock rate exponent previously set
 * by Set_Clock_Rate.
 */
int
Get_Clock_Rate (
	void
);

/*
 * This routine is invoked by root to initialize
 * the mechanism that supports thread-specific
 * alarms (see start_ms_alarm and cancel_ms_alarm).
 * 0 is returned on success, -1 on failure.
 */
int
init_per_thread_alarm (
	void
);

/*
 * This routine starts a timer that generates a SIGUSR1
 * signal when it expires. The argument is the time in
 * milliseconds. The timer can be canceled with
 * cancel_ms_alarm.
 */
int
start_ms_alarm (
	unsigned int	ms
);

/*
 * Cancel an alarm timer that was started with
 * start_ms_alarm.
 */
int
cancel_ms_alarm (
	void
);

/*
 * This routine prepares a Pthread attributes structure
 * in preparation to creating a thread. It sets the attributes
 * as follows: the thread is bound to a LWP; the thread is
 * detached; a FIFO scheduling policy is set if running as
 * root; the stack size is set; and the supplied vxWorks
 * priority is mapped to a corresponding POSIX priority.
 * This routine is called in at least 3 places: by taskSpawn()
 * in taskLib.cc; for the alarm thread in vxWorks.cc; and for
 * the watchdog thread in wdLib.cc. It returns OK or ERROR.
 */
int
prepare_thread_attr (
	pthread_attr_t	*attr_p,
	int		vxworks_priority,
	int		stack_size
);

#define NVRAM_OCTETS 65536

/*
 * For this POSIX version, NVRAM is emulated by using a
 * disk file name ".nvram_userX" in the current directory,
 * where X is the user index.
 */
STATUS
sysNvRamGet (
	char *s,
	int strLen,
	int offset
);

/*
 * For this POSIX version, NVRAM is emulated by using a
 * disk file name ".nvram_userX" in the current directory,
 * where X is the user index.
 */
STATUS
sysNvRamSet (
	char *s,
	int strLen,
	int offset
);

#ifdef __cplusplus
/*
 * The following function allows one to register certain global
 * debugging flags. Then, the two command-processor commands
 * "set_global_flags" and "clear_all_global_flags" can be used
 * to modify them. You would typically call this function from
 * the special "startup" (or "go") file -- see the Makefile.
 */
void
Register_Global (
	char *name,			// label for flag in "set_global_flags"
	int *global_flag_ptr,		// address of global flag
	bool set_initial_value = false,	// if true, sets flag to initial_value
	int initial_value = 0		// used to set flag if set_initial_value is true
);
#endif

/*
 * For all applications except main_ctrl, shell() is invoked with the following
 * function. Its purpose is to destroy a processor set created by this application
 * (if any). [Applies to Solaris only.]
 */
void
Terminate_Pset (
	int pgrp_ignored
);

/*
 * This function gracefully shuts down the application by unlinking any message
 * queues, invoking the termination function (if any), and exiting. Intended to
 * be called via the "shutdown" command or from main_ctrl.
 */
void
graceful_shutdown();


#ifdef __cplusplus
}
#endif

#include <sysLib.h>

#endif /* _VXWORKS_H */
