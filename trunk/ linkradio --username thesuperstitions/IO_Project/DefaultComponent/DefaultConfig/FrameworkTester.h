/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FrameworkTester
//!	Generated Date	: Tue, 1, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FrameworkTester.h
*********************************************************************/


#ifndef FrameworkTester_H 

#define FrameworkTester_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
// dependency FrameworkFederateAmbassador 
#include "FrameworkFederateAmbassador.h"
// dependency RtiAmbassador 
#include "RtiAmbassador.h"

//----------------------------------------------------------------------------
// FrameworkTester.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class ExampleFederate;
    }
    
}


//## package FrameworkTest 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

//## class FrameworkTester 
class FrameworkTester  {


////    Constructors and destructors    ////
public :
    
    //## operation FrameworkTester() 
    FrameworkTester();
    
    //## auto_generated 
    ~FrameworkTester();


////    Additional operations    ////
public :
    
    //## auto_generated 
    Framework::Control::ExampleFederate* getFederate_1() const;
    
    //## auto_generated 
    void setFederate_1(Framework::Control::ExampleFederate* p_ExampleFederate);
    
    //## auto_generated 
    Framework::Control::ExampleFederate* getFederate_2() const;
    
    //## auto_generated 
    void setFederate_2(Framework::Control::ExampleFederate* p_ExampleFederate);
    
    //## auto_generated 
    Framework::FrameworkFederateAmbassador* getTheFrameworkFederateAmbassador() const;
    
    //## auto_generated 
    void setTheFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
    
    //## auto_generated 
    Framework::RtiAmbassador* getTheRtiAmbassador() const;
    
    //## auto_generated 
    void setTheRtiAmbassador(Framework::RtiAmbassador* p_RtiAmbassador);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
protected :
    
    Framework::Control::ExampleFederate* Federate_1;		//## link Federate_1 
    
    
    Framework::Control::ExampleFederate* Federate_2;		//## link Federate_2 
    
    
    Framework::FrameworkFederateAmbassador* theFrameworkFederateAmbassador;		//## link theFrameworkFederateAmbassador 
    
    
    Framework::RtiAmbassador* theRtiAmbassador;		//## link theRtiAmbassador 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkTester.h
*********************************************************************/

