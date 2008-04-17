//---------------------------------------------------------------------------
#ifndef QueueH
#define QueueH

//---------------------------------------------------------------------------

#include <vector>
#include <iterator>
// link itsMessage 
//#include "FederateMessage.h"
// class FederateIO_HandlerOutputThread 
#include <QString>
#include <QObject>
#include "Thread.h"
#include "boost/thread/mutex.hpp"
//#include "boost/thread/locks.hpp"


#include <ctime>

        //## class Queue
  class Queue : public QObject
        {
          Q_OBJECT
  
          ////    Constructors and destructors    ////
          public :
            Queue();

            //## operation Queue()
            virtual ~Queue();

          ////    Operations    ////
          public :
            //## operation addMessage(FederateMessage*)
            virtual void addMessage(void* message);
            virtual void* getMessage(unsigned int timeoutSecs, unsigned long int timeoutMilliSecs);

            void LogMessage(QString Msg);

          protected :

            //## auto_generated
            void cleanUpRelations();

          ////    Attributes    ////
          protected :

            boost::timed_mutex        myMutex;		//## attribute myMutex
            boost::mutex              myDataAccessMutex;
            bool                      exitFlag;

          ////    Relations and components    ////
          protected :
            std::list<void*> myQueue;

          public :
            signals:
              void OnLogText(QString);
        };








//---------------------------------------------------------------------------
#endif
