/* mathP.h - private definitions for math functions */


/*
modification history
--------------------
01h,23jan97,cdp  reverse words in double for ARM.
01g,22sep92,rrr  added support for c++
01f,04sep92,wmd  modified definition of DOUBLE for BIG/LITTLE ENDIAN architectures.
01e,30jul92,kdl  added fp type test macros; deleted declarations of unused
		 routines (isnan(), etc.); changed _d_type() to fpTypeGet();
		 deleted prototypes for _dNormalize, _finite, _upscale.
01d,30jul92,kdl  added DOUBLE union definition, from floatLib.c.
01c,08jul92,smb  added to clib library.
01b,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
01a,14sep90,mcl  adapted from Berkeley.
*/

#ifndef MATHP_H
#define MATHP_H

#ifndef LINUX

#ifdef __cplusplus
extern "C" {
#endif

#define ZERO    0
#define REAL    1
#define INTEGER 2
#define INF     3
#define NAN     4

extern int isNan(double num); /* returns TRUE(1) or FALSE(0) */
extern int isZero(double num);/* returns TRUE(1) or FALSE(0) */
extern int isInf(double num); /* returns TRUE(1) or FALSE(0) */

extern int fpTypeGet(double v, double *r); /* returns NAN, ZERO, or INF */

#ifdef __cplusplus
}
#endif

#endif /* not LINUX */

#endif /* MATHP_H */
