#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


void elimDus(std::vector<std::string> &words){
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending){
	return (ctr > 1) ? word + ending : word;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz){
	elimDus(words);
	std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b)
													{return a.size() < b.size(); });

	//10_17
	auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &a)
															{return a.size() >= sz; });

	//10_18 replace find_if of partition. 
	//10_19 use stable_partition
	auto wc2 = std::stable_partition(words.begin(), words.end(), [sz](const std::string &a){return a.size() >= sz; });

	auto count = wc2 - words.begin();
	std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;

	std::for_each(words.begin(), wc2, [](const std::string &s){std::cout << s << " "; });
	
	std::cout << std::endl;
		
}


int main8(){
	std::vector<std::string> words{ "abc", "b", "icandoall", "unbelieve", "ca", "DevinChang", "fly", "time", "moneygo", "BangBang" };
	biggies(words, 4);
	system("pause");
	return 0;
}