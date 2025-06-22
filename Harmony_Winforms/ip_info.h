#pragma once

#include "SFML/Network.hpp"

ref class ip_info
{
public:
	sf::IpAddress* ip = nullptr;
	unsigned short port{};

	ip_info(sf::IpAddress* new_ip, unsigned short new_port)
	{
		ip = new_ip;
		port = new_port;
	}

	~ip_info()
	{
		delete ip;
	}
};