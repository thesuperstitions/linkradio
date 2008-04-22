//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "MTS_FileJoiner.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------

#define SIZE_OF_BUFFER 1024*1024

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
  getInputFileList();
}

//---------------------------------------------------------------------------

void TForm1::getInputFileList(void)
{
}

//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  char              s[500];
  unsigned long int BytesRead = 0;
  unsigned char*    buffer = new unsigned char[SIZE_OF_BUFFER];
  char              filename[500];

  BitBtn1->Enabled = false;
  BitBtn2->Enabled = false;

  if (OpenDialog1->Execute())
  {
    if (OpenDialog2->Execute())
    {
      sprintf(s, "Opening Output File (%s)", OpenDialog2->FileName.c_str());
      Memo1->Lines->Add(s);
      Memo1->Lines->Add("");
      Memo1->Repaint();

      FILE* outputFile = fopen(OpenDialog2->FileName.c_str(), "wb");
      
      for (int I = 0; I < OpenDialog1->Files->Count; I ++)
      {
        strcpy(filename, OpenDialog1->Files->Strings[I].c_str());
        sprintf(s, "Opening .mts Video File Segment (%s)", filename);
        Memo1->Lines->Add(s);
        Memo1->Lines->Add("");
        Memo1->Repaint();

        FILE* stream = fopen(OpenDialog1->Files->Strings[I].c_str(), "rb");
        if (stream)
        {
/*          while (!feof(stream))
          {
            BytesRead = fread(buffer, 1, SIZE_OF_BUFFER, stream);
            if (BytesRead > 0)
            {
              fwrite(buffer, BytesRead, 1, outputFile);

              sprintf(s, "Wrote %u Bytes To Output File (%s)", BytesRead, filename);
              Memo1->Lines->Add(s);
              Memo1->Lines->Add("");
              Memo1->Repaint();
            }
          }
          sprintf(s, "Closing .mts Video File Segment (%s)", filename);
          Memo1->Lines->Add(s);
          Memo1->Lines->Add("");
          Memo1->Repaint();
*/
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

