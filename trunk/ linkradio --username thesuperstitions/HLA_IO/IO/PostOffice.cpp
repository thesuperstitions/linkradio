/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::PostOffice
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\PostOffice.cpp
*********************************************************************/

// link theFederate 
#include "Federate.h"
// operation announcePublication(FederateInterface*) 
#include "FederateInterface.h"
#include "PostOffice.h"
//----------------------------------------------------------------------------
// PostOffice.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::io 

//## class PostOffice 

namespace framework
{
	namespace io
	{
		PostOffice::PostOffice()
		{
		}

		PostOffice::~PostOffice()
		{
		}
    
    FederateInterface* PostOffice::createFederateInterface(int interfaceID, int unitNumber, 
		std::string interfaceName, unsigned long maxMessageSize, 
    unsigned long maxMessages, FederateInterfaceType federateInterfaceType)
    {

			// Create a FederateInterface by calling the factory.
			framework::io::FederateInterface* FI_Ptr = createFederateInterfaceObject(
				interfaceID, unitNumber, interfaceName, maxMessageSize, maxMessages, federateInterfaceType);

			if ( (federateInterfaceType == FederateInterfaceTypePublisherSubscriber) || 
					(federateInterfaceType == FederateInterfaceTypePublisher) )
					{
						announcePublication( FI_Ptr );   
					}

			if ( (federateInterfaceType == FederateInterfaceTypePublisherSubscriber) || 
					(federateInterfaceType == FederateInterfaceTypeSubscriber) )
					{
						announceSubscription( FI_Ptr ); 
					}

			return(FI_Ptr); 
    }

		// same method, but inserts default sizes automatically
		FederateInterface* PostOffice::createFederateInterface(int interfaceID, int unitNumber, 
		std::string interfaceName, FederateInterfaceType federateInterfaceType)
    {
      return (createFederateInterface(interfaceID, unitNumber, interfaceName, INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES, 
        INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE, federateInterfaceType) );
    }
	}
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PostOffice.cpp
*********************************************************************/

