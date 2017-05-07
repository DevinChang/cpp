#include <iostream>
#include <vector>

int main8(){
	std::vector<int> vec;
	std::cout << vec.at(0) << std::endl;
	std::cout << vec[0] << std::endl;
	std::cout << vec.front() << std::endl;
	std::cout << *vec.begin() << std::endl;
	system("pause");
	return 0;
}