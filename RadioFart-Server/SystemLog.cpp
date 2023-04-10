#include "SystemLog.h"

void SystemLog::announceServerStarted()
{
	systemOutput();
	std::cout << termcolor::green << "Server started." << termcolor::reset << std::endl;
}

void SystemLog::announceClientConnected()
{
	systemOutput();
	std::cout << termcolor::green << "Client connected." << termcolor::reset << std::endl;
}

void SystemLog::error(const char* text, int result)
{
	if (result != 0)
	{
		systemOutput();
		std::cout << termcolor::red << text << result << termcolor::reset << std::endl;
		WSACleanup();
		exit(1);
	}
}

void SystemLog::error(
	const char* text,
	SOCKET socket,
	ADDRINFO* addrResult,
	bool invalidate
)
{
	if (socket == INVALID_SOCKET)
	{
		systemOutput();
		std::cout << text << std::endl;
		freeaddrinfo(addrResult);
		WSACleanup();
		exit(1);
	}
}

void SystemLog::error(
	const char* text,
	SOCKET socket,
	const int result,
	ADDRINFO* addrResult,
	const bool invalidate
)
{
	if (result == SOCKET_ERROR)
	{
		systemOutput();
		std::cout << text << std::endl;
		closesocket(socket);
		if (invalidate) socket = INVALID_SOCKET;
		freeaddrinfo(addrResult);
		WSACleanup();
		exit(1);
	}
}

void SystemLog::drawAsciiArt()
{
	std::ifstream asciiArt("asciiArt.txt");
	std::string line;
	while (std::getline(asciiArt, line))
	{
		std::cout << line << std::endl;
	}
	asciiArt.close();
}

void SystemLog::systemOutput()
{
	std::cout << "[" << termcolor::cyan << "System" << termcolor::reset << "]: ";
}