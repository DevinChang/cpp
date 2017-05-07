#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std::placeholders;

bool check_size(const std::string &str, std::string::size_type sz){
	return str.size() > sz;
}


void elimDus1(std::vector<std::string> &words){
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

int main11(){
	std::vector<std::string> words{ "abc", "b", "icandoall", "unbelieve", "ca", "DevinChang", "fly", "time", "moneygo", "BangBang" };

	elimDus1(words);
	std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b)
	{return a.size() < b.size(); });

	auto wc = find_if(words.begin(), words.end(), std::bind(check_size, _1, 6));

	std::for_each(wc, words.end(), [](const std::string &s){ std::cout << s << std::endl; });

	system("pause");
	return 0;
}