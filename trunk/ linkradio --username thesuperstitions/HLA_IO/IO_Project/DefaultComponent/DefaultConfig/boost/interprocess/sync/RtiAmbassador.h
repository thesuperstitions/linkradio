/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::RtiAmbassador
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\RtiAmbassador.h
*********************************************************************/


#ifndef boost_interprocess_sync_RtiAmbassador_H 

#define boost_interprocess_sync_RtiAmbassador_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "boost\interprocess\sync\Framework.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\RtiAmbassador.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    class FrameworkFederateAmbassador;
}


//## package Framework 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    //## class RtiAmbassador 
    class RtiAmbassador  {
    
    
    ////    Constructors and destructors    ////
    public :
        
        //## operation RtiAmbassador(FrameworkFederateAmbassador*) 
        RtiAmbassador(FrameworkFederateAmbassador* frameworkFederateAmbassador);
        
        //## auto_generated 
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
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\RtiAmbassador.h
*********************************************************************/

