#pragma once
#include <iostream>
#include <string>




class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0){ }
	HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(0){ }
	HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = nullptr; i = 0; }
	//ex13_8
	//ex13_22
	//HasPtr &operator = (const HasPtr &p);
	HasPtr &operator= (HasPtr);
	HasPtr &operator= (HasPtr &&p);
	//ex13_11
	~HasPtr() { delete ps; }
private:
	std::string *ps;
	int i;
};