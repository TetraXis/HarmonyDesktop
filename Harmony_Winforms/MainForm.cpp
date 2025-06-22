#include "MainForm.h"
#include "NewFriendForm.h"

Server* server = nullptr;
bool server_connection = false;

sf::IpAddress* server_ip = new sf::IpAddress("25.30.102.125");


unsigned short local_port = 0;
unsigned short server_port = 0;


extern std::string* user_name = new std::string();
extern size_t user_hash = 0;

//
//std::unordered_map<std::wstring, bool(*)(const std::vector<std::wstring>&, std::wostream*)> harmony::terminal::commands =
//{
//	{
//		L"ping",
//		ping
//	},
//	{
//		L"add_friend",
//		add_friend
//	},
//	{
//		L"send_msg",
//		send_msg
//	},
//	{
//		L"EXIT",
//		EXIT
//	},
//};
//
//bool ping(const std::vector<std::wstring>& args, std::wostream* out)
//{
//	server->send("ping", *server_ip, 11111);
//	return true;
//}
//
//bool add_friend(const std::vector<std::wstring>& args, std::wostream* out)
//{
//	return true;
//}
//
//bool send_msg(const std::vector<std::wstring>& args, std::wostream* out)
//{
//	if (args.size() < 1)
//	{
//		(*out) << "terminal> ERROR: Too few arguments in \"send_msg\" call.\n";
//	}
//
//	unsigned int id = std::stoi(args[0]);
//
//	if (id >= server->pendnig_msgs.size())
//	{
//		server->pendnig_msgs.resize(id + 1);
//	}
//
//	for (size_t i = 1; i < args.size(); i++)
//	{
//		server->pendnig_msgs[id].push_back(wstring_to_string(args[i]));
//	}
//	return true;
//}
//
//bool EXIT(const std::vector<std::wstring>& args, std::wostream* out)
//{
//	server->running = false;
//	return true;
//}

System::Void HarmonyWinforms::MainForm::NewFriendButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewFriendForm^ new_friend_form = gcnew NewFriendForm();

	new_friend_form->main_form_ref = this;

	new_friend_form->ShowDialog();
}

void HarmonyWinforms::MainForm::new_friend(String^ name, String^ ip, String^ port)
{

	std::cout << "new friend name, ip, port\n";

	sf::IpAddress ip_ = sf::IpAddress(ManagedStringToStdString(ip).c_str());
	unsigned short port_ = std::stoi(ManagedStringToStdString(port));

	Button^ new_button = gcnew Button();

	new_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),static_cast<System::Int32>(static_cast<System::Byte>(50)),																 static_cast<System::Int32>(static_cast<System::Byte>(50)));
	new_button->Dock = System::Windows::Forms::DockStyle::Left;
	new_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	new_button->Location = System::Drawing::Point(4, 3);
	new_button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
	new_button->Name = name;
	new_button->Size = System::Drawing::Size(159, 30);
	new_button->TabIndex = 0;
	new_button->Text = name;
	new_button->UseVisualStyleBackColor = false;
	new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);

	FriendsFlowLayoutPanel->Controls->Add(new_button);

	listboxes->Add(gcnew ListBox());
	friend_names->Add(name);
	friends_ips->Add(gcnew ip_info{ new sf::IpAddress(ip_), port_ });
	id_dict[name] = next_free_id;

	while (id_dict->ContainsValue(next_free_id))
	{
		++next_free_id; 
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
}

System::Void HarmonyWinforms::MainForm::JoinRoomButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	
	NewFriendForm^ new_friend_form = gcnew NewFriendForm();

	new_friend_form->main_form_ref = this;

	new_friend_form->is_room = true;
	new_friend_form->label4->Text = "Room name:";
	new_friend_form->button_add_friend->Text = "Join room";

	new_friend_form->ShowDialog();
	
	//String^ new_frined_name = gcnew String("Room" + next_free_id);
	/*if (textbox_new_room_name->Text == "")
	{
		return;
	}

	String^ new_room_name = gcnew String(textbox_new_room_name->Text);
	textbox_new_room_name->Clear();

	*/

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


void HarmonyWinforms::MainForm::new_room(String^ name, String^ ip, String^ port)
{
	sf::IpAddress ip_ = sf::IpAddress(ManagedStringToStdString(ip).c_str());
	unsigned short port_ = std::stoi(ManagedStringToStdString(port));

	Button^ new_button = gcnew Button();

	new_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
	new_button->Dock = System::Windows::Forms::DockStyle::Left;
	new_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	new_button->Location = System::Drawing::Point(4, 3);
	new_button->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
	new_button->Name = name;
	new_button->Size = System::Drawing::Size(159, 30);
	new_button->TabIndex = 0;
	new_button->Text = name;
	new_button->UseVisualStyleBackColor = false;
	new_button->Click += gcnew System::EventHandler(this, &MainForm::Friend1Button_Click);


	/*if (!server_connection)
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
	}*/


	server->send
	(
		"server_join " + *user_name + " " + std::to_string(local_port),
		*server_ip,
		server_port
	);

	Sleep(20);

	if (!server_connection)
	{
		server->send
		(
			"server_join " + *user_name + " " + std::to_string(local_port),
			*server_ip,
			server_port
		);

		Sleep(20);
	}

	server->send
	(
		"room_join " + *user_name + " " + ManagedStringToStdString(name),
		*server_ip,
		server_port
	);

	//FriendsFlowLayoutPanel->Controls->Add(new_button);
	flowLayoutPanel1->Controls->Add(new_button);

	listboxes->Add(gcnew ListBox());
	friend_names->Add(name);
	friends_ips->Add(gcnew ip_info{ new sf::IpAddress(ip_), port_ });
	id_dict[name] = next_free_id;

	while (id_dict->ContainsValue(next_free_id))
	{
		++next_free_id;
	}
}