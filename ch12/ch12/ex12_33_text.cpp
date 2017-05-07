#include "ex12_33.h"



int main() {
	std::ifstream infile("file.txt");
	TextQuery3 tq(infile);
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