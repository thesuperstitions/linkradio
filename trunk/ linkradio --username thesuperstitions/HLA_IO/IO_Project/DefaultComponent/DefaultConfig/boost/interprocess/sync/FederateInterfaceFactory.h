/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::FederateInterfaceFactory
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FederateInterfaceFactory.h
*********************************************************************/


#ifndef boost_interprocess_sync_FederateInterfaceFactory_H 

#define boost_interprocess_sync_FederateInterfaceFactory_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "boost\interprocess\sync\Control.h"
// operation FederateInterfaceFactory(FederateFrameworkType) 
#include "boost\interprocess\sync\Framework.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\FederateInterfaceFactory.h                                                                  
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
            
            //## operation createFederateInterface(std::string,Framework::InterfaceType) 
            Framework::IO::FederateInterface* createFederateInterface(std::string name, Framework::InterfaceType interfaceType);
        
        
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
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FederateInterfaceFactory.h
*********************************************************************/

