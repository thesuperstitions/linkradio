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

#ifdef WIN32
	#include <Windows.h>
	struct timespec
	{
		time_t tv_sec; //< seconds
		long   tv_nsec; //< nanoseconds
	};
#endif

        //## class Queue
        class Queue
        {
          Q_OBJECT
  
          ////    Constructors and destructors    ////
          public :
            //## operation Queue()
            virtual ~Queue();

          ////    Operations    ////
          public :
            //## operation addMessage(FederateMessage*)
            virtual void addMessage(void* message);
            virtual void* getMessage(unsigned int timeoutSecs, unsigned long int timeoutNanoSecs);


          ////    Additional operations    ////
          public :
            //## auto_generated
            std::vector<void*>::const_iterator getItsMessage() const;

            //## auto_generated
            std::vector<void*>::const_iterator getItsMessageEnd() const;

            //## auto_generated
            void addItsMessage(void* p_Message);

            //## auto_generated
            void removeItsMessage(void* p_Message);

            //## auto_generated
            void clearItsMessage();

          protected :

            //## auto_generated
            void cleanUpRelations();


          ////    Attributes    ////
          protected :
            boost::timed_mutex        myMutex;		//## attribute myMutex
            //boost::condition_variable myCondition;
            //bool                      myDataReady;

          ////    Relations and components    ////
          protected :
            std::vector<void*> itsMessage;		//## link itsMessage

          signals:
            void OnLogText(QString);
        };








//---------------------------------------------------------------------------
#endif
