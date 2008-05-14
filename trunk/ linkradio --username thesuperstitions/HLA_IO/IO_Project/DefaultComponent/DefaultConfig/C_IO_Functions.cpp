/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::C_IO_Functions
//!	Generated Date	: Wed, 14, May 2008  
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.cpp
*********************************************************************/

#include "C_IO_Functions.h"
// dependency Federate 
#include "Federate.h"
// attribute federateInterfacePtrs 
#include "FederateInterface.h"
#include <string>

//----------------------------------------------------------------------------
// C_IO_Functions.cpp                                                                  
//----------------------------------------------------------------------------

//## package Framework::IO 

//## class C_IO_Functions 

namespace Framework {
    namespace IO {
        
        // Static class member attribute
        void * C_IO_Functions::federateInterfacePtr[100];
        // Static class member attribute
        FederateInterface* C_IO_Functions::federateInterfacePtrs( NULL );
        // Static class member attribute
        Framework::utils::InterprocessQueue* C_IO_Functions::outputQueue;
        
        C_IO_Functions::C_IO_Functions() : federateInterfaceCount(0) ,federateInterfaceNames("") {
            //#[ operation C_IO_Functions() 
            
            controlQueue = new Framework::utils::InterprocessQueue("FederatIO_Handler-Control");  
            
            // Wait until other partner of the queue is ready.            
            while (controlQueue->SynchronizeQueueUsers() == false);   
            
            //#]
        }
        
        C_IO_Functions::~C_IO_Functions() {
        }
        
        void C_IO_Functions::Configure_NTDS_Device(DEVICE_DATA* device_list_ptr) {
            //#[ operation Configure_NTDS_Device(DEVICE_DATA*) 
            
             IO_InterfaceInformationType  info;
             
             std::string s.sprintf("%s-%s-%u-%u-%u", &(device_list_ptr->name_string[0]), &(device_ptr->enet_address[0], 
               device_ptr->enet_port, device_ptr->device_id, device_ptr->port);    
               
             Framework::Control::Federate* fp = Framework::Control::getFederate();
             
             Framework::IO::FederateIO_Handler* fio = fp->getItsFederateIO_Handler();
             
             federateInterfacePtrs[federateInterfaceCount] = fio->createFederateInterface(s, sizeof(NTDS_OUTPUT_MSGS), MAX_OUT_QUE_ENTRIES); 
             
             federateInterfaceNames[federateInterfaceCount] = s;    
             federateInterfaceEnetAddresss[federateInterfaceCount] = device_ptr->enet_address; 
             federateInterfaceEnetPort[federateInterfaceCount] = device_ptr->enet_port;
            
                         
            // Build a "createFederateInterface" message and send it to the Federate I/O Handler.
            info.operation = framework::InterfaceOperationType::CreateInterface;
            info.interfaceName = s;
            info.maxMessageSize = INTERPROCESS_QUEUE_MAX_MESSAGE_SIZE_IN_BYTES;
            info.maxMessages = INTERPROCESS_QUEUE_MAX_MESSAGES_IN_QUEUE;     
            info.federateInterfacePtr = NULL;      
            info.uniqueHandle = (void*)this;      
            info.messageSizeInBytes = 0;
            info.timeoutSecs = 0; 
            info.timeoutMicrosecs = 0;
            
            if (controlQueue->getQueueState() == InterprocessQueue::QueueSynchronized) 
            { 
              // Send message with arbitrary 10 Sec timeout.
              if (controlQueue->timedAddMessage((unsigned char*)&info, sizeof(IO_InterfaceInformationType), 10, 0) == true) 
              {
                if (controlQueue->timedGetMessage((unsigned char*)&info, 10, 0) == true )
                { // Save the FederateInterface pointer with the rest of this interface' data.  
                  federateInterfacePtr[federateInterfaceCount] = info.federateInterfacePtr
            
                  InputQueue = new Framework::utils::InterprocessQueue(s + "-Input"); 
                  OutputQueue = new Framework::utils::InterprocessQueue(s + "-Output"); 
                }
              }              
            }
                          
            federateInterfaceCount++;
             
            //#]
        }
        
        int C_IO_Functions::Recv_NTDS_Mesg(int device, NTDS_QUE_ID lcl_index, NTDS_INPUT_MSGS* buffer_ptr, int timeout) {
            //#[ operation Recv_NTDS_Mesg(int,NTDS_QUE_ID,NTDS_INPUT_MSGS*,int) 
            
            Federate
            return(Framework::CEC_Msg_Type_1);
            //#]
        }
        
        void C_IO_Functions::Send_NTDS_Mesg() {
            //#[ operation Send_NTDS_Mesg() 
            
              // Serialize the message data.  
              // message = Framework::IO::serializer( getMessageType( message ), message);
            
            //#]
        }
        
        Framework::utils::InterprocessQueue* C_IO_Functions::getControlQueue() const {
            return controlQueue;
        }
        
        void C_IO_Functions::setControlQueue(Framework::utils::InterprocessQueue* p_controlQueue) {
            controlQueue = p_controlQueue;
        }
        
        int C_IO_Functions::getFederateInterfaceCount() const {
            return federateInterfaceCount;
        }
        
        void C_IO_Functions::setFederateInterfaceCount(int p_federateInterfaceCount) {
            federateInterfaceCount = p_federateInterfaceCount;
        }
        
        int C_IO_Functions::getFederateInterfaceEnetPort() const {
            return federateInterfaceEnetPort;
        }
        
        void C_IO_Functions::setFederateInterfaceEnetPort(int p_federateInterfaceEnetPort) {
            federateInterfaceEnetPort = p_federateInterfaceEnetPort;
        }
        
        std::string C_IO_Functions::getFederateInterfaceNames() const {
            return federateInterfaceNames;
        }
        
        void C_IO_Functions::setFederateInterfaceNames(std::string p_federateInterfaceNames) {
            federateInterfaceNames = p_federateInterfaceNames;
        }
        
        void * C_IO_Functions::getFederateInterfacePtr(int i1) {
            return federateInterfacePtr[i1];
        }
        
        void C_IO_Functions::setFederateInterfacePtr(int i1, void * p_federateInterfacePtr) {
            federateInterfacePtr[i1] = p_federateInterfacePtr;
        }
        
        FederateInterface* C_IO_Functions::getFederateInterfacePtrs() {
            return federateInterfacePtrs;
        }
        
        void C_IO_Functions::setFederateInterfacePtrs(FederateInterface* p_federateInterfacePtrs) {
            federateInterfacePtrs = p_federateInterfacePtrs;
        }
        
        Framework::utils::InterprocessQueue* C_IO_Functions::getInputQueue() const {
            return inputQueue;
        }
        
        void C_IO_Functions::setInputQueue(Framework::utils::InterprocessQueue* p_inputQueue) {
            inputQueue = p_inputQueue;
        }
        
        Framework::utils::InterprocessQueue* C_IO_Functions::getOutputQueue() {
            return outputQueue;
        }
        
        void C_IO_Functions::setOutputQueue(Framework::utils::InterprocessQueue* p_outputQueue) {
            outputQueue = p_outputQueue;
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.cpp
*********************************************************************/

