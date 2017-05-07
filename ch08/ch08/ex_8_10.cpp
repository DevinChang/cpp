#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main4(int argc, char **argv){
	std::vector<std::string> vec;
	std::string ifile("1.txt");
	std::fstream fs(ifile);
	if (fs){
		std::string buf;
		while (std::getline(fs, buf)){
			std::istringstream word(buf);
			std::string tmp;
			while (word >> tmp)
				std::cout << tmp << std::endl;
			vec.push_back(buf);
		}
	}

	system("pause");
	return 0;
}