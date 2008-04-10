/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::RtiAmbassador
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.cpp
*********************************************************************/

#include "RtiAmbassador.h"
// link itsFrameworkFederateAmbassador 
#include "FrameworkFederateAmbassador.h"

//----------------------------------------------------------------------------
// RtiAmbassador.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class RtiAmbassador 

namespace Framework {
    namespace IO {
        
        
        RtiAmbassador::RtiAmbassador() {
            itsFrameworkFederateAmbassador = NULL;
        }
        
        RtiAmbassador::~RtiAmbassador() {
            cleanUpRelations();
        }
        
        Framework::FrameworkFederateAmbassador* RtiAmbassador::getItsFrameworkFederateAmbassador() const {
            return itsFrameworkFederateAmbassador;
        }
        
        void RtiAmbassador::__setItsFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            itsFrameworkFederateAmbassador = p_FrameworkFederateAmbassador;
        }
        
        void RtiAmbassador::_setItsFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            if(itsFrameworkFederateAmbassador != NULL)
                {
                    itsFrameworkFederateAmbassador->__setItsRtiAmbassador(NULL);
                }
            __setItsFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
        }
        
        void RtiAmbassador::setItsFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            if(p_FrameworkFederateAmbassador != NULL)
                {
                    p_FrameworkFederateAmbassador->_setItsRtiAmbassador(this);
                }
            _setItsFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
        }
        
        void RtiAmbassador::_clearItsFrameworkFederateAmbassador() {
            itsFrameworkFederateAmbassador = NULL;
        }
        
        void RtiAmbassador::cleanUpRelations() {
            if(itsFrameworkFederateAmbassador != NULL)
                {
                    Framework::IO::RtiAmbassador* p_RtiAmbassador = itsFrameworkFederateAmbassador->getItsRtiAmbassador();
                    if(p_RtiAmbassador != NULL)
                        {
                            itsFrameworkFederateAmbassador->__setItsRtiAmbassador(NULL);
                        }
                    itsFrameworkFederateAmbassador = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.cpp
*********************************************************************/

