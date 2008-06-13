#ifndef softwareClock_H
#define softwareClock_H

//------------------------------------------------------------------------------
// Standard Includes 
//------------------------------------------------------------------------------
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>	//! <! This may not be a standard include !>

//------------------------------------------------------------------------------
// SoftwareClock Includes 
//------------------------------------------------------------------------------
#include <softwareClockHelper.h>


#define TimeUndeterminedMode		0
#define TimeWaitForeverMode			10
#define TimeStepMode				20
#define TimeSensitiveMode			30
#define TimeInsensitiveMode			40




#ifdef	__cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------
typedef struct
{
	// Task time relevant info
	int taskID;
	int waitClock;
	int exeMode;	
	
	// Members that tell wheather we timed out
	bool aExitNow;
	pthread_mutex_t aExitNowLock;
	
	// A spare set of signals with mutex that apps can use
	pthread_cond_t aSpareSignal;
	pthread_mutex_t aSpareSignalMutex;
	
	// Members to wake the task up (Provided by legacy apps)
	pthread_cond_t *aSignal;
	pthread_mutex_t *aSignalMutex;
	
	// Members for debugging
	int redundantTimer;

} TaskInfo;


//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------
class SoftwareClock
{
  private:

  	list <TaskInfo*> myTaskList;
	pthread_t mainThread;				// Id of recv thread	
	pthread_t debugThread;				// Id of debug thread 
	int savedServerPort;				// Port of the server
	char savedServerAddr[256];			// Address of the server
  	int mySocket;						// My connection socket
	int debugSocket;					// Socket used for remote debugging
	int myClockSocketId;				// Server knows me by this socket index
	pthread_mutex_t myResourceLock;		// Lock for shared resources
	pthread_mutex_t myAbsTimeLock;		// Lock for abstime resource; and signal	
	pthread_mutex_t myWorkLock;			// Lock for MainThread work/control signal
	pthread_mutexattr_t myResourceLockAttr;  // Atributes of the locks
	pthread_cond_t myAbsTimeInitSignal;	// Signal of initialzation of time
	pthread_cond_t myWorkSignal;		// Signal for MainThread to go to work
	bool isAbsTimeInit;			// Has the absolute time been initialized
	unsigned long  msTotalTime;	// Time since computer started in milliseconds
	int currSyncId;				// Current Syncyronization number
	bool debugMode;				// Switch for debug info
	
	// Helper methods
	void DebugPrint(int debugType);
	int UpdateClock(int deltaTime);
	
	// Methods to manage this software clock list of tasks
	TaskInfo* FindTask(int aTaskId);
	TaskInfo* EnforceRegistration(int aTaskId);	
	int AddTask(int aTaskId, int isTimeSensitive);
	int RemoveTask(int aTaskId);
	
	// Methods to help plan for time advances
	int	GetSmallestDelay(bool resolveUndeterminates);
	int TryTimeAdvance(int aTimeAmount);

	// Method to recieve/procces messages from the TimeServer
	int ProcessServerData(int *aTimeGrant);
	

  public:

	// Creation and connection methods
  		SoftwareClock();
		~SoftwareClock();
	int ConnectTo(char *addr, int aPort);
	int Disconnect(void);
	
	// Methods to notify the software clock of system changes
	void TrashTask(int aTaskId);

	// Methods tasks use to get abs time and delta time
	unsigned long GetAbsTimeMs(void);
	unsigned long RetrieveDeltaTimeMs(unsigned long *oldTimeMs);

	// Methods to check for timing out and getting spare signals 
	void GetSpareSignal(pthread_cond_t **aSignal, pthread_mutex_t **aSignalMutex);
	bool IsTaskTimedOut(int aTaskId);

	// Methods to control a tasks execution mode. Note, for time to move forward a
	// task has to be in TimeWaitForeverMode, TimeStepMode, TimeInSensitiveMode, 
	// or TimeSensitiveMode with a waitClock > 0
	// Also the mutex passed in should be locked when RequestTimeAdvance() or WaitForMaxTimeStep()
	int DisableTimeSensitivity(int aTaskId);
	int SetWaitForeverMode(int aTaskId);
	int SetUndeterminedMode(int aTaskId);
	int ResetTimeSensitivity(int aTaskId);

	// Methods to manage and control waking up; Note aLock should be locked
	// when RequestTimeAdvance or WaitForMaxTimeStep is called
	int RequestTimeAdvance(int aTaskId, int deltaTime, pthread_cond_t *aSignal,
		pthread_mutex_t *aLock);
	int WaitForMaxTimeStep(int aTaskId, int aNumMs, pthread_cond_t *aSignal,
		pthread_mutex_t *aSignalMutex);
	
	// Tight Loop checker method	
	void PerformRedundantCheck(int aTaskId);


	// Hacker method to force a task settings
	int ForceTaskSetting (int aTaskId, int *aExeMode, int *waitClock,
		pthread_cond_t **aSignal, pthread_mutex_t **aSignalMutex,
		int *redundantTimer, bool *aExitNow);


	// The lifeline of this clock
	// Even though the below are public methods, it should never be called.
	// If you do MainThread() and DebugThread() will never return.
	// MainThread and DebugThread must be declared as public in order for 
	// them to be spawned.
	int MainThread(void);
	int DebugThread(void);
};


#ifdef	__cplusplus
}
#endif

#endif
