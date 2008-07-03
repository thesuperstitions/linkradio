/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DefaultConfig
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

#include "Main.h"
#include "PublisherThread.h"
#include "SubscriberThread.h"
#include "FrameworkThread.h"
#include <boost/interprocess/shared_memory_object.hpp>
//#include "ntds_comm_.h"
//#include "sps49_io_.h" 


PublisherThread*    publisherThread;
SubscriberThread*   subscriberThread;
FrameworkThread*    frameworkThread;

//----------------------------------------------------------------------------
// MainDefaultComponent.cpp                                                                  
//----------------------------------------------------------------------------

//## configuration DefaultComponent::DefaultConfig 
int main(int argc, char* argv[]) 
{

  char c[5];
  int unitNumber = atoi(argv[1]);

  printf("Hit any key to CREATE Framework");
  fgets(c, 2, stdin);

  frameworkThread = new FrameworkThread(unitNumber);

  if (unitNumber == 1)
  {
    printf("\n\nHit any key to START Receiving messages\n");
    fgets(c, 2, stdin);

    subscriberThread = new SubscriberThread(unitNumber);

    subscriberThread->start();
  }
   
  if (unitNumber == 2)
  {
    printf("\n\nHit any key to START Publishing messages\n");
    fgets(c, 2, stdin);

    publisherThread = new PublisherThread(unitNumber);

    publisherThread->start();
  }

  printf("\nHit any key to DELETE Framework\n\n");
  fgets(c, 2, stdin);

  delete frameworkThread;

  if (unitNumber == 1)
  {
    printf("\nHit any key to STOP Receiving Messages\n\n");
    fgets(c, 2, stdin);

    delete subscriberThread;
  }

  if (unitNumber == 2)
  {
    printf("\nHit any key to STOP Publishing Messages\n\n");
    fgets(c, 2, stdin);

	  delete publisherThread;
  }

  printf("\nHit any key to EXIT\n\n");
  fgets(c, 2, stdin);

  return 0;
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

