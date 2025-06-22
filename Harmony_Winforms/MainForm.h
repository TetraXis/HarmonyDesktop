#pragma once

#include "Server.h"
#include "ip_info.h"

#include <string>
#include <iostream>
#include <sstream>

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

//#include "NewFriendForm.h"

extern Server* server;
extern bool server_connection;

extern sf::IpAddress* server_ip;
extern unsigned short local_port;
extern unsigned short server_port;

extern std::string* user_name;
extern size_t user_hash;


namespace HarmonyWinforms {



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:

		String^ username;

		Thread^ taskThread;
		bool isThreadRunning;

		// to map button names with ids
		Dictionary<String^, unsigned int>^ id_dict = gcnew Dictionary<String^, unsigned int>();
		List<ip_info^>^ friends_ips = gcnew List<ip_info^>();
		List<String^>^ friend_names = gcnew List<String^>();
		List<ListBox^>^ listboxes = gcnew List<ListBox^>();

	public:
		unsigned int next_free_id = 0;
	public: System::Windows::Forms::Panel^ panel1;
	public: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;

	public: System::Windows::Forms::TextBox^ textbox_server_ip;

	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::TextBox^ textbox_server_port;




	public: System::Windows::Forms::Button^ JoinRoomButton;
	public: System::Windows::Forms::GroupBox^ RoomsGroupBox;

	public: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;


	public:
		unsigned int selected_id = 0;
		
		//array<String^>^ chat_history;

		MainForm(void)
		{
			InitializeComponent();

			id_dict[Friend1Button->Text] = next_free_id;
			friend_names->Add(Friend1Button->Text);
			friends_ips->Add(gcnew ip_info{ new sf::IpAddress("127.0.0.1"), 443 });
			//friend_names[next_free_id] = Friend1Button->Text;
			++next_free_id;
			listboxes->Add(gcnew ListBox());
			//ChatListBox = listboxes[0];
			CharGroupBox->Text = L"DebugChannel";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: System::Windows::Forms::Button^ NewFriendButton;
	public: System::Windows::Forms::StatusStrip^ StatusStrip;
	public: System::Windows::Forms::Panel^ MainPanel;
	public: System::Windows::Forms::GroupBox^ FriendsGroupBox;
	public: System::Windows::Forms::FlowLayoutPanel^ FriendsFlowLayoutPanel;
	public: System::Windows::Forms::Button^ Friend1Button;
	public: System::Windows::Forms::GroupBox^ CharGroupBox;
	public: System::Windows::Forms::Button^ SendButton;
	public: System::Windows::Forms::TextBox^ ChatTextBox;
	public: System::Windows::Forms::ListBox^ ChatListBox;


	protected:

	public:
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
			this->StatusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->MainPanel = (gcnew System::Windows::Forms::Panel());
			this->RoomsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CharGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->JoinRoomButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->NewFriendButton = (gcnew System::Windows::Forms::Button());
			this->ChatListBox = (gcnew System::Windows::Forms::ListBox());
			this->SendButton = (gcnew System::Windows::Forms::Button());
			this->ChatTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FriendsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->FriendsFlowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Friend1Button = (gcnew System::Windows::Forms::Button());
			this->textbox_server_ip = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textbox_server_port = (gcnew System::Windows::Forms::TextBox());
			this->StatusStrip->SuspendLayout();
			this->MainPanel->SuspendLayout();
			this->RoomsGroupBox->SuspendLayout();
			this->CharGroupBox->SuspendLayout();
			this->FriendsGroupBox->SuspendLayout();
			this->FriendsFlowLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// StatusStrip
			// 
			this->StatusStrip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->StatusStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->StatusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->StatusStrip->Location = System::Drawing::Point(0, 702);
			this->StatusStrip->Name = L"StatusStrip";
			this->StatusStrip->Padding = System::Windows::Forms::Padding(1, 0, 12, 0);
			this->StatusStrip->Size = System::Drawing::Size(1395, 26);
			this->StatusStrip->TabIndex = 0;
			this->StatusStrip->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(205, 20);
			this->toolStripStatusLabel1->Text = L"Harmony :: active user session";
			// 
			// MainPanel
			// 
			this->MainPanel->Controls->Add(this->RoomsGroupBox);
			this->MainPanel->Controls->Add(this->CharGroupBox);
			this->MainPanel->Controls->Add(this->FriendsGroupBox);
			this->MainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MainPanel->Location = System::Drawing::Point(0, 0);
			this->MainPanel->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MainPanel->Name = L"MainPanel";
			this->MainPanel->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MainPanel->Size = System::Drawing::Size(1395, 702);
			this->MainPanel->TabIndex = 1;
			// 
			// RoomsGroupBox
			// 
			this->RoomsGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->RoomsGroupBox->Controls->Add(this->flowLayoutPanel1);
			this->RoomsGroupBox->ForeColor = System::Drawing::Color::White;
			this->RoomsGroupBox->Location = System::Drawing::Point(188, 5);
			this->RoomsGroupBox->Margin = System::Windows::Forms::Padding(13, 16, 13, 16);
			this->RoomsGroupBox->Name = L"RoomsGroupBox";
			this->RoomsGroupBox->Padding = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->RoomsGroupBox->Size = System::Drawing::Size(175, 692);
			this->RoomsGroupBox->TabIndex = 1;
			this->RoomsGroupBox->TabStop = false;
			this->RoomsGroupBox->Text = L"Rooms";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(4, 21);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(167, 668);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// CharGroupBox
			// 
			this->CharGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->CharGroupBox->Controls->Add(this->JoinRoomButton);
			this->CharGroupBox->Controls->Add(this->panel1);
			this->CharGroupBox->Controls->Add(this->NewFriendButton);
			this->CharGroupBox->Controls->Add(this->ChatListBox);
			this->CharGroupBox->Controls->Add(this->SendButton);
			this->CharGroupBox->Controls->Add(this->ChatTextBox);
			this->CharGroupBox->ForeColor = System::Drawing::Color::White;
			this->CharGroupBox->Location = System::Drawing::Point(367, 5);
			this->CharGroupBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->CharGroupBox->Name = L"CharGroupBox";
			this->CharGroupBox->Padding = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->CharGroupBox->Size = System::Drawing::Size(1026, 693);
			this->CharGroupBox->TabIndex = 1;
			this->CharGroupBox->TabStop = false;
			this->CharGroupBox->Text = L"Chat";
			this->CharGroupBox->Enter += gcnew System::EventHandler(this, &MainForm::CharGroupBox_Enter);
			// 
			// JoinRoomButton
			// 
			this->JoinRoomButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->JoinRoomButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->JoinRoomButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->JoinRoomButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->JoinRoomButton->Location = System::Drawing::Point(107, 636);
			this->JoinRoomButton->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->JoinRoomButton->Name = L"JoinRoomButton";
			this->JoinRoomButton->Size = System::Drawing::Size(92, 44);
			this->JoinRoomButton->TabIndex = 8;
			this->JoinRoomButton->Text = L"Join Room";
			this->JoinRoomButton->UseVisualStyleBackColor = false;
			this->JoinRoomButton->Click += gcnew System::EventHandler(this, &MainForm::JoinRoomButton_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(208, 670);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(676, 5);
			this->panel1->TabIndex = 6;
			// 
			// NewFriendButton
			// 
			this->NewFriendButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->NewFriendButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->NewFriendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->NewFriendButton->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NewFriendButton->Location = System::Drawing::Point(8, 636);
			this->NewFriendButton->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->NewFriendButton->Name = L"NewFriendButton";
			this->NewFriendButton->Size = System::Drawing::Size(91, 44);
			this->NewFriendButton->TabIndex = 5;
			this->NewFriendButton->Text = L"Add New Friend";
			this->NewFriendButton->UseVisualStyleBackColor = false;
			this->NewFriendButton->Click += gcnew System::EventHandler(this, &MainForm::NewFriendButton_Click);
			// 
			// ChatListBox
			// 
			this->ChatListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ChatListBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->ChatListBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ChatListBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ChatListBox->ForeColor = System::Drawing::Color::White;
			this->ChatListBox->FormattingEnabled = true;
			this->ChatListBox->ItemHeight = 23;
			this->ChatListBox->Location = System::Drawing::Point(6, 23);
			this->ChatListBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->ChatListBox->Name = L"ChatListBox";
			this->ChatListBox->Size = System::Drawing::Size(1018, 598);
			this->ChatListBox->TabIndex = 4;
			this->ChatListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ChatListBox_SelectedIndexChanged);
			// 
			// SendButton
			// 
			this->SendButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->SendButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->SendButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SendButton->Location = System::Drawing::Point(889, 636);
			this->SendButton->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->SendButton->Name = L"SendButton";
			this->SendButton->Size = System::Drawing::Size(126, 44);
			this->SendButton->TabIndex = 3;
			this->SendButton->Text = L"Send";
			this->SendButton->UseVisualStyleBackColor = false;
			this->SendButton->Click += gcnew System::EventHandler(this, &MainForm::SendButton_Click);
			// 
			// ChatTextBox
			// 
			this->ChatTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ChatTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ChatTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ChatTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ChatTextBox->ForeColor = System::Drawing::Color::White;
			this->ChatTextBox->Location = System::Drawing::Point(207, 636);
			this->ChatTextBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 0);
			this->ChatTextBox->Name = L"ChatTextBox";
			this->ChatTextBox->Size = System::Drawing::Size(677, 23);
			this->ChatTextBox->TabIndex = 2;
			this->ChatTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::ChatTextBox_TextChanged);
			// 
			// FriendsGroupBox
			// 
			this->FriendsGroupBox->Controls->Add(this->FriendsFlowLayoutPanel);
			this->FriendsGroupBox->Dock = System::Windows::Forms::DockStyle::Left;
			this->FriendsGroupBox->ForeColor = System::Drawing::Color::White;
			this->FriendsGroupBox->Location = System::Drawing::Point(4, 5);
			this->FriendsGroupBox->Margin = System::Windows::Forms::Padding(13, 16, 13, 16);
			this->FriendsGroupBox->Name = L"FriendsGroupBox";
			this->FriendsGroupBox->Padding = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->FriendsGroupBox->Size = System::Drawing::Size(175, 692);
			this->FriendsGroupBox->TabIndex = 0;
			this->FriendsGroupBox->TabStop = false;
			this->FriendsGroupBox->Text = L"Friends";
			this->FriendsGroupBox->Enter += gcnew System::EventHandler(this, &MainForm::FriendsGroupBox_Enter);
			// 
			// FriendsFlowLayoutPanel
			// 
			this->FriendsFlowLayoutPanel->Controls->Add(this->Friend1Button);
			this->FriendsFlowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FriendsFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->FriendsFlowLayoutPanel->Location = System::Drawing::Point(4, 21);
			this->FriendsFlowLayoutPanel->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->FriendsFlowLayoutPanel->Name = L"FriendsFlowLayoutPanel";
			this->FriendsFlowLayoutPanel->Size = System::Drawing::Size(167, 668);
			this->FriendsFlowLayoutPanel->TabIndex = 0;
			this->FriendsFlowLayoutPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::FriendsFlowLayoutPanel_Paint);
			// 
			// Friend1Button
			// 
			this->Friend1Button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->Friend1Button->Dock = System::Windows::Forms::DockStyle::Left;
			this->Friend1Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Friend1Button->Location = System::Drawing::Point(4, 3);
			this->Friend1Button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Friend1Button->Name = L"Friend1Button";
			this->Friend1Button->Size = System::Drawing::Size(159, 30);
			this->Friend1Button->TabIndex = 0;
			this->Friend1Button->Text = L"DebugChannel";
			this->Friend1Button->UseVisualStyleBackColor = false;
			this->Friend1Button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);
			// 
			// textbox_server_ip
			// 
			this->textbox_server_ip->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textbox_server_ip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_server_ip->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_server_ip->ForeColor = System::Drawing::Color::White;
			this->textbox_server_ip->Location = System::Drawing::Point(1098, 706);
			this->textbox_server_ip->Name = L"textbox_server_ip";
			this->textbox_server_ip->Size = System::Drawing::Size(105, 18);
			this->textbox_server_ip->TabIndex = 2;
			this->textbox_server_ip->Text = L"127.0.0.1";
			this->textbox_server_ip->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			this->textbox_server_ip->Leave += gcnew System::EventHandler(this, &MainForm::textbox_server_ip_Leave);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1026, 707);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Service IP:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1209, 706);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Service PORT:";
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// textbox_server_port
			// 
			this->textbox_server_port->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textbox_server_port->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_server_port->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_server_port->ForeColor = System::Drawing::Color::White;
			this->textbox_server_port->Location = System::Drawing::Point(1302, 705);
			this->textbox_server_port->Name = L"textbox_server_port";
			this->textbox_server_port->Size = System::Drawing::Size(59, 18);
			this->textbox_server_port->TabIndex = 5;
			this->textbox_server_port->Text = L"443";
			this->textbox_server_port->TextChanged += gcnew System::EventHandler(this, &MainForm::textbox_server_port_TextChanged);
			this->textbox_server_port->Leave += gcnew System::EventHandler(this, &MainForm::textbox_server_port_Leave);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->ClientSize = System::Drawing::Size(1395, 728);
			this->Controls->Add(this->textbox_server_port);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textbox_server_ip);
			this->Controls->Add(this->MainPanel);
			this->Controls->Add(this->StatusStrip);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::Color::White;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MainForm";
			this->Text = L"Harmony";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->StatusStrip->ResumeLayout(false);
			this->StatusStrip->PerformLayout();
			this->MainPanel->ResumeLayout(false);
			this->RoomsGroupBox->ResumeLayout(false);
			this->CharGroupBox->ResumeLayout(false);
			this->CharGroupBox->PerformLayout();
			this->FriendsGroupBox->ResumeLayout(false);
			this->FriendsFlowLayoutPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SendButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (ChatTextBox->Text == "")
			{
				return;
			}

			listboxes[selected_id]->Items->Add(username + "  ::  " + DateTime::Now.ToString() + "\n");
			listboxes[selected_id]->Items->Add("  " + ChatTextBox->Text);


			//ChatListBox->Items->Add(username + "  ::  " + DateTime::Now.ToString() + "\n");
			//ChatListBox->Items->Add("  " + ChatTextBox->Text);
			//
			std::cout << "> Sent: " << "send_msg " + *user_name + " " + ManagedStringToStdString(ChatTextBox->Text) << " " << *server_ip << " " << server_port << '\n';

			if (!server_connection)
			{
				server->send
				(
					"server_join " + *user_name + " " + std::to_string(local_port),
					*server_ip,
					server_port
				);

				Sleep(100);
			}
			if (!server_connection)
			{
				server->send
				(
					"server_join " + *user_name + " " + std::to_string(local_port),
					*server_ip,
					server_port
				);

				Sleep(100);
			}

			server->send("send_msg " + *user_name + " " + ManagedStringToStdString(friend_names[selected_id]).c_str() + " " + ManagedStringToStdString(ChatTextBox->Text), *server_ip, server_port);

			ChatTextBox->Text = "";
		}
			   
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e)
		{
			*server_ip = sf::IpAddress(ManagedStringToStdString(textbox_server_ip->Text).c_str());
			server_port = std::stoi(ManagedStringToStdString(textbox_server_port->Text).c_str());

			toolStripStatusLabel1->Text = gcnew String(("Harmony :: " + *user_name).c_str());

			isThreadRunning = true; // Set the flag to true
			taskThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::update_thread));
			taskThread->Start();
		}

	public: void update_thread(Object^ data)
	{
		if (!server)
		{
			server = new Server();
			server->start(local_port);
		}
	
	
		while (isThreadRunning)
		{
			Sleep(200);
			//std::cout << server->pendnig_msgs.size() << '\n';
			if (server->pendnig_msgs.size() != 0)
			{
				for (const auto& pair : server->pendnig_msgs)
				{
					std::cout << "New message pending...\n";
					std::cout << "In room: " << pair.first.first << '\n';
					std::cout << "User: " << pair.first.second << '\n';
					std::cout << "Says: " << pair.second << '\n';

					unsigned int id = 0;

					id = id_dict[gcnew String (pair.first.first.c_str())];


					if (this->InvokeRequired)
					{
						std::cout << "Invoked with " << pair.second << '\n';
						// still compiles
						this->Invoke(gcnew Action<unsigned int, String^, String^>(this, &MainForm::AddChatMessage), id, gcnew String(pair.first.second.c_str()),
							gcnew String(pair.second.c_str()));
					}
				}
				//for (unsigned int id = 0; id < server->pendnig_msgs.size(); id++)
				//{
				//	for (int i = 0; i < server->pendnig_msgs[id].size(); i++)
				//	{
				//		if (this->InvokeRequired)
				//		{
				//			std::cout << "Invoked with " << server->pendnig_msgs[id][i].c_str() << '\n';
				//			// still compiles
				//			this->Invoke(gcnew Action<unsigned int, String^>(this, &MainForm::AddChatMessage), id, 
				//				gcnew String(server->pendnig_msgs[id][i].c_str()));
				//		}
				//	}
				//}
				server->pendnig_msgs.clear();
			}
		}
	
		delete server;
	}


	public: std::string ManagedStringToStdString(String^ managedStr)
	{
		return msclr::interop::marshal_as<std::string>(managedStr);
	}


	private: void AddChatMessage(unsigned int room_id, String^ sender, String^ message)
	{
		if (room_id >= next_free_id)
		{
			return;
		}

		std::cout << "New message " << ManagedStringToStdString(message) << '\n';


		listboxes[room_id]->Items->Add(sender + "  ::  " + DateTime::Now.ToString() + "\n");
		listboxes[room_id]->Items->Add("  " + message);

		if (room_id == selected_id)
		{
			ChatListBox->Items->Add(sender + "  ::  " + DateTime::Now.ToString() + "\n");
			ChatListBox->Items->Add("  " + message);
		}
	}

	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		isThreadRunning = false; 
		if (taskThread != nullptr && taskThread->IsAlive)
		{
			taskThread->Join(); 
		}
		//Form::OnFormClosing(e);
	}
	public: void CopyListBoxItems(ListBox^ source, ListBox^ destination)
	{
		destination->Items->Clear();
		

		for each (Object ^ item in source->Items)
		{
			destination->Items->Add(item);
		}
	}

	public: System::Void Friend1Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		unsigned int selected_new_id = id_dict[((Button^)sender)->Text];
		CopyListBoxItems(ChatListBox, listboxes[selected_id]);
		selected_id = selected_new_id;

		*server_ip = *friends_ips[selected_id]->ip;
		server_port = friends_ips[selected_id]->port;

		textbox_server_ip->Text = gcnew String (friends_ips[selected_id]->ip->toString().c_str());
		textbox_server_port->Text = gcnew String (std::to_string(friends_ips[selected_id]->port).c_str());



		CopyListBoxItems(listboxes[selected_id], ChatListBox);


		CharGroupBox->Text = (((Button^)sender)->Text);

		//ChatListBox = listboxes[selected_new_id];
	}


	public: System::Void NewFriendButton_Click(System::Object^ sender, System::EventArgs^ e);
	//{
		/*NewFriendForm^ new_friend_form = gcnew NewFriendForm();

		new_friend_form->main_form_ref = this;

		new_friend_form->ShowDialog();*/

		//if (textbox_new_friend_name->Text == "")
		//{
		//	return;
		//}
		////String^ new_frined_name = gcnew String("Room" + next_free_id);
		//String^ new_frined_name = gcnew String(textbox_new_friend_name->Text);
		//textbox_new_friend_name->Clear();

		//Button^ new_button = gcnew Button();


		///*new_button->Dock = System::Windows::Forms::DockStyle::Left;
		//new_button->Location = System::Drawing::Point(3, 3);
		//new_button->Name = new_frined_name;
		//new_button->Size = System::Drawing::Size(140, 30);
		//new_button->TabIndex = 0;
		//new_button->Text = new_frined_name;
		//new_button->UseVisualStyleBackColor = true;
		//new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);*/


		//new_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),																  static_cast<System::Int32>(static_cast<System::Byte>(50)));
		//new_button->Dock = System::Windows::Forms::DockStyle::Left;
		//new_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		//new_button->Location = System::Drawing::Point(4, 3);
		//new_button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
		//new_button->Name = new_frined_name;
		//new_button->Size = System::Drawing::Size(159, 30);
		//new_button->TabIndex = 0;
		//new_button->Text = new_frined_name;
		//new_button->UseVisualStyleBackColor = false;
		//new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);

		//FriendsFlowLayoutPanel->Controls->Add(new_button);

		//listboxes->Add(gcnew ListBox());
		//friend_names->Add(new_frined_name);
		//id_dict[new_frined_name] = next_free_id;

		//while (id_dict->ContainsValue(next_free_id))
		//{
		//	++next_free_id; 
		//}
	//}

	public: void new_friend(String^ name, String^ ip, String^ port);
	public: void new_room(String^ name, String^ ip, String^ port);


	public: void new_friend(unsigned long long new_friend_id)
	{
		std::cout << "new friend id\n";
		if (id_dict->ContainsValue(new_friend_id))
		{
			return;
		}

		String^ new_frined_name;

		new_frined_name = gcnew String(std::string("New friend " + std::to_string(new_friend_id)).c_str());

		Button^ new_button = gcnew Button();


		/*new_button->Dock = System::Windows::Forms::DockStyle::Left;
		new_button->Location = System::Drawing::Point(3, 3);
		new_button->Name = new_frined_name;
		new_button->Size = System::Drawing::Size(140, 30);
		new_button->TabIndex = 0;
		new_button->Text = new_frined_name;
		new_button->UseVisualStyleBackColor = true;
		new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);*/


		new_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
		new_button->Dock = System::Windows::Forms::DockStyle::Left;
		new_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		new_button->Location = System::Drawing::Point(4, 3);
		new_button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
		new_button->Name = new_frined_name;
		new_button->Size = System::Drawing::Size(159, 30);
		new_button->TabIndex = 0;
		new_button->Text = new_frined_name;
		new_button->UseVisualStyleBackColor = false;
		new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);

		FriendsFlowLayoutPanel->Controls->Add(new_button);

		listboxes->Add(gcnew ListBox());
		friend_names->Add(new_frined_name);
		id_dict[new_frined_name] = next_free_id;

		while (id_dict->ContainsValue(next_free_id))
		{
			++next_free_id;
		}
	}

	public: void new_friend(System::String^ new_room_name)
	{
		std::cout << "new friend name\n";

		//String^ new_room_name = gcnew String(args[0].c_str());

		Button^ new_button = gcnew Button();


		/*new_button->Dock = System::Windows::Forms::DockStyle::Left;
		new_button->Location = System::Drawing::Point(3, 3);
		new_button->Name = new_frined_name;
		new_button->Size = System::Drawing::Size(140, 30);
		new_button->TabIndex = 0;
		new_button->Text = new_frined_name;
		new_button->UseVisualStyleBackColor = true;
		new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);*/


		new_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
		new_button->Dock = System::Windows::Forms::DockStyle::Left;
		new_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		new_button->Location = System::Drawing::Point(4, 3);
		new_button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
		new_button->Name = new_room_name;
		new_button->Size = System::Drawing::Size(159, 30);
		new_button->TabIndex = 0;
		new_button->Text = new_room_name;
		new_button->UseVisualStyleBackColor = false;
		new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);

		FriendsFlowLayoutPanel->Controls->Add(new_button);

		listboxes->Add(gcnew ListBox());
		friend_names->Add(new_room_name);
		id_dict[new_room_name] = next_free_id;

		while (id_dict->ContainsValue(next_free_id))
		{
			++next_free_id;
		}
	}


	private: System::Void FriendsFlowLayoutPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
	}
	private: System::Void CharGroupBox_Enter(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void Call_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		server->send(std::string("call " + std::to_string(selected_id)), *server_ip, server_port);
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void textbox_server_port_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void JoinRoomButton_Click(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void ChatListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ChatTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void FriendsGroupBox_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textbox_server_ip_Leave(System::Object^ sender, System::EventArgs^ e)
{
	sf::IpAddress test(msclr::interop::marshal_as<std::string>(textbox_server_ip->Text));

	if (test == sf::IpAddress::None)
	{
		textbox_server_ip->Text = "127.0.0.1";
	}
		*server_ip = sf::IpAddress(ManagedStringToStdString(textbox_server_ip->Text).c_str());

		*friends_ips[selected_id]->ip = sf::IpAddress(ManagedStringToStdString(textbox_server_ip->Text).c_str());

		server_connection = false;
}
private: System::Void textbox_server_port_Leave(System::Object^ sender, System::EventArgs^ e)
{


	std::string test_port = msclr::interop::marshal_as<std::string>(textbox_server_port->Text);
	{
		std::istringstream iss(test_port);

		short num;

		iss >> num;

		if (iss.fail() || !iss.eof())
		{
			textbox_server_port->Text = "443";
		}
	}
	server_port = std::stoi(ManagedStringToStdString(textbox_server_port->Text).c_str());

	friends_ips[selected_id]->port = std::stoi(ManagedStringToStdString(textbox_server_port->Text).c_str());

	server_connection = false;

}
};

}
