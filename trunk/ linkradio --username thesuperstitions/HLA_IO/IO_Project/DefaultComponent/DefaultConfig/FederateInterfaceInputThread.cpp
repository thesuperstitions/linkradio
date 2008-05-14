/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateInterfaceInputThread
//!	Generated Date	: Mon, 12, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceInputThread.cpp
*********************************************************************/

#include "FederateInterfaceInputThread.h"
// link itsFederateInterface 
#include "FederateInterface.h"
// link itsInterprocessQueue 
#include <InterprocessQueue.h>

//----------------------------------------------------------------------------
// FederateInterfaceInputThread.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class FederateInterfaceInputThread 

namespace Framework {
    namespace IO {
        
        
        FederateInterfaceInputThread::FederateInterfaceInputThread() {
            itsFederateInterface = NULL;
            itsInterprocessQueue = NULL;
        }
        
        FederateInterfaceInputThread::~FederateInterfaceInputThread() {
            cleanUpRelations();
        }
        
        Framework::IO::FederateInterface* FederateInterfaceInputThread::getItsFederateInterface() const {
            return itsFederateInterface;
        }
        
        void FederateInterfaceInputThread::__setItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            itsFederateInterface = p_FederateInterface;
        }
        
        void FederateInterfaceInputThread::_setItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            if(itsFederateInterface != NULL)
                {
                    itsFederateInterface->__setItsFederateInterfaceInputThread(NULL);
                }
            __setItsFederateInterface(p_FederateInterface);
        }
        
        void FederateInterfaceInputThread::setItsFederateInterface(Framework::IO::FederateInterface* p_FederateInterface) {
            if(p_FederateInterface != NULL)
                {
                    p_FederateInterface->_setItsFederateInterfaceInputThread(this);
                }
            _setItsFederateInterface(p_FederateInterface);
        }
        
        void FederateInterfaceInputThread::_clearItsFederateInterface() {
            itsFederateInterface = NULL;
        }
        
        InterprocessQueue* FederateInterfaceInputThread::getItsInterprocessQueue() const {
            return itsInterprocessQueue;
        }
        
        void FederateInterfaceInputThread::__setItsInterprocessQueue(InterprocessQueue* p_InterprocessQueue) {
            itsInterprocessQueue = p_InterprocessQueue;
        }
        
        void FederateInterfaceInputThread::_setItsInterprocessQueue(InterprocessQueue* p_InterprocessQueue) {
            if(itsInterprocessQueue != NULL)
                {
                    itsInterprocessQueue->__setItsFederateInterfaceInputThread(NULL);
                }
            __setItsInterprocessQueue(p_InterprocessQueue);
        }
        
        void FederateInterfaceInputThread::setItsInterprocessQueue(InterprocessQueue* p_InterprocessQueue) {
            if(p_InterprocessQueue != NULL)
                {
                    p_InterprocessQueue->_setItsFederateInterfaceInputThread(this);
                }
            _setItsInterprocessQueue(p_InterprocessQueue);
        }
        
        void FederateInterfaceInputThread::_clearItsInterprocessQueue() {
            itsInterprocessQueue = NULL;
        }
        
        void FederateInterfaceInputThread::cleanUpRelations() {
            if(itsFederateInterface != NULL)
                {
                    Framework::IO::FederateInterfaceInputThread* p_FederateInterfaceInputThread = itsFederateInterface->getItsFederateInterfaceInputThread();
                    if(p_FederateInterfaceInputThread != NULL)
                        {
                            itsFederateInterface->__setItsFederateInterfaceInputThread(NULL);
                        }
                    itsFederateInterface = NULL;
                }
            if(itsInterprocessQueue != NULL)
                {
                    Framework::IO::FederateInterfaceInputThread* p_FederateInterfaceInputThread = itsInterprocessQueue->getItsFederateInterfaceInputThread();
                    if(p_FederateInterfaceInputThread != NULL)
                        {
                            itsInterprocessQueue->__setItsFederateInterfaceInputThread(NULL);
                        }
                    itsInterprocessQueue = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateInterfaceInputThread.cpp
*********************************************************************/

