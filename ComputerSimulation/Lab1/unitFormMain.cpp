//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "unitFormMain.h"
#include "unitFormTask1.h"
#include "unitFormTask2.h"
#include "unitFormTask3.h"
#include "unitFormTask4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformMain *formMain;
//---------------------------------------------------------------------------
__fastcall TformMain::TformMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformMain::FormCreate(TObject *Sender)
{
        srand(time(0));        
}
//---------------------------------------------------------------------------
void __fastcall TformMain::Button1Click(TObject *Sender)
{
        formTask1->Show();
        formMain->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TformMain::Button2Click(TObject *Sender)
{
        formTask2->Show();
        formMain->Hide();        
}
//---------------------------------------------------------------------------
void __fastcall TformMain::Button3Click(TObject *Sender)
{
        formTask3->Show();
        formMain->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TformMain::Button4Click(TObject *Sender)
{
        formTask4->Show();
        formMain->Hide();
}
//---------------------------------------------------------------------------

