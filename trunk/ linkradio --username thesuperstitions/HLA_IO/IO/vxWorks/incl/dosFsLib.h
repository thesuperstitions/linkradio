/* dosFsLib.h - DOS file system header file */


/*
modification history
--------------------
01f,31aug99,jkf  changes for new CBIO API.
01e,31jul99,jkf  T2 merge, tidiness & spelling.
01d,15oct98,lrn  moved 64-bit extended ioctl codes to ioLib.h
01c,11sep98,vld  prototype of dosFsDevCreate() to accept arbitrary
		 block device ptr.
01d,09jul98,lrn  added more defines for back compatibility
01c,30jun98,lrn  moved ERRNO_PX_FLAG to errno.h, renamed dosFsInit to
                 dosFsLibInit, added b.c., cosmetics
01b,28jun98,vld  tested and checked in
01a,22jan98,vld  written,
*/

#ifndef __INCdoFsLib
#define __INCdoFsLib

#include <blkIo.h>
#include <iosLib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DOS_OPT_AUTOSYNC        0x2     /* autoSync mode enabled */
#define DOS_OPT_LONGNAMES       0x4    
#define DOS_OPT_DEFAULT         0x0000  /* format with default options */
#define DOS_OPT_PRESERVE        0x0001  /* preserve boot block if possible */
#define DOS_OPT_BLANK           0x0002  /* create a clean boot block */
#define DOS_OPT_QUIET           0x0004  /* dont produce any output */
#define DOS_OPT_FAT16           0x0010  /* format with FAT16 file system */
#define DOS_OPT_FAT32           0x0020  /* format with FAT32 file system */
#define DOS_OPT_VXLONGNAMES     0x0100  /* format with VxLong file names */

#define DOS_LONG_NAME_LEN	40	/* length of filename w/ long option */
#define	DOS_EXT_LEN		3	/* length of filename extension */
#define DOS_LONG_RESERVED_LEN	13	/* reserved bytes in longNames dir ent*/
#define	DOS_SYS_ID_LEN		8	/* length of system ID string */
#define DOS_NAME_LEN		8	/* length of filename (no extension) */
#define	DOS_VOL_LABEL_LEN	(DOS_NAME_LEN + DOS_EXT_LEN)

typedef struct dosDirEnt	/* DOS_DIR_ENT */
    {
    int			dosde_hashNode;	        /* hash node for dir entry */
    void		*dosde_pNext;		/* ptr to next dir entry */
    void		*dosde_pParent;		/* ptr to parent dir entry */
    void		*dosde_pSubDir;		/* ptr to entry chain, if dir */
    UINT8		dosde_name [DOS_LONG_NAME_LEN]; /* filename */
    UINT8		dosde_ext [DOS_EXT_LEN];   /* filename extension */
    UINT8		dosde_attrib;		/* attribute byte */
    char		dosde_reserved[DOS_LONG_RESERVED_LEN];	/* reserved*/
    USHORT		dosde_time;		/* time */
    USHORT		dosde_date;		/* date */
    USHORT		dosde_cluster;		/* starting cluster number */
    ULONG		dosde_size;		/* file size (in bytes) */
    BOOL		dosde_modified;		/* flag set if dir changed */
    } DOS_DIR_ENT;

typedef struct		/* DOS_VOL_DESC */
    {
    DEV_HDR	dosvd_devHdr;		/* i/o system device header */
    short	dosvd_status;		/* (OK | ERROR) */
    char	dosvd_sysId [DOS_SYS_ID_LEN];	/* system ID string */
    SEM_ID	dosvd_semId;		/* volume semaphore id */

    BLK_DEV	*dosvd_pBlkDev;		/* pointer to block device info */

    char	dosvd_mediaByte;	/* media format byte */
    UINT8	dosvd_secPerClust;	/* number of sectors per cluster */
    UINT	dosvd_bytesPerClust;	/* bytes-per-cluster */

    UINT8	dosvd_nFats;		/* number of copies of FAT */
    UINT16	dosvd_secPerFat;	/* number of sectors per FAT */
    int		dosvd_nFatEnts;		/* number of entries in FAT */
    BOOL	dosvd_fat12Bit;		/* FAT uses 12 (vs. 16) bit entries */
    BOOL	dosvd_fatModified;	/* TRUE if FAT has been changed */
    UINT8	*dosvd_pFatBuf;		/* pointer to FAT buffer */
    int		dosvd_fatEntFreeCnt;	/* count of free clusters */

    USHORT	dosvd_maxRootEnts;	/* max num of root directory entries */
    ULONG	dosvd_nRootEnts;	/* current num of root dir entries */
    int		dosvd_rootSec;		/* starting sector number of root dir */
    DOS_DIR_ENT	*dosvd_pRoot;		/* pointer to root directory entry */

    USHORT	dosvd_nResrvdSecs;	/* number of reserved sectors */
    ULONG	dosvd_nHiddenSecs;	/* number of hidden sectors */
    UINT	dosvd_dataSec;		/* starting sector number of data area*/

    UINT8	dosvd_driveNum;		/* physical drive number */
    UINT8	dosvd_bootSigRec;	/* extended boot signature record */
    ULONG	dosvd_volId;		/* binary volume ID number */
    char	dosvd_volLabel [DOS_VOL_LABEL_LEN];
					/* volume label string */

    int		dosvd_state;		/* state of volume (see below) */
    int		dosvd_retry;		/* retry count of disk operations */
    UINT	dosvd_options;		/* volume options (see below) */

    UINT8	*dosvd_pFatModTbl;	/* ptr to table of mod'd FAT sectors */
    void	*dosvd_hashTbl;	        /* hash table for volume */
    int         dosvd_uid;	        /* user id to report from stat () */
    int         dosvd_gid;              /* group id to report from stat () */
    int         dosvd_mode;	        /* file mode to report from stat () */
    } DOS_VOL_DESC;

typedef struct          /* DOS_VOL_CONFIG */
    {                           /* Legend: M- modifiable, C- Calculated */
    enum
        { _AUTO=0, _FAT12=12, _FAT16=16, _FAT32=32 }
                fatType;        /* M- Fat format Type */
    const char * sysId ;        /* M- sys ID string */
    int         secPerClust;    /* M- sectors per cluster (minimum 1) */
    short       nResrvd;        /* M- number of reserved sectors (min 1) */
    short       maxRootEnts;    /* M- max number of entries in root dir */
    char        nFats;          /* M- number of FAT copies (minimum 1) */
    ULONG       secPerFat;      /* C- number of sectors per FAT copy */
    ULONG       nClust;         /* C- # of clusters on disk */
    ULONG       nHidden;        /* C- number of hidden sectors */
    ULONG       volSerial ;     /* M- disk serial number */
    int         secPerTrack;    /* M- sectors per track */
    char        nHeads;         /* M- number of heads */
    char        mediaByte;      /* M- media descriptor byte */
    char        volLabel[ 11 ]; /* X- disk volume label */
    } DOS_VOL_CONFIG;

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
STATUS 
dosFsInit (
	int maxFiles
);

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
DOS_VOL_DESC *
dosFsDevInit (
	char *devName,
	BLK_DEV *pBlkDev,
	DOS_VOL_CONFIG *pConfig
);

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
DOS_VOL_DESC *
dosFsMkfs (
	char *volName,
	BLK_DEV *pBlkDev
);

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
STATUS
dosFsVolUnmount (
	void *dev
);

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
STATUS
dosFsMkfsOptionsSet (
	UINT options
);

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
STATUS 
dosFsVolOptionsSet (
	DOS_VOL_DESC *vdptr,
	UINT options
);

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
STATUS
dosFsConfigInit (
	DOS_VOL_CONFIG	*pConfig,
	char		mediaByte,
	UINT8		secPerClust,
	short		nResrvd,
	char		nFats,
	UINT16		secPerFat,
	short		maxRootEnts,
	UINT		nHidden,
	UINT		options
);

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
STATUS
dosFsDateSet (
	int		year,
	int		month,
	int		day
);

/*
 * @limitation There isn't really a DOS file system in this POSIX
 * implementation, but this call can still be made. Instead, the
 * Unix file system is (silently) used.
 */
STATUS
dosFsTimeSet (
	int		hour,
	int		minute,
	int		second
);

#ifdef __cplusplus
    }
#endif

#endif /* __INCdoFsLib */

