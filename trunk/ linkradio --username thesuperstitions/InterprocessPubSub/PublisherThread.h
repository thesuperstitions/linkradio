/*********************************************************************
	Login		: rosskw1
	Model Element	: PublisherThread
	Generated Date	: Mon, 21, Apr 2008  
	File Path	: PublisherThread.h
*********************************************************************/


#ifndef PublisherThread_H 

#define PublisherThread_H 

#include "InterprocessQueue.h"
#include "Thread.h"
#include "SocketClient.h"
//----------------------------------------------------------------------------
// PublisherThread.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif


class ReaderThread : public framework::utils::Thread
{
  public:
    ReaderThread(Socket* SC);

    ~ReaderThread(void);

    void start();

    void stop();

    void threadOperation();

  protected:
    Socket* mySocket;
    bool    exitFlag;
};

		//## class PublisherThread 
class PublisherThread  : public framework::utils::Thread,  public SocketClient
{             
	////    Constructors and destructors    ////
	public :

	  //## auto_generated 
	  PublisherThread(int unitNumber, char* IP);

	  //## auto_generated 
	  ~PublisherThread();

	  virtual void threadOperation();

	  virtual void start();
	  virtual void stop();
    virtual void ClientSocketConnected(Socket* ClientSocket);
    virtual void LogData(char* Str);

	protected:
	  bool          exitFlag;
    Socket*       mySocket;
    unsigned char myUnitNumber;
    char          myIP[50];
    ReaderThread* myReader;
};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PublisherThread.h
*********************************************************************/

