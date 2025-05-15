#pragma once
#include "Structure.h"
#include "MSGlabel.h"
namespace ProjectCode {

	 using namespace System;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;

	 /// <summary>
	 /// Summary for MSGsShow
	 /// </summary>
	 public ref class MSGsShow : public System::Windows::Forms::Form
	 {
	 public:
		  MSGsShow(void)
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
		  ~MSGsShow()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 private: System::Windows::Forms::FlowLayoutPanel^ flow;
	 protected:

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
			  System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MSGsShow::typeid));
			  this->flow = (gcnew System::Windows::Forms::FlowLayoutPanel());
			  this->SuspendLayout();
			  // 
			  // flow
			  // 
			  this->flow->AutoScroll = true;
			  this->flow->BackColor = System::Drawing::Color::Black;
			  this->flow->Dock = System::Windows::Forms::DockStyle::Fill;
			  this->flow->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				  static_cast<System::Int32>(static_cast<System::Byte>(0)));
			  this->flow->Location = System::Drawing::Point(0, 0);
			  this->flow->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->flow->Name = L"flow";
			  this->flow->Size = System::Drawing::Size(434, 432);
			  this->flow->TabIndex = 0;
			  // 
			  // MSGsShow
			  // 
			  this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			  this->AutoScroll = true;
			  this->ClientSize = System::Drawing::Size(434, 432);
			  this->Controls->Add(this->flow);
			  this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			  this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			  this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->Name = L"MSGsShow";
			  this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			  this->Text = L"MSGsShow";
			  this->Load += gcnew System::EventHandler(this, &MSGsShow::MSGsShow_Load);
			  this->ResumeLayout(false);

		  }
#pragma endregion
	 private: System::Void MSGsShow_Load(System::Object^ sender, System::EventArgs^ e) {

		  for (auto& it = userList[loginID].myNotifications.begin(); it != userList[loginID].myNotifications.end(); it++)
		  {
			   MSGlabel^ msgLabel = gcnew MSGlabel();

			   msgLabel->DATE->Text = gcnew String(it->date.c_str());
			   msgLabel->TIME->Text = gcnew String(it->hour.c_str());
			   msgLabel->msgbody->Text = gcnew String(it->message.c_str());

			   it->isRead = true;
			   flow->Controls->Add(msgLabel);
		  }
	 }
	 };
}
