/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\framework.cpp
*********************************************************************/

#include "framework.h"
// operation getFrameworkFederateAmbassador() 
#include "FrameworkFederateAmbassador.h"

//----------------------------------------------------------------------------
// framework.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework 

namespace framework {
    
}

namespace framework {
    
    
    //## operation RealTimeMode() 
    bool RealTimeMode() {
        //#[ operation RealTimeMode() 
        return(true);
        //#]
    }
    
    //## operation getFrameworkFederateAmbassador() 
    FrameworkFederateAmbassador* getFrameworkFederateAmbassador() {
        //#[ operation getFrameworkFederateAmbassador() 
        return(&frameworkFederateAmbassador);
        //#]
    }
    
    //## operation getTheRtiAmbassador() 
    rti1516::RTIambassador* getTheRtiAmbassador() {
        //#[ operation getTheRtiAmbassador() 
        return(&rtiAmbassador);
        //#]
    }
    
    framework::FrameworkFederateAmbassador frameworkFederateAmbassador;
    
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\framework.cpp
*********************************************************************/

