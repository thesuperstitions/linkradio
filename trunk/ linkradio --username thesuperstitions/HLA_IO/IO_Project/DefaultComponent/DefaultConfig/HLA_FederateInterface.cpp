/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::HLA_FederateInterface
//!	Generated Date	: Tue, 13, May 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_FederateInterface.cpp
*********************************************************************/

#include "HLA_FederateInterface.h"
#include "FederateIO_Handler.h"
// link theHLA_PostOffice 
#include "HLA_PostOffice.h"
#include "InterprocessQueue.h"

//----------------------------------------------------------------------------
// HLA_FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class HLA_FederateInterface 

namespace Framework {
    namespace IO {
        
        
        HLA_FederateInterface::HLA_FederateInterface(std::string name, Framework::InterfaceType interfaceType) : isInteractionClassHandleSet(false) ,FederateInterface(name, interfaceType) {
            theHLA_PostOffice = NULL;
            //#[ operation HLA_FederateInterface(std::string,Framework::InterfaceType) 
            //#]
        }
        
        HLA_FederateInterface::~HLA_FederateInterface() {
            //#[ operation ~HLA_FederateInterface() 
            
            delete controlQueue;
            
            //#]
            cleanUpRelations();
        }
        
        void HLA_FederateInterface::setInteractionClassHandle(rti1516::InteractionClassHandle handle) {
            //#[ operation setInteractionClassHandle(rti1516::InteractionClassHandle) 
            interactionClassHandle = handle;
            isInteractionClassHandleSet = true;
            //#]
        }
        
        rti1516::InteractionClassHandle HLA_FederateInterface::getInteractionClassHandle() const {
            return interactionClassHandle;
        }
        
        bool HLA_FederateInterface::getIsInteractionClassHandleSet() const {
            return isInteractionClassHandleSet;
        }
        
        void HLA_FederateInterface::setIsInteractionClassHandleSet(bool p_isInteractionClassHandleSet) {
            isInteractionClassHandleSet = p_isInteractionClassHandleSet;
        }
        
        rti1516::ParameterHandle HLA_FederateInterface::getParamHandle() const {
            return paramHandle;
        }
        
        void HLA_FederateInterface::setParamHandle(rti1516::ParameterHandle p_paramHandle) {
            paramHandle = p_paramHandle;
        }
        
        Framework::IO::HLA_PostOffice* HLA_FederateInterface::getTheHLA_PostOffice() const {
            return theHLA_PostOffice;
        }
        
        void HLA_FederateInterface::__setTheHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
            theHLA_PostOffice = p_HLA_PostOffice;
        }
        
        void HLA_FederateInterface::_setTheHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
            if(theHLA_PostOffice != NULL)
                {
                    theHLA_PostOffice->_removeTheHLA_FederateInterface(this);
                }
            __setTheHLA_PostOffice(p_HLA_PostOffice);
        }
        
        void HLA_FederateInterface::setTheHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
            if(p_HLA_PostOffice != NULL)
                {
                    p_HLA_PostOffice->_addTheHLA_FederateInterface(getInteractionClassHandle(), this);
                }
            _setTheHLA_PostOffice(p_HLA_PostOffice);
        }
        
        void HLA_FederateInterface::_clearTheHLA_PostOffice() {
            theHLA_PostOffice = NULL;
        }
        
        void HLA_FederateInterface::cleanUpRelations() {
            if(theHLA_PostOffice != NULL)
                {
                    Framework::IO::HLA_PostOffice* current = theHLA_PostOffice;
                    if(current != NULL)
                        {
                            current->_removeTheHLA_FederateInterface(interactionClassHandle);
                        }
                    theHLA_PostOffice = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_FederateInterface.cpp
*********************************************************************/

