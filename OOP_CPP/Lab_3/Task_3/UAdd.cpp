//--------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UAdd.h"
#include "UMain.h"
#include "TDomain_IP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Add *Form_Add;
//---------------------------------------------------------------------------
__fastcall TForm_Add::TForm_Add(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_Add::Button_OKClick(TObject *Sender)
{
  if( Edit_Domain->Text != "" && Edit_IP->Text != ""){

    TDomain_IP B;
    B.ReadFromFile("BASE.txt");
    B.Add(Edit_Domain->Text.c_str(), Edit_IP->Text.c_str());
    B.WriteInFile("BASE.txt");

    Form_Add->Close();

    B.WriteInGrid(Form_Main->Grid);
  }
  else
    ShowMessage("��������� ����");
}
//---------------------------------------------------------------------------
void __fastcall TForm_Add::FormClose(TObject *Sender, TCloseAction &Action)
{ 
  Form_Main->Show();
  Form_Main->Edit_Search->Text = "";     
}
//---------------------------------------------------------------------------

void __fastcall TForm_Add::Button_CloseClick(TObject *Sender)
{
  Form_Add->Close();   
}
//---------------------------------------------------------------------------

