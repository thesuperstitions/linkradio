/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::C_IO_Functions
//!	Generated Date	: Thu, 15, May 2008  
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.h
*********************************************************************/


#ifndef C_IO_Functions_H 

#define C_IO_Functions_H 

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
// link itsInterprocessQueue 
#include "InterprocessQueue.h"
#include "ntdsTypes.h"

//----------------------------------------------------------------------------
// C_IO_Functions.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class Federate;
        
    } 
    
namespace IO {
    class FederateInterface;
}

}


//## package Framework::IO 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace Framework {
    namespace IO {
        //## class C_IO_Functions 
        class C_IO_Functions  {
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## operation C_IO_Functions() 
            C_IO_Functions();
            
            //## operation ~C_IO_Functions() 
            ~C_IO_Functions();
        
        
        ////    Operations    ////
        public :
            
            //## operation Configure_NTDS_Device(DEVICE_DATA*) 
            static void Configure_NTDS_Device(DEVICE_DATA* device_list_ptr);
            
            //## operation Recv_NTDS_Mesg(int,NTDS_QUE_ID,NTDS_INPUT_MSGS*,int) 
            static int Recv_NTDS_Mesg(int device, NTDS_QUE_ID lcl_index, NTDS_INPUT_MSGS* buffer_ptr, int timeout);
            
            //## operation Send_NTDS_Mesg(int,NTDS_OUTPUT_MSGS*,int) 
            void Send_NTDS_Mesg(int device, NTDS_OUTPUT_MSGS* buffer_ptr, int priority);
            
            //## operation findDeviceIndex(int) 
            int findDeviceIndex(int inputEnetPort);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            int getDeviceIDs(int i1) const;
            
            //## auto_generated 
            void setDeviceIDs(int i1, int p_deviceIDs);
            
            //## auto_generated 
            int getFederateInterfaceEnetPort() const;
            
            //## auto_generated 
            void setFederateInterfaceEnetPort(int p_federateInterfaceEnetPort);
            
            //## auto_generated 
            std::string getFederateInterfaceNames() const;
            
            //## auto_generated 
            void setFederateInterfaceNames(std::string p_federateInterfaceNames);
            
            //## auto_generated 
            static void * getFederateInterfacePtr(int i1);
            
            //## auto_generated 
            static void setFederateInterfacePtr(int i1, void * p_federateInterfacePtr);
            
            //## auto_generated 
            static virtual FederateInterface* getFederateInterfacePtrs();
            
            //## auto_generated 
            static virtual void setFederateInterfacePtrs(FederateInterface* p_federateInterfacePtrs);
            
            //## auto_generated 
            Framework::utils::InterprocessQueue* getPublishQueue() const;
            
            //## auto_generated 
            void setPublishQueue(Framework::utils::InterprocessQueue* p_publishQueue);
            
            //## auto_generated 
            char* getPublishQueueNames(int i1) const;
            
            //## auto_generated 
            void setPublishQueueNames(int i1, char* p_publishQueueNames);
            
            //## auto_generated 
            char* getSubscribeQueueNames(int i1) const;
            
            //## auto_generated 
            void setSubscribeQueueNames(int i1, char* p_subscribeQueueNames);
            
            //## auto_generated 
            std::map<char getItsInterprocessQueue[100] , utils::InterprocessQueue*>::const_iterator() const;
            
            //## auto_generated 
            std::map<char getItsInterprocessQueueEnd[100] , utils::InterprocessQueue*>::const_iterator() const;
            
            //## auto_generated 
            void clearItsInterprocessQueue();
            
            //## auto_generated 
            void removeItsInterprocessQueue(utils::InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            utils::InterprocessQueue* getItsInterprocessQueue(char key[100] ) const;
            
            //## auto_generated 
            void addItsInterprocessQueue(char key[100] , utils::InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            void removeItsInterprocessQueue(char key[100] );
        
        protected :
            
            //## auto_generated 
            int getFederateInterfaceCount() const;
            
            //## auto_generated 
            void setFederateInterfaceCount(int p_federateInterfaceCount);
        
        
        ////    Framework operations    ////
        public :
            
            //## auto_generated 
            void _clearItsInterprocessQueue();
            
            //## auto_generated 
            void _removeItsInterprocessQueue(utils::InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            void _addItsInterprocessQueue(char key[100] , utils::InterprocessQueue* p_InterprocessQueue);
            
            //## auto_generated 
            void _removeItsInterprocessQueue(char key[100] );
        
        protected :
            
            //## auto_generated 
            void cleanUpRelations();
        
        
        ////    Attributes    ////
        protected :
            
            int deviceIDs[100];		//## attribute deviceIDs 
            
            int federateInterfaceCount;		//## attribute federateInterfaceCount 
            
            int federateInterfaceEnetPort;		//## attribute federateInterfaceEnetPort 
            
            std::string federateInterfaceNames;		//## attribute federateInterfaceNames 
            
            static void * federateInterfacePtr[100];		//## attribute federateInterfacePtr 
            
            static FederateInterface* federateInterfacePtrs;		//## attribute federateInterfacePtrs 
            
            Framework::utils::InterprocessQueue* publishQueue;		//## attribute publishQueue 
            
            char* publishQueueNames[100];		//## attribute publishQueueNames 
            
            char* subscribeQueueNames[100];		//## attribute subscribeQueueNames 
            
        
        ////    Relations and components    ////
        protected :
            
            std::map<char itsInterprocessQueue[100] , utils::InterprocessQueue*>;		//## link itsInterprocessQueue 
            
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.h
*********************************************************************/

