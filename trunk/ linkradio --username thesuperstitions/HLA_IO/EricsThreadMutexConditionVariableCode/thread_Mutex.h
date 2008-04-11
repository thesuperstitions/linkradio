///////////////////////////////////////////////////////////////////////////////
//
// thread_Mutex.h
//
///////////////////////////////////////////////////////////////////////////////

#ifndef THREAD_MUTEX_H
#define THREAD_MUTEX_H

#ifdef _WIN32
#include <windows.h>
#else // POSIX
#include <pthread.h>
#endif

#include "error_Exception.h"

namespace thread
{
    // A Mutex is an object used to synchronize access to data shared between
    // threads.
    class Mutex
    {
    public:

        // Create an initially unlocked mutex.
        Mutex();

        // Destroy this mutex.
        //
        // If this mutex is destroyed while locked, results are undefined.
        ~Mutex();

        // Lock this mutex, blocking until the mutex becomes available.
        //
        // If lock() is called from a thread that already owns this mutex,
        // results are undefined.
        void lock();

        // Unlock this mutex.
        //
        // If unlock() is called from a thread that does not own this mutex,
        // results are undefined.
        void unlock();

    private:

        // Private unimplemented copy constructor and assignment operator
        Mutex(const Mutex& copy);
        Mutex& operator= (const Mutex& rhs);

#ifdef _WIN32
        HANDLE handle;
#else // POSIX
        pthread_mutex_t handle;
#endif

        // Condition variables access Mutex::handle.
        friend class Condition;
    };

    // Mutex exceptions.  The error code is the return value from the
    // underlying mutex function call.
    MAKE_EXCEPTION(MutexException, "Error creating mutex.");
    MAKE_EXCEPTION(LockException, "Error locking mutex.");
    MAKE_EXCEPTION(UnlockException, "Error unlocking mutex.");
} // namespace thread

#endif // THREAD_MUTEX_H
