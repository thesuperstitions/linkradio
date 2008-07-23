//---------------------------------------------------------------------------

#include <winsock2.h>
#include <stdio.h>
#include <sys\timeb.h>

#include "LinkMessages.h"
#include "simple.h"


//---------------------------------------------------------------------------

#define NETWORK_HEADER_SIZE  (int)sizeof(networkHeader_t)
#define PACKET_HEADER_SIZE   (int)sizeof(packetHeader_t)

//---------------------------------------------------------------------------

typedef struct
{
  unsigned long InitialWord;
} LinkMsgLabel;
/*
typedef struct
{
  int LatDegree;
  int LatMinutes;
  double LatSeconds;
  char LatChars[15];
  double LatDegreeDecimal;

  int LonDegree;
  int LonMinutes;
  double LonSeconds;
  char LonChars[15];
  double LonDegreeDecimal;
} LatLonStruct;
*/
void LinkMessages::LinkMessagesLogData(char* LogString)
{
}

void LinkMessages::LatLonConversion(double Lat, double Lon, int LatIncrement, int LonIncrement, LatLonStruct* LatLon)
{
  if ((int)Lat == LatIncrement+1)
  {
    strcpy(LatLon->LatChars, "No Statement");
    Lat = 0.0;
  }
  else
  {
    LatLon->LatDegreeDecimal = Lat * (90.0/LatIncrement);
    if ((int)Lat > LatIncrement+1)
    {
      strcpy(LatLon->LatChars, "S");
      LatLon->LatDegreeDecimal = 90.0 - LatLon->LatDegreeDecimal;
      Lat -= LatIncrement+1;
    }
    else
      strcpy(LatLon->LatChars, "N");

    Lat *= (90.0/LatIncrement);
    LatLon->LatDegree = Lat;
    Lat = (Lat - LatLon->LatDegree) * 60.0;
    LatLon->LatMinutes = Lat;
    Lat = (Lat - LatLon->LatMinutes) * 60.0;
    LatLon->LatSeconds = Lat;
  }


  if ((int)Lon == LonIncrement+1)
  {
    strcpy(LatLon->LonChars, "No Statement");
    Lon == 0.0;
  }
  else
  {
    LatLon->LonDegreeDecimal = Lon * ((180.0/LonIncrement));
    if ((int)Lon > LonIncrement+1)
    {
      strcpy(LatLon->LonChars, "W");
      LatLon->LonDegreeDecimal = 180.0 - LatLon->LonDegreeDecimal;
      Lon -= LonIncrement+1;
    }
    else
      strcpy(LatLon->LonChars, "E");

    Lon *= (180.0/LonIncrement); // Mult by 0.00002145767724 degrees
    LatLon->LonDegree = Lon;
    Lon = (Lon - LatLon->LonDegree) * 60.0;
    LatLon->LonMinutes = Lon;
    Lon = (Lon - LatLon->LonMinutes) * 60.0;
    LatLon->LonSeconds = Lon;
  }
}

void LinkMessages::Decode_J2_3(J2_3Msg_t* Msg)
{
  char   s[500];
  unsigned short* Ptr = (unsigned short*)Msg;
  unsigned long*  lPtr;
  double          Lat, Lon;

  lPtr = (unsigned long*)&(Ptr[5]);

  Lat = (lPtr[0] >> 2) & 0x7FFFFF;
  Lon = ((lPtr[1] & 0x1FFFF) << 7) + ((lPtr[0] >> 25) & 0x7F);
/*
  sprintf(s, "LinkMessages::Decode_J2 - WordFormat=%u, label=%u, subLabel=%u, msgLengthInd=%u, "
    "exercise=%u, _spare1=%u forceTell=%u, emergency=%u, c2Unit=%u, simulation=%u, _spare2=%u",
    Msg->I.wordFormat, Msg->I.label, Msg->I.subLabel, Msg->I.msgLengthInd, Msg->I.exercise, Msg->I._spare1,
    Msg->I.forceTell, Msg->I.emergency, Msg->I.c2Unit, Msg->I.simulation, Msg->I._spare2);
  this->LinkMessagesLogData(s);

  sprintf(s, "LinkMessages::Decode_J2 - activeRelay=%u, RTTAbnormal=%u, networkStatus=%u, timeQuality=%u, "
    "geodeticQuality=%u, strength=%u _spare3=%u, elevation25ft=%u, _spare4=%u, missionID=%u, elevationQuality=%u",
    Msg->I.activeRelay, Msg->I.RTTAbnormal, Msg->I.networkStatus, Msg->I.timeQuality, Msg->I.geodeticQuality, Msg->I.strength,
    Msg->I._spare3, Msg->I.elevation25ft, Msg->I._spare4, Msg->I.missionID, Msg->I.elevationQuality);
  this->LinkMessagesLogData(s);

  sprintf(s, "LinkMessages::Decode_J2 - wordFormat=%u, _spare1=%u, "
    "course=%u, speed=%u _spare=%u",
    Msg->E0.wordFormat, Msg->E0._spare1, Msg->E0.course, Msg->E0.speed, Msg->E0._spare);
  this->LinkMessagesLogData(s);

  sprintf(s, "%u Degrees, %u Minutes, %6.3f Seconds %s Latitude", LatDegree, LatMin, LatSecs, latchars);
  this->LinkMessagesLogData(s);
  sprintf(s, "%u Degrees, %u Minutes, %6.3f Seconds %s Longitude", LonDegree, LonMin, LonSecs, lonchars);
  this->LinkMessagesLogData(s);
  this->LinkMessagesLogData("");
*/
  struct timeb     t;
  unsigned int     H, M, S;

        // Timestamp the Data.
      ftime(&t);
      S = t.time % 86400;  //Skin off the days.
      H = S / 3600;
      S = S % 3600;
      M = S / 60;
      S = S % 60;

LatLonStruct LatLon;
  LatLonConversion(Lat, Lon, 4194303, 8388607, &LatLon);
  sprintf(s, "%02u:%02u:%02u.%3u - J%u.%u  Lat = %2u deg %2u min %2.2f sec %s  Lon = %3u deg %2u min %2.2f sec %s (%f deg, %f deg)",
    H, M, S, t.millitm, Msg->I.label, Msg->I.subLabel, LatLon.LatDegree, LatLon.LatMinutes, LatLon.LatSeconds,
    LatLon.LatChars, LatLon.LonDegree, LatLon.LonMinutes, LatLon.LonSeconds, LatLon.LonChars, LatLon.LatDegreeDecimal, LatLon.LonDegreeDecimal);
  this->LinkMessagesLogData(s);
  this->LinkMessagesLogData("");
}

void LinkMessages::Decode_J3_2(unsigned long* Msg)
{
  char            s[300];
  unsigned short* Ptr = (unsigned short*)Msg;
  unsigned long*  lPtr;
  J3_2IMsg_t      I;
  J3_2E0Msg_t     E0;
  double          Lat, Lon;

  lPtr = (unsigned long*)&(Ptr[5]);

  I.wordFormat = Msg[0] & 0x3;
  I.label = (Msg[0] >> 2) & 0x1F;
  I.subLabel = (Msg[0] >> 7) & 0x7;
  I.msgLengthInd = (Msg[0] >> 10) & 0x7;
  I.exercise = (Msg[0]  >> 13) & 0x1;
  I.ppliRTNInd = (Msg[0] >> 14) & 0x1;
  I.forceTell = (Msg[0] >> 15) & 0x1;
  I.emergency = (Msg[0] >> 16) & 0x1;
  I.specialProc = (Msg[0] >> 17) & 0x1;
  I.simulation = (Msg[0] >> 18) & 0x1;
  I.RTN = ((Msg[1] & 0x3F) << 13) + ((Msg[0] >> 19) & 0x1FFF);

  E0.wordFormat = lPtr[0] & 0x3;
  E0._spare1 = (lPtr[0] >> 2) & 0x3;
  E0.latitude = (lPtr[0] >> 4) & 0x1FFFFF;
  E0.disused = (lPtr[0] >> 25) & 0x1;
  E0._spare2 = (lPtr[0] >> 26) & 0x1;
  E0.longitude = ((lPtr[1] & 0x1FFFF) << 5) + ((lPtr[0] >> 27) & 0x1F);
  E0.active = (lPtr[1] >> 17) & 0x1;
  E0.course = (lPtr[1] >> 18) & 0x1FF;
  E0.speed = ((lPtr[2] & 0x3F) << 5) + ((lPtr[1] >> 27) & 0x1F);

  Lat = E0.latitude;
  Lon = E0.longitude;
/*
  sprintf(s, "LinkMessages::Decode_J3 - WordFormat=%u, label=%u, subLabel=%u, msgLengthInd=%u, "
    "exercise=%u, ppliRTNInd=%u, forceTell=%u, emergency=%u, specialProc=%u, simulation=%u, RTN=%u",
    I.wordFormat, I.label, I.subLabel, I.msgLengthInd, I.exercise, I.ppliRTNInd,
    I.forceTell, I.emergency, I.specialProc, I.simulation, I.RTN);
  this->LinkMessagesLogData(s);

  sprintf(s, "LinkMessages::Decode_J3 - wordFormat=%u, _spare1=%u, "
    "disused=%u, _spare2=%u, active=%u, course=%u, speed=%u _spare=%u",
    E0.wordFormat, E0._spare1, E0.disused, E0._spare2,
    E0.active, E0.course, E0.speed, E0._spare);
  this->LinkMessagesLogData(s);

  sprintf(s, "%u Degrees, %u Minutes, %6.3f Seconds %s Latitude", LatDegree, LatMin, LatSecs, latchars);
  this->LinkMessagesLogData(s);
  sprintf(s, "%u Degrees, %u Minutes, %6.3f Seconds %s Longitude", LonDegree, LonMin, LonSecs, lonchars);
  this->LinkMessagesLogData(s);
  this->LinkMessagesLogData("");

*/
  struct timeb     t;
  unsigned int     H, M, S;

        // Timestamp the Data.
      ftime(&t);
      S = t.time % 86400;  //Skin off the days.
      H = S / 3600;
      S = S % 3600;
      M = S / 60;
      S = S % 60;

LatLonStruct LatLon;
  LatLonConversion(Lat, Lon, 1048575, 2097151, &LatLon);
  sprintf(s, "%02u:%02u:%02u.%3u - J%u.%u  RTN=%u  Lat = %2u deg %2u min %2.2f sec %s  Lon = %3u deg %2u min %2.2f sec %s (%f deg, %f deg)",
    H, M, S, t.millitm, I.label, I.subLabel, I.RTN, LatLon.LatDegree, LatLon.LatMinutes, LatLon.LatSeconds,
    LatLon.LatChars, LatLon.LonDegree, LatLon.LonMinutes, LatLon.LonSeconds, LatLon.LonChars, LatLon.LatDegreeDecimal, LatLon.LonDegreeDecimal);
  this->LinkMessagesLogData(s);
  this->LinkMessagesLogData("");
}

void LinkMessages::ProcessLinkMessages(InitialWord* LinkMsg)
{
  char           s[300];

  this->LinkMessagesLogData("");
  sprintf(s, "Msg Label = %u, Sublabel = %u", LinkMsg->Label, LinkMsg->SubLabel);
  this->LinkMessagesLogData(s);

  switch(LinkMsg->Label * 10 + LinkMsg->SubLabel)
  {
    case LABEL_J2_3:
      Decode_J2_3((J2_3Msg_t*)LinkMsg);
    break;

    case LABEL_J3_2:
      Decode_J3_2((unsigned long*)LinkMsg);
    break;
  };
}
/*
void LinkMessages::ProcessSimpleMessages(char* Ptr, unsigned int Length)
{
  InitialWord* LinkMsg;
  unsigned int   i;
  char           s[300];
  networkHeader_t *nHdr = (networkHeader_t*)Ptr;
  packetHeader_t  *pHdr = (packetHeader_t*)((int)(nHdr) + NETWORK_HEADER_SIZE);
  unsigned int   PackageSize = nHdr->length - sizeof(unsigned short);  // You have to account for the checksum at the end.

  PackageSize -= NETWORK_HEADER_SIZE;


  while (PackageSize > 0)
  {
    sprintf(s, "syncByte_1=0x%x, syncByte_2=0x%x, length=%u, seqNo=%u, srcNode=%u, srcSubNode=%u "
      "destNode=%u, destSubNode=0x%x, packetSize=%u, packetType=%u, transitTime=%u",
      nHdr->syncByte_1, nHdr->syncByte_2, nHdr->length, nHdr->seqNo, nHdr->srcNode, nHdr->srcSubNode,
      nHdr->destNode, nHdr->destSubNode, nHdr->packetSize, nHdr->packetType, nHdr->transitTime);
    this->LinkMessagesLogData(s);

    sprintf(s, "msgSubType=%u, RC_flag=0x%x, netNumber=%u, seqTimeSlotCount2=%u, NPG=%u, seqTimeSlotCount1=%u "
      "STN=%u, wordCount=%u, loopbackID=%u",
      pHdr->msgSubType, pHdr->RC_flag, pHdr->netNumber, pHdr->seqTimeSlotCount2, pHdr->NPG, pHdr->seqTimeSlotCount1,
      pHdr->STN, pHdr->wordCount, pHdr->loopbackID);
    this->LinkMessagesLogData(s);

//    LinkMsg  = (InitialWord*)((int)(pHdr) + PACKET_HEADER_SIZE);
//    ProcessLinkMessages(LinkMsg);

    this->LinkMessagesLogData("");

    i = PACKET_HEADER_SIZE + (pHdr->wordCount * sizeof(unsigned short));
    pHdr = (packetHeader_t*)((int)(pHdr) + i);
    PackageSize -= i;
  };
}
*/


