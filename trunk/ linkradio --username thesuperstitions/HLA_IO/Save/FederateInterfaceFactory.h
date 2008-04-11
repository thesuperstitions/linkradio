//*********************************************************************************  
//
//	File:				Framework::IO::FederateInterfaceFactory  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Thu, 14, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef FederateInterfaceFactory_H 

#define FederateInterfaceFactory_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"
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


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
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
            Federate::Federate* getItsFederate() const;
            
            //## auto_generated 
            void setItsFederate(Federate::Federate* p_Federate);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederate(Federate::Federate* p_Federate);
            
            //## auto_generated 
            void _setItsFederate(Federate::Federate* p_Federate);
            
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
            
            Federate::Federate* itsFederate;		//## link itsFederate 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.h
*********************************************************************/

