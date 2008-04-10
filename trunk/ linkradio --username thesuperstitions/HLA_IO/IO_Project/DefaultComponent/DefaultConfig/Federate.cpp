/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::Federate::Federate
//!	Generated Date	: Fri, 15, Feb 2008  
	File Path	: DefaultComponent\DefaultConfig\Federate.cpp
*********************************************************************/

#include "Federate.h"
// attribute federateInterfaceFactory 
#include "FederateInterfaceFactory.h"
// link itsFederateInterface 
#include "FederateInterface.h"
// link itsPostOffice 
#include "PostOffice.h"

//----------------------------------------------------------------------------
// Federate.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::Federate 

//## class Federate 

namespace Framework {
    namespace Federate {
        
        
        Federate::Federate(FederateFrameworkType fedFrameworkType) : 
        federateFrameworkType(fedFrameworkType) ,itsFederateInterface() {
            itsPostOffice = NULL;
            itsFederateInterfaceFactory = NULL;
            //#[ operation Federate(FederateFrameworkType) 
            setFederateInterfaceFactory( new FederateInterfaceFactory() );
            //#]
        }
        
        Federate::~Federate() {
            cleanUpRelations();
        }
        
        FederateType Federate::getType() const {
            //#[ operation getType() const 
            return(type);
            //#]
        }
        
        void Federate::useCase_42_1_announcePublication() {
            //#[ operation useCase_42_1_announcePublication() 
            FederateInterface* SPYtoCECNtds = federateInterfaceFactory->createFederateInterface("SPYtoCECNtds", HLA_FederateFrameworkType); 
            addItsFederateInterface("SPYtoCECNtds", SPYtoCECNtds)
            PostOffice::announcePublication(SPYtoCECNtds);   
            
            //PostOffice::announceSubscription(CECtoSPYNtds);   
            //#]
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
        
        std::string Federate::getInterfaceName() const {
            return interfaceName;
        }
        
        void Federate::setInterfaceName(std::string p_interfaceName) {
            interfaceName = p_interfaceName;
        }
        
        OMIterator<Framework::IO::FederateInterface*> Federate::getItsFederateInterface() const {
            OMIterator<Framework::IO::FederateInterface*> iter(itsFederateInterface);
            return iter;
        }
        
        void Federate::clearItsFederateInterface() {
            itsFederateInterface.removeAll();
        }
        
        void Federate::removeItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            itsFederateInterface.remove(p_FederateInterface);
        }
        
        Framework::IO::FederateInterface* Federate::getItsFederateInterface(std::string key) const {
            return itsFederateInterface.getKey(key);
        }
        
        void Federate::addItsFederateInterface(std::string key, Framework::IO::FederateInterface* p_FederateInterface) {
            itsFederateInterface.add(key,p_FederateInterface);
        }
        
        void Federate::removeItsFederateInterface(std::string key) {
            itsFederateInterface.remove(key);
        }
        
        Framework::Federate::FederateInterfaceFactory* Federate::getItsFederateInterfaceFactory() const {
            return itsFederateInterfaceFactory;
        }
        
        void Federate::__setItsFederateInterfaceFactory(Framework::Federate::FederateInterfaceFactory* p_FederateInterfaceFactory) {
            itsFederateInterfaceFactory = p_FederateInterfaceFactory;
        }
        
        void Federate::_setItsFederateInterfaceFactory(Framework::Federate::FederateInterfaceFactory* p_FederateInterfaceFactory) {
            if(itsFederateInterfaceFactory != NULL)
                {
                    itsFederateInterfaceFactory->__setItsFederate(NULL);
                }
            __setItsFederateInterfaceFactory(p_FederateInterfaceFactory);
        }
        
        void Federate::setItsFederateInterfaceFactory(Framework::Federate::FederateInterfaceFactory* p_FederateInterfaceFactory) {
            if(p_FederateInterfaceFactory != NULL)
                {
                    p_FederateInterfaceFactory->_setItsFederate(this);
                }
            _setItsFederateInterfaceFactory(p_FederateInterfaceFactory);
        }
        
        void Federate::_clearItsFederateInterfaceFactory() {
            itsFederateInterfaceFactory = NULL;
        }
        
        Framework::IO::PostOffice* Federate::getItsPostOffice() const {
            return itsPostOffice;
        }
        
        void Federate::__setItsPostOffice(Framework::IO::PostOffice* p_PostOffice) {
            itsPostOffice = p_PostOffice;
        }
        
        void Federate::_setItsPostOffice(Framework::IO::PostOffice* p_PostOffice) {
            if(itsPostOffice != NULL)
                {
                    itsPostOffice->__setItsFederate(NULL);
                }
            __setItsPostOffice(p_PostOffice);
        }
        
        void Federate::setItsPostOffice(Framework::IO::PostOffice* p_PostOffice) {
            if(p_PostOffice != NULL)
                {
                    p_PostOffice->_setItsFederate(this);
                }
            _setItsPostOffice(p_PostOffice);
        }
        
        void Federate::_clearItsPostOffice() {
            itsPostOffice = NULL;
        }
        
        void Federate::cleanUpRelations() {
            {
                itsFederateInterface.removeAll();
            }
            if(itsFederateInterfaceFactory != NULL)
                {
                    Framework::Federate::Federate* p_Federate = itsFederateInterfaceFactory->getItsFederate();
                    if(p_Federate != NULL)
                        {
                            itsFederateInterfaceFactory->__setItsFederate(NULL);
                        }
                    itsFederateInterfaceFactory = NULL;
                }
            if(itsPostOffice != NULL)
                {
                    Framework::Federate::Federate* p_Federate = itsPostOffice->getItsFederate();
                    if(p_Federate != NULL)
                        {
                            itsPostOffice->__setItsFederate(NULL);
                        }
                    itsPostOffice = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Federate.cpp
*********************************************************************/

