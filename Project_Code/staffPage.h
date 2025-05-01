#pragma once

namespace ProjectCode {

	 using namespace System;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;

	 /// <summary>
	 /// Summary for staffPage
	 /// </summary>
	 public ref class staffPage : public System::Windows::Forms::Form
	 {
	 public:
		  staffPage(void)
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
		  ~staffPage()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 private: System::Windows::Forms::Panel^ MainMenu_pn;
	 protected:
	 private: System::Windows::Forms::Panel^ profile_pn;
	 private: System::Windows::Forms::Label^ AccName;
	 private: System::Windows::Forms::PictureBox^ AccPic;
	 private: System::Windows::Forms::Panel^ MainPage;


	 protected:

	 private:
		  /// <summary>
		  /// Required designer variable.
		  /// </summary>
		  System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		  /// <summary>
		  /// Required method for Designer support - do not modify
		  /// the contents of this method with the code editor.
		  /// </summary>
		  void InitializeComponent(void)
		  {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(staffPage::typeid));
			   this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
			   this->profile_pn = (gcnew System::Windows::Forms::Panel());
			   this->AccName = (gcnew System::Windows::Forms::Label());
			   this->AccPic = (gcnew System::Windows::Forms::PictureBox());
			   this->MainPage = (gcnew System::Windows::Forms::Panel());


			   this->MainMenu_pn->SuspendLayout();
			   this->profile_pn->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
			   this->SuspendLayout();

			   // 
			   // MainMenu_pn
			   // 
			   this->MainMenu_pn->Controls->Add(this->profile_pn);
			   this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
			   this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
			   this->MainMenu_pn->Name = L"MainMenu_pn";
			   this->MainMenu_pn->Size = System::Drawing::Size(313, 739);
			   this->MainMenu_pn->TabIndex = 1;
			   // 
			   // profile_pn
			   // 
			   this->profile_pn->Controls->Add(this->AccName);
			   this->profile_pn->Controls->Add(this->AccPic);
			   this->profile_pn->Dock = System::Windows::Forms::DockStyle::Top;
			   this->profile_pn->Location = System::Drawing::Point(0, 0);
			   this->profile_pn->Name = L"profile_pn";
			   this->profile_pn->Size = System::Drawing::Size(313, 212);
			   this->profile_pn->TabIndex = 1;
			   // 
			   // AccName
			   // 
			   this->AccName->AutoSize = true;
			   this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->AccName->Location = System::Drawing::Point(3, 175);
			   this->AccName->Name = L"AccName";
			   this->AccName->Size = System::Drawing::Size(58, 22);
			   this->AccName->TabIndex = 1;
			   this->AccName->Text = L"label1";
			   // 
			   // AccPic
			   // 
			   this->AccPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AccPic.Image")));
			   this->AccPic->Location = System::Drawing::Point(38, 12);
			   this->AccPic->Name = L"AccPic";
			   this->AccPic->Size = System::Drawing::Size(213, 147);
			   this->AccPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->AccPic->TabIndex = 0;
			   this->AccPic->TabStop = false;
			   // 
			   // MainPage
			   // 
			   this->MainPage->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->MainPage->Location = System::Drawing::Point(313, 0);
			   this->MainPage->Name = L"MainPage";
			   this->MainPage->Size = System::Drawing::Size(960, 739);
			   this->MainPage->TabIndex = 2;


			   // 
			   // staffPage
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1273, 739);
			   /* this->Controls->Add(this->labelMemberID);
							this->Controls->Add(this->txtMemberID);
							this->Controls->Add(this->btnSearch);
							this->Controls->Add(this->btnRenew);
							this->Controls->Add(this->btnDelete);*/
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Controls->Add(this->MainPage);
			   this->Controls->Add(this->MainMenu_pn);
			   this->Name = L"staffPage";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"staffPage";
			   this->MainMenu_pn->ResumeLayout(false);
			   this->profile_pn->ResumeLayout(false);
			   this->profile_pn->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->EndInit();
			   this->ResumeLayout(false);

		  }
#pragma endregion

	 };
}
