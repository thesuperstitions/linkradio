//*********************************************************************************  
//
//	File:				Framework::Federate::FederateInterfaceFactory  
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


#include "FederateInterfaceFactory.h"
// link itsFederate 
#include "Federate.h"
// operation createFederateInterface(std::string) 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// FederateInterfaceFactory.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::Federate 

//## class FederateInterfaceFactory 

namespace Framework {
    namespace Federate {
        
        
        FederateInterfaceFactory::FederateInterfaceFactory(FederateFrameworkType fedFrameworkType) : federateFrameworkType(fedFrameworkType) {
            itsFederate = NULL;
            //#[ operation FederateInterfaceFactory(FederateFrameworkType) 
            //#]
        }
        
        FederateInterfaceFactory::FederateInterfaceFactory() {
            itsFederate = NULL;
        }
        
        FederateInterfaceFactory::~FederateInterfaceFactory() {
            cleanUpRelations();
        }
        
        FederateInterface* FederateInterfaceFactory::createFederateInterface(std::string name) {
            //#[ operation createFederateInterface(std::string) 
            // Based upon some later-to-be-identified configuration value, the factory creates
            // the appropriate FederateInterface.
            switch(federateFrameworkType)
            {
              case HLA_FederateFrameworkType:
                HLA_FederateInterface* HLA_FedInterface = new HLA_FederateInterface(name); 
                return( (FederateInterface*)HLA_FedInterface);
              break;
              
              case OASIS_FederateFrameworkType:
                OASIS_FederateInterface* OASIS_FedInterface = new OASIS_FederateInterface(name); 
                return( (FederateInterface*)OASIS_FedInterface);
              break;
            };            
            //#]
        }
        
        FederateFrameworkType FederateInterfaceFactory::getFederateFrameworkType() const {
            return federateFrameworkType;
        }
        
        void FederateInterfaceFactory::setFederateFrameworkType(FederateFrameworkType p_federateFrameworkType) {
            federateFrameworkType = p_federateFrameworkType;
        }
        
        Framework::Federate::Federate* FederateInterfaceFactory::getItsFederate() const {
            return itsFederate;
        }
        
        void FederateInterfaceFactory::__setItsFederate(Framework::Federate::Federate* p_Federate) {
            itsFederate = p_Federate;
        }
        
        void FederateInterfaceFactory::_setItsFederate(Framework::Federate::Federate* p_Federate) {
            if(itsFederate != NULL)
                {
                    itsFederate->__setItsFederateInterfaceFactory(NULL);
                }
            __setItsFederate(p_Federate);
        }
        
        void FederateInterfaceFactory::setItsFederate(Framework::Federate::Federate* p_Federate) {
            if(p_Federate != NULL)
                {
                    p_Federate->_setItsFederateInterfaceFactory(this);
                }
            _setItsFederate(p_Federate);
        }
        
        void FederateInterfaceFactory::_clearItsFederate() {
            itsFederate = NULL;
        }
        
        void FederateInterfaceFactory::cleanUpRelations() {
            if(itsFederate != NULL)
                {
                    Framework::Federate::FederateInterfaceFactory* p_FederateInterfaceFactory = itsFederate->getItsFederateInterfaceFactory();
                    if(p_FederateInterfaceFactory != NULL)
                        {
                            itsFederate->__setItsFederateInterfaceFactory(NULL);
                        }
                    itsFederate = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceFactory.cpp
*********************************************************************/

