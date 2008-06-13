/* routeLib.h - header file for the network routing library */


/*
modification history
--------------------
02f,26jun98,spm  added mRouteEntryDelete prototype
02e,10jul97,rjc  added flag param to mRouteDelete.
02d,11apr97,rjc  changed interface of m2RouteEntryAdd
i02c,14feb97,rjc added mask versions of route add etc
02d,11jul94,dzb  added prototype for routeNetAdd() (SPR #3395).
02c,22sep92,rrr  added support for c++
02b,27jul92,elh  moved routeShow to netShow.
02a,04jul92,jcf  cleaned up.
01g,26may92,rrr  the tree shuffle
01f,02mar92,elh  added routeCmd.
01e,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01d,05oct90,shl  added ANSI function prototypes.
01c,07aug90,shl  added IMPORT type to function declarations.
01b,16nov87,llk  documentation
01a,01nov87,llk  written
*/

#ifndef ROUTE_LIB_H
#define ROUTE_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * @limitation This routine always returns OK. It makes
 * the assumption that on a workstation, the necessary
 * routes have already been set up. (Routes cannot be
 * set by ordinary users, only by the super-user.)
 */
STATUS
routeAdd (
	char	*destination,
	char	*gateway
);

/*
 * @limitation This routine always returns OK. It makes
 * the assumption that on a workstation, the necessary
 * routes have already been set up. (Routes cannot be
 * set by ordinary users, only by the super-user.)
 */
STATUS
routeDelete (
	char	*destination,
	char	*gateway
);

/*
 * @limitation Simply invokes the Unix command "netstat -r".
 */
void
routeShow (
	void
);

#ifdef	__cplusplus
}
#endif

#endif /* ROUTE_LIB_H */
