///////////////////////////////////////////////////////////////////////////////
//
// thread_Condition.cpp
//
///////////////////////////////////////////////////////////////////////////////

#include "thread_Condition.h"

// Douglas C. Schmidt and Irfan Pyarali, "Strategies for Implementing POSIX
// Condition Variables on Win32."
// http://www.cs.wustl.edu/~schmidt/win32-cv-1.html

thread::Condition::Condition() :
#ifdef _WIN32
    waitersCount(0),
    waitersCountLock(),
    waitersSemaphore(),
    waitersDoneEvent(),
    wasBroadcast(false)
#else // POSIX
    handle()
#endif
{
#ifdef _WIN32
    InitializeCriticalSection(&waitersCountLock);
    waitersSemaphore = CreateSemaphore(0, 0, 0x7fffffff, 0);
    if (waitersSemaphore == 0)
    {
        int code = static_cast<int>(GetLastError());
        DeleteCriticalSection(&waitersCountLock);
        throw ConditionException(code);
    }
    waitersDoneEvent = CreateEvent(0, false, false, 0);
    if (waitersDoneEvent == 0)
    {
        int code = static_cast<int>(GetLastError());
        DeleteCriticalSection(&waitersCountLock);
        CloseHandle(waitersSemaphore);
        throw ConditionException(code);
    }
#else // POSIX
    int code = pthread_cond_init(&handle, 0);
    if (code != 0)
    {
        throw ConditionException(code);
    }
#endif
}

thread::Condition::~Condition()
{
#ifdef _WIN32
    DeleteCriticalSection(&waitersCountLock);
    CloseHandle(waitersSemaphore);
    CloseHandle(waitersDoneEvent);
#else // POSIX
    pthread_cond_destroy(&handle);
#endif
}

void thread::Condition::signal()
{
#ifdef _WIN32
    EnterCriticalSection(&waitersCountLock);
    bool haveWaiters = (waitersCount > 0);
    LeaveCriticalSection(&waitersCountLock);
    if (haveWaiters)
    {
        if (ReleaseSemaphore(waitersSemaphore, 1, 0) == 0)
        {
            throw SignalException(static_cast<int>(GetLastError()));
        }
    }
#else // POSIX
    int code = pthread_cond_signal(&handle);
    if (code != 0)
    {
        throw SignalException(code);
    }
#endif
}

void thread::Condition::broadcast()
{
#ifdef _WIN32
    EnterCriticalSection(&waitersCountLock);
    bool haveWaiters = false;
    if (waitersCount > 0)
    {
        wasBroadcast = true;
        haveWaiters = true;
    }

    // We can release the lock on the waiter count now, since only wait() can
    // modify it, and if wait() does not hold the mutex, then it is waiting on
    // the semaphore.
    LeaveCriticalSection(&waitersCountLock);
    if (haveWaiters)
    {
        if (ReleaseSemaphore(waitersSemaphore, waitersCount, 0) == 0)
        {
            throw BroadcastException(static_cast<int>(GetLastError()));
        }
        DWORD code = WaitForSingleObject(waitersDoneEvent, INFINITE);
        if (code != WAIT_OBJECT_0)
        {
            throw BroadcastException(static_cast<int>(code));
        }
        wasBroadcast = false;
    }
#else // POSIX
    int code = pthread_cond_broadcast(&handle);
    if (code != 0)
    {
        throw BroadcastException(code);
    }
#endif
}

void thread::Condition::wait(Mutex& mutex)
{
#ifdef _WIN32
    EnterCriticalSection(&waitersCountLock);
    ++waitersCount;
    LeaveCriticalSection(&waitersCountLock);
    DWORD code = SignalObjectAndWait(
        mutex.handle, waitersSemaphore, INFINITE, false);
    if (code != WAIT_OBJECT_0)
    {
        throw WaitException(code);
    }
    EnterCriticalSection(&waitersCountLock);
    --waitersCount;
    bool lastWaiter = wasBroadcast && (waitersCount == 0);
    LeaveCriticalSection(&waitersCountLock);
    if (lastWaiter)
    {
        code = SignalObjectAndWait(
            waitersDoneEvent, mutex.handle, INFINITE, false);
    }
    else
    {
        code = WaitForSingleObject(mutex.handle, INFINITE);
    }
    if (code != WAIT_OBJECT_0)
    {
        throw WaitException(static_cast<int>(code));
    }
#else // POSIX
    int code = pthread_cond_wait(&handle, &mutex.handle);
    if (code != 0)
    {
        throw WaitException(code);
    }
#endif
}
