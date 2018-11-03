#pragma once

namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient; // #1

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  log_box;
	private: System::Windows::Forms::TextBox^  pas_box;
	private: System::Windows::Forms::Button^  Ok_but;
	protected:



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->log_box = (gcnew System::Windows::Forms::TextBox());
			this->pas_box = (gcnew System::Windows::Forms::TextBox());
			this->Ok_but = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// log_box
			// 
			this->log_box->Location = System::Drawing::Point(34, 73);
			this->log_box->Name = L"log_box";
			this->log_box->Size = System::Drawing::Size(100, 20);
			this->log_box->TabIndex = 0;
			// 
			// pas_box
			// 
			this->pas_box->Location = System::Drawing::Point(34, 153);
			this->pas_box->Name = L"pas_box";
			this->pas_box->Size = System::Drawing::Size(100, 20);
			this->pas_box->TabIndex = 1;
			// 
			// Ok_but
			// 
			this->Ok_but->Location = System::Drawing::Point(197, 73);
			this->Ok_but->Name = L"Ok_but";
			this->Ok_but->Size = System::Drawing::Size(75, 23);
			this->Ok_but->TabIndex = 2;
			this->Ok_but->Text = L"Ok";
			this->Ok_but->UseVisualStyleBackColor = true;
			this->Ok_but->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(61, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Ok_but);
			this->Controls->Add(this->pas_box);
			this->Controls->Add(this->log_box);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		String^ constring = L"datasource=localhost;port=3306;username=root;password=Shivfather65$"; 
		MySqlConnection^ conDatabase = gcnew  MySqlConnection(constring);							
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from datab.edata where user_name='"+this->log_box->Text+"'and password='"+this->pas_box->Text+"';", conDatabase); // #2
		MySqlDataReader^ myReader;																	
		try {																						
			conDatabase->Open();																	
			myReader = cmdDataBase->ExecuteReader();												
			int count = 0;
			while (myReader->Read()) {																
				count = count + 1;
			}
		   	//log_box->Text += (myReader->GetInt32(0));}											
				if (count == 1) {
					MessageBox::Show("username and pass is correct");
				}
				else if (count > 1) {
					MessageBox::Show("Duplicate Username and password ...Acess Denied");
				}
				else
					MessageBox::Show("Username and password is Not correct ..Please ReEnter");

			}																						
		catch (Exception^ ex) {																		
			MessageBox::Show(ex->Message);															
		}							
	}
};
}
