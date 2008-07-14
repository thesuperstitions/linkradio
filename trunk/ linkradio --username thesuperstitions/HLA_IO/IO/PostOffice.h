/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::PostOffice
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\PostOffice.h
*********************************************************************/


#ifndef PostOffice_H 

#define PostOffice_H 

#include "Configuration.h"
#include "IO.h"
#include "RTI\RTI1516.h"
// operation sendMessage(FrameworkMessage*) 
#include "framework.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
//----------------------------------------------------------------------------
// PostOffice.h                                                                  
//----------------------------------------------------------------------------


namespace framework
{

	namespace Control
	{
		class Federate;

	} 

namespace io
{
	class FederateInterface;
}

}


//## package framework::io 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework
{
	namespace io
	{
		//## class PostOffice 
		class PostOffice
		{


		////    Constructors and destructors    ////
		public :

			//## auto_generated 
			PostOffice();

			//## auto_generated 
			virtual ~PostOffice();


		////    Operations    ////
		public :

			//## operation announcePublication(FederateInterface*) 
			virtual void announcePublication(FederateInterface* interface)=0;

			//## operation announceSubscription(FederateInterface*) 
			virtual void announceSubscription(FederateInterface* interface)=0;

			//## operation sendMessage(char*,int,FederateInterface*) 
			virtual void sendMessage(char* message, int messageSizeInBytes, FederateInterface* federateInterface)=0;

			//## operation sendMessage(FrameworkMessage*) 
			virtual void sendMessage(FrameworkMessage* message)=0;

			//## operation unsubscribe(FederateInterface*) 
			virtual void unsubscribe(FederateInterface* interface)=0;

		  virtual FederateInterface* createFederateInterface(int interfaceID, int unitNumber, 
		    std::string interfaceName, unsigned long maxMessageSize, 
		    unsigned long maxMessages, FederateInterfaceType federateInterfaceType);

		// same method, but inserts default sizes automatically
		  virtual FederateInterface* createFederateInterface(int interfaceID, int unitNumber, 
		    std::string interfaceName, FederateInterfaceType federateInterfaceType);

	private:

		  virtual FederateInterface* createFederateInterfaceObject(int interfaceID, int unitNumber, 
		    std::string interfaceName, unsigned long maxMessageSize, 
		    unsigned long maxMessages, FederateInterfaceType federateInterfaceType )=0;

		  virtual FederateInterface* createFederateInterfaceObject(int interfaceID, int unitNumber, 
		    std::string interfaceName, FederateInterfaceType federateInterfaceType )=0;
		};
	}
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PostOffice.h
*********************************************************************/

