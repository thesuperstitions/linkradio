/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::IO::PostOffice
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\PostOffice.h
*********************************************************************/


#ifndef PostOffice_H 

#define PostOffice_H 

#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
// operation sendMessage(FrameworkMessage*) 
#include "framework.h"

//----------------------------------------------------------------------------
// PostOffice.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace Control {
        class Federate;
        
    } 
    
namespace IO {
    class FederateInterface;
}

}


//## package framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
    namespace IO {
        //## class PostOffice 
        class PostOffice  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            PostOffice();
            
            //## auto_generated 
            virtual ~PostOffice();
        
        
        ////    Operations    ////
        public :
            
            //## operation announcePublication(FederateInterface*) 
            virtual void announcePublication(FederateInterface* interface)=0;
            
            //## operation announceSubscription(FederateInterface*) 
            virtual void announceSubscription(FederateInterface* interface)=0;
            
            //## operation findFederateInterface() 
            virtual FederateInterface* findFederateInterface();
            
            //## operation sendMessage(char*,int,FederateInterface*) 
            virtual void sendMessage(char* message, int messageSizeInBytes, FederateInterface* federateInterface)=0;
            
            //## operation sendMessage(FrameworkMessage*) 
            virtual void sendMessage(FrameworkMessage* message)=0;
            
            //## operation unsubscribe(FederateInterface*) 
            virtual void unsubscribe(FederateInterface* interface)=0;
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Control::Federate* getTheFederate() const;
            
            //## auto_generated 
            void setTheFederate(Control::Federate* p_Federate);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setTheFederate(Control::Federate* p_Federate);
            
            //## auto_generated 
            void _setTheFederate(Control::Federate* p_Federate);
            
            //## auto_generated 
            void _clearTheFederate();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Relations and components    ////
        protected :
            
            Control::Federate* theFederate;		//## link theFederate 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\PostOffice.h
*********************************************************************/

