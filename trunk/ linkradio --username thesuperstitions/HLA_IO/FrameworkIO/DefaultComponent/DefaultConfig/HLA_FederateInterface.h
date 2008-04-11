//*********************************************************************************  
//
//	File:				Framework::IO::HLA_FederateInterface  
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



#ifndef HLA_FederateInterface_H 

#define HLA_FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"
// class HLA_FederateInterface 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// HLA_FederateInterface.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class FrameworkFederateAmbassador;
        
    } 
    
namespace IO {
    class HLA_PostOffice;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class HLA_FederateInterface 
        class HLA_FederateInterface : public FederateInterface {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation HLA_FederateInterface(std::string) 
            HLA_FederateInterface(std::string interfaceName = "");
            
            //## auto_generated 
            ~HLA_FederateInterface();
        
        
        ////    Operations    ////
        public :
            
            //## operation instance() 
            static FederateInterface instance();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            VariableLengthData getData() const;
            
            //## auto_generated 
            void setData(VariableLengthData p_data);
            
            //## auto_generated 
            FrameworkFederateAmbassador* getFrameworkFederateAmbassador() const;
            
            //## auto_generated 
            void setFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_frameworkFederateAmbassador);
            
            //## auto_generated 
            rti1516::InteractionClassHandle getInteractionClassHandle() const;
            
            //## auto_generated 
            void setInteractionClassHandle(rti1516::InteractionClassHandle p_interactionClassHandle);
            
            //## auto_generated 
            parameterHandle getParamHandle() const;
            
            //## auto_generated 
            void setParamHandle(parameterHandle p_paramHandle);
            
            //## auto_generated 
            RTIambassador * getRtiAmbassador() const;
            
            //## auto_generated 
            void setRtiAmbassador(RTIambassador * p_rtiAmbassador);
            
            //## auto_generated 
            HLA_PostOffice* getItsHLA_PostOffice() const;
            
            //## auto_generated 
            void setItsHLA_PostOffice(HLA_PostOffice* p_HLA_PostOffice);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsHLA_PostOffice(HLA_PostOffice* p_HLA_PostOffice);
            
            //## auto_generated 
            void _setItsHLA_PostOffice(HLA_PostOffice* p_HLA_PostOffice);
            
            //## auto_generated 
            void _clearItsHLA_PostOffice();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            VariableLengthData data;		//## attribute data 
            
            FrameworkFederateAmbassador* frameworkFederateAmbassador;		//## attribute frameworkFederateAmbassador 
            
            rti1516::InteractionClassHandle interactionClassHandle;		//## attribute interactionClassHandle 
            
            parameterHandle paramHandle;		//## attribute paramHandle 
            
            RTIambassador * rtiAmbassador;		//## attribute rtiAmbassador 
            
        
        ////    Relations and components    ////
        protected :
            
            HLA_PostOffice* itsHLA_PostOffice;		//## link itsHLA_PostOffice 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_FederateInterface.h
*********************************************************************/

