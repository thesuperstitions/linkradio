/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FrameworkTester
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FrameworkTester.cpp
*********************************************************************/

#include "FrameworkTester.h"
// link Federate_1 
#include "HlaCecFederate.h"
// dependency FederateFrameworkType 
#include "framework.h"

//----------------------------------------------------------------------------
// FrameworkTester.cpp                                                                  
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
    
    if ( (theFrameworkFederateAmbassador = new framework::FrameworkFederateAmbassador()) != NULL) 
    {
      theRtiAmbassador = new framework::RtiAmbassador(theFrameworkFederateAmbassador);
    }
    
    Federate_1 = new framework::Control::ExampleFederate(framework::HLA_FederateFrameworkType, framework::CEC_FederateType, getTheFrameworkFederateAmbassador());   
    
    Federate_2 = new framework::Control::ExampleFederate(framework::HLA_FederateFrameworkType, framework::SSDS_FederateType, getTheFrameworkFederateAmbassador());   
    
    
    
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
    
    //    char s[100];
                
    while (devices_ptr != NULL)
    {
    //      sprintf(s, "%s%u", devices_ptr->name_string, interfaceCount++);
    //      std::string myString = s;                               
      
      framework::IO::C_IO_Functions::Configure_NTDS_Device(devices_ptr);    
      
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

framework::Control::HlaCecFederate* FrameworkTester::getFederate_1() const {
    return Federate_1;
}

void FrameworkTester::setFederate_1(framework::Control::HlaCecFederate* p_HlaCecFederate) {
    Federate_1 = p_HlaCecFederate;
}

framework::Control::HlaCecFederate* FrameworkTester::getFederate_2() const {
    return Federate_2;
}

void FrameworkTester::setFederate_2(framework::Control::HlaCecFederate* p_HlaCecFederate) {
    Federate_2 = p_HlaCecFederate;
}

framework::FrameworkFederateAmbassador* FrameworkTester::getTheFrameworkFederateAmbassador() const {
    return theFrameworkFederateAmbassador;
}

void FrameworkTester::setTheFrameworkFederateAmbassador(framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
    theFrameworkFederateAmbassador = p_FrameworkFederateAmbassador;
}

framework::RtiAmbassador* FrameworkTester::getTheRtiAmbassador() const {
    return theRtiAmbassador;
}

void FrameworkTester::setTheRtiAmbassador(framework::RtiAmbassador* p_RtiAmbassador) {
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

