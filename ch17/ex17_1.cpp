#include <iostream>
#include <tuple>
#include <string>
#include <vector>



int main1() {
	//ex17_1
	std::tuple<int, int, int> it(10, 20, 30);
	std::tuple<int, int, int> t2{ 30, 40, 50 };

	//ex17_2
	std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> threet;


	system("pause");
	return 0;
}