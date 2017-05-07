#pragma once
#include <string>

class Account{
public:
	void cacluate(){ amount += amount * interestRate; }
	static double rate(){ return interestRate; }
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate;
};