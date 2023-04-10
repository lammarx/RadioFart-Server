#include "Server.h"

Server::Server()
{
	sysLog.announceServerStarted();
	sysLog.drawAsciiArt();
	WSADATA wsaData;
	ADDRINFO hints;
	clientSocket = INVALID_SOCKET;
	listenSocket = INVALID_SOCKET;
	AudioDevicePtr audioDevice = OpenDevice();
	if (!audioDevice) sysLog.soundError("Audio Device creating failed.");
	currentSound = OpenSound(audioDevice, "sound.wav", true);

	// CHECK
	clientResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	sysLog.error("WSAStartup failed, result = ", clientResult);

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// CHECK
	clientResult = getaddrinfo(NULL, "666", & hints, & addrResult);
	sysLog.error("getaddrinfo failed, result = ", clientResult);

	// CHECK
	listenSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);
	sysLog.error("Socket creation failed.", listenSocket, addrResult, 0);

	// CHECK
	clientResult = bind(listenSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
	sysLog.error("Binding socket failed.", listenSocket, clientResult, addrResult, 1);
	
	// CHECK
	clientResult = listen(listenSocket, SOMAXCONN);
	sysLog.error("Listening socket failed.", listenSocket, clientResult, addrResult, 0);
	
	// CHECK
	clientSocket = accept(listenSocket, NULL, NULL);
	sysLog.error("Accepting socket failed.", listenSocket, addrResult, 0);
	

	closesocket(listenSocket);
	
}

void Server::connectClient()
{
	do
	{
		ZeroMemory(recvBuffer, 512);
		clientResult = recv(clientSocket, recvBuffer, 512, 0);
		if (clientResult > 0)
		{
			sysLog.announceClientConnected();
			std::cout << "Recieved " << clientResult << "bytes" << std::endl;
			std::cout << "Recieved data: " << recvBuffer << std::endl;
			clientResult = send(clientSocket, sendBuffer, (int)strlen(sendBuffer), 0);
			if (clientResult == SOCKET_ERROR)
			{
				std::cout << "Failed to send data back." << std::endl;
				clear();
			}
		}
		else if (clientResult == 0)
		{
			std::cout << "Connection closing..." << std::endl;
		}
		else
		{
			std::cout << "recv failed with error." << std::endl;
			clear();
		}
	} while (clientResult > 0);

	clientResult = shutdown(clientSocket, SD_SEND);
	sysLog.error("Shutdown client socket failed.", clientSocket, clientResult, addrResult, 0);

	closesocket(clientSocket);
	freeaddrinfo(addrResult);
	WSACleanup();
	exit(0);
}

void Server::clear()
{
	closesocket(clientSocket);
	freeaddrinfo(addrResult);
	WSACleanup();
	exit(1);
}

int Server::end()
{
	return clientResult;
}