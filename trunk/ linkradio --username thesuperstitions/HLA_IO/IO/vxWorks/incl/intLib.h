/* intLib.h - interrupt library header file */


/*
modification history
--------------------
01v,03jun98,hdn  added intHandlerCreateX86() prototype.
01u,25nov97,cdp  moved ARM-specific things to arch/arm/intArmLib.h.
01t,28oct97,kkk  added INT_NON_PREEMPT_MODEL macro.
01s,19aug97,cdp  added intLibInit, INT_PREEMPT_MODEL and INT_HDWE_LOCK_LVL.
01r,27feb97,cdp  added intEnable and intDisable for ARM.
01p,29nov96,kkk  added prototypes for MIPS routines in the __STDC__ section.
		 took out intEnable & intDisable. (conflicts with PPC).
01p,25nov96,kkk  added prototypes for MIPS interrupt routines.
01q,13dec96,tpr  added #if/#endif arround intEnable() & intDisable() prototypes.
01p,09dec96,tpr  added intEnable() & intDisable() prototypes.
01o,15jun95,ms	 added intRegsLock, intRegsUnlock prototypes
01n,02dec93,tpr	 removed am29200Intr3Connect() and am29200Intr3Drv().
	    tpr  added am29200Intr3DeMuxConnect().
	    tpr  added am29200Intr3Connect() and am29200Intr3Drv() for am29200.
	    pad  added am29k family support.
01m,15oct92,jwt  added intVecTableWriteEnable() prototype for SPARC.
01l,22sep92,rrr  added support for c++
01k,27jul92,rdc  added S_intLib_VEC_TABLE_WP_UNAVAILABLE and
		 intVecTableWriteProtect ().
01j,04jul92,jcf  cleaned up.
01i,26may92,rrr  the tree shuffle
01h,10jan92,jwt  added intAckConfig(), intTBRSet() prototypes for SPARC.
01g,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01f,08apr91,jdi  added NOMANUAL to prevent mangen.
01e,23oct90,shl  fixed misspelling in intUnlock().
		 changed intConnect() to take a VOIDFUNCPTR.
01d,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01c,10aug90,dnw  added declaration of intVecSet().
01b,15jul90,dnw  added INT_CONTEXT()
01a,11apr90,jcf  written.
*/

#ifndef INT_LIB_H
#define INT_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * @limitation For Unix systems, one cannot install an interrupt handler using
 * this routine. Instead, <i>vector</i> represents a POSIX signal. Upon receipt
 * of the signal, the signal handler is invoked with the supplied argument.
 */
STATUS
intConnect
(
        VOIDFUNCPTR	*vector,    /* interrupt vector to attach to     */
        VOIDFUNCPTR	routine,   /* routine to be called              */
        int		parameter  /* parameter to be passed to routine */
);

/*
 * @limitation For Unix systems, this call does nothing.
 */
int
intLock (
	void
);

/*
 * @limitation For Unix systems, this call does nothing.
 */
void
intUnlock (
	int lockKey
);

#ifdef	__cplusplus
}
#endif

#endif
