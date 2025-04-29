#include "terminal.h"
#include "Server.h"

//#include <locale>
//#include <codecvt>
//#include <vcclr.h>



using namespace std;

//std::string wstr_to_str(const std::wstring& wstr)
//{
//	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
//	return converter.to_bytes(wstr);
//}
//
//std::wstring str_to_wstr(const std::string& str)
//{
//	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
//	return converter.from_bytes(str);
//}

// server_join <new_guy> <new_port> <new_ip>
bool server_join(const std::vector<std::wstring>& args, std::wostream* out);
bool ping(const std::vector<std::wstring>& args, std::wostream* out);
bool add_friend(const std::vector<std::wstring>& args, std::wostream* out);
// send_msg <sender> <receiver/room> <msg>
bool send_msg(const std::vector<std::wstring>& args, std::wostream* out);
// receive_msg <room> <sender> <msg>
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
	if (args.size() < 3)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"server_join\" call.\n";
		for (size_t i = 0; i < args.size(); i++)
		{
			std::wcout << args[i] << ' ';
		}
		std::cout << '\n';
		return false;
	}

	std::string name = wstr_to_str(args[0]);
	std::string port = wstr_to_str(args[1]);
	std::string ip = wstr_to_str(args[2]);

	if (global_server->map_ip_addr.count(name) != 0)
	{
		global_server->send
		(
			"server_join",
			global_server->map_ip_addr[name].first,
			global_server->map_ip_addr[name].second
		);
		return true;
	}

	global_server->map_ip_addr[name] =
	{
		sf::IpAddress(ip),
		std::stoi(port)
	};

	global_server->send
	(
		"server_join",
		global_server->map_ip_addr[name].first,
		global_server->map_ip_addr[name].second
	);

	return true;
}

bool ping(const std::vector<std::wstring>& args, std::wostream* out)
{
	global_server->send("ping_back", server_ip, 11111);
	return true;
}

bool add_friend(const std::vector<std::wstring>& args, std::wostream* out)
{
	/*if (args.size() < 1)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"add_friend\" call.\n";
	}

	global_main_form->Invoke(gcnew System::Action<unsigned long long>(global_main_form, &HarmonyWinforms::MainForm::new_friend), std::stoull(args[0]));*/
	return true;
}

// send_msg <sender> <receiver/room> <msg>
bool send_msg(const std::vector<std::wstring>& args, std::wostream* out)
{
	if (args.size() < 3)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"send_msg\" call.\n";
		return false;
	}

	std::string sender = wstr_to_str(args[0]);
	std::string receiver = wstr_to_str(args[1]);
	std::string msg{};

	for (size_t i = 2; i < args.size(); i++)
	{
		msg += wstr_to_str(args[i]);
	}


	if (global_server->map_ip_addr.count(sender) == 0)
	{
		return true;
	}
	

	if (global_server->map_ip_addr.count(receiver) != 0)
	{
		global_server->send
		(
			"receive_msg " + sender + " " + sender + " " + msg,
			global_server->map_ip_addr[receiver].first,
			global_server->map_ip_addr[receiver].second
		);
		global_server->send
		(
			"receive_msg " + receiver + " " + sender + " " + msg,
			global_server->map_ip_addr[sender].first,
			global_server->map_ip_addr[sender].second
		);
		return true;
	}

	if (global_server->map_rooms.count(receiver) != 0)
	{
		for (const auto i : global_server->map_rooms[receiver])
		{
			global_server->send
			(
				"receive_msg " + receiver + " " + sender + " " + msg,
				i.first,
				i.second
			);
		}
		return true;
	}

	//for (size_t i = 1; i < args.size(); i++)
	//{
	//	global_server->pendnig_msgs.emplace_back(wstr_to_str(args[0]), //wstr_to_str(args[i]));
	//}
	return true;
}

// receive_msg <sender> <msg>
bool receive_msg(const std::vector<std::wstring>& args, std::wostream* out)
{
	return true;
}

bool room_join(const std::vector<std::wstring>& args, std::wostream* out)
{
	if (args.size() < 2)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"room_join\" call.\n";
		return false;
	}

	if (global_server->map_ip_addr.count(wstr_to_str(args[0])) == 0)
	{
		return true;
	}

	if (global_server->map_rooms.count(wstr_to_str(args[1])) == 0)
	{
		room_create
		(
			args,
			out
		);

		return true;
	}

	global_server->map_rooms[wstr_to_str(args[1])].emplace_back
	(
		global_server->map_ip_addr[wstr_to_str(args[0])].first,
		global_server->map_ip_addr[wstr_to_str(args[0])].second
	);

	global_server->send
	(
		"room_join " + wstr_to_str(args[1]),
		global_server->map_ip_addr[wstr_to_str(args[0])].first,
		global_server->map_ip_addr[wstr_to_str(args[0])].second
	);

	return true;
}

// room_leave <old_guy> <room_name>
bool room_leave(const std::vector<std::wstring>& args, std::wostream* out)
{
	if (args.size() < 2)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"room_leave\" call.\n";
		return false;
	}

	if (global_server->map_ip_addr.count(wstr_to_str(args[0])) == 0)
	{
		return true;
	}

	return false;
}

// room_create <new_guy> <room_name>
bool room_create(const std::vector<std::wstring>& args, std::wostream* out)
{
	if (args.size() < 2)
	{
		(*out) << "terminal> ERROR: Too few arguments in \"room_create\" call.\n";
		return false;
	}

	if (global_server->map_ip_addr.count(wstr_to_str(args[0])) == 0)
	{
		return true;
	}

	global_server->map_rooms[wstr_to_str(args[1])].emplace_back
	(
		global_server->map_ip_addr[wstr_to_str(args[0])].first,
		global_server->map_ip_addr[wstr_to_str(args[0])].second
	);

	global_server->send
	(
		"room_join " + wstr_to_str(args[1]),
		global_server->map_ip_addr[wstr_to_str(args[0])].first,
		global_server->map_ip_addr[wstr_to_str(args[0])].second
	);

	return false;
}

bool EXIT(const std::vector<std::wstring>& args, std::wostream* out)
{
	global_server->running = false;
	return true;
}
