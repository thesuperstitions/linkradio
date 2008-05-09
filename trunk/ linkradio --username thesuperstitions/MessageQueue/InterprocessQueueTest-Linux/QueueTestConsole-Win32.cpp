// QueueTestConsole-Win32.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "ProducerThread.h"
#include "ConsumerThread.h"
#include "InterprocessQueue.h"

ProducerThread*    producerThread;
ConsumerThread*    consumerThread;
//InterprocessQueue* queue;


// Creates an instance of Queue, ProducerThread and ConsumerThread
// to test the performance of the Queue class.

int main(int argc, char* argv[])
{

  char c[5];

  printf("Hit any key to START queing messages");

  fgets(c, 2, stdin);

  if (strcmp(argv[1], "server") == 0)
  {
    producerThread = new ProducerThread();
    producerThread->start();
  }

  if (strcmp(argv[1], "client") == 0)
  {
    consumerThread = new ConsumerThread();
    consumerThread->start();
  }


  printf("Hit any key to STOP  queing/de-queing messages\n\n");

  fgets(c, 2, stdin);
  if (strcmp(argv[1], "server") == 0)
  {

		producerThread->stop();

		delete producerThread;
	}

  if (strcmp(argv[1], "client") == 0)
  {
    consumerThread->stop();
    delete consumerThread;
  }
	return 0;
}

