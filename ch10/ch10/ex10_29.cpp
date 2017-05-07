#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>




int main15(){
	std::fstream ifile("1.txt");
	std::istream_iterator<std::string> in(ifile), eof;
	std::vector<std::string> vec;
	while (in != eof)
		vec.push_back(*in++);

	for (auto &p : vec)
		std::cout << p << std::endl;

	system("pause");
	return 0;
}