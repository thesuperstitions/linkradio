/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Federate::FederateInterfaceFactory
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.h
*********************************************************************/


#ifndef FederateInterfaceFactory_H 

#define FederateInterfaceFactory_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
// operation FederateInterfaceFactory(FederateFrameworkType) 
#include "Framework.h"

//----------------------------------------------------------------------------
// FederateInterfaceFactory.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Federate {
        class Federate;
        
    } 
    
namespace IO {
    class FederateInterface;
}

}


//## package Framework::Federate 


namespace Framework {
    namespace Federate {
        //## class FederateInterfaceFactory 
        class FederateInterfaceFactory  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation FederateInterfaceFactory(FederateFrameworkType) 
            FederateInterfaceFactory(FederateFrameworkType fedFrameworkType);
            
            //## auto_generated 
            FederateInterfaceFactory();
            
            //## auto_generated 
            ~FederateInterfaceFactory();
        
        
        ////    Operations    ////
        public :
            
            //## operation createFederateInterface(std::string) 
            FederateInterface* createFederateInterface(std::string name);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateFrameworkType getFederateFrameworkType() const;
            
            //## auto_generated 
            void setFederateFrameworkType(FederateFrameworkType p_federateFrameworkType);
            
            //## auto_generated 
            Federate* getItsFederate() const;
            
            //## auto_generated 
            void setItsFederate(Federate* p_Federate);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederate(Federate* p_Federate);
            
            //## auto_generated 
            void _setItsFederate(Federate* p_Federate);
            
            //## auto_generated 
            void _clearItsFederate();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            FederateFrameworkType federateFrameworkType;		//## attribute federateFrameworkType 
            
        
        ////    Relations and components    ////
        protected :
            
            Federate* itsFederate;		//## link itsFederate 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.h
*********************************************************************/

