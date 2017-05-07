#pragma once
#include <iostream>
#include <string>




class HasPtr1 {
public:
	HasPtr1(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
	HasPtr1(HasPtr1 &p) : ps(p.ps), i(0), use(p.use) { ++*use; }
	HasPtr1& operator = (const HasPtr1 &);
	
	~HasPtr1();
private:
	std::string *ps;
	int i;
	std::size_t *use;
};