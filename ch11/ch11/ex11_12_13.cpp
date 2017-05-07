#include <iostream>
#include <vector>
#include <map>
#include <string>


int main6(){

	//11_12
	std::vector<std::pair<std::string, int>> vec;
	std::string str;
	int i;
	std::pair<std::string, int> p(str, i), p1 = { str, i };
	while (std::cin >> str >> i){
		//vec.push_back(std::pair<std::string, int>(str, i));
		//11_13 use three ways to create the pairs.
		//vec.push_back(std::make_pair(str, i));
		vec.push_back({ str, i });

	}
	for (auto &p : vec)
		std::cout << p.first << " " << p.second << std::endl;


	system("pause");
	return 0;
}