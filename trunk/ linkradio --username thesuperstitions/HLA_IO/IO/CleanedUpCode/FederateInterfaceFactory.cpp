/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control::FederateInterfaceFactory
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.cpp
*********************************************************************/

// link itsFederateIO_Handler 
#include "framework/io/FederateIO_Handler.h"
#include "framework/io/FederateInterfaceFactory.h"
// dependency HLA_FederateInterface 
#include "framework/io/hla/HLA_FederateInterface.h"
//----------------------------------------------------------------------------
// FederateInterfaceFactory.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::Control 

//## class FederateInterfaceFactory 

namespace framework
{
	namespace Control
	{


		FederateInterfaceFactory::FederateInterfaceFactory()
		{
			itsFederateIO_Handler = NULL;
		}

		FederateInterfaceFactory::~FederateInterfaceFactory()
		{
			cleanUpRelations();
		}

		framework::io::FederateInterface* FederateInterfaceFactory::createFederateInterface(int interfaceID, int unitNumber, 
      std::string name, unsigned long maxMessageSize, unsigned long maxMessages, framework::io::FederateInterfaceType federateInterfaceType) 
		{
				//#[ operation createFederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
				//switch(fedFrameworkType)
				//{
				//	case HLA_FederateFrameworkType:
				//	return( static_cast<framework::io::FederateInterface*>( new framework::io::hla::HLA_FederateInterface(
				//	getItsFederateIO_Handler(), interfaceID, 
				//	unitNumber, name, maxMessageSize, maxMessages, federateInterfaceType) ) );
				//	break;
				//	case OASIS_FederateFrameworkType:
				//	return( static_cast<framework::io::FederateInterface*>( new framework::io::OASIS_FederateInterface(
				//	getItsFederateIO_Handler(), interfaceID, 
				//	unitNumber, name, maxMessageSize, maxMessages, federateInterfaceType) ) );
				//	break;
				//	};  
										return(NULL);          
					//#]
					//}
					//							FederateFrameworkType FederateInterfaceFactory::getFedFrameworkType() const
					//{
					//	return fedFrameworkType;
			}

		framework::io::FederateIO_Handler* FederateInterfaceFactory::getItsFederateIO_Handler() const
		{
			return itsFederateIO_Handler;
		}

		void FederateInterfaceFactory::setItsFederateIO_Handler(framework::io::FederateIO_Handler* p_FederateIO_Handler)
		{
			itsFederateIO_Handler = p_FederateIO_Handler;
		}

		void FederateInterfaceFactory::cleanUpRelations()
		{
			if(itsFederateIO_Handler != NULL)
			{
				itsFederateIO_Handler = NULL;
			}
		}

	}
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.cpp
*********************************************************************/

