#pragma once
#include <iostream>



class ITE {
public:
	int operator() (bool b, int i, int t) { if (b) return i; else return t; }
private:

};