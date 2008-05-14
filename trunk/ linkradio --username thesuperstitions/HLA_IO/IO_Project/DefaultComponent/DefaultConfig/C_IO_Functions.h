/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::C_IO_Functions
//!	Generated Date	: Wed, 14, May 2008  
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
            
            //## auto_generated 
            ~C_IO_Functions();
        
        
        ////    Operations    ////
        public :
            
            //## operation Configure_NTDS_Device(DEVICE_DATA*) 
            static void Configure_NTDS_Device(DEVICE_DATA* device_list_ptr);
            
            //## operation Recv_NTDS_Mesg(int,NTDS_QUE_ID,NTDS_INPUT_MSGS*,int) 
            static int Recv_NTDS_Mesg(int device, NTDS_QUE_ID lcl_index, NTDS_INPUT_MSGS* buffer_ptr, int timeout);
            
            //## operation Send_NTDS_Mesg() 
            void Send_NTDS_Mesg();
        
        
        ////    Additional operations    ////
        public :
            
            //## auto_generated 
            Framework::utils::InterprocessQueue* getControlQueue() const;
            
            //## auto_generated 
            void setControlQueue(Framework::utils::InterprocessQueue* p_controlQueue);
            
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
            Framework::utils::InterprocessQueue* getInputQueue() const;
            
            //## auto_generated 
            void setInputQueue(Framework::utils::InterprocessQueue* p_inputQueue);
            
            //## auto_generated 
            static Framework::utils::InterprocessQueue* getOutputQueue();
            
            //## auto_generated 
            static void setOutputQueue(Framework::utils::InterprocessQueue* p_outputQueue);
        
        protected :
            
            //## auto_generated 
            int getFederateInterfaceCount() const;
            
            //## auto_generated 
            void setFederateInterfaceCount(int p_federateInterfaceCount);
        
        
        ////    Attributes    ////
        protected :
            
            Framework::utils::InterprocessQueue* controlQueue;		//## attribute controlQueue 
            
            int federateInterfaceCount;		//## attribute federateInterfaceCount 
            
            int federateInterfaceEnetPort;		//## attribute federateInterfaceEnetPort 
            
            std::string federateInterfaceNames;		//## attribute federateInterfaceNames 
            
            static void * federateInterfacePtr[100];		//## attribute federateInterfacePtr 
            
            static FederateInterface* federateInterfacePtrs;		//## attribute federateInterfacePtrs 
            
            Framework::utils::InterprocessQueue* inputQueue;		//## attribute inputQueue 
            
            static Framework::utils::InterprocessQueue* outputQueue;		//## attribute outputQueue 
            
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.h
*********************************************************************/

