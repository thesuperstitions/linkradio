/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::C_IO_Functions
//!	Generated Date	: Tue, 20, May 2008  
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.h
*********************************************************************/


#ifndef C_IO_Functions_H 

#define C_IO_Functions_H 

#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Configuration.h"
#include "RTI\RTI1516.h"
#include "IO.h"
#include "ntdsTypes.h"
#include "ntds_comm_.h"

//----------------------------------------------------------------------------
// C_IO_Functions.h                                                                  
//----------------------------------------------------------------------------


namespace framework {
    
    namespace Control {
        class Federate;
    }
    
}


//## package framework::io 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework {
    namespace io {
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
            static int Send_NTDS_Mesg(int device, NTDS_OUTPUT_MSGS* buffer_ptr, int priority);
            
            //## operation findDeviceIndex(int) 
            static int findDeviceIndex(int inputEnetPort);
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            static void * getPublishQueues(int i1);
            
            //## auto_generated 
            static void setPublishQueues(int i1, void * p_publishQueues);
            
            //## auto_generated 
            static void * getSubscribeQueues(int i1);
            
            //## auto_generated 
            static void setSubscribeQueues(int i1, void * p_subscribeQueues);
        
        
        ////    Attributes    ////
        protected :
            
            static int federateInterfaceCount;		//## attribute federateInterfaceCount 
            
            static int federateInterfaceDeviceIDs[100];		//## attribute federateInterfaceDeviceIDs 
            
            static int federateInterfaceEnetPorts[100];		//## attribute federateInterfaceEnetPorts 
            
            static char* federateInterfaceNames[100];		//## attribute federateInterfaceNames 
            
            static void * federateInterfacePtrs[100];		//## attribute federateInterfacePtrs 
            
            static unsigned long maxMessageCount[100];		//## attribute maxMessageCount 
            
            static unsigned int maxMessageSize[100];		//## attribute maxMessageSize 
            
            static char* publishQueueNames[100];		//## attribute publishQueueNames 
            
            static void * publishQueues[100];		//## attribute publishQueues 
            
            static char* subscribeQueueNames[100];		//## attribute subscribeQueueNames 
            
            static void * subscribeQueues[100];		//## attribute subscribeQueues 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.h
*********************************************************************/

