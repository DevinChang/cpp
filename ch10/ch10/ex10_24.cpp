#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

bool check_size1(const std::string &str, std::string::size_type sz){
	return str.size() < sz;
}


int main12(){
	std::vector<int> vec{ 1, 2, 3, 4, 6, 2, 5, 10, 15, 20, 30 };
	std::string str("i can do all things.");

	//占位符的位置_1,_2不是根据绑定的函数的参数位置，而是由其调用对象的参数位置。exm: p356.
	//这条语句的意思是，将vec中的元素传到check_size的第二个参数中，而vec中的元素相当于调用对象的第一个参数.
	auto wc = std::find_if(vec.begin(), vec.end(), std::bind(check_size1, str, _1));

	if (wc != vec.end())
		std::cout << *wc << std::endl;
	else
		std::cout << "no data!" << std::endl;
	system("pause");
	return 0;
}