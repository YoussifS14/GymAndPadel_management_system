#pragma once
#include "feature_GUI/LoadingPage.h"

#define aliens System::Windows::Forms
#define PicAsset "PicAssets/" 


namespace ProjectCode {

	 using namespace System;
	 using namespace System::IO;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;
	 using namespace System::Drawing::Drawing2D;

	 /// <summary>
	 /// Summary for LoginPage
	 /// </summary>
	 public ref class LoginPage : public System::Windows::Forms::Form
	 {
	 public:
		  LoginPage(void)
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
		  ~LoginPage()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 private: 
			System::Void MakePictureCircular(PictureBox^ picBox) {

		  Bitmap^ bmp = gcnew Bitmap(picBox->Image);
		  Bitmap^ circularBmp = gcnew Bitmap(bmp->Width, bmp->Height);

		  Graphics^ g = Graphics::FromImage(circularBmp);
		  g->SmoothingMode = SmoothingMode::AntiAlias;

		  GraphicsPath^ path = gcnew GraphicsPath();
		  path->AddEllipse(0, 0, bmp->Width, bmp->Height);

		  g->SetClip(path);
		  g->DrawImage(bmp, 0, 0);

		  picBox->Image = circularBmp;
	 }
			System::Void  setSavePic(PictureBox^ picBox) {
				 OpenFileDialog^ open = gcnew OpenFileDialog;
				 open->Filter = "Image Files |*.jpg; *.png;*.jpeg;";
				 if (open->ShowDialog() == aliens::DialogResult::OK) {
					  picBox->Image = Image::FromFile(open->FileName);

					  String^ newPATH = PicAsset + "new add" + Path::GetExtension(open->FileName);
					  if (File::Exists(newPATH)) {
						   File::Delete(newPATH);
					  }

					  MakePictureCircular(picBox);
					  MessageBox::Show(newPATH);
					  picBox->Image->Save(newPATH);

				 }

			}
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
			   this->SuspendLayout();
			   // 
			   // LoginPage
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1246, 756);
			   this->Name = L"LoginPage";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"LoginPage";
			   this->Load += gcnew System::EventHandler(this, &LoginPage::LoginPage_Load);
			   this->ResumeLayout(false);

		  }
#pragma endregion
	 private: System::Void LoginPage_Load(System::Object^ sender, System::EventArgs^ e) {
		  this->Hide(); // Hide the login page when it loads
		  LoadingPage^ loading = gcnew LoadingPage();
		 // loading->label1->Text = "Loading..."; // Set the loading text
		  loading->ShowDialog();
		  this->Show(); // Show the login page after loading


	 }
	 };
}
