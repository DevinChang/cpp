#include <iostream>
#include <vector>
#include <string>
#include "ex9_51.h"


Data::Data(const std::string &s){
	//January 1, 1990; Jan 1 1900; 1/1/1900
	int type, tag = 0;
	if (s.find_first_of('/') != std::string::npos)
		type = 1;
	else if (s.find_first_of(',') >= 4)
		type = 2;
	else if (s.find_first_of(' ') >= 3 && s.find_first_of(' ') != std::string::npos){
		type = 2;
		tag = 1;
	}

	switch (type){
	case 1:
		day = std::stoi(s.substr(0, s.find_first_of('/')));
		month = std::stoi(s.substr(s.find_first_of('/') + 1, s.find_last_of('/') - s.find_first_of('/')));
		year = std::stoi(s.substr(s.find_last_of('/') + 1, 4));
		break;
	case 2:
		if (s.find("Jan") < s.size()) month = 1;
		if (s.find("Feb") < s.size()) month = 2;
		if (s.find("Mar") < s.size()) month = 3;
		if (s.find("Apr") < s.size()) month = 4;
		if (s.find("May") < s.size()) month = 5;
		if (s.find("Jun") < s.size()) month = 6;
		if (s.find("Jul") < s.size()) month = 7;
		if (s.find("Aug") < s.size()) month = 8;
		if (s.find("Sep") < s.size()) month = 9;
		if (s.find("Oct") < s.size()) month = 10;
		if (s.find("Nov") < s.size()) month = 11;
		if (s.find("Dec") < s.size()) month = 12;

		char c;
		if (tag == 0)
			c = ',';
		else if (tag == 1)
			c = ' ';

		year = std::stoi(s.substr(s.find_last_of(' ') + 1, 4));
		day = std::stoi(s.substr(s.find_first_of("0123456789"), s.find_last_of(c) - s.find_first_of("0123456789")));
		break;
	}

}

int main(){
	std::vector<std::string> iv{ "1", "2", "3", "4", "5" };
	int sum = 0;
	for (auto p : iv){
		sum += std::stoi(p);
	}
	std::cout << sum << std::endl;

	Data d("May 2 1900");
	d.print();
	system("pause");
	return 0;
}