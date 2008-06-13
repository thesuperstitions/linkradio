/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::RtiAmbassador
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.h
*********************************************************************/


#ifndef RtiAmbassador_H 

#define RtiAmbassador_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "framework.h"

//----------------------------------------------------------------------------
// RtiAmbassador.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    class FrameworkFederateAmbassador;
}


//## package framework 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
    //## class RtiAmbassador 
    class RtiAmbassador  {
    
    
    ////    Constructors and destructors    ////
    public :
        
        //## operation RtiAmbassador() 
        RtiAmbassador();
        
        //## auto_generated 
        ~RtiAmbassador();
    
    
    ////    Additional operations    ////
    public :
        
        //## auto_generated 
        FrameworkFederateAmbassador* getItsFrameworkFederateAmbassador() const;
        
        //## auto_generated 
        void setItsFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
    
    
    ////    Framework operations    ////
    public :
        
        //## auto_generated 
        void __setItsFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
        
        //## auto_generated 
        void _setItsFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
        
        //## auto_generated 
        void _clearItsFrameworkFederateAmbassador();
    
    protected :
        
        //## auto_generated 
        void cleanUpRelations();
    
    
    ////    Relations and components    ////
    protected :
        
        FrameworkFederateAmbassador* itsFrameworkFederateAmbassador;		//## link itsFrameworkFederateAmbassador 
        
    
    
    };
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.h
*********************************************************************/

