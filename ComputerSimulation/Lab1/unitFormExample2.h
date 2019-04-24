//---------------------------------------------------------------------------

#ifndef unitFormExample2H
#define unitFormExample2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformExample2 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *Button4;
        TStringGrid *StringGrid1;
        TButton *Button1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *labelAverage;
        TLabel *Label4;
        TLabel *labelDispersion;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformExample2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformExample2 *formExample2;
//---------------------------------------------------------------------------
#endif
