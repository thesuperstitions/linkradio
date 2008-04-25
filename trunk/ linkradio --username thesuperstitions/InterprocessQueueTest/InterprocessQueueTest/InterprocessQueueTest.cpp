// InterprocessQueueTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>

using namespace boost::interprocess;

int _tmain(int argc, _TCHAR* argv[])
{
  char c[5];
  char msg[100];
  int b;

  printf("Hit any key to START queing messages\n\n");

  fgets(c, 2, stdin);

  //Erase previous message queue
  message_queue::remove("message_queue");

  //Create a message_queue.
  message_queue mq
  (
    open_or_create,            //only create
    "message_queue",           //name
    100,                       //max message number
    sizeof(int)                //max message size
  );


  if (strcmp(argv[1], "server") == 0)
  {
    unsigned int* iPtr = (unsigned int*)&msg;
    //Send 100 numbers
    for(int i = 0; i < 100; i++)
    {
      b = sprintf(msg, "Message #%u, Priority=%u\n\n", i, i);
      b = (b/2)+1, i;
      mq.send(iPtr, b, i);
      printf("Queued value=\"%u\".  Priority=%u\n\n", i, i);
    }
  }

  if (strcmp(argv[1], "client") == 0)
  {
    std::size_t recvd_size;
    unsigned int priority;

    //Receive 100 numbers
    for(int i = 0; i < 100; i++)
    {
      mq.receive(&msg, sizeof(msg), recvd_size, priority);

      printf("Message=\"%s\".  Size=%u, Priority=%u\n\n", msg, recvd_size, priority);
    }

  }





  message_queue::remove("message_queue");



  printf("Hit any key to STOP  queing/de-queing messages\n\n");

  fgets(c, 2, stdin);



	return 0;
}

