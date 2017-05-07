#pragma once
#include <iostream>



class IsEqual {
public:
	IsEqual(int v) : val(v){}
	bool operator()(int i) { return val == i; }
private:
	int val;
};