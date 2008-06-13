/* vxLib.h - header file for vxLib.c */


/*
modification history
--------------------
02i,04jun97,dat  added _func_vxMemProbeHook and vxMemArchProbe, SPR 8658
		 removed sysMemProbe.
02h,22oct96,spm  added comment specifying location of checksum() definition
02g,28feb96,tam	 added #include for ppc/vxPpcLib.h.
02f,04jul94,tpr	 added #include for mc68k/vx68kLib.h.
02e,02dec93,pme  added Am29K family support.
02c,24sep92,yao  added missing arg in vxTas() declaration.
02b,22sep92,rrr  added support for c++
02a,04jul92,jcf  cleaned up.
01f,30jun92,jmm  moved checksum() declarations to here from icmpLib.h
01e,26may92,rrr  the tree shuffle
		  -changed includes to have absolute path from h/
01d,21apr92,ccc  added vxTas.
01c,27feb92,wmd  added #include for i960/vx960Lib.h.
01b,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
01a,05oct90,shl created.
*/

#ifndef __INCvxLibh
#define __INCvxLibh

#ifdef __cplusplus
extern "C" {
#endif

/* function declarations */

#if defined(__STDC__) || defined(__cplusplus)

/*
 * @limitation This routine has no effect in this
 * POSIX implementation, and always returns ERROR.
 */
STATUS
vxMemProbe (
	char *adrs,
	int mode,
	int length,
	char *pVal
);

#else	/* __STDC__ */

extern STATUS 	vxMemProbe ();

extern STATUS 	vxMemArchProbe ();

extern FUNCPTR 	_func_vxMemProbeHook;

extern BOOL 	vxTas ();

/* checksum is defined in ./target/src/util/cksumLib.c */
extern u_short	checksum ();

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif /* __INCvxLibh */
