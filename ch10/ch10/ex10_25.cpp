#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

bool check_size2(const std::string &str, std::string::size_type sz){
	return str.size() > sz;
}

void elimDus2(std::vector<std::string> &words){
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

std::string make_plural2(size_t ctr, const std::string &word, const std::string &ending){
	return (ctr > 1) ? word + ending : word;
}

void biggies2(std::vector<std::string> &words, std::vector<std::string>::size_type sz){
	elimDus2(words);
	std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b)
	{return a.size() < b.size(); });

	auto wc2 = std::partition(words.begin(), words.end(), [sz](const std::string &a){return a.size() >= sz; });

	auto wc = std::partition(words.begin(), words.end(), std::bind(check_size2, _1, 6));


	auto count = wc - words.begin();
	std::cout << count << " " << make_plural2(count, "word", "s") << " of length " << sz << " or longer" << std::endl;

	std::for_each(words.begin(), wc, [](const std::string &s){std::cout << s << " "; });

	std::cout << std::endl;

}


int main13(){

	std::vector<std::string> words{ "abc", "b", "icandoall", "unbelieve", "ca", "DevinChang", "fly", "time", "moneygo", "BangBang" };
	biggies2(words, 6);

	system("pause");
	return 0;
}