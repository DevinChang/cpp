#include "ex12_30.h"


int main11() {

	std::ifstream infile("file.txt");
	TextQuery tq(infile);
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;
	}

	system("pause");
	return 0;
}