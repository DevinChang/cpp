#pragma once

#include <iostream>
#include <string>



class base {
public:
	std::string name() { return basename; }
	virtual void print(std::ostream &os) { os << basename; }
private:
	std::string basename;
};


class derived : public base {
public:
	//fixed: base::print()!
	void print(std::ostream &os) { base::print(os); os << " " << i; }
private:
	int i;
};