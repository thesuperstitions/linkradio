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



#ifndef HLA_PostOffice_H 

#define HLA_PostOffice_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"
#include <map>
#include <iterator>
#include <oxf/OMValueCompare.h>
// operation sendMessage(FrameworkMessage*) 
#include "Framework.h"
// link itsHLA_FederateInterface 
#include "HLA_FederateInterface.h"
// class HLA_PostOffice 
#include "PostOffice.h"

//----------------------------------------------------------------------------
// HLA_PostOffice.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        
    } 
    
namespace Federate {
    class Federate;
    
} 

namespace IO {
    class FederateInterface;
    class FederateMessage;
    
} 

namespace Control {
    class FrameworkFederateAmbassador;
    
} 

namespace IO {
    class IO_Handler;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class HLA_PostOffice 
        class HLA_PostOffice : public PostOffice {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            HLA_PostOffice();
            
            //## auto_generated 
            virtual ~HLA_PostOffice();
        
        
        ////    Operations    ////
        public :
            
            //## operation announcePublication(FederateInterface*) 
            void announcePublication(FederateInterface* interface);
            
            //## operation announceSubscription(FederateInterface*) 
            void announceSubscription(FederateInterface* interface);
            
            //## operation createInteractionClassHandle(HLA_FederateInterface*) 
            void createInteractionClassHandle(HLA_FederateInterface* interface);
            
            // Here's the function that'll actually process the incoming data.
            //## operation processInteraction(const ParameterHandleValueMap &) 
            virtual void processInteraction(const ParameterHandleValueMap & theParameterValues);
            
            // 6.9
            //## operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType) 
            virtual void receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError );
            
            //## operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const RegionHandleSet &) 
            virtual void receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError );
            
            //## operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType) 
            virtual void receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError );
            
            //## operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,const RegionHandleSet &) 
            virtual void receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, FederateInternalError );
            
            //## operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,MessageRetractionHandle) 
            virtual void receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, MessageRetractionHandle theHandle) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, InvalidLogicalTime, FederateInternalError );
            
            //## operation receiveInteraction(InteractionClassHandle,const ParameterHandleValueMap &,const VariableLengthData &,OrderType,TransportationType,const LogicalTime &,OrderType,MessageRetractionHandle,const RegionHandleSet &) 
            virtual void receiveInteraction(InteractionClassHandle theInteraction, const ParameterHandleValueMap & theParameterValues, const VariableLengthData & theUserSuppliedTag, OrderType sentOrder, TransportationType theType, const LogicalTime & theTime, OrderType receivedOrder, MessageRetractionHandle theHandle, const RegionHandleSet & theSentRegionHandleSet) throw( InteractionClassNotRecognized, InteractionParameterNotRecognized, InteractionClassNotSubscribed, InvalidLogicalTime, FederateInternalError );
            
            //## operation recvMessage(Buffer*,int) 
            void recvMessage(Buffer* buffer, int theInteraction);
            
            //## operation sendMessage(FrameworkMessage*) 
            void sendMessage(FrameworkMessage* message);
            
            //## operation sendMessage(FederateMessage*) 
            void sendMessage(FederateMessage* message);
            
            //## operation unsubscribe(FederateInterface*) 
            void unsubscribe(FederateInterface* interface);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Control::FrameworkFederateAmbassador* getItsFrameworkFederateAmbassador() const;
            
            //## auto_generated 
            void setItsFrameworkFederateAmbassador(Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            std::map<rti1516::InteractionClassHandle, HLA_FederateInterface*>::const_iterator getItsHLA_FederateInterface() const;
            
            //## auto_generated 
            std::map<rti1516::InteractionClassHandle, HLA_FederateInterface*>::const_iterator getItsHLA_FederateInterfaceEnd() const;
            
            //## auto_generated 
            void clearItsHLA_FederateInterface();
            
            //## auto_generated 
            void removeItsHLA_FederateInterface(HLA_FederateInterface* p_HLA_FederateInterface);
            
            //## auto_generated 
            HLA_FederateInterface* getItsHLA_FederateInterface(rti1516::InteractionClassHandle key) const;
            
            //## auto_generated 
            void addItsHLA_FederateInterface(rti1516::InteractionClassHandle key, HLA_FederateInterface* p_HLA_FederateInterface);
            
            //## auto_generated 
            void removeItsHLA_FederateInterface(rti1516::InteractionClassHandle key);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFrameworkFederateAmbassador(Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            void _setItsFrameworkFederateAmbassador(Control::FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            void _clearItsFrameworkFederateAmbassador();
            
            //## auto_generated 
            void _clearItsHLA_FederateInterface();
            
            //## auto_generated 
            void _removeItsHLA_FederateInterface(HLA_FederateInterface* p_HLA_FederateInterface);
            
            //## auto_generated 
            void _addItsHLA_FederateInterface(rti1516::InteractionClassHandle key, HLA_FederateInterface* p_HLA_FederateInterface);
            
            //## auto_generated 
            void _removeItsHLA_FederateInterface(rti1516::InteractionClassHandle key);
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Control::FrameworkFederateAmbassador* itsFrameworkFederateAmbassador;		//## link itsFrameworkFederateAmbassador 
            
            
            std::map<rti1516::InteractionClassHandle, HLA_FederateInterface*> itsHLA_FederateInterface;		//## link itsHLA_FederateInterface 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.h
*********************************************************************/

