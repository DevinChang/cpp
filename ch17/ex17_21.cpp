#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phone;
};




std::string format(std::string &num) {
	return num;
}

bool valid_phone(const std::smatch &m) {
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main4() {
	std::string line, word;
	std::vector<PersonInfo> people;
	while (std::getline(std::cin, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phone.push_back(word);
		people.push_back(info);
	}
	std::string ph = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])(\\d{4})";
	std::regex ir(ph);
	std::string fmt = "$2.$5.$7";
	for (auto &entry : people) {
		std::ostringstream formatted, badNums;
		for (auto &nums : entry.phone) {
			for (std::sregex_iterator it(nums.begin(), nums.end(), ir), end_it;
				it != end_it; ++it) {
				if (!valid_phone(*it))
					badNums << " " << nums;
				else
					formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty())
			std::cout << entry.name << " " << formatted.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << std::endl;
	}
	
	//ex17_24

	

	system("pause");
	return 0;
}