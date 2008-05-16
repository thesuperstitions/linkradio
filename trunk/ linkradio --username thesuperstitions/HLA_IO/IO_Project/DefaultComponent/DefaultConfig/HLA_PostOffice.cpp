/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::HLA_PostOffice
//!	Generated Date	: Thu, 15, May 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.cpp
*********************************************************************/

#include "HLA_PostOffice.h"
#include "Federate.h"
// operation HLA_PostOffice(FrameworkFederateAmbassador*) 
#include "FrameworkFederateAmbassador.h"
// operation receiveMessage(Buffer*,int) 
#include "Buffer.h"
// operation announcePublication(FederateInterface*) 
#include "FederateInterface.h"
// operation sendMessage(FederateMessage*) 
#include "FederateMessage.h"

//----------------------------------------------------------------------------
// HLA_PostOffice.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class HLA_PostOffice 

namespace Framework {
    namespace IO {
        
        
        HLA_PostOffice::HLA_PostOffice(FrameworkFederateAmbassador* frameworkFederateAmbassador) : theHLA_FederateInterface() {
            theFrameworkFederateAmbassador = NULL;
            //#[ operation HLA_PostOffice(FrameworkFederateAmbassador*) 
            setTheFrameworkFederateAmbassador(frameworkFederateAmbassador);
            //#]
        }
        
        HLA_PostOffice::HLA_PostOffice() : theHLA_FederateInterface() {
            theFrameworkFederateAmbassador = NULL;
        }
        
        HLA_PostOffice::~HLA_PostOffice() {
            cleanUpRelations();
        }
        
        void HLA_PostOffice::announcePublication(FederateInterface* interface) {
            //#[ operation announcePublication(FederateInterface*) 
            
            // If the Interaction has not been already created, create it.
            this->createInteractionClassHandle((HLA_FederateInterface*)interface);
            
            // Sign up to Publish on the interaction.
            Framework::getFrameworkFederateAmbassador()->publishInteractionClass((static_cast<HLA_FederateInterface*>(interface))->getInteractionClassHandle());
            //#]
        }
        
        void HLA_PostOffice::announceSubscription(FederateInterface* interface) {
            //#[ operation announceSubscription(FederateInterface*) 
            
            // If the Interaction has not been already created, create it.
            this->createInteractionClassHandle(static_cast<HLA_FederateInterface*>(interface));
            
            // Sign up to Subscribe to the interaction.
            getFrameworkFederateAmbassador()->subscribeInteractionClass(static_cast<HLA_FederateInterface*>(interface)->getInteractionClassHandle());
            //#]
        }
        
        void HLA_PostOffice::createInteractionClassHandle(HLA_FederateInterface* interface) {
            //#[ operation createInteractionClassHandle(HLA_FederateInterface*) 
            if (interface->getIsInteractionClassHandleSet() == false )
            {
              // Get the interaction class handle from the RTI ambassador then we map it to a string.
              interface->setInteractionClassHandle( getFrameworkFederateAmbassador()->getInteractionClassHandle( DtToWString(interface->getInterfaceName().c_str()) ) );
            
              // Map the HLA Federate Interface to the Interaction Class Handle.
              addTheHLA_FederateInterface( interface->getInteractionClassHandle(), interface ); 
              
              // Set the HLA Federate Interface's association to the HLA Post Office.  (This may not actually be used.)
              interface->setTheHLA_PostOffice(this);
            
              // Create a Parameter Handle.
              interface->setParamHandle(getFrameworkFederateAmbassador()->getParameterHandle( interface->getInteractionClassHandle(), DtToWString("Data")) );
             }
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType) 
                                           
            HLA_FederateInterface* hfi_ptr = getTheHLA_FederateInterface(theInteraction);
                                           
            // Build a FederateMessage from the interaction data.
            Framework::IO::FederateMessage* msg = new Framework::IO::FederateMessage(hfi_ptr, theParameterValues);
            //this->addTheMessage(reinterpret_cast<Framework::IO::Message*>(msg));
            
            // Send the Interaction Parameter to the FederateInterface (HLA_FederateInterface in this case).
            //todo            hfi_ptr->getItsFederateIO_Handler()->getItsFederateIO_InputThread()->addFederateMessage(msg);
            //#]
        }
        
        void HLA_PostOffice::receiveMessage(Buffer* buffer, int theInteraction) {
            //#[ operation receiveMessage(Buffer*,int) 
            //#]
        }
        
        void HLA_PostOffice::sendMessage(FrameworkMessage* message) {
            //#[ operation sendMessage(FrameworkMessage*) 
            //#]
        }
        
        void HLA_PostOffice::sendMessage(FederateMessage* message) {
            //#[ operation sendMessage(FederateMessage*) 
            HLA_FederateInterface* HLA_Interface = reinterpret_cast<HLA_FederateInterface*>(message->getFederateInterface());
            
            if (RealTimeMode() == true)
            {  
              getTheFrameworkFederateAmbassador()->sendRO(HLA_Interface->getInteractionClassHandle(), HLA_Interface->getParamHandle(), ((char*)HLA_Interface->getInterfaceName().c_str()), message->getmsgPtr());
            }
            else // Discrete Mode.
            {
              getTheFrameworkFederateAmbassador()->sendTSO(HLA_Interface->getInteractionClassHandle(), HLA_Interface->getParamHandle(), ((char*)HLA_Interface->getInterfaceName().c_str()), message->getmsgPtr());
            }
            //#]
        }
        
        void HLA_PostOffice::sendMessage(char* message, HLA_FederateInterface* hlaFederateInterface) {
            //#[ operation sendMessage(char*,HLA_FederateInterface*) 
            
            HLA_FederateInterface* HLA_Interface = reinterpret_cast<HLA_FederateInterface*>(message->getFederateInterface());
            
            if (RealTimeMode() == true)
            {  
              getTheFrameworkFederateAmbassador()->sendRO(hlaFederateInterfacee->getInteractionClassHandle(), hlaFederateInterface->getParamHandle(), ((char*)hlaFederateInterface->getInterfaceName().c_str()), message);
            }
            else // Discrete Mode.
            {
              getTheFrameworkFederateAmbassador()->sendTSO(hlaFederateInterfacee->getInteractionClassHandle(), hlaFederateInterfacee->getParamHandle(), ((char*)hlaFederateInterfacee->getInterfaceName().c_str()), message);
            }
            
            //#]
        }
        
        void HLA_PostOffice::unsubscribe(FederateInterface* interface) {
            //#[ operation unsubscribe(FederateInterface*) 
            //#]
        }
        
        Framework::FrameworkFederateAmbassador* HLA_PostOffice::getTheFrameworkFederateAmbassador() const {
            return theFrameworkFederateAmbassador;
        }
        
        void HLA_PostOffice::__setTheFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            theFrameworkFederateAmbassador = p_FrameworkFederateAmbassador;
        }
        
        void HLA_PostOffice::_setTheFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            if(theFrameworkFederateAmbassador != NULL)
                {
                    theFrameworkFederateAmbassador->__setItsHLA_PostOffice(NULL);
                }
            __setTheFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
        }
        
        void HLA_PostOffice::setTheFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            if(p_FrameworkFederateAmbassador != NULL)
                {
                    p_FrameworkFederateAmbassador->_setItsHLA_PostOffice(this);
                }
            _setTheFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
        }
        
        void HLA_PostOffice::_clearTheFrameworkFederateAmbassador() {
            theFrameworkFederateAmbassador = NULL;
        }
        
        std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator HLA_PostOffice::getTheHLA_FederateInterface() const {
            std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator iter;
            iter = theHLA_FederateInterface.begin();
            return iter;
        }
        
        std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator HLA_PostOffice::getTheHLA_FederateInterfaceEnd() const {
            return theHLA_FederateInterface.end();
        }
        
        void HLA_PostOffice::_clearTheHLA_FederateInterface() {
            theHLA_FederateInterface.clear();
        }
        
        void HLA_PostOffice::clearTheHLA_FederateInterface() {
            std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator iter;
            iter = theHLA_FederateInterface.begin();
            while (iter != theHLA_FederateInterface.end()){
                ((*iter).second)->_clearTheHLA_PostOffice();
                iter++;
            }
            _clearTheHLA_FederateInterface();
        }
        
        void HLA_PostOffice::_removeTheHLA_FederateInterface(Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::iterator pos = std::find_if(theHLA_FederateInterface.begin(), theHLA_FederateInterface.end(),OMValueCompare<const rti1516::InteractionClassHandle,Framework::IO::HLA_FederateInterface*>(p_HLA_FederateInterface));
            if (pos != theHLA_FederateInterface.end()) {
            	theHLA_FederateInterface.erase(pos);
            }
        }
        
        void HLA_PostOffice::removeTheHLA_FederateInterface(Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            if(p_HLA_FederateInterface != NULL)
                {
                    p_HLA_FederateInterface->__setTheHLA_PostOffice(NULL);
                }
            _removeTheHLA_FederateInterface(p_HLA_FederateInterface);
        }
        
        Framework::IO::HLA_FederateInterface* HLA_PostOffice::getTheHLA_FederateInterface(rti1516::InteractionClassHandle key) const {
            return (theHLA_FederateInterface.find(key) != theHLA_FederateInterface.end() ? (*theHLA_FederateInterface.find(key)).second : NULL);
        }
        
        void HLA_PostOffice::_addTheHLA_FederateInterface(rti1516::InteractionClassHandle key, Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            theHLA_FederateInterface.insert(std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::value_type(key, p_HLA_FederateInterface));
        }
        
        void HLA_PostOffice::addTheHLA_FederateInterface(rti1516::InteractionClassHandle key, Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            if(p_HLA_FederateInterface != NULL)
                {
                    p_HLA_FederateInterface->_setTheHLA_PostOffice(this);
                }
            _addTheHLA_FederateInterface(key, p_HLA_FederateInterface);
        }
        
        void HLA_PostOffice::_removeTheHLA_FederateInterface(rti1516::InteractionClassHandle key) {
            theHLA_FederateInterface.erase(key);
        }
        
        void HLA_PostOffice::removeTheHLA_FederateInterface(rti1516::InteractionClassHandle key) {
            Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface = getTheHLA_FederateInterface(key);
            if(p_HLA_FederateInterface != NULL)
                {
                    p_HLA_FederateInterface->_setTheHLA_PostOffice(NULL);
                }
            _removeTheHLA_FederateInterface(key);
        }
        
        void HLA_PostOffice::cleanUpRelations() {
            if(theFrameworkFederateAmbassador != NULL)
                {
                    Framework::IO::HLA_PostOffice* p_HLA_PostOffice = theFrameworkFederateAmbassador->getItsHLA_PostOffice();
                    if(p_HLA_PostOffice != NULL)
                        {
                            theFrameworkFederateAmbassador->__setItsHLA_PostOffice(NULL);
                        }
                    theFrameworkFederateAmbassador = NULL;
                }
            {
                std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator iter;
                iter = theHLA_FederateInterface.begin();
                while (iter != theHLA_FederateInterface.end()){
                    Framework::IO::HLA_PostOffice* p_HLA_PostOffice = ((*iter).second)->getTheHLA_PostOffice();
                    if(p_HLA_PostOffice != NULL)
                        {
                            ((*iter).second)->__setTheHLA_PostOffice(NULL);
                        }
                    iter++;
                }
                theHLA_FederateInterface.clear();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.cpp
*********************************************************************/

