/* shellLib.h - header for shell facilities */


/*
modification history
--------------------
02c,22sep92,rrr  added support for c++
02b,16jul92,jcf  added variable declarations.
02a,04jul92,jcf  cleaned up.
01e,26may92,rrr  the tree shuffle
01d,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01c,05oct90,dnw  deleted private functions
01b,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01a,10aug90,dnw  written
*/

#ifndef SHELL_LIB_H
#define SHELL_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

void
shellPromptSet (
	const char	*newPrompt
);

/*
 * @limitation Not implemented.
 */
BOOL
shellLock (
	BOOL
);

#ifdef	__cplusplus
}
#endif

#endif /* SHELL_LIB_H */
