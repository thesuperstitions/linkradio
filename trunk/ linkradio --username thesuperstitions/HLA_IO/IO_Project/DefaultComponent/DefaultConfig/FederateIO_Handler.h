/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::FederateIO_Handler
//!	Generated Date	: Wed, 14, May 2008  
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
// class FederateIO_Handler 
#include "Thread.h"

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

namespace utils {
    class InterprocessQueue;
    
} 

namespace IO {
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
        class FederateIO_Handler : public IO_Handler, public utils::Thread {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation FederateIO_Handler(FederateFrameworkType) 
            FederateIO_Handler(FederateFrameworkType frameworkType);
            
            //## auto_generated 
            FederateIO_Handler();
            
            //## operation ~FederateIO_Handler() 
            ~FederateIO_Handler();
        
        
        ////    Operations    ////
        public :
            
            //## operation createFederateInterface(std::string,unsigned long,unsigned long) 
            FederateInterface* createFederateInterface(std::string interfaceName, unsigned long maxMessageSize, unsigned long maxMessages);
            
            //## operation threadOperation() 
            void threadOperation();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            bool getExitFlag() const;
            
            //## auto_generated 
            void setExitFlag(bool p_exitFlag);
            
            //## auto_generated 
            FederateFrameworkType getFrameworkType() const;
            
            //## auto_generated 
            void setFrameworkType(FederateFrameworkType p_frameworkType);
            
            //## auto_generated 
            Framework::InterfaceType getInterfaceType() const;
            
            //## auto_generated 
            void setInterfaceType(Framework::InterfaceType p_interfaceType);
            
            //## auto_generated 
            Control::Federate* getItsFederate() const;
            
            //## auto_generated 
            void setItsFederate(Control::Federate* p_Federate);
            
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
            utils::InterprocessQueue* getItsInterprocessQueue() const;
            
            //## auto_generated 
            void setItsInterprocessQueue(utils::InterprocessQueue* p_InterprocessQueue);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederate(Control::Federate* p_Federate);
            
            //## auto_generated 
            void _setItsFederate(Control::Federate* p_Federate);
            
            //## auto_generated 
            void _clearItsFederate();
            
            //## auto_generated 
            void _clearItsFederateInterface();
            
            //## auto_generated 
            void _removeItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void _addItsFederateInterface(std::string key, FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void _removeItsFederateInterface(std::string key);
            
            //## auto_generated 
            void __setItsInterprocessQueue(utils::InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            void _setItsInterprocessQueue(utils::InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            void _clearItsInterprocessQueue();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            bool exitFlag;		//## attribute exitFlag 
            
            FederateFrameworkType frameworkType;		//## attribute frameworkType 
            
            Framework::InterfaceType interfaceType;		//## attribute interfaceType 
            
        
        ////    Relations and components    ////
        protected :
            
            Control::Federate* itsFederate;		//## link itsFederate 
            
            
            std::map<std::string, FederateInterface*> itsFederateInterface;		//## link itsFederateInterface 
            
            
            Control::FederateInterfaceFactory* itsFederateInterfaceFactory;		//## link itsFederateInterfaceFactory 
            
            
            utils::InterprocessQueue* itsInterprocessQueue;		//## link itsInterprocessQueue 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.h
*********************************************************************/

