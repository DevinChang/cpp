#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

struct PersonInfo{
	std::string name;
	std::vector<std::string> phones;
};

bool valid(const std::string &s){
	return isdigit(s[0]);
}

std::string format(const std::string &str){
	return str.substr(0, 3) + "-" + str.substr(3, 3) + str.substr(6);
}

int main(int argc, char **argv){
	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record;
	std::string file("2.txt");
	std::fstream fs(file);
	//note: double ctrl+z instruction could suspend while(cin).
	while (std::getline(fs, line)){
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	for (const auto &entry : people){
		std::ostringstream formateed, badNums;
		for (const auto &nums : entry.phones){
			if (!valid(nums))
				badNums << " " << nums;
			else
				formateed << " " << format(nums);
		}
		if (badNums.str().empty())
			std::cout << entry.name << " " << formateed.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << std::endl;
	}
	system("pause");
	return 0;
}