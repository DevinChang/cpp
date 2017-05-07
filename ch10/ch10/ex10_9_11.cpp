#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


bool isShorter(const std::string &s1, const std::string &s2){
	return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words){
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}


int main4(){
	std::vector<std::string> vec{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	elimDups(vec);
	std::stable_sort(vec.begin(), vec.end(), isShorter);
	//此处使用&，因为无须拷贝字符串
	for (auto &p : vec)
		std::cout << p << std::endl;

	system("pause");
	return 0;
}