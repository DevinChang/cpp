#include <iostream>
#include <regex>

bool valid(const std::smatch &m) {
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}


int main() {
	//ex17_15
	std::cout << "ex17_15:" << std::endl << "\t";
	std::string pattern("[c^]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);
	std::smatch results;
	std::string test_str = "receipt freind theif receive";
	if (std::regex_search(test_str, results, r))
		std::cout << results.str() << std::endl;

	//ex17_14
	std::cout << "ex17_14: " << std::endl << "\t";
	try {
		std::regex r("[[:alpha]]+\\.(cpp|cxx|cc)$", std::regex::icase);
	}
	catch (std::regex_error e) {
		std::cout << e.what() << "\n\tcode: " << e.code() << std::endl;
	}

	//ex17_17
	std::cout << "ex17_17: " << std::endl << "\t";
	for (std::sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
		it != end_it; ++it) {
		std::cout << it->str() << std::endl << "\t";
	}

	//ex17_19
	std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])(\\d{4})";
	std::regex ir(phone);
	std::smatch m;
	std::string str;
	while (std::getline(std::cin, str)) {
		for (std::sregex_iterator it(str.begin(), str.end(), ir), end_it;
			it != end_it; ++it) {
			if (valid(*it))
				std::cout << "valid: " << it->str() << std::endl;
			else
				std::cout << "not valid: " << it->str() << std::endl;
		}
	}
	system("pause");
	return 0;
}