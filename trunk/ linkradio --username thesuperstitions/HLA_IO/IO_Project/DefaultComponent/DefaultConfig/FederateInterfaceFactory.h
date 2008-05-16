/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::FederateInterfaceFactory
//!	Generated Date	: Thu, 15, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.h
*********************************************************************/


#ifndef FederateInterfaceFactory_H 

#define FederateInterfaceFactory_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Control.h"
// operation FederateInterfaceFactory(FederateFrameworkType) 
#include "Framework.h"

//----------------------------------------------------------------------------
// FederateInterfaceFactory.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class FederateInterface;
        class FederateIO_Handler;
        class HLA_FederateInterface;
        class OASIS_FederateInterface;
    }
    
}


//## package Framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace Control {
        //## class FederateInterfaceFactory 
        class FederateInterfaceFactory  {
        
        
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
            
            //## operation createFederateInterface(std::string,Framework::InterfaceType,FederateInterfaceType) 
            Framework::IO::FederateInterface* createFederateInterface(std::string name, Framework::InterfaceType interfaceType, FederateInterfaceType federateInterfaceType);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateFrameworkType getFedFrameworkType() const;
            
            //## auto_generated 
            void setFedFrameworkType(FederateFrameworkType p_fedFrameworkType);
            
            //## auto_generated 
            IO::FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(IO::FederateIO_Handler* p_FederateIO_Handler);
        
        
        ////    Framework operations    ////
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            FederateFrameworkType fedFrameworkType;		//## attribute fedFrameworkType 
            
        
        ////    Relations and components    ////
        protected :
            
            IO::FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.h
*********************************************************************/

