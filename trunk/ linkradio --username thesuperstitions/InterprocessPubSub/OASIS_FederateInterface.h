/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::OASIS_FederateInterface
//!	Generated Date	: Tue, 20, May 2008  
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.h
*********************************************************************/


#ifndef OASIS_FederateInterface_H 

#define OASIS_FederateInterface_H 

#include "Configuration.h"
// class OASIS_FederateInterface 
#include "FederateInterface.h"
#include "IO.h"
#include "RTI\RTI1516.h"
// operation OASIS_FederateInterface(int,std#include "framework.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
//#include "ntds_config.h"
#include <string>
//----------------------------------------------------------------------------
// OASIS_FederateInterface.h                                                                  
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
		//## class OASIS_FederateInterface 
		class OASIS_FederateInterface : public FederateInterface
		{


		////    Constructors and destructors    ////
		public :

			//## operation OASIS_FederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
			OASIS_FederateInterface(FederateIO_Handler* FIOH, int interfaceID, int unitNumber, 
				std::string name, unsigned long maxMessageSize, unsigned long maxMessages, 
				FederateInterfaceType federateInterfaceType);

			//## auto_generated 
			~OASIS_FederateInterface();


		};
	}
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.h
*********************************************************************/

