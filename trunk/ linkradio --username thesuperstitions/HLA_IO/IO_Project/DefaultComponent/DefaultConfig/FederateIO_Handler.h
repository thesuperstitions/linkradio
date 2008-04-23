/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_Handler
//!	Generated Date	: Tue, 22, Apr 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.h
*********************************************************************/


#ifndef FederateIO_Handler_H 

#define FederateIO_Handler_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
#include <map>
#include <iterator>
#include <oxf/OMValueCompare.h>
// operation FederateIO_Handler(FederateFrameworkType) 
#include "Framework.h"
// link itsFederateInterface 
#include "FederateInterface.h"
// class FederateIO_Handler 
#include "IO_Handler.h"

//----------------------------------------------------------------------------
// FederateIO_Handler.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace IO {
        class Buffer;
        class C_IO_Functions;
        
    } 
    
namespace Control {
    class Federate;
    class FederateInterfaceFactory;
    
} 

namespace IO {
    class FederateIO_InputThread;
    class FederateMessage;
    class PostOffice;
    
} 

namespace Control {
    class Serializer;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class FederateIO_Handler 
        class FederateIO_Handler : public IO_Handler {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation FederateIO_Handler(FederateFrameworkType) 
            FederateIO_Handler(FederateFrameworkType frameworkType);
            
            //## auto_generated 
            FederateIO_Handler();
            
            //## auto_generated 
            virtual ~FederateIO_Handler();
        
        
        ////    Operations    ////
        public :
            
            //## operation createFederateInterface(std::string) 
            void createFederateInterface(std::string interfaceName);
            
            //## operation onTimerExpired() 
            virtual void onTimerExpired();
            
            //## operation passMessageToApplication(FederateMessage*) 
            bool passMessageToApplication(FederateMessage* federateMessage);
            
            //## operation recvMessage(int,unsigned long) 
            virtual FederateMessage* recvMessage(int timeoutSeconds, unsigned long timeoutNanoseconds);
            
            //## operation sendMessage(std::string,char*,int) 
            void sendMessage(std::string interfaceName, char* message, int messageSizeInBytes);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateFrameworkType getFrameworkType() const;
            
            //## auto_generated 
            void setFrameworkType(FederateFrameworkType p_frameworkType);
            
            //## auto_generated 
            Framework::InterfaceType getInterfaceType() const;
            
            //## auto_generated 
            void setInterfaceType(Framework::InterfaceType p_interfaceType);
            
            //## auto_generated 
            bool getRecvMessageActive() const;
            
            //## auto_generated 
            void setRecvMessageActive(bool p_recvMessageActive);
            
            //## auto_generated 
            bool getTimerExpired() const;
            
            //## auto_generated 
            void setTimerExpired(bool p_timerExpired);
            
            //## auto_generated 
            Control::Federate* getItsFederate() const;
            
            //## auto_generated 
            void setItsFederate(Control::Federate* p_Federate);
            
            //## auto_generated 
            FederateIO_InputThread* getItsFederateIO_InputThread() const;
            
            //## auto_generated 
            void setItsFederateIO_InputThread(FederateIO_InputThread* p_FederateIO_InputThread);
            
            //## auto_generated 
            std::map<std::string, FederateInterface*>::const_iterator getItsFederateInterface() const;
            
            //## auto_generated 
            std::map<std::string, FederateInterface*>::const_iterator getItsFederateInterfaceEnd() const;
            
            //## auto_generated 
            void clearItsFederateInterface();
            
            //## auto_generated 
            void removeItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            FederateInterface* getItsFederateInterface(std::string key) const;
            
            //## auto_generated 
            void addItsFederateInterface(std::string key, FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void removeItsFederateInterface(std::string key);
            
            //## auto_generated 
            Control::FederateInterfaceFactory* getItsFederateInterfaceFactory() const;
            
            //## auto_generated 
            void setItsFederateInterfaceFactory(Control::FederateInterfaceFactory* p_FederateInterfaceFactory);
            
            //## auto_generated 
            FederateMessage* getItsFederateMessage() const;
            
            //## auto_generated 
            void setItsFederateMessage(FederateMessage* p_FederateMessage);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederate(Control::Federate* p_Federate);
            
            //## auto_generated 
            void _setItsFederate(Control::Federate* p_Federate);
            
            //## auto_generated 
            void _clearItsFederate();
            
            //## auto_generated 
            void __setItsFederateIO_InputThread(FederateIO_InputThread* p_FederateIO_InputThread);
            
            //## auto_generated 
            void _setItsFederateIO_InputThread(FederateIO_InputThread* p_FederateIO_InputThread);
            
            //## auto_generated 
            void _clearItsFederateIO_InputThread();
            
            //## auto_generated 
            void _clearItsFederateInterface();
            
            //## auto_generated 
            void _removeItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void _addItsFederateInterface(std::string key, FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void _removeItsFederateInterface(std::string key);
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            FederateFrameworkType frameworkType;		//## attribute frameworkType 
            
            Framework::InterfaceType interfaceType;		//## attribute interfaceType 
            
            bool recvMessageActive;		//## attribute recvMessageActive 
            
            bool timerExpired;		//## attribute timerExpired 
            
        
        ////    Relations and components    ////
        protected :
            
            Control::Federate* itsFederate;		//## link itsFederate 
            
            
            FederateIO_InputThread* itsFederateIO_InputThread;		//## link itsFederateIO_InputThread 
            
            
            std::map<std::string, FederateInterface*> itsFederateInterface;		//## link itsFederateInterface 
            
            
            Control::FederateInterfaceFactory* itsFederateInterfaceFactory;		//## link itsFederateInterfaceFactory 
            
            
            FederateMessage* itsFederateMessage;		//## link itsFederateMessage 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.h
*********************************************************************/

