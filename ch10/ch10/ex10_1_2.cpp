#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>


int main1(){
	//10_1
	std::vector<int> iv{ 1, 2, 3, 4, 5, 6, 1, 2, 3, 2, 2, 1, 2, 1 };
	int val = 2;
	std::cout << "The value " << val << " exits " << std::count(iv.begin(), iv.end(), val) << " times." << std::endl;
	//10_2
	std::list<std::string> lst{ "a", "bc", "a", "cd", "a", "bc" };
	std::string str = "ac";
	std::cout << str << " exits " << std::count(lst.begin(), lst.end(), str) << std::endl;
	system("pause");
	return 0;
}