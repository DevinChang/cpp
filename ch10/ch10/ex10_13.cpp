#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool len(std::string str){
	return str.size() > 5;
}

int main6(){
	std::vector<std::string> vec{ "abc", "b", "icandoall", "unbelieve", "ca", "DevinChang", "fly", "time", "moneygo", "BangBang" };
	auto pivot = std::partition(vec.begin(), vec.end(), len);
	for (auto it = vec.cbegin(); it != pivot; ++it)
		std::cout << *it << std::endl;
	system("pause");
	return 0;
}