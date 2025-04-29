#include "MainForm.h"

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
