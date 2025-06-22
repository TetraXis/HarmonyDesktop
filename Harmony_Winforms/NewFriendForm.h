#pragma once
#include <sstream>

#include "MainForm.h"


//namespace HarmonyWinforms
//{
//	ref class MainForm;
//}


namespace HarmonyWinforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NewFriendForm
	/// </summary>
	public ref class NewFriendForm : public System::Windows::Forms::Form
	{
	public:
		NewFriendForm(void)
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
		~NewFriendForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: bool is_room = false; // yes, bc how connections are handled, friend is a private chat and room is group chat
	public: System::Windows::Forms::TextBox^ textbox_new_friend_name;
	public: MainForm^ main_form_ref;
	protected:

	protected:
	public: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::TextBox^ textbox_server_ip;

	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ textbox_server_port;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Button^ button_add_friend;
	public:

	public:

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
			this->textbox_new_friend_name = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textbox_server_ip = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textbox_server_port = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_add_friend = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->textbox_new_friend_name->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_new_friend_name->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_new_friend_name->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textbox_new_friend_name->ForeColor = System::Drawing::Color::White;
			this->textbox_new_friend_name->Location = System::Drawing::Point(95, 8);
			this->textbox_new_friend_name->Name = L"textbox_new_friend_name";
			this->textbox_new_friend_name->Size = System::Drawing::Size(162, 18);
			this->textbox_new_friend_name->TabIndex = 11;
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(4, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 16);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Friend name:";
			this->textbox_server_ip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_server_ip->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_server_ip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textbox_server_ip->ForeColor = System::Drawing::Color::White;
			this->textbox_server_ip->Location = System::Drawing::Point(95, 32);
			this->textbox_server_ip->Name = L"textbox_server_ip";
			this->textbox_server_ip->Size = System::Drawing::Size(162, 18);
			this->textbox_server_ip->TabIndex = 13;
			this->textbox_server_ip->TextChanged += gcnew System::EventHandler(this, &NewFriendForm::textBox1_TextChanged);
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(4, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 16);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Server IP:";
			this->label1->Click += gcnew System::EventHandler(this, &NewFriendForm::label1_Click);
			this->textbox_server_port->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_server_port->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_server_port->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textbox_server_port->ForeColor = System::Drawing::Color::White;
			this->textbox_server_port->Location = System::Drawing::Point(95, 56);
			this->textbox_server_port->Name = L"textbox_server_port";
			this->textbox_server_port->Size = System::Drawing::Size(162, 18);
			this->textbox_server_port->TabIndex = 15;
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(4, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 16);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Server PORT:";
			this->button_add_friend->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->button_add_friend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_add_friend->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_add_friend->ForeColor = System::Drawing::Color::White;
			this->button_add_friend->Location = System::Drawing::Point(32, 90);
			this->button_add_friend->Name = L"button_add_friend";
			this->button_add_friend->Size = System::Drawing::Size(198, 32);
			this->button_add_friend->TabIndex = 17;
			this->button_add_friend->Text = L"Add Friend";
			this->button_add_friend->UseVisualStyleBackColor = false;
			this->button_add_friend->Click += gcnew System::EventHandler(this, &NewFriendForm::button_add_friend_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->ClientSize = System::Drawing::Size(264, 135);
			this->Controls->Add(this->button_add_friend);
			this->Controls->Add(this->textbox_server_port);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textbox_server_ip);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textbox_new_friend_name);
			this->Controls->Add(this->label4);
			this->Name = L"NewFriendForm";
			this->Text = L"NewFriendForm";
			this->Load += gcnew System::EventHandler(this, &NewFriendForm::NewFriendForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_add_friend_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textbox_new_friend_name->Text == "" || textbox_server_ip->Text == "" || textbox_server_port->Text == "")
	{
		return;
	}

	sf::IpAddress test(msclr::interop::marshal_as<std::string>(textbox_server_ip->Text));

	if (test == sf::IpAddress::None)
	{
		textbox_server_ip->Text = "Bad address";
		return;
	}

	std::string test_port = msclr::interop::marshal_as<std::string>(textbox_server_port->Text);
	{
		std::istringstream iss(test_port);

		short num;

		iss >> num;

		if (iss.fail() || !iss.eof())
		{
			textbox_server_port->Text = "Bad port";
			return;
		}
	}

	if (is_room)
	{
		main_form_ref->new_room(textbox_new_friend_name->Text, textbox_server_ip->Text, textbox_server_port->Text);
	}
	else
	{
		main_form_ref->new_friend(textbox_new_friend_name->Text, textbox_server_ip->Text, textbox_server_port->Text);
	}

	Close();
}
private: System::Void NewFriendForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
