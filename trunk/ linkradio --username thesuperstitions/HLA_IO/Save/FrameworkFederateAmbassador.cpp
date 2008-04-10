//*********************************************************************************  
//
//	File:				Framework::Control::FrameworkFederateAmbassador  
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


#include "FrameworkFederateAmbassador.h"
// link itsHLA_PostOffice 
#include "HLA_PostOffice.h"
// link itsRtiAmbassador 
#include "RtiAmbassador.h"

//----------------------------------------------------------------------------
// FrameworkFederateAmbassador.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::Control 

//## class FrameworkFederateAmbassador 

namespace Framework {
    namespace Control {
        
        
        FrameworkFederateAmbassador::FrameworkFederateAmbassador() {
            itsHLA_PostOffice = NULL;
            itsRtiAmbassador = NULL;
        }
        
        FrameworkFederateAmbassador::~FrameworkFederateAmbassador() {
            cleanUpRelations();
        }
        
        void FrameworkFederateAmbassador::publishInteractionClass(InteractionClassHandle theHandle) {
            //#[ operation publishInteractionClass(InteractionClassHandle) 
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType) 
            getItsHLA_PostOffice()->receiveInteraction(theInteraction, theParameterValues, theUserSuppliedTag, sentOrder, theType);
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const RegionHandleSet &) 
            getItsHLA_PostOffice()->receiveInteraction(theInteraction, theParameterValues, theUserSuppliedTag, sentOrder, theType, theSentRegionHandleSet);
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType) 
            getItsHLA_PostOffice()->receiveInteraction(theInteraction, theParameterValues, theUserSuppliedTag, sentOrder, theType, theTime, receivedOrder);
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,const RegionHandleSet &) 
            getItsHLA_PostOffice()->receiveInteraction(theInteraction, theParameterValues, theUserSuppliedTag, sentOrder, theType, theTime, receivedOrder, theSentRegionHandleSet);
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, MessageRetractionHandle theHandle) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, InvalidLogicalTime, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,MessageRetractionHandle) 
            getItsHLA_PostOffice()->receiveInteraction(theInteraction, theParameterValues, theUserSuppliedTag, sentOrder, theType, theTime, receivedOrder, theHandle);
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, MessageRetractionHandle theHandle, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, InvalidLogicalTime, FederateInternalError ) {
            //#[ operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,MessageRetractionHandle,const RegionHandleSet &) 
            getItsHLA_PostOffice()->receiveInteraction(theInteraction, theParameterValues, theUserSuppliedTag, sentOrder, theType, theTime, receivedOrder, theHandle, theSentRegionHandleSet);
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
                    itsHLA_PostOffice->__setItsFrameworkFederateAmbassador(NULL);
                }
            __setItsHLA_PostOffice(p_HLA_PostOffice);
        }
        
        void FrameworkFederateAmbassador::setItsHLA_PostOffice(Framework::IO::HLA_PostOffice* p_HLA_PostOffice) {
            if(p_HLA_PostOffice != NULL)
                {
                    p_HLA_PostOffice->_setItsFrameworkFederateAmbassador(this);
                }
            _setItsHLA_PostOffice(p_HLA_PostOffice);
        }
        
        void FrameworkFederateAmbassador::_clearItsHLA_PostOffice() {
            itsHLA_PostOffice = NULL;
        }
        
        Framework::IO::RtiAmbassador* FrameworkFederateAmbassador::getItsRtiAmbassador() const {
            return itsRtiAmbassador;
        }
        
        void FrameworkFederateAmbassador::__setItsRtiAmbassador(Framework::IO::RtiAmbassador* p_RtiAmbassador) {
            itsRtiAmbassador = p_RtiAmbassador;
        }
        
        void FrameworkFederateAmbassador::_setItsRtiAmbassador(Framework::IO::RtiAmbassador* p_RtiAmbassador) {
            if(itsRtiAmbassador != NULL)
                {
                    itsRtiAmbassador->__setItsFrameworkFederateAmbassador(NULL);
                }
            __setItsRtiAmbassador(p_RtiAmbassador);
        }
        
        void FrameworkFederateAmbassador::setItsRtiAmbassador(Framework::IO::RtiAmbassador* p_RtiAmbassador) {
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
                    Framework::Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador = itsHLA_PostOffice->getItsFrameworkFederateAmbassador();
                    if(p_FrameworkFederateAmbassador != NULL)
                        {
                            itsHLA_PostOffice->__setItsFrameworkFederateAmbassador(NULL);
                        }
                    itsHLA_PostOffice = NULL;
                }
            if(itsRtiAmbassador != NULL)
                {
                    Framework::Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador = itsRtiAmbassador->getItsFrameworkFederateAmbassador();
                    if(p_FrameworkFederateAmbassador != NULL)
                        {
                            itsRtiAmbassador->__setItsFrameworkFederateAmbassador(NULL);
                        }
                    itsRtiAmbassador = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkFederateAmbassador.cpp
*********************************************************************/

