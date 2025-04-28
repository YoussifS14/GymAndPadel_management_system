#pragma once
#include"Structure.h"
namespace ProjectCode {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for sighup
	/// </summary>
	public ref class sighup : public System::Windows::Forms::Form
	{
	public:
		sighup(void)
		{
			InitializeComponent();
			selectedImagePath = nullptr;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~sighup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: String^ selectedImagePath;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sighup::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 28.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(41, 25);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(342, 189);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sign Up as ";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &sighup::groupBox1_Enter);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(27, 141);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(122, 52);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Staff";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &sighup::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(27, 83);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(192, 52);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Member";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &sighup::radioButton1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 169);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(99, 176);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(371, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 236);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Email ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(99, 243);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(371, 22);
			this->textBox2->TabIndex = 3;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->radioButton4);
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(41, 220);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1058, 413);
			this->panel1->TabIndex = 4;
			this->panel1->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(400, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(235, 163);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &sighup::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(414, 345);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(221, 46);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Submit ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &sighup::button1_Click);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton4->Location = System::Drawing::Point(546, 289);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(103, 33);
			this->radioButton4->TabIndex = 9;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Coach";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton3->Location = System::Drawing::Point(370, 289);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(144, 33);
			this->radioButton3->TabIndex = 8;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Reception";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(666, 176);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(371, 22);
			this->textBox4->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(552, 176);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 29);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Phone";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(540, 243);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(120, 29);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Password";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(666, 243);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(371, 22);
			this->textBox3->TabIndex = 4;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Image Files|.jpg;.jpeg;*.png";
			this->openFileDialog1->Title = L"Select a Staff Image";
			// 
			// sighup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1302, 636);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"sighup";
			this->Text = L"sign up";
			this->Load += gcnew System::EventHandler(this, &sighup::sighup_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton1->Checked) {
			panel1->Visible = false;
		}
	}

	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton2->Checked) {
			panel1->Visible = true;
		}
		else {
			panel1->Visible = false;
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		String^ name = textBox1->Text->Trim();
		String^ email = textBox2->Text->Trim();
		String^ password = textBox3->Text->Trim();
		String^ phone = textBox4->Text->Trim();

		// Simple validation
		if (String::IsNullOrWhiteSpace(name) || String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(password) || String::IsNullOrWhiteSpace(phone)) {
			MessageBox::Show("Please fill all fields.");
			return;
		}

		// Check if the email format is valid
		if (!email->Contains("@") || !email->Contains(".")) {
			MessageBox::Show("Please enter a valid email.");
			return;
		}
		if (phone->Length <= 11) {
			MessageBox::Show("Phone number must be more than 11 digits.");
			return;
		}

		// Validate phone number contains only digits
		for each (Char c in phone) {
			if (!Char::IsDigit(c)) {
				MessageBox::Show("Phone number must contain only digits.");
				return;
			}
		}
		// Handle staff role selection
		String^ role = "";
		if (radioButton3->Checked) {
			role = "Reception";
		}
		else if (radioButton4->Checked) {
			role = "Coach";
		}
		else {
			MessageBox::Show("Please select a role.");
			return;
		}


		if (String::IsNullOrEmpty(role)) {
			MessageBox::Show("Please select a staff role.");
			return;
		}
		Staff newstaff;
		String^ imagePath = "";
		if (selectedImagePath != nullptr && !String::IsNullOrEmpty(selectedImagePath)) {
			// Generate unique image path based on role and baseID
			imagePath = "Images/Staff/staff_" + role->Substring(0, 1) + (baseID + 1).ToString() + System::IO::Path::GetExtension(selectedImagePath);
		}
		bool registed = newstaff.registerStaff(marshal_as<std::string>(name), marshal_as<std::string>(email), marshal_as<std::string>(password), marshal_as<std::string>(phone), marshal_as<std::string>(role), marshal_as<std::string>(imagePath));
		if (registed) {
			if (selectedImagePath != nullptr && !String::IsNullOrEmpty(selectedImagePath)) {
				try {
					System::IO::Directory::CreateDirectory("Images/Staff"); // Ensure directory exists
					System::IO::File::Copy(selectedImagePath, imagePath, true);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Error saving image: " + ex->Message, "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			MessageBox::Show("Staff registed successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			textBox1->Clear();
			textBox2->Clear();
			textBox3->Clear();
			textBox4->Clear();
			pictureBox1->Image = nullptr;
			selectedImagePath = nullptr;
		}
		else {
			MessageBox::Show("Sign Up failed ,This email already has an account or name contains characters .", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void sighup_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				pictureBox1->BackgroundImage = nullptr;
				// Load the image into pictureBox1
				pictureBox1->Image = Image::FromFile(openFileDialog1->FileName);
				selectedImagePath = openFileDialog1->FileName; // Store the path
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	}
	};
}