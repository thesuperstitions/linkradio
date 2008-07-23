/*******************************************************************************
*  unclassified                                                                *
*                   U  N  C  L  A  S  S  I  F  I  E  D                         *
*                                                                unclassified  *
*******************************************************************************/

#ifndef _SIMPLE_H_
#define _SIMPLE_H_

#include <sys/types.h>

#define SIMPLE_PACKET_MAX_SIZE      272 // net header w/checksum (16) + packet header (14) + 120 words (240) + mod 4 alignment (2)

/* SIMPLE Network Header defintions */
#define SNH_SYNCBYTE_1              0x49
#define SNH_SYNCBYTE_2              0x36

#define SNH_PACKET_LINK16_FIXED     1
#define SNH_PACKET_LINK11           2
#define SNH_PACKET_STATUS           61
#define SNH_PACKET_RTT              63
#define SNH_PACKET_CCD_CEC          200     // Packet types 200-203 (User Types 0-3) are for CCD to CCD communication
#define SNH_PACKET_CCD_STADILJ      201
#define SNH_PACKET_CCD_STATUS       202
#define SNH_PACKET_CCD_CONFIG       203

#define SNH_SIMPLENODE_MILO01       101
#define SNH_SIMPLENODE_MILO02       102
#define SNH_SIMPLENODE_CCD1         1
#define SNH_SIMPLENODE_CCD2         2
#define SNH_SIMPLENODE_ALL          129

#define SNH_SIMPLESUBNODE_STATUS    6
#define SNH_SIMPLESUBNODE_LINK16    206

/* SIMPLE Packet Header defintions */
#define SPH_LINK16_FIXED_FORMAT     2
#define SPH_RC_NO_PROCESSING        0
#define SPH_LINK16_CODE_WORDS       5
#define SPH_STN_MILO01              0101
#define SPH_STN_MILO02              0102

#define MAX_PAYLOAD_BYTES           4096

#pragma pack(push, 1)

#define u_char  unsigned char
#define u_short unsigned short
/*
typedef struct // SIMPLE Network Header
{
//  u_short checksum::  There is a 16-bit checksum at the end of the packet
    u_short transitTime ;
    u_char  packetType  ;
    u_char  packetSize  ;
    u_char  destSubNode ;
    u_char  destNode    ;
    u_char  srcSubNode  ;
    u_char  srcNode     ;
    u_short seqNo       ;
    u_short length      ;
    u_char  syncByte_2  ;
    u_char  syncByte_1  ;
} networkHeader_t;
*/
typedef struct // SIMPLE Network Header
{
    u_char  syncByte_1  ,
            syncByte_2  ;
    u_short length      ,
            seqNo       ;
    u_char  srcNode     ,
            srcSubNode  ,
            destNode    ,
            destSubNode ,
            packetSize  ,
            packetType  ;
    u_short transitTime ;
//  u_short checksum::  There is a 16-bit checksum at the end of the packet
} networkHeader_t;
/*
typedef struct // SIMPLE Link-16 Packet Header
{
  u_short   loopbackID          ,
            wordCount           ,
            STN                 ,
            seqTimeSlotCount1   ,
            NPG                 ;
  u_char    seqTimeSlotCount2   ,
            netNumber           ,
            RC_flag             ,
            msgSubType          ;
} packetHeader_t;
*/
typedef struct // SIMPLE Link-16 Packet Header
{
    u_char  msgSubType          ,
            RC_flag             ,
            netNumber           ,
            seqTimeSlotCount2   ;
    u_short NPG                 ,
            seqTimeSlotCount1   ,
            STN                 ,
            wordCount           ,
            loopbackID          ;
} packetHeader_t;

typedef struct
{
  networkHeader_t NH;
  packetHeader_t  PH;
  unsigned char   Message[MAX_PAYLOAD_BYTES];
} SIMPLE_Message_t;

#pragma pack (pop)

#endif /* _SIMPLE_H_ */

/*******************************************************************************
*  unclassified                                                                *
*                   U  N  C  L  A  S  S  I  F  I  E  D                         *
*                                                                unclassified  *
*******************************************************************************/


