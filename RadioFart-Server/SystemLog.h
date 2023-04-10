#pragma once
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <fstream>
#include <string>
#include <D:\libraries\termcolor-master\include\termcolor\termcolor.hpp>
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <conio.h>
#include <audiere.h>

using namespace audiere;

class SystemLog
{
public:
	void announceServerStarted();
	void announceClientConnected();
	void error(const char* text, int result = 0);
	void error(
		const char* text,
		SOCKET socket,
		ADDRINFO* addrResult,
		bool invalidate
	);
	void error(
		const char* text,
		const SOCKET socket,
		const int result,
		ADDRINFO* addrResult,
		const bool invalidate
	);
	void drawAsciiArt();
private:
	void systemOutput();
};
