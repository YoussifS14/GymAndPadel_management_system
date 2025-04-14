#pragma once


namespace ProjectCode {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoadingPage
	/// </summary>
	public ref class LoadingPage : public System::Windows::Forms::Form
	{
	public:
		LoadingPage(void)
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
		~LoadingPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	public: System::Windows::Forms::Label^ label1;
	private:
	protected:

	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			 this->components = (gcnew System::ComponentModel::Container());
			 this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			 this->label1 = (gcnew System::Windows::Forms::Label());
			 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			 this->SuspendLayout();
			 // 
			 // progressBar1
			 // 
			 this->progressBar1->Location = System::Drawing::Point(12, 254);
			 this->progressBar1->Name = L"progressBar1";
			 this->progressBar1->Size = System::Drawing::Size(584, 44);
			 this->progressBar1->Step = 15;
			 this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
			 this->progressBar1->TabIndex = 0;
			 // 
			 // label1
			 // 
			 this->label1->AutoSize = true;
			 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			 this->label1->Location = System::Drawing::Point(12, 170);
			 this->label1->Name = L"label1";
			 this->label1->Size = System::Drawing::Size(137, 32);
			 this->label1->TabIndex = 1;
			 this->label1->Text = L"Starting...";
			 // 
			 // timer1
			 // 
			 this->timer1->Enabled = true;
			 this->timer1->Interval = 110;
			 this->timer1->Tick += gcnew System::EventHandler(this, &LoadingPage::timer1_Tick);
			 // 
			 // LoadingPage
			 // 
			 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			 this->ClientSize = System::Drawing::Size(608, 328);
			 this->Controls->Add(this->label1);
			 this->Controls->Add(this->progressBar1);
			 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			 this->Name = L"LoadingPage";
			 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			 this->Text = L"LoadingPage";
			 this->ResumeLayout(false);
			 this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		 if (progressBar1->Value < 95) {
			  progressBar1->Value += 5;
		 }
		 else
		 {
			  timer1->Enabled = false;
			  this->Close();
		 
		 }
	}
	};
}
