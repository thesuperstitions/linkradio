/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::RtiAmbassador
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.h
*********************************************************************/


#ifndef RtiAmbassador_H 

#define RtiAmbassador_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"

//----------------------------------------------------------------------------
// RtiAmbassador.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    class FrameworkFederateAmbassador;
}


//## package Framework::IO 


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
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.h
*********************************************************************/

