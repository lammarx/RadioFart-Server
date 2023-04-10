#pragma once

#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "SystemLog.h"

class Server
{
public:
	Server();
	void connectClient();
	void clear();
	int end();
private:
	SystemLog sysLog;
	int clientResult;
	SOCKET clientSocket;
	SOCKET listenSocket;
	char recvBuffer[512];
	ADDRINFO* addrResult = NULL;
	const char* sendBuffer = "Hello from Serv";
};

