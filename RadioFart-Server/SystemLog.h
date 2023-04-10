#pragma once
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <Windows.h>
#include <D:\libraries\termcolor-master\include\termcolor\termcolor.hpp>
#include <WinSock2.h>
#include <WS2tcpip.h>

class SystemLog
{
public:
	void announceServerStarted();
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
private:
	void systemOutput();
};
