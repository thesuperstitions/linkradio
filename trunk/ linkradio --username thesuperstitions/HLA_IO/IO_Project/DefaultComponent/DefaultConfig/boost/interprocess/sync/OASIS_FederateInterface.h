/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::OASIS_FederateInterface
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\OASIS_FederateInterface.h
*********************************************************************/


#ifndef boost_interprocess_sync_OASIS_FederateInterface_H 

#define boost_interprocess_sync_OASIS_FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "boost\interprocess\sync\IO.h"
// class OASIS_FederateInterface 
#include "boost\interprocess\sync\FederateInterface.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\OASIS_FederateInterface.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateIO_Handler;
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
            
            //## operation OASIS_FederateInterface(std::string,Framework::InterfaceType) 
            OASIS_FederateInterface(std::string name, Framework::InterfaceType interfaceType);
            
            //## auto_generated 
            ~OASIS_FederateInterface();
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\OASIS_FederateInterface.h
*********************************************************************/

