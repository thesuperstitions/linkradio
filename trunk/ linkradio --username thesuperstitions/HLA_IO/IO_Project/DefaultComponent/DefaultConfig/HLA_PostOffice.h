/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::HLA_PostOffice
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.h
*********************************************************************/


#ifndef HLA_PostOffice_H 

#define HLA_PostOffice_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
#include <oxf/ommap.h>
// operation sendMessage(FrameworkMessage*) 
#include "Framework.h"
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

} 

namespace Framework {
    class FrameworkFederateAmbassador;
    
} 

namespace Framework {
    
    namespace IO {
        class HLA_FederateInterface;
        class IO_Handler;
        class Message;
    }
    
}


//## package Framework::IO 


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
            
            //## operation announceSubscription(FederateInterface*) 
            void announceSubscription(FederateInterface* interface);
            
            //## operation createInteractionClassHandle(HLA_FederateInterface*) 
            void createInteractionClassHandle(HLA_FederateInterface* interface);
            
            // 6.9
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::RegionHandleSet &) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,const rti1516::RegionHandleSet &) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516:: InteractionClassNotSubscribed, rti1516:: FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError );
            
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle,const rti1516::RegionHandleSet &) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516:: InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError );
            
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
            FrameworkFederateAmbassador* getItsFrameworkFederateAmbassador() const;
            
            //## auto_generated 
            void setItsFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            OMIterator<HLA_FederateInterface*> getItsHLA_FederateInterface() const;
            
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
            void __setItsFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            void _setItsFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
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
            
            FrameworkFederateAmbassador* itsFrameworkFederateAmbassador;		//## link itsFrameworkFederateAmbassador 
            
            
            OMMap<rti1516::InteractionClassHandle, HLA_FederateInterface*> itsHLA_FederateInterface;		//## link itsHLA_FederateInterface 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.h
*********************************************************************/

