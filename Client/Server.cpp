#include "Server.h"

#include "terminal.h"

#include <string>


sf::IpAddress video_server_ip("25.41.207.37");
unsigned short video_server_port(50210);

std::vector <std::string> test = {
	"CREATE_ROOM\n60711",
	"CONNECT_USER\n60711\n1\n1",
	"CONNECT_USER\n60712\n1\n2",
	"CONNECT_TO_STREAM\n1\n1\n2",
	"STREAM_PACKET\n1\n2\nstream_data1",
	"DISCONNECT_FROM_STREAM\n1\n1\n2",
	"STREAM_PACKET\n1\n2\nstream_data2",
	"DISCONNECT_USER\n1\n2",
	"DISCONNECT_USER\n1\n1",
	"CLOSE_ROOM\n60711\n1"
};

constexpr int basicDataSize = 65000;

void resetLog()
{
	std::ofstream fout("log.txt");
	fout << "=== RESTART HARMONY DESKTOP ===\n";
	fout.close();
}

void logS(const std::string& S)
{
	std::ofstream fout("log.txt", std::ios_base::app);
	fout << S << "\n";
	std::cout << S << "\n";
}

std::vector <std::string> decodeData(char* INPUT, int SIZE)
{
	std::vector <std::string> data;
	std::string tmp = "";
	int pos = 0;
	data.push_back(tmp);
	for (int i = 0; i < SIZE; i++)
	{
		if (INPUT[i] == '\n')
		{
			data.push_back(tmp);
			pos++;
			continue;
		}
		else
		{
			if (INPUT[i] == '\\')
			{
				break;
			}
			data[pos] += INPUT[i];
		}
	}
	return data;
}

void server_test(sf::IpAddress adress = video_server_ip, unsigned short port = video_server_port)
{
	sf::UdpSocket testSocket;
	for (int i = 0; i < test.size(); i++)
		testSocket.send(test[i].c_str(), test[i].size(), video_server_ip, video_server_port);
}

void ServerReceiveProc(Server* server)
{
	logS("Server receive thread started");
	char receivedData[basicDataSize];
	sf::IpAddress receivedIp;
	unsigned short receivedPort;
	std::size_t receivedSize;
	std::vector <std::string> decodedData;
	while (server->running)
	{
		if (server->receiveSocket.receive(receivedData, basicDataSize, receivedSize, receivedIp, receivedPort) != sf::Socket::Done)
		{
			logS("Server receive thread error: cannot receive data");
			return;
		}
		else
		{

			harmony::global_terminal.execute(std::wstring(receivedData, receivedData + receivedSize));
			//decodedData = decodeData(receivedData, receivedSize);
			//logS("Server receive thread receive data: "
			//	+ std::to_string(decodedData.size()) + " elements");
			//for (int i = 0; i < decodedData.size(); i++)
			//	logS(std::to_string(i) + ": [" + decodedData[i] + "]");
			//if (receivedIp == sf::IpAddress("127.0.0.1") && decodedData[0] == "EXIT")
			//	break;

			//if (decodedData[0] == "TEST")
			//{
			//	server_test();
			//}

			//else if (decodedData[0] == "CONNECTION_ACCEPTED")
			//{
			//	server->connected = true;
			//}

			//else if (decodedData[0] == "ACTIVE_ROOMS_PRESENT")
			//{
			//	/*unsigned long long rooms_amount = std::stoi(decodedData[1]);

			//	for (const auto& elem : video_server_innards->views)
			//	{
			//		elem->free_memory();
			//	}

			//	for (size_t i = 0; i < rooms_amount; i++)
			//	{
			//		video_server_innards->views.push_back(new text_button(0, 0, /100,/ 80, 2, "Room #"+ decodedData[2 + i]));
			//	}*/
			//}

			//else if (decodedData[0] == "MSG")
			//{
			//	unsigned int id = std::stoi(decodedData[1]);

			//	if (id >= server->pendnig_msgs.size())
			//	{
			//		server->pendnig_msgs.resize(id);
			//	}

			//	for (size_t i = 1; i < decodedData.size(); i++)
			//	{
			//		server->pendnig_msgs[id].push_back(decodedData[i]);
			//	}
			//}
		}
	}
	logS("Server receive thread stopped");
	// connect / disconnect users on stream if disconnect
	// notify users about stream start / end
}

Server::Server()
{
	receiveThread = NULL;
}

void Server::start(unsigned short LISTEN_PORT)
{
	logS("Server starting...");
	if (running)
	{
		logS("Server error: already started");
		return;
	}
	listenPort = LISTEN_PORT;
	if (receiveSocket.bind(listenPort) != sf::Socket::Done)
	{
		logS("Server error: cannot bind socket");
		return;
	}
	listenPort = receiveSocket.getLocalPort();
	receiveThread = CreateThread((LPSECURITY_ATTRIBUTES)NULL, 0, (LPTHREAD_START_ROUTINE)ServerReceiveProc, this, 0, NULL);
	running = true;
	Sleep(100);
	logS("Server started");
}

void Server::send(long long ROOM_ID, long long CLIENT_ID, const std::string& MESSAGE)
{
	/* MESSAGE += '\\';
	 if (rooms.find(ROOM_ID) != rooms.end())
	 {
		 Room* room = rooms[ROOM_ID];
		 if (room->users.find(CLIENT_ID) != room->users.end())
		 {
			 User* user = room->users[CLIENT_ID];
			 sendSocket.send(MESSAGE.c_str(), MESSAGE.size(), user->sessionIp, user->sessionPort);
		 }
		 else
			 logS("Server error: not exist client " + intToString(CLIENT_ID));
	 }
	 else
		 logS("Server error: not exist room " + intToString(ROOM_ID));*/
}

void Server::send(const std::string& message, sf::IpAddress address, unsigned short port)
{
	sendSocket.send(message.c_str(), message.size(), address, port);
}

void Server::stop()
{
	logS("Server stopping...");
	if (!running)
	{
		logS("Server error: already stopped");
		return;
	}
	running = false;
	sf::UdpSocket exitSocket{};
	exitSocket.send("EXIT", 4, sf::IpAddress("127.0.0.1"), listenPort);
	WaitForSingleObject(receiveThread, INFINITE);
	CloseHandle(receiveThread);
	receiveThread = NULL;
	//Room* room;
	//for (auto roomIt : rooms)
	//{
	//    room = roomIt.second;
	//    /*for (auto userIt : room->users)
	//    {
	//        send(roomIt.first, userIt.first, "DISCONNECT");
	//    }*/
	//    roomIt.second->users.clear();
	//    delete roomIt.second;
	//}
	//rooms.clear();
	logS("Server stopped");
}

Server::~Server()
{
	stop();
}