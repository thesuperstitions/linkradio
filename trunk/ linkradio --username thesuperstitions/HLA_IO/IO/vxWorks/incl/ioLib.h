/* ioLib.h - I/O interface library header */


/*
modification history
--------------------
05i,03dec98,lrn  add FIOTRUNC64 (SPR#23692)
05h,15oct98,lrn  added 64-bit ioctl codes for dosFsLib and rawFsLib
05g,29aug95,hdn  added S_ioLib_UNFORMATED for floppy disk driver.
05f,29dec93,jmm  added FIOTIMESET for utime() support
                 added FIOINODETONAME to translate inodes to names
		 added FIOFSTATFSGET to get information for fstatfs()
05e,02oct92,srh  added FIOGETFL ioctl code
05d,22sep92,rrr  added support for c++
05c,18sep92,smb  moved open and creat prototypes to fcntl.h.
05b,16sep92,kdl  added include of unistd.h; added L_* definitions for compat.
05a,02aug92,jcf  added creat().
04z,29jul92,smb  added include for fcntl.h. removed fopen options.
04y,22jul92,kdl	 added include of stdio.h if using delete() macro.
04x,22jul92,kdl	 removed references to delete(); added conditional macro
		 definition for delete() to use remove() instead.
04w,04jul92,jcf  cleaned up.
04v,30jun92,kdl	 added FIONCONTIG and FIOTRUNC ioctl codes; added CONTIG_MAX.
04u,26may92,rrr  the tree shuffle
04t,05dec91,rrr  moved O_ and L_ macros to their posix header files
04s,26nov91,llk  fixed delete() prototype.
04r,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed READ, WRITE and UPDATE to O_RDONLY O_WRONLY and
		   O_RDWR
		  -changed VOID to void
04q,10jun91.del  added pragma for gnu960 alignment.
04p,23oct90,shl  changed ioctl()'s last parameter type from "int" to "void *".
04o,20oct90,dnw  removed "iosLib.h" and declaration that required it.
04n,19oct90,shl  added #include "iosLib.h".
04m,05oct90,dnw  deleted private routines.
		 added chdir(), getcwd(), remove(), rename()
04l,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
04k,10aug90,dnw  added declaration of ioDefDirGet().
04j,11jul90,jcc  added FIOSCSICOMMAND.
04i,14jun90,kdl  added FIOUNMOUNT.
04h,25may90,dnw  added include of limits.h and defined MAX_FILENAME_LENGTH
		   in terms of PATH_MAX
04g,20apr90,kdl  added FIOREADDIR, FIOFSTATGET.
04f,01apr90,llk  added S_ioLib_NAME_TOO_LONG.
		 decreased MAX_DIRNAMES.
04e,17mar90,rdc  added FIOSELECT and FIOUNSELECT.
	    dab  changed O_CREAT and O_TRUNC values (from 0x80 and 0x100 to
		 001000 and 002000).  fixed spelling of S_ioLib_CANCELLED.
	    kdl  added MS-DOS functions: FIONFREE, FIOMKDIR, FIORMDIR,
		 FIOLABELGET, FIOLABELSET, FIOATTRIBSET, FIOCONTIG.
04d,27jul89,hjb  added ty protocol hook stuff: FIOPROTOHOOK,FIOPROTOARG
		   FIORBUFSET,FIOWBUFSET,FIORFLUSH,FIOWFLUSH.
04c,21apr89,dab  added FIOSYNC for sync to disk.
04b,18nov88,dnw  removed NOT_GENERIC stuff.
04a,22jun88,dnw  moved READ, WRITE, and UPDATE back to vxWorks.h.
03z,04jun88,llk  added MAX_DIRNAMES and S_ioLib_NO_DEVICE_NAME_IN_PATH for path
		   parsing.
		 added FSTAT for file types (inspired by nfs).
		 added DEFAULT_FILE_PERM and DEFAULT_DIR_PERM for newly created
		   files and directories.
03y,30apr88,gae  got read/write modes right.
03x,29mar88,gae  added FIOISATTY.  Added UNIX style open() and lseek() flags.
		 moved READ, WRITE, and UPDATE here from vxWorks.h.
03w,31dec87,jlf  added FOLLOW_LINK.
03v,01oct87,gae  added FIOGETNAME for all file descriptors.
		 added FIO[SG]ETOPTIONS for line options on devices.
03u,09sep87,dnw  added FIONBIO for sockets.
		 added FIONMSGS for pipes.
03t,09sep87,dnw  added FIOSQUEEZE and HD_1, HD_2 for rt-11 disks.
03s,09jun87,ecs  added S_ioLib_CANCELED & FIOCANCEL.
03r,14feb87,dnw  added S_ioLib_NO_FILENAME.
03q,04feb87,llk  added FIODISKCHANGE.
03p,24dec86,gae  changed stsLib.h to vwModNum.h.
03o,01dec86,dnw  increased MAX_FILENAME_LENGTH from 32 to 100.
03n,20nov86,dnw	 added S_ioLib_DISK_NOT_PRESENT.
03m,17oct86,gae	 added S_ioLib_WRITE_PROTECTED.
03l,21may86,llk	 corrected comments.
03k,23mar86,jlf  changed GENERIC to NOT_GENERIC
03j,08mar86,dnw  added S_ioLib_DEVICE_TIMEOUT.
*/

#ifndef IO_LIB_H
#define IO_LIB_H

#ifdef LINUX
#include <sys/ioctl.h>
#else
#include <sys/filio.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define FIOFLUSH        2
#define FIOOPTIONS      3
#define FIOBAUDRATE     4
#define FIOSEEK		7
#define FIOGETOPTIONS   19
#define FIORFLUSH	26
#define FIOSETOPTIONS   FIOOPTIONS
#define OPT_ECHO	0x01
#define OPT_CRMOD       0x02
#define OPT_TANDEM      0x04
#define OPT_7_BIT	0x08
#define OPT_MON_TRAP	0x10
#define OPT_ABORT	0x20
#define OPT_LINE        0x40
#define OPT_TERMINAL	(OPT_ECHO | OPT_CRMOD | OPT_TANDEM | \
			 OPT_MON_TRAP | OPT_7_BIT | OPT_ABORT | OPT_LINE)

/*
 * @limitation Not currently supported for stderr and stdout because in POSIX the file
 * descriptors are global to all threads.
 */
void
ioTaskStdSet
(
	int	taskId,	/* task whose std fd is to be set (0 = self) */
	int	stdFd,	/* std input (0), output (1), or error (2)   */
	int	newFd	/* new underlying file descriptor            */
);

#ifdef	__cplusplus
}
#endif

#endif
