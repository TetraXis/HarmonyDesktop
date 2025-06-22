#include <iostream>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Server.h"

/*
open ports:
88
389
443
135
137
138
139

*/

sf::IpAddress addr = sf::IpAddress("127.0.0.1");
unsigned short port = 443;

int main()
{
	std::string input;

	/*std::cout << "Enter ip: ";
	std::cin >> input;

	addr = sf::IpAddress(input);*/

	std::cout << "Enter port: ";
	std::cin >> input;

	port = std::stoi(input);

	global_server->start(port);
	while (global_server->running)
	{

	}
}