#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ProjectCode {

	/// <summary>
	/// Summary for AttedanceInfo
	/// </summary>
	public ref class AttedanceInfo : public System::Windows::Forms::UserControl
	{
	public:
		AttedanceInfo(void)
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
		~AttedanceInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ name;
	protected:
	public: System::Windows::Forms::Label^ clsName;
	public: System::Windows::Forms::RichTextBox^ richTextBox1;

	protected:


	private: System::Windows::Forms::Label^ label1;


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
			this->name = (gcnew System::Windows::Forms::Label());
			this->clsName = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// name
			// 
			this->name->AutoSize = true;
			this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(3, 14);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(73, 29);
			this->name->TabIndex = 0;
			this->name->Text = L"name";
			// 
			// clsName
			// 
			this->clsName->AutoSize = true;
			this->clsName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clsName->Location = System::Drawing::Point(3, 92);
			this->clsName->Name = L"clsName";
			this->clsName->Size = System::Drawing::Size(79, 29);
			this->clsName->TabIndex = 1;
			this->clsName->Text = L"label1";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(505, 31);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(420, 193);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(501, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Attendance";
			// 
			// AttedanceInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->clsName);
			this->Controls->Add(this->name);
			this->Name = L"AttedanceInfo";
			this->Size = System::Drawing::Size(960, 227);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
