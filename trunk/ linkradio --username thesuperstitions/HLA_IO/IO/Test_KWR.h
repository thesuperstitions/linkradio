#ifndef Test_KWR__H
#define Test_KWR__H


#ifdef __cplusplus
extern "C" {
#endif

#define ENET_ADDRESS_SIZE 20

typedef struct
{
   int		port;
   unsigned int word_size;
   unsigned int mode;
   unsigned int ei_mode;
   unsigned int init_mode;
   char         enet_address[ENET_ADDRESS_SIZE];
} NTDS_CONFIG;


int
Get_Device_Configuration (
   int         device,
   NTDS_CONFIG *device_status_ptr
);



#ifdef __cplusplus
}
#endif



#endif // #define Test_KWR__H
