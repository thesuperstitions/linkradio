/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::C_IO_Functions
//!	Generated Date	: Thu, 15, May 2008  
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
        
        C_IO_Functions::C_IO_Functions() : federateInterfaceCount(0) ,federateInterfaceNames("") ,itsInterprocessQueue() {
            //#[ operation C_IO_Functions() 
            //#[ operation C_IO_Functions() 
            
            std::ifstream input_stream("FederationConfigurationFile.cfg");
            if ( input_stream.is_open() )
            {  
              int deviceIndex = 0;
              while (!input_stream.eof())
              { 
                inStream >> enetPorts[deviceIndex] >> deviceIDs >> subscribeQueueNames[deviceIndex] >> publishQueueNames[deviceIndex];  
                deviceIndex++;
              };
            }
            // proceed with processing
            //#]
        }
        
        C_IO_Functions::~C_IO_Functions() {
            //#[ operation ~C_IO_Functions() 
            //#]
            cleanUpRelations();
        }
        
        void C_IO_Functions::Configure_NTDS_Device(DEVICE_DATA* device_list_ptr) {
            //#[ operation Configure_NTDS_Device(DEVICE_DATA*) 
            
             IO_InterfaceInformationType  info; 
             unsigned int                 sizeInBytes;  
             
             // Todo Config file must contain the device enet port and its publish and subscribe interface names.
             //      These names are used to set up the interprocess queues for sending and receiving messages. 
             
             int index = findDevice(device_ptr->enet_port);
                
            
            addItsInterprocessQueue( (subscribeQueue = new Framework::utils::InterprocessQueue(subscribeQueueNames[index])) ); 
            addItsInterprocessQueue( (publishQueue = new Framework::utils::InterprocessQueue(publishQueueNames[index])) ); 
                          
            federateInterfaceCount++;
             
            //#]
        }
        
        int C_IO_Functions::Recv_NTDS_Mesg(int device, NTDS_QUE_ID lcl_index, NTDS_INPUT_MSGS* buffer_ptr, int timeout) {
            //#[ operation Recv_NTDS_Mesg(int,NTDS_QUE_ID,NTDS_INPUT_MSGS*,int) 
            
            unsigned int  sizeInBytes;  
            
             std::string queueName.sprintf("%s-%s-%u-%u-%u", &(device_list_ptr->name_string[0]), &(device_ptr->enet_address[0], 
               device_ptr->enet_port, device_ptr->device_id, device_ptr->port);   
            
            if( (InterprocessQueue* ipq = getItsInterprocessQueue(queueName.c_str()) ) != NULL)
            { 
              if ipq->timedGetMessage(((unsigned char*)buffer_ptr->io_pkt.address), &sizeInBytes, 10, 0) == true )
              {   
                // De-serialize the message data.  
                // message = Framework::IO::deserializer( ((unsigned char*)buffer_ptr->io_pkt.address));
                return(OK);
              } 
            }
            return(CHANNEL_READINESS_ERR);
            
            //#]
        }
        
        void C_IO_Functions::Send_NTDS_Mesg(int device, NTDS_OUTPUT_MSGS* buffer_ptr, int priority) {
            //#[ operation Send_NTDS_Mesg(int,NTDS_OUTPUT_MSGS*,int) 
            
            unsigned int  sizeInBytes;
            
             std::string queueName.sprintf("%s-%s-%u-%u-%u", &(device_list_ptr->name_string[0]), &(device_ptr->enet_address[0], 
               device_ptr->enet_port, device_ptr->device_id, device_ptr->port);   
            
            if( (InterprocessQueue* ipq = getItsInterprocessQueue(queueName.c_str()) ) != NULL)
            { 
              // Serialize the message data.  
              // message = Framework::IO::serializer( message);
            
              if (ipq->timeAddMessage(((unsigned char*)buffer_ptr->io_pkt.address), buffer_ptr->io_pkt.req_size, 10, 0) == true )
              {   
                // De-serialize the message data.  
                // message = Framework::IO::deserializer( ((unsigned char*)buffer_ptr->io_pkt.address));
                return(OK);
              } 
            }
            return(CHANNEL_READINESS_ERR);
            
            
            //#]
        }
        
        int C_IO_Functions::findDeviceIndex(int inputEnetPort) {
            //#[ operation findDeviceIndex(int) 
            for (i=0; i < MAX_FEDERATE_INTERFACE_DEVICES; i++)
            {
              if (enetPorts[i] == inputEnetPort)
                return(i);
            }
            return(-1);
            //#]
        }
        
        int C_IO_Functions::getDeviceIDs(int i1) const {
            return deviceIDs[i1];
        }
        
        void C_IO_Functions::setDeviceIDs(int i1, int p_deviceIDs) {
            deviceIDs[i1] = p_deviceIDs;
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
        
        Framework::utils::InterprocessQueue* C_IO_Functions::getPublishQueue() const {
            return publishQueue;
        }
        
        void C_IO_Functions::setPublishQueue(Framework::utils::InterprocessQueue* p_publishQueue) {
            publishQueue = p_publishQueue;
        }
        
        char* C_IO_Functions::getPublishQueueNames(int i1) const {
            return publishQueueNames[i1];
        }
        
        void C_IO_Functions::setPublishQueueNames(int i1, char* p_publishQueueNames) {
            publishQueueNames[i1] = p_publishQueueNames;
        }
        
        char* C_IO_Functions::getSubscribeQueueNames(int i1) const {
            return subscribeQueueNames[i1];
        }
        
        void C_IO_Functions::setSubscribeQueueNames(int i1, char* p_subscribeQueueNames) {
            subscribeQueueNames[i1] = p_subscribeQueueNames;
        }
        
        C_IO_Functions::std::map<char getItsInterprocessQueue[100] , Framework::utils::InterprocessQueue*>::const_iterator() const {
            std::map<char %s[100] , Framework::utils::InterprocessQueue*>::const_iterator iter;
            iter = itsInterprocessQueue.begin();
            return iter;
        }
        
        C_IO_Functions::std::map<char getItsInterprocessQueueEnd[100] , Framework::utils::InterprocessQueue*>::const_iterator() const {
            return itsInterprocessQueue.end();
        }
        
        void C_IO_Functions::_clearItsInterprocessQueue() {
            itsInterprocessQueue.clear();
        }
        
        void C_IO_Functions::clearItsInterprocessQueue() {
            std::map<char %s[100] , Framework::utils::InterprocessQueue*>::const_iterator iter;
            iter = itsInterprocessQueue.begin();
            while (iter != itsInterprocessQueue.end()){
                iter++;
            }
            _clearItsInterprocessQueue();
        }
        
        void C_IO_Functions::_removeItsInterprocessQueue(Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            std::map<char %s[100] , Framework::utils::InterprocessQueue*>::iterator pos = std::find_if(itsInterprocessQueue.begin(), itsInterprocessQueue.end(),OMValueCompare<const char %s[100] ,Framework::utils::InterprocessQueue*>(p_InterprocessQueue));
            if (pos != itsInterprocessQueue.end()) {
            	itsInterprocessQueue.erase(pos);
            }
        }
        
        void C_IO_Functions::removeItsInterprocessQueue(Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            if(p_InterprocessQueue != NULL)
                {
                    p_InterprocessQueue->__setItsC_IO_Functions(NULL);
                }
            _removeItsInterprocessQueue(p_InterprocessQueue);
        }
        
        Framework::utils::InterprocessQueue* C_IO_Functions::getItsInterprocessQueue(char key[100] ) const {
            return (itsInterprocessQueue.find(key) != itsInterprocessQueue.end() ? (*itsInterprocessQueue.find(key)).second : NULL);
        }
        
        void C_IO_Functions::_addItsInterprocessQueue(char key[100] , Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            itsInterprocessQueue.insert(std::map<char %s[100] , Framework::utils::InterprocessQueue*>::value_type(key, p_InterprocessQueue));
        }
        
        void C_IO_Functions::addItsInterprocessQueue(char key[100] , Framework::utils::InterprocessQueue* p_InterprocessQueue) {
            if(p_InterprocessQueue != NULL)
                {
                    p_InterprocessQueue->_setItsC_IO_Functions(this);
                }
            _addItsInterprocessQueue(key, p_InterprocessQueue);
        }
        
        void C_IO_Functions::_removeItsInterprocessQueue(char key[100] ) {
            itsInterprocessQueue.erase(key);
        }
        
        void C_IO_Functions::removeItsInterprocessQueue(char key[100] ) {
            Framework::utils::InterprocessQueue* p_InterprocessQueue = getItsInterprocessQueue(key);
            if(p_InterprocessQueue != NULL)
                {
                    p_InterprocessQueue->_setItsC_IO_Functions(NULL);
                }
            _removeItsInterprocessQueue(key);
        }
        
        void C_IO_Functions::cleanUpRelations() {
            {
                std::map<char %s[100] , Framework::utils::InterprocessQueue*>::const_iterator iter;
                iter = itsInterprocessQueue.begin();
                while (iter != itsInterprocessQueue.end()){
                    Framework::IO::C_IO_Functions* p_C_IO_Functions = ((*iter).second)->getItsC_IO_Functions();
                    if(p_C_IO_Functions != NULL)
                        {
                            ((*iter).second)->__setItsC_IO_Functions(NULL);
                        }
                    iter++;
                }
                itsInterprocessQueue.clear();
            }
        }
        
    }
}


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.cpp
*********************************************************************/

