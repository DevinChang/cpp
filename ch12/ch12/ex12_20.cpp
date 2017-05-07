#include "ex12_19.h"
#include <fstream>


int main7() {
	std::fstream ifile("word.txt");
	std::string str;
	StrBolb bolb;
	while (std::getline(ifile, str)) {
		bolb.push_back(str);
	}
	StrBolbPtr pbeg(bolb.begin()), pend(bolb.end());
	for (; pbeg != pend; pbeg.incr())
		std::cout << pbeg.deref() << std::endl;

	system("pause");
	return 0;
}