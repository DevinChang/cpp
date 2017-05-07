#pragma once
#include <iostream>
#include <string>




class HasPtr2 {
public:
	friend void swap(HasPtr2 &, HasPtr2 &);
	friend bool operator < (const HasPtr2 &, const HasPtr2 &);
	HasPtr2(const std::string &s = std::string()) : ps(new std::string(s)), i(0){ }
	HasPtr2(HasPtr2 &p) : ps(new std::string(*p.ps)), i(p.i){  }
	HasPtr2& operator = (HasPtr2 );
	
	~HasPtr2() { delete ps; }

	
private:
	std::string *ps;
	int i;
	//std::size_t *use;
};