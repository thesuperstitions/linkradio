/* objLib.h - object management library header */


/*
modification history
--------------------
01q,20jun96,kkk	 undid 01p change.
01p,09feb96,mem  test for NULL pointer in OBJ_VERIFY.
01o,31aug94,rdc  beefed up OBJ_VERIFY.
01n,15oct93,cd   added #ifndef _ASMLANGUAGE.
01m,10dec93,smb  modified OBJ_VERIFY for windview level 1 instrumentation
01l,22sep92,rrr  added support for c++
01k,29jul92,jcf  added errno.h include.
01j,04jul92,jcf  cleaned up.
01i,26may92,rrr  the tree shuffle
01h,04dec91,rrr  some ansi cleanup.
01g,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed VOID to void
01f,10jun91.del  added pragma for gnu960 alignment.
01e,05apr91,gae  added NOMANUAL to avoid fooling mangen.
01d,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01c,15jul90,dnw  changed objAlloc() from (char*) to (void*)
		 added objAllocExtra()
01b,26jun90,jcf  added objAlloc()/objFree().
		 added standard object status codes.
01a,10dec89,jcf  written.
*/

#ifndef OBJ_LIB_H
#define OBJ_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#define M_objLib     (61 << 16)

#define S_objLib_OBJ_ID_ERROR                  (M_objLib | 1)
#define S_objLib_OBJ_UNAVAILABLE               (M_objLib | 2)
#define S_objLib_OBJ_DELETED                   (M_objLib | 3)
#define S_objLib_OBJ_TIMEOUT                   (M_objLib | 4)
#define S_objLib_OBJ_NO_METHOD                 (M_objLib | 5) 

#ifdef	__cplusplus
}
#endif

#endif
