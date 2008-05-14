/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterfaceOutputThread
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceOutputThread.cpp
*********************************************************************/

#include "FederateInterfaceOutputThread.h"
// link itsFederateInterface 
#include "FederateInterface.h"
// link itsInterprocessQueue 
#include <InterprocessQueue.h>

//----------------------------------------------------------------------------
// FederateInterfaceOutputThread.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateInterfaceOutputThread 

namespace Framework {
    namespace IO {
        
        
        FederateInterfaceOutputThread::FederateInterfaceOutputThread() {
            itsFederateInterface = NULL;
            itsInterprocessQueue = NULL;
        }
        
        FederateInterfaceOutputThread::~FederateInterfaceOutputThread() {
            cleanUpRelations();
        }
        
        Framework::IO::FederateInterface* FederateInterfaceOutputThread::getItsFederateInterface() const {
            return itsFederateInterface;
        }
        
        void FederateInterfaceOutputThread::__setItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            itsFederateInterface = p_FederateInterface;
        }
        
        void FederateInterfaceOutputThread::_setItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            if(itsFederateInterface != NULL)
                {
                    itsFederateInterface->__setItsFederateInterfaceOutputThread(NULL);
                }
            __setItsFederateInterface(p_FederateInterface);
        }
        
        void FederateInterfaceOutputThread::setItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            if(p_FederateInterface != NULL)
                {
                    p_FederateInterface->_setItsFederateInterfaceOutputThread(this);
                }
            _setItsFederateInterface(p_FederateInterface);
        }
        
        void FederateInterfaceOutputThread::_clearItsFederateInterface() {
            itsFederateInterface = NULL;
        }
        
        InterprocessQueue* FederateInterfaceOutputThread::getItsInterprocessQueue() const {
            return itsInterprocessQueue;
        }
        
        void FederateInterfaceOutputThread::setItsInterprocessQueue(InterprocessQueue* p_InterprocessQueue) {
            itsInterprocessQueue = p_InterprocessQueue;
        }
        
        void FederateInterfaceOutputThread::cleanUpRelations() {
            if(itsFederateInterface != NULL)
                {
                    Framework::IO::FederateInterfaceOutputThread* p_FederateInterfaceOutputThread = itsFederateInterface->getItsFederateInterfaceOutputThread();
                    if(p_FederateInterfaceOutputThread != NULL)
                        {
                            itsFederateInterface->__setItsFederateInterfaceOutputThread(NULL);
                        }
                    itsFederateInterface = NULL;
                }
            if(itsInterprocessQueue != NULL)
                {
                    itsInterprocessQueue = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceOutputThread.cpp
*********************************************************************/

