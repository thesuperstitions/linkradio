/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::FrameworkFederateAmbassador
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FrameworkFederateAmbassador.cpp
*********************************************************************/

#include "boost\interprocess\sync\FrameworkFederateAmbassador.h"
// link itsHLA_PostOffice 
#include "boost\interprocess\sync\HLA_PostOffice.h"
// link itsRtiAmbassador 
#include "boost\interprocess\sync\RtiAmbassador.h"

//----------------------------------------------------------------------------
// boost\interprocess\sync\FrameworkFederateAmbassador.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework 

//## class FrameworkFederateAmbassador 


//#[ ignore 
using namespace std;
//#]
namespace Framework {
    
    
    FrameworkFederateAmbassador::FrameworkFederateAmbassador() {
        itsHLA_PostOffice = NULL;
        itsRtiAmbassador = NULL;
    }
    
    FrameworkFederateAmbassador::~FrameworkFederateAmbassador() {
        cleanUpRelations();
    }
    
    rti1516::InteractionClassHandle FrameworkFederateAmbassador::getInteractionClassHandle(std::wstring interactionName) {
        //#[ operation getInteractionClassHandle(std::wstring) 
        return( Framework::getTheRtiAmbassador()->getInteractionClassHandle(interactionName) );
        //#]
    }
    
    rti1516::ParameterHandle FrameworkFederateAmbassador::getParameterHandle(rti1516::InteractionClassHandle interactionClassHandle, std::wstring parameterName) {
        //#[ operation getParameterHandle(rti1516::InteractionClassHandle,std::wstring) 
        return ( getTheRtiAmbassador()->getParameterHandle(interactionClassHandle, parameterName) );
        //#]
    }
    
    void FrameworkFederateAmbassador::publishInteractionClass(rti1516::InteractionClassHandle theParameterValues) {
        //#[ operation publishInteractionClass(rti1516::InteractionClassHandle) 
        //#]
    }
    
    void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError ) {
        //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle,const rti1516::RegionHandleSet &) 
            receiveInteraction(theInteraction,
                  theParameterValues,
                  theUserSuppliedTag,
                  sentOrder,
                  theType);
        
        //#]
    }
    
    void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
        //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::RegionHandleSet &) 
           receiveInteraction(theInteraction,
                  theParameterValues,
                  theUserSuppliedTag,
                  sentOrder,
                  theType);
        
        //#]
    }
    
    void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
        //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType) 
           receiveInteraction(theInteraction,
                  theParameterValues,
                  theUserSuppliedTag,
                  sentOrder,
                  theType);
        
        //#]
    }
    
    void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516:: InteractionClassNotSubscribed, rti1516:: FederateInternalError ) {
        //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,const rti1516::RegionHandleSet &) 
           receiveInteraction(theInteraction,
                  theParameterValues,
                  theUserSuppliedTag,
                  sentOrder,
                  theType);
        //#]
    }
    
    void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError ) {
        //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle) 
           receiveInteraction(theInteraction,
                  theParameterValues,
                  theUserSuppliedTag,
                  sentOrder,
                  theType);
        
        //#]
    }
    
    void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
        //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType) 
        getItsHLA_PostOffice()->receiveInteraction(theInteraction, theParameterValues, theUserSuppliedTag, sentOrder, theType);
        //#]
    }
    
    void FrameworkFederateAmbassador::sendRO(rti1516::InteractionClassHandle interactionClassHandle, rti1516::ParameterHandle parameterHandle, char* interactionName, char* messageToSend) {
        //#[ operation sendRO(rti1516::InteractionClassHandle,rti1516::ParameterHandle,char*,char*) 
        
        rti1516::ParameterHandleValueMap map;
        rti1516::VariableLengthData tagData( interactionName, sizeof(interactionName)+1 );
        
        
        map[parameterHandle] = rti1516::VariableLengthData(&messageToSend, sizeof(messageToSend));
                              
        Framework::getTheRtiAmbassador()->sendInteraction( interactionClassHandle, map, tagData);
                              
        //#]
    }
    
    void FrameworkFederateAmbassador::sendTSO(rti1516::InteractionClassHandle interactionClassHandle, rti1516::ParameterHandle parameterHandle, char* interactionName, char* messageToSend) {
        //#[ operation sendTSO(rti1516::InteractionClassHandle,rti1516::ParameterHandle,char*,char*) 
        //#]
    }
    
    void FrameworkFederateAmbassador::subscribeInteractionClass(rti1516::InteractionClassHandle interactionClassHandle) {
        //#[ operation subscribeInteractionClass(rti1516::InteractionClassHandle) 
        Framework::getTheRtiAmbassador()->subscribeInteractionClass(interactionClassHandle);
        //#]
    }
    
    Framework::IO::HLA_PostOffice* FrameworkFederateAmbassador::getItsHLA_PostOffice() const {
        return itsHLA_PostOffice;
    }
    
    void FrameworkFederateAmbassador::__setItsHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
        itsHLA_PostOffice = p_HLA_PostOffice;
    }
    
    void FrameworkFederateAmbassador::_setItsHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
        if(itsHLA_PostOffice != NULL)
            {
                itsHLA_PostOffice->__setTheFrameworkFederateAmbassador(NULL);
            }
        __setItsHLA_PostOffice(p_HLA_PostOffice);
    }
    
    void FrameworkFederateAmbassador::setItsHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
        if(p_HLA_PostOffice != NULL)
            {
                p_HLA_PostOffice->_setTheFrameworkFederateAmbassador(this);
            }
        _setItsHLA_PostOffice(p_HLA_PostOffice);
    }
    
    void FrameworkFederateAmbassador::_clearItsHLA_PostOffice() {
        itsHLA_PostOffice = NULL;
    }
    
    Framework::RtiAmbassador* FrameworkFederateAmbassador::getItsRtiAmbassador() const {
        return itsRtiAmbassador;
    }
    
    void FrameworkFederateAmbassador::__setItsRtiAmbassador(Framework::RtiAmbassador* p_RtiAmbassador) {
        itsRtiAmbassador = p_RtiAmbassador;
    }
    
    void FrameworkFederateAmbassador::_setItsRtiAmbassador(Framework::RtiAmbassador* p_RtiAmbassador) {
        if(itsRtiAmbassador != NULL)
            {
                itsRtiAmbassador->__setItsFrameworkFederateAmbassador(NULL);
            }
        __setItsRtiAmbassador(p_RtiAmbassador);
    }
    
    void FrameworkFederateAmbassador::setItsRtiAmbassador(Framework::RtiAmbassador* p_RtiAmbassador) {
        if(p_RtiAmbassador != NULL)
            {
                p_RtiAmbassador->_setItsFrameworkFederateAmbassador(this);
            }
        _setItsRtiAmbassador(p_RtiAmbassador);
    }
    
    void FrameworkFederateAmbassador::_clearItsRtiAmbassador() {
        itsRtiAmbassador = NULL;
    }
    
    void FrameworkFederateAmbassador::cleanUpRelations() {
        if(itsHLA_PostOffice != NULL)
            {
                Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador = itsHLA_PostOffice->getTheFrameworkFederateAmbassador();
                if(p_FrameworkFederateAmbassador != NULL)
                    {
                        itsHLA_PostOffice->__setTheFrameworkFederateAmbassador(NULL);
                    }
                itsHLA_PostOffice = NULL;
            }
        if(itsRtiAmbassador != NULL)
            {
                Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador = itsRtiAmbassador->getItsFrameworkFederateAmbassador();
                if(p_FrameworkFederateAmbassador != NULL)
                    {
                        itsRtiAmbassador->__setItsFrameworkFederateAmbassador(NULL);
                    }
                itsRtiAmbassador = NULL;
            }
    }
    
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\boost\interprocess\sync\FrameworkFederateAmbassador.cpp
*********************************************************************/

