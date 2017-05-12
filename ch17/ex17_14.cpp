#include <iostream>
#include <regex>




int main() {
	//ex17_15
	std::string pattern("[c^]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);
	std::smatch results;
	std::string test_str = "receipt freind theif receive";
	if (std::regex_search(test_str, results, r))
		std::cout << results.str() << std::endl;

	//ex17_14
	try {
		std::regex r("[[:alpha:]]+\\.(cpp|cxx|cc)$", std::regex::icase);
	}
	catch (std::regex_error e) {
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	}
	system("pause");
	return 0;
}