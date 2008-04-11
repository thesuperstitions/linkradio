///////////////////////////////////////////////////////////////////////////////
//
// thread_Condition.h
//
///////////////////////////////////////////////////////////////////////////////

#ifndef THREAD_CONDITION_H
#define THREAD_CONDITION_H

#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400 // SignalObjectAndWait
#endif // _WIN32_WINNT
#include <windows.h>
#else // POSIX
#include <pthread.h>
#endif

#include "thread_Mutex.h"
#include "error_Exception.h"

namespace thread
{
    // A Condition variable is an object used by threads to wait until a
    // condition, or boolean predicate, on shared data is satisfied.
    class Condition
    {
    public:

        // Create a condition variable.
        Condition();

        // Destroy this condition variable.
        //
        // If this condition variable is destroyed while threads are blocking
        // on it, results are undefined.
        ~Condition();

        // Unblock at least one of the threads (if any) that are blocked on
        // this condition variable.
        //
        // If the calling thread does not own the mutex that threads calling
        // wait() have associated with this condition variable during their
        // waits, results are undefined.
        void signal();

        // Unblock all threads (if any) that are blocked on this condition
        // variable.
        //
        // If the calling thread does not own the mutex that threads calling
        // wait() have associated with this condition variable during their
        // waits, results are undefined.
        void broadcast();

        // Atomically release the given mutex and block on this condition
        // variable.
        //
        // If the calling thread does not own the given mutex, results are
        // undefined.
        //
        // This function returns with the given mutex locked and owned by the
        // calling thread.
        void wait(Mutex& mutex);

    private:

        // Private unimplemented copy constructor and assignment operator
        Condition(const Condition& copy);
        Condition& operator= (const Condition& rhs);

#ifdef _WIN32
        // Douglas C. Schmidt and Irfan Pyarali, "Strategies for Implementing
        // POSIX Condition Variables on Win32."
        // http://www.cs.wustl.edu/~schmidt/win32-cv-1.html
        int waitersCount;
        CRITICAL_SECTION waitersCountLock;
        HANDLE waitersSemaphore;
        HANDLE waitersDoneEvent;
        bool wasBroadcast;
#else // POSIX
        pthread_cond_t handle;
#endif
    };

    // Condition variable exceptions.  The error code is the return value from
    // the underlying function call.
    MAKE_EXCEPTION(ConditionException, "Error creating condition variable.");
    MAKE_EXCEPTION(SignalException, "Error signaling condition variable.");
    MAKE_EXCEPTION(BroadcastException,
        "Error broadcasting condition variable.");
    MAKE_EXCEPTION(WaitException, "Error waiting on condition variable.");
} // namespace thread

#endif // THREAD_CONDITION_H
