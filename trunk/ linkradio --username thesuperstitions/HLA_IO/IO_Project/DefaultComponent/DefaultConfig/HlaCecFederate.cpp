/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::Control::HlaCecFederate
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\HlaCecFederate.cpp
*********************************************************************/

#include "HlaCecFederate.h"
// dependency FederateInterfaceFactory 
#include "FederateInterfaceFactory.h"
#include "FederateIO_Handler.h"
// dependency HLA_PostOffice 
#include "HLA_PostOffice.h"
// dependency PostOffice 
#include "PostOffice.h"

//----------------------------------------------------------------------------
// HlaCecFederate.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::Control 

//## class HlaCecFederate 

namespace framework {
    namespace Control {
        
        HlaCecFederate::HlaCecFederate() : Federate(HLA_FederateFrameworkType, CEC_FederateType, getFrameworkFederateAmbassador()) {
            //#[ operation HlaCecFederate() 
            //#]
        }
        
        HlaCecFederate::~HlaCecFederate() {
        }
        
        void HlaCecFederate::useCase_42_1_announcePublication() {
            //#[ operation useCase_42_1_announcePublication() 
            /*            
            switch (federateType)
            { 
            	case CEC_FederateType : 
            		// Publish that the interface is available.
            		getThePostOffice()->announcePublication(getTheFederateInterface("SPYtoCECNtds"));   
            		break;
            		
            	case SSDS_FederateType :
            		break;
            };  
            */            
            //#]
        }
        
        void HlaCecFederate::useCase_42_2_announceSubscription() {
            //#[ operation useCase_42_2_announceSubscription() 
            
            // Subscribe to the interaction so that we receive data on the interface.
            //            getThePostOffice()->announceSubscription(getTheFederateInterface("SPYtoCECNtds"));   
            
            //#]
        }
        
        void HlaCecFederate::useCase_42_3_sendMessageOnFederateInterface() {
            //#[ operation useCase_42_3_sendMessageOnFederateInterface() 
            
            
            //#]
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HlaCecFederate.cpp
*********************************************************************/

