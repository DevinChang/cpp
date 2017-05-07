#pragma once

#include <iostream>
#include <string>


class Data{

public:
	Data(const std::string &s);
	void print(){
		std::cout << "Year: " << year << " Month: " << month << " Day: " << day << std::endl;
	}
private:
	unsigned day, month, year;
};


