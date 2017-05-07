#include <iostream>
#include <sstream>
#include <string>


std::istream &func1(std::istream &is){
	std::string str;
	while (is >> str){
		std::cout << str << std::endl;
	}
	is.clear();
	return is;
}

int main1(int argc, char ** argv){
	
	//func1(std::cin);
	
	//8_9 print istringstream obj
	std::string str = "i can do all things.";
	std::istringstream s(str);
	
	func1(s);

	system("pause");
	return 0;
}
