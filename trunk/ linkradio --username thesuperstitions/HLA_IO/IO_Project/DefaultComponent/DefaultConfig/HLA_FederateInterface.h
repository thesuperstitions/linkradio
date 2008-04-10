/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::HLA_FederateInterface
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_FederateInterface.h
*********************************************************************/


#ifndef HLA_FederateInterface_H 

#define HLA_FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// class HLA_FederateInterface 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// HLA_FederateInterface.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class HLA_PostOffice;
    }
    
}


//## package Framework::IO 


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
            
            //## operation announcePublication(FederateInterface*) 
            void announcePublication(FederateInterface* interface);
            
            //## operation processInteraction(int) 
            void processInteraction(int argument_0);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            rti1516::VariableLengthData getData() const;
            
            //## auto_generated 
            void setData(rti1516::VariableLengthData p_data);
            
            //## auto_generated 
            rti1516::InteractionClassHandle getInteractionClassHandle() const;
            
            //## auto_generated 
            void setInteractionClassHandle(rti1516::InteractionClassHandle p_interactionClassHandle);
            
            //## auto_generated 
            rti1516::ParameterHandle getParamHandle() const;
            
            //## auto_generated 
            void setParamHandle(rti1516::ParameterHandle p_paramHandle);
            
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
            
            rti1516::VariableLengthData data;		//## attribute data 
            
            rti1516::InteractionClassHandle interactionClassHandle;		//## attribute interactionClassHandle 
            
            rti1516::ParameterHandle paramHandle;		//## attribute paramHandle 
            
        
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

