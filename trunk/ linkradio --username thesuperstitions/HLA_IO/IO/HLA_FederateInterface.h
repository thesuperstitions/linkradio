/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::hla::HLA_FederateInterface
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_FederateInterface.h
*********************************************************************/


#ifndef HLA_FederateInterface_H 

#define HLA_FederateInterface_H 

#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// operation HLA_FederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
#include "framework.h"
// class HLA_FederateInterface 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// HLA_FederateInterface.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace Control {
        class Federate;
        
    } 
    
namespace io {
    class FederateIO_Handler;
    class HLA_PostOffice;
    class PostOffice;
}

}


//## package framework::io 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
  namespace io {
    namespace hla {    
        //## class HLA_FederateInterface 
        class HLA_FederateInterface : public FederateInterface {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation HLA_FederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
            HLA_FederateInterface(FederateIO_Handler* FIOH, int interfaceID, int unitNumber, 
              std::string name, unsigned long maxMessageSize, unsigned long maxMessages, 
              FederateInterfaceType federateInterfaceType);
            
            //## operation ~HLA_FederateInterface() 
            ~HLA_FederateInterface();
        
        
        ////    Operations    ////
        public :
            
            //## operation setInteractionClassHandle(rti1516::InteractionClassHandle) 
            void setInteractionClassHandle(rti1516::InteractionClassHandle handle);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            rti1516::InteractionClassHandle getInteractionClassHandle() const;
            
            //## auto_generated 
            bool getIsInteractionClassHandleSet() const;
            
            //## auto_generated 
            void setIsInteractionClassHandleSet(bool p_isInteractionClassHandleSet);
            
            //## auto_generated 
            rti1516::ParameterHandle getParamHandle() const;
            
            //## auto_generated 
            void setParamHandle(rti1516::ParameterHandle p_paramHandle);
            
            //## auto_generated 
            HLA_PostOffice* getTheHLA_PostOffice() const;
            
            //## auto_generated 
            void setTheHLA_PostOffice(HLA_PostOffice* p_HLA_PostOffice);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setTheHLA_PostOffice(HLA_PostOffice* p_HLA_PostOffice);
            
            //## auto_generated 
            void _setTheHLA_PostOffice(HLA_PostOffice* p_HLA_PostOffice);
            
            //## auto_generated 
            void _clearTheHLA_PostOffice();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            rti1516::InteractionClassHandle interactionClassHandle;		//## attribute interactionClassHandle 
            
            bool isInteractionClassHandleSet;		//## attribute isInteractionClassHandleSet 
            
            rti1516::ParameterHandle paramHandle;		//## attribute paramHandle 
            
        
        ////    Relations and components    ////
        protected :
            
            HLA_PostOffice* theHLA_PostOffice;		//## link theHLA_PostOffice 
            
        
        
        };

    } // namespace hla    
  } // namespace io
} // namespace framework


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_FederateInterface.h
*********************************************************************/

