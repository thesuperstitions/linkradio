/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control::ExampleFederate
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\ExampleFederate.cpp
*********************************************************************/

#include "ExampleFederate.h"
#include "FederateIO_Handler.h"
// dependency FederateInterfaceFactory 
#include "FederateInterfaceFactory.h"
// operation ExampleFederate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
#include "FrameworkFederateAmbassador.h"
// dependency HLA_PostOffice 
#include "HLA_PostOffice.h"
// dependency PostOffice 
#include "PostOffice.h"
//----------------------------------------------------------------------------
// ExampleFederate.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::Control 

//## class ExampleFederate 

namespace framework
{
	namespace Control
	{

		ExampleFederate::ExampleFederate(FederateFrameworkType fedFrameworkType, FederateType fedType, FrameworkFederateAmbassador* frameworkFederateAmbassador) : Federate(fedFrameworkType, fedType, frameworkFederateAmbassador)
		{
			//#[ operation ExampleFederate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
			//#]
		}

		ExampleFederate::~ExampleFederate()
		{
		}

		void ExampleFederate::useCase_42_1_announcePublication()
		{
			//#[ operation useCase_42_1_announcePublication() 
			/*            
			switch (federateType)
			{
				case CEC_FederateType : 
				// Publish that the interface is available.
				getThePostOffice()->announcePublication(getTheFederateInterface("SPYtoCECNtds"));   
				break;
								case SSDS_FederateType :
				break;
				};  
				*/            
				//#]
			}

		void ExampleFederate::useCase_42_2_announceSubscription()
		{
			//#[ operation useCase_42_2_announceSubscription() 

			// Subscribe to the interaction so that we receive data on the interface.
			//            getThePostOffice()->announceSubscription(getTheFederateInterface("SPYtoCECNtds"));   

			//#]
		}

		void ExampleFederate::useCase_42_3_sendMessageOnFederateInterface()
		{
			//#[ operation useCase_42_3_sendMessageOnFederateInterface() 


			//#]
		}

	}
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ExampleFederate.cpp
*********************************************************************/

