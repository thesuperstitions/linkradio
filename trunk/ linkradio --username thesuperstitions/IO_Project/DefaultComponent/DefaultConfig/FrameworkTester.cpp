/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FrameworkTester
//!	Generated Date	: Tue, 1, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FrameworkTester.cpp
*********************************************************************/

#include "FrameworkTester.h"
// link Federate_1 
#include "ExampleFederate.h"
// dependency FederateFrameworkType 
#include "Framework.h"

//----------------------------------------------------------------------------
// FrameworkTester.cpp                                                                  
//----------------------------------------------------------------------------

//## package FrameworkTest 

//## class FrameworkTester 



FrameworkTester::FrameworkTester() {
    Federate_1 = NULL;
    Federate_2 = NULL;
    theFrameworkFederateAmbassador = NULL;
    theRtiAmbassador = NULL;
    //#[ operation FrameworkTester() 
    if ( (theFrameworkFederateAmbassador = new Framework::FrameworkFederateAmbassador()) != NULL) 
    {
      theRtiAmbassador = new Framework::RtiAmbassador(theFrameworkFederateAmbassador);
    }
    
    Federate_1 = new Framework::Control::ExampleFederate(Framework::HLA_FederateFrameworkType, Framework::CEC_FederateType, getTheFrameworkFederateAmbassador());   
    
    Federate_2 = new Framework::Control::ExampleFederate(Framework::HLA_FederateFrameworkType, Framework::SSDS_FederateType, getTheFrameworkFederateAmbassador());   
    //#]
}

FrameworkTester::~FrameworkTester() {
    cleanUpRelations();
}

Framework::Control::ExampleFederate* FrameworkTester::getFederate_1() const {
    return Federate_1;
}

void FrameworkTester::setFederate_1(Framework::Control::ExampleFederate* p_ExampleFederate) {
    Federate_1 = p_ExampleFederate;
}

Framework::Control::ExampleFederate* FrameworkTester::getFederate_2() const {
    return Federate_2;
}

void FrameworkTester::setFederate_2(Framework::Control::ExampleFederate* p_ExampleFederate) {
    Federate_2 = p_ExampleFederate;
}

Framework::FrameworkFederateAmbassador* FrameworkTester::getTheFrameworkFederateAmbassador() const {
    return theFrameworkFederateAmbassador;
}

void FrameworkTester::setTheFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
    theFrameworkFederateAmbassador = p_FrameworkFederateAmbassador;
}

Framework::RtiAmbassador* FrameworkTester::getTheRtiAmbassador() const {
    return theRtiAmbassador;
}

void FrameworkTester::setTheRtiAmbassador(Framework::RtiAmbassador* p_RtiAmbassador) {
    theRtiAmbassador = p_RtiAmbassador;
}

void FrameworkTester::cleanUpRelations() {
    if(Federate_1 != NULL)
        {
            Federate_1 = NULL;
        }
    if(Federate_2 != NULL)
        {
            Federate_2 = NULL;
        }
    if(theFrameworkFederateAmbassador != NULL)
        {
            theFrameworkFederateAmbassador = NULL;
        }
    if(theRtiAmbassador != NULL)
        {
            theRtiAmbassador = NULL;
        }
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkTester.cpp
*********************************************************************/

