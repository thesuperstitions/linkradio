/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::RtiAmbassador
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\RtiAmbassador.cpp
*********************************************************************/

#include "boost\interprocess\sync\RtiAmbassador.h"
// operation RtiAmbassador(FrameworkFederateAmbassador*) 
#include "boost\interprocess\sync\FrameworkFederateAmbassador.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\RtiAmbassador.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework 

//## class RtiAmbassador 

namespace Framework {
    
    
    RtiAmbassador::RtiAmbassador(FrameworkFederateAmbassador* frameworkFederateAmbassador) {
        itsFrameworkFederateAmbassador = NULL;
        //#[ operation RtiAmbassador(FrameworkFederateAmbassador*) 
        if (frameworkFederateAmbassador != NULL)
        {
        	setItsFrameworkFederateAmbassador(frameworkFederateAmbassador);  
        	frameworkFederateAmbassador->setItsRtiAmbassador(this); 
        }
        //#]
    }
    
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
                Framework::RtiAmbassador* p_RtiAmbassador = itsFrameworkFederateAmbassador->getItsRtiAmbassador();
                if(p_RtiAmbassador != NULL)
                    {
                        itsFrameworkFederateAmbassador->__setItsRtiAmbassador(NULL);
                    }
                itsFrameworkFederateAmbassador = NULL;
            }
    }
    
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\RtiAmbassador.cpp
*********************************************************************/

