/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FrameworkTester
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FrameworkTester.cpp
*********************************************************************/

#include "boost\interprocess\sync\FrameworkTester.h"
// link Federate_1 
#include "boost\interprocess\sync\ExampleFederate.h"
// dependency FederateFrameworkType 
#include "boost\interprocess\sync\Framework.h"
// dependency C_IO_Functions 
#include "boost\interprocess\sync\C_IO_Functions.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\FrameworkTester.cpp                                                                  
//----------------------------------------------------------------------------

//## package FrameworkTest 

//## class FrameworkTester 



FrameworkTester::FrameworkTester() : interfaceCount(0) {
    Federate_1 = NULL;
    Federate_2 = NULL;
    theFrameworkFederateAmbassador = NULL;
    theRtiAmbassador = NULL;
    //#[ operation FrameworkTester() 
    
    DEVICE_DATA dd[2];
    
    if ( (theFrameworkFederateAmbassador = new Framework::FrameworkFederateAmbassador()) != NULL) 
    {
      theRtiAmbassador = new Framework::RtiAmbassador(theFrameworkFederateAmbassador);
    }
    
    Federate_1 = new Framework::Control::ExampleFederate(Framework::HLA_FederateFrameworkType, Framework::CEC_FederateType, getTheFrameworkFederateAmbassador());   
    
    Federate_2 = new Framework::Control::ExampleFederate(Framework::HLA_FederateFrameworkType, Framework::SSDS_FederateType, getTheFrameworkFederateAmbassador());   
    
    
    
    strcpy(dd[0].name_string, "spy");    
    strcpy(dd[1].name_string, "cnd");    
    Configure_NTDS_Device(&(dd[0]));          
        
    //#]
}

FrameworkTester::~FrameworkTester() {
    cleanUpRelations();
}

int FrameworkTester::Configure_NTDS_Device(DEVICE_DATA * devices_ptr) {
    //#[ operation Configure_NTDS_Device(DEVICE_DATA *) 
    
    char s[100];
                
    while (devices_ptr != NULL)
    {
      sprintf(s, "%s%u", devices_ptr->name_string, interfaceCount++);
      std::string myString = s;                               
      
      Framework::IO::C_IO_Functions::createInterface(myString);    
      
      devices_ptr++;
    };  
    
    return(OK);
    
    //#]
}

int FrameworkTester::getInterfaceCount() const {
    return interfaceCount;
}

void FrameworkTester::setInterfaceCount(int p_interfaceCount) {
    interfaceCount = p_interfaceCount;
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
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FrameworkTester.cpp
*********************************************************************/

