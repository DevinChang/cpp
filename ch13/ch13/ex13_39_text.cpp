#include "ex13_39.h"



int main() {
	StrVec svec;
	svec.emplace_back(10, 'c');
	std::cout << svec.pop();
	system("pause");
	return 0;
}