///////////////////////////////////////////////////////////////////////////////
//
// thread_Mutex.cpp
//
///////////////////////////////////////////////////////////////////////////////

#include "thread_Mutex.h"

thread::Mutex::Mutex() :
    handle()
{
#ifdef _WIN32
    handle = CreateMutex(0, false, 0);
    if (handle == 0)
    {
        throw MutexException(static_cast<int>(GetLastError()));
    }
#else // POSIX
    int code = pthread_mutex_init(&handle, 0);
    if (code != 0)
    {
        throw MutexException(code);
    }
#endif
}

thread::Mutex::~Mutex()
{
#ifdef _WIN32
    CloseHandle(handle);
#else // POSIX
    pthread_mutex_destroy(&handle);
#endif
}

void thread::Mutex::lock()
{
#ifdef _WIN32
    DWORD code = WaitForSingleObject(handle, INFINITE);
    if (code != WAIT_OBJECT_0)
    {
        throw LockException(static_cast<int>(code));
    }
#else // POSIX
    int code = pthread_mutex_lock(&handle);
    if (code != 0)
    {
        throw LockException(code);
    }
#endif
}

void thread::Mutex::unlock()
{
#ifdef _WIN32
    if (ReleaseMutex(handle) == 0)
    {
        throw UnlockException(static_cast<int>(GetLastError()));
    }
#else // POSIX
    int code = pthread_mutex_unlock(&handle);
    if (code != 0)
    {
        throw UnlockException(code);
    }
#endif
}
