#ifndef softwareClockHelper_H
#define softwareClockHelper_H

//------------------------------------------------------------------------------
// Standard Includes 
//------------------------------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <time.h>


#ifdef	__cplusplus
extern "C" {
#endif



//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------
#define DEFAULT_SC_SERVER_PORT		9009
#define ERROR_STILLWAITING			-2

#ifndef STATUS
#define STATUS int
#endif
#ifndef OK
#define OK	 						0
#endif
#ifndef ERROR
#define ERROR 						-1
#endif

#define SC_TIMEINIT_MSG				110
#define SC_TIMEREQUEST_MSG			120
#define SC_TIMEGRANT_MSG			130
#define SC_GOODBYE_MSG				140
#define SC_HARDWARESIMU_MSG			150
#define SC_DEBUGSOCKET_MSG			160

#define SC_DebugTaskState_MSG		210
#define SC_DebugMutexState_MSG		215
#define SC_DebugDisableTask_MSG		220



//------------------------------------------------------------------------------
// Message Structures 
//------------------------------------------------------------------------------
typedef struct 
{
	int msgType;			// The message type
	int msgSize;			// Size of payload to come
	int syncId;				// Unique synchronization ID	
} SoftwareClock_MSG;

typedef struct 
{
	int absTimeMS;			// Time since CPU started in millisec (from Server)
	int refSocketId;		// Refrence socket index associated with client
} TimeInit_Payload;

typedef struct 
{
	int timeGranted;		// Time that was granted
} TimeGrant_Payload;

typedef struct 
{
	int amount;				// Amount of time requested
} TimeRequest_Payload;

typedef struct 
{
	int ownerClockSocket;	// ClockSocket that owns the sender-socket of this meesage
} DebugSocket_Payload;

typedef struct 
{
	int taskId;				// Id of a task
} TaskId_Payload;


STATUS ReadTCPData(int aSocket, char *data, int numBytes, int parms);
STATUS ReadTCPGarbage(int aSocket, int numBytes, int parms);
int SC_HardwareDelayMs (int numMs);


#ifdef	__cplusplus
}
#endif

#endif
