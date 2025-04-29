#include <iostream>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Server.h"

sf::IpAddress addr = sf::IpAddress("127.0.0.1");
unsigned short port = 443;

int main()
{
	global_server->start(port);
	while (global_server->running)
	{

	}
}