#pragma once
#include <iostream>
#include <string>
#include <vector>


class PrintString {
public:
	PrintString(std::istream &i = std::cin) : is(i){}
	std::string operator()() const {
		std::string buf;
		while (!std::getline(is, buf))
			buf = " ";
		return buf;
	}
private:
	std::istream &is;
	//std::vector<std::string> vec;
	
};