/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::FrameworkFederateAmbassador
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FrameworkFederateAmbassador.h
*********************************************************************/


#ifndef FrameworkFederateAmbassador_H 

#define FrameworkFederateAmbassador_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "framework.h"

//----------------------------------------------------------------------------
// FrameworkFederateAmbassador.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace IO {
        class HLA_PostOffice;
    }
    
}


//## package framework 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
    //## class FrameworkFederateAmbassador 
    
    //#[ ignore 
    using namespace std;
    //#]
    class FrameworkFederateAmbassador  {
    
    
    ////    Constructors and destructors    ////
    public :
        
        //## operation FrameworkFederateAmbassador() 
        FrameworkFederateAmbassador();
        
        //## auto_generated 
        virtual ~FrameworkFederateAmbassador();
    
    
    ////    Operations    ////
    public :
        
        //## operation getInteractionClassHandle(std::wstring) 
        rti1516::InteractionClassHandle getInteractionClassHandle(std::wstring interactionName);
        
        //## operation getParameterHandle(rti1516::InteractionClassHandle,std::wstring) 
        rti1516::ParameterHandle getParameterHandle(rti1516::InteractionClassHandle interactionClassHandle, std::wstring parameterName);
        
        //## operation publishInteractionClass(rti1516::InteractionClassHandle) 
        void publishInteractionClass(rti1516::InteractionClassHandle theParameterValues);
        
        //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle,const rti1516::RegionHandleSet &) 
        virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError );
        
        //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::RegionHandleSet &) 
        virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
        
        //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType) 
        virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
        
        //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,const rti1516::RegionHandleSet &) 
        virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516:: InteractionClassNotSubscribed, rti1516:: FederateInternalError );
        
        //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle) 
        virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError );
        
        //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType) 
        void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
        
        //## operation sendRO(rti1516::InteractionClassHandle,rti1516::ParameterHandle,char*,char*,int) 
        void sendRO(rti1516::InteractionClassHandle interactionClassHandle, rti1516::ParameterHandle parameterHandle, char* interactionName, char* messageToSend, int messageSizeInBytes);
        
        //## operation sendTSO(rti1516::InteractionClassHandle,rti1516::ParameterHandle,char*,char*,int) 
        void sendTSO(rti1516::InteractionClassHandle interactionClassHandle, rti1516::ParameterHandle parameterHandle, char* interactionName, char* messageToSend, int messageSizeInBytes);
        
        //## operation subscribeInteractionClass(rti1516::InteractionClassHandle) 
        void subscribeInteractionClass(rti1516::InteractionClassHandle interactionClassHandle);
    
    
    ////    Additional operations    ////
    public :
        
        //## auto_generated 
        IO::HLA_PostOffice* getItsHLA_PostOffice() const;
        
        //## auto_generated 
        void setItsHLA_PostOffice(IO::HLA_PostOffice* p_HLA_PostOffice);
    
    
    ////    Framework operations    ////
    public :
        
        //## auto_generated 
        void __setItsHLA_PostOffice(IO::HLA_PostOffice* p_HLA_PostOffice);
        
        //## auto_generated 
        void _setItsHLA_PostOffice(IO::HLA_PostOffice* p_HLA_PostOffice);
        
        //## auto_generated 
        void _clearItsHLA_PostOffice();
    
    protected :
        
        //## auto_generated 
        void cleanUpRelations();
    
    
    ////    Relations and components    ////
    protected :
        
        IO::HLA_PostOffice* itsHLA_PostOffice;		//## link itsHLA_PostOffice 
        
    
    
    };
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkFederateAmbassador.h
*********************************************************************/

