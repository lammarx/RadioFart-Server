#pragma once

#include <iostream>
#include <vector>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include "SystemLog.h"

class Server
{
public:
	Server();
	void run();
private:
	bool running = true;

	SystemLog systemLog;
	sf::UdpSocket socket;
	std::ifstream config;
	char data[128];
	std::size_t received;
	sf::IpAddress sender;
	unsigned short senderPort;
	void readConfig();
	sf::IpAddress ip;
};

