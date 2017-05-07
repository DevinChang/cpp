#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>




int main2() {
	std::vector<int> vec{ 1, 11, 111, 2, 22, 222, 2222, 3, 33, 333 };
	int count = std::count_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 1024));
	std::cout << count << std::endl;
	
	std::vector <std::string> svec{ "pooh", "pooh", "pooh", "devin", "chang", "gogog", };
	auto it = std::find_if(svec.begin(), svec.end(), std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh"));
	std::cout << *it << std::endl;

	std::transform(vec.begin(), vec.end(), vec.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1, 2));
	for (auto p : vec)
		std::cout << p << std::endl;

	std::cout << "ex14_43 " << std::endl;
	std::vector<int> iv{  1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::modulus<int> mod;
	int input;
	std::cin >> input;
	auto predicator = [&](int i) { return 0 == mod(input, i); };
	//auto is_divisble = std::any_of(vec.begin(), vec.end(), predicator);
	int bcount = std::count_if(iv.begin(), iv.end(), predicator);
	//int bcount = std::count_if(iv.begin(), iv.end(), std::bind(std::modulus<int>(), std::placeholders::_1, input));
	std::cout << bcount << std::endl;
	system("pause");
	return 0;
}