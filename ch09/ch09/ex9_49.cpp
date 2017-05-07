#include <iostream>
#include <fstream>
#include <string>
#include <vector>



int main19(){
	std::fstream ifile("letter.txt");
	std::string letter("acemnorsuvwxz");
	std::string buf;
	std::string maxstr;
	int max = 0, len = 0;
	while (ifile >> buf){
		if (buf.find_first_not_of(letter) == std::string::npos){
			len = buf.size();
			if (len > max){
				max = len;
				maxstr = buf;
			}
		}	
	}
	std::cout << "The lengest string is: " << maxstr << std::endl;
	system("pause");
	return 0;
}