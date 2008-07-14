/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::FederateIO_Handler
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/
#include "framework/io/FederateIO_Handler.h"

#include "framework/common/FrameworkComponentFactory.h"
// link itsFederate 
#include "framework/common/Federate.h"
// link itsFederateInterfaceFactory 
#include "framework/io/FederateInterfaceFactory.h"
// dependency PostOffice 
#include "framework/io/PostOffice.h"

#include "framework/io/ValueCompare.h"
//----------------------------------------------------------------------------
// FederateIO_Handler.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::io 

//## class FederateIO_Handler 

namespace framework
{
	namespace io
	{


		FederateIO_Handler::FederateIO_Handler(void) : itsFederateInterface()
		{
			itsFederateInterfaceFactory = NULL;
			//#[ 

			//#]
		}

		FederateIO_Handler::~FederateIO_Handler()
		{
			//#[ operation ~FederateIO_Handler() 

			//#]
			cleanUpRelations();
		}

		FederateInterface* FederateIO_Handler::createFederateInterface(int interfaceID, int unitNumber, std::string interfaceName, unsigned long maxMessageSize, unsigned long maxMessages, FederateInterfaceType federateInterfaceType)
		{
			//#[ operation createFederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 

			// Create a FederateInterface by calling the factory.
			framework::io::FederateInterface* FI_Ptr = getItsFederateInterfaceFactory()->createFederateInterface(
				interfaceID, unitNumber, interfaceName, maxMessageSize, maxMessages, federateInterfaceType);

			// Map the Federate interface to its name.
			addItsFederateInterface(interfaceID, FI_Ptr);   

			if ( (federateInterfaceType == FederateInterfaceTypePublisherSubscriber) || 
					(federateInterfaceType == FederateInterfaceTypePublisher) )
					{
            framework::common::FrameworkComponentFactory::instance().getPostOffice().announcePublication( FI_Ptr );
					}

			if ( (federateInterfaceType == FederateInterfaceTypePublisherSubscriber) || 
					(federateInterfaceType == FederateInterfaceTypeSubscriber) )
					{
            framework::common::FrameworkComponentFactory::instance().getPostOffice().announceSubscription( FI_Ptr );
					}

			return(FI_Ptr); 

			//#]
		}

		std::map<int, framework::io::FederateInterface*>::const_iterator FederateIO_Handler::getItsFederateInterface() const
		{
			std::map<int, framework::io::FederateInterface*>::const_iterator iter;
			iter = itsFederateInterface.begin();
			return iter;
		}

		std::map<int, framework::io::FederateInterface*>::const_iterator FederateIO_Handler::getItsFederateInterfaceEnd() const
		{
			return itsFederateInterface.end();
		}

		void FederateIO_Handler::_clearItsFederateInterface()
		{
			itsFederateInterface.clear();
		}

		void FederateIO_Handler::clearItsFederateInterface()
		{
			std::map<int, framework::io::FederateInterface*>::const_iterator iter;
			iter = itsFederateInterface.begin();
			while (iter != itsFederateInterface.end())
			{
				((*iter).second)->_clearItsFederateIO_Handler();
				iter++;
			}
			_clearItsFederateInterface();
		}

		void FederateIO_Handler::_removeItsFederateInterface(framework::io::FederateInterface* p_FederateInterface)
		{
			std::map<int, framework::io::FederateInterface*>::iterator pos = std::find_if(itsFederateInterface.begin(), itsFederateInterface.end(),ValueCompare<const int,framework::io::FederateInterface*>(p_FederateInterface));
			if (pos != itsFederateInterface.end())
			{
				itsFederateInterface.erase(pos);
			}
		}

		void FederateIO_Handler::removeItsFederateInterface(framework::io::FederateInterface* p_FederateInterface)
		{
			if(p_FederateInterface != NULL)
			{
				p_FederateInterface->__setItsFederateIO_Handler(NULL);
			}
			_removeItsFederateInterface(p_FederateInterface);
		}

		framework::io::FederateInterface* FederateIO_Handler::getItsFederateInterface(int key) const
		{
			return (itsFederateInterface.find(key) != itsFederateInterface.end() ? (*itsFederateInterface.find(key)).second : NULL);
		}

		void FederateIO_Handler::_addItsFederateInterface(int key, framework::io::FederateInterface* p_FederateInterface)
		{
			itsFederateInterface.insert(std::map<int, framework::io::FederateInterface*>::value_type(key, p_FederateInterface));
		}

		void FederateIO_Handler::addItsFederateInterface(int key, framework::io::FederateInterface* p_FederateInterface)
		{
			if(p_FederateInterface != NULL)
			{
				p_FederateInterface->_setItsFederateIO_Handler(this);
			}
			_addItsFederateInterface(key, p_FederateInterface);
		}

		void FederateIO_Handler::_removeItsFederateInterface(int key)
		{
			itsFederateInterface.erase(key);
		}

		void FederateIO_Handler::removeItsFederateInterface(int key)
		{
			framework::io::FederateInterface* p_FederateInterface = getItsFederateInterface(key);
			if(p_FederateInterface != NULL)
			{
				p_FederateInterface->_setItsFederateIO_Handler(NULL);
			}
			_removeItsFederateInterface(key);
		}

		framework::Control::FederateInterfaceFactory* FederateIO_Handler::getItsFederateInterfaceFactory() const
		{
			return itsFederateInterfaceFactory;
		}

		void FederateIO_Handler::setItsFederateInterfaceFactory(framework::Control::FederateInterfaceFactory* p_FederateInterfaceFactory)
		{
			itsFederateInterfaceFactory = p_FederateInterfaceFactory;
			p_FederateInterfaceFactory->setItsFederateIO_Handler(this);
		}

		void FederateIO_Handler::cleanUpRelations()
		{
  		itsFederateInterface.clear();

			if(itsFederateInterfaceFactory != NULL)
			{
				delete itsFederateInterfaceFactory;
				itsFederateInterfaceFactory = NULL;
			}
		}

	}
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.cpp
*********************************************************************/

