/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::FrameworkFederateAmbassador
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FrameworkFederateAmbassador.cpp
*********************************************************************/

#include "FrameworkFederateAmbassador.h"
// link itsHLA_PostOffice 
#include "HLA_PostOffice.h"
// link itsRtiAmbassador 
#include "RtiAmbassador.h"

//----------------------------------------------------------------------------
// FrameworkFederateAmbassador.cpp                                                                  
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
    
    rti1516::InteractionClassHandle FrameworkFederateAmbassador::getInteractionClassHandle(std::string interactionName) {
        //#[ operation getInteractionClassHandle(std::string) 
        return( getRTIambassador()->getInteractionClassHandle(Framework::DtToWString(interactionName.c_str())) );
        //#]
    }
    
    rti1516::ParameterHandle FrameworkFederateAmbassador::getParameterHandle(rti1516::InteractionClassHandle interactionClassHandle, std::string parameterName) {
        //#[ operation getParameterHandle(rti1516::InteractionClassHandle,std::string) 
        return ( getRTIambassador()->getParameterHandle(interactionClassHandle, DtToWString(parameterName.c_str())) );
        //#]
    }
    
    void FrameworkFederateAmbassador::processInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError ) {
        //#[ operation processInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle,const rti1516::RegionHandleSet &) 
        //#]
    }
    
    void FrameworkFederateAmbassador::publishInteractionClass(const rti1516::ParameterHandleValueMap & theParameterValues) {
        //#[ operation publishInteractionClass(const rti1516::ParameterHandleValueMap &) 
        //#]
    }
    
    void FrameworkFederateAmbassador::subscribeInteractionClass(rti1516::InteractionClassHandle interactionClassHandle) {
        //#[ operation subscribeInteractionClass(rti1516::InteractionClassHandle) 
        getRTIambassador()->subscribeInteractionClass(interactionClassHandle);
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
                Framework::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador = itsHLA_PostOffice->getItsFrameworkFederateAmbassador();
                if(p_FrameworkFederateAmbassador != NULL)
                    {
                        itsHLA_PostOffice->__setItsFrameworkFederateAmbassador(NULL);
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
	File Path	: DefaultComponent\DefaultConfig\FrameworkFederateAmbassador.cpp
*********************************************************************/

