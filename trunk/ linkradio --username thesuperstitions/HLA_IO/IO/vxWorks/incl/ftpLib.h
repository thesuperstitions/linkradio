/* ftpLib.h - arpa File Transfer Protocol library header */


/*
modification history
--------------------
01j,22sep92,rrr  added support for c++
01i,11sep92,jmm  added external definition for ftpErrorSupress (for spr #1257)
01h,04jul92,jcf  cleaned up.
01g,26may92,rrr  the tree shuffle
01f,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
01e,19oct90,shl  changed ftpCommand() to use variable length argument list.
01d,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01c,07aug90,shl  added INCftpLibh to #endif.
01b,20mar87,dnw  prepended FTP_ to reply codes.
01a,07nov86,dnw  written
*/

#ifndef __INCftpLibh
#define __INCftpLibh

#ifdef __cplusplus
extern "C" {
#endif

#define FTP_COMPLETE	2	/* positive completion */

/*
 * @limitation Not currently implemented.
 */
STATUS 
ftpLogin (
	int ctrlSock,
	char *user,
	char *passwd,
	char *account
);

/*
 * @limitation Not currently implemented.
 */
STATUS 
ftpXfer (
	char *host,
	char *user,
	char *passwd,
	char *acct,
	char *cmd,
	char *dirname,
	char *filename,
	int *pCtrlSock,
	int *pDataSock
);

/*
 * @limitation Not currently implemented.
 */
int 
ftpCommand (
	int ctrlSock,
	char *fmt,
	int arg1,
	int arg2,
	int arg3,
	int arg4,
	int arg5,
	int arg6
);

/*
 * @limitation Not currently implemented.
 */
int 
ftpDataConnGet (
	int dataSock
);

/*
 * @limitation Not currently implemented.
 */
int
ftpDataConnInit (
	int ctrlSock
);

/*
 * @limitation Not currently implemented.
 */
int 
ftpHookup (
	char *host
);

/*
 * @limitation Not currently implemented.
 */
int 
ftpReplyGet (
	int ctrlSock,
	BOOL expecteof
);

#ifdef __cplusplus
}
#endif

#endif /* __INCftpLibh */
