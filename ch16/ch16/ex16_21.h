#pragma once
#include <iostream>



class DebugDelete {
public:
	DebugDelete(std::ostream &os = std::cerr) : os(os){}
	template <typename T> void operator() (T *p) const {
		os << "delting" << std::endl; 
		delete p;
	}
private:
	std::ostream &os;
};