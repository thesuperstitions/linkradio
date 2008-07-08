/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\framework.h
*********************************************************************/


#ifndef framework_H 

#define framework_H 

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <wchar.h>

#include "Configuration.h"
#include <RTI/logicalTimeFactoryImpl.h>
#include <RTI\RTI1516.h>
#include <RTI\RTIambassador.h>
#include <RTI\RTIambassadorFactory.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <wchar.h>
//----------------------------------------------------------------------------
// framework.h                                                                  
//----------------------------------------------------------------------------


namespace framework
{
	class FrameworkFederateAmbassador;
}

namespace rti1516
{
	class RTIambassador ;
}


//## package framework 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif


namespace framework
{

	//## type FrameworkMessage 
	struct FrameworkMessage {};

	// Returned in "getType" function in class "Federate I/O Handler.  I believe that this is the Message Type to be passed by the I/O Handler.
	//## type MessageType 
	enum MessageType {CEC_Msg_Type_1 = 1};

	//## type FederateFrameworkType 
	enum FederateFrameworkType
	{
		HLA_FederateFrameworkType,
		OASIS_FederateFrameworkType
	};

	//## type FederateType 
	enum FederateType
	{
		SSDS_FederateType,
		CEC_FederateType
	};

	//## type timespec 
	struct timespec
	{
		long tv_nsec;		//## attribute tv_nsec 
		time_t tv_sec;		//## attribute tv_sec 
	};

	//## type InterfaceType 
	enum InterfaceType
	{
		CEC_NTDS_SPY = 0,
		CEC_NTDS_CND = 1,
		CEC_NTDS_R48 = 2,
		CEC_NTDS_R49 = 3,
		SSDS_TCP_CEC = 4
	};

	//## type FederateInterfaceType 
	enum FederateInterfaceType
	{
		FederateInterfaceTypeUnselected = 0,
		FederateInterfaceTypePublisher = 1,
		FederateInterfaceTypeSubscriber = 2,
		FederateInterfaceTypePublisherSubscriber = 3
	};


	// Convert narrow string to wide string
	//## operation DtToString(const std::wstring &) 
	inline std::string DtToString(const std::wstring & in_val)
	{
		//#[ operation DtToString(const std::wstring &) 
		std::string temp;
		std::wstring::const_iterator b = in_val.begin();
		const std::wstring::const_iterator e = in_val.end();
		while (b != e)
		{
			temp += static_cast<char>(*b);
			++b;
		}
		return temp;
		//#]
	}


	// Convert narrow C string to wide string
	//## operation DtToWString(const char *) 
	inline std::wstring DtToWString(const char * in_val)
	{
		//#[ operation DtToWString(const char *) 
		std::wstring temp;
		while (*in_val != '\0')
		temp += *in_val++;
		return temp;
		//#]
	}


	//## operation RealTimeMode() 
	bool RealTimeMode();

	//## operation convert(const std::string &,const std::string &,T &) 
	template <class T> inline bool convert(const std::string & param, const std::string & value, T & dest)
	{
		//#[ operation convert(const std::string &,const std::string &,T &) 
		istringstream convert( value );
		convert >> dest;
		if ( convert.fail() )
		{
			std::cout << "Bad Parameter Value\n"
			<< "Param: " << param
			<< "\tValue: " << value << endl;
			return false;
		}
		return true;
		//#]
	}

	void initializeFramework();

	void finalizeFramework();

	//## operation getFrameworkFederateAmbassador() 
	FrameworkFederateAmbassador* getFrameworkFederateAmbassador();

	//## operation getTheRTIambassador () 
	rti1516::RTIambassador* getTheRTIambassador ();

	//## classInstance frameworkFederateAmbassador 
//    extern FrameworkFederateAmbassador* frameworkFederateAmbassador;

	//## classInstance rtiAmbassador 
//    extern rti1516::RTIambassador* rtiAmb;

	//## attribute INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE 
//    #define INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE 20

	//## attribute INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES 
//    #define INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES 100


}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\framework.h
*********************************************************************/

