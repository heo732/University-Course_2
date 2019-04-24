//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unitFormTask3.h"
#include "unitMain.h"
#include "unitTask3.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformTask3 *formTask3;
//---------------------------------------------------------------------------
__fastcall TformTask3::TformTask3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformTask3::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        formMain->Show();        
}
//---------------------------------------------------------------------------
void __fastcall TformTask3::buttonGoMainClick(TObject *Sender)
{
        formMain->Show();
        formTask3->Hide();        
}
//---------------------------------------------------------------------------


void __fastcall TformTask3::memoInChange(TObject *Sender)
{
        memoStrings->Clear();
        memoDigitStrings->Clear();

        Strings strings;
        DigitStrings digitStrings;

        for(int i = 0; i < memoIn->Lines->Count; i++)
        {
                strings.addLine(memoIn->Lines->operator [](i), 1);
                digitStrings.addLine(memoIn->Lines->operator [](i), 1);
        }

        for(int i = 0; i < strings.getCountLines(); i++)
                memoStrings->Lines->Add(strings(i));

        for(int i = 0; i < digitStrings.getCountLines(); i++)
                memoDigitStrings->Lines->Add(digitStrings(i));
}
//---------------------------------------------------------------------------


