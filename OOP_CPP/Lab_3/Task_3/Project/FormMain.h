#include "FormAdd.h"

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace Domain_IP;

//extern TDomain_IP obj_Domain_IP;

namespace Project {

	/// <summary>
	/// Ñâîäêà äëÿ FormMain
	///
	/// Âíèìàíèå! Ïðè èçìåíåíèè èìåíè ýòîãî êëàññà íåîáõîäèìî òàêæå èçìåíèòü
	///          ñâîéñòâî èìåíè ôàéëà ðåñóðñîâ ("Resource File Name") äëÿ ñðåäñòâà êîìïèëÿöèè óïðàâëÿåìîãî ðåñóðñà,
	///          ñâÿçàííîãî ñî âñåìè ôàéëàìè ñ ðàñøèðåíèåì .resx, îò êîòîðûõ çàâèñèò äàííûé êëàññ. Â ïðîòèâíîì ñëó÷àå,
	///          êîíñòðóêòîðû íå ñìîãóò ïðàâèëüíî ðàáîòàòü ñ ëîêàëèçîâàííûìè
	///          ðåñóðñàìè, ñîïîñòàâëåííûìè äàííîé ôîðìå.
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
    FormAdd^ formAdd;

	public:
		FormMain(void)
		{
			InitializeComponent();
			
      formAdd = gcnew FormAdd();
      formAdd->Owner = this;      
		}
	
  protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  Button_Add;
  protected: 

  private: System::Windows::Forms::DataGridView^  Grid;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  Coloumn_Domain;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_IP;



  protected: 

	private:
		/// <summary>
		/// Òðåáóåòñÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Îáÿçàòåëüíûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà - íå èçìåíÿéòå
		/// ñîäåðæèìîå äàííîãî ìåòîäà ïðè ïîìîùè ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
      this->Button_Add = (gcnew System::Windows::Forms::Button());
      this->Grid = (gcnew System::Windows::Forms::DataGridView());
      this->Coloumn_Domain = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      this->Column_IP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Grid))->BeginInit();
      this->SuspendLayout();
      // 
      // Button_Add
      // 
      this->Button_Add->Location = System::Drawing::Point(12, 379);
      this->Button_Add->Name = L"Button_Add";
      this->Button_Add->Size = System::Drawing::Size(75, 23);
      this->Button_Add->TabIndex = 0;
      this->Button_Add->Text = L"Додати";
      this->Button_Add->UseVisualStyleBackColor = true;
      this->Button_Add->Click += gcnew System::EventHandler(this, &FormMain::Button_Add_Click);
      // 
      // Grid
      // 
      this->Grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
      this->Grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Coloumn_Domain, 
        this->Column_IP});
      this->Grid->Location = System::Drawing::Point(12, 12);
      this->Grid->Name = L"Grid";
      this->Grid->Size = System::Drawing::Size(490, 343);
      this->Grid->TabIndex = 1;
      // 
      // Coloumn_Domain
      // 
      this->Coloumn_Domain->HeaderText = L"Domain";
      this->Coloumn_Domain->Name = L"Coloumn_Domain";
      this->Coloumn_Domain->ReadOnly = true;
      this->Coloumn_Domain->Width = 210;
      // 
      // Column_IP
      // 
      this->Column_IP->HeaderText = L"IP";
      this->Column_IP->Name = L"Column_IP";
      this->Column_IP->ReadOnly = true;
      this->Column_IP->Width = 210;
      // 
      // FormMain
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(513, 512);
      this->Controls->Add(this->Grid);
      this->Controls->Add(this->Button_Add);
      this->Name = L"FormMain";
      this->Text = L"База доменних імен";
      this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
      this->Activated += gcnew System::EventHandler(this, &FormMain::FormMain_Activated);
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Grid))->EndInit();
      this->ResumeLayout(false);

    }
#pragma endregion
	private: System::Void FormMain_Load(System::Object^  sender, System::EventArgs^  e) {				          
         TDomain_IP B;
         if(B.ReadFromFile("BASE.txt"))
           B.WriteInGrid(Grid);
         else
           MessageBox::Show("Не вдалося знайти файл BASE.txt");
			 }
  //---------------------------------------------------------------------------------------------
  private: System::Void Button_Add_Click(System::Object^  sender, System::EventArgs^  e) {         
         formAdd->Show();
         this->Enabled = false;
			 } 
	//---------------------------------------------------------------------------------------------
  private: System::Void FormMain_Activated(System::Object^  sender, System::EventArgs^  e) {
             TDomain_IP B;
             if(B.ReadFromFile("BASE.txt"))
               B.WriteInGrid(Grid);
             else
               MessageBox::Show("Не вдалося знайти файл BASE.txt");
           }
};
}
