// InterprocessQueueTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>

using namespace boost::interprocess;

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

//#include <iostream>

class Message
{
  private:
    friend class boost::serialization::access;
    // When the class Archive corresponds to an output archive, the
    // & operator is defined similar to <<.  Likewise, when the class Archive
    // is a type of input archive the & operator is defined similar to >>.
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & degrees;
        ar & minutes;
        ar & seconds;
    }
    int degrees;
    int minutes;
    float seconds;
public:
    Message(){};
    Message(int d, int m, float s) :
        degrees(d), minutes(m), seconds(s)
    {}
};

int _tmain(int argc, _TCHAR* argv[])
{
  char c[5];
  Message msg(1, 2, 333.333);
  char cMsg[100];
  std::ostream os;


  //printf("Hit any key to START queing messages\n\n");

  //fgets(c, 2, stdin);

  ////Erase previous message queue
  //message_queue::remove("message_queue");

  ////Create a message_queue.
  //message_queue mq
  //(
  //  open_or_create,            //only create
  //  "message_queue",           //name
  //  100,                       //max message number
  //  sizeof(int)                //max message size
  //);


  if (strcmp(argv[1], "server") == 0)
  {
    // save data to archive
    {
        boost::archive::text_oarchive oa(os);
        // write class instance to archive
        oa << msg;
        cMsg << os;
    	// archive and stream closed when destructors are called
    }

    //mq.send(&msg, sizeof(msg), 1);
    //printf("Queued Message.\n\n");

  }

  if (strcmp(argv[1], "client") == 0)
  {
    //std::size_t recvd_size;
    //unsigned int priority;

    //mq.receive(&msg, sizeof(msg), recvd_size, priority);
    //printf("Dequeued Message.  Size=%u, Priority=%u, Value=%f\n\n", recvd_size, priority, msg);

    //Receive 100 numbers
    //for(int i = 0; i < 100; i++)
    //{
    //  printf("Message[%u]=%u,  Priority=%u\n\n", i, msg[i], priority);
    //}

  }





  //message_queue::remove("message_queue");



  //printf("Hit any key to STOP  queing/de-queing messages\n\n");

  //fgets(c, 2, stdin);



	return 0;
}

