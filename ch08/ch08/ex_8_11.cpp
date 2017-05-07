#include <sstream>
#include <vector>
#include <string>
#include <iostream>

struct PersonInfo{
	std::string name;
	std::vector<std::string> phones;
};

int main5(){
	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record;
	//note: double ctrl+z instruction could suspend while(cin).
	while (std::getline(std::cin, line)){
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	//question: p and ph shoule be referense?
	for (auto &p : people){
		std::cout << p.name << " ";
		for (auto &ph : p.phones){
			std::cout << ph << " ";
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}