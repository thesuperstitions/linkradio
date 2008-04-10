///////////////////////////////////////////////////////////////////////////////
//
// thread_Runnable.cpp
//
///////////////////////////////////////////////////////////////////////////////

#include "thread_Runnable.h"

thread::Runnable::Runnable() :
    detached(false)
{
    // empty
}

thread::Runnable::~Runnable()
{
    // empty
}

bool thread::Runnable::isDetached() const
{
    return detached;
}
