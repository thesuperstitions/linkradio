/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Framework::IO::C_IO_Functions
//!	Generated Date	: Tue, 22, Apr 2008  
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

//----------------------------------------------------------------------------
// C_IO_Functions.h                                                                  
//----------------------------------------------------------------------------


namespace Framework {
    
    namespace Control {
        class Federate;
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
        public :
            //## type DEVICE_DATA 
            typedef device_node DEVICE_DATA;
            
            //## type device_node 
            struct device_node {
                unsigned int attribute_0 : 26;		//## attribute attribute_0 
                NIO_BD_CONFIG board;		//## attribute board 
                int device_id;		//## attribute device_id 
                char enet_address[ENET_ADDRESS_SIZE];		//## attribute enet_address 
                int enet_port;		//## attribute enet_port 
                NTDS_CTRL_FUNC function;		//## attribute function 
                unsigned int in_signal_queue : 1;		//## attribute in_signal_queue 
                // Must be a multiple 4 
                char name_string[12];		//## attribute name_string 
                device_node * next;		//## attribute next 
                unsigned int no_remote_enable : 1;		//## attribute no_remote_enable 
                unsigned int out_signal_queue : 1;		//## attribute out_signal_queue 
                unsigned int packed_output_queue : 1;		//## attribute packed_output_queue 
                int port;		//## attribute port 
                unsigned int raw_input_que_type : 1;		//## attribute raw_input_que_type 
                unsigned int redundant_channel_flag : 1;		//## attribute redundant_channel_flag 
                unsigned int user1;		//## attribute user1 
                unsigned int user10;		//## attribute user10 
                unsigned int user2;		//## attribute user2 
                unsigned int user3;		//## attribute user3 
                unsigned int user4;		//## attribute user4 
                unsigned int user5;		//## attribute user5 
                unsigned int user6;		//## attribute user6 
                unsigned int user7;		//## attribute user7 
                unsigned int user8;		//## attribute user8 
                unsigned int user9;		//## attribute user9 
            };
            
            //#[ ignore 
            typedef struct   /* structure of NIO Configuration Packet */
            {
                    /* Primary port address is Used as backplane id on VME driver */
               unsigned int   primary_ntds_port_address;
               unsigned int   secondary_ntds_port_address;
               int            address_modifier;
               char           enet_address[ENET_ADDRESS_SIZE];
               int            enet_port;
             
               unsigned int                       :  3,
                            io_mode               :  4, /* CAT I, CAT II, CAT III */
                            interrupt_level       :  3, /* VME interrupt level    */
                            manual_ei_mode        :  1, /* Auto or Manual         */
                            word_size             :  4, /* BYTE, WORD, LONG WORD  */
                            io_type               :  4, /* A, B, C, D, or E       */
                            int_enable            :  1, /* Enable interrupts T/F  */
                            passive_mode          :  1, /* passive tap            */
                            server_enable         :  1, /* enables the vme server */
                            driver_type           :  4, /* VME, ANTARES, GET,     */
                            secondary_driver_type :  4, /* VME, ANTARES, GET,     */
                            init_mode             :  2; /* LOCAL, REMOTE, SATELLITE_INTERFACE, or TEST */
            } NIO_BD_CONFIG;
            
            typedef struct
            {
               int  (*init_comm) (int, int);
               int  (*enable_comm) (int, int);
               int  (*disable_comm) (int, int);
               int  (*reset_comm) (int, int);
               int  (*restart_comm) (int, int);
               int  (*test_comm) (int, int);  /* Used for NTDS_Wrap */
               int  (*level2_comm) (int, NTDS_TEST_MSGS); /* allows invocation of protocol's Level 2 function dispatcher.*/
               int  (*output_comm) (int, int);
               int  (*input_comm) (int, int, NIO_MESG *);
               int  (*spcl_comm) (int, int);
               int  (*suspend_comm) (int, int);
               int  (*resume_comm) (int, int);
               int  (*redundant_channel_comm) (int, int, int, int); /* Device, Port, State */
            } NTDS_CTRL_FUNC;
            
            typedef struct
              {
                unsigned int time;
                unsigned int test;
                unsigned int user1;
                unsigned int user2;
            
              } NTDS_TEST_MSGS;
            //#]
            
            
        
        
        ////    Constructors and destructors    ////
        public :
            
            //## auto_generated 
            C_IO_Functions();
            
            //## auto_generated 
            ~C_IO_Functions();
        
        
        ////    Operations    ////
        public :
            
            //## operation createInterface(std::string) 
            static void createInterface(std::string interfaceName);
            
            //## operation getMessageType(char*,Framework::InterfaceType) 
            static Framework::MessageType getMessageType(char* message, Framework::InterfaceType interfaceType);
        
        
        };
    }
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\C_IO_Functions.h
*********************************************************************/

