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

void SystemLog::error(const char* text)
{
	systemOutput();
	std::cout << termcolor::red << text << termcolor::reset << std::endl;
	exit(1);
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