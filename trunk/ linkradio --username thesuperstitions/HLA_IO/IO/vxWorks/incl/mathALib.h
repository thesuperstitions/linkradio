/* mathALib.h
*
* many of the math functions are provided by Solaris and prototyped in
* /usr/include/math.h, however a few provided by vxworks are not provided by
* solaris so they have been added here as needed.
*/

#ifndef __INCmathh
#define __INCmathh

#ifdef __cplusplus
extern "C" {
#endif

extern int iround (double x);

#ifndef LINUX 
				/* Solaris does not have the 'round' func but Linux does */
	extern double round (double x);
#endif /*LINUX*/

#ifdef __cplusplus
}
#endif

#endif /* __INCmathh */

