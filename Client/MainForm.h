#pragma once

#include "Server.h"

#include <string>
#include <iostream>

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

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
		List<String^>^ friend_names = gcnew List<String^>();
		List<ListBox^>^ listboxes = gcnew List<ListBox^>();

	public:
		unsigned int next_free_id = 0;
	public: System::Windows::Forms::Panel^ panel1;
	public: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	public: System::Windows::Forms::Button^ Call_button;
	public: System::Windows::Forms::TextBox^ textbox_server_ip;

	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::TextBox^ textbox_server_port;
	public: System::Windows::Forms::TextBox^ textbox_new_friend_name;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::TextBox^ textbox_new_room_name;
	public: System::Windows::Forms::Button^ JoinRoomButton;


	public:
		unsigned int selected_id = 0;
		
		//array<String^>^ chat_history;

		MainForm(void)
		{
			InitializeComponent();

			id_dict[Friend1Button->Text] = next_free_id;
			friend_names->Add(Friend1Button->Text);
			//friend_names[next_free_id] = Friend1Button->Text;
			++next_free_id;
			listboxes->Add(gcnew ListBox());
			//ChatListBox = listboxes[0];
			CharGroupBox->Text = L"Виктор";
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
			this->CharGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->JoinRoomButton = (gcnew System::Windows::Forms::Button());
			this->Call_button = (gcnew System::Windows::Forms::Button());
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
			this->textbox_new_friend_name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textbox_new_room_name = (gcnew System::Windows::Forms::TextBox());
			this->StatusStrip->SuspendLayout();
			this->MainPanel->SuspendLayout();
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
			this->StatusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1)
			{
				this->toolStripStatusLabel1
			});
			this->StatusStrip->Location = System::Drawing::Point(0, 699);
			this->StatusStrip->Name = L"StatusStrip";
			this->StatusStrip->Padding = System::Windows::Forms::Padding(1, 0, 12, 0);
			this->StatusStrip->Size = System::Drawing::Size(1208, 26);
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
			this->MainPanel->Controls->Add(this->CharGroupBox);
			this->MainPanel->Controls->Add(this->FriendsGroupBox);
			this->MainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MainPanel->Location = System::Drawing::Point(0, 0);
			this->MainPanel->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MainPanel->Name = L"MainPanel";
			this->MainPanel->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MainPanel->Size = System::Drawing::Size(1208, 699);
			this->MainPanel->TabIndex = 1;
			// 
			// CharGroupBox
			// 
			this->CharGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
																							 | System::Windows::Forms::AnchorStyles::Left)
																							| System::Windows::Forms::AnchorStyles::Right));
			this->CharGroupBox->Controls->Add(this->JoinRoomButton);
			this->CharGroupBox->Controls->Add(this->Call_button);
			this->CharGroupBox->Controls->Add(this->panel1);
			this->CharGroupBox->Controls->Add(this->NewFriendButton);
			this->CharGroupBox->Controls->Add(this->ChatListBox);
			this->CharGroupBox->Controls->Add(this->SendButton);
			this->CharGroupBox->Controls->Add(this->ChatTextBox);
			this->CharGroupBox->ForeColor = System::Drawing::Color::White;
			this->CharGroupBox->Location = System::Drawing::Point(182, 5);
			this->CharGroupBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->CharGroupBox->Name = L"CharGroupBox";
			this->CharGroupBox->Padding = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->CharGroupBox->Size = System::Drawing::Size(1024, 690);
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
			this->JoinRoomButton->Location = System::Drawing::Point(107, 633);
			this->JoinRoomButton->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->JoinRoomButton->Name = L"JoinRoomButton";
			this->JoinRoomButton->Size = System::Drawing::Size(92, 44);
			this->JoinRoomButton->TabIndex = 8;
			this->JoinRoomButton->Text = L"Join Room";
			this->JoinRoomButton->UseVisualStyleBackColor = false;
			this->JoinRoomButton->Click += gcnew System::EventHandler(this, &MainForm::JoinRoomButton_Click);
			// 
			// Call_button
			// 
			this->Call_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Call_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
																			static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->Call_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Call_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(204)));
			this->Call_button->Location = System::Drawing::Point(207, 633);
			this->Call_button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Call_button->Name = L"Call_button";
			this->Call_button->Size = System::Drawing::Size(105, 45);
			this->Call_button->TabIndex = 7;
			this->Call_button->Text = L"Call";
			this->Call_button->UseVisualStyleBackColor = false;
			this->Call_button->Click += gcnew System::EventHandler(this, &MainForm::Call_button_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
																					  | System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(319, 660);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(562, 3);
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
			this->NewFriendButton->Location = System::Drawing::Point(8, 633);
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
			this->ChatListBox->Size = System::Drawing::Size(1016, 598);
			this->ChatListBox->TabIndex = 4;
			// 
			// SendButton
			// 
			this->SendButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->SendButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
																		   static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->SendButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																  static_cast<System::Byte>(204)));
			this->SendButton->Location = System::Drawing::Point(887, 633);
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
			this->ChatTextBox->Location = System::Drawing::Point(318, 632);
			this->ChatTextBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 0);
			this->ChatTextBox->Multiline = true;
			this->ChatTextBox->Name = L"ChatTextBox";
			this->ChatTextBox->Size = System::Drawing::Size(564, 38);
			this->ChatTextBox->TabIndex = 2;
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
			this->FriendsGroupBox->Size = System::Drawing::Size(175, 689);
			this->FriendsGroupBox->TabIndex = 0;
			this->FriendsGroupBox->TabStop = false;
			this->FriendsGroupBox->Text = L"Friends";
			// 
			// FriendsFlowLayoutPanel
			// 
			this->FriendsFlowLayoutPanel->Controls->Add(this->Friend1Button);
			this->FriendsFlowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FriendsFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->FriendsFlowLayoutPanel->Location = System::Drawing::Point(4, 21);
			this->FriendsFlowLayoutPanel->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->FriendsFlowLayoutPanel->Name = L"FriendsFlowLayoutPanel";
			this->FriendsFlowLayoutPanel->Size = System::Drawing::Size(167, 665);
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
			this->Friend1Button->Text = L"Виктор";
			this->Friend1Button->UseVisualStyleBackColor = false;
			this->Friend1Button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);
			// 
			// textbox_server_ip
			// 
			this->textbox_server_ip->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
																								 | System::Windows::Forms::AnchorStyles::Right));
			this->textbox_server_ip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
																				  static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_server_ip->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_server_ip->ForeColor = System::Drawing::Color::White;
			this->textbox_server_ip->Location = System::Drawing::Point(911, 703);
			this->textbox_server_ip->Name = L"textbox_server_ip";
			this->textbox_server_ip->Size = System::Drawing::Size(105, 18);
			this->textbox_server_ip->TabIndex = 2;
			this->textbox_server_ip->Text = L"127.0.0.1";
			this->textbox_server_ip->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(839, 704);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Service IP:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1022, 703);
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
			this->textbox_server_port->Location = System::Drawing::Point(1115, 702);
			this->textbox_server_port->Name = L"textbox_server_port";
			this->textbox_server_port->Size = System::Drawing::Size(59, 18);
			this->textbox_server_port->TabIndex = 5;
			this->textbox_server_port->Text = L"443";
			this->textbox_server_port->TextChanged += gcnew System::EventHandler(this, &MainForm::textbox_server_port_TextChanged);
			// 
			// textbox_new_friend_name
			// 
			this->textbox_new_friend_name->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textbox_new_friend_name->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
																						static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_new_friend_name->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_new_friend_name->ForeColor = System::Drawing::Color::White;
			this->textbox_new_friend_name->Location = System::Drawing::Point(386, 703);
			this->textbox_new_friend_name->Name = L"textbox_new_friend_name";
			this->textbox_new_friend_name->Size = System::Drawing::Size(105, 18);
			this->textbox_new_friend_name->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(269, 703);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"New friend name:";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(497, 704);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"New room name:";
			this->label4->Click += gcnew System::EventHandler(this, &MainForm::label4_Click);
			// 
			// textbox_new_room_name
			// 
			this->textbox_new_room_name->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textbox_new_room_name->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
																					  static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->textbox_new_room_name->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textbox_new_room_name->ForeColor = System::Drawing::Color::White;
			this->textbox_new_room_name->Location = System::Drawing::Point(612, 703);
			this->textbox_new_room_name->Name = L"textbox_new_room_name";
			this->textbox_new_room_name->Size = System::Drawing::Size(105, 18);
			this->textbox_new_room_name->TabIndex = 9;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
															   static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->ClientSize = System::Drawing::Size(1208, 725);
			this->Controls->Add(this->textbox_new_room_name);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textbox_server_port);
			this->Controls->Add(this->textbox_new_friend_name);
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
			std::cout << "Sent: " << "send_msg " + *user_name + " " + ManagedStringToStdString(ChatTextBox->Text) << " " << *server_ip << " " << server_port << '\n';

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

		CopyListBoxItems(listboxes[selected_id], ChatListBox);


		CharGroupBox->Text = (((Button^)sender)->Text);

		//ChatListBox = listboxes[selected_new_id];
	}


	public: System::Void NewFriendButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (textbox_new_friend_name->Text == "")
		{
			return;
		}
		//String^ new_frined_name = gcnew String("Room" + next_free_id);
		String^ new_frined_name = gcnew String(textbox_new_friend_name->Text);
		textbox_new_friend_name->Clear();

		Button^ new_button = gcnew Button();


		/*new_button->Dock = System::Windows::Forms::DockStyle::Left;
		new_button->Location = System::Drawing::Point(3, 3);
		new_button->Name = new_frined_name;
		new_button->Size = System::Drawing::Size(140, 30);
		new_button->TabIndex = 0;
		new_button->Text = new_frined_name;
		new_button->UseVisualStyleBackColor = true;
		new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);*/


		new_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),																  static_cast<System::Int32>(static_cast<System::Byte>(50)));
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

	public: void new_friend(unsigned long long new_friend_id)
	{
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
		*server_ip = sf::IpAddress(ManagedStringToStdString(textbox_server_ip->Text).c_str());
		server_connection = false;
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void textbox_server_port_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		server_port = std::stoi(ManagedStringToStdString(textbox_server_port->Text).c_str());
		server_connection = false;
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void JoinRoomButton_Click(System::Object^ sender, System::EventArgs^ e)
	{//String^ new_frined_name = gcnew String("Room" + next_free_id);
		if (textbox_new_room_name->Text == "")
		{
			return;
		}

		String^ new_room_name = gcnew String(textbox_new_room_name->Text);
		textbox_new_room_name->Clear();

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

		server->send
		(
			"room_join " + *user_name + " " + ManagedStringToStdString(new_room_name),
			*server_ip,
			server_port
		);

		//Button^ new_button = gcnew Button();


		///*new_button->Dock = System::Windows::Forms::DockStyle::Left;
		//new_button->Location = System::Drawing::Point(3, 3);
		//new_button->Name = new_frined_name;
		//new_button->Size = System::Drawing::Size(140, 30);
		//new_button->TabIndex = 0;
		//new_button->Text = new_frined_name;
		//new_button->UseVisualStyleBackColor = true;
		//new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);*/


		//new_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
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
	}
};

}
