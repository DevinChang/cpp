#pragma once
#include <iostream>
#include <string>

class chkword {
public:
	chkword(std::size_t l) : len(l){}
	bool operator()(const std::string &str) { return str.length == len; }
private:
	std::size_t len;
};