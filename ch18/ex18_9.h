#pragma once
#include <iostream>
#include <string>


class out_of_stock : public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s) : std::runtime_error(s){}
};


class isbn_mismatch : public std::logic_error {
public:
	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) : std::logic_error(s), 
		left(lhs), right(rhs){}
	const std::string left, right;
};