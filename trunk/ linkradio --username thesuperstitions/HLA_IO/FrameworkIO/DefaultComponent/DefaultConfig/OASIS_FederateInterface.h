//*********************************************************************************  
//
//	File:				Framework::IO::OASIS_FederateInterface  
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



#ifndef OASIS_FederateInterface_H 

#define OASIS_FederateInterface_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include "IO.h"
// class OASIS_FederateInterface 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// OASIS_FederateInterface.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Federate {
        class FederateInterfaceFactory;
    }
    
}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class OASIS_FederateInterface 
        class OASIS_FederateInterface : public FederateInterface {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            OASIS_FederateInterface();
            
            //## auto_generated 
            ~OASIS_FederateInterface();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Federate::FederateInterfaceFactory* getItsFederateInterfaceFactory() const;
            
            //## auto_generated 
            void setItsFederateInterfaceFactory(Federate::FederateInterfaceFactory* p_FederateInterfaceFactory);
        
        
        ////    Framework operations    ////
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Federate::FederateInterfaceFactory* itsFederateInterfaceFactory;		//## link itsFederateInterfaceFactory 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\OASIS_FederateInterface.h
*********************************************************************/

