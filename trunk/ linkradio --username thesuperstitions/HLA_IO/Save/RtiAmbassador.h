//*********************************************************************************  
//
//	File:				Framework::IO::RtiAmbassador  
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



#ifndef RtiAmbassador_H 

#define RtiAmbassador_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"

//----------------------------------------------------------------------------
// RtiAmbassador.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class FrameworkFederateAmbassador;
    }
    
}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class RtiAmbassador 
        class RtiAmbassador  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            RtiAmbassador();
            
            //## auto_generated 
            ~RtiAmbassador();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Control::FrameworkFederateAmbassador* getItsFrameworkFederateAmbassador() const;
            
            //## auto_generated 
            void setItsFrameworkFederateAmbassador(Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFrameworkFederateAmbassador(Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            void _setItsFrameworkFederateAmbassador(Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            void _clearItsFrameworkFederateAmbassador();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Control::FrameworkFederateAmbassador* itsFrameworkFederateAmbassador;		//## link itsFrameworkFederateAmbassador 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.h
*********************************************************************/

