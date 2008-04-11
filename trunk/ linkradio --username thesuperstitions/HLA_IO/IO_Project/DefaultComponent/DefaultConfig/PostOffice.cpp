/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::PostOffice
//!	Generated Date	: Fri, 4, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\PostOffice.cpp
*********************************************************************/

#include "PostOffice.h"
// link theFederate 
#include "Federate.h"
// operation receiveMessage(Buffer*,int) 
#include "Buffer.h"
// operation announcePublication(FederateInterface*) 
#include "FederateInterface.h"
// operation sendMessage(FederateMessage*) 
#include "FederateMessage.h"

//----------------------------------------------------------------------------
// PostOffice.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class PostOffice 

namespace Framework {
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
        
        Framework::Control::Federate* PostOffice::getTheFederate() const {
            return theFederate;
        }
        
        void PostOffice::__setTheFederate(Framework::Control::Federate* p_Federate) {
            theFederate = p_Federate;
        }
        
        void PostOffice::_setTheFederate(Framework::Control::Federate* p_Federate) {
            if(theFederate != NULL)
                {
                    theFederate->__setThePostOffice(NULL);
                }
            __setTheFederate(p_Federate);
        }
        
        void PostOffice::setTheFederate(Framework::Control::Federate* p_Federate) {
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
                    Framework::IO::PostOffice* p_PostOffice = theFederate->getThePostOffice();
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

