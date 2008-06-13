/* netShow.h - header file for netShow.c */


/*
modification history
--------------------
01h,12sep94,dzb  added tcpDebugShow() declaration (SPR #1552).
01g,22sep92,rrr  added support for c++
01f,27jul92,elh  Moved hostShow and routeShow here.
01e,04jul92,jcf  cleaned up.
01d,11jun92,elh  moved arpShow here from arpLib.
01c,26may92,rrr  the tree shuffle
01b,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed VOID to void
01a,05oct90,shl created.
*/

#ifndef NETSHOW_H
#define NETSHOW_H

#ifdef	__cplusplus
extern "C" {
#endif

void mbufShow();

void inetstatShow(void);

#ifdef	__cplusplus
}
#endif

#endif
