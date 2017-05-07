#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main2(int argc, char **argv){
	std::vector<std::string> vec;
	std::string ifile("1.txt");
	std::fstream in(ifile);
	if (in){
		std::string buf;
		//8_4 read by a line
		//while (std::getline(in, buf))
		
		//8_5 read by a word, use << read a word.
		while (in >> buf){
			vec.push_back(buf);
		}
		
	}
	for (auto i : vec){
		std::cout << i << std::endl;
	}
	system("pause");
	return 0;
}