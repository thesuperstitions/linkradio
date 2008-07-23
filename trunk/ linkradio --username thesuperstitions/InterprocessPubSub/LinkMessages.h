//---------------------------------------------------------------------------
#ifndef LinkMessagesH
#define LinkMessagesH
//---------------------------------------------------------------------------

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

typedef struct
{
  unsigned long WordFormat                    : 2,
                Label                         : 5,
                SubLabel                      : 3;
} InitialWord;

typedef struct // J2.2 Air PPLI (Extension word 0)
{
    u_int   wordFormat      :  2,
            latitude        : 23,
            longitude       : 24,
            _spare1         :  1,
            course          :  9,
            speed           : 11,
            _spare          : 10;
} J2_2E0Msg_t;

typedef struct // J2.3 Surface PPLI (Initial word)
{
    u_int   wordFormat      :  2,
            label           :  5,
            subLabel        :  3,
            msgLengthInd    :  3,
            exercise        :  1,
            _spare1         :  1,
            forceTell       :  1,
            emergency       :  1,
            c2Unit          :  1,
            simulation      :  1,
            _spare2         :  2,
            activeRelay     :  1,
            RTTAbnormal     :  1,
            networkStatus   :  4,
            timeQuality     :  4,
            geodeticQuality :  4,
            strength        :  4,
            _spare3         :  1,
            elevation25ft   : 11,
            _spare4         :  2,
            missionID       :  8,
            elevationQuality:  4,
            _spare5         :  5,
            _spare          : 10;
} J2_3IMsg_t;

typedef J2_2E0Msg_t J2_3E0Msg_t; // J2.3 Surface PPLI (Extension word 0)

typedef struct // J2.3 Surface PPLI (Initial word & Extension word 0)
{
    J2_3IMsg_t  I  ;
    J2_3E0Msg_t E0 ;
} J2_3Msg_t;

typedef struct // J3.2 Air Track (Initial word)
{
    u_int   wordFormat      :  2,
            label           :  5,
            subLabel        :  3,
            msgLengthInd    :  3,
            exercise        :  1,
            ppliRTNInd      :  1,
            forceTell       :  1,
            emergency       :  1,
            specialProc     :  1,
            simulation      :  1,
            RTN             : 19,
            strength        :  4,
            altitudeSrc     :  2,
            altitude25ft    : 13,
            identDiff       :  1,
            trackQuality    :  4,
            identConfidence :  4,
            trackIdentity   :  3,
            specialInterest :  1,
            _spare          : 10;
} J3_2IMsg_t;

typedef struct // J3.2 Air Track (Extension word 0)
{
    u_int   wordFormat      :  2,
            _spare1         :  2,
            latitude        : 21,
            disused         :  1,
            _spare2         :  1,
            longitude       : 22,
            active          :  1,
            course          :  9,
            speed           : 11,
            _spare          : 10;
} J3_2E0Msg_t;

typedef struct // J3.2 Air Track (Initial word & Extension word 0)
{
    J3_2IMsg_t  I  ;
    J3_2E0Msg_t E0 ;
} J3_2Msg_t;


#define LABEL_J2_3 23
#define LABEL_J3_2 32

class LinkMessages
{
  public:
    virtual void ProcessLinkMessages(InitialWord* LinkMsg);
//    virtual void ProcessSimpleMessages(char* Ptr, unsigned int Length);
    virtual void LinkMessagesLogData(char* LogString);
    virtual void LatLonConversion(double Lat, double Lon, int LatIncrement, int LonIncrement, LatLonStruct* LatLon);
    virtual void Decode_J2_3(J2_3Msg_t* Msg);
    virtual void Decode_J3_2(unsigned long* Msg);
};


#endif
