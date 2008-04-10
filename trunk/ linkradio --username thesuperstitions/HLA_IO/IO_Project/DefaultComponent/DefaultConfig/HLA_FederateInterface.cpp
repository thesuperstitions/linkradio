/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::HLA_FederateInterface
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_FederateInterface.cpp
*********************************************************************/

#include "HLA_FederateInterface.h"
// link itsHLA_PostOffice 
#include "HLA_PostOffice.h"

//----------------------------------------------------------------------------
// HLA_FederateInterface.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class HLA_FederateInterface 

namespace Framework {
    namespace IO {
        
        
        HLA_FederateInterface::HLA_FederateInterface(std::string interfaceName) : interactionClassHandle(NULL) ,paramHandle(NULL) ,FederateInterface(interfaceName) {
            itsHLA_PostOffice = NULL;
            //#[ operation HLA_FederateInterface(std::string) 
            //#]
        }
        
        HLA_FederateInterface::~HLA_FederateInterface() {
            cleanUpRelations();
        }
        
        void HLA_FederateInterface::announcePublication(FederateInterface* interface) {
            //#[ operation announcePublication(FederateInterface*) 
            
            // If the Interaction has not been already created, create it.
            this->createInteractionClassHandle((HLA_FederateInterface*)interface);
            
            // Sign up to Publish on the interaction.
            (HLA_FederateInterface*)interface->getFrameworkFederateAmbassador()->publishInteractionClass((HLA_FederateInterface*)interface->getInteractionClassHandle());
            //#]
        }
        
        void HLA_FederateInterface::processInteraction(int argument_0) {
            //#[ operation processInteraction(int) 
            //#]
        }
        
        rti1516::VariableLengthData HLA_FederateInterface::getData() const {
            return data;
        }
        
        void HLA_FederateInterface::setData(rti1516::VariableLengthData p_data) {
            data = p_data;
        }
        
        rti1516::InteractionClassHandle HLA_FederateInterface::getInteractionClassHandle() const {
            return interactionClassHandle;
        }
        
        void HLA_FederateInterface::setInteractionClassHandle(rti1516::InteractionClassHandle p_interactionClassHandle) {
            interactionClassHandle = p_interactionClassHandle;
        }
        
        rti1516::ParameterHandle HLA_FederateInterface::getParamHandle() const {
            return paramHandle;
        }
        
        void HLA_FederateInterface::setParamHandle(rti1516::ParameterHandle p_paramHandle) {
            paramHandle = p_paramHandle;
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

