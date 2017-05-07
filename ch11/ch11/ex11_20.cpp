#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>




int main8(){
	std::map<std::string, size_t> word_count;
	std::set<std::string> exclude = { "The", "But", "And", "the", "but", "and" };
	std::string word;
	while (std::cin >> word){
		if (exclude.find(word) == exclude.end()){
			auto ret = word_count.insert({ word, 1 });
			if (!ret.second)
				++ret.first->second;

			//++word_count.insert({ word, 1 }).first->second;

		}	
	}

	for (const auto &p : word_count)
		std::cout << p.first << " occurs " << p.second << ((p.second > 1) ? " the times." : " the time.") << std::endl;
	system("pause");
	return 0;
}