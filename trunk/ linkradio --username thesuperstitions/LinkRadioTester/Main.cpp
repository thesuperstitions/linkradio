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
//#include "SubscriberThread.h"
#include <boost/interprocess/shared_memory_object.hpp>
#include <string.h>

PublisherThread*    publisherThread;
//SubscriberThread*   subscriberThread;

//----------------------------------------------------------------------------
// MainDefaultComponent.cpp                                                                  
//----------------------------------------------------------------------------
//## configuration DefaultComponent::DefaultConfig 
int main(int argc, char* argv[]) 
{
	char c[5];
  char IP[100];
	int unitNumber = atoi(argv[1]);

  if (argc >= 3)
    strcpy(IP, argv[2]);

	//if (unitNumber == 2)
	//{
		printf("\n\nHit any key to START Publishing messages\n");
		fgets(c, 2, stdin);
		publisherThread = new PublisherThread(unitNumber, IP);
    publisherThread->Initialize();
	//}

	//if (unitNumber == 2)
	//{
		printf("\nHit any key to STOP Publishing Messages\n\n");
		fgets(c, 2, stdin);
    delete publisherThread;
	//}

	printf("\nHit any key to EXIT\n\n");
	fgets(c, 2, stdin);

	return 0;
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

