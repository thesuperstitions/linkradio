/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control::FederateInterfaceFactory
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.h
*********************************************************************/


#ifndef FederateInterfaceFactory_H 

#define FederateInterfaceFactory_H 

#include "Configuration.h"
#include "Control.h"
#include "RTI\RTI1516.h"
// operation FederateInterfaceFactory(FederateFrameworkType) 
#include "framework.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
//----------------------------------------------------------------------------
// FederateInterfaceFactory.h                                                                  
//----------------------------------------------------------------------------

namespace framework
{
	namespace io
	{

		class FederateInterface;
		class FederateIO_Handler;
		class OASIS_FederateInterface;
	namespace hla
	{
		class HLA_FederateInterface;
	}
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
		//## class FederateInterfaceFactory 
		class FederateInterfaceFactory
		{


		////    Constructors and destructors    ////
		public :

			//## operation FederateInterfaceFactory(FederateFrameworkType) 
			FederateInterfaceFactory(const FederateFrameworkType& frameworkType);

			//## auto_generated 
			FederateInterfaceFactory();

			//## auto_generated 
			~FederateInterfaceFactory();


		////    Operations    ////
		public :

			//## operation createFederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
			framework::io::FederateInterface* createFederateInterface(int interfaceID, int unitNumber, std::string name, unsigned long maxMessageSize, unsigned long maxMessages, FederateInterfaceType federateInterfaceType);


		////    Additional operations    ////
		public :

			//## auto_generated 
			FederateFrameworkType getFedFrameworkType() const;

			//## auto_generated 
			void setFedFrameworkType(FederateFrameworkType p_fedFrameworkType);

			//## auto_generated 
			io::FederateIO_Handler* getItsFederateIO_Handler() const;

			//## auto_generated 
			void setItsFederateIO_Handler(io::FederateIO_Handler* p_FederateIO_Handler);


		////    Framework operations    ////
		protected :

			//## auto_generated 
			void cleanUpRelations();


		////    Attributes    ////
		protected :

			FederateFrameworkType fedFrameworkType;		//## attribute fedFrameworkType 


		////    Relations and components    ////
		protected :

			io::FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 



		};
	}
}

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.h
*********************************************************************/

