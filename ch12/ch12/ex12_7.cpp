#include <iostream>
#include <vector>
#include <memory>


std::shared_ptr<std::vector<int>> func2(std::istream &is){
	std::shared_ptr<std::vector<int>> vec(std::make_shared<std::vector<int>>());
	int str;
	while (is >> str)
		vec->push_back(str);
	return vec;
}

void print2(std::shared_ptr<std::vector<int>> vec){
	for (auto it = vec->begin(); it != vec->end(); ++it)
		std::cout << *it << std::endl;
}

int main3(){
	print2(func2(std::cin));

	system("pause");
	return 0;
}