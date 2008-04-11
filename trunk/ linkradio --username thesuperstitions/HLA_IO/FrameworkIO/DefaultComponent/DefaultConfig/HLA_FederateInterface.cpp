//*********************************************************************************  
//
//	File:				Framework::IO::HLA_FederateInterface  
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


#include "HLA_FederateInterface.h"
// attribute frameworkFederateAmbassador 
#include "FrameworkFederateAmbassador.h"
// link itsHLA_PostOffice 
#include "HLA_PostOffice.h"

//----------------------------------------------------------------------------
// HLA_FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class HLA_FederateInterface 

namespace Framework {
    namespace IO {
        
        
        HLA_FederateInterface::HLA_FederateInterface(std::string interfaceName) : interactionClassHandle(NULL) ,paramHandle(NULL) ,rtiAmbassador(NULL) ,FederateInterface(interfaceName) {
            itsHLA_PostOffice = NULL;
            //#[ operation HLA_FederateInterface(std::string) 
            //#]
        }
        
        HLA_FederateInterface::~HLA_FederateInterface() {
            cleanUpRelations();
        }
        
        FederateInterface HLA_FederateInterface::instance() {
            //#[ operation instance() 
            static FederateInterface processor;
            return processor;
            //#]
        }
        
        VariableLengthData HLA_FederateInterface::getData() const {
            return data;
        }
        
        void HLA_FederateInterface::setData(VariableLengthData p_data) {
            data = p_data;
        }
        
        FrameworkFederateAmbassador* HLA_FederateInterface::getFrameworkFederateAmbassador() const {
            return frameworkFederateAmbassador;
        }
        
        void HLA_FederateInterface::setFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_frameworkFederateAmbassador) {
            frameworkFederateAmbassador = p_frameworkFederateAmbassador;
        }
        
        rti1516::InteractionClassHandle HLA_FederateInterface::getInteractionClassHandle() const {
            return interactionClassHandle;
        }
        
        void HLA_FederateInterface::setInteractionClassHandle(rti1516::InteractionClassHandle p_interactionClassHandle) {
            interactionClassHandle = p_interactionClassHandle;
        }
        
        parameterHandle HLA_FederateInterface::getParamHandle() const {
            return paramHandle;
        }
        
        void HLA_FederateInterface::setParamHandle(parameterHandle p_paramHandle) {
            paramHandle = p_paramHandle;
        }
        
        RTIambassador * HLA_FederateInterface::getRtiAmbassador() const {
            return rtiAmbassador;
        }
        
        void HLA_FederateInterface::setRtiAmbassador(RTIambassador * p_rtiAmbassador) {
            rtiAmbassador = p_rtiAmbassador;
        }
        
        Framework::IO::HLA_PostOffice* HLA_FederateInterface::getItsHLA_PostOffice() const {
            return itsHLA_PostOffice;
        }
        
        void HLA_FederateInterface::__setItsHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
            itsHLA_PostOffice = p_HLA_PostOffice;
        }
        
        void HLA_FederateInterface::_setItsHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
            if(itsHLA_PostOffice != NULL)
                {
                    itsHLA_PostOffice->_removeItsHLA_FederateInterface(this);
                }
            __setItsHLA_PostOffice(p_HLA_PostOffice);
        }
        
        void HLA_FederateInterface::setItsHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
            if(p_HLA_PostOffice != NULL)
                {
                    p_HLA_PostOffice->_addItsHLA_FederateInterface(getInteractionClassHandle(), this);
                }
            _setItsHLA_PostOffice(p_HLA_PostOffice);
        }
        
        void HLA_FederateInterface::_clearItsHLA_PostOffice() {
            itsHLA_PostOffice = NULL;
        }
        
        void HLA_FederateInterface::cleanUpRelations() {
            if(itsHLA_PostOffice != NULL)
                {
                    Framework::IO::HLA_PostOffice* current = itsHLA_PostOffice;
                    if(current != NULL)
                        {
                            current->_removeItsHLA_FederateInterface(interactionClassHandle);
                        }
                    itsHLA_PostOffice = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_FederateInterface.cpp
*********************************************************************/

