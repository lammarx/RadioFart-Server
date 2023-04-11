#pragma once
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <fstream>
#include <string>
#include <D:\libraries\termcolor-master\include\termcolor\termcolor.hpp>

class SystemLog
{
public:
	void announceServerStarted();
	void announceClientConnected();
	void drawAsciiArt();

	void error(const char* text);
private:
	void systemOutput();
};
