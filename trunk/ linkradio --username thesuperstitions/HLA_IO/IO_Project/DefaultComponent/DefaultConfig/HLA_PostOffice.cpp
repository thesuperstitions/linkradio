/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::HLA_PostOffice
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.cpp
*********************************************************************/

#include "HLA_PostOffice.h"
#include "Federate.h"
// link itsFrameworkFederateAmbassador 
#include "FrameworkFederateAmbassador.h"
// operation recvMessage(Buffer*,int) 
#include "Buffer.h"
// operation announceSubscription(FederateInterface*) 
#include "FederateInterface.h"
// operation sendMessage(FederateMessage*) 
#include "FederateMessage.h"
// operation createInteractionClassHandle(HLA_FederateInterface*) 
#include "HLA_FederateInterface.h"
#include "IO_Handler.h"
#include "Message.h"

//----------------------------------------------------------------------------
// HLA_PostOffice.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class HLA_PostOffice 

namespace Framework {
    namespace IO {
        
        
        HLA_PostOffice::HLA_PostOffice() : itsHLA_FederateInterface() {
            itsFrameworkFederateAmbassador = NULL;
        }
        
        HLA_PostOffice::~HLA_PostOffice() {
            cleanUpRelations();
        }
        
        void HLA_PostOffice::announceSubscription(FederateInterface* interface) {
            //#[ operation announceSubscription(FederateInterface*) 
            
            // If the Interaction has not been already created, create it.
            this->createInteractionClassHandle((HLA_FederateInterface*)interface);
            
            // Sign up to Subscribe to the interaction.
            getFrameworkFederateAmbassador()->subscribeInteractionClass((HLA_FederateInterface*)interface->getItsInteractionClassHandle());
            //#]
        }
        
        void HLA_PostOffice::createInteractionClassHandle(HLA_FederateInterface* interface) {
            //#[ operation createInteractionClassHandle(HLA_FederateInterface*) 
            if (interactionClassHandle != NULL)
            {
              // Get the interaction class handle from the RTI ambassador then we map it to a string.
              interface->setInteractionClassHandle( (getFrameworkFederateAmbassador()->getInteractionClassHandle(DtToWString(interface->getInterfaceName())) );
            
              // Map the HLA Federate Interface to the Interaction Class Handle.
              addItsHLA_FederateInterface( interface->getInteractionClassHandle(), interface ); 
              
              // Set the HLA Federate Interface's association to the HLA Post Office.  (This may not actually be used.)
              interface->addItsHLA_PostOffice(this);
            
              // Create a Parameter Handle.
              interface->setParamHandle(getFrameworkFederateAmbassador()->getParameterHandle( (HLA_FederateInterface*)interface->getInteractionClassHandle(), DtToWString("Data")) );
             }
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType) 
                        
            // Send the Interaction Parameter to the FederateInterface (HLA_FederateInterface in this case).
            getItsHLA_FederateInterface( interactionClassHandle)->processInteraction(theParameterValues) );
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::RegionHandleSet &) 
               receiveInteraction(theInteraction,
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType);
            
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType) 
               receiveInteraction(theInteraction,
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType);
            
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516:: InteractionClassNotSubscribed, rti1516:: FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,const rti1516::RegionHandleSet &) 
               receiveInteraction(theInteraction,
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType,
                      theTime,
                      receivedOrder);
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle) 
               receiveInteraction(theInteraction,
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType,
                      theTime,
                      receivedOrder);
            
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle,const rti1516::RegionHandleSet &) 
               receiveInteraction(theInteraction, 
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType,
                      theTime,
                      receivedOrder);  
            
            //#]
        }
        
        void HLA_PostOffice::recvMessage(Buffer* buffer, int theInteraction) {
            //#[ operation recvMessage(Buffer*,int) 
            //#]
        }
        
        void HLA_PostOffice::sendMessage(FrameworkMessage* message) {
            //#[ operation sendMessage(FrameworkMessage*) 
            //#]
        }
        
        void HLA_PostOffice::sendMessage(FederateMessage* message) {
            //#[ operation sendMessage(FederateMessage*) 
            //#]
        }
        
        void HLA_PostOffice::unsubscribe(FederateInterface* interface) {
            //#[ operation unsubscribe(FederateInterface*) 
            //#]
        }
        
        Framework::FrameworkFederateAmbassador* HLA_PostOffice::getItsFrameworkFederateAmbassador() const {
            return itsFrameworkFederateAmbassador;
        }
        
        void HLA_PostOffice::__setItsFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            itsFrameworkFederateAmbassador = p_FrameworkFederateAmbassador;
        }
        
        void HLA_PostOffice::_setItsFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            if(itsFrameworkFederateAmbassador != NULL)
                {
                    itsFrameworkFederateAmbassador->__setItsHLA_PostOffice(NULL);
                }
            __setItsFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
        }
        
        void HLA_PostOffice::setItsFrameworkFederateAmbassador(Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            if(p_FrameworkFederateAmbassador != NULL)
                {
                    p_FrameworkFederateAmbassador->_setItsHLA_PostOffice(this);
                }
            _setItsFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
        }
        
        void HLA_PostOffice::_clearItsFrameworkFederateAmbassador() {
            itsFrameworkFederateAmbassador = NULL;
        }
        
        OMIterator<Framework::IO::HLA_FederateInterface*> HLA_PostOffice::getItsHLA_FederateInterface() const {
            OMIterator<Framework::IO::HLA_FederateInterface*> iter(itsHLA_FederateInterface);
            return iter;
        }
        
        void HLA_PostOffice::_clearItsHLA_FederateInterface() {
            itsHLA_FederateInterface.removeAll();
        }
        
        void HLA_PostOffice::clearItsHLA_FederateInterface() {
            OMIterator<Framework::IO::HLA_FederateInterface*> iter(itsHLA_FederateInterface);
            while (*iter){
                (*iter)->_clearItsHLA_PostOffice();
                iter++;
            }
            _clearItsHLA_FederateInterface();
        }
        
        void HLA_PostOffice::_removeItsHLA_FederateInterface(Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            itsHLA_FederateInterface.remove(p_HLA_FederateInterface);
        }
        
        void HLA_PostOffice::removeItsHLA_FederateInterface(Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            if(p_HLA_FederateInterface != NULL)
                {
                    p_HLA_FederateInterface->__setItsHLA_PostOffice(NULL);
                }
            _removeItsHLA_FederateInterface(p_HLA_FederateInterface);
        }
        
        Framework::IO::HLA_FederateInterface* HLA_PostOffice::getItsHLA_FederateInterface(rti1516::InteractionClassHandle key) const {
            return itsHLA_FederateInterface.getKey(key);
        }
        
        void HLA_PostOffice::_addItsHLA_FederateInterface(rti1516::InteractionClassHandle key, Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            itsHLA_FederateInterface.add(key,p_HLA_FederateInterface);
        }
        
        void HLA_PostOffice::addItsHLA_FederateInterface(rti1516::InteractionClassHandle key, Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            if(p_HLA_FederateInterface != NULL)
                {
                    p_HLA_FederateInterface->_setItsHLA_PostOffice(this);
                }
            _addItsHLA_FederateInterface(key, p_HLA_FederateInterface);
        }
        
        void HLA_PostOffice::_removeItsHLA_FederateInterface(rti1516::InteractionClassHandle key) {
            itsHLA_FederateInterface.remove(key);
        }
        
        void HLA_PostOffice::removeItsHLA_FederateInterface(rti1516::InteractionClassHandle key) {
            Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface = getItsHLA_FederateInterface(key);
            if(p_HLA_FederateInterface != NULL)
                {
                    p_HLA_FederateInterface->_setItsHLA_PostOffice(NULL);
                }
            _removeItsHLA_FederateInterface(key);
        }
        
        void HLA_PostOffice::cleanUpRelations() {
            if(itsFrameworkFederateAmbassador != NULL)
                {
                    Framework::IO::HLA_PostOffice* p_HLA_PostOffice = itsFrameworkFederateAmbassador->getItsHLA_PostOffice();
                    if(p_HLA_PostOffice != NULL)
                        {
                            itsFrameworkFederateAmbassador->__setItsHLA_PostOffice(NULL);
                        }
                    itsFrameworkFederateAmbassador = NULL;
                }
            {
                OMIterator<Framework::IO::HLA_FederateInterface*> iter(itsHLA_FederateInterface);
                while (*iter){
                    Framework::IO::HLA_PostOffice* p_HLA_PostOffice = (*iter)->getItsHLA_PostOffice();
                    if(p_HLA_PostOffice != NULL)
                        {
                            (*iter)->__setItsHLA_PostOffice(NULL);
                        }
                    iter++;
                }
                itsHLA_FederateInterface.removeAll();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.cpp
*********************************************************************/

