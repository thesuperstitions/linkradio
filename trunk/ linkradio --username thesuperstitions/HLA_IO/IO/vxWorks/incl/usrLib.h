/* usrLib.h - header for user interface subroutines */


/*
modification history
--------------------
02f,27may95,p_m  added spy routines prototypes.
02e,22sep92,rrr  added support for c++
02d,18sep92,smb  moved mkdir and rmdir prototype to sys/stat.h and
		 unistd.h repecatively and included sys/stat.h and unistd.h
02c,29jul92,smb  changed parameter to printErrno from errno to errNo.
02b,15jul92,jmm  changed ld() to return MODULE_ID rather than STATUS
02a,04jul92,jcf  cleaned up.
01v,25jun92,yao  added ANSI definition for pc().
01u,16jun92,yao  changed declaration for mRegs().
01t,26may92,rrr  the tree shuffle
01s,20jan92,yao  removed ANSI definition for register displaying routines.
		 removed conditional CPU_FAMILY != I960.  changed ANSI
		 propotype definition for d(), m() and mRegs().
01r,09jan92,jwt  converted CPU==SPARC to CPU_FAMILY==SPARC.
01q,07nov91,hdn  added defines F0 - F15, FPMCR, FPSR, FPQR for G200.
01p,07nov91,wmd  conditionalized declaration of d() with BYTE_ORDER.
01o,29oct91,shl  removed duplicate rename() prototype -- SPR #927.
01n,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed VOID to void
01m,20aug91,ajm  added MIPS_R3k support.
01l,14aug91,del  (intel) added FPx regs for I960KB support.
01k,29apr91,hdn  added defines and macros for TRON architecture.
01j,03feb90,del  added I960 support.
01i,05oct90,dnw  deleted private functions.
		 changed spawn, etc, to take var args.
01h,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01g,20aug89,gae  changed ifdef to CPU_FAMILY.
01f,16jul88,ecs  added SPARC register codes.
01e,24dec86,gae  changed stsLib.h to vwModNum.h.
01d,20aug86,llk  added register codes.
01c,10feb86,dnw  deleted obsolete definition of S_usrLib_NO_FREE_TID.
01b,13aug84,dnw  changed name to usrLib.
01a,06aug84,ecs  written
*/

#ifndef __INCusrLibh
#define __INCusrLibh

#ifdef __cplusplus
extern "C" {
#endif

#include <vwModNum.h>
#include <regs.h>
#include <fppLib.h>
#include <moduleLib.h>
#include <sys/stat.h>
#include <vxWorks.h>

/* usrLib status codes */

#define M_usrLib	(35 << 16)
#define S_usrLib_NOT_ENOUGH_ARGS	(M_usrLib | 1)


/* function declarations */

int
help (
	int ignore
);

int
i (
	int taskNameOrId
);

void
printErrno (
	int errNo
);

void
checkStack (
	int taskNameOrId
);

int copy (
	char *in,
	char *out
);

/*
 * @limitation Not implemented.
 */
void
logout (
	void
);

/*
 * @limitation Not implemented.
 */
void
d (
	void *adrs,
	int nunits,
	int width
);

int sp (
	FUNCPTR func,
	int arg1,
	int arg2,
	int arg3,
	int arg4,
	int arg5,
	int arg6,
	int arg7,
	int arg8,
	int arg9
);

#ifdef __cplusplus
}
#endif

#endif /* __INCusrLibh */
