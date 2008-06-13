/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FrameworkTester
//!	Generated Date	: Wed, 21, May 2008  
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
#include "FrameworkTest.h"
// dependency FrameworkFederateAmbassador 
#include "FrameworkFederateAmbassador.h"
// dependency C_IO_Functions 
#include "C_IO_Functions.h"
// dependency RtiAmbassador 
#include "RtiAmbassador.h"

//----------------------------------------------------------------------------
// FrameworkTester.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace Control {
        class HlaCecFederate;
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


////    Operations    ////
public :
    
    //## operation Configure_NTDS_Device(DEVICE_DATA *) 
    int Configure_NTDS_Device(DEVICE_DATA * devices_ptr);


////    Additional operations    ////
public :
    
    //## auto_generated 
    int getInterfaceCount() const;
    
    //## auto_generated 
    void setInterfaceCount(int p_interfaceCount);
    
    //## auto_generated 
    framework::Control::HlaCecFederate* getFederate_1() const;
    
    //## auto_generated 
    void setFederate_1(framework::Control::HlaCecFederate* p_HlaCecFederate);
    
    //## auto_generated 
    framework::Control::HlaCecFederate* getFederate_2() const;
    
    //## auto_generated 
    void setFederate_2(framework::Control::HlaCecFederate* p_HlaCecFederate);
    
    //## auto_generated 
    framework::FrameworkFederateAmbassador* getTheFrameworkFederateAmbassador() const;
    
    //## auto_generated 
    void setTheFrameworkFederateAmbassador(framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
    
    //## auto_generated 
    framework::RtiAmbassador* getTheRtiAmbassador() const;
    
    //## auto_generated 
    void setTheRtiAmbassador(framework::RtiAmbassador* p_RtiAmbassador);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
protected :
    
    int interfaceCount;		//## attribute interfaceCount 
    

////    Relations and components    ////
protected :
    
    framework::Control::HlaCecFederate* Federate_1;		//## link Federate_1 
    
    
    framework::Control::HlaCecFederate* Federate_2;		//## link Federate_2 
    
    
    framework::FrameworkFederateAmbassador* theFrameworkFederateAmbassador;		//## link theFrameworkFederateAmbassador 
    
    
    framework::RtiAmbassador* theRtiAmbassador;		//## link theRtiAmbassador 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkTester.h
*********************************************************************/

