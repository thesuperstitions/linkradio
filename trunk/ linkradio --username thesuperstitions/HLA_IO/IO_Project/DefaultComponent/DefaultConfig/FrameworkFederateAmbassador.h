/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::FrameworkFederateAmbassador
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\FrameworkFederateAmbassador.h
*********************************************************************/


#ifndef FrameworkFederateAmbassador_H 

#define FrameworkFederateAmbassador_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "Framework.h"

//----------------------------------------------------------------------------
// FrameworkFederateAmbassador.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class HLA_PostOffice;
        class RtiAmbassador;
    }
    
}


//## package Framework 


namespace Framework {
    //## class FrameworkFederateAmbassador 
    
    //#[ ignore 
    using namespace std;
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
        
        //## operation getInteractionClassHandle(std::string) 
        rti1516::InteractionClassHandle getInteractionClassHandle(std::string interactionName);
        
        //## operation getParameterHandle(rti1516::InteractionClassHandle,std::string) 
        rti1516::ParameterHandle getParameterHandle(rti1516::InteractionClassHandle interactionClassHandle, std::string parameterName);
        
        //## operation processInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType,const rti1516::LogicalTime &,rti1516::OrderType,rti1516::MessageRetractionHandle,const rti1516::RegionHandleSet &) 
        virtual void processInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType, const rti1516::LogicalTime & theTime, rti1516::OrderType receivedOrder, rti1516::MessageRetractionHandle theHandle, const rti1516::RegionHandleSet & theSentRegionHandleSet) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::InvalidLogicalTime, rti1516::FederateInternalError );
        
        //## operation publishInteractionClass(const rti1516::ParameterHandleValueMap &) 
        void publishInteractionClass(const rti1516::ParameterHandleValueMap & theParameterValues);
        
        //## operation subscribeInteractionClass(rti1516::InteractionClassHandle) 
        void subscribeInteractionClass(rti1516::InteractionClassHandle interactionClassHandle);
    
    
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


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FrameworkFederateAmbassador.h
*********************************************************************/

