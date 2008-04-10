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
        
        void FrameworkFederateAmbassador::publishInteractionClass(rti1516::InteractionClassHandle theHandle) {
            //#[ operation publishInteractionClass(rti1516::InteractionClassHandle) 
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::RegionHandleSet & theSentRegionHandleSet) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::RegionHandleSet &) 
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const LogicalTime & theTime, rti1516::OrderType receivedOrder) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const LogicalTime &,rti1516::OrderType) 
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const LogicalTime & theTime, rti1516::OrderType receivedOrder, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const LogicalTime &,rti1516::OrderType,const rti1516::RegionHandleSet &) 
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const LogicalTime & theTime, rti1516::OrderType receivedOrder, MessageRetractionHandle theHandle) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, InvalidLogicalTime, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const LogicalTime &,rti1516::OrderType,MessageRetractionHandle) 
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType) 
            //#]
        }
        
        void FrameworkFederateAmbassador::receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError ) {
            //#[ operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle) 
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

