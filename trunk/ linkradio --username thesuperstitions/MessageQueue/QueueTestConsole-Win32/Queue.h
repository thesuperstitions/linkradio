//---------------------------------------------------------------------------
#ifndef QueueH
#define QueueH

//---------------------------------------------------------------------------

//#include <QString>
//#include <QObject>
//#include "Thread.h"
#include "boost/thread/mutex.hpp"
#include <boost/circular_buffer.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

#include <stdio.h>
#include <time.h>
#include <sys\timeb.h>

#include "Sleep.h"
#include <ctime>

#define MAX_MESSAGE_SIZE_IN_BYTES 100
#define MAX_MESSAGES_IN_QUEUE     100000


struct genericMessage
{
  unsigned char message[MAX_MESSAGE_SIZE_IN_BYTES];
};

struct Shared_Memory_Queue
{
  Shared_Memory_Queue() : NumberMessagesInQueue(0), CurrentReadSlot(0), CurrentWriteSlot(0) {}

  boost::interprocess::interprocess_mutex myMutex;		//## attribute myMutex
  boost::interprocess::interprocess_mutex myDataAccessMutex;

  unsigned int                            NumberMessagesInQueue;
  unsigned int                            CurrentReadSlot;
  unsigned int                            CurrentWriteSlot;

  // Message queue.
  genericMessage messages[MAX_MESSAGES_IN_QUEUE];
};


using namespace boost::interprocess;


        //## class Queue
class InterprocessQueue
{
  protected:
    //unsigned long CurrentMessageSlot;
    char          QueueName[100];

  ////    Constructors and destructors    ////
  public :
    enum UserType
    {
      IPQ_SERVER,
      IPQ_CLIENT
    };

    InterprocessQueue(char* queueName, UserType uType);

    //## operation Queue()
    virtual ~InterprocessQueue();

    ////    Operations    ////
    public :
      //## operation addMessage(FederateMessage*)
      virtual bool addMessage(unsigned char* message, unsigned int messageSizeInBytes);
      virtual void* getMessage(genericMessage* msg, unsigned int timeoutSecs, unsigned long int timeoutMicroSecs);

    protected :
      void* InterprocessQueue::CheckForMessage(genericMessage* msg);

    ////    Attributes    ////
    protected :
      bool      exitFlag;

    ////    Relations and components    ////
    public :
      Shared_Memory_Queue* myQueue;
      shared_memory_object* shm;
      mapped_region* region;
      void * addr;
void LogMessage(char* Msg, double count);
};



//---------------------------------------------------------------------------
#endif
