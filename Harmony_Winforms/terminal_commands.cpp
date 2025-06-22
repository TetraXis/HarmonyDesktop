#include "terminal.h"
#include "MainForm.h"

using namespace HarmonyWinforms;

#include <locale>
#include <codecvt>
#include <vcclr.h>



using namespace std;

std::string wstring_to_string(const std::wstring& wstr)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.to_bytes(wstr);
}

// server_join <new_guy> <new_ip> <new_port>
bool server_join(const std::vector<std::wstring>& args, std::wostream* out);
bool ping(const std::vector<std::wstring>& args, std::wostream* out);
bool add_friend(const std::vector<std::wstring>& args, std::wostream* out);
// send_msg <sender> <receiver/room> <msg>
bool send_msg(const std::vector<std::wstring>& args, std::wostream* out);
// receive_msg <room = "sender"> <sender> <msg>
bool receive_msg(const std::vector<std::wstring>& args, std::wostream* out);
// room_join <new_guy> <room_name>
bool room_join(const std::vector<std::wstring>& args, std::wostream* out);
// room_leave <old_guy> <room_name>
bool room_leave(const std::vector<std::wstring>& args, std::wostream* out);
// room_create <new_guy> <room_name>
bool room_create(const std::vector<std::wstring>& args, std::wostream* out);
bool EXIT(const std::vector<std::wstring>& args, std::wostream* out);

std::unordered_map<std::wstring, bool(*)(const std::vector<std::wstring>&, std::wostream*)> harmony::terminal::commands =
{
	{
		L"ping",
		ping
	},
	{
		L"server_join",
		server_join
	},
	{
		L"add_friend",
		add_friend
	},
	{
		L"room_join",
		room_join
	},
	{
		L"room_leave",
		room_leave
	},
	{
		L"room_create",
		room_create
	},
	{
		L"send_msg",
		send_msg
	},
	{
		L"receive_msg",
		send_msg
	},
	{
		L"EXIT",
		EXIT
	},
};

bool server_join(const std::vector<std::wstring>& args, std::wostream* out)
{
	server_connection = true;
	return true;
}

bool ping(const std::vector<std::wstring>& args, std::wostream* out)
{
	server->send("ping_back", *server_ip, server_port);
	return true;
}

bool add_friend(const std::vector<std::wstring>& args, std::wostream* out)
{
	if (args.size() < 1)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"add_friend\" call.\n";
		return true;
	}

	global_main_form->Invoke(gcnew System::Action<unsigned long long>(global_main_form, &HarmonyWinforms::MainForm::new_friend), std::stoull(args[0]));
	return true;
}

bool send_msg(const std::vector<std::wstring>& args, std::wostream* out)
{
	if (args.size() < 2)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"reveive_msg\" call.\n";
		return true;
	}

	//unsigned int id = std::stoi(args[0]);

	//if (id >= server->pendnig_msgs.size())
	//{
	//	server->pendnig_msgs.resize(id + 1);
	//}

	for (size_t i = 2; i < args.size(); i++)
	{
		server->pendnig_msgs.emplace_back(std::pair<std::string, std::string>{ wstring_to_string(args[0]), wstring_to_string(args[1]) }, wstring_to_string(args[i]));
	}
	return true;
}

bool receive_msg(const std::vector<std::wstring>& args, std::wostream* out)
{
	if (args.size() < 2)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"reveive_msg\" call.\n";
		return true;
	}

	//unsigned int id = std::stoi(args[0]);

	//if (id >= server->pendnig_msgs.size())
	//{
	//	server->pendnig_msgs.resize(id + 1);
	//}

	for (size_t i = 2; i < args.size(); i++)
	{
		server->pendnig_msgs.emplace_back(std::pair<std::string, std::string>{ wstring_to_string(args[0]), wstring_to_string(args[1]) }, wstring_to_string(args[i]));
	}
	return true;
}

bool room_join(const std::vector<std::wstring>& args, std::wostream* out)
{
	return true;

	if (args.size() < 1)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"send_msg\" call.\n";
		return true;
	}


	global_main_form->Invoke
	(
		gcnew System::Action<String^>(global_main_form, &MainForm::new_friend),
				 gcnew String(args[0].c_str())
	);

	return true;
}

bool room_leave(const std::vector<std::wstring>& args, std::wostream* out)
{
	return false;
}

bool room_create(const std::vector<std::wstring>& args, std::wostream* out)
{
	return false;
}

bool EXIT(const std::vector<std::wstring>& args, std::wostream* out)
{
	server->running = false;
	return true;
}
