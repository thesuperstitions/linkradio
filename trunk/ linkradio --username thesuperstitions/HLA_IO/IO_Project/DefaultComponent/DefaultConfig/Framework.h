/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\Framework.h
*********************************************************************/


#ifndef Framework_H 

#define Framework_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"

//----------------------------------------------------------------------------
// Framework.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    class FrameworkFederateAmbassador;
}


//## package Framework 


namespace Framework {
    
    //## type FederateType 
    enum FederateType {
        SSDS,
        CEC
    };
    
    //## type FrameworkMessage 
    struct FrameworkMessage {};
    
    // Returned in "getType" function in class "Federate I/O Handler.  I believe that this is the Message Type to be passed by the I/O Handler.
    //## type MessageType 
    enum MessageType {};
    
    //## type FederateFrameworkType 
    enum FederateFrameworkType {
        HLA_FederateFrameworkType,
        OASIS_FederateFrameworkType
    };
    
    
    // Convert narrow string to wide string
    //## operation DtToString(const std::wstring &) 
    inline std::string DtToString(const std::wstring & in_val) {
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
    inline std::wstring DtToWString(const char * in_val) {
        //#[ operation DtToWString(const char *) 
        std::wstring temp;
        while (*in_val != '\0')
        temp += *in_val++;
        return temp;
        //#]
    }
    
    
    //## operation convert(const std::string &,const std::string &,T &) 
    template <class T> inline bool convert(const std::string & param, const std::string & value, T & dest) {
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
    
    
    //## operation getFrameworkFederateAmbassador() 
    inline FrameworkFederateAmbassador* getFrameworkFederateAmbassador() {
        //#[ operation getFrameworkFederateAmbassador() 
        //#]
    }
    
    
    //## operation getRTIambassador() 
    rti1516::RTIambassador* getRTIambassador();
    
    
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Framework.h
*********************************************************************/

