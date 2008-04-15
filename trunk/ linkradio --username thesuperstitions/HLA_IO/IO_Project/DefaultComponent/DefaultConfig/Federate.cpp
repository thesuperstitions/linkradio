/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Control::Federate
//!	Generated Date	: Mon, 14, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\Federate.cpp
*********************************************************************/

#include "Federate.h"
// dependency FederateInterfaceFactory 
#include "FederateInterfaceFactory.h"
// operation Federate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
#include "FrameworkFederateAmbassador.h"
// dependency HLA_PostOffice 
#include "HLA_PostOffice.h"
// dependency PostOffice 
#include "PostOffice.h"

//----------------------------------------------------------------------------
// Federate.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::Control 

//## class Federate 

namespace Framework {
    namespace Control {
        
        
        Federate::Federate(FederateFrameworkType fedFrameworkType, FederateType fedType, FrameworkFederateAmbassador* frameworkFederateAmbassador) {
            thePostOffice = NULL;
            itsFederateIO_Handler = NULL;
            //#[ operation Federate(FederateFrameworkType,FederateType,FrameworkFederateAmbassador*) 
                             
            // Save this class' attributes.
            setFederateFrameworkType(fedFrameworkType);
            setFederateType(fedType);      
            
            // Create the FederateIO_Handler
            setItsFederateIO_Handler(new Framework::IO::FederateIO_Handler(fedFrameworkType)); 
            
            switch(fedFrameworkType)
            {
              case HLA_FederateFrameworkType :  
                setThePostOffice( static_cast<Framework::IO::PostOffice*>(new Framework::IO::HLA_PostOffice(frameworkFederateAmbassador)) );  
              	break;
                
              case OASIS_FederateFrameworkType :    
            //    setThePostOffice( static_cast<Framework::IO::PostOffice>(new Framework::IO::OASIS_PostOffice()) );
                break;
            }; 
            
            setFederate(this);
            
            //#]
        }
        
        Federate::~Federate() {
            cleanUpRelations();
        }
        
        FederateFrameworkType Federate::getFederateFrameworkType() const {
            return federateFrameworkType;
        }
        
        void Federate::setFederateFrameworkType(FederateFrameworkType p_federateFrameworkType) {
            federateFrameworkType = p_federateFrameworkType;
        }
        
        FederateInterfaceFactory* Federate::getFederateInterfaceFactory() const {
            return federateInterfaceFactory;
        }
        
        void Federate::setFederateInterfaceFactory(FederateInterfaceFactory* p_federateInterfaceFactory) {
            federateInterfaceFactory = p_federateInterfaceFactory;
        }
        
        int Federate::getFederateType() const {
            return federateType;
        }
        
        void Federate::setFederateType(int p_federateType) {
            federateType = p_federateType;
        }
        
        Framework::IO::FederateIO_Handler* Federate::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void Federate::__setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void Federate::_setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler->__setItsFederate(NULL);
                }
            __setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void Federate::setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(p_FederateIO_Handler != NULL)
                {
                    p_FederateIO_Handler->_setItsFederate(this);
                }
            _setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void Federate::_clearItsFederateIO_Handler() {
            itsFederateIO_Handler = NULL;
        }
        
        Framework::IO::PostOffice* Federate::getThePostOffice() const {
            return thePostOffice;
        }
        
        void Federate::__setThePostOffice(Framework::IO::PostOffice* p_PostOffice) {
            thePostOffice = p_PostOffice;
        }
        
        void Federate::_setThePostOffice(Framework::IO::PostOffice* p_PostOffice) {
            if(thePostOffice != NULL)
                {
                    thePostOffice->__setTheFederate(NULL);
                }
            __setThePostOffice(p_PostOffice);
        }
        
        void Federate::setThePostOffice(Framework::IO::PostOffice* p_PostOffice) {
            if(p_PostOffice != NULL)
                {
                    p_PostOffice->_setTheFederate(this);
                }
            _setThePostOffice(p_PostOffice);
        }
        
        void Federate::_clearThePostOffice() {
            thePostOffice = NULL;
        }
        
        void Federate::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    Framework::Control::Federate* p_Federate = itsFederateIO_Handler->getItsFederate();
                    if(p_Federate != NULL)
                        {
                            itsFederateIO_Handler->__setItsFederate(NULL);
                        }
                    itsFederateIO_Handler = NULL;
                }
            if(thePostOffice != NULL)
                {
                    Framework::Control::Federate* p_Federate = thePostOffice->getTheFederate();
                    if(p_Federate != NULL)
                        {
                            thePostOffice->__setTheFederate(NULL);
                        }
                    thePostOffice = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Federate.cpp
*********************************************************************/

