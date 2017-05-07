#include <iostream>
#include <vector>
#include <string>
#include <new>

std::vector<int> *func1(std::istream &is){
	std::vector<int> *vec = new std::vector<int>;
	int str;
	while (is >> str)
		vec->push_back(str);
	return vec;
}

void print(std::vector<int> *vec){
	for (auto it = vec->begin(); it != vec->end(); ++it)
		std::cout << *it << std::endl;
}




int main2(){
	std::vector<int> *vec = func1(std::cin);
	print(vec);
	delete vec;

	//system("pause");
	return 0;
}