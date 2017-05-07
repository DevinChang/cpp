#pragma once
#include<iostream>
#include <string>


class StrLenBetween {
public:
	StrLenBetween(std::size_t il = 1, std::size_t al = 10) : minlen(il), maxlen(al){}
	bool operator() (const std::string &str) { return str.length() >= minlen && str.length() <= maxlen; }
private:
	std::size_t minlen;
	std::size_t maxlen;
};


class StrLenBig {
public:
	StrLenBig(std::size_t n = 10) : len(n) {}
	bool operator() (const std::string &str) { return str.length() > len; }
private:
	std::size_t len;
};