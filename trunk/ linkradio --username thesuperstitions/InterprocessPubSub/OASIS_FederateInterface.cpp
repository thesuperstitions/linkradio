/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::OASIS_FederateInterface
//!	Generated Date	: Tue, 20, May 2008  
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.cpp
*********************************************************************/

// dependency Federate 
#include "Federate.h"
#include "FederateIO_Handler.h"
#include "OASIS_FederateInterface.h"
// dependency PostOffice 
#include "PostOffice.h"
//----------------------------------------------------------------------------
// OASIS_FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::io 

//## class OASIS_FederateInterface 

namespace framework
{
	namespace io
	{

		OASIS_FederateInterface::OASIS_FederateInterface(FederateIO_Handler* FIOH, int interfaceID, int unitNumber, 
															std::string name, unsigned long maxMessageSize, 
															unsigned long maxMessages, 
															FederateInterfaceType federateInterfaceType) : 
			FederateInterface(interfaceID, unitNumber, name, maxMessageSize, maxMessages, federateInterfaceType) 
			{
				//#[ operation OASIS_FederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
				//#]
			}

		OASIS_FederateInterface::~OASIS_FederateInterface()
		{
		}

	}
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.cpp
*********************************************************************/

