//*********************************************************************************  
//
//	File:				Framework::Federate::Federate  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Thu, 14, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef Federate_H 

#define Federate_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <oxf/OMValueCompare.h>
// operation Federate(FederateFrameworkType) 
#include "Framework.h"
// link itsFederateInterface 
#include "FederateInterface.h"

//----------------------------------------------------------------------------
// Federate.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Federate {
        class FederateInterfaceFactory;
        
    } 
    
namespace IO {
    class PostOffice;
}

}


//## package Framework::Federate 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace Federate {
        //## class Federate 
        class Federate  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation Federate(FederateFrameworkType) 
            Federate(FederateFrameworkType fedFrameworkType);
            
            //## auto_generated 
            virtual ~Federate();
        
        
        ////    Operations    ////
        public :
            
            //## operation getType() const 
            virtual FederateType getType() const;
            
            //## operation useCase_42_1_announcePublication() 
            void useCase_42_1_announcePublication();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            FederateInterfaceFactory* getFederateInterfaceFactory() const;
            
            //## auto_generated 
            void setFederateInterfaceFactory(FederateInterfaceFactory* p_federateInterfaceFactory);
            
            //## auto_generated 
            std::string getInterfaceName() const;
            
            //## auto_generated 
            void setInterfaceName(std::string p_interfaceName);
            
            //## auto_generated 
            std::map<std::string, IO::FederateInterface*>::const_iterator getItsFederateInterface() const;
            
            //## auto_generated 
            std::map<std::string, IO::FederateInterface*>::const_iterator getItsFederateInterfaceEnd() const;
            
            //## auto_generated 
            void clearItsFederateInterface();
            
            //## auto_generated 
            void removeItsFederateInterface(IO::FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            IO::FederateInterface* getItsFederateInterface(std::string key) const;
            
            //## auto_generated 
            void addItsFederateInterface(std::string key, IO::FederateInterface* p_FederateInterface);
            
            //## auto_generated 
            void removeItsFederateInterface(std::string key);
            
            //## auto_generated 
            FederateInterfaceFactory* getItsFederateInterfaceFactory() const;
            
            //## auto_generated 
            void setItsFederateInterfaceFactory(FederateInterfaceFactory* p_FederateInterfaceFactory);
            
            //## auto_generated 
            IO::PostOffice* getItsPostOffice() const;
            
            //## auto_generated 
            void setItsPostOffice(IO::PostOffice* p_PostOffice);
        
        protected :
            
            //## auto_generated 
            FederateFrameworkType getFederateFrameworkType() const;
            
            //## auto_generated 
            void setFederateFrameworkType(FederateFrameworkType p_federateFrameworkType);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void __setItsFederateInterfaceFactory(FederateInterfaceFactory* p_FederateInterfaceFactory);
            
            //## auto_generated 
            void _setItsFederateInterfaceFactory(FederateInterfaceFactory* p_FederateInterfaceFactory);
            
            //## auto_generated 
            void _clearItsFederateInterfaceFactory();
            
            //## auto_generated 
            void __setItsPostOffice(IO::PostOffice* p_PostOffice);
            
            //## auto_generated 
            void _setItsPostOffice(IO::PostOffice* p_PostOffice);
            
            //## auto_generated 
            void _clearItsPostOffice();
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            FederateFrameworkType federateFrameworkType;		//## attribute federateFrameworkType 
            
            FederateInterfaceFactory* federateInterfaceFactory;		//## attribute federateInterfaceFactory 
            
            std::string interfaceName;		//## attribute interfaceName 
            
        
        ////    Relations and components    ////
        protected :
            
            std::map<std::string, IO::FederateInterface*> itsFederateInterface;		//## link itsFederateInterface 
            
            
            FederateInterfaceFactory* itsFederateInterfaceFactory;		//## link itsFederateInterfaceFactory 
            
            
            IO::PostOffice* itsPostOffice;		//## link itsPostOffice 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Federate.h
*********************************************************************/

