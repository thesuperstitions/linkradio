//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys\timeb.h>
#pragma hdrstop

#include "MTS_FileJoiner.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------

#define SIZE_OF_BUFFER 1024*1024*10

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void TForm1::GetNextFileName(char* filename)
{
  char s[500];

  int count = OpenDialog1->Files->Count;

  int index = 0;

  if (count == 0)
  {
    filename[0] = 0;
    return;
  }
  else
  {
    strcpy(filename, OpenDialog1->Files->Strings[0].c_str() );
    if (count == 1)
    {
      sprintf(s, "File[%u] (%s) Returned", 0, OpenDialog1->Files->Strings[0].c_str());
      LogMessage(s);

      OpenDialog1->Files->Delete(0);
      return;
    }
  }

  for (int I=0; I < count-1; I++)
  {
    if (strcmp(OpenDialog1->Files->Strings[index].c_str(), OpenDialog1->Files->Strings[I+1].c_str()) > 0)
    {
      sprintf(s, "File[%u] (%s) > File[%u] (%s).", index, OpenDialog1->Files->Strings[index].c_str(), I+1, OpenDialog1->Files->Strings[I+1].c_str());
      LogMessage(s);

      strcpy(filename, OpenDialog1->Files->Strings[I+1].c_str() );
      index = I+1;
    }
  }

  sprintf(s, "Deleting Filename from list (%s).  Index = %u", OpenDialog1->Files->Strings[index].c_str(), index);
  LogMessage(s);
  OpenDialog1->Files->Delete(index);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  char              s[500];
  unsigned long int BytesRead;
  unsigned char*    buffer = new unsigned char[SIZE_OF_BUFFER];
  char              filename[500];
  char              outputfilename[500];
  int               count;
  double            totalBytesWritten = 0;

  BitBtn1->Enabled = false;
  BitBtn2->Enabled = false;

  if (OpenDialog1->Execute())
  {
    if (OpenDialog2->Execute())
    {
      strcpy(outputfilename, OpenDialog2->FileName.c_str());
      sprintf(s, "Opening Output File (%s)", outputfilename);
      LogMessage(s);

      FILE* outputFile = fopen(outputfilename, "wb");

      count = OpenDialog1->Files->Count;

      for (int I = 0; I < count; I ++)
      {
        GetNextFileName(&filename[0]);
        sprintf(s, "Opening .mts Video File Segment (%s)", filename);
        LogMessage(s);

        FILE* stream = fopen(filename, "rb");
        if (stream)
        {
          while (!feof(stream))
          {
            BytesRead = fread(buffer, 1, SIZE_OF_BUFFER, stream);
            if (BytesRead > 0)
            {
              fwrite(buffer, BytesRead, 1, outputFile);

              totalBytesWritten += BytesRead;

              sprintf(s, "Wrote %10.0f Bytes To Output File (%s)", totalBytesWritten, outputfilename);
              LogMessage(s);
            }
          }
          sprintf(s, "Closing .mts Video File Segment (%s)", filename);
          LogMessage(s);

          fclose(stream);
        }
      } // for (int I = 0; I < OpenDialog1->Files->Count; I ++)

      fclose(outputFile);
    }
  }
  
  BitBtn1->Enabled = true;
  BitBtn2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel2Resize(TObject *Sender)
{
  int center = Panel2->Width / 2;
  BitBtn1->Left = (center-10) - BitBtn1->Width;
  BitBtn2->Left = (center+10);
}

//---------------------------------------------------------------------------


static struct timeb previousTime;

void TForm1::LogMessage(char* Msg)
{
  char          s[500];
  struct timeb  t;
  int           Hours, Mins, Secs;
  unsigned long milliSecs, previousMilliSecs;
  double        deltaTime;

  ftime(&t);
  milliSecs = (t.time * 1000) + t.millitm;
  Secs = milliSecs % 86400000; // 86400000 = Milli-Seconds/24 hours
  Hours = Secs / 3600;
  Secs -= Hours * 3600;
  Mins = Secs / 60;
  Secs -= Mins * 60;

  if (previousTime.time == 0)
  {
    previousTime = t;
    deltaTime = 0.0;
  }
  else
  {
    previousMilliSecs = (previousTime.time * 1000) + previousTime.millitm;
    deltaTime = (milliSecs - previousMilliSecs) / 1000.0;
  }

  sprintf(s, "%02u:%02u:%02u.%03u - Delta Time = %8.3f Secs - %s : ",
    Hours, Mins, Secs, t.millitm, deltaTime, Msg);

  Memo1->Lines->Add(s);
  Memo1->Lines->Add("");
  Memo1->Repaint();
}

//---------------------------------------------------------------------------


