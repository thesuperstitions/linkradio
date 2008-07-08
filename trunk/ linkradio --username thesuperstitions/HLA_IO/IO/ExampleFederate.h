/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control::ExampleFederate
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\ExampleFederate.h
*********************************************************************/


#ifndef ExampleFederate_H 

#define ExampleFederate_H 

#include "Configuration.h"
#include "Control.h"
// class ExampleFederate 
#include "Federate.h"
#include "RTI\RTI1516.h"
// operation ExampleFederate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
#include "framework.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
//----------------------------------------------------------------------------
// ExampleFederate.h                                                                  
//----------------------------------------------------------------------------


namespace framework
{

	namespace Control
	{
		class FederateInterfaceFactory;

	} 

namespace io
{
	class FederateIO_Handler;

} 

} 

namespace framework
{
	class FrameworkFederateAmbassador;

} 

namespace framework
{

	namespace io
	{
		class HLA_PostOffice;
		class PostOffice;
	}

}


//## package framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework
{
	namespace Control
	{
		//## class ExampleFederate 
		class ExampleFederate : public Federate
		{


		////    Constructors and destructors    ////
		public :

			//## operation ExampleFederate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
			ExampleFederate(FederateFrameworkType fedFrameworkType, FederateType fedType, FrameworkFederateAmbassador* frameworkFederateAmbassador);

			//## auto_generated 
			~ExampleFederate();


		////    Operations    ////
		public :

			//## operation useCase_42_1_announcePublication() 
			void useCase_42_1_announcePublication();

			//## operation useCase_42_2_announceSubscription() 
			void useCase_42_2_announceSubscription();

			//## operation useCase_42_3_sendMessageOnFederateInterface() 
			void useCase_42_3_sendMessageOnFederateInterface();


		};
	}
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ExampleFederate.h
*********************************************************************/

