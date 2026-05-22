#pragma once
#include <iostream>
#include <string>

inline void Log(const std::string& out, int code) {
	if (code == 0)      std::cout << "[ ERR ] " << out << std::endl;
	else if (code == 1) std::cout << "[ OK ] " << out << std::endl;
	else if (code == 2) std::cout << "[ WAIT ] " << out << std::endl;
}

inline std::string rline() {
	std::string line;
	std::getline(std::cin, line);
	return line;
}
