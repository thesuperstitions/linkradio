/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::C_IO_Functions
//!	Generated Date	: Tue, 20, May 2008  
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.cpp
*********************************************************************/

#include "C_IO_Functions.h"
// dependency Federate 
#include "Federate.h"
#include <string>
#include <fstream>

//----------------------------------------------------------------------------
// C_IO_Functions.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework::io 

//## class C_IO_Functions 

namespace framework {
    namespace io {
        
        // Static class member attribute
        int C_IO_Functions::federateInterfaceCount( 0 );
        // Static class member attribute
        int C_IO_Functions::federateInterfaceDeviceIDs[100];
        // Static class member attribute
        int C_IO_Functions::federateInterfaceEnetPorts[100];
        // Static class member attribute
        char* C_IO_Functions::federateInterfaceNames[100];
        // Static class member attribute
        void * C_IO_Functions::federateInterfacePtrs[100];
        // Static class member attribute
        unsigned long C_IO_Functions::maxMessageCount[100];
        // Static class member attribute
        unsigned int C_IO_Functions::maxMessageSize[100];
        // Static class member attribute
        char* C_IO_Functions::publishQueueNames[100];
        // Static class member attribute
        void * C_IO_Functions::publishQueues[100];
        // Static class member attribute
        char* C_IO_Functions::subscribeQueueNames[100];
        // Static class member attribute
        void * C_IO_Functions::subscribeQueues[100];
        
        C_IO_Functions::C_IO_Functions() {
            //#[ operation C_IO_Functions() 
            //#[ operation C_IO_Functions() 
            
            std::ifstream input_stream("FederationConfigurationFile.cfg");
            if ( input_stream.is_open() )
            {  
              int deviceIndex = 0;
              while (!input_stream.eof())
              { 
                input_stream >> federateInterfaceEnetPorts[deviceIndex] >> federateInterfaceDeviceIDs[deviceIndex] >> subscribeQueueNames[deviceIndex] >> publishQueueNames[deviceIndex] 
                         >> maxMessageSize[deviceIndex] >> maxMessageCount[deviceIndex];  
                deviceIndex++;
              };
            }
            // proceed with processing
            //#]
        }
        
        C_IO_Functions::~C_IO_Functions() {
            //#[ operation ~C_IO_Functions() 
            //#]
        }
        
        void C_IO_Functions::Configure_NTDS_Device(DEVICE_DATA* device_list_ptr) {
            //#[ operation Configure_NTDS_Device(DEVICE_DATA*) 
             
             // Todo Config file must contain the device enet port and its publish and subscribe interface names.
             //      These names are used to set up the interprocess queues for sending and receiving messages. 
             
             int index = findDeviceIndex(1);  //device_list_ptr->enet_port
                
            
            subscribeQueues[index] = (void*) new framework::utils::InterprocessQueue(subscribeQueueNames[index], maxMessageSize[index], maxMessageCount[index]); 
            publishQueues[index]    = (void*) new framework::utils::InterprocessQueue(publishQueueNames[index], maxMessageSize[index], maxMessageCount[index]); 
                          
            federateInterfaceCount++;
             
            //#]
        }
        
        int C_IO_Functions::Recv_NTDS_Mesg(int device, NTDS_QUE_ID lcl_index, NTDS_INPUT_MSGS* buffer_ptr, int timeout) {
            //#[ operation Recv_NTDS_Mesg(int,NTDS_QUE_ID,NTDS_INPUT_MSGS*,int) 
            
            unsigned int                         sizeInBytes; 
            framework::utils::InterprocessQueue* ipq; 
            
            if( (ipq = (framework::utils::InterprocessQueue*)publishQueues[findDeviceIndex(device)]) != NULL)
            { 
              if (ipq->timedGetMessage(((unsigned char*)buffer_ptr->io_pkt.address), &sizeInBytes, 10, 0) == true )
              {   
                // De-serialize the message data.  
                // message = Framework::io::deserializer( ((unsigned char*)buffer_ptr->io_pkt.address));
                return(OK);
              } 
            }
            return(ERROR);
            
            //#]
        }
        
        int C_IO_Functions::Send_NTDS_Mesg(int device, NTDS_OUTPUT_MSGS* buffer_ptr, int priority) {
            //#[ operation Send_NTDS_Mesg(int,NTDS_OUTPUT_MSGS*,int) 
            
            framework::utils::InterprocessQueue* ipq;
            
            if( (ipq = (framework::utils::InterprocessQueue*)publishQueues[findDeviceIndex(device)]) != NULL)
            { 
              // Serialize the message data.  
              // message = Framework::io::serializer( message);
            
              if (ipq->timedAddMessage(((unsigned char*)buffer_ptr->io_pkt.address), buffer_ptr->io_pkt.req_size, 10, 0) == true )
              {   
                // De-serialize the message data.  
                // message = Framework::io::deserializer( ((unsigned char*)buffer_ptr->io_pkt.address));
                return(OK);
              } 
            }
            return(ERROR);
            
            
            //#]
        }
        
        int C_IO_Functions::findDeviceIndex(int inputEnetPort) {
            //#[ operation findDeviceIndex(int) 
            
            int i;
            
            for (i=0; i < MAX_FEDERATE_INTERFACE_DEVICES; i++)
            {
              if (federateInterfaceEnetPorts[i] == inputEnetPort)
                return(i);
            }
            return(-1);
            //#]
        }
        
        void * C_IO_Functions::getPublishQueues(int i1) {
            return publishQueues[i1];
        }
        
        void C_IO_Functions::setPublishQueues(int i1, void * p_publishQueues) {
            publishQueues[i1] = p_publishQueues;
        }
        
        void * C_IO_Functions::getSubscribeQueues(int i1) {
            return subscribeQueues[i1];
        }
        
        void C_IO_Functions::setSubscribeQueues(int i1, void * p_subscribeQueues) {
            subscribeQueues[i1] = p_subscribeQueues;
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.cpp
*********************************************************************/

