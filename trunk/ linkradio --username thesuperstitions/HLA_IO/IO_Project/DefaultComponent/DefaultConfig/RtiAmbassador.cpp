/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::RtiAmbassador
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.cpp
*********************************************************************/

#include "RtiAmbassador.h"
// link itsFrameworkFederateAmbassador 
#include "FrameworkFederateAmbassador.h"

//----------------------------------------------------------------------------
// RtiAmbassador.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework 

//## class RtiAmbassador 

namespace framework {
    
    
    RtiAmbassador::RtiAmbassador() {
        itsFrameworkFederateAmbassador = NULL;
        //#[ operation RtiAmbassador() 
        
        setItsFrameworkFederateAmbassador(getFrameworkFederateAmbassador());  
        frameworkFederateAmbassador->setItsRtiAmbassador(this); 
        
        //#]
    }
    
    RtiAmbassador::~RtiAmbassador() {
        cleanUpRelations();
    }
    
    framework::FrameworkFederateAmbassador* RtiAmbassador::getItsFrameworkFederateAmbassador() const {
        return itsFrameworkFederateAmbassador;
    }
    
    void RtiAmbassador::__setItsFrameworkFederateAmbassador(framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
        itsFrameworkFederateAmbassador = p_FrameworkFederateAmbassador;
    }
    
    void RtiAmbassador::_setItsFrameworkFederateAmbassador(framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
        if(itsFrameworkFederateAmbassador != NULL)
            {
                itsFrameworkFederateAmbassador->__setItsRtiAmbassador(NULL);
            }
        __setItsFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
    }
    
    void RtiAmbassador::setItsFrameworkFederateAmbassador(framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
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
                framework::RtiAmbassador* p_RtiAmbassador = itsFrameworkFederateAmbassador->getItsRtiAmbassador();
                if(p_RtiAmbassador != NULL)
                    {
                        itsFrameworkFederateAmbassador->__setItsRtiAmbassador(NULL);
                    }
                itsFrameworkFederateAmbassador = NULL;
            }
    }
    
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RtiAmbassador.cpp
*********************************************************************/

