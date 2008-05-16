/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::OASIS_FederateInterface
//!	Generated Date	: Thu, 15, May 2008  
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.h
*********************************************************************/


#ifndef OASIS_FederateInterface_H 

#define OASIS_FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// operation OASIS_FederateInterface(std::string,Framework::InterfaceType,FederateInterfaceType) 
#include "Framework.h"
// class OASIS_FederateInterface 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// OASIS_FederateInterface.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateIO_Handler;
        
    } 
    
namespace utils {
    class InterprocessQueue;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class OASIS_FederateInterface 
        class OASIS_FederateInterface : public FederateInterface {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation OASIS_FederateInterface(std::string,Framework::InterfaceType,FederateInterfaceType) 
            OASIS_FederateInterface(std::string name, Framework::InterfaceType interfaceType, FederateInterfaceType federateInterfaceType);
            
            //## auto_generated 
            ~OASIS_FederateInterface();
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.h
*********************************************************************/

