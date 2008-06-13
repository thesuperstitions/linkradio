/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::IO::FederateIO_Handler
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.h
*********************************************************************/


#ifndef FederateIO_Handler_H 

#define FederateIO_Handler_H 

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
// operation FederateIO_Handler(FederateFrameworkType) 
#include "framework.h"
// link itsFederateInterface 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// FederateIO_Handler.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace IO {
        class C_IO_Functions;
        
    } 
    
namespace Control {
    class Federate;
    class FederateInterfaceFactory;
    
} 

namespace IO {
    class PostOffice;
}

}


//## package framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
    namespace IO {
        //## class FederateIO_Handler 
        class FederateIO_Handler  {
        
        
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
            
            //## operation createFederateInterface(int,std::string,unsigned long,unsigned long,FederateInterfaceType) 
            FederateInterface* createFederateInterface(int interfaceID, int unitNumber, std::string interfaceName, unsigned long maxMessageSize, unsigned long maxMessages, FederateInterfaceType federateInterfaceType);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateFrameworkType getFrameworkType() const;
            
            //## auto_generated 
            void setFrameworkType(FederateFrameworkType p_frameworkType);
            
            //## auto_generated 
            framework::InterfaceType getInterfaceType() const;
            
            //## auto_generated 
            void setInterfaceType(framework::InterfaceType p_interfaceType);
            
            //## auto_generated 
            Control::Federate* getItsFederate() const;
            
            //## auto_generated 
            void setItsFederate(Control::Federate* p_Federate);
            
            //## auto_generated 
            std::map<int, FederateInterface*>::const_iterator getItsFederateInterface() const;
            
            //## auto_generated 
            std::map<int, FederateInterface*>::const_iterator getItsFederateInterfaceEnd() const;
            
            //## auto_generated 
            void clearItsFederateInterface();
            
            //## auto_generated 
            void removeItsFederateInterface(FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            FederateInterface* getItsFederateInterface(int key) const;
            
            //## auto_generated 
            void addItsFederateInterface(int key, FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void removeItsFederateInterface(int key);
            
            //## auto_generated 
            Control::FederateInterfaceFactory* getItsFederateInterfaceFactory() const;
            
            //## auto_generated 
            void setItsFederateInterfaceFactory(Control::FederateInterfaceFactory* p_FederateInterfaceFactory);
        
        
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
            void _addItsFederateInterface(int key, FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void _removeItsFederateInterface(int key);
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            FederateFrameworkType frameworkType;		//## attribute frameworkType 
            
            framework::InterfaceType interfaceType;		//## attribute interfaceType 
            
        
        ////    Relations and components    ////
        protected :
            
            Control::Federate* itsFederate;		//## link itsFederate 
            
            
            std::map<int, FederateInterface*> itsFederateInterface;		//## link itsFederateInterface 
            
            
            Control::FederateInterfaceFactory* itsFederateInterfaceFactory;		//## link itsFederateInterfaceFactory 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FederateIO_Handler.h
*********************************************************************/

