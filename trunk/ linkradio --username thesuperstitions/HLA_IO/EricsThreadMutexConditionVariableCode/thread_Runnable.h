///////////////////////////////////////////////////////////////////////////////
//
// thread_Runnable.h
//
///////////////////////////////////////////////////////////////////////////////

#ifndef THREAD_RUNNABLE_H
#define THREAD_RUNNABLE_H

namespace thread
{
    // Runnable is an abstract base class for a task to be executed by a Thread
    // object.  Derived classes should implement run() to specify the task to
    // be executed.
    class Runnable
    {
    public:

        // Default constructor and destructor
        Runnable();
        virtual ~Runnable();

        // When a thread is started with this Runnable object, run() is called
        // in that separately executing thread.
        virtual void run() = 0;

        // Return true iff this task is being executed in a detached thread, in
        // which case this Runnable object will be deleted automatically upon
        // termination of the thread.
        bool isDetached() const;

    private:

        // Private unimplemented copy constructor and assignment operator
        Runnable(const Runnable& copy);
        Runnable& operator= (const Runnable& rhs);

        bool detached;

        // Thread objects access Runnable::detached.
        friend class Thread;
    };
} // namespace thread

#endif // THREAD_RUNNABLE_H
