/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::FederateInterface
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/


#ifndef FederateInterface_H 

#define FederateInterface_H 

#include "Configuration.h"
// dependency Control 
#include "Control.h"
#include "IO.h"
#include "RTI\RTI1516.h"
// operation FederateInterface(int,std#include "framework.h"
// class FederateInterface 
#include <Thread.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "Configuration.h"
// dependency Control 
#include "Control.h"
#include "IO.h"
#include "RTI\RTI1516.h"
// operation FederateInterface(int,std#include "framework.h"
#include <InterprocessQueue.h>
// class FederateInterface 
#include <Thread.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
//----------------------------------------------------------------------------
// FederateInterface.h                                                                  
//----------------------------------------------------------------------------


namespace framework
{

	namespace Control
	{
		class Federate;

	} 

namespace io
{
	class FederateIO_Handler;
	class PostOffice;
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
		//## class FederateInterface 
		class FederateInterface : public utils::Thread
		{


		////    Constructors and destructors    ////
		public :

			//## operation FederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
			FederateInterface(int interfaceID, int unitNumber, std::string name, 
				unsigned long maxMessageSize = INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES, 
				unsigned long maxMessages = INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE, 
				FederateInterfaceType federateInterfaceType = FederateInterfaceTypeUnselected);

			//## operation ~FederateInterface() 
			~FederateInterface();


		////    Operations    ////
		public :

			//## operation processFederateMessage(char*,int) 
			virtual bool processFederateMessage(unsigned char* message, int messageSizeInBytes);

			//## operation threadOperation() 
			void threadOperation();


		////    Additional operations    ////
		public :

			//## auto_generated 
			bool getExitFlag() const;

			//## auto_generated 
			void setExitFlag(bool p_exitFlag);

			//## auto_generated 
			int getInterfaceID() const;

			//## auto_generated 
			void setInterfaceID(int p_interfaceID);

			//## auto_generated 
			std::string getInterfaceName() const;

			//## auto_generated 
			void setInterfaceName(std::string p_interfaceName);

			//## auto_generated 
			unsigned long getMaxMessageSize() const;

			//## auto_generated 
			void setMaxMessageSize(unsigned long p_maxMessageSize);

			//## auto_generated 
			unsigned long getMaxMessages() const;

			//## auto_generated 
			void setMaxMessages(unsigned long p_maxMessages);

			//## auto_generated 
			framework::utils::InterprocessQueue* getPublishQueue() const;

			//## auto_generated 
			void setPublishQueue(framework::utils::InterprocessQueue* p_publishQueue);

			//## auto_generated 
			framework::utils::InterprocessQueue* getSubscribeQueue();

			//## auto_generated 
			void setSubscribeQueue(framework::utils::InterprocessQueue* p_subscribeQueue);

			//## auto_generated 
			FederateIO_Handler* getItsFederateIO_Handler() const;

			//## auto_generated 
			void setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);


		////    Framework operations    ////
		public :

			//## auto_generated 
			void __setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);

			//## auto_generated 
			void _setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);

			//## auto_generated 
			void _clearItsFederateIO_Handler();

		protected :

			//## auto_generated 
			void cleanUpRelations();


		////    Attributes    ////
		protected :

			bool exitFlag;		//## attribute exitFlag 

			int interfaceID;		//## attribute interfaceID 

			std::string interfaceName;		//## attribute interfaceName 

			unsigned long maxMessageSize;		//## attribute maxMessageSize 

			unsigned long maxMessages;		//## attribute maxMessages 

			framework::utils::InterprocessQueue* publishQueue;		//## attribute publishQueue 

			framework::utils::InterprocessQueue* subscribeQueue;		//## attribute subscribeQueue 


		////    Relations and components    ////
		protected :

			FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 



		};
	} // namespace io
} // namespace framework


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/

