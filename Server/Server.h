#pragma once

#include <fstream>
#include <iostream>
#include <map>

#include "SFML/Network.hpp"
#include <Windows.h> // do not change the order of includes

//#include "MainForm.h"

// remove later

extern sf::IpAddress server_ip;
extern unsigned short server_port;

struct Server
{
private:
	HANDLE receiveThread;
public:
	bool running = false;
	bool connected = false;
	unsigned long long auth_key = 0;
	unsigned short listenPort{};
	sf::UdpSocket receiveSocket{}, sendSocket{};
	// they are spread along the rooms
	//std::vector<std::vector<std::string>> pendnig_msgs{};
						  // sender    / msg
	std::vector<std::pair<std::string, std::string>> pendnig_msgs{};
	std::map<std::string, std::pair<sf::IpAddress, unsigned short>> map_ip_addr{};
	std::map<std::string, std::vector<std::pair<sf::IpAddress, unsigned short>>> map_rooms{};
public:
	Server();
	void start(unsigned short LISTEN_PORT);
	void send(long long ROOM_ID, long long CLIENT_ID, const std::string& MESSAGE);
	void send(const std::string& message, sf::IpAddress address, unsigned short port);
	void stop();
	~Server();
};

extern Server* global_server;