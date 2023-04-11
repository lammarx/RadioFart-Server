#include "Server.h"

Server::Server()
{
	systemLog.announceServerStarted();
	systemLog.drawAsciiArt();

	if (socket.bind(sf::Socket::AnyPort) != sf::Socket::Done)
	{
		systemLog.error("Socket binding error.");
		exit(1);
	}

}

void Server::run()
{
	while (running)
	{

	}
}

void Server::readConfig()
{
	std::string line;

	config.open("config.txt");
	while (std::getline(config, line))
	{
		ip = line;
	}
	config.close();
}