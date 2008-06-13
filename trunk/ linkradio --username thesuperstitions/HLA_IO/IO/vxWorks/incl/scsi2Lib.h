/* scsiLib.h - SCSI library header file */


/*
modification history
--------------------
04m,10jul97,dds  added new fields to SCSI_CTRL structure.
04l,28mar97,dds  SPR 8220: added new event type SCSI_EVENT_PARITY_ERR.
04k,06mar97,dds  SPR 8120: changed declaration for scsiRdTape.
04j,13sep96,dds  added declarations required by scsiMgrLib.c and scsiCtrlLib.c
04i,29jul96,jds  added hardware cache snooping support
04h,15apr96,jds  added WIDE data transfer support
04g,20jul95,jds  added scsiSeqStatusCheck as a global function
04f,24jul95,jds  added some additional sense key macros; added pointer to
		 SEQ_DEV in SCSI_PHYS_DEV
04e,28apr95,jds  integrated into WRS tree; added backward compatability 
04d,24mar95,ihw  added "identMsg" field in SCSI_EVENT structure
04c,07oct94,ihw  added errno's for reaching max threads, bad sense data
04b,27may94,ihw  documented prior to release
04a,30mar94,ihw  modified for enhanced SCSI library: tagged command queueing
                 removed redundant "pAddLengthByte" field from SCSI_PHYS_DEV
		 added definitions for proper handling of max length ext msgs
03a,12jan94,ihw  modified for enhanced SCSI library: multiple initiators,
    	    	    disconnect/reconnect and synchronous transfer supported
02j,11jan93,ccc  added #ifndef _ASMLANGUAGE.
02i,30sep92,ccc  added two new errno's.
02h,24sep92,ccc  removed timeout parameter to scsiAutoConfig().
02g,22sep92,rrr  added support for c++
02f,27aug92,ccc  added timeout to SCSI_TRANSACTION structure.
02e,26jul92,rrr  Removed decl of scsiSyncTarget, it was made LOCAL.
02d,20jul92,eve  Remove conditional compilation.
02c,14jul92,eve  added a pScsiXaction info in SCSI_PHYS_DEV structure to
		 maintain the data direction information to support
		 cache coherency in drivers.
02b,06jul92,eve  added declaration for extended sync functionalities.
02a,04jul92,jcf  cleaned up.
01l,26may92,rrr  the tree shuffle
01k,07apr92,yao  changed BYTE_ORDER to _BYTE_ORDER, BIG_ENDIAN to _BIG_ENDIAN.
01j,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed READ, WRITE and UPDATE to O_RDONLY O_WRONLY O_RDWR
		  -changed VOID to void
01i,07mar91,jcc  added SCSI_BLK_DEV_LIST and SCSI_BLK_DEV_NODE definitions;
    	    	 added SCSI_SWAB macro. added a few error codes.
01h,05oct90,shl  added ANSI function prototypes.
01g,02oct90,jcc  changed SEM_ID's to SEMAPHORE's in SCSI_PHYS_DEV and SCSI_CTRL
		 structures; modified structures to return variable length
		 REQUEST SENSE data; miscellaneous.
01f,20aug90,jcc  added conditional defines and typedefs for 4.0.2 compatibility.
01e,10aug90,dnw  changed scsiBusReset and scsiSelTimeOutCvt to VOIDFUNCPTR.
01d,07aug90,shl  moved function declarations to end of file.
01c,12jul90,jcc  misc. enhancements and changes.
01b,08jun90,jcc  added scsiMsgInAck to SCSI_CTRL, which routine is invoked
		 to accept incoming messages.
01a,17apr89,jcc  written.
*/

#ifndef SCSI2_LIB_H
#define SCSI2_LIB_H

#include <vxWorks.h>
#include <lstLib.h>
#include <semLib.h>
#include <blkIo.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define SPACE_CODE_DATABLK		0x00   	/* space data blocks  */
#define SPACE_CODE_FILEMARK		0x01   	/* space file-marks   */

#define S_scsiLib_DEV_NOT_READY         (M_scsiLib | 1)
#define S_scsiLib_WRITE_PROTECTED       (M_scsiLib | 2)
#define S_scsiLib_MEDIUM_ERROR          (M_scsiLib | 3)
#define S_scsiLib_HARDWARE_ERROR        (M_scsiLib | 4)
#define S_scsiLib_ILLEGAL_REQUEST       (M_scsiLib | 5)
#define S_scsiLib_BLANK_CHECK           (M_scsiLib | 6)
#define S_scsiLib_ABORTED_COMMAND       (M_scsiLib | 7)
#define S_scsiLib_VOLUME_OVERFLOW       (M_scsiLib | 8)
#define S_scsiLib_UNIT_ATTENTION        (M_scsiLib | 9)
#define S_scsiLib_SELECT_TIMEOUT        (M_scsiLib | 10)
#define S_scsiLib_LUN_NOT_PRESENT       (M_scsiLib | 11)
#define S_scsiLib_ILLEGAL_BUS_ID        (M_scsiLib | 12)
#define S_scsiLib_NO_CONTROLLER         (M_scsiLib | 13)
#define S_scsiLib_REQ_SENSE_ERROR       (M_scsiLib | 14)
#define S_scsiLib_DEV_UNSUPPORTED       (M_scsiLib | 15)
#define S_scsiLib_ILLEGAL_PARAMETER     (M_scsiLib | 16)
#define S_scsiLib_INVALID_PHASE         (M_scsiLib | 17)
#define S_scsiLib_ABORTED               (M_scsiLib | 18)
#define S_scsiLib_ILLEGAL_OPERATION     (M_scsiLib | 19)
#define S_scsiLib_DEVICE_EXIST          (M_scsiLib | 20)
#define S_scsiLib_DISCONNECTED          (M_scsiLib | 21)
#define S_scsiLib_BUS_RESET             (M_scsiLib | 22)
#define S_scsiLib_INVALID_TAG_TYPE      (M_scsiLib | 23)
#define S_scsiLib_SOFTWARE_ERROR        (M_scsiLib | 24)
#define S_scsiLib_NO_MORE_THREADS       (M_scsiLib | 25)
#define S_scsiLib_UNKNOWN_SENSE_DATA    (M_scsiLib | 26)
#define S_scsiLib_INVALID_BLOCK_SIZE    (M_scsiLib | 27)

#define SCSI_INQUIRY_VENDOR_ID_LENGTH       8
#define SCSI_INQUIRY_PRODUCT_ID_LENGTH      16
#define SCSI_INQUIRY_REV_LEVEL_LENGTH       4

#define SCSI_SENSE_KEY_NO_SENSE         0x00  /* no sense sense key */
#define SCSI_SENSE_KEY_RECOVERED_ERROR  0x01  /* recovered error sense key */
#define SCSI_SENSE_KEY_NOT_READY        0x02  /* not ready sense key */
#define SCSI_SENSE_KEY_MEDIUM_ERROR     0x03  /* medium error sense key */
#define SCSI_SENSE_KEY_HARDWARE_ERROR   0x04  /* hardware error sense key */
#define SCSI_SENSE_KEY_ILLEGAL_REQUEST  0x05  /* illegal request sense key */
#define SCSI_SENSE_KEY_UNIT_ATTENTION   0x06  /* unit attention sense key */
#define SCSI_SENSE_KEY_DATA_PROTECT     0x07  /* data protect sense key */
#define SCSI_SENSE_KEY_BLANK_CHECK      0x08  /* blank check sense key */
#define SCSI_SENSE_KEY_VENDOR_UNIQUE    0x09  /* vendor unique sense key */
#define SCSI_SENSE_KEY_COPY_ABORTED     0x0a  /* copy aborted sense key */
#define SCSI_SENSE_KEY_ABORTED_COMMAND  0x0b  /* aborted command sense key */
#define SCSI_SENSE_KEY_EQUAL            0x0c  /* key equal sense key */
#define SCSI_SENSE_KEY_VOLUME_OVERFLOW  0x0d  /* volume overflow sense key */
#define SCSI_SENSE_KEY_MISCOMPARE       0x0e  /* miscompare sense key */
#define SCSI_SENSE_KEY_RESERVED         0x0f  /* reserved sense key */

typedef enum                    /* SCSI_TAG_TYPE */
{
    SCSI_TAG_DEFAULT  = -1,     /* use default for device                */
    SCSI_TAG_UNTAGGED = 0,      /* untagged command                      */
    SCSI_TAG_SENSE_RECOVERY,    /* untagged, even if tagged cmds present */
    SCSI_TAG_SIMPLE,            /* tagged with simple  queue tag         */
    SCSI_TAG_ORDERED,           /* tagged with ordered queue tag         */
    SCSI_TAG_HEAD_OF_Q          /* tagged with head-of-queue tag         */
} SCSI_TAG_TYPE;

typedef enum                            /* Synchronous transfer state  */
    {
    SYNC_XFER_NOT_NEGOTIATED = 0,       /* no negotiation ever started */
    SYNC_XFER_REQUEST_PENDING,          /* attempting to send request  */
    SYNC_XFER_REQUEST_SENT,             /* waiting for target's reply  */
    SYNC_XFER_REPLY_PENDING,            /* attempting to send reply    */
    SYNC_XFER_NEGOTIATION_COMPLETE      /* all done (at least once)    */
    } SCSI_SYNC_XFER_STATE;

typedef enum                            /* Wide data transfer state        */
    {
    WIDE_XFER_NOT_NEGOTIATED = 0,       /* no negotiation ever stared      */
    WIDE_XFER_REQUEST_PENDING,          /* attempting to send wide request */
    WIDE_XFER_REQUEST_SENT,             /* waiting for target's reply      */
    WIDE_XFER_REPLY_PENDING,            /* attempting to send reply        */
    WIDE_XFER_NEGOTIATION_COMPLETE      /* negotiations done (min. once)   */
    } SCSI_WIDE_XFER_STATE;

typedef enum                    /* SCSI nexus type enumeration */
    {
    SCSI_NEXUS_NONE = 0,        /* no         nexus */
    SCSI_NEXUS_IT,              /* an I-T     nexus */
    SCSI_NEXUS_ITL,             /* an I-T-L   nexus */
    SCSI_NEXUS_ITLQ             /* an I-T-L-Q nexus */
    } SCSI_NEXUS_TYPE;

typedef struct                  /* SCSI_TARGET - SCSI target information   */
{
    int           scsiDevBusId; /* device's address on SCSI bus            */
    UINT          selTimeOut;   /* device select time-out (us)             */
    BOOL          messages;     /* FALSE => do not use SCSI messages       */
    BOOL          disconnect;   /* FALSE => do not use disconnect          */
    SCSI_TAG_TYPE tagType;      /* default tag type (cmds may override)    */
    UINT          maxTags;      /* max cmd tags available (0 => untagged)  */
    UINT8         maxOffset;    /* maximum sync xfer offset (0 => async.)  */
    UINT8         minPeriod;    /* minimum sync xfer period (x 4 ns)       */
    UINT8         xferOffset;   /* current sync xfer offset (0 => async.)  */
    UINT8         xferPeriod;   /* current sync xfer period (x 4 ns)       */
    UINT8         xferWidth;    /* width in bits of the wide transfer      */
    UINT8         syncSupport;  /* supports synchronous transfers          */
    UINT8         wideSupport;  /* supports synchronous transfers          */
    SCSI_SYNC_XFER_STATE syncXferState; /* state of sync xfer negotiation  */
    SCSI_WIDE_XFER_STATE wideXferState; /* state of wide xfer negotiation  */
} SCSI_TARGET;

typedef UINT SCSI_TAG;          /* has the values [0..255] or SCSI_TAG_NONE */

typedef struct scsiTagInfo
    {
    UINT8 inUse; 	    	/* actually a BOOL (but want to save space) */
    } SCSI_TAG_INFO;

typedef struct                  /* SCSI_PHYS_DEV - SCSI physical device info */
{
    SEM_ID       mutexSem;      /* semaphore for access to blk dev list      */
    struct scsiCtrl *pScsiCtrl; /* ptr to dev's SCSI controller info         */
    SCSI_TARGET *pScsiTarget;   /* ptr to data for corresponding SCSI target */
    int          scsiDevLUN;    /* device's logical unit number              */
    UINT8        scsiDevType;   /* SCSI device type                          */
    BOOL         resetFlag;     /* set TRUE when dev reset sensed            */

                                /* product info from INQUIRY command         */
    char devVendorID  [SCSI_INQUIRY_VENDOR_ID_LENGTH  + 1];
    char devProductID [SCSI_INQUIRY_PRODUCT_ID_LENGTH + 1];
    char devRevLevel  [SCSI_INQUIRY_REV_LEVEL_LENGTH  + 1];

    BOOL  removable;            /* whether medium is removable               */
    SCSI_TAG_TYPE tagType;      /* default tag type: cmds may over-ride      */
    UINT  nTags;                /* total number of tags for device           */
    UINT8 lastSenseKey;         /* last sense key returned by dev            */
    UINT8 lastAddSenseCode;     /* last additional sense code returned       */
    int   controlByte;          /* vendor unique control byte for commands   */
    int   numBlocks;            /* number of blocks on the physical device   */
    int   blockSize;            /* size of an SCSI disk sector               */
    int   maxVarBlockLimit;     /* maximum size of a variable block: seq dev */
    BOOL  extendedSense;        /* whether device returns extended sense     */
    UINT8 *pReqSenseData;       /* ptr to last REQ SENSE data returned       */
    int   reqSenseDataLength;   /* size of REQ SENSE data array              */
    LIST  blkDevList;           /* list of block devs created on device      */
    struct scsiSeqDev *pScsiSeqDev;/* ptr to SCSI seq dev; one per phys dev  */

    SCSI_NEXUS_TYPE nexus;      /* type of current nexuses in progress       */
    UINT nTaggedNexus;          /* number of tagged nexuses in progress      */
    BOOL connected;             /* currently connected to SCSI bus ?         */
    BOOL pendingCA;             /* contingent allegiance condition pending ? */
    SCSI_NEXUS_TYPE savedNexus; /* type of nexus prior to CA recovery        */
    LIST waitingThreads;        /* list of threads waiting for device        */
    LIST activeThreads;         /* list of threads active on device          */
    SCSI_TAG curTag;            /* currently-connected tag (or NONE)         */
    SCSI_TAG nextTag;           /* next free tag number (if any)             */
    UINT nFreeTags;             /* number of free tags (if tags supported)   */
    SCSI_TAG_INFO   untagged;   /* "tag" info for a single untagged thread   */
    SCSI_TAG_INFO * pTagInfo;   /* ptr to tag info table for tagged threads  */
} SCSI_PHYS_DEV;

typedef struct          /* SEQ_DEV */
{
	FUNCPTR             sd_seqRd;               /* function to read blocks   */
	FUNCPTR             sd_seqWrt;              /* function to write blocks  */
	FUNCPTR             sd_ioctl;               /* function to ioctl device  */
	FUNCPTR             sd_seqWrtFileMarks;     /* function to write f-marks */
	FUNCPTR             sd_rewind;              /* function to rewind device */
	FUNCPTR             sd_reserve;             /* function to reserve dev   */
	FUNCPTR             sd_release;             /* function to release dev   */
	FUNCPTR             sd_readBlkLim;          /* function to read blk lims */
	FUNCPTR             sd_load;                /* function to load device   */
	FUNCPTR             sd_space;               /* function to space device  */
	FUNCPTR             sd_erase;               /* function to erase device  */
	FUNCPTR             sd_reset;               /* function to reset device  */
	FUNCPTR             sd_statusChk;           /* function to check status  */
	int                 sd_blkSize;             /* block size for device     */
	int                 sd_mode;                /* O_RDONLY or O_WRONLY      */
	BOOL                sd_readyChanged;        /* indicates medium change   */
	int                 sd_maxVarBlockLimit;    /* maximum variable blk size */
	int                 sd_density;             /* density of seq device     */
} SEQ_DEV;

typedef struct scsiSeqDev       /* SCSI_SEQ_DEV - SCSI logical sequential device info */
{
	SEQ_DEV seqDev;			/*  generic logical sequential device info */
	SCSI_PHYS_DEV *pScsiPhysDev;	/* ptr to SCSI physical device info */
} SCSI_SEQ_DEV;

typedef void SCSI_CTRL;

/*
 *  Data structure and constants for "scsiTargetOptionsSet()"
 */
#define	SCSI_SET_OPT_ALL_TARGETS    ((UINT) -1)

#define SCSI_SET_OPT_BITMASK	    0x003f  /* mask for valid option bits   */
#define	SCSI_SET_OPT_TIMEOUT	    0x0001  /* bit values to select options */
#define	SCSI_SET_OPT_MESSAGES	    0x0002
#define	SCSI_SET_OPT_DISCONNECT	    0x0004
#define	SCSI_SET_OPT_XFER_PARAMS    0x0008
#define	SCSI_SET_OPT_TAG_PARAMS	    0x0010
#define	SCSI_SET_OPT_WIDE_PARAMS    0x0020

typedef struct	    	    	/* SCSI_OPTIONS - programmable options */
    {
    UINT          selTimeOut;	/* device select time-out (us)             */
    BOOL          messages; 	/* FALSE => do not use SCSI messages       */
    BOOL          disconnect;	/* FALSE => do not use disconnect          */
    UINT8         maxOffset;	/* max sync xfer offset (0 => async.)      */
    UINT8         minPeriod;	/* min sync xfer period (x 4 ns)           */
    SCSI_TAG_TYPE tagType;  	/* default tag type (see SCSI_TRANSACTION) */
    UINT          maxTags;  	/* max cmd tags available (0 => untagged)  */
    UINT8    	  xferWidth;	/* wide data transfer width in SCSI units  */
    } SCSI_OPTIONS;

extern int scsiDebug;
extern int scsiIntsDebug;

void
scsi2IfInit (
	void
);

/*
 * @limitation When running on a POSIX workstation, direct control
 * of a SCSI disk is not permitted. Therefore, this function always
 * returns ERROR.
 */
STATUS
scsiInquiry (
	SCSI_PHYS_DEV *pScsiPhysDev,
	char *buffer,
	int bufLength
);

STATUS
scsiLoadUnit (
	SCSI_SEQ_DEV *pScsiSeqDev,
	BOOL load,
	BOOL reten,
	BOOL eot
);

STATUS
scsiModeSelect (
	SCSI_PHYS_DEV *pScsiPhysDev,
	int pageFormat,
	int saveParams,
	char *buffer,
	int bufLength
);

/*
 * @limitation When running on a POSIX workstation, direct control
 * of a SCSI disk is not permitted. This function attempts to open
 * the default tape device (/dev/mt/0) instead.
 */
SCSI_PHYS_DEV *
scsiPhysDevCreate (
	SCSI_CTRL *pScsiCtrl,
	int devBusId,
	int devLUN,
	int reqSenseLength,
	int devType,
	BOOL removable,
	int numBlocks,
	int blockSize
);

/*
 * @limitation When running on a POSIX workstation, direct control
 * of a SCSI disk is not permitted. This function attempts to close
 * the tape driver previously opened with scsiPhysDevCreate.
 */
STATUS
scsiPhysDevDelete (
	SCSI_PHYS_DEV *pScsiPhysDev
);

/*
 * @limitation The only supported <i>spaceCode</i>, SPACE_CODE_DATABLK,
 * attempts to seek <i>count</i> data blocks from the current tape location.
 */
STATUS
scsiSpace (
	SCSI_SEQ_DEV *pScsiSeqDev,
	int count,
	int spaceCode
);

int
scsiRdTape (
	SCSI_SEQ_DEV *pScsiSeqDev,
	UINT numBytes, 
	char *buffer,
	BOOL fixedSize
);

/*
 * @limitation When running on a POSIX workstation, direct control
 * of a SCSI disk is not permitted. Therefore, this function always
 * returns ERROR.
 */
STATUS
scsiReqSense (
	SCSI_PHYS_DEV *pScsiPhysDev,
	char *buffer,
	int bufLength
);

STATUS
scsiRewind (
	SCSI_SEQ_DEV *pScsiSeqDev
);

SEQ_DEV *
scsiSeqDevCreate (
	SCSI_PHYS_DEV *pScsiPhysDev
);

/*
 * @limitation When running on a POSIX workstation, direct control
 * of a SCSI disk is not permitted. This routine always returns OK.
 */
STATUS
scsiTestUnitRdy (
	SCSI_PHYS_DEV *pScsiPhysDev
);

/*
 * @limitation When running on a POSIX workstation, direct control
 * of a SCSI disk is not permitted. Therefore, this function always
 * returns ERROR.
 */
STATUS
scsiWrtFileMarks (
	SCSI_SEQ_DEV *pScsiSeqDev,
	int numMarks, 
	BOOL shortMark
);

STATUS
scsiWrtTape (
	SCSI_SEQ_DEV *pScsiSeqDev,
	int numBytes, 
	char *buffer,
	BOOL fixedSize
);

/*
 * @limitation Always returns OK, even though it doesn't really do anything.
 */
STATUS  
scsiTargetOptionsSet (
	SCSI_CTRL *pScsiCtrl,
	int devBusId,
	SCSI_OPTIONS *pOptions,
	UINT which
);

/*
 * @limitation Always returns ERROR, and prints message.
 */
STATUS
scsiTargetOptionsGet (
	SCSI_CTRL *pScsiCtrl,
	int devBusId,
	SCSI_OPTIONS *pOptions
);

/*
 * @limitation When running on a POSIX workstation, the Unix file system
 * is used; nevertheless, this function behaves like it's really creating
 * a SCSI block device.
 */
BLK_DEV *
scsiBlkDevCreate (
	SCSI_PHYS_DEV *pScsiPhysDev,
	int numBlocks,
	int blockOffset
);

#ifdef  __cplusplus
}
#endif

#endif
