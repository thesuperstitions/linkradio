/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::HLA_PostOffice
//!	Generated Date	: Thu, 15, May 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.h
*********************************************************************/


#ifndef HLA_PostOffice_H 

#define HLA_PostOffice_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
#include <map>
#include <iterator>
#include <oxf/OMValueCompare.h>
// operation sendMessage(FrameworkMessage*) 
#include "Framework.h"
// link theHLA_FederateInterface 
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
    
namespace Control {
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
            
            //## operation HLA_PostOffice(FrameworkFederateAmbassador*) 
            HLA_PostOffice(FrameworkFederateAmbassador* frameworkFederateAmbassador);
            
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
            
            // 6.9
            //## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType) 
            virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );
            
            //## operation receiveMessage(Buffer*,int) 
            void receiveMessage(Buffer* buffer, int theInteraction);
            
            //## operation sendMessage(FrameworkMessage*) 
            void sendMessage(FrameworkMessage* message);
            
            //## operation sendMessage(FederateMessage*) 
            void sendMessage(FederateMessage* message);
            
            //## operation sendMessage(char*,HLA_FederateInterface*) 
            void sendMessage(char* message, HLA_FederateInterface* hlaFederateInterface);
            
            //## operation unsubscribe(FederateInterface*) 
            void unsubscribe(FederateInterface* interface);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FrameworkFederateAmbassador* getTheFrameworkFederateAmbassador() const;
            
            //## auto_generated 
            void setTheFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            std::map<rti1516::InteractionClassHandle, HLA_FederateInterface*>::const_iterator getTheHLA_FederateInterface() const;
            
            //## auto_generated 
            std::map<rti1516::InteractionClassHandle, HLA_FederateInterface*>::const_iterator getTheHLA_FederateInterfaceEnd() const;
            
            //## auto_generated 
            void clearTheHLA_FederateInterface();
            
            //## auto_generated 
            void removeTheHLA_FederateInterface(HLA_FederateInterface* p_HLA_FederateInterface);
            
            //## auto_generated 
            HLA_FederateInterface* getTheHLA_FederateInterface(rti1516::InteractionClassHandle key) const;
            
            //## auto_generated 
            void addTheHLA_FederateInterface(rti1516::InteractionClassHandle key, HLA_FederateInterface* p_HLA_FederateInterface);
            
            //## auto_generated 
            void removeTheHLA_FederateInterface(rti1516::InteractionClassHandle key);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setTheFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            void _setTheFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);
            
            //## auto_generated 
            void _clearTheFrameworkFederateAmbassador();
            
            //## auto_generated 
            void _clearTheHLA_FederateInterface();
            
            //## auto_generated 
            void _removeTheHLA_FederateInterface(HLA_FederateInterface* p_HLA_FederateInterface);
            
            //## auto_generated 
            void _addTheHLA_FederateInterface(rti1516::InteractionClassHandle key, HLA_FederateInterface* p_HLA_FederateInterface);
            
            //## auto_generated 
            void _removeTheHLA_FederateInterface(rti1516::InteractionClassHandle key);
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            FrameworkFederateAmbassador* theFrameworkFederateAmbassador;		//## link theFrameworkFederateAmbassador 
            
            
            std::map<rti1516::InteractionClassHandle, HLA_FederateInterface*> theHLA_FederateInterface;		//## link theHLA_FederateInterface 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.h
*********************************************************************/

