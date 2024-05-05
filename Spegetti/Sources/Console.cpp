#include <iostream>

void print(std::string text) {

	std::cout << text << std::endl;

}

void warn(std::string text) {

	std::cout << "\x1B[33m" << "WARN : " << text << "\033[0m\t\t" << std::endl;

}

void error(std::string text) {

	std::cout << "\x1B[31m" << "ERROR : " << text << "\033[0m\t\t" << std::endl;

}