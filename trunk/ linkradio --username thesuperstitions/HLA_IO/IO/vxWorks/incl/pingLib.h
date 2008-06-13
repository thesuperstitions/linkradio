/* pingLib.h - Packet InterNet Grouper (PING) library header */


/*
modification history
--------------------
01a,25oct94,dzb  written.
*/

#ifndef __INCpingLibh
#define __INCpingLibh

#ifdef __cplusplus
extern "C" {
#endif

#define	PING_OPT_SILENT		0x1	/* work silently */

STATUS	 ping (char *host, int numPackets, unsigned long options);
 
#ifdef __cplusplus
}
#endif
 
#endif /* __INCpingLibh */
