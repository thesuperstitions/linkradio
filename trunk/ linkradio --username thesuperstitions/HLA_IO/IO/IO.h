/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io
//!	Generated Date	: Tue, 20, May 2008  
	File Path	: DefaultComponent\DefaultConfig\IO.h
*********************************************************************/


#ifndef IO_H 

#define IO_H 

#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "framework.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
//----------------------------------------------------------------------------
// IO.h                                                                  
//----------------------------------------------------------------------------


namespace framework
{

	namespace io
	{
		class C_IO_Functions;
		class FederateInterface;
		class FederateIO_Handler;
		class HLA_FederateInterface;
		class HLA_PostOffice;
		class OASIS_FederateInterface;
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


		//## attribute MAX_FEDERATE_INTERFACE_DEVICES 
		#define MAX_FEDERATE_INTERFACE_DEVICES 100


	}

}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IO.h
*********************************************************************/

