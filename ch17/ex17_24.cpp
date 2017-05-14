#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>

struct person_info {
	std::string name;
	std::vector<std::string> phone;
};




std::string Format(std::string &num) {
	return num;
}

bool validPhone(const std::smatch &m) {
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main() {
	/*std::string line, word;
	std::vector<person_info> people;
	while (std::getline(std::cin, line)) {
		person_info info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phone.push_back(word);
		people.push_back(info);
	}*/
	std::string ph = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])(\\d{4})";
	std::regex ir(ph);
	std::string fmt = "$2.$5.$7";
	std::string s;
	while (std::getline(std::cin, s)) {
		std::cout << std::regex_replace(s, ir, fmt) << std::endl;
	}

	//ex17_24



	system("pause");
	return 0;
}