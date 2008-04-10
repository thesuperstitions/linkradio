/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterface
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/


#ifndef FederateInterface_H 

#define FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"

//----------------------------------------------------------------------------
// FederateInterface.h                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 


namespace Framework {
    namespace IO {
        //## class FederateInterface 
        class FederateInterface  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation FederateInterface(std::string) 
            FederateInterface(std::string name);
            
            //## auto_generated 
            ~FederateInterface();
        
        
        ////    Additional operations    ////
        protected :
            
            //## auto_generated 
            std::string getInterfaceName() const;
            
            //## auto_generated 
            void setInterfaceName(std::string p_interfaceName);
        
        
        ////    Attributes    ////
        protected :
            
            std::string interfaceName;		//## attribute interfaceName 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/

