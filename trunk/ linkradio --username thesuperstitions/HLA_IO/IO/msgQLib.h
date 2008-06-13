/* msgQLib.h - message queue library header file */


/*
modification history
--------------------
02l,17apr98,rlp  canceled MSG_Q_INFO modification for backward compatibility.
02k,04nov97,rlp  modified MSG_Q_INFO structure for tracking messages sent.
02j,13jul93,wmd  use MEM_ROUND_UP to determine MSG_NODE_SIZE.
02i,22sep92,rrr  added support for c++
02h,04jul92,jcf  cleaned up.
01g,26may92,rrr  the tree shuffle
01f,04oct91,rrr  passed through the ansification filter
01e,05oct90,dnw  changed MSG_Q_INFO structure.
01d,05oct90,dnw  changed function declarations for new interface.
01c,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01b,07aug90,shl  moved function declarations to end of file.
01a,10may90,dnw  written
*/

#ifndef MSGQ_LIB_H
#define MSGQ_LIB_H

#include <vxWorks.h>
#include <pthread.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define M_msgQLib	(65 << 16)

#define S_msgQLib_INVALID_MSG_LENGTH	(M_msgQLib | 1)

typedef void *MSG_Q_ID;

#ifndef IPC_NOWAIT
#define IPC_NOWAIT 0004000
#endif

/* message queue options */

#define MSG_Q_TYPE_MASK 0x01    /* mask for pend queue type in options */
#define MSG_Q_FIFO      0x00    /* tasks wait in FIFO order */
#define MSG_Q_PRIORITY  0x01    /* tasks wait in PRIORITY order */

/* message send priorities */

#define MSG_PRI_NORMAL  0       /* normal priority message */
#define MSG_PRI_URGENT  1       /* urgent priority message */

typedef struct                  /* MSG_Q_INFO */
{
    int     numMsgs;            /* OUT: number of messages queued */
    int     numTasks;           /* OUT: number of tasks waiting on msg q */

    int     sendTimeouts;       /* OUT: count of send timeouts */
    int     recvTimeouts;       /* OUT: count of receive timeouts */

    int     options;            /* OUT: options with which msg q was created */
    int     maxMsgs;            /* OUT: max messages that can be queued */
    int     maxMsgLength;       /* OUT: max byte length of each message */

    int     taskIdListMax;      /* IN: max tasks to fill in taskIdList */
    int *   taskIdList;         /* PTR: array of task ids waiting on msg q */

    int     msgListMax;         /* IN: max msgs to fill in msg lists */
    char ** msgPtrList;         /* PTR: array of msg ptrs queued to msg q */
    int *   msgLenList;         /* PTR: array of lengths of msgs */
    
    unsigned int overflows;	/* OUT: count of sends to full queue */
    unsigned int hiwat;		/* OUT: largest number of msgs ever in queue */

} MSG_Q_INFO;


/*
 * @limitation In this POSIX implementation, the <i>options</i>
 * argument is ignored, as message queueing/dequeueing is always
 * performed in priority order.
 */
MSG_Q_ID
msgQCreate (
	int maxMsgs,
	int maxMsgLength,
	int options
);

STATUS
msgQDelete (
	MSG_Q_ID msgQId
);

/*
 * @limitation When timeout is specified as NO_WAIT, the POSIX implementation
 * temporarily changes the queue's attributes to nonblocking (as is also the
 * case for msgQReceive). To avoid a potential conflict with the receiver, one
 * should not use NO_WAIT for msgQSend, but only for msgQReceive.
 */
STATUS
msgQSend (
	MSG_Q_ID msgQId,
	char *buffer,
	UINT nBytes,
	int timeout,
	int priority
);

int
msgQReceive (
	MSG_Q_ID msgQId,
	char *buffer,
	UINT maxNBytes,
	int timeout
);

/*
 * @limitation Only the numMsgs, maxMsgs and maxMsgLength fields are filled
 * in with useful information in the structure pointed to by pInfo. The
 * options field is always set to MSG_Q_PRIORITY (see msgQCreate);
 */
STATUS  
msgQInfoGet (
	MSG_Q_ID msgQId,
	MSG_Q_INFO *pInfo
);

int
msgQNumMsgs (
	MSG_Q_ID msgQId
);

void	
msgQShowInit (
	void
);

STATUS
msgQShow (
	MSG_Q_ID	msgQid,
	int		level
);

#ifdef	__cplusplus
}
#endif

#endif
