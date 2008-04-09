//*********************************************************************************  
//
//	File:				Framework::IO::HLA_PostOffice  
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


#include "HLA_PostOffice.h"
// link itsFrameworkFederateAmbassador 
#include "FrameworkFederateAmbassador.h"
#include "Federate.h"
// operation recvMessage(Buffer*,int) 
#include "Buffer.h"
// operation announcePublication(FederateInterface*) 
#include "FederateInterface.h"
// operation sendMessage(FederateMessage*) 
#include "FederateMessage.h"
#include "IO_Handler.h"

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
        
        void HLA_PostOffice::announcePublication(FederateInterface* interface) {
            //#[ operation announcePublication(FederateInterface*) 
            
            // If the Interaction has not been already created, create it.
            this->createInteractionClassHandle((HLA_FederateInterface*)interface);
            
            // Sign up to Publish on the interaction.
            (HLA_FederateInterface*)interface->getFrameworkFederateAmbassador()->publishInteractionClass((HLA_FederateInterface*)interface->getInteractionClassHandle());
            //#]
        }
        
        void HLA_PostOffice::announceSubscription(FederateInterface* interface) {
            //#[ operation announceSubscription(FederateInterface*) 
            
            // If the Interaction has not been already created, create it.
            this->createInteractionClassHandle((HLA_FederateInterface*)interface);
            
            // Sign up to Subscribe to the interaction.
            (HLA_FederateInterface*)interface->getFrameworkFederateAmbassador()->subscribeInteractionClass((HLA_FederateInterface*)interface->getInteractionClassHandle());
            //#]
        }
        
        void HLA_PostOffice::createInteractionClassHandle(HLA_FederateInterface* interface) {
            //#[ operation createInteractionClassHandle(HLA_FederateInterface*) 
            if (interactionClassHandle != NULL)
            {
              // I'm assuming that the FrameworkFederateAmbassador is a singleton and available in this manner.  
              interface->setRtiAmbassador(getRtiAmbassador());
                                               
              // Set the association between the HLA_FederateInterface and the Framework Federate Ambassador.
              interface->setFrameworkFederateAmbassador( getFrameworkFederateAmbassador() ); 
            
              // Get the interaction class handle from the RTI ambassador then we map it to a string.
              interface->setInteractionClassHandle( (getRtiAmbassador()->getInteractionClassHandle(DtToWString(interface->getInterfaceName())) );
            
              // Map the HLA Federate Interface to the Interaction Class Handle.
              addItsHLA_FederateInterface( interface->getInteractionClassHandle(), interface ); 
              
              // Set the HLA Federate Interface's association to the HLA Post Office.  (This may not actually be used.)
              interface->addItsHLA_PostOffice(this);
            
              // Create a Parameter Handle.
              interface->setParamHandle(getRtiAmbassador()->getParameterHandle( (HLA_FederateInterface*)interface->getInteractionClassHandle(), DtToWString("Data")) );
             }
            //#]
        }
        
        void HLA_PostOffice::processInteraction(const ParameterHandleValueMap & theParameterValues) {
            //#[ operation processInteraction(const ParameterHandleValueMap &) 
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType) 
            this->processInteraction(theParameterValues);
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const RegionHandleSet &) 
               receiveInteraction(theInteraction,
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType);
            
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType) 
               receiveInteraction(theInteraction,
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType);
            
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,const RegionHandleSet &) 
               receiveInteraction(theInteraction,
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType,
                      theTime,
                      receivedOrder);
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, MessageRetractionHandle theHandle) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, InvalidLogicalTime, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,MessageRetractionHandle) 
               receiveInteraction(theInteraction,
                      theParameterValues,
                      theUserSuppliedTag,
                      sentOrder,
                      theType,
                      theTime,
                      receivedOrder);
            
            //#]
        }
        
        void HLA_PostOffice::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, MessageRetractionHandle theHandle, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, InvalidLogicalTime, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,MessageRetractionHandle,const RegionHandleSet &) 
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
        
        Framework::Control::FrameworkFederateAmbassador* HLA_PostOffice::getItsFrameworkFederateAmbassador() const {
            return itsFrameworkFederateAmbassador;
        }
        
        void HLA_PostOffice::__setItsFrameworkFederateAmbassador(Framework::Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            itsFrameworkFederateAmbassador = p_FrameworkFederateAmbassador;
        }
        
        void HLA_PostOffice::_setItsFrameworkFederateAmbassador(Framework::Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            if(itsFrameworkFederateAmbassador != NULL)
                {
                    itsFrameworkFederateAmbassador->__setItsHLA_PostOffice(NULL);
                }
            __setItsFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
        }
        
        void HLA_PostOffice::setItsFrameworkFederateAmbassador(Framework::Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador) {
            if(p_FrameworkFederateAmbassador != NULL)
                {
                    p_FrameworkFederateAmbassador->_setItsHLA_PostOffice(this);
                }
            _setItsFrameworkFederateAmbassador(p_FrameworkFederateAmbassador);
        }
        
        void HLA_PostOffice::_clearItsFrameworkFederateAmbassador() {
            itsFrameworkFederateAmbassador = NULL;
        }
        
        std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator HLA_PostOffice::getItsHLA_FederateInterface() const {
            std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator iter;
            iter = itsHLA_FederateInterface.begin();
            return iter;
        }
        
        std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator HLA_PostOffice::getItsHLA_FederateInterfaceEnd() const {
            return itsHLA_FederateInterface.end();
        }
        
        void HLA_PostOffice::_clearItsHLA_FederateInterface() {
            itsHLA_FederateInterface.clear();
        }
        
        void HLA_PostOffice::clearItsHLA_FederateInterface() {
            std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator iter;
            iter = itsHLA_FederateInterface.begin();
            while (iter != itsHLA_FederateInterface.end()){
                ((*iter).second)->_clearItsHLA_PostOffice();
                iter++;
            }
            _clearItsHLA_FederateInterface();
        }
        
        void HLA_PostOffice::_removeItsHLA_FederateInterface(Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::iterator pos = std::find_if(itsHLA_FederateInterface.begin(), itsHLA_FederateInterface.end(),OMValueCompare<const rti1516::InteractionClassHandle,Framework::IO::HLA_FederateInterface*>(p_HLA_FederateInterface));
            if (pos != itsHLA_FederateInterface.end()) {
            	itsHLA_FederateInterface.erase(pos);
            }
        }
        
        void HLA_PostOffice::removeItsHLA_FederateInterface(Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            if(p_HLA_FederateInterface != NULL)
                {
                    p_HLA_FederateInterface->__setItsHLA_PostOffice(NULL);
                }
            _removeItsHLA_FederateInterface(p_HLA_FederateInterface);
        }
        
        Framework::IO::HLA_FederateInterface* HLA_PostOffice::getItsHLA_FederateInterface(rti1516::InteractionClassHandle key) const {
            return (itsHLA_FederateInterface.find(key) != itsHLA_FederateInterface.end() ? (*itsHLA_FederateInterface.find(key)).second : NULL);
        }
        
        void HLA_PostOffice::_addItsHLA_FederateInterface(rti1516::InteractionClassHandle key, Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            itsHLA_FederateInterface.insert(std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::value_type(key, p_HLA_FederateInterface));
        }
        
        void HLA_PostOffice::addItsHLA_FederateInterface(rti1516::InteractionClassHandle key, Framework::IO::HLA_FederateInterface* p_HLA_FederateInterface) {
            if(p_HLA_FederateInterface != NULL)
                {
                    p_HLA_FederateInterface->_setItsHLA_PostOffice(this);
                }
            _addItsHLA_FederateInterface(key, p_HLA_FederateInterface);
        }
        
        void HLA_PostOffice::_removeItsHLA_FederateInterface(rti1516::InteractionClassHandle key) {
            itsHLA_FederateInterface.erase(key);
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
                std::map<rti1516::InteractionClassHandle, Framework::IO::HLA_FederateInterface*>::const_iterator iter;
                iter = itsHLA_FederateInterface.begin();
                while (iter != itsHLA_FederateInterface.end()){
                    Framework::IO::HLA_PostOffice* p_HLA_PostOffice = ((*iter).second)->getItsHLA_PostOffice();
                    if(p_HLA_PostOffice != NULL)
                        {
                            ((*iter).second)->__setItsHLA_PostOffice(NULL);
                        }
                    iter++;
                }
                itsHLA_FederateInterface.clear();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.cpp
*********************************************************************/

