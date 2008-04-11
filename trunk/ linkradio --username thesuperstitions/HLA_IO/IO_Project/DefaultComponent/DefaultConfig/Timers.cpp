/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::utils::Timers
//!	Generated Date	: Tue, 8, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\Timers.cpp
*********************************************************************/

#include "Timers.h"
// link itsFederateIO_Handler 
#include "FederateIO_Handler.h"
// dependency Sleep 
#include "Sleep.h"

//----------------------------------------------------------------------------
// Timers.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::utils 

//## class Timers 

namespace Framework {
    namespace utils {
        
        
        Timers::Timers(int seconds, unsigned long nanoseconds, bool startImmediately, bool periodic) : isPeriodic(periodic), periodicTimerActive(startImmediately), seconds(seconds), nanoseconds(nanoseconds) {
            itsFederateIO_Handler = NULL;
            itsFederateIO_Handler_1 = NULL;
            //#[ operation Timers(int,unsigned long,bool,bool) 
            //#]
        }
        
        Timers::~Timers() {
            cleanUpRelations();
        }
        
        void Timers::startPeriodicTimer() {
            //#[ operation startPeriodicTimer() 
            
            setPeriodicTimerActive(true);
            Sleep::sleep(seconds, nanoseconds);  
            
            //#]
        }
        
        void Timers::stopPeriodicTimer() {
            //#[ operation stopPeriodicTimer() 
            //#]
        }
        
        bool Timers::getIsPeriodic() const {
            return isPeriodic;
        }
        
        void Timers::setIsPeriodic(bool p_isPeriodic) {
            isPeriodic = p_isPeriodic;
        }
        
        unsigned long Timers::getNanoseconds() const {
            return nanoseconds;
        }
        
        void Timers::setNanoseconds(unsigned long p_nanoseconds) {
            nanoseconds = p_nanoseconds;
        }
        
        bool Timers::getPeriodicTimerActive() const {
            return periodicTimerActive;
        }
        
        void Timers::setPeriodicTimerActive(bool p_periodicTimerActive) {
            periodicTimerActive = p_periodicTimerActive;
        }
        
        int Timers::getSeconds() const {
            return seconds;
        }
        
        void Timers::setSeconds(int p_seconds) {
            seconds = p_seconds;
        }
        
        Framework::IO::FederateIO_Handler* Timers::getItsFederateIO_Handler() const {
            return itsFederateIO_Handler;
        }
        
        void Timers::__setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler = p_FederateIO_Handler;
        }
        
        void Timers::_setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(itsFederateIO_Handler != NULL)
                {
                    itsFederateIO_Handler->__setItsTimers(NULL);
                }
            __setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void Timers::setItsFederateIO_Handler(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(p_FederateIO_Handler != NULL)
                {
                    p_FederateIO_Handler->_setItsTimers(this);
                }
            _setItsFederateIO_Handler(p_FederateIO_Handler);
        }
        
        void Timers::_clearItsFederateIO_Handler() {
            itsFederateIO_Handler = NULL;
        }
        
        Framework::IO::FederateIO_Handler* Timers::getItsFederateIO_Handler_1() const {
            return itsFederateIO_Handler_1;
        }
        
        void Timers::__setItsFederateIO_Handler_1(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            itsFederateIO_Handler_1 = p_FederateIO_Handler;
        }
        
        void Timers::_setItsFederateIO_Handler_1(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(itsFederateIO_Handler_1 != NULL)
                {
                    itsFederateIO_Handler_1->__setItsTimers_1(NULL);
                }
            __setItsFederateIO_Handler_1(p_FederateIO_Handler);
        }
        
        void Timers::setItsFederateIO_Handler_1(Framework::IO::FederateIO_Handler* p_FederateIO_Handler) {
            if(p_FederateIO_Handler != NULL)
                {
                    p_FederateIO_Handler->_setItsTimers_1(this);
                }
            _setItsFederateIO_Handler_1(p_FederateIO_Handler);
        }
        
        void Timers::_clearItsFederateIO_Handler_1() {
            itsFederateIO_Handler_1 = NULL;
        }
        
        void Timers::cleanUpRelations() {
            if(itsFederateIO_Handler != NULL)
                {
                    Framework::utils::Timers* p_Timers = itsFederateIO_Handler->getItsTimers();
                    if(p_Timers != NULL)
                        {
                            itsFederateIO_Handler->__setItsTimers(NULL);
                        }
                    itsFederateIO_Handler = NULL;
                }
            if(itsFederateIO_Handler_1 != NULL)
                {
                    Framework::utils::Timers* p_Timers = itsFederateIO_Handler_1->getItsTimers_1();
                    if(p_Timers != NULL)
                        {
                            itsFederateIO_Handler_1->__setItsTimers_1(NULL);
                        }
                    itsFederateIO_Handler_1 = NULL;
                }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Timers.cpp
*********************************************************************/

