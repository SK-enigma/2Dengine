#include "Logger.h"
#include <iostream>
#include <chrono>
#include <string>
#include <ctime>



std::vector<LogEntry> Logger::messages;


std::string CurrentDateTimeToString() {
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm localTime;
	localtime_s(&localTime, &now);

	std::string output(30, '\0');
	std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", &localTime);
	output.resize(std::strlen(output.c_str())); // Resize to actual length

	return output;
}




void Logger::Log(const std::string& message) {
	LogEntry logEntry;
	logEntry.type = LOG_INFO;

	logEntry.message = "LOG: [" + CurrentDateTimeToString() + "]: " + message;
	std::cout << "\x1B[32m" << logEntry.message << "\033[0m" << std::endl;
	
	messages.push_back(logEntry);
}

void Logger::Err(const std::string& message) {
	
	LogEntry logEntry;
	logEntry.type = LOG_ERROR;

	logEntry.message = "ERR: [" + CurrentDateTimeToString() + "]: " + message;
	std::cout << "\x1B[91m" << logEntry.message << "\033[0m" << std::endl;

	messages.push_back(logEntry);


}
