///////////////////////////////////////////////////////////////////////////////
//
// thread_Thread.h
//
///////////////////////////////////////////////////////////////////////////////

#ifndef THREAD_THREAD_H
#define THREAD_THREAD_H

#ifdef _WIN32
#include <windows.h>
#else // POSIX
#include <pthread.h>
#endif

#include "thread_Condition.h"
#include "thread_Mutex.h"
#include "thread_Runnable.h"
#include "error_Exception.h"

#ifndef THREAD_STACK_SIZE
#define THREAD_STACK_SIZE 0 // thread stack reserve size (bytes)
#endif

namespace thread
{
    // A Thread is a handle to a thread of execution in a program.  A thread is
    // started by creating a Thread object and calling start().
    class Thread
    {
    public:

        // Create a thread handle.  Calling start() will execute the given
        // Runnable object's run() method in the created thread.
        explicit Thread(Runnable *runnable);

        // Close this thread handle.  Closing this handle does not terminate
        // the associated thread.
        ~Thread();

        // Start a new thread and call this task's run() method in that thread.
        //
        // If detached is false, then the thread is joinable; join() must be
        // called to ensure system resources are freed, and the associated
        // Runnable object will not be deleted automatically.
        //
        // If detached is true, then the thread is detached; the associated
        // Runnable object will be deleted automatically upon termination of
        // the thread (and so should only be allocated via new).
        //
        // If start() is called again after a prior successful start() call,
        // results are undefined.
        void start(bool detached = false);

        // Suspend execution of the calling thread until this joinable thread
        // terminates.
        //
        // After a successful start(false) call, join() must be called to
        // ensure system resources are freed.  If join() is called more than
        // once, or is called after start(true) is called, results are
        // undefined.
        void join();

        // ID is an opaque type representing an operating system identifier for
        // a thread.
#ifdef _WIN32
        typedef DWORD ID;
#else // POSIX
        typedef pthread_t ID;
#endif

        // Return the identifier of the calling thread.
        static ID self();

        // Return true iff the given identifiers refer to the same thread.
        static bool equal(ID t1, ID t2);

        // Suspend execution of the calling thread for at least the given time
        // (milliseconds).
        static void sleep(long ms);

    private:

        // Private unimplemented copy constructor and assignment operator
        Thread(const Thread& copy);
        Thread& operator= (const Thread& rhs);

        Runnable *runnable;
#ifdef _WIN32
        HANDLE handle;
#else // POSIX
        pthread_t handle;
#endif
    };

    // Thread exceptions.  The error code is the return value from the
    // underlying thread function call.
    MAKE_EXCEPTION(StartException, "Error starting thread.");
    MAKE_EXCEPTION(JoinException, "Error joining thread.");
    MAKE_EXCEPTION(DetachException, "Error detaching thread.");
} // namespace thread

#endif // THREAD_THREAD_H
