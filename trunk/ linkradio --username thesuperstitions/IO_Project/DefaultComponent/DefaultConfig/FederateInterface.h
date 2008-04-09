/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterface
//!	Generated Date	: Tue, 1, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/


#ifndef FederateInterface_H 

#define FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"

//----------------------------------------------------------------------------
// FederateInterface.h                                                                  
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
        //## class FederateInterface 
        class FederateInterface  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation FederateInterface(std::string,Framework::InterfaceType) 
            FederateInterface(std::string name, Framework::InterfaceType interfaceType);
            
            //## auto_generated 
            ~FederateInterface();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            std::string getInterfaceName() const;
            
            //## auto_generated 
            void setInterfaceName(std::string p_interfaceName);
            
            //## auto_generated 
            Framework::InterfaceType getInterfaceType() const;
            
            //## auto_generated 
            void setInterfaceType(Framework::InterfaceType p_interfaceType);
            
            //## auto_generated 
            FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _setItsFederateIO_Handler(FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _clearItsFederateIO_Handler();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            std::string interfaceName;		//## attribute interfaceName 
            
            Framework::InterfaceType interfaceType;		//## attribute interfaceType 
            
        
        ////    Relations and components    ////
        protected :
            
            FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterface.h
*********************************************************************/

