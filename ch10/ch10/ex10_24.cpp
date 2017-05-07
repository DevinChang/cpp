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

	//ռλ����λ��_1,_2���Ǹ��ݰ󶨵ĺ����Ĳ���λ�ã�����������ö���Ĳ���λ�á�exm: p356.
	//����������˼�ǣ���vec�е�Ԫ�ش���check_size�ĵڶ��������У���vec�е�Ԫ���൱�ڵ��ö���ĵ�һ������.
	auto wc = std::find_if(vec.begin(), vec.end(), std::bind(check_size1, str, _1));

	if (wc != vec.end())
		std::cout << *wc << std::endl;
	else
		std::cout << "no data!" << std::endl;
	system("pause");
	return 0;
}