#include <iostream>
#include <vector>
#include <string>
#include <algorithm>





int main9(){
	std::vector<std::string> words{ "abc", "b", "icandoall", "unbelieve", "ca", "DevinChang", "fly", "time", "moneygo", "BangBang" };
	auto count = std::count_if(words.begin(), words.end(), [](const std::string &s){return s.size() >= 6; });
	std::cout << count << std::endl;
	system("pause");
	return 0;
}