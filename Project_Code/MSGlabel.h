#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ProjectCode {

	/// <summary>
	/// Summary for MSGlabel
	/// </summary>
	public ref class MSGlabel : public System::Windows::Forms::UserControl
	{
	public:
		MSGlabel(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MSGlabel()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ DATE;
	protected:
	public: System::Windows::Forms::Label^ TIME;

	protected:


	protected:

	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::RichTextBox^ msgbody;
	private:

	private:

	private:

	private:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->DATE = (gcnew System::Windows::Forms::Label());
			this->TIME = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->msgbody = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// DATE
			// 
			this->DATE->AutoSize = true;
			this->DATE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DATE->Location = System::Drawing::Point(203, 11);
			this->DATE->Name = L"DATE";
			this->DATE->Size = System::Drawing::Size(192, 32);
			this->DATE->TabIndex = 0;
			this->DATE->Text = L"MM/DD/YYYY";
			// 
			// TIME
			// 
			this->TIME->AutoSize = true;
			this->TIME->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TIME->Location = System::Drawing::Point(427, 11);
			this->TIME->Name = L"TIME";
			this->TIME->Size = System::Drawing::Size(108, 32);
			this->TIME->TabIndex = 1;
			this->TIME->Text = L"HH:MM";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(-2, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Received Time: ";
			// 
			// msgbody
			// 
			this->msgbody->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->msgbody->Location = System::Drawing::Point(3, 74);
			this->msgbody->Name = L"msgbody";
			this->msgbody->ReadOnly = true;
			this->msgbody->Size = System::Drawing::Size(556, 204);
			this->msgbody->TabIndex = 3;
			this->msgbody->Text = L"vsd";
			// 
			// MSGlabel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->msgbody);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TIME);
			this->Controls->Add(this->DATE);
			this->Name = L"MSGlabel";
			this->Size = System::Drawing::Size(568, 299);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
