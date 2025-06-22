#pragma once

//#include "MainForm.h"
#include "terminal.h"

namespace HarmonyWinforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ LoginGroupBox;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ PasswordsTextVox;


	private: System::Windows::Forms::TextBox^ LoginTextBox;
	private: System::Windows::Forms::FlowLayoutPanel^ LoginLayoutPanel;
	private: System::Windows::Forms::Button^ LoginButton;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_version;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textbox_local_port;

	private: System::Windows::Forms::Label^ label3;




	protected:

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
			this->LoginGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->LoginLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->LoginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->PasswordsTextVox = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->LoginButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_version = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textbox_local_port = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->LoginGroupBox->SuspendLayout();
			this->LoginLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// LoginGroupBox
			// 
			this->LoginGroupBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->LoginGroupBox->AutoSize = true;
			this->LoginGroupBox->Controls->Add(this->LoginLayoutPanel);
			this->LoginGroupBox->ForeColor = System::Drawing::Color::White;
			this->LoginGroupBox->Location = System::Drawing::Point(350, 245);
			this->LoginGroupBox->Name = L"LoginGroupBox";
			this->LoginGroupBox->Size = System::Drawing::Size(240, 139);
			this->LoginGroupBox->TabIndex = 0;
			this->LoginGroupBox->TabStop = false;
			this->LoginGroupBox->Text = L"Login";
			// 
			// LoginLayoutPanel
			// 
			this->LoginLayoutPanel->Controls->Add(this->LoginTextBox);
			this->LoginLayoutPanel->Controls->Add(this->panel1);
			this->LoginLayoutPanel->Controls->Add(this->PasswordsTextVox);
			this->LoginLayoutPanel->Controls->Add(this->panel2);
			this->LoginLayoutPanel->Controls->Add(this->LoginButton);
			this->LoginLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LoginLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->LoginLayoutPanel->Location = System::Drawing::Point(3, 21);
			this->LoginLayoutPanel->Name = L"LoginLayoutPanel";
			this->LoginLayoutPanel->Size = System::Drawing::Size(234, 115);
			this->LoginLayoutPanel->TabIndex = 1;
			// 
			// LoginTextBox
			// 
			this->LoginTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
																			 static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->LoginTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->LoginTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
																	static_cast<System::Byte>(204)));
			this->LoginTextBox->ForeColor = System::Drawing::Color::White;
			this->LoginTextBox->Location = System::Drawing::Point(3, 0);
			this->LoginTextBox->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->LoginTextBox->Name = L"LoginTextBox";
			this->LoginTextBox->Size = System::Drawing::Size(230, 27);
			this->LoginTextBox->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(3, 27);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(231, 3);
			this->panel1->TabIndex = 1;
			// 
			// PasswordsTextVox
			// 
			this->PasswordsTextVox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																								| System::Windows::Forms::AnchorStyles::Right));
			this->PasswordsTextVox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
																				 static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->PasswordsTextVox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PasswordsTextVox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
																		static_cast<System::Byte>(204)));
			this->PasswordsTextVox->ForeColor = System::Drawing::Color::White;
			this->PasswordsTextVox->Location = System::Drawing::Point(3, 33);
			this->PasswordsTextVox->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->PasswordsTextVox->Name = L"PasswordsTextVox";
			this->PasswordsTextVox->PasswordChar = '*';
			this->PasswordsTextVox->Size = System::Drawing::Size(231, 27);
			this->PasswordsTextVox->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(3, 60);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(231, 3);
			this->panel2->TabIndex = 2;
			// 
			// LoginButton
			// 
			this->LoginButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																						   | System::Windows::Forms::AnchorStyles::Right));
			this->LoginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
																			static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->LoginButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->LoginButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(204)));
			this->LoginButton->ForeColor = System::Drawing::Color::White;
			this->LoginButton->Location = System::Drawing::Point(3, 69);
			this->LoginButton->Name = L"LoginButton";
			this->LoginButton->Size = System::Drawing::Size(231, 43);
			this->LoginButton->TabIndex = 2;
			this->LoginButton->Text = L"Login";
			this->LoginButton->UseVisualStyleBackColor = false;
			this->LoginButton->Click += gcnew System::EventHandler(this, &LoginForm::LoginButton_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
															  static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->label1->Location = System::Drawing::Point(346, 387);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(208, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Forgot login or password\?";
			// 
			// label_version
			// 
			this->label_version->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_version->AutoSize = true;
			this->label_version->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																	 static_cast<System::Byte>(204)));
			this->label_version->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
																			  static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->label_version->Location = System::Drawing::Point(12, 609);
			this->label_version->Name = L"label_version";
			this->label_version->Size = System::Drawing::Size(238, 28);
			this->label_version->TabIndex = 2;
			this->label_version->Text = L"Harmony version 0.0.2";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
															  static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->label2->Location = System::Drawing::Point(346, 410);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Register";
			// 
			// textbox_local_port
			// 
			this->textbox_local_port->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textbox_local_port->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
																				   static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_local_port->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_local_port->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																		  static_cast<System::Byte>(204)));
			this->textbox_local_port->ForeColor = System::Drawing::Color::White;
			this->textbox_local_port->Location = System::Drawing::Point(859, 609);
			this->textbox_local_port->Name = L"textbox_local_port";
			this->textbox_local_port->Size = System::Drawing::Size(71, 23);
			this->textbox_local_port->TabIndex = 4;
			this->textbox_local_port->Text = L"11111";
			this->textbox_local_port->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textbox_local_port->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(787, 613);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Local PORT:";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
															   static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->ClientSize = System::Drawing::Size(942, 646);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textbox_local_port);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label_version);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LoginGroupBox);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
													  static_cast<System::Byte>(204)));
			this->Name = L"LoginForm";
			this->Text = L"Harmony";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->LoginGroupBox->ResumeLayout(false);
			this->LoginLayoutPanel->ResumeLayout(false);
			this->LoginLayoutPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	public: std::string ManagedStringToStdString(String^ managedStr)
	{
		return msclr::interop::marshal_as<std::string>(managedStr);
	}

		private: System::Void LoginButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (LoginTextBox->Text == "")
			{
				LoginButton->Text = "Login (Enter username)";
				return;
			}


			std::hash<std::string> hasher;

			MainForm^ main_form = gcnew MainForm();
			global_main_form = main_form;

			*user_name = ManagedStringToStdString(LoginTextBox->Text);
			user_hash = hasher(*user_name);

			local_port = std::stoi(ManagedStringToStdString(textbox_local_port->Text).c_str());
			main_form->username = LoginTextBox->Text;

			this->Hide();

			main_form->Show();
		}
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}
};
}
