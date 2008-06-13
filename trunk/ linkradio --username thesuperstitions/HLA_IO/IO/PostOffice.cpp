/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::IO::PostOffice
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\PostOffice.cpp
*********************************************************************/

#include "PostOffice.h"
// link theFederate 
#include "Federate.h"
// operation announcePublication(FederateInterface*) 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// PostOffice.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::IO 

//## class PostOffice 

namespace framework {
    namespace IO {
        
        
        PostOffice::PostOffice() {
            theFederate = NULL;
        }
        
        PostOffice::~PostOffice() {
            cleanUpRelations();
        }
        
        FederateInterface* PostOffice::findFederateInterface() {
            //#[ operation findFederateInterface() 
            return(NULL);  // This is just temporary until the code is fleshed out.
            //#]
        }
        
        framework::Control::Federate* PostOffice::getTheFederate() const {
            return theFederate;
        }
        
        void PostOffice::__setTheFederate(framework::Control::Federate* p_Federate) {
            theFederate = p_Federate;
        }
        
        void PostOffice::_setTheFederate(framework::Control::Federate* p_Federate) {
            if(theFederate != NULL)
                {
                    theFederate->__setThePostOffice(NULL);
                }
            __setTheFederate(p_Federate);
        }
        
        void PostOffice::setTheFederate(framework::Control::Federate* p_Federate) {
            if(p_Federate != NULL)
                {
                    p_Federate->_setThePostOffice(this);
                }
            _setTheFederate(p_Federate);
        }
        
        void PostOffice::_clearTheFederate() {
            theFederate = NULL;
        }
        
        void PostOffice::cleanUpRelations() {
            if(theFederate != NULL)
                {
                    framework::IO::PostOffice* p_PostOffice = theFederate->getThePostOffice();
                    if(p_PostOffice != NULL)
                        {
                            theFederate->__setThePostOffice(NULL);
                        }
                    theFederate = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PostOffice.cpp
*********************************************************************/

