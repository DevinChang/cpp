#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>


std::string  &strip(std::string &str){
	for (auto &p : str)
		p = tolower(p);
	str.erase(std::remove_if(str.begin(), str.end(), ispunct));
	return str;
}


int main1(){
	std::cout << "ex11_3: " << std::endl;
	std::map<std::string, size_t> word_count;
	std::string word;
	//ctrl + z, ctrl + z pause.
	while (std::cin >> word)
		++word_count[word];

	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;

	std::cout << "ex11_4: " << std::endl;
	word_count.clear();
	std::cin.clear();
	while (std::cin >> word)
		++word_count[strip(word)];
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;


	system("pause");
	return 0;
}