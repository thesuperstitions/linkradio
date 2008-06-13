/* taskHookLib.h - header file for taskHookLib.c */


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

#ifndef __INCtaskHookLibh
#define __INCtaskHookLibh

#ifdef __cplusplus
extern "C" {
#endif

/* function declarations */

#if defined(__STDC__) || defined(__cplusplus)

void
taskHookInit (
	void
);

/*
 * @limitation Not implemented.
 */
STATUS 
taskCreateHookAdd (
	FUNCPTR createHook
);

/*
 * @limitation Not implemented.
 */
STATUS 
taskCreateHookDelete (
	FUNCPTR createHook
);

/*
 * @limitation Not implemented.
 */
STATUS 
taskDeleteHookAdd (
	FUNCPTR deleteHook
);

/*
 * @limitation Not implemented.
 */
STATUS 
taskDeleteHookDelete (
	FUNCPTR deleteHook
);

/*
 * @limitation Not implemented.
 */
STATUS 
taskSwapHookAdd (
	FUNCPTR swapHook
);

/*
 * @limitation Not implemented.
 */
STATUS 
taskSwapHookAttach (
	FUNCPTR swapHook,
	int tid,
	BOOL in,
	BOOL out
);

/*
 * @limitation Not implemented.
 */
STATUS 
taskSwapHookDelete (
	FUNCPTR swapHook
);

/*
 * @limitation Not implemented.
 */
STATUS 
taskSwapHookDetach (
	FUNCPTR swapHook,
	int tid,
	BOOL in,
	BOOL out
);

/*
 * @limitation Not supported in POSIX environment; always
 * returns ERROR.
 */
STATUS 
taskSwitchHookAdd (
	FUNCPTR switchHook
);

/*
 * @limitation Not supported in POSIX environment; always
 * returns ERROR.
 */
STATUS 
taskSwitchHookDelete (
	FUNCPTR switchHook
);

/*
 * @limitation Not implemented.
 */
void
taskHookShowInit (
	void
);

/*
 * @limitation Not implemented.
 */
void 
taskCreateHookShow (
	void
);

/*
 * @limitation Not implemented.
 */
void 
taskDeleteHookShow (
	void
);

/*
 * @limitation Not implemented.
 */
void 
taskSwapHookShow (
	void
);

/*
 * @limitation Not implemented.
 */
void 
taskSwitchHookShow (
	void
);

#else	/* __STDC__ */

extern void	taskHookInit ();
extern STATUS 	taskCreateHookAdd ();
extern STATUS 	taskCreateHookDelete ();
extern STATUS 	taskDeleteHookAdd ();
extern STATUS 	taskDeleteHookDelete ();
extern STATUS 	taskSwapHookAdd ();
extern STATUS 	taskSwapHookAttach ();
extern STATUS 	taskSwapHookDelete ();
extern STATUS 	taskSwapHookDetach ();
extern STATUS 	taskSwitchHookAdd ();
extern STATUS 	taskSwitchHookDelete ();
extern void	taskHookShowInit ();
extern void 	taskCreateHookShow ();
extern void 	taskDeleteHookShow ();
extern void 	taskSwapHookShow ();
extern void 	taskSwitchHookShow ();

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif /* __INCtaskHookLibh */
