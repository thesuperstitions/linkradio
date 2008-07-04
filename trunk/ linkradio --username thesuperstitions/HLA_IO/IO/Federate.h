/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control::Federate
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\Federate.h
*********************************************************************/


#ifndef Federate_H 

#define Federate_H 

#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Control.h"
// operation Federate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
#include "framework.h"
// dependency FederateIO_Handler 
#include "FederateIO_Handler.h"

//----------------------------------------------------------------------------
// Federate.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace Control {
        class FederateInterfaceFactory;
        
    } 
    
} 

namespace framework {
    class FrameworkFederateAmbassador;
    
} 

namespace framework {
    
    namespace io {
        class HLA_PostOffice;
        class PostOffice;
    }
    
}


//## package framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
    namespace Control {
        //## class Federate 
        class Federate  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation Federate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
            Federate(FederateFrameworkType fedFrameworkType, FederateType fedType, FrameworkFederateAmbassador* frameworkFederateAmbassador);
            
            //## auto_generated 
            ~Federate();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            io::FederateIO_Handler* getItsFederateIO_Handler() const;
            
            //## auto_generated 
            void setItsFederateIO_Handler(io::FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            io::PostOffice* getThePostOffice() const;
            
            //## auto_generated 
            void setThePostOffice(io::PostOffice* p_PostOffice);
        
        protected :
            
            //## auto_generated 
            FederateFrameworkType getFederateFrameworkType() const;
            
            //## auto_generated 
            void setFederateFrameworkType(FederateFrameworkType p_federateFrameworkType);
            
            //## auto_generated 
            FederateInterfaceFactory* getFederateInterfaceFactory() const;
            
            //## auto_generated 
            void setFederateInterfaceFactory(FederateInterfaceFactory* p_federateInterfaceFactory);
            
            //## auto_generated 
            int getFederateType() const;
            
            //## auto_generated 
            void setFederateType(int p_federateType);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederateIO_Handler(io::FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _setItsFederateIO_Handler(io::FederateIO_Handler* p_FederateIO_Handler);
            
            //## auto_generated 
            void _clearItsFederateIO_Handler();
            
            //## auto_generated 
            void __setThePostOffice(io::PostOffice* p_PostOffice);
            
            //## auto_generated 
            void _setThePostOffice(io::PostOffice* p_PostOffice);
            
            //## auto_generated 
            void _clearThePostOffice();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            FederateFrameworkType federateFrameworkType;		//## attribute federateFrameworkType 
            
            FederateInterfaceFactory* federateInterfaceFactory;		//## attribute federateInterfaceFactory 
            
            int federateType;		//## attribute federateType 
            
        
        ////    Relations and components    ////
        protected :
            
            io::FederateIO_Handler* itsFederateIO_Handler;		//## link itsFederateIO_Handler 
            
            
            io::PostOffice* thePostOffice;		//## link thePostOffice 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Federate.h
*********************************************************************/

