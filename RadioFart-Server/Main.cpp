#include "Server.h"

int main()
{
	Server server;
	server.connectClient();
	return server.end();
}