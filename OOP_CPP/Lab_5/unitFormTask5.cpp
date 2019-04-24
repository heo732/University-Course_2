//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unitFormTask5.h"
#include "unitMain.h"
#include "unitTask5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
short currentPage = 0;
//---------------------------------------------------------------------------
TformTask5 *formTask5;
//---------------------------------------------------------------------------
__fastcall TformTask5::TformTask5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformTask5::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        formMain->Show();
}
//---------------------------------------------------------------------------
void __fastcall TformTask5::buttonGoMainClick(TObject *Sender)
{
        formMain->Show();
        formTask5->Hide();        
}
//---------------------------------------------------------------------------
void __fastcall TformTask5::FormCreate(TObject *Sender)
{
        srand(time(0));

        imageArrowLeft->Picture->LoadFromFile("cards/leftArrow.bmp");
        imageArrowRight->Picture->LoadFromFile("cards/rightArrow.bmp");

        imageEyeColor->Canvas->Pen->Color = clGreen;
        imageEyeColor->Canvas->Brush->Color = clGreen;
        imageEyeColor->Canvas->Rectangle(0, 0, imageEyeColor->Width, imageEyeColor->Height);

        imageHairColor->Canvas->Pen->Color = clRed;
        imageHairColor->Canvas->Brush->Color = clRed;
        imageHairColor->Canvas->Rectangle(0, 0, imageEyeColor->Width, imageEyeColor->Height);

        EmployeeFather ef((RadioGroup1->ItemIndex == 1) ? 1 : 0, imageEyeColor->Canvas->Pixels[0][0], imageHairColor->Canvas->Pixels[0][0], StrToFloat(editWorkday->Text), StrToInt(editCountChildren->Text));
        float width, height;
        height = StrToFloat(editHeight->Text);
        width = height * 0.382;
        ef.Father::drawHuman(image, image->Width/2-width/2, image->Height/2-height/2, width, height);
}
//---------------------------------------------------------------------------


void __fastcall TformTask5::imageArrowRightClick(TObject *Sender)
{
        image->Picture->Bitmap = NULL;
        switch(currentPage)
        {
        case 0:{
                EmployeeFather ef((RadioGroup1->ItemIndex == 1) ? 1 : 0, imageEyeColor->Canvas->Pixels[0][0], imageHairColor->Canvas->Pixels[0][0], StrToFloat(editWorkday->Text), StrToInt(editCountChildren->Text));
                ef.drawClock(image, image->Width/2, image->Height/2, 200);
                currentPage = 1;
                break;
        }
        case 1:{
                EmployeeFather ef((RadioGroup1->ItemIndex == 1) ? 1 : 0, imageEyeColor->Canvas->Pixels[0][0], imageHairColor->Canvas->Pixels[0][0], StrToFloat(editWorkday->Text), StrToInt(editCountChildren->Text));
                ef.drawChildren(image, 0, 0, image->Width, image->Height-50);
                currentPage = 2;
                break;
        }
        case 2:{
                EmployeeFather ef((RadioGroup1->ItemIndex == 1) ? 1 : 0, imageEyeColor->Canvas->Pixels[0][0], imageHairColor->Canvas->Pixels[0][0], StrToFloat(editWorkday->Text), StrToInt(editCountChildren->Text));
                float width, height;
                height = StrToFloat(editHeight->Text);
                width = height * 0.382;
                ef.Father::drawHuman(image, image->Width/2-width/2, image->Height/2-height/2, width, height);
                currentPage = 0;
                break;
        }
        }
}
//---------------------------------------------------------------------------

void __fastcall TformTask5::imageEyeColorClick(TObject *Sender)
{
        if(ColorDialog1->Execute())
        {
                TColor color = ColorDialog1->Color;
                imageEyeColor->Canvas->Pen->Color = color;
                imageEyeColor->Canvas->Brush->Color = color;
                imageEyeColor->Canvas->Rectangle(0, 0, imageEyeColor->Width, imageEyeColor->Height);
        }
}
//---------------------------------------------------------------------------

void __fastcall TformTask5::imageHairColorClick(TObject *Sender)
{
        if(ColorDialog1->Execute())
        {
                TColor color = ColorDialog1->Color;
                imageHairColor->Canvas->Pen->Color = color;
                imageHairColor->Canvas->Brush->Color = color;
                imageHairColor->Canvas->Rectangle(0, 0, imageHairColor->Width, imageHairColor->Height);
        }
}
//---------------------------------------------------------------------------

void __fastcall TformTask5::imageArrowLeftClick(TObject *Sender)
{
        image->Picture->Bitmap = NULL;
        
        switch(currentPage)
        {
        case 0:{
                EmployeeFather ef((RadioGroup1->ItemIndex == 1) ? 1 : 0, imageEyeColor->Canvas->Pixels[0][0], imageHairColor->Canvas->Pixels[0][0], StrToFloat(editWorkday->Text), StrToInt(editCountChildren->Text));
                ef.drawChildren(image, 0, 0, image->Width, image->Height-50);
                currentPage = 2;
                break;
        }
        case 1:{
                EmployeeFather ef((RadioGroup1->ItemIndex == 1) ? 1 : 0, imageEyeColor->Canvas->Pixels[0][0], imageHairColor->Canvas->Pixels[0][0], StrToFloat(editWorkday->Text), StrToInt(editCountChildren->Text));
                float width, height;
                height = StrToFloat(editHeight->Text);
                width = height * 0.382;
                ef.Father::drawHuman(image, image->Width/2-width/2, image->Height/2-height/2, width, height);
                currentPage = 0;
                break;
        }
        case 2:{
                EmployeeFather ef((RadioGroup1->ItemIndex == 1) ? 1 : 0, imageEyeColor->Canvas->Pixels[0][0], imageHairColor->Canvas->Pixels[0][0], StrToFloat(editWorkday->Text), StrToInt(editCountChildren->Text));
                ef.drawClock(image, image->Width/2, image->Height/2, 200);
                currentPage = 1;
                break;
        }
        }
}
//---------------------------------------------------------------------------

