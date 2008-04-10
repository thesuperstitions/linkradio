///////////////////////////////////////////////////////////////////////////////
//
// thread_Thread.cpp
//
///////////////////////////////////////////////////////////////////////////////

#include "thread_Thread.h"

#ifdef _WIN32
#include <process.h> // _beginthreadex
#else // POSIX
#include <sys/select.h> // select
#endif

thread::Thread::Thread(Runnable *runnable) :
    runnable(runnable),
    handle()
{
    // empty
}

thread::Thread::~Thread()
{
#ifdef _WIN32
    CloseHandle(handle);
#else // POSIX
    // empty
#endif
}

namespace // unnamed namespace
{
#ifdef _WIN32
    unsigned int __stdcall startThread(void *arg)
#else // POSIX
    extern "C" void *startThread(void *arg)
#endif
    {
        thread::Runnable *runnable = static_cast<thread::Runnable *>(arg);
        runnable->run();
        if (runnable->isDetached())
        {
            delete runnable;
        }
        return 0;
    }
} // unnamed namespace

void thread::Thread::start(bool detached)
{
    runnable->detached = detached;
#ifdef _WIN32
    handle = (HANDLE)_beginthreadex(0, THREAD_STACK_SIZE, startThread,
        runnable, STACK_SIZE_PARAM_IS_A_RESERVATION, 0);
    if (handle == 0)
    {
        throw StartException(errno);
    }
#else // POSIX
    int code = pthread_create(&handle, 0, startThread, runnable);
    if (code != 0)
    {
        throw StartException(code);
    }
    if (detached)
    {
        code = pthread_detach(handle);
        if (code != 0)
        {
            throw DetachException(code);
        }
    }
#endif
}

void thread::Thread::join()
{
#ifdef _WIN32
    DWORD code = WaitForSingleObject(handle, INFINITE);
    if (code != WAIT_OBJECT_0)
    {
        throw JoinException(static_cast<int>(code));
    }
#else // POSIX
    void *value;
    int code = pthread_join(handle, &value);
    if (code != 0)
    {
        throw JoinException(code);
    }
#endif
}

thread::Thread::ID thread::Thread::self()
{
#ifdef _WIN32
    return GetCurrentThreadId();
#else // POSIX
    return pthread_self();
#endif
}

bool thread::Thread::equal(ID t1, ID t2)
{
#ifdef _WIN32
    return (t1 == t2);
#else // POSIX
    return (pthread_equal(t1, t2) != 0);
#endif
}

void thread::Thread::sleep(long ms)
{
#ifdef _WIN32
    Sleep(static_cast<DWORD>(ms));
#else // POSIX
    timeval timeout;
    timeout.tv_sec = ms/1000;
    timeout.tv_usec = (ms - timeout.tv_sec*1000)*1000;
    select(0, 0, 0, 0, &timeout);
#endif
}
