#ifndef SYS_H
#define SYS_H

#include <vxWorks.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * @limitation In this POSIX implementation, the boot line is obtained from the
 * relevant command-line arguments. For example, the "-o" argument
 * precedes the "other" string. The format of the returned "string"
 * does follow VxWorks conventions, however. Currently, only the "-o" option
 * is supported.
 */
STATUS
sysBootLineGet (
	char *string,	/* where to copy non-volatile RAM    */
	int strLen	/* maximum number of bytes to copy   */
);

#ifdef	__cplusplus
}
#endif

#endif
