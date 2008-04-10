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



#ifndef FrameworkFederateAmbassador_H 

#define FrameworkFederateAmbassador_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "Control.h"

//----------------------------------------------------------------------------
// FrameworkFederateAmbassador.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class HLA_PostOffice;
        class RtiAmbassador;
    }
    
}


//## package Framework::Control 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace Control {
        //## class FrameworkFederateAmbassador 
        
        //#[ ignore 
        
        #ifdef WIN32
        #pragma warning(disable: 4251)
        #pragma warning(disable: 4786)
        #pragma warning(disable: 4290)
        #endif
        
        #include <RTI/RTI1516.h>        
        //#]
        class FrameworkFederateAmbassador  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            FrameworkFederateAmbassador();
            
            //## auto_generated 
            virtual ~FrameworkFederateAmbassador();
        
        
        ////    Operations    ////
        public :
            
            //## operation publishInteractionClass(rti1516::InteractionClassHandle) 
            void publishInteractionClass(rti1516::InteractionClassHandle theHandle);
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::RegionHandleSet &) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::RegionHandleSet & theSentRegionHandleSet);
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const LogicalTime &,rti1516::OrderType) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const LogicalTime & theTime, rti1516::OrderType receivedOrder) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const LogicalTime &,rti1516::OrderType,const rti1516::RegionHandleSet &) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const LogicalTime & theTime, rti1516::OrderType receivedOrder, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const LogicalTime &,rti1516::OrderType,MessageRetractionHandle) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const LogicalTime & theTime, rti1516::OrderType receivedOrder, MessageRetractionHandle theHandle) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, InvalidLogicalTime, rti1516::FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::InteractionClassHandle &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::InteractionClassHandle & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError );
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            IO::HLA_PostOffice* getItsHLA_PostOffice() const;
            
            //## auto_generated 
            void setItsHLA_PostOffice(IO::HLA_PostOffice* p_HLA_PostOffice);
            
            //## auto_generated 
            IO::RtiAmbassador* getItsRtiAmbassador() const;
            
            //## auto_generated 
            void setItsRtiAmbassador(IO::RtiAmbassador* p_RtiAmbassador);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsHLA_PostOffice(IO::HLA_PostOffice* p_HLA_PostOffice);
            
            //## auto_generated 
            void _setItsHLA_PostOffice(IO::HLA_PostOffice* p_HLA_PostOffice);
            
            //## auto_generated 
            void _clearItsHLA_PostOffice();
            
            //## auto_generated 
            void __setItsRtiAmbassador(IO::RtiAmbassador* p_RtiAmbassador);
            
            //## auto_generated 
            void _setItsRtiAmbassador(IO::RtiAmbassador* p_RtiAmbassador);
            
            //## auto_generated 
            void _clearItsRtiAmbassador();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            IO::HLA_PostOffice* itsHLA_PostOffice;		//## link itsHLA_PostOffice 
            
            
            IO::RtiAmbassador* itsRtiAmbassador;		//## link itsRtiAmbassador 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkFederateAmbassador.h
*********************************************************************/

